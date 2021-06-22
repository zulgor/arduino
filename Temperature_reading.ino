#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);
#define sensor A0

byte degree[8] =
{
0b00011,
0b00011,
0b00000,
0b00000,
0b00000,
0b00000,
0b00000,
0b00000
};
void setup()
{
Serial.begin(9600);

lcd.begin(16,2);
lcd.createChar(1, degree);
lcd.setCursor(0,0);
lcd.print(" Measure ");
lcd.setCursor(0,1);
lcd.print(" Temperature ");
delay(200);
lcd.clear();
}
void loop()
{
/*---------Temperature-------*/
float reading=analogRead(sensor);
float temperature=reading*(5.0/1023.0)*100;
delay(2000);
 
/*------Display Result------*/
lcd.clear();
lcd.setCursor(2,0);
lcd.print("Temperature");
lcd.setCursor(4,1);
lcd.print(temperature);
Serial.print(temperature);
Serial.print('\n');
lcd.write(1);
lcd.print("C");}
