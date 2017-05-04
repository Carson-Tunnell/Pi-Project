#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "smoke_sensor.h"
#include "temp_sensor.h"
#include <wiringPi.h>

//Must Use Wiring pi to initialize system and read data from pins
//http://wiringpi.com/reference/setup/
using namespace std;

//individual Gas sensors if set
string check_smoke_sensors(smoke_sensor s){
    string result = "";
    //MQh3
    if(s.MQ3() == 1){
	cout << "\t-MQ3 sensor is activated\n";
	result += "3,";
    }else result += "0,";
    //MQ5
    if(s.MQ5() == 1){
	cout << "\t-MQ5 sensor is activated\n";
	result +="5,";
    }else result += "0,";
    //MQ7
    if(s.MQ7() == 1){
	cout << "\t-MQ7 sensor is activated\n";
    	result += "7,";
    }else result +="0,";
    //flame
    if(s.flame() == 1){
    	cout << "\t-Flame detected\n";
	result += "9";
    }else result +="0";
    return result;
}
double get_temp(temp_sensor t){
    return t.get_temp();
}
double get_humidity(temp_sensor t){
    return t.get_humid();
}
int main(void)
{
    //map <string, bool> sensors;
    wiringPiSetup();
    
    smoke_sensor sensor_s;
    temp_sensor sensor_t;
    //Start smoke_sensor
    
    //opens output file as csv
    ofstream output("/home/pi/Alarm/outfile.csv");
    //Get temp;
    output << "Temperature,";
    output << get_temp(sensor_t) << '\n';
    output << "Humidity,";
    output << get_humidity(sensor_t) << '\n';
    output << "Smoke,";
    //Check smoke sensor;
    if(sensor_s.detection()){
	sensor_s.alert();
	cout << "Smoke sensor is activated" << '\n';
        output << check_smoke_sensors(sensor_s);
	output << "\n";
    }else output << "0,0,0,0\n";
    
    output.close();
    cout << " \n";

    system("scp -i /home/pi/.ssh/id_rsa /home/pi/Alarm/outfile.csv ctunnell@albany.cs.colostate.edu:/s/bach/l/under/ctunnell/public_html/outfile.csv");

	return 0;
}