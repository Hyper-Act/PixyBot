#include <Pixy.h>

Pixy pixy;
const int ain_1 = 2 ;
const int ain_2 = 3 ;
const int bin_1 = 4 ;
const int bin_2 = 5 ;

void setup()
{
  Serial.begin(9600);
  Serial.print("Starting...\n");
  pinMode(ain_1,OUTPUT) ;
  pinMode(ain_2,OUTPUT) ;
  pinMode(bin_1,OUTPUT) ;
  pinMode(bin_2,OUTPUT) ;
  pixy.init();
}

void loop()
{ 
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; 

  blocks = pixy.getBlocks();

  if (blocks)
  {
    i++;
    if (i%50==0)
    {
      sprintf(buf, "Detected %d:\n", blocks);
      Serial.print(buf);
      for (j=0; j<blocks; j++)
      {
        sprintf(buf, "  block %d: ", j);
        Serial.print(buf); 
        pixy.blocks[j].print();
        digitalWrite(ain_1,HIGH) ;
        digitalWrite(ain_2,LOW) ;
        digitalWrite(bin_1,HIGH) ;
        digitalWrite(bin_2,LOW) ;
      }
    }
  }  
}
