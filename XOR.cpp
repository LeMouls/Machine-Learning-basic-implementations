#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define En    4  
#define CE    2    
#define CC    2  
#define CS    1    

//fonction pour comparer so
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

	int x[En][CC]={{1,1},{1,0},{0,1},{0,0}};
	int d[En]={0,1,1,0};
    int s[En];

	int n;
	int k=0;
	int nb;
	
//retro
    
    double w[CE][CC]={{0.5,0.9},{0.4,1}};
    double ws[2]={-1.2,1.1};
    double wbe[CC]={-0.8,-0.8};
    double wbs=-0.3;
    double Os[En];
    double O[En][CC];
    double y[En][CC];
    double ys[En];
    double e[En];
    double eus[En];
    double euc[En][CC];
   // int d[En];
    // double ds[10][8];
	//double k;
	float m=0.1;
	int it=0;
	bool clin;
	double tau; 
     do {
     	tau=0;
 	   it++;
 	   printf("it=%d\n",it);
 	   	for(int v=0;v<En;v++){
 	   		
 	   		//v=255=En
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
    	//	 printf("i=%d \n",i);
    		             
			           for(int j=0;j<CE;j++){
				        y[v][i]=y[v][i]+(x[v][j]*w[j][i]);
				      //  printf("y[%d][%d]=%f   \n",j,i,w[j][i]);
			            }
			            
			            O[v][i]=1/(1+exp(-y[v][i]));
			           // printf("y[%d][%d]=%f  O=%f \n",v,i,y[v][i],O[v][i]);
				   }
	
	
    //2
   // for(int i=0;i<8;i++){
                       ys[v]=wbs;
			           for(int j=0;j<CC;j++){
				        ys[v]=ys[v]+(O[v][j]*ws[j]);
			            }
			         //    printf("ys[%d]=%f \n",v,ys[v]);
			            
			            Os[v]=1/(1+exp(-ys[v]));
			           //  printf("Os[%d]=%f \n",v,Os[v]);
			            if((Os[v])>=0.5)
			               s[v]=1;
			            else 
			               s[v]=0;
			                printf("s[%d]=%d \n",v,s[v]);
		if(s[v]!=d[v]){
		
			            //printf(" Os[%d][%d]=%f \n",v,i,Os[v][i]);
			            
			            //3
			            e[v]=d[v]-Os[v];
			            //printf("e[%d]=%f \n",i, e[i]);
			            //4
			            eus[v]=e[v]*(Os[v]*(1-Os[v]));
			            //printf(" rrrr %s \n", eus[i]);
			         //   printf("eus[%d]=%f \n",v, eus[v]);
			            
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
        
			           for(int j=0;j<CC;j++){
			        //   	 printf(" ws[%d] = %f \n",j,ws[j]);
				        ws[j]=ws[j]+(m*eus[v]*O[v][j]);
				      //  printf(" ws[%d] = %f \n",j,ws[j]);
				        
				        
				        //seuil=m*eus[j]*O[i];
				       // k= m*eus[j]*O[i];
				        
				        //printf("seuil de [%d][%d] = %f \n",i,j,seuil);
			            }
			           
			            
				  // }
			double a;
	//poids w 
	        for(int i=0;i<CE;i++){
			           for(int j=0;j<CC;j++){
			           	
				       w[i][j]=w[i][j]+(m*euc[v][j]*x[v][i]);
				       wbe[j]=wbe[j]+(m*euc[v][j]);
				       //seuil=m*euc[j]*x[v][j];
			            }
			            
				   }
				     
				   
	}
				    
			
  }			
    tau= cmp_tab(s,d,En);
  printf("it=%d\n",it);
  printf("*************************************taux=%f\n",tau);

}while(tau<4 );
       //it<40
        
	       return 0;
}
