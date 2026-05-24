#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "provider.h"

#define MAX_LINE 512

int get_sensors_data(SensorData sensors[], int max_sensors) {

    FILE *fp;
    char line[MAX_LINE];

    int count = 0;

    fp = popen("sensors", "r");

    if (fp == NULL) {
        perror("Error ejecutando sensors");
        return 0;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {

        char name[64];
        float temp;

        if (sscanf(line, "%63[^:]: +%f°C", name, &temp) == 2) {

            // Ignorar sensores basura comunes
            if (
                strcmp(name, "temp1") == 0 ||
                strcmp(name, "Composite") == 0
            ) {
                continue;
            }

            snprintf(sensors[count].label, sizeof(sensors[count].label), "%s", name);
	    sensors[count].temperature = temp;

            count++;

            if (count >= max_sensors)
                break;
        }
    }

    pclose(fp);

    return count;
}
