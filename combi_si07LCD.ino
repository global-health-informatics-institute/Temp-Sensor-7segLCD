 #include <Wire.h>
#define si7021Addr 0x40
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
//int volume;
int seg1;
int seg2;
int cont;
int counter;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.


  
  Wire.begin();
  Serial.begin(9600);
  Wire.beginTransmission(si7021Addr);
  Wire.endTransmission();
  
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
  delay(300);
  
}

void loop() {
  unsigned int data[2];
    Wire.beginTransmission(si7021Addr);
    Wire.write(0xF3);
    Wire.endTransmission();
    delay(500);
   Wire.requestFrom(si7021Addr, 2);
 // Read 2 bytes of data for temperature  
    if(Wire.available() == 2)
  {
    data[0] = Wire.read();
    data[1] = Wire.read();
  }// Convert the data
  float temp  = ((data[0] * 256.0) + data[1]);
  float celsTemp = ((175.72 * temp) / 65536.0) - 46.85;
  float fahrTemp = celsTemp * 1.8 + 32;
  
 Serial.println(celsTemp);
  Serial.print(seg1);
  Serial.print(seg2);
  Serial.println();
  int temperature = round(celsTemp);

  seg2 = temperature%10;
  seg1=(temperature/10)%10;
  
  switch (seg2)
  
  {
   case 0: 
   digitalWrite(segment2_1, HIGH); 
   digitalWrite(segment2_2, HIGH);
   digitalWrite(segment2_3, HIGH);
   digitalWrite(segment2_4, HIGH);
   digitalWrite(segment2_5, HIGH);
   digitalWrite(segment2_6, HIGH);
   digitalWrite(ground, LOW);
  
   break;
        
   case 1:
  digitalWrite(segment2_2, HIGH);
  digitalWrite(segment2_3, HIGH);
  digitalWrite(ground, LOW);
   break;

   case 2:
   digitalWrite(segment2_1, HIGH); 
   digitalWrite(segment2_2, HIGH);
   digitalWrite(segment2_4, HIGH);
   digitalWrite(segment2_5, HIGH);
   digitalWrite(segment2_7, HIGH);
   digitalWrite(ground, LOW);
   break;
   
   case 3:
   digitalWrite(segment2_1, HIGH); 
   digitalWrite(segment2_2, HIGH);
   digitalWrite(segment2_3, HIGH);
   digitalWrite(segment2_4, HIGH);
   digitalWrite(segment2_7, HIGH);
   digitalWrite(ground, LOW);
   break;
   
   case 4:
   digitalWrite(segment2_3, HIGH); 
   digitalWrite(segment2_2, HIGH);
   digitalWrite(segment2_6, HIGH);
   digitalWrite(segment2_7, HIGH);
  digitalWrite(ground, LOW);
   break;

   case 5:
   digitalWrite(segment2_1, HIGH); 
   digitalWrite(segment2_3, HIGH);
   digitalWrite(segment2_4, HIGH);
   digitalWrite(segment2_7, HIGH);
   digitalWrite(segment2_6, HIGH);
   digitalWrite(ground, LOW);
   break;
   
case 6:
   digitalWrite(segment2_1, HIGH); 
   digitalWrite(segment2_7, HIGH);
   digitalWrite(segment2_3, HIGH);
   digitalWrite(segment2_4, HIGH);
   digitalWrite(segment2_5, HIGH);
   digitalWrite(segment2_6, HIGH);
   digitalWrite(ground, LOW);
 break;
   case 7:
   digitalWrite(segment2_1, HIGH);
   digitalWrite(segment2_2, HIGH);
   digitalWrite(segment2_3, HIGH);
   digitalWrite(ground, LOW);
   break;

    case 8: 
   digitalWrite(segment2_1, HIGH); 
   digitalWrite(segment2_2, HIGH);
   digitalWrite(segment2_3, HIGH);
   digitalWrite(segment2_4, HIGH);
   digitalWrite(segment2_5, HIGH);
   digitalWrite(segment2_6, HIGH);
   digitalWrite(segment2_7, HIGH);
   digitalWrite(ground, LOW);
   break;
   
   
  }

  ///second seg starting

   switch (seg1)
  {
    case 0: 
   digitalWrite(segment1_1, HIGH); 
   digitalWrite(segment1_2, HIGH);
   digitalWrite(segment1_3, HIGH);
   digitalWrite(segment1_4, HIGH);
   digitalWrite(segment1_5, HIGH);
   digitalWrite(segment1_6, HIGH);
   digitalWrite(ground, LOW);
   break;
        
   case 1:
  digitalWrite(segment1_2, HIGH);
  digitalWrite(segment1_3, HIGH);
  digitalWrite(ground, LOW);
   break;

   case 2:
   digitalWrite(segment1_1, HIGH); 
   digitalWrite(segment1_2, HIGH);
   digitalWrite(segment1_4, HIGH);
   digitalWrite(segment1_5, HIGH);
   digitalWrite(segment1_7, HIGH);
   digitalWrite(ground, LOW);
   break;
   
   case 3:
   digitalWrite(segment1_1, HIGH); 
   digitalWrite(segment1_2, HIGH);
   digitalWrite(segment1_3, HIGH);
   digitalWrite(segment1_4, HIGH);
   digitalWrite(segment1_7, HIGH);
   digitalWrite(ground, LOW);
   break;
   
   case 4:
   digitalWrite(segment1_3, HIGH); 
   digitalWrite(segment1_2, HIGH);
   digitalWrite(segment1_6, HIGH);
   digitalWrite(segment1_7, HIGH);
   digitalWrite(ground, LOW);
   break;

   case 5:
   digitalWrite(segment1_1, HIGH); 
   digitalWrite(segment1_3, HIGH);
   digitalWrite(segment1_4, HIGH);
   digitalWrite(segment1_7, HIGH);
   digitalWrite(segment1_6, HIGH);
   digitalWrite(ground, LOW);
   break;
   
   case 6:
   digitalWrite(segment1_1, HIGH); 
   digitalWrite(segment1_7, HIGH);
   digitalWrite(segment1_3, HIGH);
   digitalWrite(segment1_4, HIGH);
   digitalWrite(segment1_5, HIGH);
   digitalWrite(segment1_6, HIGH);
   digitalWrite(ground, LOW);
   break;

   case 7:
  digitalWrite(segment1_1, HIGH);
  digitalWrite(segment1_2, HIGH);
  digitalWrite(segment1_3, HIGH);
  digitalWrite(ground, LOW);
   break;

    case 8: 
   digitalWrite(segment1_1, HIGH); 
   digitalWrite(segment1_2, HIGH);
   digitalWrite(segment1_3, HIGH);
   digitalWrite(segment1_4, HIGH);
   digitalWrite(segment1_5, HIGH);
   digitalWrite(segment1_6, HIGH);
   digitalWrite(segment1_7, HIGH);
   digitalWrite(ground, LOW);
   break;
   
    
  }
   
  delay(500);

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
  

  





