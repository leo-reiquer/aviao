#include <ServoTimer2.h>
#include <VirtualWire.h>

ServoTimer2 esc;
ServoTimer2 leme;
ServoTimer2 profundor;
ServoTimer2 aileron;


#define servoaileron 7
#define servoleme 6
#define servoprofundor 4
#define motorpin 9
#define pinRF 3

byte pacoterecebido[27];
int angulosservo[4];
byte tamanhomaxpacote = sizeof(pacoterecebido);

void setup() {
  Serial.begin(115200);
  esc.attach(motorpin);
  leme.attach(servoleme);
  profundor.attach(servoprofundor);
  aileron.attach(servoaileron);
  vw_set_rx_pin(pinRF);
  vw_setup(2000);   
  vw_rx_start();
}

void loop() {
  vw_get_message(pacoterecebido, tamanhomaxpacote);
  angulosservo[0] = map(pacoterecebido[0], 0, 255, 1000, 1900);
  angulosservo[1] = map(pacoterecebido[1], 0, 255, 1000, 1900);
  angulosservo[2] = map(pacoterecebido[2], 0, 255, 900, 1600);
  angulosservo[3] = map(pacoterecebido[3], 0, 255, 1000, 1900);
  Serial.println(pacoterecebido[0]);
  //esc.write(angulosservo[0]);
  leme.write(angulosservo[0]);
  //profundor.write(angulosservo[0]);
  //aileron.write(angulosservo[3]);
  
}
