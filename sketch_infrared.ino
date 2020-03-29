#define pin 2



void setup() {
  pinMode(pin,INPUT);
  Serial.begin(115200);
  
}

void loop() {
bool isDetected = digitalRead(pin);

if(!isDetected){
    Serial.write("Presence detected\n");
    
}
else{
  Serial.write("Path is clear\n");
}

delay(5);
  
}
