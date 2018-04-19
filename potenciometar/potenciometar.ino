/*
Name:    potenciometar.ino
Created: 7/2/2017 1:21:09 AM
Author:  Dimito
*/
const int LED = 6;
const int analogPin = A2;
const int analogPin2 = A3;
int potentiometer, potentiometer2, dimmer, dimmer2;
// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(LED, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	//v. #1
	//potentiometer = analogRead(analogPin);
	//dimmer = potentiometer / 4.01;
	//analogWrite(LED, dimmer);
	//v. #2
	potentiometer = analogRead(analogPin);
	potentiometer2 = analogRead(analogPin2);
	if (potentiometer > 512 && potentiometer < 600 && potentiometer2 < 512 && potentiometer2 > 100)
	{
		digitalWrite(LED, HIGH);
	}
	else {
		analogWrite(LED, LOW);
	}
	Serial.println("Pot1 = " + potentiometer);
	Serial.println("Pot2 = " + potentiometer2);
	//dimmer = map(potentiometer, 0, 1023, 0, 1);
	//dimmer2 = map(potentiometer, 0, 1023, 0, 128);
	//analogWrite(LED, dimmer);
	//analogWrite(LED, dimmer2);
	//v. #3
	//for (int i = 0; i < 255; i++)
	//{
	//analogWrite(LED, i);
	//delay(50);
	//}
	//for (int i = 255; i >= 0; i--)
	//{
	//analogWrite(LED, i);
	//delay(50);
	//}
}
