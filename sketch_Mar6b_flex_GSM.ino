
int timesTosend_calltodoctor=1;
int timesTosend_thankyou=1;
int timesTosend_NeedHelp=1;
int count1=0;
int count2=0;
int count3=0;
char phone_no[] = "8919609237";  //phone number to alert
#include <LiquidCrystal.h>// includ the LCD library header file.
# include<math.h>
#include <TimerOne.h>
//#include <SoftwareSerial.h>
#define FLEX_1  A0
#define FLEX_2  A1
#define FLEX_3  A2
#define vioce_1  10  // vioce-1 :- Need Help 
#define vioce_2  9  // vioce-2 :- Call to Doctor
#define vioce_3  8  // vioce-3 :- I am Hungry
#define vioce_4  7  // vioce-4 :- Need Water
#define vioce_5  6  // vioce-5 :- Thak you
#define vioce_6  5  // vioce-6 :- Sorry
#define vioce_7  4  // vioce-7 :- Welcome
#define vioce_8  3  // vioce-8 :- Be Happy
const int sensorMin1 =803;
const int sensorMax1 =953;
const int sensorMin2 =780;
const int sensorMax2 =950;
const int sensorMin3 =765;
const int sensorMax3 =955;
int m1 =0;
int m2 =0;
int m3 =0;

LiquidCrystal lcd(12, 11, A3, A4, A5, 2); // for (RS,E,D4,D5,D6,D7);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  //Open Serial connection at baud 9600
pinMode(FLEX_1, INPUT);  // initialze input
pinMode(FLEX_2, INPUT);  // initialze input
pinMode(FLEX_3, INPUT);  // initialze input
pinMode(vioce_1, OUTPUT); // initialze output  
pinMode(vioce_2, OUTPUT); // initialze output
pinMode(vioce_3, OUTPUT); // initialze output
pinMode(vioce_4, OUTPUT); // initialze output
pinMode(vioce_5, OUTPUT); // initialze output
pinMode(vioce_6, OUTPUT); // initialze output
pinMode(vioce_7, OUTPUT); // initialze output

}

