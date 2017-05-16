#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct points
		{
		int x;
		int y;
		}array[100];

int a[100],b[100],n,i,j,count;
int p=2,p2;                                  //Global declaration of some variables
int result[100],result1[100];
int deletepoints();
void sort();
void lowerconvex(int i,int count2);
void upperconvex(int i,int count1);

			void upperconvex(int i,int count1)
			{

			int c1,c2,c3,c4,c5,c6,c7,temp1,p1;           //upper convex hull


			count1=count1+1;
			if(p>=2 && count1<p)
			{
			if(result[p]=i)
			{
			p1=p1-1;
			}
			else
			p1=p;

						c1=(array[result[p1]].x)*(array[i].y);
						c2=((array[i].x)*(array[result[p1]].y));
						c3=((array[result[p1-1]].x)*(array[i].y));
						c4=((array[result[p1-1]].x)*(array[result[p1]].y));        
						c5=((array[i].x)*(array[result[p1-1]].y));
						c6=(array[result[p1]].x)*(array[result[p1-1]].y);
	
					c7=c1-c2-c3+c4+c5-c6;
			if(c7>=0)
			{
			if(count1==1)
			{p=p+1;
			result[p]=i;
			}}


			else
			{
			if(count1==1)
			{
			result[p]=i;
			}
			else if(count1>1)
			{
			p=p-1;
			result[p]=i;
			}
			upperconvex(i,count1);
			}

			}
			}

void lowerconvex(int i,int count2)
{

int d1,d2,d3,d4,d5,d6,d7,p3;


count2=count2+1;
if(p2>=n-count-1 && count2<p2)
{
if(result1[p2]=i)
{
p3=p3+1;                                                 //lower convex hull
}
else
p3=p2;

			d1=(array[result1[p3]].x)*(array[i].y);
			d2=((array[i].x)*(array[result1[p3]].y));
			d3=((array[result1[p3-1]].x)*(array[i].y));
			d4=((array[result1[p3-1]].x)*(array[result1[p3]].y));        
			d5=((array[i].x)*(array[result1[p3-1]].y));
			d6=(array[result1[p3]].x)*(array[result1[p3-1]].y);
	
		d7=d1-d2-d3+d4+d5-d6;
if(d7>=0)
{
if(count2==1)
{p2=p2-1;
result[p2]=i;
}}


else
{
if(count2==1)
{
result[p2]=i;
}
else if(count2>1)
{
p2=p2+1;
result[p2]=i;
}
lowerconvex(i,count2);
}

}
}






						int deletepoints()
						{

						int k;
						for(k=1;k<=n;k++)
						{
						if(b[k]==0)
						{
						count=count+1;
						array[k].x=99999;
						array[k].y=99999;
						}
						}

		sort();
		//return(count);
		}

		void sort()
		{
		int temp,l,m;
		for(l=1;l<=n;l++)
		{
		for(m=l+1;m<=n;m++)
		{
		if(array[l].x==array[m].x && array[l].y>array[m].y)
		{
		temp=array[l].y;
		array[l].y=array[m].y;
		array[m].y=temp;
		}
		if(array[l].x>array[m].x)
		{
		temp=array[l].x;
		array[l].x=array[m].x;
		array[m].x=temp;
		temp=array[l].y;
		array[l].y=array[m].y;
		array[m].y=temp;
		}
		}
		}


		}



void main()
{
int i,c=0,j;
int n1,a1,a2,a3,a4,a5,a6,b1=0,b2=0;

printf("Enter no.of vertices of convex polygon ");
printf("\n");

scanf("%d",&n1);

printf("enter indexes of vertices ");
printf("\n");

for(i=1;i<=n1;i++)
{
scanf("%d",&a[i]);
}



printf("\nEnter total no.of Vertices\n");
scanf("%d",&n);
printf("\n");


for(i=1;i<=n;i++)
{
printf("X%d= ",i);
scanf("%d",&array[i].x);
//printf("\n");
printf("Y%d= ",i);
scanf("%d",&array[i].y);
//printf("\n");
}

a[n1+1]=a[1];

for(i=1;i<=n1;i++)
{
	for(j=1;j<=n;j++)
	{	
 	
	if(j!=a[i] && j!=a[i+1] && b[j]==0)
	{



			a1=(array[a[i+1]].x)*(array[j].y);
			a2=((array[j].x)*(array[a[i+1]].y));
			a3=((array[a[i]].x)*(array[j].y));
			a4=((array[a[i]].x)*(array[a[i+1]].y));        //condition for checking whether it is left or right
			a5=((array[j].x)*(array[a[i]].y));
			a6=(array[a[i+1]].x)*(array[a[i]].y);


	c=a1-a2-a3+a4+a5-a6;

			if(c<0)
			b[j]=1;
			else
			b[j]=0;
	}

	}
}

for(i=1;i<=n1;i++)
{


b[a[i]]=1;


}


printf("\n");
/*for(i=1;i<=n;i++)
{

printf("%d",b[i]);
}*/

deletepoints();


printf("sorted vertices according to x-coordinates\n");
for(i=1;i<=n-count;i++)
{

printf("(%d,%d) ",array[i].x,array[i].y);
}
result[1]=1;
result[2]=2;

for(i=3;i<=(n-count-1);i++){
upperconvex(i,0);}

result1[1]=n-count;
result1[2]=n-count-1;
p2=n-count-1;

for(i=n-count-2;i>1;i--)
{
lowerconvex(i,0);
}

for(i=1;i<=n-count-1;i++)
{
if(result[i]>0)
{b1=b1+1;}
}

for(i=n-count-2;i>1;i--)
{if(result1[i]>0)
{b2=b2+1;}
}
printf("\nResulting Convex Hull\n");
printf(" (%d,%d) ",array[1].x,array[1].y);
printf("->");
for(i=2;i<=b1;i++)
{
printf(" (%d,%d) ",array[result[i]].x,array[result[i]].y);
printf("->");
}
printf(" (%d,%d) ",array[n-count].x,array[n-count].y);


for(i=b2-1;i>1;i--){printf("->");
printf(" (%d,%d) ",array[result1[i]].x,array[result1[i]].y);
}







}
