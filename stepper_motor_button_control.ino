// Include the AccelStepper Library
  #include <AccelStepper.h>

// Define step constant
  #define FULLSTEP 4

// Stepper setup
  const int StepperSpeed = 200;
  const int StepperMaxSpeed = 2038;
  const int StepperAccel = 119;
  int StepperGoal = 0;

  const int StepperPin1 = 10;
  const int StepperPin2 = 11;
  const int StepperPin3 = 12;
  const int StepperPin4 = 13;

  AccelStepper myStepper(FULLSTEP, StepperPin1, StepperPin3, StepperPin2, StepperPin4);


// Button setup
  const int ButtonA = 8;
  const int ButtonB = 9;


void setup() {
  // More button setup
    pinMode(ButtonA, INPUT);
    pinMode(ButtonB, INPUT);

  // Speed of the stepper motor
    myStepper.setMaxSpeed(StepperMaxSpeed);
    myStepper.setAcceleration(StepperAccel);
    myStepper.setSpeed(StepperSpeed);
}


void loop() {
    // Button A - Button B times StepsPreRevolution devided by 1000 for 1MS times the polling rate.
      StepperGoal += digitalRead(ButtonA) - digitalRead(ButtonB);
      myStepper.moveTo(StepperGoal);
      myStepper.run();
}
