#include <stdio.h>
#include <stdlib.h>
int main()
{
   int tab[10][8] = { 
        { 1,1, 1, 1, 1, 1, 1, 0 }, //0
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
				   
int compt=0;
float m=0.1;
int i,j,r,s;
float tab1[8];
float tab2[8];
int tab3[10];
int clin;
  do {
   	clin = 0;

for (i = 0 ; i < 10 ; i++)
{
	//printf("compteur=%d\n",compt);
	// printf("le cal num %d\n",i);
	float a=0;
   for(j=0 ;j < 8; j++){
   a=a+(w[j]*tab[i][j]);
   tab1[j]=tab[i][j];
   tab2[j]=a;

}
   if(a<0){
   
   s=0;
   tab3[i]=0;}
   else {
   s=1;
   tab3[i]=1;}
   //printf("a=%f,s=%d,d=%d ",a,s,d[i]);
   //printf("s=%d",s);
   if(s!=d[i]){
   	clin=1;
   
   	for(r=0;r<8;r++){
   	
   		w[r]=w[r]+m*((d[i]-tab2[r])*tab1[r]);
   	//	printf("w%d=%f",r,w[r]);
   	//	printf(" , ");
   	
	   }
	  
	   
   }
   
   
   	for(r=0;r<8;r++){
   		//printf("w%d=%f",r,w[r]);
   	//	printf(" , ");
	   }
   //printf("\n");
   
   
   } for(r=0;r<10;r++){
   	printf("%d",tab3[r]);
   	
   }
   printf("\n");
   
}while (clin!=0);








   return 0;
 } 


