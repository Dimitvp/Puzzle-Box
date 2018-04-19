//Foto
const int LEDFoto = 5;
const int analogPinFoto = A0;
char s;
//Potenciometar
const int LEDPot = 5;
const int analogPinPot1 = A2;
const int analogPinPot2 = A3;
int potentiometer, potentiometer2, dimmer, dimmer2;
//Button
const int LEDButton = 6;
const int ButtonNum3 = 7;
const int ButtonNum4 = 8;
const int ButtonNum7 = 9;
const int ButtonNum9 = 10;
//Tilt Sensor
const int LEDTilt = 3;      
const int tiltSensor = A1; 
int sensorReading;
int ledState = LOW;
int tiltState;
int lastTiltState = HIGH;
long lastDebounceTime = 0;
long debounceDelay = 50;


void setup() {
	Serial.begin(9600);
	//Potenc
	pinMode(LEDPot, OUTPUT);
	pinMode(LEDFoto, OUTPUT);
	//Button
	pinMode(LEDButton, OUTPUT);
	pinMode(ButtonNum3, INPUT_PULLUP);
	pinMode(ButtonNum4, INPUT_PULLUP);
	pinMode(ButtonNum7, INPUT_PULLUP);
	pinMode(ButtonNum9, INPUT_PULLUP);
	//TiltSensor
	pinMode(LEDTilt, OUTPUT);
	pinMode(tiltSensor, INPUT);
}

void loop() {
	if (Serial.available() > 0) {
		s = Serial.read();
	}

	//Fotoresistor
	if (s == 'a')
	{
		pinMode(LEDFoto, OUTPUT);
		int sensorVal = analogRead(analogPinFoto);
		if (sensorVal < 980)
		{
			digitalWrite(LEDFoto, LOW);
		}
		else if (sensorVal >= 980) {
			digitalWrite(LEDFoto, HIGH);
		}
	}
	//Tilt
	else if (s == 'b') {
		sensorReading = digitalRead(tiltSensor);
		if (sensorReading != lastTiltState) {
			lastDebounceTime = millis();
		}
		if ((millis() - lastDebounceTime) > debounceDelay) {
			if (sensorReading != tiltState) {
				tiltState = sensorReading;
				if (sensorReading == LOW) {
					ledState = HIGH;
					digitalWrite(LEDTilt, ledState);
					delay(500);
				}
				else if (sensorReading == HIGH) {
					ledState = LOW;
					digitalWrite(LEDTilt, ledState);
				}
			}
		}
		lastTiltState = sensorReading;
		delay(100);
	}
	//Button
	else if (s == 'c') {
		if (!digitalRead(ButtonNum3) && !digitalRead(ButtonNum7) && !digitalRead(ButtonNum9))//Tha law of demorgan !(digitalRead(ButtonNum3) || digitalRead(ButtonNum7) || digitalRead(ButtonNum9))
		{
			digitalWrite(LEDButton, HIGH);
		}
		else
		{
			digitalWrite(LEDButton, LOW);

		}
	}

	//Potenciometers
	else if (s == 'd') {
		potentiometer = analogRead(analogPinPot1);//A2
		potentiometer2 = analogRead(analogPinPot2);//A3
		if (potentiometer > 512 && potentiometer < 600 && potentiometer2 < 512 && potentiometer2 > 100)
		{
			digitalWrite(LEDPot, HIGH);
		}
		else {
			analogWrite(LEDPot, LOW);
		}
	}
	else if (s == 'e') {
		for (int i = 0; i < 10; i++)
		{
			//LEDFoto
			digitalWrite(LEDFoto, HIGH);//5
			digitalWrite(LEDTilt, LOW);//3
			digitalWrite(LEDButton, LOW);//6
			digitalWrite(LEDPot, LOW);//6
			delay(2000);
			//LEDTilt
			digitalWrite(LEDFoto, LOW);
			digitalWrite(LEDTilt, HIGH);
			digitalWrite(LEDButton, LOW);
			digitalWrite(LEDPot, LOW);
			delay(2000);
			////LEDButton
			digitalWrite(LEDFoto, LOW);
			digitalWrite(LEDTilt, LOW);
			digitalWrite(LEDButton, HIGH);
			digitalWrite(LEDPot, LOW);
			delay(2000);
			////LEDPot
			digitalWrite(LEDFoto, HIGH);
			digitalWrite(LEDTilt, LOW);
			digitalWrite(LEDButton, LOW);
			digitalWrite(LEDPot, LOW);
			delay(2000);
			////All Dark
			digitalWrite(LEDFoto, LOW);
			digitalWrite(LEDTilt, LOW);
			digitalWrite(LEDButton, LOW);
			digitalWrite(LEDPot, LOW);
			delay(5000);
		}
	}
}
