#ifndef TEMP_API_H_

#define TEMP_API_H_

#include <inttypes.h>
#include <limits.h>

typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
} Sensor;

void sensor_replace(Sensor *s, int i, int j);
uint16_t date_to_int(Sensor *s);
void sensor_sort_by_temp(Sensor *s, size_t size);
void sensor_sort_by_date(Sensor *s, size_t size);
uint8_t median_month_temp(Sensor *s, uint8_t month, size_t size);
uint8_t min_month_temp(Sensor *s, uint8_t month, size_t size);
uint8_t max_month_temp(Sensor *s, uint8_t month, size_t size);
uint8_t median_year_temp(Sensor *s, size_t size);
uint8_t min_year_temp(Sensor *s, size_t size);
uint8_t max_year_temp(Sensor *s, size_t size);
void add_record(Sensor *s, size_t num, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t temperature);

#endif