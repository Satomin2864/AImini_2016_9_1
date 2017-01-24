/*******************************************************************************
* File Name: IN_H.c  
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
#include "IN_H.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 IN_H__PORT == 15 && ((IN_H__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: IN_H_Write
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
void IN_H_Write(uint8 value) 
{
    uint8 staticBits = (IN_H_DR & (uint8)(~IN_H_MASK));
    IN_H_DR = staticBits | ((uint8)(value << IN_H_SHIFT) & IN_H_MASK);
}


/*******************************************************************************
* Function Name: IN_H_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  IN_H_DM_STRONG     Strong Drive 
*  IN_H_DM_OD_HI      Open Drain, Drives High 
*  IN_H_DM_OD_LO      Open Drain, Drives Low 
*  IN_H_DM_RES_UP     Resistive Pull Up 
*  IN_H_DM_RES_DWN    Resistive Pull Down 
*  IN_H_DM_RES_UPDWN  Resistive Pull Up/Down 
*  IN_H_DM_DIG_HIZ    High Impedance Digital 
*  IN_H_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void IN_H_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(IN_H_0, mode);
}


/*******************************************************************************
* Function Name: IN_H_Read
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
*  Macro IN_H_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 IN_H_Read(void) 
{
    return (IN_H_PS & IN_H_MASK) >> IN_H_SHIFT;
}


/*******************************************************************************
* Function Name: IN_H_ReadDataReg
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
uint8 IN_H_ReadDataReg(void) 
{
    return (IN_H_DR & IN_H_MASK) >> IN_H_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(IN_H_INTSTAT) 

    /*******************************************************************************
    * Function Name: IN_H_ClearInterrupt
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
    uint8 IN_H_ClearInterrupt(void) 
    {
        return (IN_H_INTSTAT & IN_H_MASK) >> IN_H_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
