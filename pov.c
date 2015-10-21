/*
 * pov_mohit.c
 *
 * Created: 05-09-2015 17:40:51
 *  Author: Admin
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>

#define led1 (1<<PC0)
#define led2 (1<<PC1)
#define led3 (1<<PC2)
#define led4 (1<<PC3)
#define led5 (1<<PC4)
#define led6 (1<<PC5)
#define led7 (1<<PD2)
#define led8 (1<<PD3)
#define ledc PORTC
#define ledd PORTD

void Delay_us(int);
void a();
void b();
void c();
void d();
void e();
void f();
void g();
void h();
void i();
void j();
void k();
void l();
void m();
void n();
void o();
void p();
void q();
void r();
void s();
void t();
void u();
void v();
void w();
void x();
void y();
void z();
void hour_hand();
void minute_hand();
/*
void printled(int *a)
{
	int i=1;
	for(i=1;i<=8;i++)
	{
		if(a[i] == 1)
		{
			switch(i)
			{
				case 1:
					ledc |= led1;
					break;
				case 2:
					ledc |= led2;
					break;
				case 3:
					ledc |= led3;
					break;
				case 4:
					ledc |= led4;
					break;
				case 5:
					ledc |= led5;
					break;
				case 6:
					ledc |= led6;
					break;
				case 7:
					ledd |= led7;
					break;
				case 8:
					ledd |= led8;
					break;
				default:
					break;		
			}
		}
	}
}
*/

void wave1()
{
	ledc |= led3;
	Delay_us(30);
	ledc |= led2;
	ledc &= ~led3;
	Delay_us(30);
	ledc |= led1;
	ledc &= ~led2;
	Delay_us(30);
	ledc |= led2;
	ledc &= ~led1;
	Delay_us(30);
	ledc |= led3;
	ledc &= ~led2;
	Delay_us(30);
	ledc &= ~led3;
}

void wave2()
{
	ledc |= led4;
	Delay_us(30);
	ledc |= led5;
	ledc &= ~led4;
	Delay_us(30);
	ledc |= led4;
	ledc &= ~led5;
	Delay_us(30);
	ledc &= ~led4;
}

void ball1()
{
	ledc |= led2;
	Delay_us(50);
	ledc |= led1 | led3;
	ledc &= ~led2;
	Delay_us(50);
	ledc |= led2;
	ledc &= ~led1 &~ led3;
	Delay_us(50);
	ledc &= ~led2;
}

void ball2()
{
	ledc |= led3;
	Delay_us(50);
	ledc |= led2 | led4;
	ledc &= ~led3;
	Delay_us(50);
	ledc |= led3;
	ledc &= ~led2 &~ led4;
	Delay_us(50);
	ledc &= ~led3;
}

void ball3()
{
	ledc |= led4;
	Delay_us(50);
	ledc |= led3 | led5;
	ledc &= ~led4;
	Delay_us(50);
	ledc |= led4;
	ledc &= ~led3 &~ led5;
	Delay_us(50);
	ledc &= ~led4;
}

void ball4()
{
	ledc |= led5;
	Delay_us(50);
	ledc |= led4 | led6;
	ledc &= ~led5;
	Delay_us(50);
	ledc |= led5;
	ledc &= ~led4 &~ led6;
	Delay_us(50);
	ledc &= ~led5;
}

void ball5()
{
	ledc |= led6;
	Delay_us(50);
	ledc |= led5 ;
	ledd|= led7;
	ledc &= ~led6;
	Delay_us(50);
	ledc |= led6;
	ledc &= ~led5 ;
	ledd &= ~led7;
	Delay_us(50);
	ledc &= ~led6;
}

void ball6()
{
	ledd |= led7;
	Delay_us(50);
	ledc |= led6; 
	ledd |= led8;
	ledd &= ~led7;
	Delay_us(50);
	ledd |= led7;
	ledc &= ~led6; 
	ledd &= ~led8;
	Delay_us(50);
	ledd &= ~led7;
}

