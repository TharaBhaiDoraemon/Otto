#include<Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
char data;
#define trigpin 8
#define echopin 9
float distance;
float duration;
int pos;
 
 void setup(){
pinMode(8,OUTPUT);
pinMode(9,INPUT);
 servo1.attach(2);
 servo2.attach(3);
 servo3.attach(4);
 servo4.attach(5);
 Serial.begin(9600);

}

void onwheels (){
  servo1.write(0);// on wheels
  servo3.write(175);// on wheels
 }
void onfoot(){  
  servo1.write(105);// on foot,decrease to go to wheels
  servo3.write(70);// on foot,increase to go on to wheels
  }

void forward (){
  servo1.write(5);// on wheels
  servo3.write(170);// on wheels
  servo2.writeMicroseconds(1250);//half speed in clockwise direction 
  servo4.writeMicroseconds(1750);//half speed in clockwise direction
}
void backward (){
  servo1.write(5);// on wheels
  servo3.write(170);// on wheels
  servo2.writeMicroseconds(1750);// half speed in  anti clockwise direction
  servo4.writeMicroseconds(1250);//half speed in anti clockwise direction 
} 
void Stop (){
  servo2.write(90);// wheels at rest
  servo4.write(90);// wheels at rest
}
void right (){
  servo1.write(5);// on wheels
  servo3.write(170);// on wheels
  servo2.writeMicroseconds(1250);// half speed in clockwise direction
  servo4.writeMicroseconds(1250);//half speed in anti clockwise direction 
}
  void left (){
  servo1.write(5);// on wheels
  servo3.write(170);// on wheels
  servo2.writeMicroseconds(1750);// half speed in  anti clockwise direction
  servo4.writeMicroseconds(1750);//half speed in clockwise direction 
}
 
 //-----------------------------------------------------------------

 void walk(){
  servo1.write(105);// on foot,decrease to go to wheels
  servo3.write(70);// on foot,increase to go on to wheels
 

 //starting first step
 for(pos=70;pos>=10;pos-=1){servo3.write(pos);
 delay(3);}
 for(pos=105;pos>=60;pos-=1){servo1.write(pos);
 delay(3);}
 
 delay(400);
 
 servo2.writeMicroseconds(1200);//half speed clockwise
 delay(170);
 servo2.write(90);
 delay(200);
 // first step done
  
  for(pos=60;pos<=105;pos+=1){servo1.write(pos);
 delay(3);}
  for(pos=10;pos<=70;pos+=1){servo3.write(pos);
 delay(2);}
 delay(500);
 //both feet on ground

 //starting second step
 for(pos=105;pos<=160;pos+=1){servo1.write(pos);
 delay(3);}
 for(pos=70;pos<=110;pos+=1){servo3.write(pos);
 delay(3);}
  
 delay(400);
 servo4.writeMicroseconds(1800);//clockwise
 delay(170);
 servo4.write(90);
 delay(200);

 for(pos=110;pos>=70;pos-=1){servo3.write(pos);
 delay(3);}
 for(pos=160;pos>=105;pos-=1){servo1.write(pos);
 delay(2);}
 
 delay(500);
 //both feet on ground
 // second step done
 }

void dance()
{
 // both feet on ground
 for(pos=110;pos>=70;pos-=1){servo3.write(pos);
 delay(3);}
 for(pos=160;pos>=105;pos-=1){servo1.write(pos);
 delay(2);}
 delay(200);

 // first step
 for(pos=70;pos>=10;pos-=1){servo3.write(pos);
 delay(3);}
 for(pos=105;pos>=60;pos-=1){servo1.write(pos);
 delay(3);}
 delay(100);

 // rotation
 servo2.writeMicroseconds(1200);//half speed clockwise
 delay(2500);
 servo2.write(90);

 // both feet on ground
 for(pos=60;pos<=105;pos+=1){servo1.write(pos);
 delay(3);}
 for(pos=10;pos<=70;pos+=1){servo3.write(pos);
 delay(2);}
 delay(200);

 // second step
 for(pos=105;pos<=160;pos+=1){servo1.write(pos);
 delay(3);}
 for(pos=70;pos<=110;pos+=1){servo3.write(pos);
 delay(3);}
 delay(100);

 // rotation
 servo4.writeMicroseconds(1820);//clockwise
 delay(2500);
 servo4.write(90);
  }
void moonwalk(){
 
  for(pos=70;pos>=5;pos-=1){servo3.write(pos);
 delay(4);}
  for(pos=105;pos<=160;pos+=1){servo1.write(pos);
 delay(1);}
 for(pos=15;pos<=70;pos+=1){servo3.write(pos);
 delay(2);}
 for(pos=150;pos>=105;pos-=1){servo1.write(pos);
 delay(7);}
  }
  
void loop() {
digitalWrite(trigpin,HIGH);
delay(10);
digitalWrite(trigpin,LOW);

duration= pulseIn(echopin,HIGH);
distance=0.034*(duration/2);



if(Serial.available())
{data=Serial.read();}

if(distance<15)
{ Stop();
}

 else if(data=='a'){
  forward();}
 else if(data=='c'){
  right();}
else if(data=='b'){
  backward();}
  else if(data=='d'){
  left();}
else if(data=='g'){
  servo1.write(105);// on foot,decrease to go to wheels
  servo3.write(70);// on foot,increase to go on to wheels and to go  back 
  walk();}  
  else if(data=='h'){
  dance();}
  else if(data=='i'){
  onfoot();}
  else if(data=='k'){
  onwheels();}
  else if(data=='f'){
  Stop();}
  else if(data=='e')
  {servo1.write(105);// on foot,decrease to go to wheels
  servo3.write(70);// on foot,increase to go on to wheels
  delay(200);
  moonwalk();}
  
  else if
  (data=='o')
  {
  servo2.write(90);// wheels at rest
  servo4.write(90);}// on foot,increase to go on to wheels
  
  else{servo1.write(105);// on foot,decrease to go to wheels
  servo3.write(70);}// on foot,increase to go on to wheels
  
}
