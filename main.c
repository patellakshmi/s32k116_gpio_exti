
#include "S32K116.h"
#define PTE8 (8)	/*! Port PTE, bit 8: FRDM EVB output to blue LED 	*/
#define PTD3 (3)	/*! Port PTD, bit 3: FRDM EVB input from BTN0 [SW2] */


int main(){

	PCC->PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK;
	PCC->PCCn[PCC_PORTE_INDEX] = PCC_PCCn_CGC_MASK;


	PTD->PDDR &= ~( 1 << PTD3);
	PORTD->PCR[PTD3] = PORT_PCR_MUX(1) | PORT_PCR_PFE_MASK;

	PTE->PDDR |= ( 1 << PTE8);
	PORTE->PCR[PTE8] = PORT_PCR_MUX(1);

	while(1){

		if( PTD->PDIR && (1 << PTD3) ){
			PTE-> PSOR |= 1 <<PTE8;
		}else{
			PTE-> PCOR |= 1 <<PTE8;
		}

	}

	return 0;
}

