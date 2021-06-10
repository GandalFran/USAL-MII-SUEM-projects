/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : Term1.h
**     Project     : AlarmEmiter
**     Processor   : MKE06Z128VLK4
**     Component   : Term
**     Version     : Component 02.061, Driver 03.22, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2021-06-10, 18:37, # CodeGen: 16
**     Abstract    :
**This components generates low-level console IO routines for selected UART.
**     Settings    :
**          Component name                                 : Term1
**          Asynchro serial communication                  : AsynchroForTerminal
**          CPU clock/speed selection                      : 
**            High speed mode                              : This component enabled
**            Low speed mode                               : This component disabled
**            Slow speed mode                              : This component disabled
**     Contents    :
**         CRLF       - void Term1_CRLF(void);
**         SendStr    - void Term1_SendStr(uint8_t *str);
**         SendNum    - void Term1_SendNum(int32_t number);
**         SendChar   - void Term1_SendChar(char_t Val);
**         Cls        - void Term1_Cls(void);
**         MoveTo     - void Term1_MoveTo(uint8_t x, uint8_t y);
**         SetColor   - void Term1_SetColor(uint8_t foreground, uint8_t background);
**         ReadChar   - void Term1_ReadChar(char_t *c);
**         KeyPressed - bool Term1_KeyPressed(void);
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
** @file Term1.h
** @version 03.22
** @brief
**This components generates low-level console IO routines for selected UART.
*/         
/*!
**  @addtogroup Term1_module Term1 module documentation
**  @{
*/         

#ifndef __Term1
#define __Term1

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* MODULE Term1. */

#include "Cpu.h"


/* Color constants */
#define   clBlack   30U                /* Black color */
#define   clRed     31U                /* Red color */
#define   clGreen   32U                /* Green color */
#define   clYellow  33U                /* Yellow color */
#define   clBlue    34U                /* Blue color */
#define   clMagenta 35U                /* Magenta color */
#define   clCyan    36U                /* Cyan color */
#define   clWhite   37U                /* White color */

void Term1_SendChar(char_t Val);
/*
** ===================================================================
**     Method      :  Term1_SendChar (component Term)
**     Description :
**         Send char to terminal.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Val             - Char to send
**     Returns     : Nothing
** ===================================================================
*/

void Term1_ReadChar(char_t *c);
/*
** ===================================================================
**     Method      :  Term1_ReadChar (component Term)
**     Description :
**         Read char from terminal.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * c               - Pointer to a char variable
**     Returns     : Nothing
** ===================================================================
*/

bool Term1_KeyPressed(void);
/*
** ===================================================================
**     Method      :  Term1_KeyPressed (component Term)
**     Description :
**         Test if char was received from the terminal.
**     Parameters  : None
**     Returns     :
**         ---             - Return <true> if user pressed some key
** ===================================================================
*/

void Term1_CRLF(void);
/*
** ===================================================================
**     Method      :  Term1_CRLF (component Term)
**     Description :
**         Send CRLF to terminal.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void Term1_SendStr(void *str);
/*
** ===================================================================
**     Method      :  Term1_SendStr (component Term)
**     Description :
**         Send string to terminal.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * str             - Pointer to a string variable
**     Returns     : Nothing
** ===================================================================
*/

void Term1_SendNum(int32_t number);
/*
** ===================================================================
**     Method      :  Term1_SendNum (component Term)
**     Description :
**         Send number to terminal.
**     Parameters  :
**         NAME            - DESCRIPTION
**         number          - Long number
**     Returns     : Nothing
** ===================================================================
*/

void Term1_Cls(void);
/*
** ===================================================================
**     Method      :  Term1_Cls (component Term)
**     Description :
**         Clear the terminal window.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void Term1_MoveTo(uint8_t x,uint8_t y);
/*
** ===================================================================
**     Method      :  Term1_MoveTo (component Term)
**     Description :
**         Move cursor to position x, y. Range of coordinates can be
**         from 1 to the size, which depends on the used terminal.
**         Position [1,1] represents the upper left corner.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - Column number
**         y               - Row number
**     Returns     : Nothing
** ===================================================================
*/

void Term1_SetColor(uint8_t foreground,uint8_t background);
/*
** ===================================================================
**     Method      :  Term1_SetColor (component Term)
**     Description :
**         Set foreground and background color. The following color
**         constant are defined in the header file:
**         clBlack - Black color
**         clRed - Red color
**         clGreen - Green color
**         clYellow - Yellow color
**         clBlue - Blue color
**         clMagenta - Magenta color
**         clCyan - Cyan color
**         clWhite - White color
**     Parameters  :
**         NAME            - DESCRIPTION
**         foreground      - Foreground color.
**         background      - Background color.
**     Returns     : Nothing
** ===================================================================
*/


/* END Term1. */

#endif /* ifndef __Term1 */
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
