# system-on-a-chip-labs

Lab01(Intro to DE1-SoC board) uses top-level-entity.vhdl and bcd_7segment.vhdl on the DE1-SoC board. What is does is depending on the Switches 0-3 the hex value is outputed on the 7 segment display.

Lab02(Using VHDL) used top-level-entity.vhdl, bsc_7segment.vhdl, and add_bothSW.vhdl on the DE1-SoC board. What is does is output Switches 4-7 as hex on 7 segment display #4 and Switches 0-3 as hex on 7 segment display #2. It then takes these 2 hex values and outputs them on 7 segment display #1 and #0. 

Lab03(Nios II Softcore Processor) Project will use NIOS 2 processor with PIO cores to read the switches (sw3-0 as one hex digit, sw7 - 4 as another hex digit, and sw9-8 as a third hex digit) and display them on the 7 segment displays. All of the decoding is done in software and only generic PIO cores are used.

Lab04(FreeRTOS and the NIOS II) Project will use the NIOS 2 processor with PIO cores to read  4 push buttons and output to the 10 LED's a different LED pattern based on which button was pressed. This is using FreeRTOS to create the 2 tasks and they share a queue object to transmit the message between tasks.