void loop() {
  // put your main code here, to run repeatedly:
 int sensorValue1 = analogRead(A0);   // Read the FLEX_1 INPUT on analog pin A0
 int sensorValue2 = analogRead(A1);   // Read the FLEX_2 INPUT on analog pin A1
 int sensorValue3 = analogRead(A2);   // Read the FLEX_3 INPUT on analog pin A2 
//delay(1000);
 int m1 = ((sensorValue1)/878);
 int m2 =((sensorValue2)/865);
 int m3 =(sensorValue3/860);
 /*Serial.print("m1=");
 Serial.println(m1);
 
 Serial.print("m2=");
 Serial.println(m2);

 Serial.print("m3=");
 Serial.println(m3);
//delay(50);*/

if((m1==1) && (m2==0) && (m3==0) ){ // If condition to said only sensorvalue-1 is high

 int range1 = map(sensorValue1, sensorMin1, sensorMax1, 0,1); 
  switch (range1) {
    case 0: // sensorvalue-1 is at sensorMin
    lcd.noDisplay();
     digitalWrite (vioce_1, HIGH); // To stop the vioce -1
      break; 
     
    case 1: // sensorvalue-1 is at sensorMax
      while(count3<timesTosend_NeedHelp){
    digitalWrite (vioce_7, HIGH);
    Serial.println(" ");
    Serial.println("AT+CMGF=1");
    //delay(1000);
    lcd.display();
    lcd.setCursor(0,0);
    lcd.print("Calling to Phone");
    delay(2000);
    lcd.display();
    lcd.setCursor(0,0);
    lcd.print("SMS is Sending..");
    delay(1500);
    Serial.print("ATD");; //Dial the phone number using ATD command
    Serial.print(phone_no);
    Serial.println(";"); // Semicolon is a must at the end
    delay(10000);
    Serial.println("ATH"); // After a delay of 5 secs Hang the call
    delay(1000);
    Serial.print("AT+CMGS=\"");
    Serial.print(phone_no);
    Serial.println("\""); 
    delay(1000);  // delay is must it waits for > symbol
    Serial.print("Need Help....");  //SMS body
    Serial.write(0x1A);  // sends ctrl+z end of message
    delay(5000);
    count3++;
}
     lcd.display();
      lcd.setCursor(0,0);
      lcd.print("Need Help.       ");  //
      delay(1000);
      digitalWrite(vioce_1, LOW); // To play vioce-1(Need Help) 
      delay(1000); 
     // break;   
  }
 }
 if((m2==1) && (m1==0) && (m3==0)){ // If condition to said only sensorvalue-2 is high

 int range2 = map(sensorValue2, sensorMin2, sensorMax2, 0,1);
  switch (range2) {
    case 0:  // sensorvalue-2 is at sensorMin
    lcd.noDisplay();
    digitalWrite (vioce_2, HIGH);  // To stop the vioce -2
    break;
      
    case 1: // sensorvalue-2 is at sensorMax
    while(count1<timesTosend_calltodoctor){
    digitalWrite (vioce_7, HIGH);
    Serial.println(" ");
    Serial.println("AT+CMGF=1");
    //delay(1000);
    lcd.display();
    lcd.setCursor(0,0);
    lcd.print("Calling to Phone");
    delay(2000);
    lcd.display();
    lcd.setCursor(0,0);
    lcd.print("SMS is Sending..");
    delay(1500);
    Serial.print("ATD");; //Dial the phone number using ATD command
    Serial.print(phone_no);
    Serial.println(";"); // Semicolon is a must at the end
    delay(10000);
    Serial.println("ATH"); // After a delay of 5 secs Hang the call
    delay(1000);
    Serial.print("AT+CMGS=\"");
    Serial.print(phone_no);
    Serial.println("\""); 
    delay(1000);  // delay is must it waits for > symbol
    Serial.print("Call to Doctor....");  //SMS body
    Serial.write(0x1A);  // sends ctrl+z end of message
    delay(5000);
    count1++;
}
    lcd.display();
    lcd.setCursor(0,0);
    lcd.print("Call to Doctor.   "); 
    delay(900);
    digitalWrite(vioce_2, LOW); // To play vioce-2(Call to Doctor)
    delay(900);
 }
 } 
 if((m3==1) && (m1==0) && (m2==0) ) { // If condition to said only sensorvalue-3 is high
  
  int range3 = map(sensorValue3, sensorMin3, sensorMax3, 0,1);
  switch (range3) {
    case 0: // sensorvalue-3 is at sensorMin
    lcd.noDisplay();
     digitalWrite (vioce_3, HIGH);  // To stop the vioce -3
      break;   
    case 1: // sensorvalue-3 is at sensorMax 
     lcd.display();  
    lcd.setCursor(0,0);
    lcd.print("I am Hungry.        ");
    delay(1000);
    digitalWrite(vioce_3, LOW); // To play vioce-3(I am Hungry)
    delay(1000);
}
}
if((m1==1) && (m2==1) && (m3==0)){
       lcd.noDisplay();
       digitalWrite(vioce_4, HIGH);  // To stop the vioce -4
if((m1==1) && (m2==1) && (m3==0)){ //If condition to said only sensorvalue-1 & 2 is high         
     lcd.display();  
     lcd.setCursor(0,0);
     lcd.print("Need Water.          ");
     delay(1000);
     digitalWrite(vioce_4, LOW); // To play vioce-4(Need Water)
      delay(1000);
}
}
if((m1==1) && (m3==1) && (m2==0)){
       lcd.noDisplay();  
      digitalWrite(vioce_5, HIGH);  // To stop the vioce -5
if((m1==1) && (m3==1) && (m2==0)){ //If condition to said only sensorvalue-1 & 3 is high
    while(count2<timesTosend_thankyou){
    digitalWrite (vioce_7, HIGH);
    Serial.println(" ");
    Serial.println("AT+CMGF=1");
    //delay(1000);
    lcd.display();
    lcd.setCursor(0,0);
    lcd.print("Calling to Phone");
    delay(2000);
    lcd.display();
    lcd.setCursor(0,0);
    lcd.print("SMS is Sending..");
    delay(1500);
    Serial.print("ATD");; //Dial the phone number using ATD command
    Serial.print(phone_no);
    Serial.println(";"); // Semicolon is a must at the end
    delay(10000);
    Serial.println("ATH"); // After a delay of 5 secs Hang the call
    delay(1000);
    Serial.print("AT+CMGS=\"");
    Serial.print(phone_no);
    Serial.println("\"");
    delay(1000);  // delay is must it waits for > symbol
    Serial.print("Thankyou....");  //SMS body
    Serial.write(0x1A);  // sends ctrl+z end of message
    delay(5000);
    count2++;
}
     lcd.display();  
     lcd.setCursor(0,0);
     lcd.print("Thank You.      ");
     delay(1000);
     digitalWrite(vioce_5, LOW);  // To play vioce-5(Thank You)
     delay(1000);
} 
}   
if((m2==1) && (m3==1) && (m1==0)){ 
       lcd.noDisplay();  
       digitalWrite(vioce_6, HIGH);  // To stop the vioce -6
if((m2==1) && (m3==1) && (m1==0)){  //If condition to said only sensorvalue-2 & 3 is high    
     lcd.display();  
     lcd.setCursor(0,0);
     lcd.print("Sorry.         ");
     delay(800);
     digitalWrite(vioce_6, LOW);  // To play vioce-6(Sorry)
     delay(800);   
  }
  }
  if((m2==0) && (m3==0) && (m1==0)){
     lcd.noDisplay();  
      digitalWrite(vioce_7, HIGH); // To stop vioce-7(Welcome)
   if((m2==0) && (m3==0) && (m1==0)){
      lcd.noDisplay(); 
       delay(1000); 
      digitalWrite(vioce_7, LOW); // To play vioce-7(Welcome)
      delay(1000);   
  }
  }
  if((m2==1) && (m3==1) && (m1==1)){ 
     lcd.noDisplay();  
     digitalWrite(vioce_8, HIGH); // To stop vioce-7(Welcome)
     if((m2==1) && (m3==1) && (m1==1)){ 
     lcd.display();  
     lcd.setCursor(0,0);
     lcd.print("Be Happy.         "); 
     delay(1000);
     digitalWrite(vioce_8, LOW);  // To play vioce-8(Be Happy)
     delay(1000);    
}
}
} 

