/* 
 * File:   mcal_eeprom.h
 * Author: Ammar yasser
 *
 * Created on 20/9/2023
 */


#include "hal_eeprom.h"


Std_ReturnType EEPROM_Writedata(uint16 address,uint8 Data)
{
    Std_ReturnType ret = E_OK;
    
    //read GIE status and disable GIE 
    uint8 GIE_status = INTCONbits.GIE;
    //Update address register
    EEADRH = (uint8) ((address>>8)&0x03);
    EEADR  = (uint8) (address & 0xFF);
    //Update Data register
    EEDATA = Data;
    //Select Access data EEPROM memory
    EECON1bits.EEPGD = ACCESS_EEPROM_MEMORY;
    EECON1bits.CFGS  = ACCESS_FLASH_OR_EEPROM_MEMORY;
    //Allows Write cycle to flash/EEPROM memory
    EECON1bits.WREN  = ALLOWS_WRITE_CYCLES_FLASH_OR_EEPROM_MEMORY;
    //disable GIE
    INTERRUPT_GlobalINTERRUPTDisable();
    //write sequence : 0x55 -> oxAA 
    EECON2 = 0x55;
    EECON2 = 0xAA;
    //initiate a data erase/write cycle 
    EECON1bits.WR = INITIATES_DATA_EEPROM_WRITE_ERASE;  
    //wait for write complete
    while(EECON1bits.WR);
    //Inhibits write cycles to flash/EEPROM
    EECON1bits.WREN  = INHIBiTS_WRITE_CYCLES_FLASH_OR_EEPROM_MEMORY;
    //restore GIE status
    INTCONbits.GIE = GIE_status;
    
    return ret;
}


Std_ReturnType EEPROM_Readdata(uint16 address,uint8 *Data)
{
    Std_ReturnType ret = E_OK;
    if(Data == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //Update the  address register
        EEADRH = (uint8) ((address>>8)&0x03);
        EEADR  = (uint8) (address & 0xFF);
        //Select Access data EEPROM memory
        EECON1bits.EEPGD = ACCESS_EEPROM_MEMORY;
        EECON1bits.CFGS  = ACCESS_FLASH_OR_EEPROM_MEMORY;
        //initiate a data Read cycle 
        EECON1bits.RD = INITIATES_DATA_EEPROM_READ_ERASE;
        NOP();
        NOP();
        //return Data
        *Data = EEDATA;
    }
    return ret;
}