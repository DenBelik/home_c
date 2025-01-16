#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "temp_function.h"

#define PARAM_COUNT 6

void print_help() {
    printf("-h: Help key. Displays information about all other keys and their purpose\n");
    printf("\n");
    printf("-f file_name: Specifying the file to be processed, where file_name is the name of file\n"); 
    printf("              If the key '-m' is not added in this mode, then all statistics for entire file will be displayed\n");
    printf("\n");
    printf("-m xx: Selecting a month to obtain statistics for a specific month, where xx is the month\n");
    printf("\n");
}

int main(int argc, char *argv[]) {
    printf("\n");

    if (argc < 2) { 
        print_help(); 
        return 0; 
    }

    int err_counter[13] = {0};
    int month_counter[13] = {0};
    size_t len = 10;
    size_t size = 0;
    FILE *fin, *fout;
    char *filename;
    Sensor *sensor_arr = NULL;

    int rez = 0;
    int month = -1;

    while((rez = getopt(argc, argv, "hf:m:")) != -1) {
        switch (rez)
        {
        case 'h':
            print_help();
            return 0;
        case 'f':
            filename = optarg;
            break;
        case 'm':
            month = atoi(optarg);
            break;
        default:
            printf("Unknown key: -%c\n", optopt);
            print_help();
            return 1;
        }
    }

    fin = fopen(filename, "r");

    if (fin == NULL) {
        printf("File doesn't exist!");
        return 1;
    }

    sensor_arr = malloc(len * sizeof(Sensor));

    if (sensor_arr == NULL) {
        printf("No memory!");
        return 1;
    }

    int scan;
    Sensor temp;

    while((scan = fscanf(fin, "%hu;%hhu;%hhu;%hhu;%hhu;%hhd", &temp.year, &temp.month, &temp.day, &temp.hour, &temp.minute, &temp.temperature)) > 0) {
        month_counter[temp.month]++;
        if (scan < PARAM_COUNT) {
            char s[20];
            scan = fscanf(fin, "%[^\n]", s);
            err_counter[temp.month]++;
        } else {
            if (size == len) {
                len *= 2;
                sensor_arr = realloc(sensor_arr, len * sizeof(Sensor));
            }
            add_record(sensor_arr, size, temp.year, temp.month, temp.day, temp.hour, temp.minute, temp.temperature);
            size++;
        }
    }

    fclose(fin);

    if (month != -1) {
        printf(" #  Year  Month  NuValue  ErValue  MonthAvg  MonthMax  MonthMin\n");
        printf(" 0  %4hu %4hhu %7d %8d %9hhd %9hhd %9hhd\n",    sensor_arr[0].year,
                                                                month,
                                                                month_counter[month],
                                                                err_counter[month],
                                                                median_month_temp(sensor_arr, month, size),
                                                                max_month_temp(sensor_arr, month, size),
                                                                min_month_temp(sensor_arr, month, size));
    } else {
        printf(" #  Year  Month  NuValue  ErValue  MonthAvg  MonthMax  MonthMin\n");
        for (int i = 0; i < 12; ++i) {
            printf("%2d  %4hu %4hhu %7d %8d %9hhd %9hhd %9hhd\n",   i,
                                                                    sensor_arr[i].year,
                                                                    i+1,
                                                                    month_counter[i+1],
                                                                    err_counter[i+1],
                                                                    median_month_temp(sensor_arr, i+1, size),
                                                                    max_month_temp(sensor_arr, i+1, size),
                                                                    min_month_temp(sensor_arr, i+1, size));
        }
        printf("\n");
        printf("Year statistics: average is %hhd, max is %hhd, min is %hhd",    median_year_temp(sensor_arr, size),
                                                                                max_year_temp(sensor_arr, size),
                                                                                min_year_temp(sensor_arr, size));
    }

    free(sensor_arr);

    return 0;
}
