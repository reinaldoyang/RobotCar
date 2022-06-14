#include <SoftwareSerial.h>
#include <Servo.h>

Servo myservo1, myservo2,myservo3,myservo4;
Servo solenoid;

int motor1pin1 = 2;
int motor1pin2 = 3;
int motor2pin1=4;
int motor2pin2=5;
int motor3pin1=6;
int motor3pin2=7;
int motor4pin1=8;
int motor4pin2=9;
int servo1=90;
int servo2 = 90;
int servo3= 90;
int servo4=0;
int vacuum1=12;
int vacuum2=13;
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
  pinMode(vacuum1,OUTPUT);
  pinMode(vacuum2,OUTPUT);
  Serial.begin(9600);
  myservo1.attach(10);
  myservo2.attach(11);
  myservo3.attach(53);
  myservo4.attach(51);
  solenoid.attach(26);
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
    if (read1== "Degree0") {
      myservo1.write(0);
      Serial.println(0);
      Serial.println("Servo 1 ON");
      delay(1000);
    }
    if (read1== "Degree90") {
      myservo1.write(90);
      Serial.println(90);
      Serial.println("Servo 1 ON");
      delay(1000);
    }
    if (read1== "Degree180") {
      myservo1.write(180);
      Serial.println(180);
      Serial.println("Servo 1 ON");
      delay(1000);
    }
    if (read1== "Forward-5") {
      servo1=servo1-5;
      myservo1.write(servo1);
      Serial.println(servo1);
      Serial.println("Servo 1 ON");
      delay(1000);
    }
    if (read1== "Forward+5") {
      servo1 =servo1+5;
      myservo1.write(servo1);
      Serial.println(servo1);
      Serial.println("Servo 1 ON");
      delay(1000);
    }

    
    if (read1== "ROLLFRONT2") {
      servo2 =servo2-5;
      servo3=servo3+5;
      myservo2.write(servo2);
      myservo3.write(servo3);
      Serial.println(servo2);
      Serial.println(servo2);
      Serial.println("Servo 2 ON");
      delay(1000);
    }
    if (read1== "ROLLFRONT2+2") {
      servo2 =servo2-1;
      servo3=servo3+1;
      myservo2.write(servo2);
      myservo3.write(servo3);
      Serial.println(servo2);
      Serial.println(servo2);
      Serial.println("Servo 2 ON");
      delay(1000);
    }
    if (read1== "ROLLBACK2") {
      servo2 =servo2+5;
      servo3=servo3-5;
      myservo2.write(servo2);
      myservo3.write(servo3);
      Serial.println(servo2);
      Serial.println(servo2);
      Serial.println("Servo 2 ON");
      delay(1000);
    }
    if (read1== "ROLLBACK2+2") {
      servo2 =servo2+1;
      servo3=servo3-1;
      myservo2.write(servo2);
      myservo3.write(servo3);
      Serial.println(servo2);
      Serial.println(servo2);
      Serial.println("Servo 2 ON");
      delay(1000);
    }
    if (read1== "STOPROLL") {
      myservo2.write(90);
      myservo3.write(90);
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
    if(read1=="SUCTIONON"){
      solenoid.write(0);
      digitalWrite(vacuum1,LOW);
      digitalWrite(vacuum2,HIGH);
      Serial.println("Vacuum is on");
      delay(1000);
    }
    if(read1=="SUCTIONOFF"){
      digitalWrite(vacuum2,LOW);
      digitalWrite(vacuum1,LOW);
      Serial.println("Solenoid is on");
      solenoid.write(180);
      delay(1000);
    }
     if(read1=="SMALLPLUS"){
     servo4=servo4+10;
     myservo4.write(servo4);
     Serial.println(servo4);
    }
    if(read1=="SMALLMINUS"){
     servo4=servo4-10;
     myservo4.write(servo4);
     Serial.println(servo4);
    }
    }
    read1="";
}  
