#include "stm32f4xx_hal.h"   // Core HAL library
#include "stm32f4xx_hal_gpio.h" // GPIO handling
#include "stm32f4xx_hal_rcc.h"  // Clock configuration

#define LED_PIN GPIO_PIN_5
#define LED_PORT GPIOA

void SystemClock_Config(void);
void GPIO_Init(void);

int main(void) {
    HAL_Init();             // Initialize HAL library
    SystemClock_Config();   // Configure system clock
    GPIO_Init();            // Initialize GPIO

    while (1) {
        HAL_GPIO_TogglePin(LED_PORT, LED_PIN); // Toggle LED
        HAL_Delay(500); // Wait 500ms
    }
}

void GPIO_Init(void) {
    __HAL_RCC_GPIOA_CLK_ENABLE(); // Enable GPIOA clock

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    
    HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);
}

void SystemClock_Config(void) {
    // System clock configuration should be set based on your MCU and application
}
