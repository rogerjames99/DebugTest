#pragma GCC optimize("O0")

#include <Arduino.h>
#include "TeensyDebug.h"

int mark = 0;

void blinker(int count = 1)
{
    digitalWrite(LED_BUILTIN, 0);
    for (int i = 0; i < count; i++)
    {
        digitalWrite(LED_BUILTIN, 1);
        delay(100);
        digitalWrite(LED_BUILTIN, 0);
    }
    delay(200);
}

void test_function()
{
    mark++;
}

void setup()
{
    while (!SerialUSB1)
    {
        delay(100);
    } // wait for Serial Debugger to be ready
    // Launch the GDB debugger stub
#ifdef GDB_IS_ENABLED
    debug.begin(SerialUSB1);
    delay(100);
    halt_cpu();
#endif
    blinker(10);
    while (!Serial)
    {
        delay(100);
    } // wait for Serial Monitor to be ready
    Serial.printf("Serial is ready\n");
    Serial.flush();
}

void loop()
{
    test_function();
    Serial.println(mark);
    blinker(5);
    delay(10000);
}