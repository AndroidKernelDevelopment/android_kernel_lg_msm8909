/***************************************************************************
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 *    File  : lgtp_model_config_misc.c
 *    Author(s)   : D3 BSP Touch Team < d3-bsp-touch@lge.com >
 *    Description :
 *
 ***************************************************************************/
#define LGTP_MODULE "[CONFIG]"

/****************************************************************************
* Include Files
****************************************************************************/
#include <linux/input/unified_driver_4/lgtp_common.h>
#include <linux/input/unified_driver_4/lgtp_model_config_misc.h>
#include <linux/input/unified_driver_4/lgtp_platform_api_power.h>


/****************************************************************************
* Manifest Constants / Defines
****************************************************************************/


/****************************************************************************
 * Macros
 ****************************************************************************/


/****************************************************************************
* Type Definitions
****************************************************************************/


/****************************************************************************
* Variables
****************************************************************************/

    
#if defined(TOUCH_MODEL_M2) || defined(TOUCH_MODEL_PH1)
	extern TouchDeviceControlFunction MIT300_Func;

#elif defined(TOUCH_MODEL_E1)
	extern TouchDeviceControlFunction Sn280h_Func;
	extern TouchDeviceControlFunction Ft6x36_Func;
	extern TouchDeviceControlFunction Lu202x_Func;
#elif defined(TOUCH_MODEL_CLING) 	
	extern TouchDeviceControlFunction Lu202x_Func;
#elif defined(TOUCH_MODEL_ME0) 	
	extern TouchDeviceControlFunction Ft3x07_Func;

#else
	#error "Model should be defined"
#endif


/****************************************************************************
* Extern Function Prototypes
****************************************************************************/


/****************************************************************************
* Local Function Prototypes
****************************************************************************/


/****************************************************************************
* Local Functions
****************************************************************************/

/****************************************************************************
* Global Functions
****************************************************************************/
/* this function is for platform api so do not use it in other module */
TouchDeviceControlFunction * TouchGetDeviceControlFunction(int index)
{
	TouchDeviceControlFunction *pControlFunction = NULL;
	
	#if defined(TOUCH_MODEL_M2) || defined(TOUCH_MODEL_PH1)
	if (index == FIRST_MODULE)
		pControlFunction = &MIT300_Func;

	#elif defined (TOUCH_MODEL_E1)
	if (index == FIRST_MODULE) {
		pControlFunction = &Sn280h_Func;
	} else if (index == SECOND_MODULE) {
		pControlFunction = &Ft6x36_Func;
	} else {
		pControlFunction = &Lu202x_Func;
	}
	#elif defined (TOUCH_MODEL_CLING)
	if (index == FIRST_MODULE) {
		pControlFunction = &Lu202x_Func;
	}
	#elif defined (TOUCH_MODEL_ME0)
	if (index == FIRST_MODULE) {
		pControlFunction = &Ft3x07_Func;
	}
	#else
	#error "Model should be defined"
	#endif

	return pControlFunction;
}

