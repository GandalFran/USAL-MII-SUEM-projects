/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : PpgLdd1.c
**     Project     : laberinto
**     Processor   : MKE06Z128VLK4
**     Component   : PPG_LDD
**     Version     : Component 01.015, Driver 01.03, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2021-06-08, 16:12, # CodeGen: 37
**     Abstract    :
**          This component implements a programmable pulse generator that
**          generates signal with variable duty and variable cycle (period).
**     Settings    :
**          Component name                                 : PpgLdd1
**          Module name                                    : FTM2
**          Counter                                        : FTM2_CNT
**          Period device                                  : FTM2_MOD
**          Duty device                                    : FTM2_C0V
**          Output pin                                     : PTH0/KBI1_P24/FTM2_CH0
**          Interrupt service/event                        : Disabled
**          Period                                         : 500 Hz
**          Starting pulse width                           : 1 ms
**          Initial polarity                               : low
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnEnd                                      : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init            - LDD_TDeviceData* PpgLdd1_Init(LDD_TUserData *UserDataPtr);
**         Enable          - LDD_TError PpgLdd1_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable         - LDD_TError PpgLdd1_Disable(LDD_TDeviceData *DeviceDataPtr);
**         SetPeriodUS     - LDD_TError PpgLdd1_SetPeriodUS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);
**         SetPeriodMS     - LDD_TError PpgLdd1_SetPeriodMS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);
**         SetPeriodSec    - LDD_TError PpgLdd1_SetPeriodSec(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);
**         SetPeriodReal   - LDD_TError PpgLdd1_SetPeriodReal(LDD_TDeviceData *DeviceDataPtr,...
**         SetFrequencyHz  - LDD_TError PpgLdd1_SetFrequencyHz(LDD_TDeviceData *DeviceDataPtr, uint16_t...
**         SetFrequencykHz - LDD_TError PpgLdd1_SetFrequencykHz(LDD_TDeviceData *DeviceDataPtr, uint16_t...
**         SetFrequencyMHz - LDD_TError PpgLdd1_SetFrequencyMHz(LDD_TDeviceData *DeviceDataPtr, uint16_t...
**         SetRatio16      - LDD_TError PpgLdd1_SetRatio16(LDD_TDeviceData *DeviceDataPtr, uint16_t Ratio);
**         SetDutyUS       - LDD_TError PpgLdd1_SetDutyUS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);
**         SetDutyMS       - LDD_TError PpgLdd1_SetDutyMS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time);
**         ClearValue      - LDD_TError PpgLdd1_ClearValue(LDD_TDeviceData *DeviceDataPtr);
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
** @file PpgLdd1.c
** @version 01.03
** @brief
**          This component implements a programmable pulse generator that
**          generates signal with variable duty and variable cycle (period).
*/         
/*!
**  @addtogroup PpgLdd1_module PpgLdd1 module documentation
**  @{
*/         

/* MODULE PpgLdd1. */

#include "PpgLdd1.h"
/* {Default RTOS Adapter} No RTOS includes */

#ifdef __cplusplus
extern "C" {
#endif 

typedef struct {
  uint16_t CmpDuty0;                   /* Duty register value for Clock configuration 0 */
  uint16_t CmpPeriod0;                 /* Period register value for Clock configuration 0 */
  uint16_t RatioStore;                 /* Ratio of L-level to H-level */
  uint32_t Source;                     /* Current source clock */
  LDD_TUserData *UserDataPtr;          /* RTOS device data structure */
} PpgLdd1_TDeviceData;

typedef PpgLdd1_TDeviceData *PpgLdd1_TDeviceDataPtr; /* Pointer to the device data structure. */

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static PpgLdd1_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;

#define AVAILABLE_PIN_MASK (LDD_TPinMask)(PpgLdd1_OUT_PIN)

/* Internal method prototypes */
static void SetRatio(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  PpgLdd1_Init (component PPG_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the
**         property ["Enable in init. code"] is set to "yes" value then
**         the device is also enabled (see the description of the
**         [Enable] method). In this case the [Enable] method is not
**         necessary and needn't to be generated. This method can be
**         called only once. Before the second call of Init the [Deinit]
**         must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* PpgLdd1_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate device structure */
  PpgLdd1_TDeviceData *DeviceDataPrv;
  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
  /* FTM2_MODE: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,FAULTIE=0,FAULTM=0,CAPTEST=0,PWMSYNC=0,WPDIS=1,INIT=0,FTMEN=0 */
  FTM2_MODE = (FTM_MODE_FAULTM(0x00) | FTM_MODE_WPDIS_MASK); /* Set up mode register */
  /* FTM2_SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,TOF=0,TOIE=0,CPWMS=0,CLKS=0,PS=0 */
  FTM2_SC = (FTM_SC_CLKS(0x00) | FTM_SC_PS(0x00)); /* Clear status and control register */
  /* FTM2_CNTIN: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,INIT=0 */
  FTM2_CNTIN = FTM_CNTIN_INIT(0x00);   /* Clear counter initial register */
  /* FTM2_CNT: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,COUNT=0 */
  FTM2_CNT = FTM_CNT_COUNT(0x00);      /* Reset counter register */
  /* FTM2_C0SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,??=0 */
  FTM2_C0SC = 0x00U;                   /* Clear channel status and control register */
  /* FTM2_C1SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,??=0 */
  FTM2_C1SC = 0x00U;                   /* Clear channel status and control register */
  /* FTM2_C2SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,??=0 */
  FTM2_C2SC = 0x00U;                   /* Clear channel status and control register */
  /* FTM2_C3SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,??=0 */
  FTM2_C3SC = 0x00U;                   /* Clear channel status and control register */
  /* FTM2_C4SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,??=0 */
  FTM2_C4SC = 0x00U;                   /* Clear channel status and control register */
  /* FTM2_C5SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,??=0 */
  FTM2_C5SC = 0x00U;                   /* Clear channel status and control register */
  /* FTM2_MOD: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,MOD=0x3D */
  FTM2_MOD = FTM_MOD_MOD(0x3D);        /* Set up modulo register */
  /* FTM2_C0SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=1,MSA=0,ELSB=1,ELSA=1,??=0,??=0 */
  FTM2_C0SC = (FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK | FTM_CnSC_ELSA_MASK); /* Set up channel status and control register */
  /* FTM2_C0V: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,VAL=0x1F */
  FTM2_C0V = FTM_CnV_VAL(0x1F);        /* Set up channel value register */
  DeviceDataPrv->RatioStore = 0x7DF8U; /* Ratio after initialization */
  DeviceDataPrv->CmpDuty0 = 0x1FU;     /* Duty - duty register value for Clock configuration 0 */
  DeviceDataPrv->CmpPeriod0 = 0x3DU;   /* Period - period register value for Clock configuration 0 */
  DeviceDataPrv->Source = FTM_PDD_FIXED; /* Store clock source */
  /* FTM2_SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,TOF=0,TOIE=0,CPWMS=0,CLKS=2,PS=0 */
  FTM2_SC = (FTM_SC_CLKS(0x02) | FTM_SC_PS(0x00)); /* Set up status and control register */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_PpgLdd1_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv); /* Return pointer to the device data structure */
}

/*
** ===================================================================
**     Method      :  PpgLdd1_Enable (component PPG_LDD)
*/
/*!
**     @brief
**         Enables the component - it starts the signal generation.
**         Events may be generated (see SetEventMask).
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError PpgLdd1_Enable(LDD_TDeviceData *DeviceDataPtr)
{
  PpgLdd1_TDeviceData *DeviceDataPrv = (PpgLdd1_TDeviceData *)DeviceDataPtr;

  FTM_PDD_SelectPrescalerSource(FTM2_BASE_PTR, DeviceDataPrv->Source); /* Enable the device */
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  PpgLdd1_Disable (component PPG_LDD)
*/
/*!
**     @brief
**         Disables the component - it stops signal generation and
**         events calling.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError PpgLdd1_Disable(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  FTM_PDD_SelectPrescalerSource(FTM2_BASE_PTR, FTM_PDD_DISABLED);
  FTM_PDD_InitializeCounter(FTM2_BASE_PTR); /* Reset counter */
  FTM_PDD_InitializeOutputs(FTM2_BASE_PTR); /* Force output signal level */
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  PpgLdd1_SetPeriodUS (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets the new period of the output signal. The
**         period is expressed in [microseconds] as a 16-bit unsigned
**         integer number. This method is available only if ["Runtime
**         setting type"] property is set to "interval" .
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Time            - Period to set [in microseconds]
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_MATH - Overflow during evaluation
**                           ERR_PARAM_RANGE - Parameter Time out of
**                           range
*/
/* ===================================================================*/
LDD_TError PpgLdd1_SetPeriodUS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time)
{
  PpgLdd1_TDeviceData *DeviceDataPrv = (PpgLdd1_TDeviceData *)DeviceDataPtr;
  LDD_PPG_Tfloat rtval;                /* Result of multiplication */

  /* Time test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if (Time < PpgLdd1_SPUS_MIN) {       /* Is the given value out of range? */
    return ERR_PARAM_RANGE;            /* If yes then error */
  }
  rtval = Time * 0.03125F;             /* Multiply given value and Clock configuration 0 coefficient */
  if (rtval > 0xFFFFUL) {              /* Is the result greater than 65535 ? */
    DeviceDataPrv->CmpPeriod0 = 0xFFFFU; /* If yes then use maximal possible value */
  }
  else {
    DeviceDataPrv->CmpPeriod0 = (uint16_t)rtval;
  }
  SetRatio(DeviceDataPtr);             /* Calculate and set up new appropriate values of the duty and period registers */
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  PpgLdd1_SetPeriodMS (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets the new period of the output signal. The
**         period is expressed in [milliseconds] as a 16-bit unsigned
**         integer number. This method is available only if ["Runtime
**         setting type"] property is set to "interval" .
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Time            - Period to set [in milliseconds]
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_MATH - Overflow during evaluation
**                           ERR_PARAM_RANGE - Parameter Time out of
**                           range
*/
/* ===================================================================*/
LDD_TError PpgLdd1_SetPeriodMS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time)
{
  PpgLdd1_TDeviceData *DeviceDataPrv = (PpgLdd1_TDeviceData *)DeviceDataPtr;
  LDD_PPG_Tfloat rtval;                /* Result of multiplication */

  /* Time test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if ((Time > PpgLdd1_SPMS_MAX) || (Time < PpgLdd1_SPMS_MIN)) { /* Is the given value out of range? */
    return ERR_PARAM_RANGE;            /* If yes then error */
  }
  rtval = Time * 31.25F;               /* Multiply given value and Clock configuration 0 coefficient */
  if (rtval > 0xFFFFUL) {              /* Is the result greater than 65535 ? */
    DeviceDataPrv->CmpPeriod0 = 0xFFFFU; /* If yes then use maximal possible value */
  }
  else {
    DeviceDataPrv->CmpPeriod0 = (uint16_t)rtval;
  }
  SetRatio(DeviceDataPtr);             /* Calculate and set up new appropriate values of the duty and period registers */
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  PpgLdd1_SetPeriodSec (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets the new period of the output signal. The
**         period is expressed in [seconds] as a 16-bit unsigned
**         integer number. This method is available only if ["Runtime
**         setting type"] property is set to "interval" .
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Time            - Period to set [in seconds]
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_MATH - Overflow during evaluation
**                           ERR_PARAM_RANGE - Parameter Time out of
**                           range
*/
/* ===================================================================*/
LDD_TError PpgLdd1_SetPeriodSec(LDD_TDeviceData *DeviceDataPtr, uint16_t Time)
{
  PpgLdd1_TDeviceData *DeviceDataPrv = (PpgLdd1_TDeviceData *)DeviceDataPtr;
  LDD_PPG_Tfloat rtval;                /* Result of multiplication */

  /* Time test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if ((Time > PpgLdd1_SPSEC_MAX) || (Time < PpgLdd1_SPSEC_MIN)) { /* Is the given value out of range? */
    return ERR_PARAM_RANGE;            /* If yes then error */
  }
  rtval = Time * 31250.0F;             /* Multiply given value and Clock configuration 0 coefficient */
  if (rtval > 0xFFFFUL) {              /* Is the result greater than 65535 ? */
    DeviceDataPrv->CmpPeriod0 = 0xFFFFU; /* If yes then use maximal possible value */
  }
  else {
    DeviceDataPrv->CmpPeriod0 = (uint16_t)rtval;
  }
  SetRatio(DeviceDataPtr);             /* Calculate and set up new appropriate values of the duty and period registers */
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  PpgLdd1_SetPeriodReal (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets the new period of the output signal. The
**         period is expressed in [seconds] as a real number. To use
**         this method the compiler have to support floating point
**         operations. This method is available only if ["Runtime
**         setting type"] property is set to "interval" .
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Time            - Period to set [in seconds]
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_PARAM_RANGE - Parameter out of range
*/
/* ===================================================================*/
LDD_TError PpgLdd1_SetPeriodReal(LDD_TDeviceData *DeviceDataPtr, LDD_PPG_Tfloat Time)
{
  PpgLdd1_TDeviceData *DeviceDataPrv = (PpgLdd1_TDeviceData *)DeviceDataPtr;
  LDD_PPG_Tfloat rtval;                /* Result of multiplication */

  /* Time test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if ((Time > PpgLdd1_SPREAL_MAX) || (Time < PpgLdd1_SPREAL_MIN)) { /* Is the given value out of range? */
    return ERR_PARAM_RANGE;            /* If yes then error */
  }
  rtval = Time * 31250.0F;             /* Multiply given value and Clock configuration 0 coefficient */
  if (rtval > 0xFFFFUL) {              /* Is the result greater than 65535 ? */
    DeviceDataPrv->CmpPeriod0 = 0xFFFFU; /* If yes then use maximal possible value */
  }
  else {
    DeviceDataPrv->CmpPeriod0 = (uint16_t)rtval;
  }
  SetRatio(DeviceDataPtr);             /* Calculate and set up new appropriate values of the duty and period registers */
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  PpgLdd1_SetFrequencyHz (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets the new frequency of the output signal. The
**         frequency is expressed in [Hz] as a 16-bit unsigned integer
**         number. This method is available only if ["Runtime setting
**         type"] property is set to "interval" .
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Frequency       - Frequency to set [in Hz]
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_MATH - Overflow during evaluation
**                           ERR_PARAM_RANGE - Parameter Frequency is
**                           out of range
*/
/* ===================================================================*/
LDD_TError PpgLdd1_SetFrequencyHz(LDD_TDeviceData *DeviceDataPtr, uint16_t Frequency)
{
  PpgLdd1_TDeviceData *DeviceDataPrv = (PpgLdd1_TDeviceData *)DeviceDataPtr;
  LDD_PPG_Tfloat rtval;                /* Result of multiplication */

  /* Frequency test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if ((Frequency > PpgLdd1_SFREQ_HZ_MAX) || (Frequency < PpgLdd1_SFREQ_HZ_MIN)) { /* Is the given value out of range? */
    return ERR_PARAM_RANGE;            /* If yes then error */
  }
  rtval = 31250.0F / Frequency;        /* Divide Clock configuration 0 coefficient by the given value */
  if (rtval > 0xFFFFUL) {              /* Is the result greater than 65535 ? */
    DeviceDataPrv->CmpPeriod0 = 0xFFFFU; /* If yes then use maximal possible value */
  }
  else {
    DeviceDataPrv->CmpPeriod0 = (uint16_t)rtval;
  }
  SetRatio(DeviceDataPtr);             /* Calculate and set up new appropriate values of the duty and period registers */
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  PpgLdd1_SetFrequencykHz (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets the new frequency of the output signal. The
**         frequency is expressed in [kHz] as a 16-bit unsigned integer
**         number. This method is available only if ["Runtime setting
**         type"] property is set to "interval" .
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Frequency       - Frequency to set [in kHz]
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_MATH - Overflow during evaluation
**                           ERR_PARAM_RANGE - Parameter Frequency is
**                           out of range
*/
/* ===================================================================*/
LDD_TError PpgLdd1_SetFrequencykHz(LDD_TDeviceData *DeviceDataPtr, uint16_t Frequency)
{
  PpgLdd1_TDeviceData *DeviceDataPrv = (PpgLdd1_TDeviceData *)DeviceDataPtr;
  LDD_PPG_Tfloat rtval;                /* Result of multiplication */

  /* Frequency test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if ((Frequency > PpgLdd1_SFREQ_KHZ_MAX) || (Frequency < PpgLdd1_SFREQ_KHZ_MIN)) { /* Is the given value out of range? */
    return ERR_PARAM_RANGE;            /* If yes then error */
  }
  rtval = 31.25F / Frequency;          /* Divide Clock configuration 0 coefficient by the given value */
  if (rtval > 0xFFFFUL) {              /* Is the result greater than 65535 ? */
    DeviceDataPrv->CmpPeriod0 = 0xFFFFU; /* If yes then use maximal possible value */
  }
  else {
    DeviceDataPrv->CmpPeriod0 = (uint16_t)rtval;
  }
  SetRatio(DeviceDataPtr);             /* Calculate and set up new appropriate values of the duty and period registers */
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  PpgLdd1_SetFrequencyMHz (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets the new frequency of the output signal. The
**         frequency is expressed in [MHz] as a 16-bit unsigned integer
**         number. This method is available only if ["Runtime setting
**         type"] property is set to "interval" .
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Frequency       - Frequency to set [in MHz]
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_MATH - Overflow during evaluation
**                           ERR_PARAM_RANGE - Parameter Frequency is
**                           out of range
*/
/* ===================================================================*/
LDD_TError PpgLdd1_SetFrequencyMHz(LDD_TDeviceData *DeviceDataPtr, uint16_t Frequency)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  (void)Frequency;                     /* Parameter is not used, suppress unused argument warning */
  /* Interval for this method is too narrow.
     The method 'SetFrequencyMHz' will return only an error code. */
  return ERR_MATH;                     /* Calculation error */
}

/*
** ===================================================================
**     Method      :  PpgLdd1_SetRatio16 (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. 0 - FFFF value is
**         proportional to ratio 0 - 100%. The method is available
**         only if it is not selected list of predefined values in
**         [Starting pulse width] property. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Ratio           - Ratio to set. 0 - 65535 value is
**                           proportional to ratio 0 - 100%
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError PpgLdd1_SetRatio16(LDD_TDeviceData *DeviceDataPtr, uint16_t Ratio)
{
  PpgLdd1_TDeviceData *DeviceDataPrv = (PpgLdd1_TDeviceData *)DeviceDataPtr;

  DeviceDataPrv->RatioStore = Ratio;   /* Store new value of the ratio */
  SetRatio(DeviceDataPtr);             /* Calculate and set up new appropriate values of the duty and period registers */
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  PpgLdd1_SetDutyUS (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets the new duty value of the output signal.
**         The duty is expressed in microseconds as a 16-bit unsigned
**         integer number. The method is available only if it is not
**         selected list of predefined values in [Starting pulse width]
**         property.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Time            - Duty to set [in microseconds]
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
**                           ERR_MATH - Overflow during evaluation
**                           ERR_PARAM_RANGE - Parameter out of range
*/
/* ===================================================================*/
LDD_TError PpgLdd1_SetDutyUS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time)
{
  PpgLdd1_TDeviceData *DeviceDataPrv = (PpgLdd1_TDeviceData *)DeviceDataPtr;
  LDD_PPG_Tfloat rtval;                /* Result of multiplication */

  rtval = (Time * 2048.0F) / (LDD_PPG_Tfloat)DeviceDataPrv->CmpPeriod0; /* Calculate new ratio for Clock configuration 0 */
  /* Time test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if (rtval >= 0x00010000UL) {         /* Is the result greater or equal than 65536 ? */
    return ERR_PARAM_RANGE;            /* If yes then error */
  }
  DeviceDataPrv->RatioStore = (uint16_t)rtval; /* Store new value of the ratio */
  SetRatio(DeviceDataPtr);             /* Calculate and set up new appropriate values of the duty and period registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  PpgLdd1_SetDutyMS (component PPG_LDD)
*/
/*!
**     @brief
**         This method sets the new duty value of the output signal.
**         The duty is expressed in milliseconds as a 16-bit unsigned
**         integer number. The method is available only if it is not
**         selected list of predefined values in [Starting pulse width]
**         property.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Time            - Duty to set [in milliseconds]
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
**                           ERR_MATH - Overflow during evaluation
**                           ERR_PARAM_RANGE - Parameter out of range
*/
/* ===================================================================*/
LDD_TError PpgLdd1_SetDutyMS(LDD_TDeviceData *DeviceDataPtr, uint16_t Time)
{
  PpgLdd1_TDeviceData *DeviceDataPrv = (PpgLdd1_TDeviceData *)DeviceDataPtr;
  LDD_PPG_Tfloat rtval;                /* Result of multiplication */

  rtval = (Time * 2048000.0F) / (LDD_PPG_Tfloat)DeviceDataPrv->CmpPeriod0; /* Calculate new ratio for Clock configuration 0 */
  /* Time test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if (rtval >= 0x00010000UL) {         /* Is the result greater or equal than 65536 ? */
    return ERR_PARAM_RANGE;            /* If yes then error */
  }
  DeviceDataPrv->RatioStore = (uint16_t)rtval; /* Store new value of the ratio */
  SetRatio(DeviceDataPtr);             /* Calculate and set up new appropriate values of the duty and period registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  PpgLdd1_ClearValue (component PPG_LDD)
*/
/*!
**     @brief
**         This method clears (set to "0" = "Low") timer flip-flop
**         output signal level. It allows to the user to directly set
**         the output pin value (=flip-flop state), and can set the
**         signal polarity. This method only works when the timer is
**         disabled ([Disable] otherwise it returns the error code.
**         [ClearValue] and [SetValue] methods are used for setting the
**         initial state.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
**                           ERR_ENABLED - Component is enabled.
**                           Component must be disabled (see "Disable
**                           method")
*/
/* ===================================================================*/
LDD_TError PpgLdd1_ClearValue(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* Component enable test - this test can be disabled by setting the "Ignore enable test"
     property to the "yes" value in the "Configuration inspector" */
  if (FTM_PDD_GetEnableDeviceStatus(FTM2_BASE_PTR)) { /* Is the device enabled? */
    return ERR_ENABLED;                /* If yes then error */
  }
  FTM_PDD_SelectChannelMode(FTM2_BASE_PTR, FTM_PDD_CHANNEL_0, FTM_PDD_OUTPUT_CLEAR);
  FTM_PDD_SelectChannelEdgeLevel(FTM2_BASE_PTR, FTM_PDD_CHANNEL_0, FTM_PDD_EDGE_BOTH);
  FTM_PDD_WriteInitialOutputReg(FTM2_BASE_PTR, (FTM_PDD_ReadInitialOutputReg(FTM2_BASE_PTR) & (uint32_t)(~1UL))); /* Set output signal level to low */
  FTM_PDD_InitializeOutputs(FTM2_BASE_PTR); /* Force output signal level */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  SetRatio (component PPG_LDD)
**
**     Description :
**         Calculates and sets new duty ratio. The method is called 
**         automatically as a part of several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void SetRatio(LDD_TDeviceData *DeviceDataPtr)
{
  PpgLdd1_TDeviceData *DeviceDataPrv = (PpgLdd1_TDeviceData*)DeviceDataPtr;

  DeviceDataPrv->CmpDuty0 = (uint16_t)(((((uint32_t)DeviceDataPrv->CmpPeriod0 + 1U) * DeviceDataPrv->RatioStore) + 0x8000U) >> 0x10U); /* Calculate new value of duty register according to the given ratio for Clock configuration 'for_index_0' */
  FTM_PDD_WriteChannelValueReg(FTM2_BASE_PTR, FTM_PDD_CHANNEL_0, DeviceDataPrv->CmpDuty0); /* Set the duty register in Clock configuration 'for_index_0' */
  FTM_PDD_WriteModuloReg(FTM2_BASE_PTR, DeviceDataPrv->CmpPeriod0); /* Set the period register in Clock configuration 'for_index_0' */
}

/* END PpgLdd1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

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
