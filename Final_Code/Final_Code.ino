#include <Shieldbot.h> //includes the Shieldbot Library
Shieldbot shieldbot = Shieldbot(); //decares a Shieldbot object
unsigned long A2counter=0;
unsigned long A4counter=0;
int S1,S3,S5; //values to store state of sensors
void setup() {
 // put your setup code here, to run once:
pinMode(A2,INPUT);
pinMode(A4,INPUT);
Serial.begin(9600);//Begin serial comm for debugging
shieldbot.setMaxSpeed(50,50);//255 is max, if one motor is faster than another, adjust values 
}
void loop() {
 // put your main code here, to run repeatedly:
int valSENSOR1 = analogRead(A2);
int valSENSOR2 = analogRead(A4);
 S1 = shieldbot.readS1();
 S3 = shieldbot.readS3();
 S5 = shieldbot.readS5();
 //Print the status of each sensor to the Serial console
 Serial.print("S5: ");
 Serial.print(S5);
 Serial.print(" S3: ");
 Serial.print(S3);
 Serial.print(" S1: ");
 Serial.print(S1);
 Serial.println();
 //Note about IR sensors 
 //if a sensor sees HIGH, it means that it just sees a reflective surface background (eg. white)
 //if a sensor sees LOW, it means that it sees a non-reflective surface or empty space (ex. black tape line, or 
empty space off ledge)
 
