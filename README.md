## Documentation

### STM32-microcontroller-using-HAL-library

### 1. **Included Libraries**
```c
#include "stm32f4xx_hal.h"   // Core HAL library
#include "stm32f4xx_hal_gpio.h" // GPIO handling
#include "stm32f4xx_hal_rcc.h"  // Clock configuration
```
These libraries are essential for using STM32 HAL functions:
- **`stm32f4xx_hal.h`**: The main HAL library that includes core functions for initialization and hardware interaction.
- **`stm32f4xx_hal_gpio.h`**: Provides functions to configure and manipulate GPIO pins.
- **`stm32f4xx_hal_rcc.h`**: Handles the clock system of the microcontroller.

### 2. **Defining LED Pin and Port**
```c
#define LED_PIN GPIO_PIN_5
#define LED_PORT GPIOA
```
- `LED_PIN` is set to **GPIO_PIN_5**, meaning the LED is connected to **pin PA5**.
- `LED_PORT` is set to **GPIOA**, meaning the LED is part of **GPIO Port A**.

### 3. **System Clock Configuration (Placeholder)**
```c
void SystemClock_Config(void) {
    // System clock configuration should be set based on your MCU and application
}
```
- The function is meant to configure the clock but is left as a placeholder.
- STM32 microcontrollers require proper clock settings depending on the specific board being used.

### 4. **GPIO Initialization**
```c
void GPIO_Init(void) {
    __HAL_RCC_GPIOA_CLK_ENABLE(); // Enable GPIOA clock

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    
    HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);
}
```
- **`__HAL_RCC_GPIOA_CLK_ENABLE();`**: Enables the clock for **GPIOA** so that it can be used.
- **`GPIO_InitTypeDef GPIO_InitStruct = {0};`**: Defines a struct to configure the GPIO settings.
    - **`Pin = LED_PIN;`** → Configures **PA5** as an output pin.
    - **`Mode = GPIO_MODE_OUTPUT_PP;`** → Sets pin mode to **push-pull output**.
    - **`Pull = GPIO_NOPULL;`** → No internal pull-up or pull-down resistors.
    - **`Speed = GPIO_SPEED_FREQ_LOW;`** → Configures the pin for **low-speed operation**.

### 5. **Main Function**
```c
int main(void) {
    HAL_Init();             // Initialize HAL library
    SystemClock_Config();   // Configure system clock
    GPIO_Init();            // Initialize GPIO

    while (1) {
        HAL_GPIO_TogglePin(LED_PORT, LED_PIN); // Toggle LED
        HAL_Delay(500); // Wait 500ms
    }
}
```
- **`HAL_Init();`**: Initializes the HAL library for proper STM32 function execution.
- **`SystemClock_Config();`**: Configures the clock system (left unimplemented in this case).
- **`GPIO_Init();`**: Calls the function to set up GPIO for the LED.

#### **Infinite Loop (`while (1)`)**
- The microcontroller continuously executes this loop:
    1. **`HAL_GPIO_TogglePin(LED_PORT, LED_PIN);`** → Toggles the state of **PA5** (LED turns on or off).
    2. **`HAL_Delay(500);`** → Waits **500 milliseconds** before toggling again.
- This creates the blinking effect of the LED.

### **Summary**
This program initializes the STM32 microcontroller, sets up GPIO **PA5** as an output, and continuously toggles it every 500ms to make the LED blink.


---

### GPIO


### **1. Understanding GPIO in STM32**
- GPIO pins are versatile and can be configured as **inputs**, **outputs**, **analog**, or for **alternate functions** (such as communication interfaces like SPI, I2C, UART).
- Each STM32 microcontroller has **multiple GPIO ports** (e.g., **GPIOA, GPIOB, GPIOC, etc.**), with each port containing several pins.

### **2. Enabling the GPIO Clock**
Before configuring a GPIO pin, you must enable its corresponding **clock**. This allows the microcontroller to interact with the pin.

```c
__HAL_RCC_GPIOA_CLK_ENABLE(); // Enable clock for GPIOA
```
- The **`__HAL_RCC_GPIOA_CLK_ENABLE();`** function enables the **clock for GPIOA** so that its pins can be used.

### **3. Configuring the GPIO Pin as Output**
We use the **GPIO_InitTypeDef** structure to define the pin configuration:

```c
GPIO_InitTypeDef GPIO_InitStruct = {0}; // Create configuration structure
GPIO_InitStruct.Pin = LED_PIN;          // Select pin PA5
GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // Set as output (Push-Pull)
GPIO_InitStruct.Pull = GPIO_NOPULL;     // No internal pull-up or pull-down resistor
GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW; // Set low-speed mode
```

- **Pin Selection (`Pin = LED_PIN`)**  
  - `LED_PIN` represents **PA5**, meaning the LED is connected to pin **5** of port **A**.
  
- **Mode Selection (`Mode = GPIO_MODE_OUTPUT_PP`)**  
  - **`GPIO_MODE_OUTPUT_PP`** sets the pin as an **output** in **push-pull mode**.
  - Push-Pull mode means the pin can actively drive **high (VCC)** or **low (GND)**.

- **Pull Configuration (`Pull = GPIO_NOPULL`)**  
  - No internal **pull-up or pull-down resistor** is used.  
  - If pull-up/down were enabled, they would affect signal stability.

- **Speed Configuration (`Speed = GPIO_SPEED_FREQ_LOW`)**  
  - Defines the speed at which the pin switches states.
  - Options:  
    - `GPIO_SPEED_FREQ_LOW` → Suitable for basic LED blinking.  
    - `GPIO_SPEED_FREQ_MEDIUM` → Used in moderate-speed signal transmission.  
    - `GPIO_SPEED_FREQ_HIGH` → For high-speed data applications.

### **4. Initializing the GPIO**
Once the configuration structure is prepared, we **initialize the GPIO pin**:

```c
HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);
```

- **`HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);`** tells the microcontroller to apply the settings for **PA5**.

### **5. Toggling the LED**
To control the LED, we use:

```c
HAL_GPIO_TogglePin(LED_PORT, LED_PIN); // Toggle LED state
HAL_Delay(500); // Wait 500ms
```
- **`HAL_GPIO_TogglePin()`** flips the **PA5** state from HIGH to LOW (or vice versa).
- **`HAL_Delay(500);`** waits **500 milliseconds** between toggles, creating a blinking effect.

---

### **Summary**
The GPIO configuration process follows these steps:
1. **Enable the GPIO clock** (`__HAL_RCC_GPIOA_CLK_ENABLE();`).
2. **Define pin settings** (output mode, pull-up/down, speed).
3. **Initialize the GPIO** (`HAL_GPIO_Init();`).
4. **Toggle the pin to blink an LED** (`HAL_GPIO_TogglePin();`).
 
