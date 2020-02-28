<<<<<<< HEAD
unsigned long last_round1 = 0;
unsigned long last_round2 = 0;
unsigned long round_counted = 0;
unsigned long roundlast = 0;
unsigned long lastbutton = 0;

byte onecarmode = 0; //0-off;1-on
byte load = 0;

int sensor = 3;
int  relay = 12;
int buzzer = 2;
int button = 5;
=======
unsigned long timer = 0;
unsigned long last_round = 0;

int sensor = 3;
int  relay = 4;
byte in = 0;
>>>>>>> parent of 833ba75... Add round counting

void setup(){
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(button, INPUT);
  pinMode(relay, OUTPUT);
<<<<<<< HEAD
  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(relay, HIGH);
  digitalWrite(buzzer, LOW);
  digitalWrite(LED_BUILTIN, LOW);
=======
>>>>>>> parent of 833ba75... Add round counting
}

void loop()
{
<<<<<<< HEAD
  /*//Turn On
  if (((digitalRead(button) == HIGH) && (onecarmode == 0)) && (lastbutton < millis())) {
    digitalWrite(LED_BUILTIN, HIGH);
    onecarmode = 1;
    lastbutton = (millis() + 2000);
  }

  //Turn Off
  if (((digitalRead(button) == HIGH) && (onecarmode == 1)) && (lastbutton < millis())) {
    digitalWrite(LED_BUILTIN, LOW);
    onecarmode = 0;
    lastbutton = (millis() + 2000);
  }
*/
  if (((millis() - roundlast) >= round_counted) && (round_counted != 0)) {
    Serial.println((millis() - roundlast));
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }
  

  if (((digitalRead(sensor) == HIGH) && (load == 0))) {
    delay(5000);
    load = 1;

  }

  if ((digitalRead(sensor) == HIGH) && ((load == 1)))
  {
    if ((last_round2 == 0) && (last_round1 != 0)) {
      last_round2 = millis();
      Serial.println(last_round2);
    }

    if (last_round1 == 0) {
      last_round1 = millis();
      Serial.println(last_round1);
    }

    if ((last_round2 != 0) && (last_round1 != 0) && (round_counted == 0)) {
      round_counted = (((last_round2) - (last_round1)) + 5000);
      Serial.println(round_counted);
    }
    roundlast = millis();
    if (onecarmode == 0) {
      digitalWrite(relay, LOW);
      delay(2000);
      digitalWrite(relay, HIGH);
      delay(10000);
    }

  } else
  {
=======
  
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
>>>>>>> parent of 833ba75... Add round counting

  

  
