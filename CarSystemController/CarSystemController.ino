//Version 2
unsigned long last_round1 = 0;
unsigned long last_round2 = 0;
unsigned long round_counted = 0;
unsigned long roundlast = 0;
unsigned long lastbutton = 0;

byte onecarmode = 0; //0-off;1-on
byte load = 0;
byte in = 0;

int sensor = 3;
int sensor2 = 4;
int relay = 12;
int buzzer = 2;
int button = 5;
int onecarmodeled = 4;


void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(onecarmodeled, OUTPUT);
  digitalWrite(relay, LOW);
  digitalWrite(buzzer, LOW);
  digitalWrite(onecarmodeled, LOW);
}

void loop()
{
  //Turn On
  if (((digitalRead(button) == LOW) && (onecarmode == 0)) && (lastbutton < millis())) {
    digitalWrite(onecarmodeled, HIGH);
    lastbutton = (millis() + 2000);
    Serial.println("OneCarMode On");
    onecarmode = 1;
  }

  //Turn Off
  if (((digitalRead(button) == LOW) && (onecarmode == 1)) && (lastbutton < millis())) {
    digitalWrite(onecarmodeled, LOW);
    lastbutton = (millis() + 2000);
    Serial.println("OneCarMode Off");
    onecarmode = 0;
  }

  //Buzzer
  if (((millis() - roundlast) >= round_counted) && (round_counted != 0)) {
    Serial.println((millis() - roundlast));
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }

  //Load
  if ((((digitalRead(sensor) == HIGH) && (load == 0))) && (onecarmode == 0)) {
    delay(5000);
    load = 1;

  }
  //Round time read
  if ((digitalRead(sensor) == HIGH) && (((load == 1) || (onecarmode == 1))))
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
    in = 1;
    if (onecarmode == 0) {
      digitalWrite(relay, HIGH);
    }
  }
  if ((digitalRead(sensor2) != HIGH) && (in = 1)) {
    in = 0;
  }
  if ((digitalRead(sensor2) == HIGH) && (in = 0)) {
    digitalWrite(relay, LOW);
    in == 1;

  }

}