//////////////////////////////////GOINGFORWARD//////////////////////////////
if(S1 == LOW && S5 == LOW && A4counter==0){ //if the two outer IR line sensors see background, go 
forward
shieldbot.forward();
Serial.println("Forward");
if(A4counter<40){
int Counter_Difference= A4counter-A2counter; //The sheildbot always turns left. Any change in counter 
difference turn right abit so it goes straight
if (Counter_Difference=0){
shieldbot.forward(); 
}
else if(Counter_Difference>0){
shieldbot.drive(127,64);
delay(250);
A2counter=A4counter;
}
else if(Counter_Difference<0){
shieldbot.drive(127,64);
delay(250);
A2counter=A4counter;
}
}
else if (A4counter>40){
//should be reverse/ neg but still turn left so a bit of cali bra for b
shieldbot.stop();
delay(2000);
shieldbot.backward();
delay(10000);
int Counter_Difference= A4counter-A2counter; //The sheildbot always turns left. Any change in counter 
difference turn right abit so it goes straight
if (Counter_Difference=0){
shieldbot.backward(); 
}
else if(Counter_Difference>0){
shieldbot.drive(-127,-64);
delay(250);
A2counter=A4counter;
}
else if(Counter_Difference<0){
shieldbot.drive(-127,-64);
delay(250);
A2counter=A4counter;
}
}
else if(A4counter>80){
shieldbot.stop();
delay(5000);
A4counter=0;
A2counter=0;
}
}
////////////////////////////////////GOING LEFT/////////////////////////////////
else if(S5 == LOW && S1 == HIGH && A4counter==0){ //if either of the two outer IR line sensors see empty 
space (like edge of a table) stop moving
shieldbot.drive(-128,127);// left
if (A4counter>6){
shieldbot.stop();
shieldbot.forward();
delay(10000);
int Counter_Difference= A4counter-A2counter; //The sheildbot always turns left. Any change in counter 
difference turn right abit so it goes straight
if (Counter_Difference=0){
shieldbot.forward(); 
}
else if(Counter_Difference>0){
shieldbot.drive(127,64);
delay(250);
A2counter=A4counter;
}
else if(Counter_Difference<0){
shieldbot.drive(127,64);
delay(250);
A2counter=A4counter;
} 
} // should be the same number of ticks as right
//ticks to move left +9
else if (A4counter<15){
shieldbot.stop();
shieldbot.drive(127,-128);// right
}
else if (A4counter<21){
shieldbot.stop();
shieldbot.forward();
delay(10000);
int Counter_Difference= A4counter-A2counter; //The sheildbot always turns left. Any change in counter 
difference turn right abit so it goes straight
if (Counter_Difference=0){
shieldbot.forward(); 
}
else if(Counter_Difference>0){
shieldbot.drive(127,64);
delay(250);
A2counter=A4counter;
}
else if(Counter_Difference<0){
shieldbot.drive(127,64);
delay(250);
A2counter=A4counter;
}
}
else if (A4counter<27){
shieldbot.stop();
delay(2000);
shieldbot.backward();
delay(10000);
int Counter_Difference= A4counter-A2counter; //The sheildbot always turns left. Any change in counter 
difference turn right abit so it goes straight
if (Counter_Difference=0){
shieldbot.backward(); 
}
else if(Counter_Difference>0){
shieldbot.drive(-127,-64);
delay(250);
A2counter=A4counter;
}
else if(Counter_Difference<0){
shieldbot.drive(-127,-64);
delay(250);
A2counter=A4counter;
}
}
else if (A4counter<33){
shieldbot.stop();
shieldbot.drive(-128,127);// left
} 
else if (A4counter<39){
shieldbot.stop();
shieldbot.backward();
delay(10000);
int Counter_Difference= A4counter-A2counter; //The sheildbot always turns left. Any change in counter 
difference turn right abit so it goes straight
if (Counter_Difference=0){
shieldbot.backward(); 
}
else if(Counter_Difference>0){
shieldbot.drive(-127,-64);
delay(250);
A2counter=A4counter;
}
else if(Counter_Difference<0){
shieldbot.drive(-127,-64);
delay(250);
A2counter=A4counter;
}
}
else if (A4counter<48){
shieldbot.stop();
shieldbot.drive(127,-128);// right
}
else if (A4counter<54){
shieldbot.stop();
delay(5000);
A4counter=0;
A2counter=0;
}
Serial.println("Left");
}
////////////////////////////////////////////////////////////
////////////// GOING RIGHT///////////////////
else if(S5 == HIGH && S1 == LOW && A4counter==0){ //if either of the two outer IR line sensors see empty 
space (like edge of a table) stop moving
shieldbot.drive(127,-128);// RIGHT
if (A4counter>6){
shieldbot.stop();
shieldbot.forward();
delay(10000);
int Counter_Difference= A4counter-A2counter; //The sheildbot always turns left. Any change in counter 
difference turn right abit so it goes straight
if (Counter_Difference=0){
shieldbot.forward(); 
}
else if(Counter_Difference>0){
shieldbot.drive(127,64);
delay(250);
A2counter=A4counter;
}
else if(Counter_Difference<0){
shieldbot.drive(127,64);
delay(250);
A2counter=A4counter;
} 
} // should be the same number of ticks as right
//ticks to move RIGHT +9
else if (A4counter<15){
shieldbot.stop();
shieldbot.drive(-128,127);// LEFT
}
else if (A4counter<21){
shieldbot.stop();
shieldbot.forward();
delay(10000);
int Counter_Difference= A4counter-A2counter; //The sheildbot always turns left. Any change in counter 
difference turn right abit so it goes straight
if (Counter_Difference=0){
shieldbot.forward(); 
}
else if(Counter_Difference>0){
shieldbot.drive(127,64);
delay(250);
A2counter=A4counter;
}
else if(Counter_Difference<0){
shieldbot.drive(127,64);
delay(250);
A2counter=A4counter;
}
}
else if (A4counter<27){
shieldbot.stop();
delay(2000);
shieldbot.backward();
delay(10000);
int Counter_Difference= A4counter-A2counter; //The sheildbot always turns left. Any change in counter 
difference turn right abit so it goes straight
if (Counter_Difference=0){
shieldbot.backward(); 
}
else if(Counter_Difference>0){
shieldbot.drive(-127,-64);
delay(250);
A2counter=A4counter;
}
else if(Counter_Difference<0){
shieldbot.drive(-127,-64);
delay(250);
A2counter=A4counter;
}
}
else if (A4counter<33){
shieldbot.stop();
shieldbot.drive(127,-128);// RIGHT
} 
else if (A4counter<39){
shieldbot.stop();
shieldbot.backward();
delay(10000);
int Counter_Difference= A4counter-A2counter; //The sheildbot always turns left. Any change in counter 
difference turn right abit so it goes straight
if (Counter_Difference=0){
shieldbot.backward(); 
}
else if(Counter_Difference>0){
shieldbot.drive(-127,-64);
delay(250);
A2counter=A4counter;
}
else if(Counter_Difference<0){
shieldbot.drive(-127,-64);
delay(250);
A2counter=A4counter;
}
}
else if (A4counter<48){
shieldbot.stop();
shieldbot.drive(-128,127);// LEFT
}
else if (A4counter<54){
shieldbot.stop();
delay(5000);
A4counter=0;
A2counter=0;
}
Serial.println("RIGHT");
}
/////////////////////////////////////////////////////////////////////////
else //otherwise just go forward
shieldbot.forward();
if(valSENSOR1<900){
 Serial.println("Low / 1st sensor with A2");
 
} else if (valSENSOR1>980){
 Serial.println("High / 1st sensor with A2");
 A2counter++;
 Serial.println(A2counter);
 }
if(valSENSOR2<50){
 Serial.println("Low / 2nd sensor with A4");
 
} else if (valSENSOR2>100){
 Serial.println("High / 2nd sensor with A4");
 A4counter++;
 Serial.println(A4counter);
 }
}
