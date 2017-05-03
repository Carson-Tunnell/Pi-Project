#include <wiringPi.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


class temp_sensor
{
    public:
       temp_sensor(int=4);    // call once to set the pin for the temp sensor
       double get_temp();          //returns a double with the current temp
       double get_humid();         //returns a double with the current humidity
       int* read_dht11(); // reads raw data from DHT_11
    private:
        int pin;
        int dht11_dat[5];
};
