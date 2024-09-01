/**
  ******************************************************************************
  EEPROM_Data_struct.h
  For M95m02 / EEPROM=256KB /PAGE_SIZE=256B
  Author:   Pathum J Dissanayake
  Updated:  Dec 15, 2023
  ******************************************************************************
*/

#ifndef SRC_EEPROM_DATA_STRUCT_H_
#define SRC_EEPROM_DATA_STRUCT_H_

uint8_t data_buf[]={0x12,0x13,0x14,0x15,0x16};
uint8_t data_buf1[]={0x00};
uint8_t tx_buf[300];
uint8_t tx_buf1[5];
uint8_t dum1={0xff};
uint8_t rec_data[4];
uint8_t rec_data1[1];



uint32_t last_writeadd;
uint8_t currunt_page;
uint32_t page_bound;
uint32_t prev_add;
uint32_t next_write_add;
uint32_t read_add;


const uint8_t sen_byte=0xAA;

const uint32_t room_size=0x1000;

uint8_t WREN= 0x06;
uint8_t WRDI= 0x04;
#define RDSR 0x05
#define WRSR 0x01
#define READ 0x03
#define WRITE 0x02
#define RDID 0x83
#define WRID 0x82
#define RDLS 0x83
#define LID 0x82


#endif /* SRC_EEPROM_DATA_STRUCT_H_ */

