#include<reg52.h>

int i = 0;
sbit led = P1^1;

void main ()
{
	TMOD=0x01;			//定时器T0为方式1
	TH0=0xfc;			//设置定时器初值
	TL0=0x18;
	EA=1;					//开总中断
	ET0=1;					//开定时器T0中断
	TR0=1;					//启动定时器T0
	while(1)
	{
	if(i <= 100 && i>0)
	{
	  led = 0;
	}
	 else if(i>100 && i<=1000) led = 1;
	 else i =0;
	}			
}	 


void timer0() interrupt 1			
{
	TH0=0xfc;			
	TL0=0x18;
	i++;
}
