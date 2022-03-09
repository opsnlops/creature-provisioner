#include <Arduino.h>
#include <Preferences.h>

/**
 * @brief Provisions a new ESP32
 * 
 * Sets up a new ESP32 with the basics needed to work and get on the network. Note
 * that this will wipe the NVS on a device. Good to know if it had been used for
 * ESPHome before. :)
 * 
 */

#includes "secrets.h"

void setup()
{

  
}

void loop()
{
  vTaskDelete(NULL);
}