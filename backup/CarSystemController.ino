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


void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(relay, HIGH);
  digitalWrite(buzzer, LOW);
  digitalWrite(4, LOW);
}

void loop()
{
  //Turn On
  if (((digitalRead(button) == LOW) && (onecarmode == 0)) && (lastbutton < millis())) {
    digitalWrite(4, HIGH);
    lastbutton = (millis() + 2000);
    Serial.println("OneCarMode On");
    onecarmode = 1;
  }

  //Turn Off
  if (((digitalRead(button) == LOW) && (onecarmode == 1)) && (lastbutton < millis())) {
    digitalWrite(4, LOW);
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
      digitalWrite(relay, LOW);
      delay(2000);
      digitalWrite(relay, HIGH);
      delay(10000);
    }else {
      digitalWrite(relay, LOW);
      delay(10000);
    }

  } else
  {


  }
}
