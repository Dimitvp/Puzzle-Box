/*
 Name:		PuzzelBox.ino
 Created:	7/1/2017 11:04:46 PM
 Author:	Dimito
*/
const int LED = 9;
const int analogPin = A0;
char s;

// the setup function runs once when you press reset or power the board
void setup() {
	//Serial.begin(9600);
	pinMode(LED, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	/*if (Serial.available() > 0) {
		s = Serial.read();
	}*/
	//if (s == 'a')
	//{
	digitalWrite(LED, LOW);
		int sensorVal = analogRead(analogPin);
		Serial.print("Photoresistor value: ");
		Serial.println(sensorVal);

		if (sensorVal < 980)
		{
			Serial.println("It`s geting data");
			digitalWrite(LED, LOW);
		}
		else if (sensorVal >= 980) {
			Serial.println("It`s realy dark in here");
			digitalWrite(LED, HIGH);
		//}
	}
	
}
