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

* __Midterm(Custom IP with NIOS II Processor)__
Video Demo: https://oregontech-my.sharepoint.com/:v:/g/personal/juan_madrigal_oit_edu/EQXb8XB6v3lKvvM09oERYUABAAnsyLKS1hQMUS030fKMFQ?e=AKgrhv
