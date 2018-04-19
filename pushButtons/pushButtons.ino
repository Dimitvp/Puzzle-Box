/*
 Name:		pushButtons.ino
 Created:	7/2/2017 1:07:51 AM
 Author:	Dimito
*/
const int LED = 6;
const int BUTTON = 7;
// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(LED, OUTPUT);
	pinMode(BUTTON, INPUT_PULLUP);
}

// the loop function runs over and over again until power down or reset
void loop() {
	if (digitalRead(BUTTON))
	{
		digitalWrite(LED, LOW);
	}
	else
	{
		digitalWrite(LED, HIGH);
		
	}
}
