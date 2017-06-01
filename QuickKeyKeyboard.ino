#include <Keyboard.h>

int button1Pin = 8;
int button2Pin = 6;

int led1pin = 9;
int led2pin = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(button1Pin, INPUT);
  digitalWrite(button1Pin, HIGH);
  pinMode(button2Pin, INPUT);
  digitalWrite(button2Pin, HIGH);

  pinMode(led1pin, OUTPUT);
  pinMode(led2pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button1Pin) == LOW) {
    if(digitalRead(button2Pin) == LOW) {
      Keyboard.press('z');
      digitalWrite(led1pin, HIGH);
      Keyboard.press('x');
      digitalWrite(led2pin, HIGH);
    }else {
      Keyboard.release('x');
      Keyboard.press('z');
      digitalWrite(led1pin, HIGH);
      digitalWrite(led2pin, LOW);
    }
  }else if(digitalRead(button2Pin) == LOW) {
    Keyboard.release('z');
      digitalWrite(led1pin, LOW);
    Keyboard.press('x');
      digitalWrite(led2pin, HIGH);
  }else {
    Keyboard.releaseAll();
      digitalWrite(led1pin, LOW);
      digitalWrite(led2pin, LOW);
  }
  delay(5);
}
