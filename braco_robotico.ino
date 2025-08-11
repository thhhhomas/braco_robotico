#include <Servo.h>

// Motores

Servo servo_base_0, servo_art_avanco_1, servo_art_elevar_2, servo_garra_3;
int posicoes[4] = {90, 15, 180, 0};
int pinos[4] = {5, 2, 3, 4};
int posicoes_max[4] = {180, 110, 180, 180};
int posicoes_min[4] = {0, 15, 50, 0};

bool estado_garra = true; // true = aberta

// Joysticks

int joy_direita_x = A0;
int joy_direita_y = A1;
int joy_esquerda_x = A2;

int variacao_mais = 70;
int variacao_menos = 30;

// Botão Joysticks

int btn_esquerda = 0;

unsigned long ultimo_click = 0;
const unsigned long tempo_entre_click = 300;

// LED

int led = 13;

const int delay_padrao = 10;

void setup(){
  servo_base_0.attach(pinos[0]);
  servo_base_0.write(posicoes[0]);
  delay(delay_padrao);

  servo_art_avanco_1.attach(pinos[1]);
  servo_art_avanco_1.write(posicoes[1]);
  delay(delay_padrao);

  servo_art_elevar_2.attach(pinos[2]);
  servo_art_elevar_2.write(posicoes[2]);
  delay(delay_padrao);

  servo_garra_3.attach(pinos[3]);
  servo_garra_3.write(posicoes[3]);
  delay(delay_padrao);

  pinMode(btn_esquerda, INPUT_PULLUP);

  pinMode(led, OUTPUT);

  Serial.begin(115200);
  
  Serial.println("Braço ligado");
}

void loop() {
  int x_dir = map(analogRead(joy_direita_x), 0 ,1023, 0, 100);
  int y_dir = map(analogRead(joy_direita_y), 0, 1023, 0, 100);
  int x_esq = map(analogRead(joy_esquerda_x), 0, 1023, 0, 100);

  int btn_esq = digitalRead(btn_esquerda);
  
  Serial.println("-------------Leitura Joysticks----------------");
  Serial.print("Leitura analógico - Direita (x): ");
  Serial.print(x_dir);
  Serial.println();
  Serial.print("Leitura analógico - Direita (y): ");
  Serial.print(y_dir);
  Serial.println();
  Serial.print("Leitura analógico - Esquerda (x): ");
  Serial.print(x_esq);
  Serial.println();
  Serial.println("----------------------------------------------");

  Serial.println("----------------Botão - Garra-----------------");
  if(btn_esq == 0 && millis() - ultimo_click > tempo_entre_click){
    Serial.println("Leitura botão - Apertado");
    mover(true, 3);
    ultimo_click = millis();
  } else {
    Serial.println("Leitura botão - Solto");
  }
  Serial.println("----------------------------------------------");

  Serial.println("-------------Movimentação Motores-------------");
  if(y_dir > variacao_mais){
    mover(false, 0);
  } else if(y_dir < variacao_menos){
    mover(true, 0);
  }

  if(x_dir > variacao_mais){
    mover(true, 1);
  } else if(x_dir < variacao_menos){
    mover(false, 1);
  }

  if(x_esq > variacao_mais){
    mover(true, 2);
  } else if(x_esq < variacao_menos){
    mover(false, 2);
  }
  Serial.println("----------------------------------------------");
}

void mover(bool sentido, int i){
  if (sentido && posicoes[i] < posicoes_max[i]){
    posicoes[i] += 1;
    
  } else if (posicoes[i] > posicoes_min[i]){
    posicoes[i] -= 1;
  }

  switch(i){
    case 0:
      Serial.print("Movendo servo 0 - Base | Posição: ");
      servo_base_0.write(posicoes[i]);
      break;

    case 1:
      Serial.print("Movendo servo 1 - Avanço | Posição: ");
      servo_art_avanco_1.write(posicoes[i]);
      break;

    case 2:
      Serial.print("Movendo servo 2 - Elevar | Posição: ");
       servo_art_elevar_2.write(posicoes[i]);
       break;
    
    case 3:
       if(estado_garra){
         posicoes[i] = 0;
         digitalWrite(led, LOW);
       } else {
         posicoes[i] = 180;
         digitalWrite(led, HIGH);
       }
       Serial.print("Movendo servo 3 - Garra | Posição: ");
       servo_garra_3.write(posicoes[i]);
       delay(delay_padrao*5);
       estado_garra = !estado_garra;

    default:
      break;
  }

  delay(delay_padrao);

  Serial.print(posicoes[i]);
  Serial.println();

  return;
}
