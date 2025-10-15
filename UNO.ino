/* ========== ARDUINO UNO CODE ========== */
int cambien1, cambien2;
int button1, button2, led1, led2;
int giatri1, giatri2, pre1 = HIGH, pre2 = HIGH;
int dem = 0, pre_dem = 0;
bool isButtonPressed1 = false, button2State = false;
bool called = false;
int buttonState1, buttonState2, lastButtonState1, lastButtonState2;
String phone_no = "+84123456789";

void setup() {
  pinMode(button1, INPUT);
  pinMode(led1, OUTPUT);
  digitalWrite(led1, LOW);
  pinMode(button2, INPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led2, LOW);
  Serial.begin(9600);
  pinMode(cambien1, INPUT);
  pinMode(cambien2, INPUT);
  Serial.println("Initializing....");
}

void loop() {
  giatri1 = digitalRead(cambien1);
  if (giatri1 == LOW && pre1 == HIGH) {
    dem++;
    delay(1000);
  }
  pre1 = giatri1;

  giatri2 = digitalRead(cambien2);
  if (giatri2 == LOW && pre2 == HIGH) {
    dem--;
    delay(1000);
  }
  pre2 = giatri2;

  if (dem < 0) dem = 0;
  pre_dem = dem;

  if (Serial.availableForWrite()) {
    Serial.println(dem);
  }

  buttonState1 = digitalRead(button1);
  if (buttonState1 != lastButtonState1) {
    if (buttonState1 == HIGH) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      button2State = false;
      if (!isButtonPressed1 && dem != 0) {
        isButtonPressed1 = true;
        Serial.println("Calling...");
      } else {
        if (isButtonPressed1) {
          isButtonPressed1 = false;
          button2State = false;
        }
      }
    } else {
      isButtonPressed1 = false;
      digitalWrite(led1, LOW);
    }
    delay(50);
  }

  buttonState2 = digitalRead(button2);
  if (buttonState2 != lastButtonState2) {
    if (buttonState2 == HIGH) {
      if (button2State == false) {
        digitalWrite(led2, HIGH);
        dem = 0;
        pre1 = HIGH;
        pre2 = HIGH;
        called = false;
        pre_dem = 0;
        button2State = true;
      } else {
        digitalWrite(led2, LOW);
        button2State = false;
      }
    }
    delay(50);
  }
  lastButtonState2 = buttonState2;
  lastButtonState1 = buttonState1;
}
