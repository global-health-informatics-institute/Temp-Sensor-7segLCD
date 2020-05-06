#include <dht.h>

#define dht_apin 13 // sensor Pin is connected to
 
dht DHT;
const int segment1_1 = 2;
const int segment1_2= 4;
const int segment1_3 =5;
const int segment1_4 =12;
const int segment1_5 =14;
const int segment1_6 =16;
const int segment1_7 =17;
const int segment2_1 =18;
const int segment2_2 =19;
const int segment2_3 =33;
const int segment2_4 =32;
const int segment2_5 =23;
const int segment2_6 =25;
const int segment2_7 =26;
const int ground  = 27;
int seg1;
int seg2;
 
void setup()
{
  Serial.begin(9600);
  
  pinMode(segment1_1, OUTPUT);
  pinMode(segment1_2, OUTPUT);
  pinMode(segment1_3, OUTPUT);
  pinMode(segment1_4, OUTPUT);
  pinMode(segment1_5, OUTPUT);
  pinMode(segment1_6, OUTPUT);
  pinMode(segment1_7, OUTPUT);
  pinMode(segment2_1, OUTPUT);
  pinMode(segment2_2, OUTPUT);
  pinMode(segment2_3, OUTPUT);
  pinMode(segment2_4, OUTPUT);
  pinMode(segment2_5, OUTPUT);
  pinMode(segment2_6, OUTPUT);
  pinMode(segment2_7, OUTPUT);
  pinMode(ground,    OUTPUT);
  allPinsLOW();
  delay(300);//Wait before accessing Sensor
}
 
void loop(){
  DHT.read11(dht_apin);
  updateLCD(DHT.temperature); 
  delay(25);
  alternate();
  
}

