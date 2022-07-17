#include<Wire.h>
uint8_t buf[8] = { 0 };
 
const int MPU_addr=0x68;
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
 
int minVal=265;
int maxVal=402;
 
double x;
double y;
double Xdiff;
double Ydiff;

bool runningX = true;
bool runningY = true;
 
void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
}
void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);
  AcX=Wire.read()<<8|Wire.read();
  AcY=Wire.read()<<8|Wire.read();
  AcZ=Wire.read()<<8|Wire.read();
  int xAng = map(AcX,minVal,maxVal,-90,90);
  int yAng = map(AcY,minVal,maxVal,-90,90);
  int zAng = map(AcZ,minVal,maxVal,-90,90);
   
  x= RAD_TO_DEG * (atan2(-yAng, -zAng)+PI);
  y= RAD_TO_DEG * (atan2(-xAng, -zAng)+PI);

  Xdiff = (x<180)? x : (360-x);
  Ydiff = (y<160)? (y+20):abs(340 - y);

  if(x<5 || x>355){
    runningX = true;
  }
  if(y < 345 && y > 335){
    runningY = true;
  }
  
  if(Xdiff > Ydiff){
    
    //When button representing W is pressed  
    if (x > 50 && x < 180 && runningX == true) { 
      buf[2] = 4;   // A keycode
      Serial.write(buf, 8); // Send keypress
//      Serial.println("A");
      releaseKey();
      runningX = false;
    }

    //When button representing S is pressed
    else if (x < 320 && x > 180 && runningX == true) {
      buf[2] = 7;   // D keycode
      Serial.write(buf, 8); // Send keypress
//      Serial.println("D");
      releaseKey();
      runningX = false;
    } 
  }
  else if(Xdiff < Ydiff){
    
    //When button representing A is pressed
    if (y > 10 && y < 160 && runningY == true) {
    buf[2] = 22;   // S keycode
    Serial.write(buf, 8); // Send keypress
//    Serial.println("S");
    releaseKey();
    runningY = false;
    } 
  
    //When button representing D is pressed
    else if (y < 310 && y > 160 && runningY == true) {
    buf[2] = 26;   // W keycode
    Serial.write(buf, 8); // Send keypress
//    Serial.println("W");
    releaseKey();
    runningY = false;
    } 
  }
  Xdiff = 0;
  Ydiff = 0;
}

// Function for Key Release
void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Send Release key  
}
