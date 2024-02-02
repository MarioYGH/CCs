// PROGRAMA MANEJO DE LCD Y USO DE INTERRUPCIÓN EXTERNA
// Contador ascendente de 0 a 255
// DIRECTIVAS
#include<16f877A.h> //Directiva del microcontrolador a utilizar
#fuses XT, NOWDT, NOPROTECT, PUT //Activación y desactivación de fusibles
#use delay(clock=4000000) //Directiva para establecer Frecuencia del cristal 

#include<lcd.c>  //Directiva de la LCD
#use fast_io(A)  //Directiva Entrada/Salida del Puerto A
#use fast_io(B)  //Directiva Entrada/Salida del Puerto B
#use fast_io(D)  //Directiva Entrada/Salida del Puerto D

#bit PB0=0x06.0   //Asignación del pin B0 con el nombre PB0
#bit F1=0x05.0    //Asignación del pin A0 con el nombre F1
#bit F2=0x05.1    //Asignación del pin A1 con el nombre F2

int contador=0;   //Declaración e inicialización de variable contador

//FUNCIONES
inicializar(){    //Función inicializar
PB0=0;            // Inicializa a 0 el Pin B0
set_tris_b(0x01); //Configuración del Pin B0 como entrada
F1=0; F2=0;       //Inicializa a 0 los Pines A0 y A1 llamados F1 y F2
set_tris_a(0x00);  //Configuración del Puerto A como salida


enable_interrupts(INT_EXT); //Habilitación de la Interrupción externa
enable_interrupts(GLOBAL); //Habilita la interrupción en forma global en el Programa
}

#int_ext  //Directiva para crear una función mientras se ejecuta la Interrupción externa
   atender(){  // Función a utilizar al ejecutar la interrupción externa
   contador ++;  //Incremento en la variable contador 
   }

//FUNCIÓN PRINCIPAL
   main(){         
   inicializar();   //Llama la función inicializar
   lcd_init();      //Inicializa la LCD
   while(TRUE){       //Inicia el ciclo while
   lcd_gotoxy(1,1);   //Posición de inicio en la LCD (Columna, fila)
   printf(lcd_putc, "Contador= %03u", contador); //Impresión en pantalla de la LCD  
                                 //de la leyenda Contador: y el valor de la variable contador
                                 // asignando el formato %03u especificado para 
                                 //el tipo de variable en uso en este caso entera
   F1=1; F2=1;  //Envío de pulsos en los pines A0 y A1  
   delay_ms(100);  //retardo de los pulso en alto 100ms 
   F1=0; F2=0;     //Envío de pulsos en bajo en los pines A0 y A1
   delay_ms(100);   //retardo de los pulso en bajo 100ms 
   }
   }
