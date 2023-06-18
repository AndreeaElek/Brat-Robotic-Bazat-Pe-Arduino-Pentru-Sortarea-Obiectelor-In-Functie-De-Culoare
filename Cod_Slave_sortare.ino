
#include <Wire.h>
#include <Pixy2.h>

int sigRed = 1;                   // signature 1, for red balls
int sigBlue = 2;                  //signature 2, for blue balls
int sigYellow = 3;                //signature 3, for yellow balls
int sigGreen = 4;                 //signature 4, for green balls

                                
Pixy2 pixy;                      // This is the main Pixy object


void setup() {
  Wire.begin(8);                        // join I2C bus with address #8
  Wire.onRequest(requestEvent);         // register event
  Serial.begin(115200);
  Serial.print("Starting...\n");

  pixy.init();
}

void loop() {
  delay(100);

}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  int colorValue;
  uint16_t blocks;
  blocks = pixy.ccc.getBlocks();
  int ballSignature = 0;
  if ( blocks)
  {
    ballSignature = pixy.ccc.blocks[0].m_signature;
  }
  if (ballSignature != 0)
  {
    switch (ballSignature)
    {
      case 1:
        {
          Wire.write("R");
          break;
        }
      case 2:
        {
          Wire.write("B");
          break;
        }
      case 3:
        {
          Wire.write("Y");
          break;
        }
      case 4:
        {
          Wire.write("G");
          break;
        }
      default:
        {
          Wire.write("O");
        }
    }
  }
  else
  {   
    Wire.write("N");
  }
}
