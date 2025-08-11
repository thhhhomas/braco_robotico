# Braço Robótico

O projeto foi desenvolvido para um braço robótico de MDF que possui 4 servo motores.

---

## Materiais

 - 1 Arduino Uno
 - 2 Módulos Joystick
 - 1 Braço Mecânico (com quatro servo motores)
 - Jumpers

---

## Motores

Os motores foram separados dentro deste projeto por sua respectiva função, sendo eles:
 - Motor 0 (base): movimenta o braço inteiro, indo da esquerda à direita;
 - Motor 1 (avanço): movimeta o braço para frente;
 - Motor 2 (elevar): eleva a garra;
 - Motor 3 (garra): abre e fecha a garra.

---

## Joysticks

Os joysticks funcionam como potenciômetros, eles geram uma entrada analógica que pode ser lida e, assim, determinar a movimentação das articulações. Dois joysticks foram utilizados, para simular um controle de video-game, cada um possui eixo x,y e um botão. Neste projeto, os joysticks foram separados entre o da esquerda e o da direita:
 - Direita: o eixo y controla o motor base e o eixo x controla o motor de avanço;
 - Esquerda: o eixo x controla o motor de elevação ee o botão controla a abertura e fechamento da garra.

---

## Subir código para o arduino

"braco_robotico.ino" é o arquivo com o código fonte usado no braço mecânico. Você pode copiar esse arquivo, ou seu conteúdo, para dentro de um sketch e então subir para seu Arduino Uno. Se não sabe criar um sketch, consulte a documentação oficial em: https://docs.arduino.cc/software/
