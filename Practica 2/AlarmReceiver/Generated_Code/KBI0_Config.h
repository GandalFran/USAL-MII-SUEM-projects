/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : KBI0_Config.h
**     Project     : AlarmReceiver
**     Processor   : MKE06Z128VLK4
**     Component   : Init_KBI
**     Version     : Component 01.000, Driver 01.00, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2021-06-09, 19:04, # CodeGen: 14
**     Abstract    :
**          This file implements the KBI (KBI0) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : KBI0
**          Device                                         : KBI0
**          Settings                                       : 
**            Clock gate                                   : <Automatic>
**            Detection mode                               : Edges only
**            Pin sensitivity                              : 
**              Input pin 0                                : Falling edge or low level
**              Input pin 1                                : Falling edge or low level
**              Input pin 2                                : Falling edge or low level
**              Input pin 3                                : Falling edge or low level
**              Input pin 4                                : Falling edge or low level
**              Input pin 5                                : Falling edge or low level
**              Input pin 6                                : Falling edge or low level
**              Input pin 7                                : Falling edge or low level
**              Input pin 8                                : Falling edge or low level
**              Input pin 9                                : Falling edge or low level
**              Input pin 10                               : Falling edge or low level
**              Input pin 11                               : Falling edge or low level
**              Input pin 12                               : Falling edge or low level
**              Input pin 13                               : Falling edge or low level
**              Input pin 14                               : Falling edge or low level
**              Input pin 15                               : Falling edge or low level
**              Input pin 16                               : Falling edge or low level
**              Input pin 17                               : Falling edge or low level
**              Input pin 18                               : Falling edge or low level
**              Input pin 19                               : Falling edge or low level
**              Input pin 20                               : Falling edge or low level
**              Input pin 21                               : Falling edge or low level
**              Input pin 22                               : Falling edge or low level
**              Input pin 23                               : Falling edge or low level
**              Input pin 24                               : Falling edge or low level
**              Input pin 25                               : Falling edge or low level
**              Input pin 26                               : Falling edge or low level
**              Input pin 27                               : Falling edge or low level
**              Input pin 28                               : Falling edge or low level
**              Input pin 29                               : Falling edge or low level
**              Input pin 30                               : Falling edge or low level
**              Input pin 31                               : Falling edge or low level
**            Read source pin register                     : Real time value
**          Pins/Signals                                   : 
**            Input pin 0                                  : Disabled
**            Input pin 1                                  : Disabled
**            Input pin 2                                  : Disabled
**            Input pin 3                                  : Disabled
**            Input pin 4                                  : Disabled
**            Input pin 5                                  : Disabled
**            Input pin 6                                  : Disabled
**            Input pin 7                                  : Disabled
**            Input pin 8                                  : Disabled
**            Input pin 9                                  : Disabled
**            Input pin 10                                 : Disabled
**            Input pin 11                                 : Disabled
**            Input pin 12                                 : Disabled
**            Input pin 13                                 : Disabled
**            Input pin 14                                 : Disabled
**            Input pin 15                                 : Disabled
**            Input pin 16                                 : Disabled
**            Input pin 17                                 : Disabled
**            Input pin 18                                 : Disabled
**            Input pin 19                                 : Disabled
**            Input pin 20                                 : Disabled
**            Input pin 21                                 : Disabled
**            Input pin 22                                 : Disabled
**            Input pin 23                                 : Disabled
**            Input pin 24                                 : Disabled
**            Input pin 25                                 : Disabled
**            Input pin 26                                 : Disabled
**            Input pin 27                                 : Disabled
**            Input pin 28                                 : Disabled
**            Input pin 29                                 : Disabled
**            Input pin 30                                 : Disabled
**            Input pin 31                                 : Disabled
**          Interrupts                                     : 
**            Interrupt                                    : INT_KBI0
**            Interrupt request                            : <Automatic>
**            Interrupt priority                           : <Automatic>
**            ISR name                                     : 
**            KBI interrupt                                : Disabled
**          Initialization                                 : 
**            Reset source pin register                    : Disabled
**            Call Init method                             : yes
**            Utilize after reset values                   : default
**     Contents    :
**         Init - void KBI0_Init(void);
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file KBI0_Config.h                                                  
** @version 01.00
** @brief
**          This file implements the KBI (KBI0) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
*/         
/*!
**  @addtogroup KBI0_Config_module KBI0_Config module documentation
**  @{
*/         

#ifndef KBI0_Config_H_
#define KBI0_Config_H_

/* MODULE KBI0. */

/* KBI0_SC: KBSPEN=0 */
#define KBI0_SC_VALUE_1      0x00U
#define KBI0_SC_MASK_1       0x10U
/* KBI0_ES: KBEDG=0 */
#define KBI0_ES_VALUE        0x00U
/* KBI0_PE: KBIPE=0 */
#define KBI0_PE_VALUE        0x00U
/* KBI0_SC: RSTKBSP=0,KBACK=1,KBMOD=0 */
#define KBI0_SC_VALUE_2      0x04U
#define KBI0_SC_MASK_2       0x25U

#define KBI0_AUTOINIT

/* END KBI0. */
#endif /* #ifndef __KBI0_Config_H_ */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
