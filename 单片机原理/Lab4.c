#include<reg52.h>

int i = 0;
sbit led = P1^1;

void main ()
{
	TMOD=0x01;			//��ʱ��T0Ϊ��ʽ1
	TH0=0xfc;			//���ö�ʱ����ֵ
	TL0=0x18;
	EA=1;					//�����ж�
	ET0=1;					//����ʱ��T0�ж�
	TR0=1;					//������ʱ��T0
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
