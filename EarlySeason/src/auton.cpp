#include "main.h"
#include "config.h"
using namespace okapi;
void auton(){
  turn_ccw(490);
  /*
  while((int)ultraLeft.controllerGet() != (int)ultraRight.controllerGet()){
    if((int)ultraLeft.controllerGet() > (int)ultraRight.controllerGet()){
      fR.moveVelocity(5);
      bR.moveVelocity(5);
      delay(25);
    }
    else if((int)ultraLeft.controllerGet() < (int)ultraRight.controllerGet()){
      fL.moveVelocity(5);
      bL.moveVelocity(5);
      delay(25);
    }
  }
  */
  /*
  while((int)ultraLeft.controllerGet() != (int)ultraRight.controllerGet()){
    if((int)ultraLeft.controllerGet() > (int)ultraRight.controllerGet()){
      fR.moveVelocity(5);
      bR.moveVelocity(5);
      delay(25);
    }
    else if((int)ultraLeft.controllerGet() < (int)ultraRight.controllerGet()){
      fL.moveVelocity(5);
      bL.moveVelocity(5);
      delay(25);
    }
  }
  */
  /*
    chassis->setMaxVelocity(60);
    float count = 0;
    while(!intakeLimitSwitch.isPressed()){
      moveDistance(60, 25);
      count += 25;
    }
    stop();
    for(int i = 0; i < 10; i++)
    frontIntakeClampDown();
    stop();
    chassis->setMaxVelocity(-60);
    moveDistance(-60, count*(float)3/4);
    stop();
    frontIntakeUp();
    stop();
    chassis->setMaxVelocity(60);
    turn_ccw(75);
    moveDistance(60, count*(float)1/2);
    turn_cw(count*(float)1/4);
    count = 0;
    while(!intakeLimitSwitch.isPressed()){
      moveDistance(60, 25);
      count += 25;
    }
    chassis->setMaxVelocity(-60);
    moveDistance(-60, count*(float)3/4);
    stop();
    frontIntakeUp();
    stop();
    moveDistance(-60, count*(float)1/4);
    stop();

    chassis->setMaxVelocity(150);
    */

    chassis->setMaxVelocity(60);
    float count = 0;
    while(!intakeLimitSwitch.isPressed()){
      moveDistance(60, 25);
      count += 25;
    }
    stop();
    for(int i = 0; i < 10; i++)
    frontIntakeClampDown();
    stop();
    chassis->setMaxVelocity(-60);
    moveDistance(-60, count*(float)3/4);
    stop();
    frontIntakeUp();
    stop();
    moveDistance(-60, count*(float)1/4);
    stop();
    chassis->setMaxVelocity(150);

}
void auton_selector(){

}
void moveDistance(float spd, int time){
  fL.moveVelocity(spd);
  fR.moveVelocity(spd);
  bL.moveVelocity(spd);
  bR.moveVelocity(spd);
  delay(time);
}
void frontIntakeUp(){
  intake.moveVoltage(8000);
  delay(75); //experiment with this value
}
void frontIntakeClampDown(){
  intake.moveVoltage(-8000);
  delay(75); //experiment with this value
}
void backClawOpen(){
  delay(1000);
}
void backClawClose(){
  delay(1000);
}
void liftMoveUp(){
  lift.moveVelocity(100);
  delay(30); //experiment with this value
}
void liftMoveDown(){
  lift.moveVelocity(-100);
  delay(30); //experiment with this value
}
void stop(){
  fL.moveVelocity(0);
  fR.moveVelocity(0);
  bL.moveVelocity(0);
  bR.moveVelocity(0);
  lift.moveVelocity(0);
  intake.moveVoltage(0);
}

void turn_cw(int time){
  fL.moveVelocity(100);
  fR.moveVelocity(0);
  bL.moveVelocity(100);
  bR.moveVelocity(100);
  delay(time);
  stop();
}
void turn_ccw(int time){
  fL.moveVelocity(0);
  fR.moveVelocity(150);
  bL.moveVelocity(0);
  bR.moveVelocity(150);
  delay(time);
  stop();
}/*
void motionPID(float dist){
  float error, integral, prevError, derivative = 0;
  float power = 100;
  while((int)pot.controllerGet() != (int)dist){
    error = dist - pot.controllerGet();
    integral += error;
    if(error == 0 || (int)pot.controllerGet() == (int)dist){
      integral = 0;
    }
    if(pot.controllerGet() > 10){ //if error is outside of useful range
      integral = 0;
    }
    derivative = integral - prevError;
    prevError = error;
    power = error*kP + integral*kI + derivative*kD;
    delay(15);
    moveDistance(power, 15);
  }
}
*/
