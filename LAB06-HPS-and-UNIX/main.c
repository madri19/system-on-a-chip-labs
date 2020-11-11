#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "hwlib.h"
#include "socal/socal.h"
#include "socal/hps.h"
#include "socal/alt_gpio.h"
#include "hps_0.h"

#define HW_REGS_BASE ( ALT_STM_OFST )
#define HW_REGS_SPAN ( 0x04000000 )
#define HW_REGS_MASK ( HW_REGS_SPAN - 1 )

int bcd_to_7seg(int num);

int main() 
{
	void *virtual_base;	
	void *hex0_addr;
	void *hex1_addr;
	void *hex2_addr;
	void *switches_addr;
	int fd;

	if((fd = open("/dev/mem", (O_RDWR | O_SYNC))) == -1) 
	{ 
		printf("ERROR: could not open \"/dev/mem\"...\n"); 
		return (1); 
	} 

	virtual_base = mmap(NULL, HW_REGS_SPAN, (PROT_READ | PROT_WRITE), MAP_SHARED, fd, HW_REGS_BASE); 

	if(virtual_base == MAP_FAILED) 
	{ 
		printf("ERROR: mmap() failed...\n"); 
		close(fd); 
		return(1); 
	} 

	// Get the addresses of our hardware IO
	hex0_addr = virtual_base + ((unsigned long) (ALT_LWFPGASLVS_OFST + PIO_SEVENSEG_0_BASE) & (unsigned long) (HW_REGS_MASK)); 
	hex1_addr = virtual_base + ((unsigned long) (ALT_LWFPGASLVS_OFST + PIO_SEVENSEG_1_BASE) & (unsigned long) (HW_REGS_MASK)); 
	hex2_addr = virtual_base + ((unsigned long) (ALT_LWFPGASLVS_OFST + PIO_SEVENSEG_2_BASE) & (unsigned long) (HW_REGS_MASK)); 
	switches_addr = virtual_base + ((unsigned long) (ALT_LWFPGASLVS_OFST + PIO_SWITCHES_BASE) & (unsigned long) (HW_REGS_MASK)); 
	
	//Variables for the while loop
	uint32_t switches, hex0, hex1, hex2;
	
	while(1) 
	{ 
		//Get the values of the switches and split, mask, shift.
		switches = *(uint32_t *)switches_addr;
		hex0 = switches & 0b0000001111;
		hex1 = (switches & 0b0011110000) >> 4;
		hex2 = (switches & 0b1100000000) >> 8;

		// Output SWs values to Hex Displays
		*(uint32_t *)hex0_addr = bcd_to_7seg(hex0);
		*(uint32_t *)hex1_addr = bcd_to_7seg(hex1);
		*(uint32_t *)hex2_addr = bcd_to_7seg(hex2);		
	}  // while
}

int bcd_to_7seg(int num){
	switch(num)
	{
		case 0:
			return 0b1000000;
		case 1:
			return 0b1111001;
		case 2:
			return 0b0100100;
		case 3:
			return 0b0110000;
		case 4:
			return 0b0011001;
		case 5:
			return 0b0010010;
		case 6:
			return 0b0000010;
		case 7:
			return 0b1111000;
		case 8:
			return 0b0000000;
		case 9:
			return 0b0010000;
		case 10:
			return 0b0001000;
		case 11:
			return 0b0000011;
		case 12:
			return 0b1000110;
		case 13:
			return 0b0100001;
		case 14:
			return 0b0000110;
		case 15:
			return 0b0001110;
		default:
			return 0b0101010;
	}
}