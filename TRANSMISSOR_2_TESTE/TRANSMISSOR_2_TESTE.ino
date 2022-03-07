// VERIFICAR SE O VIRTUAL WIRE ESTÁ NA VERSÃO 3.2
#include <VirtualWire.h>

#define potprofundor A3
#define potleme A2
#define potaileron A1
#define potmotor A0
#define pinRF 3

byte pacote[4];
byte tamanhopacote = sizeof(pacote); //tamanho em bytes do pacote



void setup() {
  vw_set_tx_pin(pinRF);
  vw_setup(2000); // velocidade transmissao 4000 no maximo
 
  Serial.begin(115200);
}

void loop() {
  pacote[0] = map(analogRead(potmotor), 0, 1023, 0, 255);
  pacote[1] = map(analogRead(potleme), 0, 1023, 0, 255); 
  pacote[2] = map(analogRead(potprofundor), 0, 1023, 0, 255);
  pacote[3] = map(analogRead(potaileron), 0, 1023, 0, 255);
  Serial.println(pacote[0]);
  vw_send(pacote, tamanhopacote);
  vw_wait_tx();
}
