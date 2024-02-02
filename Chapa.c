#include <16F877A.h>
#fuses NOWDT,XT,NOPROTECT,NOLVP

#use delay (clock=4000000)
#include <lcd_puertob.c>
#include <kbd_puertob.c>
char k,c;
int x,i;
char M[]={""};
char B[] ={""};

void main(){
   lcd_init();
   kbd_init();
   port_b_pullups(TRUE);

 //limpia y muestra mensaje 
lcd_gotoxy(1,1);  
lcd_putc("\fIngresa la clave\n");


   while(TRUE){
  // k = kbd_getc();
   x=lcd_read_byte();
   if(x!=0){
      if(x=='*')
      lcd_putc('\f'); //limpia lcd 
      else
       lcd_gotoxy(1,2);
   printf(lcd_putc,"%d", x);
   delay_ms(500);
   lcd_putc("\fIngresa la clave\n");
}
   }
}
   //for(y=0;y<4;y++){ 
   //B[y]=M[x];
   //}
  // lcd_gotoxy(1,2);
   //printf(lcd_putc,"%d", M[i]);
   //delay_ms(500);
   //lcd_putc("\fIngresa la clave\n");
   //}//if
   //lcd_putc(k); //imprime caracter
    //print valor numérico 
