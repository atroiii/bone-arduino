# 🧢Aplicação de Tecnologia Embarcada para Acessibilidade de Pessoas​ com Deficiência Visual

&nbsp;&nbsp;&nbsp;De acordo com a Organização Mundial da Saúde (OMS), estima-se que cerca de 285 milhões de pessoas no mundo vivem com algum tipo de deficiência visual, sendo que 39 milhões são cegas e 246 milhões têm baixa visão, limitando sua autonomia e segurança na locomoção.Embora existam tecnologias assistivas como bengalas e cães-guia, muitas são inacessíveis devido ao alto custo ou à complexidade de uso. Com o avanço da eletrônica e da programação embarcada, é possível desenvolver soluções simples, eficazes e de baixo custo.​Este projeto propõe a criação de um boné inteligente com sensor ultrassônico e buzzer, capaz de alertar o usuário sobre obstáculos à sua frente, promovendo maior independência e segurança.​

## 🧠 Objetivo do Projeto
 Desenvolver um protótipo de boné inteligente utilizando tecnologia embarcada com Arduino, sensor ultrassônico e buzzer, com o propósito de auxiliar pessoas com deficiência visual na detecção de obstáculos, promovendo maior autonomia, segurança e inclusão na mobilidade urbana

## 🛠 Métodos

 Materiais Utilizados:​

 o Boné comum​

 o Arduino Uno​

 o Sensor ultrassônico HC-SR04​

 o Buzzer piezoelétrico​

 o Jumpers, protoboard e fonte de alimentação portátil​

 Procedimentos:​

 o Fixação do sensor ultrassônico na aba frontal do boné.​

 o Programação do Arduino para medir a distância entre  o sensor e obstáculos à frente.​

 o Configuração do buzzer para emitir um som quando a distância for igual ou inferior a 30 cm.​

 o Testes em ambiente controlado com diferentes tipos de obstáculos.​

 o Avaliação da resposta do sistema e conforto do usuário.

## 📦 Código
O código foi desenvolvido na IDE Arduino

```cpp
#include <Arduino_FreeRTOS.h>

const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 8;

volatile int distance = 0;

void TaskUltrasonic(void *pvParameters);
void TaskBuzzer(void *pvParameters);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);

  xTaskCreate(TaskUltrasonic, "Ultrasonic", 128, NULL, 2, NULL);
  xTaskCreate(TaskBuzzer, "Buzzer", 128, NULL, 1, NULL);
}

void loop() {}


void TaskUltrasonic(void *pvParameters) {
  long duration;
  for (;;) {
    digitalWrite(trigPin, LOW);
    vTaskDelay(1);
    digitalWrite(trigPin, HIGH);
    vTaskDelay
(1);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;

    Serial.print("Distancia: ");
    Serial.print(distance);
    Serial.println(" cm");

    vTaskDelay(100);
  }
}


void TaskBuzzer(void *pvParameters) {
  for (;;) {
    if (distance <= 30) {
      digitalWrite(buzzerPin, HIGH);
    } else {
      digitalWrite(buzzerPin, LOW);
    }
    vTaskDelay(50);
  }
}

```
##Esquema Eletrico
![Esquema_Eletrico](esquema_elétrico.png)


## ✅Resultados
 Durante os testes realizados, o sistema foi capaz de detectar obstáculos com precisão a uma distância de 30 cm, sendo possível ajustar essa distância conforme necessário através da programação do Arduino. ​
O buzzer emitiu alertas sonoros imediatos, pois foi implementado um sistema operacional de tempo real (FreeRTOS), proporcionando maior eficiência e controle das tarefas, permitindo ao usuário reagir antes de uma possível colisão. O boné mostrou-se confortável e funcional.

