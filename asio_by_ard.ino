/*
 Name:		asio_by_ard.ino
 Created:	2020/5/20 9:53:10
 Author:	miss-yins
*/

// the setup function runs once when you press reset or power the board
int num = 0;
char aaa[50];
char bbb;
void setup() {
	Serial.begin(38400);
	pinMode(13,OUTPUT);
	digitalWrite(13, HIGH);
}

// the loop function runs over and over again until power down or reset
void loop() {
  
	if (Serial.available())
	{
		Serial.print( (char)Serial.read());
		bbb = (char)Serial.read();
		Serial.print(bbb);
	}
	delay(5);
	num++;
}
