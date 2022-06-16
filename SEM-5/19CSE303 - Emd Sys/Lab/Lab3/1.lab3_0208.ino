/* Print data received through serial communication on to the serial monitor of Arduino */



/* Setup is run once at the start (Power-On or Reset) of sketch */

void setup()

{

Serial.begin(9600); /* opens serial port, sets data rate to 9600 bps */

}



/* Loop runs over and over after the startup function */

void loop()

{

char data = 0;



if(Serial.available()>0) /* If data available at serial port, enter if loop */

{

data = Serial.read(); /* Read data present at serial port */

Serial.println("Data Received is : "); /* Print string with \r\n */

Serial.write(data); /* Print data received */

}

}

