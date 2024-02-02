#include <16f877a.h>
#fuses HS,NOWDT,NOPROTECT,NOPUT,NOLVP,BROWNOUT
#use delay(clock=20M)


#use standard_io(C)
#define boton_1 PIN_C0
#use standard_io(D)
#define buzzer PIN_D0
#define led PIN_D1
#include <buzzer_tone.c>

void main(){
output_low(led);   // Asegurar que el LED comience apagado
set_tris_d(0b11111101);
 while(true)
   {
      if(input(boton_1) == 4) ///Condición
      {
         generate_tone(buzzer, 4000, 250);
         output_high(led);  // Encender el LED
      } else {
         output_low(led);
      }
   }
}
