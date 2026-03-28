
//semáforo de carros
#define LED_RED 13
#define LED_YELLOW 12
#define LED_GREEN 11

//parte de pedestres
#define LED_P_RED 9
#define LED_P_GREEN 8

#define BUTTON_OPEN 6

unsigned long int tempo_atual;   
unsigned long int tempo_30000ms;


void setup() {
  Serial.begin(9600);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(BUTTON_OPEN, INPUT);
  



  pinMode(LED_P_RED, OUTPUT);
  pinMode(LED_P_GREEN, OUTPUT);
  tempo_30000ms = millis();
}

void loop() {
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_P_RED, HIGH);
  digitalWrite(LED_P_GREEN, LOW);

  for (int i = 0; i < 100; i++) { 
    if (digitalRead(BUTTON_OPEN) == HIGH) {
      Serial.println("Botao pressionado! Cortando ciclo automatico...");
      Serial.println("init dos cabaça de nós todos");
      break; 
    }
    delay(100); 
  }

  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, HIGH);
  delay(3000); 

  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, HIGH);
  delay(1000); 
  
  digitalWrite(LED_P_RED, LOW);
  digitalWrite(LED_P_GREEN, HIGH);
  delay(8000); 

  digitalWrite(LED_P_GREEN, LOW);
  digitalWrite(LED_P_RED, HIGH);
  delay(2000);


}
