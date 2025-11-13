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
    vTaskDelay(1);
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
