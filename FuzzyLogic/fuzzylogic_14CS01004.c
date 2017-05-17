#include<stdio.h>
#include<math.h>

float a[4],b[4],p,q;
void speed(float n);
void weather(float n);
float sunny(float n);
float cloudy(float n);
float overcast(float n);
void temperature(float n);
float freezing(float n);
float cool(float n);
float warm(float n);
float hot(float n);

							void speed(float n) //Finds the speed 
							{
							if(n>0.50 )
							printf("FAST: ");


							else if(n>=0.0 && n<=0.50)
							printf("SLOW: ");


							 
							/*else if (n>0 && n<=0.25)
							printf("Slowest");

							else
							printf("Fastest");
							*/

							}

				void weather(float n)             //Finds y-coordinate of weather graph
				{float x1=0,x2=0,x3=0;
				if(n>=0 && n<=40)
				x1=sunny(n);
				if(n>=20 && n<=80)
				x2=cloudy(n);
				if(n>=60)
				x3=overcast(n);

				b[0]=x1;
				b[1]=x2;
				b[2]=x3;

				}


				float sunny(float n)
				{
				float y;
				if(n<=20)
				return 1;
				else{
				y=-0.05*(n-40);
				return y;}

				}

				float cloudy(float n)
				{
				float y;
				if(n==50)
				return 1;
				else if (n>=20 && n<50){
				y=0.05*(n-20);
				return y;}
				else{
				y=-0.05*(n-80);
				return y;}
				 }

				float overcast(float n)
				{
				float y;
				if(n>=80)
				return 1;
				else{
				y=0.05*(n-60);
				return y;}
				}





								void temperature(float n)    //Finds the y-c0rdinates of temperature graph
								{
								float x1=0,x2=0,x3=0,x4=0;
								if(n>=0 && n<=50)
								x1=freezing(n);
								if(n>=30 && n<=70)
								x2=cool(n);
								if(n>=50 && n<=90)
								x3=warm(n);
								if(n>=70)
								x4=hot(n);
								a[0]=x1;
								a[1]=x2;
								a[2]=x3;
								a[3]=x4;
								}

								float freezing(float n)
								{
								float y;
								if(n<=30)
								return 1;
								else
								{
								y=(-0.05*n) +2.5;
								return y;
								}}


								float cool(float n)
								{

								float y;
								if(n==50)
								return 1;
								else if(n>=30 && n<50){
								y=(0.05*n)+1.5;
								return y;}
								else if (n>50 && n<=70)
								{y=(-0.05*(n-70));
								return y;
								}
								}


								float warm(float n)
								{
								float y;
								if(n==70)
								return 1;
								else if(n>=50 && n<70){
								y=(0.05*(n-50));
								return y;}
								else if (n>70 && n<=90)
								{y=(-0.05*(n-90));
								return y;
								}



								}
								float hot(float n)
								{
								float y;
								if(n>=90)
								return 1;
								else
								{
								y=(0.05*(n-70));
								return y;
								}}


void main()
{
float n1,n2;
printf("Enter temperature in Fahrenheit: ");
scanf("%f",&n1);
temperature(n1);

printf("Enter weather condition in percentage: ");
scanf("%f",&n2);
weather(n2);

if(a[2]!=0 && b[0]!=0)  //Rule1:Sunny^warm
{
	if(a[2]>b[0])
	p=b[0];
	else
	p=a[2];
if(p<0.5)
printf("Doesnot satisfy 1st Rule as 1st rule outcome must be fast\n");
}
else
{printf("Doesnot satisfy 1st rule\n");}
if(a[1]!=0 && b[1]!=0)  //Rule2:Cloudy^cool
{
	if(a[1]>b[1])
	q=b[1];
	else
	q=a[1];
if(q>0.5)
printf("Doesnot satisfy 2nd Rule as 2nd rule outcome must be slow\n");
}
else
printf("Doesnot satisfy 2nd Rule\n");
if(p!=0)
{
printf("RULE 1 RESULT\n");
	speed(p);

	printf("%0.2f\n",p);
}
if(p!=0)
{printf("RULE 2 RESULT\n");
	speed(q);
	printf("%0.2f\n",q);
}
float temp;
if(p>q)
{	temp=q;
	q=p;
	p=temp;
}
float r;
if(p!=0 && q!=0){
r=((p*25)+(q*75))/(p+q);  printf("\n"); //Speed Calculation weighted mean
printf("SPEED : %0.2f mph Approximately\n",r);
printf("\n");
}
}