void TouchGetModelConfig(TouchDriverData *pDriverData)
{
	TouchModelConfig *pConfig = &pDriverData->mConfig;
	
	#if defined(TOUCH_MODEL_C70) || defined(TOUCH_MODEL_Y70) || defined(TOUCH_MODEL_LION_3G) || defined ( TOUCH_MODEL_M2) \
	|| defined(TOUCH_MODEL_PH1)

	pConfig->button_support = 0;
	pConfig->number_of_button = 0;
	pConfig->button_name[0] = 0;
	pConfig->button_name[1] = 0;
	pConfig->button_name[2] = 0;
	pConfig->button_name[3] = 0;

	pConfig->max_x = 720;
	pConfig->max_y = 1280;
	pConfig->max_pressure = 0xff;
	pConfig->max_width = 15;
	pConfig->max_orientation = 1;
	pConfig->max_id = 10;

	pConfig->protocol_type = MT_PROTOCOL_B;
    
	#elif defined(TOUCH_MODEL_E1)

	pConfig->button_support = 0;
	pConfig->number_of_button = 0;
	pConfig->button_name[0] = 0;
	pConfig->button_name[1] = 0;
	pConfig->button_name[2] = 0;
	pConfig->button_name[3] = 0;

	pConfig->max_x = 480;
	pConfig->max_y = 854;
	pConfig->max_pressure = 0xff;
	pConfig->max_width = 15;
	pConfig->max_orientation = 1;
	pConfig->max_id = 2;

	pConfig->protocol_type = MT_PROTOCOL_B;
	#elif defined(TOUCH_MODEL_CLING)

	pConfig->button_support = 0;
	pConfig->number_of_button = 0;
	pConfig->button_name[0] = 0;
	pConfig->button_name[1] = 0;
	pConfig->button_name[2] = 0;
	pConfig->button_name[3] = 0;

	pConfig->max_x = 320;
	pConfig->max_y = 240;
	pConfig->max_pressure = 0xff;
	pConfig->max_width = 15;
	pConfig->max_orientation = 1;
	pConfig->max_id = 2;

	pConfig->protocol_type = MT_PROTOCOL_B;

	#elif defined(TOUCH_MODEL_ME0)
	pConfig->button_support = 0;
	pConfig->number_of_button = 0;
	pConfig->button_name[0] = 0;
	pConfig->button_name[1] = 0;
	pConfig->button_name[2] = 0;
	pConfig->button_name[3] = 0;

	pConfig->max_x = 480;
	pConfig->max_y = 854;
	pConfig->max_pressure = 0xff;
	pConfig->max_width = 15;
	pConfig->max_orientation = 1;
	pConfig->max_id = 2;

	pConfig->protocol_type = MT_PROTOCOL_B;
	#else
	#error "Model should be defined"
	#endif

	TOUCH_LOG("======== Model Configuration ( Begin ) ========\n");
	TOUCH_LOG("button_support=%d\n", pConfig->button_support);
	TOUCH_LOG("number_of_button=%d\n", pConfig->number_of_button);
	TOUCH_LOG("button_name[0]=%d\n", pConfig->button_name[0]);
	TOUCH_LOG("button_name[1]=%d\n", pConfig->button_name[1]);
	TOUCH_LOG("button_name[2]=%d\n", pConfig->button_name[2]);
	TOUCH_LOG("button_name[3]=%d\n", pConfig->button_name[3]);
	TOUCH_LOG("max_x=%d\n", pConfig->max_x);
	TOUCH_LOG("max_y=%d\n", pConfig->max_y);
	TOUCH_LOG("max_pressure=%d\n", pConfig->max_pressure);
	TOUCH_LOG("max_width=%d\n", pConfig->max_width);
	TOUCH_LOG("max_orientation=%d\n", pConfig->max_orientation);
	TOUCH_LOG("max_id=%d\n", pConfig->max_id);
	TOUCH_LOG("protocol_type=%s", (pConfig->protocol_type == MT_PROTOCOL_A) ?\
			 "MT_PROTOCOL_A\n" : "MT_PROTOCOL_B\n");
	TOUCH_LOG("======== Model Configuration ( End ) ========\n");

	return;

}

void TouchVddPowerModel(int isOn)
{
	#if defined(TOUCH_MODEL_E1)
		TouchPowerPMIC(isOn,"vdd_dd",3000000, 3000000);
	#elif defined(TOUCH_MODEL_CLING)
		TouchPowerPMIC(isOn,"vdd_dd",3000000, 3000000);
	#elif defined(TOUCH_MODEL_ME0)
		TouchPowerPMIC(isOn,"vdd_dd",3000000, 3000000);
	#elif defined(TOUCH_MODEL_Y50)
		DSI_change_mode(DSI_INCELL_GPIO_TIMER_MODE);
		TouchPowerPMIC(isOn,MT6323_POWER_LDO_VGP2, VOL_3000);
	#elif defined(TOUCH_MODEL_C50)
		TouchSetGpioDirection(TOUCH_GPIO_POWER, 1);
		TouchPowerSetGpio(TOUCH_GPIO_POWER, isOn);
	#elif defined(TOUCH_MODEL_LION_3G) || defined ( TOUCH_MODEL_M2) || defined(TOUCH_MODEL_PH1)
        /* there is no power control */
	#else
		#error "Model should be defined"
	#endif
}

void TouchVioPowerModel(int isOn)
{
	#if defined(TOUCH_MODEL_E1)
		TouchPowerPMIC(isOn,"vdd_ana",1800000, 1800000);
	#elif defined(TOUCH_MODEL_CLING)
		TouchPowerPMIC(isOn,"vdd_ana",1800000, 1800000);
    #elif defined(TOUCH_MODEL_ME0)
		TouchPowerPMIC(isOn,"vdd_ana",1800000, 1800000);
	#elif defined(TOUCH_MODEL_Y50)
		TouchPowerPMIC(isOn,MT6323_POWER_LDO_VGP1, VOL_1800);
	#elif defined(TOUCH_MODEL_LION_3G) || defined ( TOUCH_MODEL_M2) || defined(TOUCH_MODEL_PH1)
		/* there is no power control */
	#else
		#error "Model should be defined"
	#endif
}


/* End Of File */

