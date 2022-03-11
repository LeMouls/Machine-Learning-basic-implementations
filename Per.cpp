#include <stdio.h>
#include <stdlib.h>
int main()
{
   int tab[10][8] = { 
        {1,1, 1, 1, 1, 1, 1, 0 }, //0
	    {1, 0, 1, 1, 0, 0, 0, 0 }, //1
	    {1, 1, 1, 0, 1, 1, 0, 1 }, //2
	    { 1,1, 1, 1, 1, 0, 0, 1 }, //3
	    { 1,0, 1, 1, 0, 0, 1, 1 }, //4
	    {1, 1, 0, 1, 1, 0, 1, 1 }, //5
	    {1, 1, 0, 1, 1, 1, 1, 1 }, //6
	    {1, 1, 1, 1, 0, 0, 0, 0 }, //7
	    {1, 1, 1, 1, 1, 1, 1, 1 }, //8
	    {1, 1, 1, 1, 1, 0, 1, 1 } };//9
 int k;
int d[10]={ 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0, 1 };
float w[8];
for(int i=0;i<8;i++){
			           w[i]=(-0.5)+(rand()/(float) RAND_MAX)*(1);
				          }
int te[8];		
int compt=0;
float m=0.1;
int i,j,r,s;
int ta[10];

do
   {
   	
compt=0;
for (i = 0 ; i < 10 ; i++)
{
//	printf("compteur=%d\n",compt);
	// printf("le cal num %d\n",i);
	float a=0;
   for(j=0 ;j < 8; j++){
   a=a+(w[j]*tab[i][j]);
   te[j]=tab[i][j];
   
   }
   if(a<0){
   s=0;
   ta[i]=0;
   }
   else{
   s=1;
   ta[i]=1;
   } 
   //printf("%d ",s);
   //printf("a=%f,s=%d,d=%d ",a,s,d[i]);
   if(s!=d[i]){
   	compt=1;
   	for(r=0;r<8;r++){
	   
   	
   
   
   	
   		w[r]=w[r]+m*((d[i]-s)*te[r]);
   	//	printf("w%d=%f",r,w[r]);
   	//	printf(" , ");
   	
	   }
	   
	   
   }
   
   
}
    for(i=0;i<10;i++){
   	printf("%d",ta[i]);
   	
   }
   printf("\n");
}

while (compt!=0);
    







   return 0;
}


