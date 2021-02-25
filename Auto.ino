#include <IRremote.h>

int receptor = 11;

#define Motor1_1 2
#define Motor1_2 3
#define Motor2_1 5
#define Motor2_2 4

IRrecv irrecv(receptor);
decode_results codigo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(Motor1_1, OUTPUT);
  pinMode(Motor1_2, OUTPUT);
  pinMode(Motor2_1, OUTPUT);
  pinMode(Motor2_2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&codigo)) {
    
    Serial.println(codigo.value, HEX);

    if (codigo.value == 0xFF6897 || codigo.value == 0xE0E006F9) {
      digitalWrite(Motor1_1, HIGH);
      digitalWrite(Motor1_2, LOW);
      digitalWrite(Motor2_1, HIGH);
      digitalWrite(Motor2_2, LOW);
    }
    
    if (codigo.value == 0xFF30CF || codigo.value == 0xE0E0A659) {
      digitalWrite(Motor1_1, HIGH);
      digitalWrite(Motor1_2, LOW);
      digitalWrite(Motor2_1, LOW);
      digitalWrite(Motor2_2, HIGH);
    }

    if (codigo.value == 0xFF18E7 || codigo.value == 0xE0E08679) {
      digitalWrite(Motor1_1, LOW);
      digitalWrite(Motor1_2, HIGH);
      digitalWrite(Motor2_1, LOW);
      digitalWrite(Motor2_2, HIGH);
    }

    if (codigo.value == 0xFF7A85 || codigo.value == 0xE0E046B9) {
      digitalWrite(Motor1_1, LOW);
      digitalWrite(Motor1_2, HIGH);
      digitalWrite(Motor2_1, HIGH);
      digitalWrite(Motor2_2, LOW);
    }
    
    if (codigo.value == 0xE0E016E9) {
      digitalWrite(Motor1_1, LOW);
      digitalWrite(Motor1_2, LOW);
      digitalWrite(Motor2_1, LOW);
      digitalWrite(Motor2_2, LOW);
    }

    
    delay(500);
    irrecv.resume();
  }
}
