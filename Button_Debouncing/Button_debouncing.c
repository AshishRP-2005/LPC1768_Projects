#include <LPC17xx.h>

typedef enum {
			IDLE,
			UP,
			DOWN,
			RIGHT,
			LEFT
		} system_state;
		

void led_connections(int STATUS){
		LPC_GPIO2->FIODIR |= (1U << 2) | (1U << 3) | (1U << 4) | (1U << 5);
		LPC_GPIO2->FIOCLR = (1U<<2) | (1U << 3) |(1U << 4) | (1U << 5);
		
	switch(STATUS){
			
		 case UP :
						LPC_GPIO2->FIOSET = (1U<<2);
						break;
		 case DOWN :
						LPC_GPIO2->FIOSET = (1U<<3);
						break;
		 case RIGHT :
						LPC_GPIO2->FIOSET = (1U<<4);
		 break;
		 case LEFT :
						LPC_GPIO2->FIOSET = (1U<<5);
		 break;
		 default : 
						LPC_GPIO2->FIOCLR = (1U<<2) | (1U << 3) |(1U << 4) | (1U << 5);
						break;
	 }
	 
 }
 
 int main(){
	 	 
	 //LPC_PINCON->PINSEL3 &= ~((3U << 20)  | (3U << 23) | (3U << 24) | (3U << 25) | (3U << 26));

	 
	 LPC_GPIO1->FIOCLR = (1U<<20) | (1U << 23) |(1U << 24) | (1U << 25) | (1U<<26);
	 LPC_GPIO1->FIODIR &= ~((1U<<23) | (1U<<24) | (1U<<25) | (1U<<26)) ;
	 
	 
		
		while(1){
			
			system_state STATE = IDLE;
			
			if ((LPC_GPIO1->FIOPIN & (1U<<20)) == 0)
			{
				STATE = IDLE;
			} else if ((LPC_GPIO1->FIOPIN & (1U<<23)) == 0)
			{
				STATE = UP;
			} else if ((LPC_GPIO1->FIOPIN & (1U<<24)) == 0)
			{
				STATE = DOWN;
			} else if ((LPC_GPIO1->FIOPIN & (1U<<25)) == 0)
			{
				STATE = RIGHT;
			} else if ((LPC_GPIO1->FIOPIN & (1U<<26)) == 0)
			{
				STATE = LEFT;
			} 
			
			led_connections(STATE);
			
		}
	}
	
		
		 