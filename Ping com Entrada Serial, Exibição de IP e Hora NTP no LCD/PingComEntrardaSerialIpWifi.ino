//link do repositório: https://github.com/d-Jhon-b/IOT-Models.git
//link do exemplo no wolki: https://wokwi.com/projects/463375495463307265


#include <WiFi.h>
#include <ESPping.h> // Biblioteca disponível no seu Wokwi
#include <LiquidCrystal_I2C.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define COLUNAS 20
#define LINHAS 4
LiquidCrystal_I2C lcd(0x27, COLUNAS, LINHAS);

const char *ssid = "Wokwi-GUEST";
const char *password = "";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "a.st1.ntp.br", -3 * 3600); 

String host = ""; 

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();

  WiFi.begin(ssid, password);
  lcd.setCursor(0, 0);
  lcd.print("Conectando WiFi...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConectado!");
  Serial.print("IP local: ");
  Serial.println(WiFi.localIP());
  
  timeClient.begin();
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Aguardando Host...");
  Serial.println("Digite o endereco do host (ex: 8.8.8.8) no Serial:");
}

void loop() {
  timeClient.update();
  
  // Atualiza a hora na primeira linha
  lcd.setCursor(0, 0);
  lcd.print("Hora: ");
  lcd.print(timeClient.getFormattedTime());

  if (Serial.available() > 0) {
    host = Serial.readStringUntil('\n');
    host.trim(); 
    
    if (host.length() > 0) {
      lcd.clear();
      // Mostra a hora novamente após o clear
      lcd.setCursor(0, 0);
      lcd.print("Hora: ");
      lcd.print(timeClient.getFormattedTime());
      
      lcd.setCursor(0, 1);
      lcd.print("Host: ");
      lcd.print(host.substring(0, 14));
      
      Serial.print("\nTestando ping para: ");
      Serial.println(host);

      // Na ESPping, o objeto geralmente é 'Ping'
      // O método ping() retorna true se houver resposta
      if (Ping.ping(host.c_str(), 3)) {
        float avgTime = Ping.averageTime();
        
        lcd.setCursor(0, 2);
        lcd.print("Status: Online    ");
        
        lcd.setCursor(0, 3);
        lcd.print("Ping: ");
        lcd.print(avgTime, 1); // Uma casa decimal
        lcd.print("ms      ");

        Serial.print("Sucesso! Tempo medio: ");
        Serial.print(avgTime);
        Serial.println("ms");
      } else {
        lcd.setCursor(0, 2);
        lcd.print("Status: Offline   ");
        lcd.setCursor(0, 3);
        lcd.print("Erro no Ping      ");
        Serial.println("Erro: Host inacessivel.");
      }
    }
  }

  delay(1000); 
}
