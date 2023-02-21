#pragma GCC optimize("O0")

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
    debug.begin(SerialUSB1);
    delay(100);
    halt_cpu();
#endif
}

void loop()
{
    test_function();
    Serial.println(mark);
}
