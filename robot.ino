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
int servo1 = 90;
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
{  
  while(Serial.available())
    {
    delay(50);
    char c=Serial.read();
    read1+=c;
    }
    
  if(Serial.available());
   {
    
    Serial.println(read1);
    if (read1== "ROLLBACK") {
      servo1 =servo1-5;
      myservo1.write(servo1);
      delay(500);
      Serial.println(servo1);
      Serial.println("Servo 1 ON");
      delay(10);

    }
    if (read1== "ROLLFRONT") {
      servo1 =servo1+5;
      myservo1.write(servo1);
      delay(500);
      Serial.println(servo1);
      Serial.println("Servo 1 ON");
      delay(10);

    }
    if (read1== "STOPROLL") {
      servo1=90;
      myservo1.write(90);
      delay(500);
      Serial.println(90);
      Serial.println("STOP 90");
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
