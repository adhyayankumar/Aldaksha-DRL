#include<IBusBM.h>   
#include<AFMotor.h>

IBusBM IBus;

int rcCH1 = 0;
int rcCH2 = 0;
int rcCH3 = 0;
int rcCH4 = 0;
int rcCH5 = 0;
bool rcCH6 = 0;

AF_DCMotor motor1 (1, MOTOR12_1KHZ);
AF_DCMotor motor2 (2, MOTOR12_1KHZ);
AF_DCMotor motor3 (3, MOTOR34_1KHZ);
AF_DCMotor motor4 (4, MOTOR34_1KHZ);

int motorSpeed = 0;

void setup() {

    IBus.begin(Serial);
}

void loop() {
 rcCH1 = map(IBus.readChannel(0), 1000, 2000, 0, 255);
 rcCH2 = map(IBus.readChannel(1), 1000, 2000, 0, 255);
 rcCH3 = map(IBus.readChannel(2), 1000, 2000, 0, 255);
 rcCH4 = map(IBus.readChannel(3), 1000, 2000, 0, 255);
 rcCH5 = map(IBus.readChannel(4), 1000, 2000, 0, 255);
 rcCH6 = IBus.readChannel(5), 

  motorSpeed = rcCH5;

 if(rcCH1 > 150) {
  MoveRight();  
  }else if (rcCH1 < 100) { 
   MoveLeft(); 
  }else if (rcCH2 > 150) { 
   MoveForward();  
  }else if (rcCH2 < 100) {
   MoveBackward();
  }else{ 
   Stop();
  }

 if(rcCH6 == 1) {
   if ((rcCH3 > 150)&&(rcCH4 > 100)){
     MoveTopRight();
    }else if ((rcCH3 > 150)&&(rcCH4 < 100)){
     MoveTopLeft();
    }else if ((rcCH3 < 100)&&(rcCH4 > 150)){
     MoveBackRight();
    }else if ((rcCH3 < 100)&&(rcCH4 < 100)) {
     MoveBackLeft();
    }
  }else{
    if ((rcCH3 > 150)&&(rcCH4 > 100)){
     LeftTurn(); 
    }else if ((rcCH3 > 150)&&(rcCH4 < 100)){
     RightTurn();
    }
  }
}

void MoveForward() { 
 motor1.run(FORWARD);
 motor1.setSpeed(motorSpeed);       
 motor2.run(FORWARD);                
 motor2.setSpeed(motorSpeed);             
 motor3.run(FORWARD);            
 motor3.setSpeed(motorSpeed);        
 motor4.run(FORWARD);           
 motor4.setSpeed(motorSpeed);            
}
void Stop() { 
 motor1.run(RELEASE);                   
 motor1.setSpeed(0);              
 motor2.run(RELEASE);                  
 motor2.setSpeed(0);                      
 motor3.run(RELEASE);               
 motor3.setSpeed(0);              
 motor4.run(RELEASE);                      
 motor4.setSpeed(0);            
}
void MoveBackward () { 
 motor1.run(BACKWARD);                     
 motor1.setSpeed(motorSpeed);         
 motor2.run(BACKWARD);       
 motor2.setSpeed(motorSpeed);             
 motor3.run(BACKWARD);                   
 motor3.setSpeed(motorSpeed);      
 motor4.run(BACKWARD);        
 motor4.setSpeed(motorSpeed);   
}
void MoveRight() { 
  motor1.run(FORWARD);                      
  motor1.setSpeed(motorSpeed);            
  motor2.run(BACKWARD);            
  motor2.setSpeed(motorSpeed);           
  motor3.run(FORWARD);                
  motor3.setSpeed(motorSpeed);         
  motor4.run(BACKWARD);                  
  motor4.setSpeed(motorSpeed);          
}
void MoveLeft() { 
  motor1.run(BACKWARD);         
  motor1.setSpeed(motorSpeed);            
  motor2.run(FORWARD);             
  motor2.setSpeed(motorSpeed);           
  motor3.run(BACKWARD);             
  motor3.setSpeed(motorSpeed);
  motor4.run(FORWARD);                 
  motor4.setSpeed(motorSpeed);  
}
void MoveTopRight() { 
  motor1.run(FORWARD);   
  motor1.setSpeed(motorSpeed);  
  motor2.run(RELEASE);    
  motor2.setSpeed(motorSpeed);
  motor3.run(FORWARD);  
  motor3.setSpeed(motorSpeed);  
  motor4.run(RELEASE);   
  motor4.setSpeed(motorSpeed);    
}
void MoveTopLeft() { 
  motor1.run(RELEASE); 
  motor1.setSpeed(motorSpeed);  
  motor2.run(FORWARD);
  motor2.setSpeed(motorSpeed);  
  motor3.run(RELEASE);  
  motor3.setSpeed(motorSpeed); 
  motor4.run(FORWARD);  
  motor4.setSpeed(motorSpeed); 
}
void MoveBackRight() {
  motor1.run(RELEASE);  
  motor1.setSpeed(motorSpeed); 
  motor2.run(BACKWARD);
  motor2.setSpeed(motorSpeed);  
  motor3.run(RELEASE);   
  motor3.setSpeed(motorSpeed);   
  motor4.run(BACKWARD);      
  motor4.setSpeed(motorSpeed);  
}
void MoveBackLeft() { 
  motor1.run(BACKWARD);   
  motor1.setSpeed(motorSpeed);  
  motor2.run(RELEASE); 
  motor2.setSpeed(motorSpeed); 
  motor3.run(BACKWARD);   
  motor3.setSpeed(motorSpeed); 
  motor4.run(RELEASE); 
  motor4.setSpeed(motorSpeed); 
}
void RightTurn() { 
  motor1.run(FORWARD); 
  motor1.setSpeed(motorSpeed); 
  motor2.run(FORWARD);   
  motor2.setSpeed(motorSpeed);   
  motor3.run(BACKWARD);  
  motor3.setSpeed(motorSpeed);   
  motor4.run(BACKWARD); 
  motor4.setSpeed(motorSpeed); 
}
void LeftTurn() { 
  motor1.run(BACKWARD);
  motor1.setSpeed(motorSpeed); 
  motor2.run(BACKWARD);
  motor2.setSpeed(motorSpeed);
  motor3.run(FORWARD);
  motor3.setSpeed(motorSpeed);
  motor4.run(FORWARD); 
  motor4.setSpeed(motorSpeed);
}