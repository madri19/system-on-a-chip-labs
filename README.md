# system-on-a-chip-labs

* __Lab01(Intro to DE1-SoC board)__ 
Uses top-level-entity.vhdl and bcd_7segment.vhdl on the DE1-SoC board. What is does is depending on the Switches 0-3 the hex value is outputed on the 7 segment display.

* __Lab02(Intro Using VHDL)__ 
Used top-level-entity.vhdl, bsc_7segment.vhdl, and add_bothSW.vhdl on the DE1-SoC board. What is does is output Switches 4-7 as hex on 7 segment display #4 and Switches 0-3 as hex on 7 segment display #2. It then takes these 2 hex values and outputs them on 7 segment display #1 and #0. 

* __Lab03(Nios II Softcore Processor)__ 
Project will use NIOS 2 processor with PIO cores to read the switches (sw3-0 as one hex digit, sw7 - 4 as another hex digit, and sw9-8 as a third hex digit) and display them on the 7 segment displays. All of the decoding is done in software and only generic PIO cores are used.
Video Demo: https://oregontech-my.sharepoint.com/:v:/g/personal/juan_madrigal_oit_edu/EfCCoqQMj-FGtrIMs8OrtakBkuiQiiZPSMXFaRLY5wIpcQ?e=focNQE

* __Lab04(FreeRTOS and the NIOS II)__ 
Project will use the NIOS 2 processor with PIO cores to read  4 push buttons and output to the 10 LED's a different LED pattern based on which button was pressed. This is using FreeRTOS to create the 2 tasks and they share a queue object to transmit the message between tasks.
Video Demo: https://oregontech-my.sharepoint.com/:v:/g/personal/juan_madrigal_oit_edu/EaETxUIu6nNFrR2XY_DADiEBKVkdjIet8FbZV6gM12yP3g?e=U2MEet

* __Midterm(Custom IP with NIOS II Processor)__ You will write a small SoPC system based on a NIOS II core processor. The system will comprise the following minimum specs. A NIOS II core processor, system memory, JTAG UART and several pieces of custom IP (Note: The system may contain more things IE. Timers and etc.). You will write four custom pieces of I/O for this processor system. The first will be a piece of hardware to handle the slide switches on the DE1-SOC board. The second will be another piece of hardware to handle the push buttons. The third will handle the LEDs and the last will handle the 7-SEG displays. Your system will perform the following tasks. Read the slide switches and perform the following operations on them. SW3 – SW0 will be a 4bit number, SW7 – SW4 will also be a four bit number. You will perform various math on these two numbers based on the last two switches. The first number will be displayed on HEX5-HEX4, The second number will be displayed on HEX3-HEX2, the result will be displayed on HEX1-HEX0. All numbers must be displayed in base 10 format. The second function that the system will perform is display various chase patterns on the LEDs. These patterns will be selected from the four push buttons on the board.

Probably won't post code and design but I have a video.
Video Demo: https://oregontech-my.sharepoint.com/:v:/g/personal/juan_madrigal_oit_edu/EQXb8XB6v3lKvvM09oERYUABAAnsyLKS1hQMUS030fKMFQ?e=AKgrhv
