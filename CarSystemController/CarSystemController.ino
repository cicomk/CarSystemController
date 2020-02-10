unsigned long timer = 0;
unsigned long last_round = 0;

int sensor = 3;
int  relay = 4;
byte in = 0;

void setup(){
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(relay, OUTPUT);
}
void loop()
{
  
  /*if (((last_relay_nonfree + 2000)>=millis()) && (in == 1)){
    digitalWrite(relay, LOW);
    
  }else {
    digitalWrite(relay, HIGH);
    
  }
  */
  if (digitalRead(sensor) == HIGH)
  {
   //Foglalt(nonfree)
  /* if (in == 0) {
    last_relay_nonfree == millis();
    Serial.println("in=1");
    in = 1; */
     digitalWrite(relay, LOW);
     delay(2000);
     digitalWrite(relay, HIGH);
     delay(10000);
  }else
  {
    
    
   }
  }

  

  
