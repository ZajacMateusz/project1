 #include <stdio.h>
 #include <stdlib.h>

#include "src/nmea.h"
 
char uart_data[] = "$GPGLL,4916.45,N,12311.12,W,225444,A";

typedef struct device_data{
	 nmea *position;
	 double snow_depth;
}device_data;

void print_device_data(device_data *dev){
	printf("%f %c\n", dev->position->lat, dev->position->ns);
	printf("%f %c\n", dev->position->lon, dev->position->ew);
	printf("%s \n", dev->position->time);
}

 int main ()
 {
    device_data *dev1 = malloc(sizeof(device_data));
 	dev1->position = malloc(sizeof(nmea)); 	

 	nmea_parse( dev1->position, uart_data);
	print_device_data(dev1);

    return 0;
 }