--Juan Madrigal 10-1-20

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY add_bothSW IS
	PORT	( NUM1 :IN std_logic_vector(3 downto 0); 
			  NUM2 :IN std_logic_vector(3 downto 0);
			  CARRYOUT1 :OUT std_logic_vector(3 downto 0); 
			  OUT2 :OUT std_logic_vector(3 downto 0) );
END add_bothSW;



ARCHITECTURE behavior OF add_bothSW IS

begin

	getthedata: process(NUM1, NUM2)
		variable total: std_logic_vector(4 downto 0);
		variable sub: std_logic_vector(4 downto 0);
	Begin
		total := ('0' & NUM1) + ('0' & NUM2);
		if total > 15 then 
			sub := total - 16;
			oUT2 <= sub(3 downto 0);
			CARRYOUT1 <= "0001";
		else
			CARRYOUT1 <= "0000";
			OUT2 <= total(3 downto 0);
		end if;

	end process getthedata;

	END behavior;
