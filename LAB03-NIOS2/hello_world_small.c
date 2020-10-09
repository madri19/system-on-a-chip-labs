// Juan Madrigal - CST455 - LAB03 - NIOS2 using Switches and 7 Segment Displays

#include "sys/alt_stdio.h"
#include "altera_avalon_pio_regs.h"
#include "system.h"

int bcd_to_7seg(int dec){
	switch(dec)
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

int main()
{ 
  alt_putstr("Hello from Nios II!\n");

  // Variables
  int switches, hex0, hex1, hex2;

  /* Event loop never exits. */
  while (1){
	  //Get the values of the switches
	  switches = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);

	  // Mask for new bcd values specific for each 7seg output
	  hex0 = switches & 0b0000001111;
	  hex1 = (switches & 0b0011110000) >> 4;
	  hex2 = (switches & 0b1100000000) >> 8;

	  // Output SW[0-3] on 7seg[0-2] after converting from BCD to 7seg value
	  IOWR_ALTERA_AVALON_PIO_DATA(SEVEN_SEG_0_BASE, bcd_to_7seg(hex0));
	  IOWR_ALTERA_AVALON_PIO_DATA(SEVEN_SEG_1_BASE, bcd_to_7seg(hex1));
	  IOWR_ALTERA_AVALON_PIO_DATA(SEVEN_SEG_2_BASE, bcd_to_7seg(hex2));
  }

  return 0;
}
