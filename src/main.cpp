#include <Arduino.h>
#include "TeensyDebug.h"

int mark = 0;

void test_function()
{
    mark++;
}

void setup()
{
    while (!Serial)
    {
        delay(100);
    } // wait for Serial Monitor to be ready
    Serial.printf("Serial is ready\n");
    Serial.flush();
    

    // Launch the GDB debugger stub
#ifdef GDB_IS_ENABLED
    Serial.printf("Calling debug.begin\n");
    debug.begin(SerialUSB1);
    Serial.printf("Back from debug.begin\n");
    delay(100);
    Serial.printf("Calling halt_cpu\n");
    Serial.flush();
    halt_cpu();
    Serial.printf("After halt_cpu\n");
    Serial.flush();
#endif
}

void loop()
{
    test_function();
    Serial.println(mark);
}
