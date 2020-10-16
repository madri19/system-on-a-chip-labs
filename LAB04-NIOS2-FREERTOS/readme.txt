I only uploaded some of the significant files since the IP work is done in the Quartus Platform Designer. 
In summary this Lab synthesis the NIOS 2 processors with PIO IP to handle the push buttons and the LEDs. Each button will cause a different pattern to be displayed. 
A task polls the buttons and sends a message to an LED task. The LED task is responsible for producing the pattern on the LEDs. I end up with two tasks and a queue to send messages from one to the other. The patterns include cylon, up counter, blink, and one of your choice.
