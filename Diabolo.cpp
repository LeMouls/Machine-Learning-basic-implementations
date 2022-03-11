#include <stdio.h>
#include <stdlib.h>
#include <math.h>

	float tab[8];
	float tot;
	float del[3][8];
	float del2[8][3];
    float w[8][3];
    float ws[3][8];
    float O[3];
    float Os[8];
    float y[3];
    float ys[8];
    float e[8];
    float eus[8];
    float euc[3];
    float temp;
    float delta=0.5;
	//bool clin;
	float k;
	int compt;
	float m=0.1;
	int it=0;
	bool clin;
	double seuil;
	int sortie[10][8];
	double tau;
	int x[10][8]={{0,0,0,0,0,0,0,0},
	              {0,0,0,0,0,0,0,1},
				  {0,0,0,0,0,0,1,0},
				  {0,0,0,0,0,0,1,1},
				  {0,0,0,0,0,1,0,0},
				  {0,0,0,0,0,1,0,1},
				  {0,0,0,0,0,1,1,0},
				  {0,0,0,0,0,1,1,1},
				  {0,0,0,0,1,0,0,0},
				  {0,0,0,0,1,0,0,1}};
				  
	int ds[10][8]={{0,0,0,0,0,0,0,0},
	              {0,0,0,0,0,0,0,1},
				  {0,0,0,0,0,0,1,0},
				  {0,0,0,0,0,0,1,1},
				  {0,0,0,0,0,1,0,0},
				  {0,0,0,0,0,1,0,1},
				  {0,0,0,0,0,1,1,0},
				  {0,0,0,0,0,1,1,1},
				  {0,0,0,0,1,0,0,0},
				  {0,0,0,0,1,0,0,1}};
	
	 
	
int main(){
	for(int i=0;i<8;i++){
			           for(int j=0;j<3;j++){
				        w[i][j]=(-0.5)+(rand()/(float) RAND_MAX)*(1);
				        //printf("w[%d][%d]=%f\n",i,j,w[i][j]);
			            }
				   }
	        
	
    for(int i=0;i<3;i++){
			           for(int j=0;j<8;j++){
				        ws[i][j]=(-0.5)+(rand()/(float) RAND_MAX)*(1);
				        //printf("w[%d][%d]=%f\n",i,j,w[i][j]);
				       // printf("ws[%d][%d]=%f\n",i,j,ws[i][j]);
			            }
				   }

     do {
 	   it++;
 	  
 	   for(int v=0;v<10;v++){
		
	       for(int i=0;i<3;i++){
	       	    y[i]=0;
	             O[i]=0;
	             euc[i]=0;
	         }
	         for(int i=0;i<8;i++){
	         	Os[i];
	         	 ys[i]=0;
	         	 eus[i]=0;
	         	 e[i]=0;
	         }
	       
	    	
			
			for(int j=0;j<8;j++){
			
			tab[j]= (float)(x[v][j]);
		//	printf("%f\n",tab[j]);
			
		}
		
		//1  
		
    	for(int i=0;i<3;i++){
    		tot=0;
			           for(int j=0;j<8;j++){
				       // y[i]=y[i]+(x[v][j]*w[i][j]);
				        tot=tot+(tab[j]*w[j][i]);
			            }
			            O[i]=1/(1+ exp(-tot));
			            
			            //printf("O[%d]=%f \n",i, O[i]);
				   }
	
    //2
    for(int i=0;i<8;i++){
    	tot=0;
			           for(int j=0;j<3;j++){
				     ;:,   tot=tot+(O[j]*ws[j][i]);
			            }
			            Os[i]=1/(1+ exp(-tot));
			           // printf(" Os[%d][%d]=%f \n",v,i,Os[i]);
			            if (Os[i] >= 0.5){
			            	sortie[v][i]=1;
						}
			            
			            else if (Os[i] < 0.5){
			            	sortie[v][i]=0;
						}
						
			            
			            
				   }
				   
				   
				   
				   //4
				  for(int i=0;i<8;i++){ 
				   eus[i]=(Os[i]-(float)ds[v][i])*(Os[i]*(1.0-Os[i]));
				  
				}
	//5
	for(int i=0;i<3;i++){
			           for(int j=0;j<8;j++){
			           	//sw=sw+ws[j][i]*eus[j];
			           	euc[i]= euc[i] + ws[i][j]*(O[i]*(1.0-O[i]))*eus[j];
			            }
			            
				   }
				   
	//6-ajustement des p oids
        
       
		 for(int j=0;j<3;j++)
        	for(int i=0;i<8;i++){
			           
			           	temp = -delta*O[j]*eus[i];
				        ws[j][i]= ws[j][i] +temp+ m*eus[i]*O[j];
				        del[j][i]=temp;
				       // k= m*eus[j]*O[i];
				     //   printf("seuil de [%d][%d] = %f \n",i,j,k);
			            }
			        
				   
				   
	
				   
				    for(int j=0;j<8;j++)
	        for(int i=0;i<3;i++){
			          
			           	temp = -delta*tab[j]*euc[i];
				       w[j][i]=w[j][i]+temp+ m*del2[j][i];
					   	del2[j][i]=temp;			       
			            }
				   
			
	
		 
  }	// fin boucle for v
  compt =0;
  
  for(int i=0;i<10;i++){
			           for(int j=0;j<8;j++){
				       printf("%d ",sortie[i][j]);
				       
				       if (sortie[i][j]==ds[i][j]){
							compt=compt+1;
						}
			            }
			            printf("\n");
				   }
				
		printf("learnd patterns  %d  \n",compt);
		

				   		   
}while( it < 1000);
       
        
	       return 0;
	   }
	   

	   
