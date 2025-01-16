#include "temp_function.h"
#include <stdio.h>

void sensor_replace(Sensor *s, int i, int j) {
    Sensor temp;
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

uint16_t date_to_int(Sensor *s) {
    return s->year << 16 | s->month << 8 | s->day;
}

void sensor_sort_by_temp(Sensor *s, size_t size) {
    for (int i = 0; i < size-1; ++i) {
        for (int j = i; j < size; ++j) {
            if (s[i].temperature >= s[j].temperature)
                sensor_replace(s, i, j);
        }
    }
}

void sensor_sort_by_date(Sensor *s, size_t size) {
    for (int i = 0; i < size-1; ++i) {
        for (int j = 0; j < size; ++j) {
            if (date_to_int(s + i) >= date_to_int(s + j))
                sensor_replace(s, i, j);
        }
    }
}

uint8_t median_month_temp(Sensor *s, uint8_t month, size_t size) {
    int sum = 0;
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if (s[i].month == month) {
            sum += s[i].temperature;
            counter++;
        }
    }
    return sum/counter;
}

uint8_t min_month_temp(Sensor *s, uint8_t month, size_t size) {
    int8_t min = 99;
    for (int i = 0; i < size; ++i) {
        if (s[i].month == month && s[i].temperature < min)
            min = s[i].temperature;
    }
    return min;
}

uint8_t max_month_temp(Sensor *s, uint8_t month, size_t size) {
    int8_t max = -99;
    for (int i = 0; i < size; ++i) {
        if (s[i].month == month && s[i].temperature > max)
            max = s[i].temperature;
    }
    return max;
}

uint8_t median_year_temp(Sensor *s, size_t size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += s[i].temperature;
    }
    return (uint8_t)(sum/size);    
}

uint8_t min_year_temp(Sensor *s, size_t size) {
    int8_t min = 99;
    for (int i = 0; i < size; ++i) {
        if (s[i].temperature < min)
            min = s[i].temperature;
    }
    return min;    
}


uint8_t max_year_temp(Sensor *s, size_t size) {
    int8_t max = -99;
    for (int i = 0; i < size; ++i) {
        if (s[i].temperature > max)
            max = s[i].temperature;
    }
    return max;    
}

void add_record(Sensor *s, size_t num, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t temperature) {
    s[num].day = day;
    s[num].hour = hour;
    s[num].minute = minute;
    s[num].month = month;
    s[num].temperature = temperature;
    s[num].year = year;
}
