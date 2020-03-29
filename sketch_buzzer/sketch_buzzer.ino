const int led =13;
const int buzz =12;
const int ldr =A0;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(led,OUTPUT);
  pinMode (buzz,OUTPUT);
  pinMode (ldr,INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  int ldrStat =analogRead(ldr);

  if(ldrStat >= 400){
    tone(buzz,HIGH);
    digitalWrite(led,HIGH);
    delay(1000);

    noTone(buzz);
    digitalWrite(led,LOW);
    delay(100);

    Serial.println("------------ALARM--------------");
  }

  else{
    noTone(buzz);
    digitalWrite(led,LOW);

    Serial.println("------NO ALARM----------------");
  }

}
