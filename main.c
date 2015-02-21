#include <msp430.h>

#define IRLED1 BIT4



int count =0;
int bit =0;
int i =0;
int ii =0;
int iii=0;
int bitt =0;


unsigned long irdata=0;


void tx_send(long irdata);


int main(void)
{

WDTCTL = WDTPW + WDTHOLD;                            // Stop watchdog timer

P1DIR |= (IRLED1);


__enable_interrupt(); // enable all interrupts
while(1)
{
	__delay_cycles(700);
count++;
if(count == 50)
{
	tx_send(0xFF17942);

}
if(count > 2000)
{
	count =0;

}
}
}


void tx_send(long irrealdata)
{


  __disable_interrupt(); // enable all interrupts
//  irdata = irrealdata;

for(iii=32;iii>0;iii--)
{
	bitt = irrealdata & 1;
	irdata |= bitt;
	irrealdata>>=1;
	irdata<<=1;
}

  for (i = 322;i>0;i--)
  {
    P1OUT |= IRLED1;
    __delay_cycles(4);
    P1OUT &= ~IRLED1;
    __delay_cycles(4);

  }

    __delay_cycles(3830);


  for(ii = 32; ii>0;ii--)
  {
    bit = irdata & 1;
    if(bit == 0)
    {
        __delay_cycles(500);
      for (i = 21;i>0;i--)
      {
        P1OUT |= IRLED1;
        __delay_cycles(4);
        P1OUT &= ~IRLED1;
        __delay_cycles(4);

      }



    }
    else
    {

        __delay_cycles(1590);

      for (i = 21;i>0;i--)
      {
        P1OUT |= IRLED1;
        __delay_cycles(4);
        P1OUT &= ~IRLED1;
        __delay_cycles(4);


      }



    }
    irdata >>= 1;
  }

  for (i = 5;i>0;i--)
  {
    P1OUT |= IRLED1;
    __delay_cycles(4);
    P1OUT &= ~IRLED1;
    __delay_cycles(4);


  }


    __delay_cycles(1590);

    for (i = 20;i>0;i--)
    {
      P1OUT |= IRLED1;
      __delay_cycles(4);
      P1OUT &= ~IRLED1;
      __delay_cycles(4);

    }

  __enable_interrupt(); // enable all interrupts
}


