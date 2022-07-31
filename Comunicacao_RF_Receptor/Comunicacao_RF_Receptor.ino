#include <VirtualWire.h> //carrega a biblioteca para comunicação

//PINO 11 PARA RECEBER

int l1, l2, l3, l4 = 0; //variáveis para identificação status LEDs

void setup() {
  pinMode(31, OUTPUT); //LED1
  pinMode(33, OUTPUT); //LED2
  pinMode(35, OUTPUT); //LED3
  pinMode(37, OUTPUT); //LED4

  Serial.begin(9600);

  vw_set_ptt_inverted(true);
  vw_setup(2000); //velocidade comunicação, bits por segundos
  vw_rx_start(); //inicializa o receptor
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) { //verifica o recebimento de informações
    Serial.println(buf[0]);
    switch (buf[0]) {
      case 49: //1 em DECIMAL na tabela ASCII
        if (l1 == 0) { //confere se o LED está acesou ou apagado
          digitalWrite(31, HIGH); //acende LED
          l1 = 1; //muda o status do LED
        }
        else {
          digitalWrite(31, LOW); //apaga LED
          l1 = 0; //muda o status do LED
        }
        break;
      case 50:
        if (l2 == 0) {
          digitalWrite(33, HIGH);
          l2 = 1;
        }
        else {
          digitalWrite(33, LOW);
          l2 = 0;
        }
        break;
      case 51:
        if (l3 == 0) {
          digitalWrite(35, HIGH);
          l3 = 1;
        }
        else {
          digitalWrite(35, LOW);
          l3 = 0;
        }
        break;
      case 52:
        if (l4 == 0) {
          digitalWrite(37, HIGH);
          l4 = 1;
        }
        else {
          digitalWrite(37, LOW);
          l4 = 0;
        }
        break;
      default: return;
    }
  }
}
