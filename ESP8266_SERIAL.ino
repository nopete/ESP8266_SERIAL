#include <SoftwareSerial.h>
SoftwareSerial softSerial(8, 9); // RX, TX

void setup() 
{
  uint32_t baud = 9600;
  Serial.begin(9600);
  softSerial.begin(115200);
  softSerial.print("AT+CIOBAUD=");
  softSerial.println(baud);
  softSerial.begin(baud);
  Serial.print("SETUP!! @");
  Serial.println(baud);
}

void loop() 
{
    while(softSerial.available() > 0) 
    {
      char a = softSerial.read();
      if(a == '\0')
        continue;
      if(a != '\r' && a != '\n' && (a < 32))
        continue;
      Serial.print(a);
    }
    
    while(Serial.available() > 0)
    {
      char a = Serial.read();
      Serial.write(a);
      softSerial.write(a);
    }
}
