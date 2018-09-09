/*
 * hw_def.h
 *
 *  Created on: 2018. 5. 12.
 *      Author: Baram
 */

#ifndef SRC_HW_HW_DEF_H_
#define SRC_HW_HW_DEF_H_

#include "def.h"
#include "bsp.h"



#define _USE_HW_EEPROM



#define FLASH_FW_SIZE                     (96*1024)  // 96KB
#define FLASH_FW_ADDR_START               0x08008000
#define FLASH_FW_ADDR_END                 (FLASH_FW_ADDR_START + FLASH_FW_SIZE)




#endif /* SRC_HW_HW_DEF_H_ */
