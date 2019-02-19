#include <SPI.h>  
#include <Pixy.h>

#define left_pos 2
#define left_neg 3
#define right_pos 4
#define right_neg 5

// This is the main Pixy object 
Pixy pixy;

void setup()
{
  Serial.begin(9600);
  Serial.print("Starting...\n");
  pinMode(left_pos,OUTPUT) ;
  pinMode(left_neg,OUTPUT) ;
  pinMode(right_pos,OUTPUT) ;
  pinMode(right_neg,OUTPUT) ;
  
  pixy.init();
}

void loop()
{ 
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; 
  
  // grab blocks!
  blocks = pixy.getBlocks();
  
  // If there are detect blocks, print them!
  if (blocks)
  {
    i++;
    
    // do this (print) every 50 frames because printing every
    // frame would bog down the Arduino
    if (i%50==0)
    {
      sprintf(buf, "Detected %d:\n", blocks);
      Serial.print(buf);
      for (j=0; j<blocks; j++)
      {
        sprintf(buf, "  block %d: ", j);
        Serial.print(buf); 
        pixy.blocks[j].print();
        if(pixy.blocks[j].signature == 1){
           analogWrite(left_pos,200);
           analogWrite(left_neg,0);
           analogWrite(right_pos,200);
           analogWrite(right_neg,0);
        }
      }
    }
  }  
}


void mov()
