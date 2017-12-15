#ifndef nmea_h
#define nmea_h

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>


typedef struct _nmea{
	char time[11];		/**< Time - hh:mm:ss:ss */
	double  lat;        /**< Latitude in NDEG - [degree][min].[sec/60] */
    char    ns;         /**< [N]orth or [S]outh */
	double  lon;        /**< Longitude in NDEG - [degree][min].[sec/60] */
    char    ew; 		/**< [E]ast or [W]est */
}nmea;

int nmea_parse( nmea *position, char data[]);


#endif