//  ESP32: Acionamento LED por tempo

#include <NTPClient.h> // Biblioteca do NTP.
#include <WiFi.h> // Biblioteca do WiFi. 

// -------- Configurações de Wi-fi----------- 
const char* ssid = "***";          //KJB
const char* password = "*****";      //keke1000
// -------- Configurações de relógio on-line----------- 
WiFiUDP udp;
NTPClient ntp(udp, "a.st1.ntp.br", -3 * 3600, 60000); // Cria um objeto "NTP" com as configurações. 

#define led 2              //  Define o LED ao pino D4.
String horario;            // Variável que armazenara a hora 

void setup()
{
  Serial.begin(115200);
  pinMode(led, OUTPUT);        // Define o pino como saída. 
  digitalWrite(led, LOW);      // Apaga o LED. 
  WiFi.begin(ssid, password);
  delay(2000);               // Espera a conexão. 
  ntp.begin();               // Inicia o NTP. 
  ntp.forceUpdate();         // Força o Update. 
}

void loop()
{
  // Armazena na variável HORA, o horário atual.
  horario = ntp.getFormattedTime(); //Retorna um String com a hora formatada como HH:MM:SS
  Serial.println(horario);     // Escreve a hora no monitor serial. 
  if (horario == "03:30:00")
  { // Ao atingir o período definido 
    digitalWrite(led, HIGH);   // O LED Acende 
  }
  if (horario == "03:35:00")
  { //  Ao atingir o período definido 
    digitalWrite(led, LOW);   // O LED Apaga 
  }
  delay(1000);              // Espera 1 segundo. 
}
