void setup()

{

	Serial.begin(9600);
	pinMode(13,OUTPUT);
	pinMode(11,OUTPUT);
}

void loop()

{

	char data = 0;

	if(Serial.available()>0) 
	{

		data = Serial.read(); 
		if (data == 65)
		{
			digitalWrite(13, HIGH);
			digitalWrite(11, HIGH);

		} 

		if (data == 97)
		{
			digitalWrite(13,HIGH);
			digitalWrite(11, LOW);
		}

		Serial.println("Input Value: ");

		Serial.write(data);

	}

}