#ifndef SENSOR_TYPES_H
#define SENSOR_TYPES_H

#define MAX_SENSORS 64

typedef struct {
    char label[64];
    float temperature;
} SensorData;

#endif
