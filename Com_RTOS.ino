#include <Arduino_FreeRTOS.h>

void Task_Controlled(void *param);
void Task_Print(void *param);

TaskHandle_t Task_Handle1;
TaskHandle_t Task_Handle2;

void setup() {
  Serial.begin(9600);
  pinMode(8,INPUT_PULLUP);
  pinMode(13,OUTPUT);

  // Tarefa com prioridade mais alta rodará primeiro
  xTaskCreate(Task_Controlled,"Task1",100,NULL,1,&Task_Handle1);
  xTaskCreate(Task_Print,"Task2",100,NULL,1,&Task_Handle2);
}

void loop() {}

void Task_Controlled(void *param){
  (void) param;

  while(1){
    if(digitalRead(8) == 0){
      while(digitalRead(8) == 0);
      digitalWrite(13,LOW); // Liga
    }
    else digitalWrite(13,HIGH); // Desliga
    vTaskDelay(1000/portTICK_PERIOD_MS); // O Arduino escreverá no monitor serial a cada 1 segundo
  }
}

void Task_Print(void *param){
  (void) param;
  while(1){
    Serial.print("TASKprint");
    vTaskDelay(1000/portTICK_PERIOD_MS); // O Arduino escreverá no monitor serial a cada 1 segundo
  }
}