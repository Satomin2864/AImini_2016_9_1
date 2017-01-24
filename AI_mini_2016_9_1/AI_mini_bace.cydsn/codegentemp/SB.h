/*******************************************************************************
* File Name: SB.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SB_H) /* Pins SB_H */
#define CY_PINS_SB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SB_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SB__PORT == 15 && ((SB__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SB_Write(uint8 value);
void    SB_SetDriveMode(uint8 mode);
uint8   SB_ReadDataReg(void);
uint8   SB_Read(void);
void    SB_SetInterruptMode(uint16 position, uint16 mode);
uint8   SB_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SB_SetDriveMode() function.
     *  @{
     */
        #define SB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SB_DM_RES_UP          PIN_DM_RES_UP
        #define SB_DM_RES_DWN         PIN_DM_RES_DWN
        #define SB_DM_OD_LO           PIN_DM_OD_LO
        #define SB_DM_OD_HI           PIN_DM_OD_HI
        #define SB_DM_STRONG          PIN_DM_STRONG
        #define SB_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SB_MASK               SB__MASK
#define SB_SHIFT              SB__SHIFT
#define SB_WIDTH              1u

/* Interrupt constants */
#if defined(SB__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SB_SetInterruptMode() function.
     *  @{
     */
        #define SB_INTR_NONE      (uint16)(0x0000u)
        #define SB_INTR_RISING    (uint16)(0x0001u)
        #define SB_INTR_FALLING   (uint16)(0x0002u)
        #define SB_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SB_INTR_MASK      (0x01u) 
#endif /* (SB__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SB_PS                     (* (reg8 *) SB__PS)
/* Data Register */
#define SB_DR                     (* (reg8 *) SB__DR)
/* Port Number */
#define SB_PRT_NUM                (* (reg8 *) SB__PRT) 
/* Connect to Analog Globals */                                                  
#define SB_AG                     (* (reg8 *) SB__AG)                       
/* Analog MUX bux enable */
#define SB_AMUX                   (* (reg8 *) SB__AMUX) 
/* Bidirectional Enable */                                                        
#define SB_BIE                    (* (reg8 *) SB__BIE)
/* Bit-mask for Aliased Register Access */
#define SB_BIT_MASK               (* (reg8 *) SB__BIT_MASK)
/* Bypass Enable */
#define SB_BYP                    (* (reg8 *) SB__BYP)
/* Port wide control signals */                                                   
#define SB_CTL                    (* (reg8 *) SB__CTL)
/* Drive Modes */
#define SB_DM0                    (* (reg8 *) SB__DM0) 
#define SB_DM1                    (* (reg8 *) SB__DM1)
#define SB_DM2                    (* (reg8 *) SB__DM2) 
/* Input Buffer Disable Override */
#define SB_INP_DIS                (* (reg8 *) SB__INP_DIS)
/* LCD Common or Segment Drive */
#define SB_LCD_COM_SEG            (* (reg8 *) SB__LCD_COM_SEG)
/* Enable Segment LCD */
#define SB_LCD_EN                 (* (reg8 *) SB__LCD_EN)
/* Slew Rate Control */
#define SB_SLW                    (* (reg8 *) SB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SB_PRTDSI__CAPS_SEL       (* (reg8 *) SB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SB_PRTDSI__OE_SEL0        (* (reg8 *) SB__PRTDSI__OE_SEL0) 
#define SB_PRTDSI__OE_SEL1        (* (reg8 *) SB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SB_PRTDSI__OUT_SEL0       (* (reg8 *) SB__PRTDSI__OUT_SEL0) 
#define SB_PRTDSI__OUT_SEL1       (* (reg8 *) SB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SB_PRTDSI__SYNC_OUT       (* (reg8 *) SB__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SB__SIO_CFG)
    #define SB_SIO_HYST_EN        (* (reg8 *) SB__SIO_HYST_EN)
    #define SB_SIO_REG_HIFREQ     (* (reg8 *) SB__SIO_REG_HIFREQ)
    #define SB_SIO_CFG            (* (reg8 *) SB__SIO_CFG)
    #define SB_SIO_DIFF           (* (reg8 *) SB__SIO_DIFF)
#endif /* (SB__SIO_CFG) */

/* Interrupt Registers */
#if defined(SB__INTSTAT)
    #define SB_INTSTAT            (* (reg8 *) SB__INTSTAT)
    #define SB_SNAP               (* (reg8 *) SB__SNAP)
    
	#define SB_0_INTTYPE_REG 		(* (reg8 *) SB__0__INTTYPE)
#endif /* (SB__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SB_H */


/* [] END OF FILE */
