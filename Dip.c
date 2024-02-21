#include<16F877A.h>
#fuses XT, NOWDT, NOPROTECT, NOLVP,PUT
#use delay(clock=4000000)
#use fast_io(B)
#use fast_io(D)

#byte portb = 0x06
#byte portd = 0x08

void main(){
set_tris_B(0xFF); 
set_tris_D(0x00); 

portb = 0;
portd = 0;


while(TRUE){ 
if(input(portb)==0x00){ //CERO
  portd = 0;
  output_high(PIN_D0);
  output_high(PIN_D1);
  output_high(PIN_D2);
  output_high(PIN_D3);
  output_high(PIN_D4);
  output_high(PIN_D5);
  }
  else if(input(portb)==0x01){ //UNO
  portd = 0;
  output_high(PIN_D1);
  output_high(PIN_D2);
  }
  else if(input(portb)==0x02){ //DOS
  portd = 0;
  output_high(PIN_D0);
  output_high(PIN_D1);
  output_high(PIN_D3);
  output_high(PIN_D4);
  output_high(PIN_D6);
  }
  else if(input(portb)==0x03){ //TRES
  portd = 0;
  output_high(PIN_D0);
  output_high(PIN_D1);
  output_high(PIN_D2);
  output_high(PIN_D3);
  output_high(PIN_D6);
  }
  else if(input(portb)==0x04){ //CUATRO 
  portd = 0;
  output_high(PIN_D1);
  output_high(PIN_D2);
  output_high(PIN_D5);
  output_high(PIN_D6);
  }
  else if(input(portb)==0x05){ //CINCO
  portd = 0;
  output_high(PIN_D0);
  output_high(PIN_D2);
  output_high(PIN_D3);
  output_high(PIN_D5);
  output_high(PIN_D6);
  }
  else if(input(portb)==0x06){ //SEIS
  portd = 0;
  output_high(PIN_D0);
  output_high(PIN_D2);
  output_high(PIN_D3);
  output_high(PIN_D4);
  output_high(PIN_D5);
  output_high(PIN_D6);
  }
   else if(input(portb)==0x07){ //SIETE
  portd = 0;
  output_high(PIN_D0);
  output_high(PIN_D1);
  output_high(PIN_D2);
  output_high(PIN_D6);
  }
   else if(input(portb)==0x08){ //OCHO
  portd = 0;
  output_high(PIN_D0);
  output_high(PIN_D1);
  output_high(PIN_D2);
  output_high(PIN_D3);
  output_high(PIN_D4);
  output_high(PIN_D5);
  output_high(PIN_D6);
  }
   else if(input(portb)==0x09){ //NUEVE
  portd = 0;
  output_high(PIN_D0);
  output_high(PIN_D1);
  output_high(PIN_D2);
  output_high(PIN_D5);
  output_high(PIN_D6);
  }
   else if(input(portb)==0x0A){ //A
  portd = 0;
  output_high(PIN_D0);
  output_high(PIN_D1);
  output_high(PIN_D2);
  output_high(PIN_D4);
  output_high(PIN_D5);
  output_high(PIN_D6);
  }
   else if(input(portb)==0x0B){ //B
  portd = 0;
  output_high(PIN_D2);
  output_high(PIN_D3);
  output_high(PIN_D4);
  output_high(PIN_D5);
  output_high(PIN_D6);
  }
   else if(input(portb)==0x0C){ //C
  portd = 0;
  output_high(PIN_D3);
  output_high(PIN_D4);
  output_high(PIN_D6);
  }
   else if(input(portb)==0x0D){ //D
  portd = 0;
  output_high(PIN_D1);
  output_high(PIN_D2);
  output_high(PIN_D3);
  output_high(PIN_D5);
  output_high(PIN_D6);
  }
   else if(input(portb)==0x0E){ //E
  portd = 0;
  output_high(PIN_D0);
  output_high(PIN_D3);
  output_high(PIN_D4);
  output_high(PIN_D5);
  output_high(PIN_D6);
  }
   else if(input(portb)==0x0F){ //F
  portd = 0;
  output_high(PIN_D0);
  output_high(PIN_D4);
  output_high(PIN_D5);
  output_high(PIN_D6);
  }
 }
}
