#include <SoftwareSerial.h>
#include <Servo.h>
Servo myservo1, myservo2;

int motor1pin1 = 2;
int motor1pin2 = 3;
int motor2pin1=4;
int motor2pin2=5;
int motor3pin1=6;
int motor3pin2=7;
int motor4pin1=8;
int motor4pin2=9;
int number;

String read1;

void setup() 
//Read from bluetooth and write to usb serial
  {
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor3pin1, OUTPUT);
  pinMode(motor4pin1, OUTPUT);
  pinMode(motor4pin2, OUTPUT);
//  pinMode(pump1,OUTPUT);
  Serial.begin(9600);
  myservo1.attach(10);
}

void loop()  
{  while(Serial.available()){
    delay(50);
    char c=Serial.read();
    read1+=c;
    number = Serial.parseInt();
    Serial.println(number);
    read1+=number;
   }
  if(read1.length()>0){
    if (read1 >= 1000 && number <1180) {
      int servo1 = number;
      servo1 = map(servo1, 1000, 1180, 0, 180);
      myservo1.write(servo1);
      Serial.println("Servo 1 ON");
      delay(10);
    }
    if (number >= 2000 && number <2180) {
      int servo2 = number;
      servo2 = map(servo2, 2000, 2180, 0, 180);
      myservo2.write(servo2);
      Serial.println("Servo 2 ON");
      delay(10);
    }
    if(read1=="FORWARD"){
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);
      digitalWrite(motor2pin1,LOW);
      digitalWrite(motor2pin2,HIGH);
      digitalWrite(motor3pin1, HIGH);
      digitalWrite(motor3pin2, LOW);
      digitalWrite(motor4pin1,HIGH);
      digitalWrite(motor4pin2,LOW);
    }
    if(read1=="RIGHT"){
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);
      digitalWrite(motor2pin1,HIGH);
      digitalWrite(motor2pin2,LOW);
      digitalWrite(motor3pin1, HIGH);
      digitalWrite(motor3pin2, LOW);
      digitalWrite(motor4pin1,LOW);
      digitalWrite(motor4pin2,HIGH);
    }
    if(read1=="LEFT"){
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);
      digitalWrite(motor2pin1,LOW);
      digitalWrite(motor2pin2,HIGH);
      digitalWrite(motor3pin1, LOW);
      digitalWrite(motor3pin2, HIGH);
      digitalWrite(motor4pin1,HIGH);
      digitalWrite(motor4pin2,LOW);
    }
    if(read1=="STOP"){
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);
      digitalWrite(motor2pin1,LOW);
      digitalWrite(motor2pin2,LOW);
      digitalWrite(motor3pin1, LOW);
      digitalWrite(motor3pin2, LOW);
      digitalWrite(motor4pin1,LOW);
      digitalWrite(motor4pin2,LOW);
    }
    if(read1=="BACK"){
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);
      digitalWrite(motor2pin1,HIGH);
      digitalWrite(motor2pin2,LOW);
      digitalWrite(motor3pin1, LOW);
      digitalWrite(motor3pin2, HIGH);
      digitalWrite(motor4pin1,LOW);
      digitalWrite(motor4pin2,HIGH);
    }

    }
    read1="";
}  
