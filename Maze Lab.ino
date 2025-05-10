#include "Romi_Motor_Power.h"
/* Defines pin configuration of robot */
#include "RSLK_Pins.h"
#include "SimpleRSLK.h"

float right_speed = 15;
float left_speed = 15;

void setup() {
  // put your setup code here, to run once:
  setupRSLK();

   //set motor directions
  setMotorDirection(BOTH_MOTORS, MOTOR_DIR_FORWARD);
  
   //turn motors ON
   enableMotor(BOTH_MOTORS);

   //initialize bump sensor inputs
  pinMode(BP_SW_PIN_0,INPUT_PULLUP);
  pinMode(BP_SW_PIN_1,INPUT_PULLUP);
  pinMode(BP_SW_PIN_2,INPUT_PULLUP);
  pinMode(BP_SW_PIN_3,INPUT_PULLUP);
  pinMode(BP_SW_PIN_4,INPUT_PULLUP);
  pinMode(BP_SW_PIN_5,INPUT_PULLUP);

  //set motor directions
  setMotorDirection(BOTH_MOTORS, MOTOR_DIR_FORWARD);
  setMotorSpeed(RIGHT_MOTOR, right_speed);
  setMotorSpeed(LEFT_MOTOR, left_speed);
 
}

void stop() {
  setMotorSpeed(BOTH_MOTORS, 0);
}

void reverse() {
  setMotorDirection(BOTH_MOTORS, MOTOR_DIR_BACKWARD);
  setMotorSpeed(RIGHT_MOTOR, right_speed);
  setMotorSpeed(LEFT_MOTOR, left_speed);
}

void turnRight(int degrees) {
  // Assuming that turning right for a certain amount of time corresponds to a certain angle
  setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_BACKWARD);
  setMotorDirection(LEFT_MOTOR, MOTOR_DIR_FORWARD);
  setMotorSpeed(RIGHT_MOTOR, right_speed);
  setMotorSpeed(LEFT_MOTOR, left_speed);
  delay(degrees); //claibrate based on robot?
}

void turnLeft(int degrees) {
  // Assuming that turning left for a certain amount of time corresponds to a certain angle
  setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_FORWARD);
  setMotorDirection(LEFT_MOTOR, MOTOR_DIR_BACKWARD);
  setMotorSpeed(RIGHT_MOTOR, right_speed);
  setMotorSpeed(LEFT_MOTOR, left_speed);
  delay(degrees); // claibrate based on robot?
}


void loop() {
  // put your main code here, to run repeatedly: 

  // move forward somewhere here
  setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_FORWARD);
  
  bool right_pressed = false;
  bool left_pressed =  false;
    if(digitalRead(BP_SW_PIN_0) == 0){
        right_pressed = true;
    }
    if(digitalRead(BP_SW_PIN_1) == 0){
        right_pressed = true;
    }
    if(digitalRead(BP_SW_PIN_2) == 0){
        right_pressed = true;
    }
    if(digitalRead(BP_SW_PIN_3) == 0){
        left_pressed = true;
    }
    if(digitalRead(BP_SW_PIN_4) == 0){
        left_pressed = true;
    }
    if(digitalRead(BP_SW_PIN_5) == 0){
        left_pressed = true;
    }
    if (left_pressed && right_pressed){
       stop();
       reverse();
       delay(500);
       turnRight(90);
       delay(750);
       left_pressed =  false;
       right_pressed =  false;
       //go back to move foward or just exsit loop?
 
    } else if(left_pressed){
        stop();
        reverse();
        delay(500);
        turnRight(30);
        delay(750);
        left_pressed = false;
        //go back to move foward or just exsit loop?
        
    } else if(right_pressed){
        stop();
        reverse();
        delay(500);
        turnLeft(30);
        right_pressed =  false;
        delay(750);
        //go back to move foward or just exsit loop?
      
     }
}
