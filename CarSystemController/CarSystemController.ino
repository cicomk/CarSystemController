unsigned long last_round1 = 0;
unsigned long last_round2 = 0;
unsigned long round_counted = 0;
int sensor = 3;
int  relay = 4;


void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
}
void loop()
{


  if (digitalRead(sensor) == HIGH)
  {
 if ((last_round2==0)&&(last_round1 != 0)){
      last_round2= millis();
      Serial.println(last_round2);
    }
    
    if (last_round1 == 0){
      last_round1= millis();
      Serial.println(last_round1);
    }

  if ((last_round2!=0)&&(last_round1 != 0)&&(round_counted==0)){
      round_counted = (((last_round2)-(last_round1))+ 5000);
      Serial.println(round_counted);
    }
    
    digitalWrite(relay, LOW);
    delay(2000);
    digitalWrite(relay, HIGH);
    delay(10000);
  } else
  {


  }
}
