--convert a bdc 4 bit input into a 7segment display output representation in 0-15 in hex
--Juan Madrigal 10-1-20

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY bcd_7segment IS
	PORT   (D :IN std_logic_vector(3 downto 0);
				S :OUT std_logic_vector(6 downto 0) );
END bcd_7segment;

ARCHITECTURE behavior OF bcd_7segment IS
	Begin
		S <=	"1000000" when D="0000" else
				"1111001" when D="0001" else
				"0100100" when D="0010" else
				"0110000" when D="0011" else
				"0011001" when D="0100" else
				"0010010" when D="0101" else
				"0000010" when D="0110" else
				"1111000" when D="0111" else
				"0000000" when D="1000" else
				"0010000" when D="1001" else
				"0001000" when D="1010" else
				"0000011" when D="1011" else
				"1000110" when D="1100" else
				"0100001" when D="1101" else
				"0000110" when D="1110" else
				"0001110" when D="1111" else
				"1111111" ;
END behavior;
