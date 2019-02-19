const int ain_1 = 2 ;
const int ain_2 = 3 ;
const int bin_1 = 4 ;
const int bin_2 = 5 ;

void setup()
{
pinMode(ain_1,OUTPUT) ;
pinMode(ain_2,OUTPUT) ;
pinMode(bin_1,OUTPUT) ;
pinMode(bin_2,OUTPUT) ;
}

void loop()
{
digitalWrite(ain_1,HIGH) ;
digitalWrite(ain_2,LOW) ;
digitalWrite(bin_1,HIGH) ;
digitalWrite(bin_2,LOW) ;
}

