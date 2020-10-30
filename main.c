/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * This is a bare minimum user application template.
 *
 * For documentation of the board, go \ref group_common_boards "here" for a link
 * to the board-specific documentation.
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to board_init()
 * -# Basic usage of on-board LED and button
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <asf.h>

void adc_setup(void)
{
	adc_init(ADC, sysclk_get_main_hz(), sysclk_get_main_hz()/2, ADC_STARTUP_TIME_5);
	adc_configure_timing(ADC, 0, ADC_SETTLING_TIME_0, 0);
	adc_set_resolution(ADC, ADC_MR_LOWRES_BITS_12);
	adc_enable_channel(ADC, ADC_TEMPERATURE_SENSOR);
	adc_configure_trigger(ADC, ADC_TRIG_SW, 1);
	adc_enable_interrupt(ADC, ADC_IER_EOC15);
	NVIC_EnableIRQ(ADC_IRQn);
	pmc_enable_periph_clk(ID_ADC);
	adc_enable_ts(ADC);
}  
/*
void adc_register_setup(void)
{
	ADC->ADC_CR = 0x01; 
	ADC->ADC_MR = 0x2005080; 
	ADC->ADC_CHER = 0x8000; 
	ADC->ADC_IER = 0x8000; 
	NVIC_EnableIRQ(ADC_IRQn);
	pmc_enable_periph_clk(ID_ADC);
	ADC->ADC_ACR = 0x10;
}
*/

void ADC_Handler()
{
	uint32_t result = adc_get_channel_value(ADC, ADC_TEMPERATURE_SENSOR);
}

int main (void)
{
	board_init();
	adc_setup();
	adc_start(ADC);
	//adc_register_setup();
	
	ADC->ADC_CR = 0x2; //start ADC
	
	/* Insert application code here, after the board has been initialized. */

	/* This skeleton code simply sets the LED to the state of the button. */
	while (1) {
	}
	
}
