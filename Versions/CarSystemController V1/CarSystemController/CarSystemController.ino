//Version 1
unsigned long last_round1 = 0;
unsigned long last_round2 = 0;
unsigned long round_counted = 0;
unsigned long roundlast = 0;
unsigned long lastbutton = 0;

byte onecarmode = 0; //0-off;1-on
byte load = 0;

int sensor = 11;
int  relay = 10;
int buzzer = 9;
int button = 13;


void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(relay, LOW);//High
  digitalWrite(buzzer, LOW);
  digitalWrite(12, LOW);
  Serial.println("Start");
}

void loop()
{
  //Turn On
  if (((digitalRead(button) == LOW) && (onecarmode == 0)) && (lastbutton < millis())) {
    digitalWrite(12, HIGH);
    lastbutton = (millis() + 2000);
    Serial.println("OneCarMode On");
    onecarmode = 1;
  }

  //Turn Off
  if (((digitalRead(button) == LOW) && (onecarmode == 1)) && (lastbutton < millis())) {
    digitalWrite(12, LOW);
    lastbutton = (millis() + 2000);
    Serial.println("OneCarMode Off");
     onecarmode = 0;
  }

  if (((millis() - roundlast) >= round_counted) && (round_counted != 0)) {
    Serial.println((millis() - roundlast));
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }
  

  if ((((digitalRead(sensor) == HIGH) && (load == 0)))&&(onecarmode==0)) {
    delay(5000);
    Serial.println("Loaded");
    load = 1;

  }

  if ((digitalRead(sensor) == HIGH) && (((load == 1)||(onecarmode==1))))
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
      digitalWrite(relay, HIGH);//Low
      delay(2000);
      digitalWrite(relay, LOW);//High
      delay(10000);
    }else {
      digitalWrite(relay, HIGH);//Low
      delay(10000);
    }

  } else
  {


  }
}
