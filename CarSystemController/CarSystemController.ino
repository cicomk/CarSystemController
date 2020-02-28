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
  pinMode(button, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(relay, HIGH);
  digitalWrite(buzzer, LOW);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
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


  }
}
