#include <LGPS.h>
#include <LCheckSIM.h>
#include <LGSM.h>
#include <stdio.h>

float latitude = 0;
char ns = 'N';

float longitude = 0;
char ew = 'E';

void setup()
{
    Serial.begin(115200);
    Serial.print("Traxxor.\r\n");
}

void loop()
{
  Serial.println("loop");
  handleSMS();
  retrieveGPSLocation();  
  delay(1000);
}

void handleSMS()
{
  if(!LSMS.available())
    return;

  Serial.println("SMS Received");
  
  char num[20] = "";
  char buf_contex[200];

  LSMS.remoteNumber(num, 20);
  Serial.print("Number: ");
  Serial.println(num);
  
  LSMS.remoteContent(buf_contex, 50);
  
  Serial.print("Content");
  Serial.println(buf_contex);

  if(buf_contex[0] == 'L')
  {
    while(!LSMS.ready())
      delay(1000);
        
    char buffer[100] = {0,};
    sprintf(buffer, "%c:%f,%c:%f", LGPS.get_ns(), LGPS.get_latitude(), LGPS.get_ew(), LGPS.get_longitude());
   
    Serial.println("SIM ready for work!");
    LSMS.beginSMS(num);
    LSMS.print(buffer);
    
    if(LSMS.endSMS())
      Serial.println("SMS is sent");
    else
      Serial.println("SMS send fail");
        
    LSMS.flush();  
  } 
}

void retrieveGPSLocation() 
{ 
  if(LGPS.check_online())
  {
    char buffer[100] = {0,};
    
    sprintf(buffer, "GPS latitude is %c:%f\r\n", LGPS.get_ns(), LGPS.get_latitude());
    Serial.print(buffer);
        
    sprintf(buffer, "GPS longitude is %c:%f\r\n", LGPS.get_ew(), LGPS.get_longitude());
    Serial.print(buffer);  
    
    ns = LGPS.get_ns();
    latitude = LGPS.get_latitude();
    
    ew = LGPS.get_ew();
    longitude = LGPS.get_longitude();
  }    
}