int sec=1;
int cnt = 0;
int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
int tmp = 0, tmp2=1,tmp3=0;
int main(void)
{
	DDRC = 0xff;
	DDRD = 0xff;
	DDRB |= (1<<PB0);
	PORTB |= (1<<PB0);
	TCCR1B = (1<<CS12);
    while(1)
    {
		if(bit_is_set(PINB,1))
		{
			
		
		
			if( cnt >=80 && q1 == 0)
			{
				Delay_us(1700);
				d();
				r();
				i();
				s();
				h();
				t();
				i();
				cnt++;
				if(cnt >=170)
				{
					cnt = 0;
					q1 =1;
				}
			}
			else if( cnt<80 && q1 == 0)
			{
				Delay_us(1400);
				w();
				e();
				l();
				ledc |= led3;
				Delay_us(70);
				ledc &= ~led3;
				Delay_us(60);
				c();
				o();
				m();
				e();
 				Delay_us(130);
				 two();
				 cnt++;
			}	
			
			else if ( q1 == 1)
			{
				if(tmp<=50)
				{
					ledc |= led1 | led3 | led5;
					Delay_us(sec);
					ledc &= ~led1 &~ led3 &~ led5;
					sec+=150;
					tmp++;
					if(tmp>=40)
						sec=0;
					
				}
				else if(tmp<80)
				{
					ledc |= led2 | led4 ;
					Delay_us(sec);
					ledc &= ~led2 &~ led4 ;
					sec+=150;
					tmp++;
					if(tmp >= 79)
					{
						q1=2;
						sec = 0;
						tmp = 0;
					}
				}
			}
			
		
		else if( q1 == 1)
		{
			if(tmp<=40)
			{
				ledc |= led1 | led3 | led5;
				Delay_us(sec);
				ledc &= ~led1 &~ led3 &~ led5;
				sec+=200;
				tmp++;
				if(tmp>=40)
					sec=0;
					
			}
			else if(tmp<90)
			{
				ledc |= led2 | led4 ;
				Delay_us(sec);
				ledc &= ~led2 &~ led4 ;
				sec+=200;
				tmp++;
				if(tmp >= 89)
				{
					q1=2;
					sec = 0;
					tmp = 0;
				}
			}
		}		
     
	 
		else if( q1 == 3)
		{
			for(tmp=0;tmp<sec;tmp++)
			{
				if(tmp2 <10)
				{
					wave1();
					tmp2++;
				}
				if(tmp2 >=10 && tmp2 <=20)
				{
					wave2();
					tmp2++;
					if(tmp2>=20)
						tmp2=0;
				}	
			}
			tmp3++;
			if(tmp3>=5)
			{
				sec++;
				tmp3=0;
			}
			
			if(sec >= 50 )
			{
				q1 = 0;
				tmp = 0;
				sec = 0;
				tmp2 = 0;
				tmp3=0;
			}
		}	
    
		else if(q1 == 2 )
		{
			for(tmp=0;tmp<sec;tmp++)
			{
				if(tmp2 == 1)
				{
					wave1();
					tmp2 = 2;
				}
				if(tmp2 == 2)
				{
					wave2();
					tmp2 = 1;
				}
			}
			tmp3++;
			if(tmp3>=10)
			{
				sec++;
				tmp3=0;
			}
			
			if(sec>=25)
			{
				q1 = 3;
				sec = 0;
				tmp = 0;
				tmp3 = 0;
				tmp2 = 0;
			}
		}	
		}
}
}

void Delay_us(int n)
{
	while(n--)
	{
		_delay_us(1);
	}
}

void hour_hand()
{
	ledc |= led3|led4|led5;
	Delay_us(50);
	ledc &= ~led3 & ~led4 & ~led5;
}

void two()
{
	ledc |= led1|led5;
	Delay_us(60);
	ledc |= led4;
	Delay_us(30);
	ledc |= led2;
	ledc &= ~led1;
	Delay_us(30);
	ledc |= led3;
	ledc&= ~led4 &~ led2;
	Delay_us(50);
	ledc &= ~led3 &~ led5;
	Delay_us(60);
	
}

void minute_hand()
{
	ledc |= led3|led4|led5;
	ledd |= led6|led7|led8;
	Delay_us(50);
	ledc &= ~led3&~led4&~led5;
	ledd &= ~led6&~led7&~led8;
}
void a()
{
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led2&~led4&~led5;
	Delay_us(150);
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	Delay_us(60);
}

