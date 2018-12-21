#include<reg52.h>
typedef   unsigned char  uint8;
typedef   unsigned int   uint16;
#define uchar unsigned char
uchar  first, second, third, fourth, fifth;
int nums = 0,s=0;

sbit k4 = P3^3;		  //  外部中断1
sbit k3 = P3^2;			//外部中断0

void delayms(unsigned int ms) 

{
   unsigned int i ;
   while(ms--)
    {
      for(i = 0 ; i < 120 ; i++) ;
    }
}

/*
 * UART初始化
 * 波特率：57600
*/
void UART_init(void)
{
    SCON = 0x50;        // 10位uart，允许串行接受
	PCON |= 0x80;  // smod=1 (double baud rate)

    TMOD = 0x20;        // 定时器1工作在方式2（自动重装）

//	EA=1;  // enable global interrupt
//    ES=1;  // enable UART interrupt

    TH1 = 0xFF;
    TL1 = 0xFF;

    TR1 = 1;     //开启外部中断1
}

/*
 * UART 发送一字节
*/
void UART_send_byte(uint8 dat)
{
	SBUF = dat;
	while (TI == 0);
	TI = 0;
}



void UART_send_int(int num)
{

	  first = num % 10+'0';
	second = num % 100 / 10+'0';
	third = num % 1000 / 100+'0';
	fourth = num % 10000 / 1000+'0';
	fifth = num / 10000+'0'; 
	 if(num>=0&&s==0)
	 {

	   UART_send_byte(fifth);
	 UART_send_byte(fourth);
	 UART_send_byte(third);
	 UART_send_byte(second);
	 UART_send_byte(first);
	 UART_send_byte('\n');
	 UART_send_byte('\r');
	 
	 } 
	 if(num>0&&s==1)
	 {

	
	  UART_send_byte('-');
	 UART_send_byte(fifth);
	 UART_send_byte(fourth);
	 UART_send_byte(third);
	 UART_send_byte(second);
	 UART_send_byte(first);
	 UART_send_byte('\n');
	 UART_send_byte('\r');
	 }
	 
}



void main()
{

	UART_init();
	EA = 1;
	EX0 = 1;   //外部中断0
	IT0 = 1;   //0低电平 1下降沿
	EX1 = 1;	//外部中断1
	IT1 = 1; 



	while(1)
	{
		 UART_send_int(nums);		 
		 delayms(500);
	}
	


}	


void int_0()interrupt 0
{
	if(k3 == 0)
	{
	delayms(200);
	if(k3 == 0)
	{
	while(k3 == 0);
	if(nums>0&& s==1)
	{
	nums--;
	if(nums==0)
	{
	s=0;
	}
	}
	else if	(nums>=0&& s==0)
	  {nums++;}
	  
	}
	}
} 


void int1_routine() interrupt 2
{
   	 if(k4 == 0)
	{
	delayms(200);
	if(k4 == 0)
	{
	while(k4 == 0);
	if(nums==0)
	{
	 nums++;
	 s=1;
	}
	else if(nums>0&&s==0) {
	nums--;
	s=0;	}
	else if(nums>0&&s==1)
	{
	nums++;
	}
	}
	}
}  



