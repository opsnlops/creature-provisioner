#include <Arduino.h>
#include <Preferences.h>

#include <nvs_flash.h>

/**
 * @brief Provisions a new ESP32
 *
 * Sets up a new ESP32 with the basics needed to work and get on the network. Note
 * that this will wipe the NVS on a device. Good to know if it had been used for
 * ESPHome before. :)
 *
 */

#include "secrets.h"

#define WIFI_CONFIG_STORAGE_SPACE "creature-wifi"

void setup()
{

    Preferences prefs;

    Serial.begin(115200);
    while (!Serial && !Serial.available())
        ;

    Serial.println("Provisioning ESP32!");

    Serial.println("Wiping out existing NVS...");
    nvs_flash_erase();
    nvs_flash_init();

    Serial.println("Configuring WiFi");
    prefs.begin(WIFI_CONFIG_STORAGE_SPACE, false);
    prefs.putString("ssid", WIFI_NETWORK);
    prefs.putString("passwd", WIFI_PASSWORD);
    prefs.end();

    Serial.println("Done! Use me!! :)");
}

void loop()
{
    vTaskDelete(NULL);
}