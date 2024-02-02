#include <16F877A.h>
#fuses NOWDT, XT, NOPROTECT, NOLVP

#use delay (clock = 4000000)
#include <lcd1.c>
#include <kbd1.c>

#use fast_io(D)
#byte PORTD = 0X08
#byte TRISD = 0X88
#bit alarma = portd.0
#bit cerradura = portd.1

int clave_correcta = 1111;
int intentos = 0;
int acumulador = 0;
int permitir_entrada_lcd = 1;

void main() {
    lcd_init();
    kbd_init();
    port_b_pullups(TRUE);

   lcd_gotoxy(1,1);  
   lcd_putc("\fIngresa la clave\n");
   lcd_gotoxy(1,2);  
   lcd_putc("----");
   lcd_gotoxy(1,2);

    trisd = 0x00;
    portd = 0x00;

    while (TRUE) {
        int k = kbd_getc();

        if (permitir_entrada_lcd) {
            if (k >= '0' && k <= '9') {
                lcd_putc(k);
                int x = k - '0';
                acumulador = acumulador * 10 + x;
            } else if (k == '*') {
                if (acumulador == clave_correcta) {
                    lcd_putc("\fCORRECTO");
                    cerradura = 1;
                } else {
                    lcd_putc("\fINCORRECTO");
                    delay_ms(2000);
                    lcd_putc("\f----");
                    acumulador = 0;
                    intentos++;
                    lcd_gotoxy(1,1);  
                    lcd_putc("\fIngresa la clave\n");
                    lcd_gotoxy(1,2);  
                    lcd_putc("----");
                    lcd_gotoxy(1,2);

                    if (intentos == 3) {
                        alarma = 1;
                        lcd_gotoxy(1,1);  
                        lcd_putc("\fRatita\n");
                        permitir_entrada_lcd = 0;  // Desactiva la entrada en la LCD
                    }
                }
            }
        }
    }
}
