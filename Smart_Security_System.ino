
#include<LiquidCrystal.h>
#define PIR_In 8
#define buzzer_Out 9
LiquidCrystal lcd(12,11,2,3,4,5);
void setup()
{
  pinMode(buzzer_Out, OUTPUT);
pinMode(PIR_In, INPUT);
Serial.begin(9600);
  lcd.begin(16,2);
}
//now let us consider the time is taken in 24hr format.
void loop()
{
  int time=800; //We have taken the time as 11pm which is off business hours.
  
  if(time>=700 && time<=2200){
    lcd.clear();
    lcd.setCursor(0,0);
  people_passing();
    
  }
  else{
    lcd.clear();
  lcd.setCursor(0,0);
    check_For_Intruder();
  }
  }

void check_For_Intruder()
  {
boolean sensorvalue= digitalRead(PIR_In);
if(sensorvalue==1)
     {
digitalWrite(buzzer_Out,HIGH);
lcd.setCursor(0,0);
lcd.print("Intruder in the ");
lcd.setCursor(0,1);
lcd.print("MALL :( ");
delay(5000);
lcd.clear();
}else{     
digitalWrite(buzzer_Out,LOW);        
         }
delay(10);    
}
void people_passing(){
boolean sensorvalue= digitalRead(PIR_In);
if(sensorvalue==1)
     {
lcd.setCursor(0,0);
lcd.print("Welcomee to ");
lcd.setCursor(0,1);
lcd.print("the MALL!!");
delay(5000);
lcd.clear();
}else{     
digitalWrite(buzzer_Out,LOW);        
         }
delay(10); 
}
