// 2025 01 09 - Daniel Mitchell - iotcloudlabs.com
// This sketch and supporting files 
// is a working example of multiple parallel working tasks
// each task is split out into a separate file to keep the code as clean and easy to read and debug as possible
// Initial concept credited to "The Las Outpost Workshop" Youtube tutorial : https://youtu.be/382p1NT1Wcs
//
// version 1.0 - 2025 01 09 
// 

#include "led1.h"       // Sketch
#include "led2.h"       // Sketch
#include "led3.h"       // Sketch
#include "temphumid.h"  // Sketch

void setup()
{
    Serial.begin(115200);

    xTaskCreatePinnedToCore(
        led1_sketch,  // Task function
        "taskName",   // Task name
        8192,         // Stack size
        NULL,         // Task input parameters
        1,            // Task priority, be carefull when changing this
        NULL,         // Task handle, add one if you want control over the task (resume or suspend the task)
        1             // Core to run the task on
    );

    xTaskCreatePinnedToCore(
        led2_sketch,  // Task function
        "taskName",   // Task name
        8192,         // Stack size
        NULL,         // Task input parameters
        1,            // Task priority, be carefull when changing this
        NULL,         // Task handle, add one if you want control over the task (resume or suspend the task)
        1             // Core to run the task on
    );

    xTaskCreatePinnedToCore(
        led3_sketch,     // Task function
        "taskName",      // Task name
        8192,            // Stack size
        NULL,            // Task input parameters
        1,               // Task priority, be carefull when changing this
        NULL,            // Task handle, add one if you want control over the task (resume or suspend the task)
        1                // Core to run the task on
    );

    xTaskCreatePinnedToCore(
        temphumid_sketch,     // Task function
        "taskName",      // Task name
        16192,           // Stack size
        NULL,            // Task input parameters
        1,               // Task priority, be carefull when changing this
        NULL,            // Task handle, add one if you want control over the task (resume or suspend the task)
        1                // Core to run the task on
    );

}

void loop()
{
}
