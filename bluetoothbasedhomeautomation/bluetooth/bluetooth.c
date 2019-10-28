#include<avr/io.h>
#define F_CPU 8000000
#include<util/delay.h>
#include<lcdavr.h>
#include<serial.h>

unsigned char v;
int main()
{
DDRB=0XFF;
lcd_init();
usart_init();
DDRA=0XFF;

while(1)

{
usart_string("WELCOME TO SERIAL");
for(int x=0XC0;x<=0XCF;x++)
{
v=usart_rec();
lcd_command(x);
lcd_data(v);
lcd_command(0x06);
_delay_ms(10);

if(v=='1')
{
lcd_clear();
lcd_command(0x80);
lcd_string("LAMP 1 GLOW ");

PORTA|=(1<<PA0);
}

if(v=='6')
{
lcd_clear();
lcd_command(0x80);
lcd_string("LAMP 1 OFF  ");
if(PINA &=0x01)
{

PORTA |=(0<<PA0);}
}

if(v=='2')

{
lcd_clear();
lcd_command(0x80);
lcd_string("LAMP 2 GLOW ");

PORTA|=(1<<PA1);
}

if(v=='7')

{
lcd_clear();
lcd_command(0x80);
lcd_string("LAMP 2 OFF ");
if(PINA &=0x02)
{
PORTA|=(0<<PA1);}
}

if(v=='3')
{
lcd_clear();
lcd_command(0x80);
lcd_string("LAMP 3 GLOW");

PORTA|=(1<<PA2);
}

if(v=='8')
{
lcd_clear();
lcd_command(0x80);
lcd_string("LAMP 3 OFF");
if(PINA &=0x04)
{
PORTA|=(0<<PA2);}
}

if(v=='4')
{
lcd_clear();
lcd_command(0x80);
lcd_string(" LAMP 4 GLOW ");

PORTA|=(1<<PA3);
}

if(v=='9')
{
lcd_clear();
lcd_command(0x80);
lcd_string(" LAMP 4 OFF  ");
if(PINA &=0x08)
{
PORTA |=(0<<PA3);}
}





}
}
}


