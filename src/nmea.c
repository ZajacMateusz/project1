#include "nmea.h"

int nmea_parse( nmea *position, char data[] ){
	
char buff[10];
	int data_number= 0;
	int i, j;
	for(i= 0; i< strlen(data); ++i){
		j= 0;
		while(data[i]!=',' && i< strlen(data)){
			buff[j++]= data[i++]; 
		}; 

		switch(data_number){
			case 0:
				if(strcmp(buff, "$GPGLL")!= 0)
					return 0;					
				break;
			case 1:
				position->lat = atof(buff);
				break;
			case 2:
				position->ns = buff[0];
				break;
			case 3:
				position->lon = atof(buff);
				break;
			case 4:
				position->ew = buff[0];
				break;
			case 5:{
				char temp_buff[11]= "00:00:00:00";
				temp_buff[0]= buff[0];
				temp_buff[1]= buff[1];
				temp_buff[3]= buff[2];
				temp_buff[4]= buff[3];
				temp_buff[6]= buff[4];
				temp_buff[7]= buff[5];
				strcpy(position->time, temp_buff);
				break;
			}
			
		}
		++data_number;
	}
	return 0;
}