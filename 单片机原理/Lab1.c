#include<reg52.h>
#define uchar	unsigned char
#define uint 	unsigned int 
void delay(uint z)
{
    uchar j;
    for(z;z>0;z--)
        for(j=200;j>0;j--);
}
void  main()
{
      while(1)
      {
       P3=0xff;                                   
       if(P3==0xfe){P1=0xfe ;delay(500);}         
       else if(P3==0xfd){P1=0xfd ;}    
       else if(P3==0xfb){P1=0xfb ;}   
       else if(P3==0xf7){P1=0xf7 ;}   
       else if(P3==0xef){P1=0xef ;}   
       else if(P3==0xdf){P1=0xdf ;}    
       else if(P3==0xbf){P1=0xbf ;}    
       else if(P3==0x7f){P1=0x7f ;}    
      }
}