/**
  ******************************************************************************
  EEPROM_SPI.h
  For M95m02 / EEPROM=256KB /PAGE_SIZE=256B
  Author:   Pathum J Dissanayake
  Updated:  Dec 15, 2023
  ******************************************************************************
*/

#include "EEPROM_Data_struct.h"
#include "stm32f1xx_hal_spi.c"
#include "stm32f1xx_hal_gpio.c"


#ifndef SRC_EEPROM_SPI_H_
#define SRC_EEPROM_SPI_H_

uint32_t read_1byte(uint32_t address){
  		tx_buf[0]=READ;
                tx_buf[1]=((address>>16)&0xff);
  		tx_buf[2]=((address>>8)&0xff);
  		tx_buf[3]=(address&0xff);

  		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
  		HAL_SPI_Transmit(&hspi1, tx_buf, 4, 100);
  		HAL_SPI_TransmitReceive(&hspi1,dum1,rec_data1, 1, 100);
  		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
  }


  uint32_t read_nbyte(uint32_t address,uint8_t size){
	  	  uint32_t w_add=address+1;
                tx_buf[0]=READ;
                tx_buf[1]=((w_add>>16)&0xff);
  		tx_buf[2]=((w_add>>8)&0xff);
  		tx_buf[3]=(w_add&0xff);
  		uint8_t var_dum[size];
  		for(int p=0;p<size;p++){
  			var_dum[p]=0xff;
  		}

  		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
  		HAL_SPI_Transmit(&hspi1, tx_buf, size, 1000);
  		HAL_SPI_TransmitReceive(&hspi1,var_dum,rec_data, size, 1000);
  		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
  		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, 1);
  }

uint32_t write_1byte(uint32_t address1,uint8_t data_buf1[1]){
    		tx_buf1[0]=WRITE;
                tx_buf1[1]=((address1>>16)&0xff);
    		tx_buf1[2]=((address1>>8)&0xff);
    		tx_buf1[3]=(address1&0xff);
    		tx_buf1[4]=data_buf1[0];

    		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
    	  	HAL_SPI_Transmit(&hspi1,(uint8_t*)&WREN, 1, 100);
    	  	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);

    	  	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
    	  	HAL_SPI_Transmit(&hspi1, tx_buf1, sizeof(tx_buf1), 100);
    	  	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);

    	  	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
    	  	HAL_SPI_Transmit(&hspi1,(uint8_t*)&WRDI, 1, 100);
    	  	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);

    	  	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
    }

  uint32_t write_nbyte(uint32_t address,uint8_t size,uint8_t data_buf[256]){
  		tx_buf[0]=WRITE;
  		tx_buf[1]=((address>>16)&0xff);
  		tx_buf[2]=((address>>8)&0xff);
  		tx_buf[3]=(address&0xff);
  		tx_buf[4]=0xff;

  			for(int j=0;j<size;j++){
  				tx_buf[j+5]=data_buf[j];
  				}

  			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
  			HAL_SPI_Transmit(&hspi1,(uint8_t*)&WREN, 1, 100);
  			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);

  			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
  			HAL_SPI_Transmit(&hspi1, tx_buf, (size+5), 2000);
  			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);

  			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
  			HAL_SPI_Transmit(&hspi1,(uint8_t*)&WRDI, 1, 100);
  			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);

  			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
  }

#endif /* SRC_EEPROM_SPI_H_ */
