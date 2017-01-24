/*******************************************************************************
* File Name: SW.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SW_H) /* Pins SW_H */
#define CY_PINS_SW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SW_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SW__PORT == 15 && ((SW__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    SW_Write(uint8 value) ;
void    SW_SetDriveMode(uint8 mode) ;
uint8   SW_ReadDataReg(void) ;
uint8   SW_Read(void) ;
uint8   SW_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SW_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define SW_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define SW_DM_RES_UP          PIN_DM_RES_UP
#define SW_DM_RES_DWN         PIN_DM_RES_DWN
#define SW_DM_OD_LO           PIN_DM_OD_LO
#define SW_DM_OD_HI           PIN_DM_OD_HI
#define SW_DM_STRONG          PIN_DM_STRONG
#define SW_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define SW_MASK               SW__MASK
#define SW_SHIFT              SW__SHIFT
#define SW_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SW_PS                     (* (reg8 *) SW__PS)
/* Data Register */
#define SW_DR                     (* (reg8 *) SW__DR)
/* Port Number */
#define SW_PRT_NUM                (* (reg8 *) SW__PRT) 
/* Connect to Analog Globals */                                                  
#define SW_AG                     (* (reg8 *) SW__AG)                       
/* Analog MUX bux enable */
#define SW_AMUX                   (* (reg8 *) SW__AMUX) 
/* Bidirectional Enable */                                                        
#define SW_BIE                    (* (reg8 *) SW__BIE)
/* Bit-mask for Aliased Register Access */
#define SW_BIT_MASK               (* (reg8 *) SW__BIT_MASK)
/* Bypass Enable */
#define SW_BYP                    (* (reg8 *) SW__BYP)
/* Port wide control signals */                                                   
#define SW_CTL                    (* (reg8 *) SW__CTL)
/* Drive Modes */
#define SW_DM0                    (* (reg8 *) SW__DM0) 
#define SW_DM1                    (* (reg8 *) SW__DM1)
#define SW_DM2                    (* (reg8 *) SW__DM2) 
/* Input Buffer Disable Override */
#define SW_INP_DIS                (* (reg8 *) SW__INP_DIS)
/* LCD Common or Segment Drive */
#define SW_LCD_COM_SEG            (* (reg8 *) SW__LCD_COM_SEG)
/* Enable Segment LCD */
#define SW_LCD_EN                 (* (reg8 *) SW__LCD_EN)
/* Slew Rate Control */
#define SW_SLW                    (* (reg8 *) SW__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SW_PRTDSI__CAPS_SEL       (* (reg8 *) SW__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SW_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SW__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SW_PRTDSI__OE_SEL0        (* (reg8 *) SW__PRTDSI__OE_SEL0) 
#define SW_PRTDSI__OE_SEL1        (* (reg8 *) SW__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SW_PRTDSI__OUT_SEL0       (* (reg8 *) SW__PRTDSI__OUT_SEL0) 
#define SW_PRTDSI__OUT_SEL1       (* (reg8 *) SW__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SW_PRTDSI__SYNC_OUT       (* (reg8 *) SW__PRTDSI__SYNC_OUT) 


#if defined(SW__INTSTAT)  /* Interrupt Registers */

    #define SW_INTSTAT                (* (reg8 *) SW__INTSTAT)
    #define SW_SNAP                   (* (reg8 *) SW__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SW_H */


/* [] END OF FILE */
