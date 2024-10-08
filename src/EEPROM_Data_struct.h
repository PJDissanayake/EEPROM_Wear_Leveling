/**
  ******************************************************************************
  EEPROM_Data_struct.h
  For M95m02 / EEPROM=256KB /PAGE_SIZE=256B
  Author:   Pathum J Dissanayake
  Updated:  Dec 15, 2023
  ******************************************************************************
**/

#ifndef SRC_EEPROM_DATA_STRUCT_H_
#define SRC_EEPROM_DATA_STRUCT_H_

// Data Buffers
uint8_t data_buf[] = {0x12, 0x13, 0x14, 0x15, 0x16};  // Main data buffer
uint8_t data_buf1[] = {0x00};  // Single-byte buffer
uint8_t tx_buf[300];  // General transmission buffer
uint8_t tx_buf1[5];  // Single-byte transmission buffer
uint8_t rec_data[4];  // Received data buffer
uint8_t rec_data1[1];  // Single-byte received data buffer
uint8_t dum1 = 0xff;  // Dummy byte

// Addresses and Page Information
uint32_t last_writeadd;  // Last write address
uint32_t page_bound;  // Current page boundary
uint32_t prev_add;  // Previous address
uint32_t next_write_add;  // Next write address
uint32_t read_add;  // Read address
uint32_t current_page;  // Current page number


// EEPROM Constants
const uint8_t sen_byte = 0xAA;  // Sentinel byte
const uint32_t room_size = 0x1000;  // Size of each "room"

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

