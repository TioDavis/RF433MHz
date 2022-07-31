#include <VirtualWire.h>

//PINO 12 PARA ENVIO

void setup () {
  pinMode(31, INPUT_PULLUP); //botão 1, o PULLUP habilita o nível alto no pino, logo a leitura deve ser com o LOW
  pinMode(33, INPUT_PULLUP); //botão 2
  pinMode(35, INPUT_PULLUP); //botão 3
  pinMode(37, INPUT_PULLUP); //botão 4
  
  Serial.begin(9600);
  
  vw_set_ptt_inverted(true);
  vw_setup(2000); //velocidade em bits por segundo
}

void loop() {

  if (digitalRead(31) == LOW) { //verifica se o botão foi pressionado
    const char *msg = "1"; //mensagem a ser enviada
    vw_send((uint8_t*)msg, strlen(msg)); //envia a mensagem
    vw_wait_tx(); //aguarda o envio da mensagem
    Serial.println(msg);
    while (digitalRead(31) == LOW) {} //aguarda até que o botão seja solto
  }
  if (digitalRead(33) == LOW) {
    const char *msg = "2";
    vw_send((uint8_t*)msg, strlen(msg));
    vw_wait_tx();
    Serial.println(msg);
    while (digitalRead(33) == LOW) {}
  }
  if (digitalRead(35) == LOW) {
    const char *msg = "3";
    vw_send((uint8_t*)msg, strlen(msg));
    vw_wait_tx();
    Serial.println(msg);
    while (digitalRead(35) == LOW) {}
  }
  if (digitalRead(37) == LOW) {
    const char *msg = "4";
    vw_send((uint8_t*)msg, strlen(msg));
    vw_wait_tx();
    Serial.println(msg);
    while (digitalRead(37) == LOW) {}
  }
  
    delay(250);
  
}
