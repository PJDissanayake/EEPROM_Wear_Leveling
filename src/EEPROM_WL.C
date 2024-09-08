/**
  ******************************************************************************
  EEPROM_WL.C
  For M95m02 / EEPROM=256KB /PAGE_SIZE=256B
  Author:   Pathum J Dissanayake
  Updated:  Dec 15, 2023
  ******************************************************************************
*/

#include "stdint.h"
#include <stdbool.h>
#include "EEPROM_SPI.h"
#include "EEPROM_Data_struct.h"

uint8_t mem;
uint8_t pag;
uint32_t base_adr;

uint8_t EEPROM_init(uint8_t mem_size,uint8_t page_size,uint8_t no_of_dat){ //input mem size Kilo bytes value and Page size bytes value
	mem=mem_size*1024;
	pag=page_size;
	base_adr=mem/no_of_dat;
}

void CALL_EEPROM(uint8_t data_no,uint8_t data_size,bool command){ //command 1 for write; 0 for read  ***input  byte value of data size
      uint32_t u_bound=base_adr*(data_no);
      uint32_t l_bound=u_bound-base_adr;

      SEN_check(l_bound, u_bound, data_size,last_writeadd,current_page);
      uint32_t page_bound = l_bound + (current_page * Pag + Pag);

      if(command){//write
	  	if(last_writeadd==0){
			next_write_add=0;
		}
		else{
      		next_write_add=(last_writeadd+(data_size+1));
		}
		
      	write_1byte(last_writeadd, data_buf1);

      	if((next_write_add+data_size+0x1)<page_bound){
      	write_nbyte(next_write_add,data_size,data_buf);
      	}
      	else{
      	next_write_add=page_bound;
      	write_nbyte(next_write_add,data_size,data_buf);
      	}
      }

      else if(!command){//Read
      	read_add=last_writeadd+0x1; 
      	read_nbyte(read_add,data_size);
      }

  }


uint32_t SEN_check(uint32_t start,uint32_t stop,uint8_t step,uint32_t last_add,uint32_t curre_page){
  	for(uint32_t c=0x01;c<(base_adr/pag);c++){
  	for (uint32_t var = (start+((stop-start)/pag)*c); (var+step+1)<stop; var+=(step+1)) {
  		read_1byte(var);
  		if(rec_data1[0]==sen_byte){
  			last_add=var;
  			curre_page=c;
  			break;
  			}
  		else if(var>=(stop-(step+1))){
			if(data_no==1){
				last_add=0;
  				curre_page=0;	
			}
			else{
  				last_add=start-(step+1);
  				curre_page=0;
			}
  			break;
  			}
  		}
  	 }


  	}




