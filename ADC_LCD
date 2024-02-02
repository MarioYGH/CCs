#include <16F877A.h>
#device adc = 10

#fuses XT,NOWDT

#use delay (clock=4000000)
#include <lcd.c>

void main(){
int16 q;
float p;

setup_adc_ports(AN0); //Canal 0 analógico
setup_adc(ADC_CLOCK_INTERNAL); //Fuente de reloj RC

lcd_init();

for(;;){ //Ciclo for infinito
set_adc_channel(0); //Habolitación canal 0
delay_us(20);
q = read_adc(); //Lectura canal 0
p = 5.0*q/1024.0; //Conversión a tensión  y "%41d" 4 números enteros y la d es por número entero sin signo 
printf(lcd_putc, "\fADC = %4ld",q); // "\f" limpia el LCD y "01.2fV" 1 entero con dos decimales con f- flotante 
printf(lcd_putc, "\nVoltage = %01.2fV",p); //"\n" salto de linea

delay_ms(100);


}

}
