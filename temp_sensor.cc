//http://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-the-raspberry-pi/
//http://www.raspberrypi-spy.co.uk/2013/03/raspberry-pi-1-wire-digital-thermometer-sensor/
//http://www.rpiblog.com/2012/11/interfacing-temperature-and-humidity.html
#include "temp_sensor.h"

int dht11_dat[5] = { 0, 0, 0, 0, 0 };



using namespace std;

    temp_sensor::temp_sensor(int given_pin)
    {
        pin = given_pin;
        // sets current pin for temp sensor
    }

    double temp_sensor::get_temp()
    {
        read_dht11();
        double temp = dht11_dat[2];

        return temp;
    }

    int* temp_sensor::read_dht11()
    {
        //Code to read Temperature

        //Pi sends read request to sensor in pin value
    
	    uint8_t laststate	= HIGH;
	    uint8_t counter		= 0;
	    uint8_t j		= 0, i;
	
     
	    dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;
 
	    pinMode( pin, OUTPUT );
	    digitalWrite( pin, LOW );
	    delay( 18 );
	    digitalWrite( pin, HIGH );
	    delayMicroseconds( 40 );
	    pinMode( pin, INPUT );
 
	    for ( i = 0; i < 85; i++ )
	    {
    		counter = 0;
	    	while ( digitalRead( pin ) == laststate )
		    {
			    counter++;
			    delayMicroseconds( 1 );
			    if ( counter == 255 )
			    {
				    break;
			    }
		    }   
		laststate = digitalRead( pin );
 
		if ( counter == 255 )
			break;
 
		if ( (i >= 4) && (i % 2 == 0) )
		{
			dht11_dat[j / 8] <<= 1;
			if ( counter > 16 )
				dht11_dat[j / 8] |= 1;
			j++;
		}
	}

        return dht11_dat;
}//end get DHT data


    double temp_sensor::get_humid()
    {
        delay(1000); 
        read_dht11();
        double humid = dht11_dat[0];

        return humid;
    }

