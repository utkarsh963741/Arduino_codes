void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0 ;i<20;i++)
{
    digitalWrite(2,HIGH);
  delay(500);
  digitalWrite(2,LOW);
  delay(2000);
  
}

}
