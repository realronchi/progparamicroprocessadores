/* EXEMPLOS DE APLICACAO EM LINGUAGEM C PARA MICROCONTROLADORES MICROCHIP
MCU:                  PIC16F877A
CRISTAL OSCILADOR:    HS - 8,000 MHz
COMPILADOR:           MIKROC PRO FOR PIC - VER:5.61
KIT DESENVOLVIMENTO:  PICKIT PIC18F - MICROGENIOS
GRAVADOR USB:         MICROICD ZIF - MICROGENIOS
PROGRAMADOR:          PICkit2 - VER: 2.61.00
==============================================================+==============
CHAVES DIP USADAS [0N] / [OFF]:
1- GLCD / LCD = [GLCD]   2- RX = [OFF]      3- TX = [OFF]     4- REL1 = [ON]
5- REL2 = [OFF]          6- SCK = [OFF]     7- SDA = [OFF]    8- RTC [OFF]
9- LED1 = [OFF]          0- LED2 = [OFF]
1- DIS1 = [ON]           2- DIS2 = [ON]     3- DIS3 = [ON]    4- DIS4 = [ON]
5- INFR = [OFF]          6- RESIS = [OFF]   7- TEMP = [OFF]   8- VENT = [OFF]
9- AN0 = [OFF]           0- AN1 = [OFF]     a- JUMPER BUZZER ABERTO
=============================================================================
DESCRICAO: ESTE CODIGO FAZ COM QUE SEJA APRESENTADO O NUMERO: "6.057" NO
MOSTRADOR DE SETE SEGMENTOS INDEFINIDAMENTE.
============================================================================ */
// DIRETIVAS DO COMPILADOR
# define BARRA_LEDS_1     PORTD
# define DIS1             PORTA.RA2
# define DIS2             PORTA.RA3
# define DIS3             PORTA.RA4
# define DIS4             PORTA.RA5
void main() { // ABRE FUNCAO PRINCIPAL: MAIN
ADCON1 = 0x06;           // CONFIGURA ENTRADAS AN COMO E/S DIGITAIS
CMCON = 7;               // DESLIGA COMPARADORES
// CONFIGURACOES E/S E ESTADOS INICIAIS [BINARIO]
TRISA = 0b00000000;            PORTA = 0b00000000;
TRISB = 0b00000000;            PORTB = 0b00000000;
TRISC = 0b00000000;            PORTC = 0b00000000;
TRISD = 0b00000000;            PORTD = 0b00000000;
TRISE = 0b00000000;            PORTE = 0b00000000;
// ESTADOS INICIAIS DOS ACESSORIOS
BARRA_LEDS_1 = 0b00000001;
DIS1 = 0;      DIS2 = 0;
DIS3 = 0;      DIS4 = 0;
// APRESENTA O NUMERO: "6.057" NO MOSTRADOR DE SETE SEGMENTOS
do {
DIS1 = 1;
BARRA_LEDS_1 = 0b11111101; // DIGITO "6" COM O PONTO DECIMAL
Delay_ms(1);
DIS1 = 0;
DIS2 = 1;
BARRA_LEDS_1 = 0b00111111; // DIGITO "0" SEM O PONTO DECIMAL
Delay_ms(1);
DIS2 = 0;
DIS3 = 1;
BARRA_LEDS_1 = 0b01101101; // DIGITO "5" SEM O PONTO DECIMAL
Delay_ms(1);
DIS3 = 0;
DIS4 = 1;
BARRA_LEDS_1 = 0b00000111; // DIGITO "7" SEM O PONTO DECIMAL
Delay_ms(1);
DIS4 = 0;
} while (1);}  // FECHA DO-WHILE  // FECHA MAIN