//Function to display temperature on LCD
void updateLCD(int temperature)
{
  Serial.println(temperature);
  seg1 = (temperature/10)%10; // Extracting the first digit from temperature
  seg2 = temperature%10; // Extracting the second digit from temperature

  //Print First digit
  if(seg1 == 0){
   digitalWrite(segment1_1, HIGH); 
   digitalWrite(segment1_2, HIGH);
   digitalWrite(segment1_3, HIGH);
   digitalWrite(segment1_4, HIGH);
   digitalWrite(segment1_5, HIGH);
   digitalWrite(segment1_6, HIGH);
   digitalWrite(segment1_7, LOW);
   digitalWrite(ground, LOW);
  }
  else if(seg1 == 1){
   digitalWrite(segment1_1, LOW); 
   digitalWrite(segment1_2, HIGH);
   digitalWrite(segment1_3, HIGH);
   digitalWrite(segment1_4, LOW);
   digitalWrite(segment1_5, LOW);
   digitalWrite(segment1_6, LOW);
   digitalWrite(segment1_7, LOW);
   digitalWrite(ground, LOW);
  }
  else if(seg1 == 2){
   digitalWrite(segment1_1, HIGH); 
   digitalWrite(segment1_2, HIGH);
   digitalWrite(segment1_3, LOW);
   digitalWrite(segment1_4, HIGH);
   digitalWrite(segment1_5, HIGH);
   digitalWrite(segment1_6, LOW);
   digitalWrite(segment1_7, HIGH);
   digitalWrite(ground, LOW);
  }
  else if(seg1 == 3){
   digitalWrite(segment1_1, HIGH); 
   digitalWrite(segment1_2, HIGH);
   digitalWrite(segment1_3, HIGH);
   digitalWrite(segment1_4, HIGH);
   digitalWrite(segment1_5, LOW);
   digitalWrite(segment1_6, LOW);
   digitalWrite(segment1_7, HIGH);
   digitalWrite(ground, LOW);
  }
  else if(seg1 == 4){
   digitalWrite(segment1_1, LOW); 
   digitalWrite(segment1_2, HIGH);
   digitalWrite(segment1_3, HIGH);
   digitalWrite(segment1_4, LOW);
   digitalWrite(segment1_5, LOW);
   digitalWrite(segment1_6, HIGH);
   digitalWrite(segment1_7, HIGH);
   digitalWrite(ground, LOW);
  }
  else if(seg1 == 5){
   digitalWrite(segment1_1, HIGH); 
   digitalWrite(segment1_2, LOW);
   digitalWrite(segment1_3, HIGH);
   digitalWrite(segment1_4, HIGH);
   digitalWrite(segment1_5, LOW);
   digitalWrite(segment1_6, HIGH);
   digitalWrite(segment1_7, HIGH);
   digitalWrite(ground, LOW);
  }
  else if(seg1 == 6){
   digitalWrite(segment1_1, HIGH); 
   digitalWrite(segment1_2, LOW);
   digitalWrite(segment1_3, HIGH);
   digitalWrite(segment1_4, HIGH);
   digitalWrite(segment1_5, HIGH);
   digitalWrite(segment1_6, HIGH);
   digitalWrite(segment1_7, LOW);
   digitalWrite(ground, LOW);
  }
  else if(seg1 == 7){
   digitalWrite(segment1_1, HIGH); 
   digitalWrite(segment1_2, HIGH);
   digitalWrite(segment1_3, HIGH);
   digitalWrite(segment1_4, LOW);
   digitalWrite(segment1_5, LOW);
   digitalWrite(segment1_6, LOW);
   digitalWrite(segment1_7, LOW);
   digitalWrite(ground, LOW);
  }
  else if(seg1 == 8){
   digitalWrite(segment1_1, HIGH); 
   digitalWrite(segment1_2, HIGH);
   digitalWrite(segment1_3, HIGH);
   digitalWrite(segment1_4, HIGH);
   digitalWrite(segment1_5, HIGH);
   digitalWrite(segment1_6, HIGH);
   digitalWrite(segment1_7, HIGH);
   digitalWrite(ground, LOW);
  }
  else if(seg1 == 9){
   digitalWrite(segment1_1, HIGH); 
   digitalWrite(segment1_2, HIGH);
   digitalWrite(segment1_3, HIGH);
   digitalWrite(segment1_4, HIGH);
   digitalWrite(segment1_5, LOW);
   digitalWrite(segment1_6, HIGH);
   digitalWrite(segment1_7, HIGH);
   digitalWrite(ground, LOW);
  }

  //Print Second digit
  if(seg2 == 0){
   digitalWrite(segment2_1, HIGH); 
   digitalWrite(segment2_2, HIGH);
   digitalWrite(segment2_3, HIGH);
   digitalWrite(segment2_4, HIGH);
   digitalWrite(segment2_5, HIGH);
   digitalWrite(segment2_6, HIGH);
   digitalWrite(segment2_7, LOW);
   digitalWrite(ground, LOW);
  }
  else if(seg2 == 1){
   digitalWrite(segment2_1, LOW); 
   digitalWrite(segment2_2, HIGH);
   digitalWrite(segment2_3, HIGH);
   digitalWrite(segment2_4, LOW);
   digitalWrite(segment2_5, LOW);
   digitalWrite(segment2_6, LOW);
   digitalWrite(segment2_7, LOW);
   digitalWrite(ground, LOW);
  }
  else if(seg2 == 2){
   digitalWrite(segment2_1, HIGH); 
   digitalWrite(segment2_2, HIGH);
   digitalWrite(segment2_3, LOW);
   digitalWrite(segment2_4, HIGH);
   digitalWrite(segment2_5, HIGH);
   digitalWrite(segment2_6, LOW);
   digitalWrite(segment2_7, HIGH);
   digitalWrite(ground, LOW);
  }
  else if(seg2 == 3){
   digitalWrite(segment2_1, HIGH); 
   digitalWrite(segment2_2, HIGH);
   digitalWrite(segment2_3, HIGH);
   digitalWrite(segment2_4, HIGH);
   digitalWrite(segment2_5, LOW);
   digitalWrite(segment2_6, LOW);
   digitalWrite(segment2_7, HIGH);
   digitalWrite(ground, LOW);
  }
  else if(seg2 == 4){
   digitalWrite(segment2_1, LOW); 
   digitalWrite(segment2_2, HIGH);
   digitalWrite(segment2_3, HIGH);
   digitalWrite(segment2_4, LOW);
   digitalWrite(segment2_5, LOW);
   digitalWrite(segment2_6, HIGH);
   digitalWrite(segment2_7, HIGH);
   digitalWrite(ground, LOW);
  }
  else if(seg2 == 5){
   digitalWrite(segment2_1, HIGH); 
   digitalWrite(segment2_2, LOW);
   digitalWrite(segment2_3, HIGH);
   digitalWrite(segment2_4, HIGH);
   digitalWrite(segment2_5, LOW);
   digitalWrite(segment2_6, HIGH);
   digitalWrite(segment2_7, HIGH);
   digitalWrite(ground, LOW);
  }
  else if(seg2 == 6){
   digitalWrite(segment2_1, HIGH); 
   digitalWrite(segment2_2, LOW);
   digitalWrite(segment2_3, HIGH);
   digitalWrite(segment2_4, HIGH);
   digitalWrite(segment2_5, HIGH);
   digitalWrite(segment2_6, HIGH);
   digitalWrite(segment2_7, LOW);
   digitalWrite(ground, LOW);
  }
  else if(seg2 == 7){
   digitalWrite(segment2_1, HIGH); 
   digitalWrite(segment2_2, HIGH);
   digitalWrite(segment2_3, HIGH);
   digitalWrite(segment2_4, LOW);
   digitalWrite(segment2_5, LOW);
   digitalWrite(segment2_6, LOW);
   digitalWrite(segment2_7, LOW);
   digitalWrite(ground, LOW);
  }
  else if(seg2 == 8){
   digitalWrite(segment2_1, HIGH); 
   digitalWrite(segment2_2, HIGH);
   digitalWrite(segment2_3, HIGH);
   digitalWrite(segment2_4, HIGH);
   digitalWrite(segment2_5, HIGH);
   digitalWrite(segment2_6, HIGH);
   digitalWrite(segment2_7, HIGH);
   digitalWrite(ground, LOW);
  }
  else if(seg2 == 9){
   digitalWrite(segment2_1, HIGH); 
   digitalWrite(segment2_2, HIGH);
   digitalWrite(segment2_3, HIGH);
   digitalWrite(segment2_4, HIGH);
   digitalWrite(segment2_5, LOW);
   digitalWrite(segment2_6, HIGH);
   digitalWrite(segment2_7, HIGH);
   digitalWrite(ground, LOW);
  }  
}