void b()
{
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led2&~led4;
	Delay_us(120);
	ledc &= ~led1&~led3&~led5;
	ledc |= led2|led4;
	Delay_us(50);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	Delay_us(60);
}

void c()
{
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led2&~led3&~led4;
	Delay_us(130);
	ledc &= ~led5;
	Delay_us(20);
	ledc &= ~led1&~led2&~led3&~led4;
	Delay_us(60);
}

void d()
{
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led2&~led3&~led4;
	Delay_us(100)	;
	ledc &= ~led1&~led5;
	ledc |= led2|led4;
	Delay_us(70);
	ledc &= ~led2&~led4;
	ledc |= led3;
	Delay_us(50);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	Delay_us(60);
}

void e()
{
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led2&~led4;
	Delay_us(150);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	Delay_us(60);
}

void f()
{
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led2&~led4&~led5;
	Delay_us(150);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	Delay_us(60);
}

void g()
{
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led2&~led3&~led4;
	Delay_us(100);
	ledc |= led3;
	Delay_us(50);
	ledc |= led4;
	Delay_us(50);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	Delay_us(60);
}

void h()
{
	
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led1&~led2&~led4&~led5;
	Delay_us(150);
	ledc |= led1|led2|led3;
	Delay_us(50);
	ledc |= led4|led5;
	ledc &= ~led1&~led2&~led3;
	Delay_us(20);
	ledc &= ~led4&~led5;
	Delay_us(30);
	ledc &= ~led1&~led2&~led3;
	Delay_us(30);
	
}

void i()
{
	ledc = led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc = 0x00;
	Delay_us(80);
}

void j()
{
	ledc |= led4;
	Delay_us(70);
	ledc|= led5;
	ledc &= ~led4;
	Delay_us(150);
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	Delay_us(60);
}

void k()
{
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led1&~led2&~led4&~led5;
	Delay_us(75);
	ledc &= ~led3;
	ledc |= led2|led4;
	Delay_us(50);
	ledc |= led1|led5;
	ledc &= ~led2&~led4;
	Delay_us(50);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	Delay_us(60);
}

void l()
{
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led1&~led2&~led3&~led4;
	Delay_us(120);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	Delay_us(60);
}

void m()
{
	
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(30);
	ledc &= ~led2&~led3&~led4&~led5;
	Delay_us(30);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	ledc|= led2;
	Delay_us(30);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	ledc|= led3;
	Delay_us(30);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	ledc|= led2;
	Delay_us(30);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	ledc|= led1;
	Delay_us(30);
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(30);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	Delay_us(60);
	
}

void n()
{
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led2&~led3&~led4&~led5;
	Delay_us(50);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	ledc|= led2;
	Delay_us(50);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	ledc|= led3;
	Delay_us(50);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	ledc|= led4;
	Delay_us(50);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	ledc|= led5;
	Delay_us(50);
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	Delay_us(60);
}

void o()
{
	
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led2&~led3&~led4;
	Delay_us(150);
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	Delay_us(60);
	
}

void p()
{
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led2&~led4&~led5;
	Delay_us(80);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	ledc |= led2;
	Delay_us(60);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	Delay_us(60);
}

void q()
{
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led3&~led4;
	Delay_us(70);
	ledc &= ~led2&~led4;
	ledc |= led3;
	Delay_us(50);
	ledc &= ~led2&~led3;
	ledc |= led4;
	Delay_us(50);
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	Delay_us(60);
}

void r()
{
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led2&~led5;
	ledc |= led3;
	Delay_us(50);
	ledc|= led4;
	Delay_us(30);
	ledc &= ~led2&~led4;
	ledc |= led5;
	Delay_us(50);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	ledc |= led2|led5;
	Delay_us(60);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	Delay_us(80);
	
}

void s()
{
	
	ledc |= led1|led2|led3|led5;
	Delay_us(70);
	ledc &= ~led2;
	
	Delay_us(150);
	ledc |= led4;
	ledc &= ~led1&~led3;
	Delay_us(50);
	ledc &= ~led1&~led2&~led3&~led4&~led5;
	Delay_us(60);
	
}

