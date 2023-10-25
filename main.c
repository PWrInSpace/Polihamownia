#include "stdio.h"
#include "freertos/task.h"
#include "freertos/FreeRTOS.h"

TaskHandle_t myTaskHandle = NULL;
TaskHandle_t myTaskHandle2 = NULL;

void Demo_Task(void *arg) {
    while(1) {
        printf("Demo_Task printing...\n");
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}

oid Demo_Task2(void *arg) {
    while(1) {
        printf("222222222 printing...\n");
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}

void app_main(void) {
    xTaskCreate(Demo_Task, "Demo_Task", 4096, NULL, 10, &myTaskHandle);
    xTaskCreatePinnedToCore(Demo_Task2, "Demo_Task2", 4096, NULL, 10, &myTaskHandle2, 1);

    return;
}