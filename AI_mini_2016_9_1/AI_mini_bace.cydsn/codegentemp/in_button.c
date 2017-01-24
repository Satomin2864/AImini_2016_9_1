/*******************************************************************************
* File Name: in_button.c  
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
#include "in_button.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 in_button__PORT == 15 && ((in_button__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: in_button_Write
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
void in_button_Write(uint8 value) 
{
    uint8 staticBits = (in_button_DR & (uint8)(~in_button_MASK));
    in_button_DR = staticBits | ((uint8)(value << in_button_SHIFT) & in_button_MASK);
}


/*******************************************************************************
* Function Name: in_button_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  in_button_DM_STRONG     Strong Drive 
*  in_button_DM_OD_HI      Open Drain, Drives High 
*  in_button_DM_OD_LO      Open Drain, Drives Low 
*  in_button_DM_RES_UP     Resistive Pull Up 
*  in_button_DM_RES_DWN    Resistive Pull Down 
*  in_button_DM_RES_UPDWN  Resistive Pull Up/Down 
*  in_button_DM_DIG_HIZ    High Impedance Digital 
*  in_button_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void in_button_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(in_button_0, mode);
}


/*******************************************************************************
* Function Name: in_button_Read
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
*  Macro in_button_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 in_button_Read(void) 
{
    return (in_button_PS & in_button_MASK) >> in_button_SHIFT;
}


/*******************************************************************************
* Function Name: in_button_ReadDataReg
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
uint8 in_button_ReadDataReg(void) 
{
    return (in_button_DR & in_button_MASK) >> in_button_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(in_button_INTSTAT) 

    /*******************************************************************************
    * Function Name: in_button_ClearInterrupt
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
    uint8 in_button_ClearInterrupt(void) 
    {
        return (in_button_INTSTAT & in_button_MASK) >> in_button_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
