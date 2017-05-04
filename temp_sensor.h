#include <wiringPi.h>


class temp_sensor
{
    public:
       temp_sensor(int=4);    // call once to set the pin for the temp sensor
       double get_temp();          //returns a double with the current temp
       double get_humid();         //returns a double with the current humidity
    private:
        int pin;
};
