#include <Braccio.h>
#include <BraccioRobot.h>
#include <Servo.h>
#include <Wire.h>

char Incoming_value = 0;
Position pos;

void setup() {
  Wire.begin();                        // join i2c bus 
  Serial.begin(9600);
  BraccioRobot.init();
}

void loop() {
  boolean ballFound = true;

  if (Serial.available() > 0)
  {
    Incoming_value = Serial.read();
    
    Serial.print(Incoming_value);
    Serial.print("\n");


    if (Incoming_value == 'r')
    {
      while (ballFound == true)
      {
        pos.set(20, 45, 180, 180, 90, 10);
        BraccioRobot.moveToPosition(pos, 100);
        delay(1000);

        //The braccio moves to the ball. Only the M2 servo will moves
        pos.set(20, 117, 147, 180, 90, 10);
        BraccioRobot.moveToPosition(pos, 100);
        delay(1000);

        //CHECK COLOR
        Wire.requestFrom(8, 1);       // request 6 bytes from slave device #8
        while (Wire.available()) {    // slave may send less than requested
          char color = Wire.read();    // receive a byte as character that indicates the color of the ball
          char finalColor = color;
          
          // IF BALL IS RED
          switch (finalColor)
          {
            case 'R':
              {
                //Close the gripper to take the ball. Only the M6 servo will moves
                pos.set(20, 117, 147, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Brings the ball upwards.
                pos.set(20, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Show the ball. Only the M1 servo will moves
                pos.set(75, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Move to new position position.
                pos.set(75, 45, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                pos.set(75, 130, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Open the gripper
                pos.set(75, 130, 120, 180, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                pos.set(90, 90, 90, 90, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                BraccioRobot.init();
                ballFound = true;
                break;
              }
            case 'N':
              {
                pos.set(90, 90, 90, 90, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                BraccioRobot.init();
                ballFound = false;
                break;
              }
              
            default:
              {
                //The braccio moves to the ball. Only the M2 servo will moves
                pos.set(20, 117, 147, 180, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Close the gripper to take the ball. Only the M6 servo will moves
                pos.set(20, 117, 147, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Brings the ball upwards.
                pos.set(20, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Show the ball. Only the M1 servo will moves
                pos.set(110, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Move to new position.
                pos.set(110, 45, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                pos.set(110, 130, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Open the gripper
                pos.set(110, 130, 120, 180, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                pos.set(90, 90, 90, 90, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                BraccioRobot.init();
                ballFound = true;
                break;
              }
          }
        }
      }
    }

    if (Incoming_value == 'b')
    {
      while (ballFound == true)
      {
        pos.set(20, 45, 180, 180, 90, 10);
        BraccioRobot.moveToPosition(pos, 100);
        delay(1000);

        //The braccio moves to the sponge. Only the M2 servo will moves
        //Braccio.ServoMovement(20,           0,  90, 180, 180,  90,   10);
        pos.set(20, 117, 147, 180, 90, 10);
        BraccioRobot.moveToPosition(pos, 100);
        delay(1000);

        //CHECK COLOR
        Wire.requestFrom(8, 1);    // request 6 bytes from slave device #8
        while (Wire.available()) { // slave may send less than requested
          char color = Wire.read(); // receive a byte as character
          char finalColor = color;

          // IF BALL IS BLUE
          switch (finalColor)
          {
            case 'B':
              {
                //Close the gripper to take the sponge. Only the M6 servo will moves
                //Braccio.ServoMovement(10,           0,  90, 180, 180,  90,  60 );
                pos.set(20, 117, 147, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Brings the sponge upwards.
                //Braccio.ServoMovement(20,         0,   45, 180,  45,  0, 60);
                pos.set(20, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Show the sponge. Only the M1 servo will moves
                //Braccio.ServoMovement(20,         180,  45, 180,   45,   0,  60);
                pos.set(75, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Return to the start position.
                pos.set(75, 45, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Braccio.ServoMovement(20,         0,   90, 180,  180,  90, 60);
                pos.set(75, 130, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Open the gripper
                //Braccio.ServoMovement(20,         0,   90, 180,  180,  90, 10 );
                pos.set(75, 130, 120, 180, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                pos.set(90, 90, 90, 90, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                BraccioRobot.init();
                ballFound = true;
                break;
              }
            case 'N':
              {
                pos.set(90, 90, 90, 90, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                BraccioRobot.init();
                ballFound = false;
                break;

              }
            default:
              {
                //The braccio moves to the sponge. Only the M2 servo will moves
                //Braccio.ServoMovement(20,           0,  90, 180, 180,  90,   10);
                pos.set(20, 117, 147, 180, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Close the gripper to take the sponge. Only the M6 servo will moves
                //Braccio.ServoMovement(10,           0,  90, 180, 180,  90,  60 );
                pos.set(20, 117, 147, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Brings the sponge upwards.
                //Braccio.ServoMovement(20,         0,   45, 180,  45,  0, 60);
                pos.set(20, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Show the sponge. Only the M1 servo will moves
                //Braccio.ServoMovement(20,         180,  45, 180,   45,   0,  60);
                pos.set(110, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Return to the start position.
                pos.set(110, 45, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Braccio.ServoMovement(20,         0,   90, 180,  180,  90, 60);
                pos.set(110, 130, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Open the gripper
                //Braccio.ServoMovement(20,         0,   90, 180,  180,  90, 10 );
                pos.set(110, 130, 120, 180, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                pos.set(90, 90, 90, 90, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                BraccioRobot.init();
                ballFound = true;
                break;
              }
          }
        }
      }
    }
    if (Incoming_value == 'y')
    {
      while (ballFound == true)
      {
        pos.set(20, 45, 180, 180, 90, 10);
        BraccioRobot.moveToPosition(pos, 100);
        delay(1000);

        //The braccio moves to the sponge. Only the M2 servo will moves
        //Braccio.ServoMovement(20,           0,  90, 180, 180,  90,   10);
        pos.set(20, 117, 147, 180, 90, 10);
        BraccioRobot.moveToPosition(pos, 100);
        delay(1000);

        //CHECK COLOR
        Wire.requestFrom(8, 1);    // request 6 bytes from slave device #8
        while (Wire.available()) { // slave may send less than requested
          char color = Wire.read(); // receive a byte as character
          char finalColor = color;

          // IF BALL IS YELLOW
          switch (finalColor)
          {
            case 'Y':
              {
                //Close the gripper to take the sponge. Only the M6 servo will moves
                //Braccio.ServoMovement(10,           0,  90, 180, 180,  90,  60 );
                pos.set(20, 117, 147, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Brings the sponge upwards.
                //Braccio.ServoMovement(20,         0,   45, 180,  45,  0, 60);
                pos.set(20, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Show the sponge. Only the M1 servo will moves
                //Braccio.ServoMovement(20,         180,  45, 180,   45,   0,  60);
                pos.set(75, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Return to the start position.
                pos.set(75, 45, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Braccio.ServoMovement(20,         0,   90, 180,  180,  90, 60);
                pos.set(75, 130, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Open the gripper
                //Braccio.ServoMovement(20,         0,   90, 180,  180,  90, 10 );
                pos.set(75, 130, 120, 180, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                pos.set(90, 90, 90, 90, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                BraccioRobot.init();
                ballFound = true;
                break;
              }
            case 'N':
              {
                pos.set(90, 90, 90, 90, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                BraccioRobot.init();
                ballFound = false;
                break;
              }
            default:
              {
                //The braccio moves to the sponge. Only the M2 servo will moves
                //Braccio.ServoMovement(20,           0,  90, 180, 180,  90,   10);
                pos.set(20, 117, 147, 180, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Close the gripper to take the sponge. Only the M6 servo will moves
                //Braccio.ServoMovement(10,           0,  90, 180, 180,  90,  60 );
                pos.set(20, 117, 147, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Brings the sponge upwards.
                //Braccio.ServoMovement(20,         0,   45, 180,  45,  0, 60);
                pos.set(20, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Show the sponge. Only the M1 servo will moves
                //Braccio.ServoMovement(20,         180,  45, 180,   45,   0,  60);
                pos.set(110, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Return to the start position.
                pos.set(110, 45, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Braccio.ServoMovement(20,         0,   90, 180,  180,  90, 60);
                pos.set(110, 130, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Open the gripper
                //Braccio.ServoMovement(20,         0,   90, 180,  180,  90, 10 );
                pos.set(110, 130, 120, 180, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                pos.set(90, 90, 90, 90, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                BraccioRobot.init();
                ballFound = true;
                break;
              }
          }
        }
      }
    }
    if (Incoming_value == 'g')
    {
      while (ballFound == true)
      {
        pos.set(20, 45, 180, 180, 90, 10);
        BraccioRobot.moveToPosition(pos, 100);
        delay(1000);

        //The braccio moves to the sponge. Only the M2 servo will moves
        //Braccio.ServoMovement(20,           0,  90, 180, 180,  90,   10);
        pos.set(20, 117, 147, 180, 90, 10);
        BraccioRobot.moveToPosition(pos, 100);
        delay(1000);

        //CHECK COLOR
        Wire.requestFrom(8, 1);    // request 6 bytes from slave device #8
        while (Wire.available()) { // slave may send less than requested
          char color = Wire.read(); // receive a byte as character
          char finalColor = color;

          // IF BALL IS GREEN

          switch (finalColor)
          {
            case 'G':
              {
                //Close the gripper to take the ball. Only the M6 servo will moves
                //Braccio.ServoMovement(10,           0,  90, 180, 180,  90,  60 );
                pos.set(20, 117, 147, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Brings the ball upwards.
                //Braccio.ServoMovement(20,         0,   45, 180,  45,  0, 60);
                pos.set(20, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Show the ball. Only the M1 servo will moves
                //Braccio.ServoMovement(20,         180,  45, 180,   45,   0,  60);
                pos.set(75, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Return to the start position.
                pos.set(75, 45, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Braccio.ServoMovement(20,         0,   90, 180,  180,  90, 60);
                pos.set(75, 130, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Open the gripper
                //Braccio.ServoMovement(20,         0,   90, 180,  180,  90, 10 );
                pos.set(75, 130, 120, 180, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                pos.set(90, 90, 90, 90, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                BraccioRobot.init();
                ballFound = true;
                break;
              }
            case 'N':
              {
                pos.set(90, 90, 90, 90, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                BraccioRobot.init();
                ballFound = false;
                break;

              }
            default:
              {
                //The braccio moves to the sponge. Only the M2 servo will moves
                //Braccio.ServoMovement(20,           0,  90, 180, 180,  90,   10);
                pos.set(20, 117, 147, 180, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Close the gripper to take the sponge. Only the M6 servo will moves
                //Braccio.ServoMovement(10,           0,  90, 180, 180,  90,  60 );
                pos.set(20, 117, 147, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Brings the sponge upwards.
                //Braccio.ServoMovement(20,         0,   45, 180,  45,  0, 60);
                pos.set(20, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Show the sponge. Only the M1 servo will moves
                //Braccio.ServoMovement(20,         180,  45, 180,   45,   0,  60);
                pos.set(110, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Return to the start position.
                pos.set(110, 45, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Braccio.ServoMovement(20,         0,   90, 180,  180,  90, 60);
                pos.set(110, 130, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Open the gripper
                //Braccio.ServoMovement(20,         0,   90, 180,  180,  90, 10 );
                pos.set(110, 130, 120, 180, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                pos.set(90, 90, 90, 90, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                BraccioRobot.init();
                ballFound = true;
                break;
              }
          }
        }
      }
    }
    if (Incoming_value == 'a')
    {
      while (ballFound == true)
      {
        pos.set(20, 45, 180, 180, 90, 10);
        BraccioRobot.moveToPosition(pos, 100);
        delay(1000);

        //The braccio moves to the sponge. Only the M2 servo will moves
        //Braccio.ServoMovement(20,           0,  90, 180, 180,  90,   10);
        pos.set(20, 117, 147, 180, 90, 10);
        BraccioRobot.moveToPosition(pos, 100);
        delay(1000);

        //CHECK COLOR
        Wire.requestFrom(8, 1);    // request 6 bytes from slave device #8
        while (Wire.available()) { // slave may send less than requested
          char color = Wire.read(); // receive a byte as character
          char finalColor = color;

          // IF BALL IS RED

          switch (finalColor)
          {
            case 'R':
              {
                //Close the gripper to take the sponge. Only the M6 servo will moves
                //Braccio.ServoMovement(10,           0,  90, 180, 180,  90,  60 );
                pos.set(20, 117, 147, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Brings the sponge upwards.
                //Braccio.ServoMovement(20,         0,   45, 180,  45,  0, 60);
                pos.set(20, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Show the sponge. Only the M1 servo will moves
                //Braccio.ServoMovement(20,         180,  45, 180,   45,   0,  60);
                pos.set(75, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Return to the start position.
                pos.set(75, 45, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Braccio.ServoMovement(20,         0,   90, 180,  180,  90, 60);
                pos.set(75, 130, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Open the gripper
                //Braccio.ServoMovement(20,         0,   90, 180,  180,  90, 10 );
                pos.set(75, 130, 120, 180, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                pos.set(90, 90, 90, 90, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                BraccioRobot.init();
                ballFound = true;
                break;
              }

            case 'B':
              {
                //The braccio moves to the sponge. Only the M2 servo will moves
                //Braccio.ServoMovement(20,           0,  90, 180, 180,  90,   10);
                pos.set(20, 117, 147, 180, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Close the gripper to take the sponge. Only the M6 servo will moves
                //Braccio.ServoMovement(10,           0,  90, 180, 180,  90,  60 );
                pos.set(20, 117, 147, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Brings the sponge upwards.
                //Braccio.ServoMovement(20,         0,   45, 180,  45,  0, 60);
                pos.set(20, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Show the sponge. Only the M1 servo will moves
                //Braccio.ServoMovement(20,         180,  45, 180,   45,   0,  60);
                pos.set(110, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Return to the start position.
                pos.set(110, 45, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Braccio.ServoMovement(20,         0,   90, 180,  180,  90, 60);
                pos.set(110, 130, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Open the gripper
                //Braccio.ServoMovement(20,         0,   90, 180,  180,  90, 10 );
                pos.set(110, 130, 120, 180, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                pos.set(90, 90, 90, 90, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                BraccioRobot.init();
                ballFound = true;
                break;
              }

            case 'Y':
              {
                //The braccio moves to the sponge. Only the M2 servo will moves
                //Braccio.ServoMovement(20,           0,  90, 180, 180,  90,   10);
                pos.set(20, 117, 147, 180, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Close the gripper to take the sponge. Only the M6 servo will moves
                //Braccio.ServoMovement(10,           0,  90, 180, 180,  90,  60 );
                pos.set(20, 117, 147, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Brings the sponge upwards.
                //Braccio.ServoMovement(20,         0,   45, 180,  45,  0, 60);
                pos.set(20, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Show the sponge. Only the M1 servo will moves
                //Braccio.ServoMovement(20,         180,  45, 180,   45,   0,  60);
                pos.set(135, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Return to the start position.
                pos.set(135, 45, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Braccio.ServoMovement(20,         0,   90, 180,  180,  90, 60);
                pos.set(135, 130, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Open the gripper
                //Braccio.ServoMovement(20,         0,   90, 180,  180,  90, 10 );
                pos.set(135, 130, 120, 180, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                pos.set(90, 90, 90, 90, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                BraccioRobot.init();
                ballFound = true;
                break;
              }

            case 'G':
              {
                //The braccio moves to the sponge. Only the M2 servo will moves
                //Braccio.ServoMovement(20,           0,  90, 180, 180,  90,   10);
                pos.set(20, 117, 147, 180, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Close the gripper to take the sponge. Only the M6 servo will moves
                //Braccio.ServoMovement(10,           0,  90, 180, 180,  90,  60 );
                pos.set(20, 117, 147, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Brings the sponge upwards.
                //Braccio.ServoMovement(20,         0,   45, 180,  45,  0, 60);
                pos.set(20, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Show the sponge. Only the M1 servo will moves
                //Braccio.ServoMovement(20,         180,  45, 180,   45,   0,  60);
                pos.set(170, 45, 180, 45, 0, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Return to the start position.
                pos.set(170, 45, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Braccio.ServoMovement(20,         0,   90, 180,  180,  90, 60);
                pos.set(170, 130, 120, 180, 90, 60);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                //Open the gripper
                //Braccio.ServoMovement(20,         0,   90, 180,  180,  90, 10 );
                pos.set(170, 130, 120, 180, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                pos.set(90, 90, 90, 90, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                BraccioRobot.init();
                ballFound = true;
                break;
              }

            default :
              {
                pos.set(90, 90, 90, 90, 90, 10);
                BraccioRobot.moveToPosition(pos, 100);
                delay(1000);

                BraccioRobot.init();
                ballFound = false;
                break;

              }
          }
        }
      }
    }
  }

}
