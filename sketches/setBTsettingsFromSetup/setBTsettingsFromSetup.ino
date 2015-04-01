#include <SoftwareSerial.h>
#define RX_PIN 10
#define TX_PIN 11

SoftwareSerial btSerial = SoftwareSerial(RX_PIN, TX_PIN);

void setup() {

  pinMode(TX_PIN, OUTPUT);
  pinMode(RX_PIN, INPUT);

  btSerial.begin(9600);
  Serial.begin(9600);

  Serial.println("Bluetooth with 9600");
  btSerial.write("AT");
  delay(1100);
  while (btSerial.available())     // optional. Display response
    Serial.write(btSerial.read()); // can be removed

  Serial.println("\nChange name");
  btSerial.write("AT+NAMEBotName");
  delay(1100);
  while (btSerial.available())
    Serial.write(btSerial.read());

  Serial.println("\nAjusting PIN - 6666");
  btSerial.write("AT+PIN6666");
  delay(1100);
  while (btSerial.available())
    Serial.write(btSerial.read());
 
  Serial.println("\nBluetooth version:");
  btSerial.write("AT+VERSION");
  delay(1100);
  while (btSerial.available())
    Serial.write(btSerial.read());
}

void loop() {
}
