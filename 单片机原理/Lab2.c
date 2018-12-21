#include<reg52.h>

#define uchar unsigned char
#define unit unsigned int

uchar dis[]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};

sbit DU = P2^0;
sbit WE = P2^1;	   

uchar qianwei = 0 ,baiwei = 0 ,shiwei = 0 ,gewei = 0;
unit count = 0;

void delayms(unit xms)
{
	unit i,j;
	for(i= xms; i>0; i--)
		for(j=110; j>0; j--);
}
void jiayi()
{
	count = count + 1;
	if(count == 10000)
	count =0;
}

void quwei()
{
	qianwei = count/1000;         //千位数
	baiwei = count%1000/100;      //百位数
	shiwei = count%100/10;		  //十位数
	gewei = count%10;			  //个位数
}

void xianshi()
{
	DU = 1;	  //gewei
	P0 = ~dis[gewei]; 
	DU = 0;
	WE = 1;
	P0 = 0x7f; 
	WE = 0;
	delayms(5);

	DU = 1;		 //shiwei
	P0 = ~dis[shiwei];  
	DU = 0;
	WE = 1;
	P0 = 0xbf; 
	WE = 0;
	delayms(5);

	DU = 1;		 //baiwei
	P0 = ~dis[baiwei];  
	DU = 0;
	WE = 1;
	P0 = 0xdf;
	WE = 0;
	delayms(5);

	DU = 1;		 //qianwei
	P0 = ~dis[qianwei];
	DU = 0;
	WE = 1;
	P0 = 0xef; //1110 
	WE = 0;
	delayms(5);

	
}
void main()
{
	while(1)
	{
	jiayi();
	quwei();
	xianshi();
	}
}


 
