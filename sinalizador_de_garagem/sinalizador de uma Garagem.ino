//link do repositório: https://github.com/d-Jhon-b/IOT-Models.git
//link do exemplo no wolki: https://wokwi.com/projects/459671671209434113



#define BUZZER 10
#define LED_R 9
#define LED_Y 8

void setup() {
  pinMode(LED_Y, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  digitalWrite(LED_Y, HIGH);
  digitalWrite(LED_R, LOW);
  tone(BUZZER, 1000);
  delay(500);

  digitalWrite(LED_Y, LOW);
  digitalWrite(LED_R, HIGH);
  tone(BUZZER, 800); 
  delay(500);
}