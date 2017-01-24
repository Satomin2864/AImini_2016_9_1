/*******************************************************************************
* File Name: SDA.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "SDA.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 SDA__PORT == 15 && ((SDA__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: SDA_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void SDA_Write(uint8 value) 
{
    uint8 staticBits = (SDA_DR & (uint8)(~SDA_MASK));
    SDA_DR = staticBits | ((uint8)(value << SDA_SHIFT) & SDA_MASK);
}


/*******************************************************************************
* Function Name: SDA_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SDA_DM_STRONG     Strong Drive 
*  SDA_DM_OD_HI      Open Drain, Drives High 
*  SDA_DM_OD_LO      Open Drain, Drives Low 
*  SDA_DM_RES_UP     Resistive Pull Up 
*  SDA_DM_RES_DWN    Resistive Pull Down 
*  SDA_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SDA_DM_DIG_HIZ    High Impedance Digital 
*  SDA_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SDA_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(SDA_0, mode);
}


/*******************************************************************************
* Function Name: SDA_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro SDA_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SDA_Read(void) 
{
    return (SDA_PS & SDA_MASK) >> SDA_SHIFT;
}


/*******************************************************************************
* Function Name: SDA_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 SDA_ReadDataReg(void) 
{
    return (SDA_DR & SDA_MASK) >> SDA_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SDA_INTSTAT) 

    /*******************************************************************************
    * Function Name: SDA_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 SDA_ClearInterrupt(void) 
    {
        return (SDA_INTSTAT & SDA_MASK) >> SDA_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
