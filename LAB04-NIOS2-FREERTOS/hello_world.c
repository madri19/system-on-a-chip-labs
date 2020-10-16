#include <stdio.h>
#include "sys/alt_irq.h"
#include "altera_avalon_pio_regs.h"
#include "system.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

void taskPolling(void *p);
void taskLEDs(void *p);

int main(){
	printf("Hello from NIOS II\n");
	QueueHandle_t theQueue = xQueueCreate(1, sizeof(uint8_t));
	xTaskCreate(taskPolling, "taskPolling", 512, &theQueue, 2, NULL);
	xTaskCreate(taskLEDs, "taskLEDs", 512, &theQueue, 2, NULL);
	vTaskStartScheduler();
	return 0;
}

void taskPolling(void *p){
	printf("Starting taskPolling...\n");
	QueueHandle_t * cast = (QueueHandle_t*) p;
	QueueHandle_t leds = *cast;
	int buttons, key1, key2, key3, key4, pushedFlag;
	uint8_t message;
	pushedFlag = 0;

	while(1){
		vTaskDelay(100);

		// Read the Buttons and then mask and shift them, then set into variables
		buttons = IORD_ALTERA_AVALON_PIO_DATA(BUTTONS_BASE);
		key1 = buttons & 0b0001;
		key2 = (buttons & 0b0010) >> 1;
		key3 = (buttons & 0b0100) >> 2;
		key4 = (buttons & 0b1000) >> 3;

		// Next poll if the keys are being pressed == 0 and send a message to taskLEDs
		if(!key1){
			message = 0b00000001;
			pushedFlag = 1;
			printf("Key0 Pressed!\n");
			if(xQueueSendToBack(leds, (void *)&message, (TickType_t)10) != pdPASS){
				printf("Failed to send message to queue key 0\n");
			}
		}
		else if(!key2){
			message = 0b00000010;
			pushedFlag = 1;
			printf("Key1 Pressed!\n");
			if(xQueueSendToBack(leds, (void *)&message, (TickType_t)10) != pdPASS){
				printf("Failed to send message to queue key 1\n");
			}
		}
		else if(!key3){
			message = 0b00000011;
			pushedFlag = 1;
			printf("Key2 Pressed!\n");
			if(xQueueSendToBack(leds, (void *)&message, (TickType_t)10) != pdPASS){
				printf("Failed to send message to queue key 2\n");
			}
		}
		else if(!key4){
			message = 0b00000100;
			pushedFlag = 1;
			printf("Key3 Pressed!\n");
			if(xQueueSendToBack(leds, (void *)&message, (TickType_t)10) != pdPASS){
				printf("Failed to send message to queue key 3\n");
			}
		}

		if(pushedFlag == 1){
			vTaskDelay(600);
			pushedFlag = 0;
		}
	}
}

void taskLEDs(void *p){
	printf("Starting taskLEDs...\n");
	QueueHandle_t * cast = (QueueHandle_t*) p;
	QueueHandle_t leds = *cast;
	uint8_t message;

	// Cylon variables
	uint8_t upDown = 1;
	int cylon = 0;
	// Counter variables
	int counter = 0;
	// BLINK varaible
	uint8_t onOff = 1;
	// My Custom LED pattern
	uint16_t twoInOut[5] = {0b0000110000, 0b0001001000, 0b0010000100, 0b0100000010, 0b1000000001};
	uint8_t twoCylon = 0;

	while(1){
		vTaskDelay(150);
		if(uxQueueMessagesWaiting(leds)){
			if(xQueueReceive(leds, &message, (TickType_t)10) == pdPASS){
				printf("Key%d Pressed Message Received!\n", message-1);
			}
		}
		// Do the LED Dance
		if(message == 0b00000001){
			counter = 0;
			twoCylon = 0;
			// CYLON
			if(upDown == 1){
				cylon++;
				if(cylon == 9)
					upDown = 0;
			}
			else {
				cylon--;
				if(cylon == 0)
					upDown = 1;
			}
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, (1 << cylon));
		}
		else if(message == 0b00000010){
			cylon = 0;
			upDown = 1;
			twoCylon = 0;
			// UP COUNTER
			if(counter > 1023)
				counter = 0;
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, counter++);
		}
		else if(message == 0b00000011){
			cylon = 0;
			counter = 0;
			upDown = 1;
			twoCylon = 0;
			// BLINK
			onOff = (onOff == 1) ? 0 : 1;
			if(onOff)
				IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, 0b1111111111);
			else
				IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, 0b0000000000);
		}
		else if(message == 0b00000100){
			cylon = 0;
			counter = 0;
			upDown = 1;
			// My Custom LED Pattern
			if(twoCylon == 5)
				twoCylon = 0;
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, twoInOut[twoCylon++]);
		}
		else{
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, 0b1010101010);
		}
	}
}