void t()
{
	ledc |= led1;
	Delay_us(100);
	ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
	ledc &= ~led2&~led3&~led4&~led5;
	Delay_us(100);
	ledc &= ~led1;
	Delay_us(60);
}

void u()
{
		ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
		ledc &= ~led1&~led2&~led3&~led4;
	Delay_us(150);
		ledc |= led1|led2|led3|led4|led5;
	Delay_us(50);
		ledc &= ~led1&~led2&~led3&~led4&~led5;
	Delay_us(60);
}

void v()
{
		ledc |= led1;
	Delay_us(50);
		ledc &= ~led1;
		ledc |= led2;
	Delay_us(50);
		ledc &= ~led2;
		ledc |= led3;
	Delay_us(50);
		ledc &= ~led3;
		ledc |= led4;
	Delay_us(50);
		ledc &= ~led4;
		ledc |= led5;
	Delay_us(50);
		ledc &= ~led5;
		ledc |= led4;
	Delay_us(50);
		ledc &= ~led4;
		ledc |= led3;
	Delay_us(50);
		ledc &= ~led3;
		ledc |= led2;
	Delay_us(50);
		ledc &= ~led2;
		ledc |= led1;
	Delay_us(50);
		ledc &= ~led1;
	Delay_us(60);
}

void w()
{
		ledc |= led1;
	Delay_us(20);
		ledc &= ~led1;
		ledc |= led2;
	Delay_us(20);
		ledc &= ~led2;
		ledc |= led3;
	Delay_us(20);
		ledc &= ~led3;
		ledc |= led4;
	Delay_us(20);
		ledc &= ~led4;
		ledc |= led5;
	Delay_us(20);
		ledc &= ~led5;
		ledc |= led4;
	Delay_us(20);
		ledc &= ~led4;
		ledc |= led3;
	Delay_us(20);
		ledc &= ~led3;
		ledc |= led2;
	Delay_us(20);
		ledc &= ~led2;
		ledc |= led1;
	Delay_us(20);
		ledc &= ~led1;	
	Delay_us(20);
		ledc &= ~led1;
		ledc |= led2;
	Delay_us(20);
		ledc &= ~led2;
		ledc |= led3;
	Delay_us(20);
		ledc &= ~led3;
		ledc |= led4;
	Delay_us(20);
		ledc &= ~led4;
		ledc |= led5;
	Delay_us(20);
		ledc &= ~led5;
		ledc |= led4;
	Delay_us(20);
		ledc &= ~led4;
		ledc |= led3;
	Delay_us(20);
		ledc &= ~led3;
		ledc |= led2;
	Delay_us(20);
		ledc &= ~led2;
		ledc |= led1;
	Delay_us(20);
		ledc &= ~led1;
	Delay_us(60);
}

void x()
{
		ledc |= led1|led5;
	Delay_us(50);
		ledc |= led2|led4;
		ledc &= ~led1&~led5;
	Delay_us(50);
		ledc |= led3;
		ledc &= ~led2&~led4;
	Delay_us(50);
		ledc |= led2|led4;
		ledc &= ~led3;
	Delay_us(50);
		ledc |= led1|led5;
		ledc &= ~led2&~led4;
	Delay_us(50);
		ledc &= ~led1&~led5;
	Delay_us(60);
}

void y()
{
		ledc |= led1|led5;
	Delay_us(50);
		ledc |= led2|led4;
		ledc &= ~led1&~led5;
	Delay_us(50);
		ledc |= led3;
		ledc &= ~led2&~led4;
	Delay_us(50);
		ledc |= led2;
		ledc &= ~led3;
	Delay_us(50);
		ledc |= led1;
		ledc &= ~led2;
	Delay_us(50);
		ledc &= ~led1;
	Delay_us(60);
}

void z()
{
		ledc |= led1|led5;
	Delay_us(50);
		ledc |= led4;
	Delay_us(50);
		ledc |= led3;
		ledc &= ~led4;
	Delay_us(50);
		ledc |= led2;
		ledc &= ~led3;
	Delay_us(50);
		ledc |= led1;
		ledc &= ~led2;
	Delay_us(50);
		ledc &= ~led1&~led5;
		TCNT1=0;
	Delay_us(60);
}

