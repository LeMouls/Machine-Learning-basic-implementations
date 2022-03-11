#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define En    256  
#define CE    8    
#define CC    8  
#define CS    1    

//fonction pour comparer les sorties
int cmp_tab(int *x,int *y,double h){
int i=0,j=0,k=0;
float t=0;
double pt=0;
while( i<h ){
if(x[i]==y[i])
     t++;
   //  printf("s[%d]=%d  d[%d]=%d \t",i,x[i],i,y[i]);
 else 
 printf("s[%d]=%d  d[%d]=%d \t",i,x[i],i,y[i]);
i++;

 }
 //pt=((t*100)/h);
 return t;

 } 
 

int main(){
//bin

	int x[En][CC];
	
    int s[En];
	int bin[8]={128,64,32,16,8,4,2,1};
	int n;
	int k=0;
	int nb;
	
//retropropagation
    
    double w[CE][CC];
    double ws[CC];
    double Os[En];
    double O[En][CC];
    double y[En][CC];
    double ys[En];
    double e[En];
    double eus[En];
    double euc[En][CC];
    int d[En];
    // double ds[10][8];
	//double k;
	float m=0.1;
	int it=0;
	bool clin;
	double tau; 
	//initialisation des entrees x et des sorties desirees d
		
do{
	n=k;
	//printf("debut k %d\n",k);
	 for(int i=0;i<8;i++){
	 	if(bin[i]<=n){
		x[k][i]=1;
	 	   n=n-bin[i];
	     }
	 	else
		x[k][i]=0;
		//printf("x[%d][%d]=%d\n",n,i,x[k][i]);
		
	if(k%2==0)
	  d[k]=0;
	else 
	  d[k]=1;
}
k++;
} while (k < 256);
	
 
 	
	//initialisation des piods
	for(int i=0;i<CE;i++){ 
			           for(int j=0;j<CC;j++){
				        w[i][j]=(-0.5)+(rand()/(float) RAND_MAX)*(1);
				        //printf("w[%d][%d]=%f\n",i,j,w[i][j]);
			            }
				   }
	        
	
   // for(int i=0;i<8;i++){
			           for(int j=0;j<CC;j++){
				        ws[j]=(-0.5)+(rand()/(float) RAND_MAX)*(1);
				        //printf("w[%d][%d]=%f\n",i,j,w[i][j]);
				       // printf("ws[%d][%d]=%f\n",i,j,ws[i][j]);
			            }
				   //}
	//fin init poids

     do {
     	tau=0;
 	   it++;
 	   printf("it=%d\n",it);
 	   	for(int v=0;v<En;v++){
 	   		
 	   		
			           //for(int j=0;j<8;j++){
			                e[v]=0;
 	                       Os[v]=0;
 	                     ys[v]=0;
			}
		 
 	   for(int v=0;v<En;v++){
		

	       for(int i=0;i<CC;i++){
	       	    y[v][i]=0;
	             O[v][i]=0;
	         }
			 /*
	         for(int i=0;i<8;i++){
	         	 ys[i]=0;
	         }
	       */
	    	//1    
    	for(int i=0;i<CC;i++){
			           for(int j=0;j<CE;j++){
				        y[v][i]=y[v][i]+(x[v][j]*w[j][i]);
			            }
			            O[v][i]=1/(1+exp(-y[v][i]));
			           // printf("O[%d][%d]=%f \n",v,i, O[v][i]);
				   }
	
	
    //2
   // for(int i=0;i<8;i++){
			           for(int j=0;j<CC;j++){
				        ys[v]=ys[v]+(O[v][j]*ws[j]);
				       // printf("ys[%d]=%f \n",v,ys[v]);
			            }
			            
			            Os[v]=1/(1+exp(-ys[v]));
			           //  printf("Os[%d]=%f \n",v,Os[v]);
			            if((Os[v])>=0.5)
			               s[v]=1;
			            else 
			               s[v]=0;
			               
		if(s[v]!=d[v]){
		
			            //printf(" Os[%d][%d]=%f \n",v,i,Os[v][i]);
			            
			            //3
			            e[v]=d[v]-Os[v];
			            //printf("e[%d]=%f \n",i, e[i]);
			            //4
			            eus[v]=e[v]*(Os[v]*(1-Os[v]));
			            //printf(" rrrr %s \n", eus[i]);
			            //printf("eus[%d]=%f \n",v, eus[v]);
			            
				  // }
				  
	//5
	double sw=0;
	for(int i=0;i<CC;i++){
		
			          // for(int j=0;j<8;j++){
			          //sw=sw+(e[v]*ws[i]*eus[v]);
			           	sw=(e[v]*ws[i]*eus[v]);
			            //}
			            euc[v][i]=O[v][i]*(1-O[v][i])*sw;
			          //  printf("euc[%d]=%f \n",i,euc[v][i]);
				   }
				  
	//6-ajust des poids
        
         k=0; 
        	//for(int i=0;i<8;i++){
        		   // printf("seuil de poids de couche sortie\n");
			           for(int j=0;j<CC;j++){
			           	// printf(" ws[%d] = %f \n",j,ws[j]);
				        ws[j]=ws[j]+(m*eus[v]*O[v][j]);
				       // printf(" ws[%d] = %f \n",j,ws[j]);
				        
			            }
				  // }
			double a;
	//poids w CC
	        for(int i=0;i<CE;i++){
			           for(int j=0;j<CC;j++){
				       w[i][j]=w[i][j]+(m*euc[v][j]*x[v][i]);
				       //seuil=m*euc[j]*x[v][j];
			            }
				   }
	}
				    
			
  }			
    tau= cmp_tab(s,d,En);
  printf("it=%d\n",it);
  printf("*************************************taux=%f\n",tau);
  //seuil > 0.04    
    tau=(tau*100)/En;
    printf("*********************************taux=%f  \n",tau);
}while(tau<100);
       //it<40
        
	       return 0;
}
