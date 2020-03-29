#define type 1 //0 -> common cathode 1-> common anode

const int displayPins[] = {2,3,1,5,6,7,8};
const int decimalPoint =9;

byte displayLEDs[10][7] = {
        { 0,0,0,0,0,0,1 },  // = 0
        { 1,0,0,1,1,1,1 },  // = 1
        { 0,0,1,0,0,1,0 },  // = 2
        { 0,0,0,0,1,1,0 },  // = 3
        { 1,0,0,1,1,0,0 },  // = 4
        { 0,1,0,0,1,0,0 },  // = 5
        { 0,1,0,0,0,0,0 },  // = 6
        { 0,0,0,1,1,1,1 },  // = 7
        { 0,0,0,0,0,0,0 },  // = 8
        { 0,0,0,0,1,0,0 }   // = 9   
};

void writeDigit(int digit) {
  // Robojax Seven Segment Display for Arduino
  Serial.print(digit);
  Serial.print(" ");

   int digitValue;
  for (int i=0; i < 7; i++) 
  {

      digitalWrite(displayPins[i], convertHighLow(displayLEDs[digit][i]));// write the HGIH or LOW (depending on the type) to output pin
      Serial.print(convertHighLow(displayLEDs[digit][i]));// print the result to the Serial monitor

  }// for i
}//writeDigit ends here


int convertHighLow(int v)
{
  int convertedValue;
    if(type ==0)
    {
      convertedValue = 1 - v;// if common anode, change the HIGH to LOW and LOW to HIGH
    }else{
      convertedValue = v;// if common cathode, keep it the same
    } 

    return convertedValue;
}

void setup() {
 for(int d=0; d<8; d++)
  {
    pinMode(displayPins[d], OUTPUT);// set pin as output
    
  }
   pinMode(decimalPoint,OUTPUT);// define a pin for decimal pint
   digitalWrite(decimalPoint,HIGH);// turn decimal point OFF. Set to LOW if common Anode and HIGH for common cathode

  Serial.begin(9600);// initialize serial monitor with 9600 baud
}

void loop() {
 for (int i=0; i<=9 ; i++) {
   writeDigit(i); 
   Serial.println("=====");
   delay(1000);
  }
  digitalWrite(decimalPoint,LOW);// turn decimal point ON
  delay(5000);
}
