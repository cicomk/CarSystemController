//Version 2


unsigned long roundc = 0;
unsigned long ticking = 0;

byte onecarmode = 0; //0-off;1-on
byte load = 0;
byte relay1 = 0;

int first = 0;
int sensor = 11;
int  relay = 10;
int buzzer = 9;
int button = 13;
int tickEvent;
int relaylast;

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
   ticking++;
  //Turn On
  if (((digitalRead(button) == LOW) && (onecarmode == 0))) {
    digitalWrite(12, HIGH);
    Serial.println("OneCarMode On");
    onecarmode = 1;
    delay(2000);
    }

  //Turn Off
  if (((digitalRead(button) == LOW) && (onecarmode == 1))) {
    digitalWrite(12, LOW);
    Serial.println("OneCarMode Off");
     onecarmode = 0;
     delay(2000);
  }

  if ((ticking <= roundc) && (roundc != 0)) {
    Serial.println((ticking)+(" timeout"));
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
    if ((ticking != 0)&&(first==1)) {
      roundc = (ticking+5);
      Serial.println(roundc);
      first = 2;
    }

    if (first == 0) {
      ticking=0;
      Serial.println(ticking);
      first=1;
    }
    if ((onecarmode == 0)&&(roundc!=0)) {
      ticking = 0;
      relay1=1;
    }
    if ((onecarmode == 1)&&(roundc!=0)){
      digitalWrite(buzzer, LOW);
      digitalWrite(relay, HIGH);//Low
    }

  }

  if (relay1==1){
    digitalWrite(buzzer, LOW);
    
    if (ticking<1){
    digitalWrite(relay, HIGH);//Low
    }
    if (ticking=3){
      digitalWrite(relay, LOW);//High
      relay1=0;
    }
  }
}
