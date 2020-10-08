-- This is my generic file for interfacing modules to DE1-SoC

--------------- Libraries ------------------------------------
library ieee;
use ieee.std_logic_1164.all;

entity De1_SoC_Generic is
	port (
--------------- Clocks --------------------------------------
--			CLOCK_50			: in std_logic;
--			MAX10_CLK1_50	: in std_logic;
--			MAX10_CLK2_50	: in std_logic;
	
--------------- 7-Segment Displays --------------------------	
			HEX0				: out std_logic_vector (7 downto 0);
			HEX1				: out std_logic_vector (7 downto 0);
			HEX2				: out std_logic_vector (7 downto 0);
--			HEX3				: out std_logic_vector (7 downto 0);
			HEX4				: out std_logic_vector (7 downto 0);
--			HEX5				: out std_logic_vector (7 downto 0);
			
--------------- Key Buttons ---------------------------------
--			KEY		: in std_logic_vector (3 downto 0);
			
--------------- LED's ---------------------------------------
--			LEDR		: out std_logic_vector (9 downto 0);
			
--------------- GPIO ----------------------------------------
--			GPIO		: inout std_logic_vector (35 downto 0)
			
--------------- Switches ------------------------------------
			SW			: in std_logic_vector (9 downto 0)
			);
end De1_SoC_Generic;


architecture struct of De1_SoC_Generic is

COMPONENT bcd_7segment
	PORT(D :IN std_logic_vector(3 downto 0);
		  S :OUT std_logic_vector(6 downto 0) );
END COMPONENT;

COMPONENT add_bothSW
	PORT   (NUM1 :IN std_logic_vector(3 downto 0); NUM2 :IN std_logic_vector(3 downto 0);
				CARRYOUT1 :OUT std_logic_vector(3 downto 0); OUT2 :OUT std_logic_vector(3 downto 0) );
END COMPONENT;


--Lab2 wires
	signal outLeft, outRight: std_logic_vector(3 downto 0);

begin

--------------- This tests the board and library ==----------

--Here is my lab 1
--	lab1		: bcd_7segment port map (SW(3 downto 0), HEX0(6 downto 0));

--Here is my lab2
	seg7_a	: bcd_7segment port map (SW(7 downto 4), HEX4(6 downto 0));
	seg7_b	: bcd_7segment port map (SW(3 downto 0), HEX2(6 downto 0));
	lab2add	: add_bothSW port map(SW(7 downto 4), SW(3 downto 0), outLeft, outRight);
	seg7_c	: bcd_7segment port map (outLeft, HEX1(6 downto 0));
	seg7_d	: bcd_7segment port map (outRight, HEX0(6 downto 0));


end struct;








