# EEPROM Wear Leveling Library

This library provides wear leveling functionality for EEPROM, specifically designed for the M95M02 EEPROM with a capacity of 256KB and a page size of 256 bytes. Wear leveling helps to extend the lifespan of EEPROM by distributing write and erase cycles more evenly across memory.

---

## Features

- Supports wear leveling for EEPROM with customizable memory size and page size.
- Allows writing and reading of data with wear leveling to prevent excessive wear on specific memory locations.
- Optimized for M95M02 EEPROM but can be adapted for other EEPROMs with similar characteristics.

---

## Usage

### Initialization

To initialize the EEPROM with wear leveling, call the `EEPROM_init` function with the memory size (in KB), page size (in bytes), and the number of data blocks to manage:

```c
uint8_t EEPROM_init(uint8_t mem_size, uint8_t page_size, uint8_t no_of_dat);
```

- mem_size: Total EEPROM memory size in KB.
- page_size: Size of each page in bytes.
- no_of_dat: Number of data blocks to manage.


### Writing and Reading Data
To write or read data with wear leveling, use the CALL_EEPROM function:

```c
void CALL_EEPROM(uint8_t data_no, uint8_t data_size, bool command);
```
- data_no: Data block number to be written or read.
- data_size: Size of the data in bytes.
- command: Set to 1 for write operations or 0 for read operations.


###Internal Functions
- SEN_check
The SEN_check function is used internally to determine the correct address and page for the next write operation:

```c
uint32_t SEN_check(uint32_t start, uint32_t stop, uint8_t step, uint32_t last_add, uint32_t curru_page);
```

---

## Example

Here’s an example of how to use the library:

```c
#include "EEPROM_WL.h"

int main() {
    EEPROM_init(256, 256, 10); // Initialize EEPROM with 256KB memory, 256B page size, managing 10 data blocks

    // Write 8 bytes of data to block 1
    CALL_EEPROM(1, 8, 1);

    // Read 8 bytes of data from block 1
    CALL_EEPROM(1, 8, 0);

    return 0;
}
```

---

## Dependencies
This library requires the following dependencies:

- EEPROM_SPI.h: SPI communication functions for EEPROM.
- EEPROM_Data_struct.h: Data structures used for managing EEPROM data.
License
- This project is licensed under the MIT License - see the LICENSE file for details.
  
---

## Author
 Pathum Jeewantha Dissanayake 

---

## Acknowledgments
Special thanks to everyone who has contributed to the development and testing of this library.