void alternate()
{
   digitalWrite(segment1_1, LOW); 
   digitalWrite(segment1_2, LOW);
   digitalWrite(segment1_3, LOW);
   digitalWrite(segment1_4, LOW);
   digitalWrite(segment1_5, LOW);
   digitalWrite(segment1_6, LOW);
   digitalWrite(segment1_7, LOW);
   digitalWrite(segment2_1, LOW); 
   digitalWrite(segment2_2, LOW);
   digitalWrite(segment2_3, LOW);
   digitalWrite(segment2_4, LOW);
   digitalWrite(segment2_5, LOW);
   digitalWrite(segment2_6, LOW);
   digitalWrite(segment2_7, LOW);
   digitalWrite(ground, HIGH);
}

void allPinsLOW()
{
    digitalWrite(segment1_1, LOW); 
   digitalWrite(segment1_2, LOW);
   digitalWrite(segment1_3, LOW);
   digitalWrite(segment1_4, LOW);
   digitalWrite(segment1_5, LOW);
   digitalWrite(segment1_6, LOW);
   digitalWrite(segment1_7, LOW);
   digitalWrite(segment2_1, LOW); 
   digitalWrite(segment2_2, LOW);
   digitalWrite(segment2_3, LOW);
   digitalWrite(segment2_4, LOW);
   digitalWrite(segment2_5, LOW);
   digitalWrite(segment2_6, LOW);
   digitalWrite(segment2_7, LOW);
   digitalWrite(ground, LOW);
}
