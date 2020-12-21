#include <SoftwareSerial.h>
//Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(PB11,PB10); //SIM800L Tx & Rx is connected to Arduino #3 & #2
int incomingByte = 0; // for incoming serial data
String message;
void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  //Begin serial communication with Arduino and SIM800L
  mySerial.begin(9600);

  Serial.println("Initializing..."); 
  delay(1000);

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  //mySerial.println("AT+CMGS=\"+66970762483\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  //updateSerial();
  //mySerial.print("Idatabots send SMS| idatabots.com"); //text content
  //updateSerial();
  mySerial.write(26);
}

void loop()
{
   Serialdata(incomingByte); //Testing 
}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}
void Serialdata(int incomingByte){
  // reply only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    // say what you got:
    Serial.print("I received: ");
    message = incomingByte,DEC; 
    Serial.println(message);
    //char splitdata = strtok(message,","); // Split data from the incoming message 
    //print(splitdata);
    //Serial.println("Initializing..."); 
    //delay(1000);
    //mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
    //updateSerial();
    //mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
    //updateSerial();
    mySerial.println("AT+CMGS=\"+66970762483\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
    updateSerial();
    mySerial.print("Idatabots send SMS| "+ message); //text content
    updateSerial();
    mySerial.write(26);
  }
}
