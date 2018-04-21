#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<conio.h>
#define max 20    
   /*Author : Gamane Adel 
       Date :17/04/18
   */    
   	  	
   	//################################**Le corps des fonctions **############################  	

int tache_affect(int a[][max],int cost[][max],int size)
{
	int i,j,costm;
	costm=0;
	for(i=0;i<size;i++)
            {
                for(j=0;j<size;j++)
                {
                    if(a[i][j]== -1)
                    {
                          printf("\n La tache %d est affecte a l'agent %d ",i,j);
                          printf("\n");
                          costm=costm+cost[i][j];
                    }
                }
            }
            return costm;
}

int mark_col(int mat[][max],int j,int lg[max],int size)
{
	int i,ln[max];
	
	for(i=0;i<size;i++)
               {	
              	 if(mat[i][j]==-2 && lg[i]==-11)
				   {
				   	ln[j]=-11;
				   	printf("\n La colomne %d est marquee ",j);
				   	
					}	
			   }
			   
    return 	ln[j];	
}

int mark_line(int mat[][max],int i,int ln[max],int lg[max],int size)
{
	int j;
	
			for(j=0;j<size;j++)
               {	
              	 if(mat[i][j]==-1 && ln[j]==-11)
				   {
				   	lg[i]=-11;
				   	printf("\n La ligne %d est marquee ",i);
					}	
			   }	
				   
    return 	lg[i];	
}








int zero_encadre(int mat[][max],int size)
{
	int i,j,l;
	l=0;
	for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                   if(mat[i][j]==-1)
                   {
                    l=l+1;
                   }
            }
        }
        return l;
}



int mark_zero_line(int mat[][max],int repon3,int k,int size)
{
	
	int i,j,co,lz[max],lzz[max],lzzz;
	lzzz=0;
	for(i=0;i<size;i++)
        			{
        				lz[i]=0;
        				lzz[i]=0;
         			for(j=0;j<size;j++)
    				{
     				if(mat[i][j]==0)
      				{
       				lz[i]=lz[i]+1;
					lzz[i]=lz[i];                
      				}			  
     				}   
        			}
			     
	if(lz[k]==1)
	  {
			 	for(j=0;j<size;j++)
			 	 {
			    	if (mat[k][j]==0)
			  	     { 
					   co=j;
			  		    mat[k][j]=-1 ;
			  	     }
			     }
			  	for(i=0;i<size;i++)
			  	 {
			  	   if (mat[i][co]==0)
					{
					  mat[i][co]=-2;
					  lz[i]=lz[i]-1;
			  	  	}
			     }
			     
		}
		// test 
		for(i=0;i<size;i++)
		 {
		  if(lzz[i]==lz[i])
			{
			 lzzz++;	
			}
		 }
		 if(lzzz=size)
		   {
		   	repon3=repon3+1;
		   }
		 return repon3;
}	  	
 
void mark_zero_col(int mat[][max],int m,int size)
{
	int i,j,li,cz[max];
	
	for(j=0;j<size;j++)
        {	
        	cz[j]=0;
         for(i=0;i<size;i++)
            {
                if(mat[i][j]==0)
                {
                    cz[j]=cz[j]+1;
                }
            }	     
        }
	
	if(cz[m]==1)
	  {
			 	for(i=0;i<size;i++)
			 	{
			  	 if (mat[i][m]==0)
			  	  { 
					li=i;
			  		mat[i][m]=-1 ;
			  	  }
			    }
			  	for(j=0;j<size;j++)
			  	{
			  		if (mat[li][j]==0)
					{
					  	mat[li][j]=-2;
					  	cz[j]=cz[j]-1;
					}
				}
					
	  }
}	   
   	  	
   	  	
int min_col(int mat[][max],int j,int size)
{
    int aug,aug1,i,minc[max];

      
            minc[j]=mat[0][j];
            for(i=0;i<size;i++)
            {
                if(minc[j]>mat[i][j])
                {
                    minc[j]=mat[i][j];
                }
            }
        
return minc[j];
}   	  	



int min_row (int mat[][max],int i,int size)
{
	int j,minr[max];
	
	
            minr[i]=mat[i][0];
            for(j=0;j<size;j++)
            {
                if(minr[i]>mat[i][j])
                {
                    minr[i]=mat[i][j];
                }
            }
        
	return minr[i] ;
	
}

	  	
int make_mat(int mat[][max],int matt[][max],int size)   	  	
{
	int i,j;
for(i=0;i<size;i++)
   {
    for(j=0;j<size;j++)
      {
        mat[i][j]=matt[i][j];
      }
    }			 			 
}   	  	
 	  	
   	  	
int rech_min_pos(int mat[][max],int size)
{
	 int min,a,b;
	 min=mat[0][0];  
  for(a=0;a<size;a++)
    {
     for(b=0;b<size;b++)
      	{
		 if(mat[a][b] > 0 && mat[a][b] < min )
		   {
		    min = mat[a][b];
			}
    	}
    }
    return min ;	
} 	
   	  	
   	  	
void affich_mat(int mat[][max],int size)
 {
 	int a,b;
 	for(a=0;a<size;a++)
        {
            for(b=0;b<size;b++)
            {
                printf("| %d ", mat[a][b]);
            }
            printf("\n");
        }
 }  	  	
   	  	
int mat_size(int r,int c,int mat[][max])
{
	int diff,i,j,size;

	   if(r!=c)
        {
            if(r>c)
            {
                diff=r-c;
                while(diff!=0)
                {
                    for(i=0;i<r;i++)
                    {
                        mat[i][c]=0;
                    }
                    c++;
					diff--;
                }
              size=r;  
            }
          if(r<c)
            {
                diff=c-r;
                while(diff!=0)
                {
                    for(i=0;i<c;i++)
                    {
                        mat[r][i]=0;
                    }
                    r++;diff--;
                }
              size=r;  
            }
        }
        if(r==c)
        {
            size=r;
        }
	
	return size ;
}  
  
  
  //***********************************************************************************************************************
   
int main()
    {
	  int tr,size,test1,test2,aug[max],aug1[max],m,repon1,repon2,av,i,j,repon3,k,r,lg[max],ln[max],c,li,co,diff,l=0,lz[max],cz[max]
        ,a[max][max],t[max][max],ad[max][max],minr[max],minc[max],minnew;
        int cross[max][max];
        int nbz[max],nrc[max],ncc[max];
        int cost[max][max],costm=0;
      
        
        // saisisser la taille de la matrice
        printf("*******************La taille de la matrice******************** \n ");
        printf("Donner le nombre de ligne : ");
        scanf("%d",&r);
        printf("Donner le nombre de colonne : ");
        scanf("%d",&c);
        
        //saisisser les eléments de la matrice 
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {   
			printf("Entrer l'element a[%d][%d] : ",i,j);
            scanf("%d",&a[i][j]);
            }
        }
        
        //obtenir la taille de matrice 
        size=mat_size(r,c,a);
        
        //affichage de la matrice 
        printf(" \n La matrice est : \n");
        affich_mat(a,size);
        
        //initialiser toutes les matrices
        for(i=0;i<size;i++)
        {
            lz[i]=cz[i]=0;
            nbz[i]=ncc[i]=0;
            for(j=0;j<size;j++)
            {
                cost[i][j]=0;
            }
        }
        //making cost matrix
        make_mat(cost,a,size);
        
        //calculating min row
        for(i=0;i<size;i++)
        {
       		minr[i]=min_row(a,i,size);
    	}
        //subtracting min row from respective row
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                a[i][j]=a[i][j]-minr[i];
            }
        }
        
        //calculating min col
        for(j=0;j<size;j++)
          {
    		minc[j]=min_col(a,j,size);
		   }
		   
		   
        //subtracting min column from respective column
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                a[j][i]=a[j][i]-minc[i];
            }
        }
        
        //displaying reduced matrix
        printf("\n La matrice reduite est : \n");
        affich_mat(a,size);
        
        //copying reduced matrix
        make_mat(t,a,size);
        make_mat(cross,a,size);
        make_mat(ad,a,size);
        
        
        
//##############################################################################################################################        
       
	   
	           
        //striking lines in row
       repon3=0;
        while(repon3<2)
		{    
            k=0;
            while(k<size)
            {
			repon3=mark_zero_line(a,repon3,k,size);
			 k++;	
			}	
		}
        //calculating colomn zero
        
        //striking lins in colomn
        
         	m=0;
            while(m<size)
            {
			 mark_zero_col(a,m,size);
			 m++;	
			}	  
    
        //calculating no of zero encadre
       	l=zero_encadre(a,size);
      	
        printf("\n Nombre de zero encadre : %d \n",l);
        
        //cross matrix
        printf(" \n La matrice de marquage est : \n");
        affich_mat(a,size);
        
        
    if (l==size)
    {
         costm=tache_affect(a,cost,size);
        printf("\n Le cout minimum d'affectation est : %d ",costm);
    }


    //********************************************************************************************************
while(l!=size)
{	
	
	for(i=0;i<size;i++)
      {
      	nbz[i]=0;
      	lg[i]=0;
      	ln[i]=0;
      	lz[i]=0;
      	cz[i]=0;
      	nbz[i]=0;
      }
	//calculating row zero i.e. no of zeros in row
	
	//striking lines in row
	    repon3=0;
        while(repon3<2)
		{    
            k=0;
            while(k<size)
            {
			repon3=mark_zero_line(a,repon3,k,size);
			 k++;	
			}	
		}
	//calculating colomn zero
        
        
        //striking lins in colomn
         	m=0;
            while(m<size)
            {
			 mark_zero_col(t,m,size);
			 m++;	
			}	  
    
	//calcul de nombre de zero encadree
    	 for(i=0;i<size;i++)
            {
              for(j=0;j<size;j++)
                {
                  if(a[i][j]== -1) 
					{
					 nbz[i]=nbz[i]+1;  
           		    }                  
    			}
    		printf("\n nbr de -1 en ligne %d est : %d ",i,nbz[i]);	
    		}
    		
    	for(i=0;i<size;i++)
            {
            	printf("\n la valeur de ligne %d est : %d \n",i,lg[i]);
			}
				
		//marquer ligne sans zeero encadre	
    	  for(i=0;i<size;i++)
            {
              if(nbz[i]==0)
			   {
			   	lg[i]=-11;
			   	printf("\n La ligne %d est marquee ",i); //marquer une ligne sans zero encadre
			   }
			   		
			}
			for(i=0;i<size;i++)
            {
            	printf("\n la valeur de ligne %d est : %d \n",i,lg[i]);
			}
			
//""""""""""""""""""""""""""""""""La prtie repetitive """"""""""""""""""""""""""""""""""""""""""""""""""""			


			for(j=0;j<size;j++)
			   {
			   	aug[j]=0;
				}	
    		for(i=0;i<size;i++)
			   {
			   	aug1[i]=0;
				}
		test1=0;	
		test2=0;

	while( test1<2 && test2<2 )
		{
	   	k=0;
		m=0;	
		//Marquer une colonne ayant zero baree sur une ligne marquee			
    	for(j=0;j<size;j++)
            {
			ln[j]=mark_col(a,j,lg,size);
			aug1[j]=ln[j];
			}
			
    	  //Marquer tt ligne ayant zero encadre sur une colonne marquee
    	  for(i=0;i<size;i++)
            {
             lg[i]=mark_line(a,i,ln,lg,size);
             aug[i]=lg[i];
    		}
    		
    		for(j=0;j<size;j++)
        	  {
		  		if(aug1[j]==ln[j])
		    	{
		    	k++;	
				}
			  }
			  printf("\n k %d",k);
    		for(i=0;i<size;i++)
        	  {
		  		if(aug[i]==lg[i])
		    	{
		    	m++;	
				}
    		  }
    		  printf("\n m %d",m);
    		if(k==size)
    		{
    		test1++;	
			}
			printf("\n test1 %d",test1);
			if(m==size)
    		{
    		test2++;	
			}
			printf("\n test2 %d",test2);
		}
    	//copie de la matrice t sur cross	
    	make_mat(cross,t,size);
    	 
		// barer les colomnes marque
    	for(i=0;i<size;i++)
            {
             for(j=0;j<size;j++)
               {	
			     if(ln[j]==-11)
				   {
				   	cross[i][j]=-7;
					}	
				}	  
    		}
    	//	baree les ligne non marquee
    		for(j=0;j<size;j++)
            {
             for(i=0;i<size;i++)
               {	
			     if(lg[i]!=-11)
				   {
				   	cross[i][j]=-7;
					}	
				}	  
    		}
    	  
    	printf(" \n La sous matrice reduite est : \n");
        affich_mat(cross,size);
            
        
 		// recherche new min    
 		
 		
    	minnew=rech_min_pos(cross,size);
    	printf("\n Le new min est : %d ",minnew);
			
    	for(i=0;i<size;i++) // retrancher le min from la sous matrice
            {
			  for(j=0;j<size;j++)
            	{
            	  if(cross[i][j]!=-7)
            	    {
				  	  cross[i][j]=cross[i][j]-minnew;	
				  	}
    			}
    		}
    		
    	printf(" \n La matrice aprés retancher est : \n");
        affich_mat(cross,size);	
        
    	printf(" \n La matrice reduite : \n");
        affich_mat(a,size);
        
        printf("************************");
    	for(i=0;i<size;i++)
        {
          printf("| %d ",lg[i]);
           printf("\n");
        }	
        printf("************************");
    	for(j=0;j<size;j++)
        {
          printf("| %d ",ln[j]);
           printf("\n");
        }		
    		
    	for(i=0;i<size;i++)  // ajouter min au inter ligne colomne baree
            {
			  for(j=0;j<size;j++)
            	{
					if(cross[i][j]==-7 && ln[j]==-11  && lg[i]!=-11)
					  {
					  	cross[i][j]=t[i][j]+minnew;
					  }
  				}
    		}
    		
		printf(" \n La nouvelle matrice reduite est : \n");
        for(i=0;i<size;i++) //
        {
            for(j=0;j<size;j++)
            {
                printf("| %d ",cross[i][j]);
            }
            printf("\n");
        }	
		for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
              if(cross[i][j]==-7) 
			    {
			    	cross[i][j]=ad[i][j];
				 } 
            }  
        }	
        
                
		printf(" \n La derniere matrice reduite est : \n");
        affich_mat(cross,size);	
			
			make_mat(t,cross,size);
			make_mat(a,cross,size);
			make_mat(ad,cross,size); 	
			
			
			
			
		for(i=0;i<size;i++)//initialiser conteur 
            {
             	lz[i]=0  ;
            }	
						  	
		//calculating new row zero 
        
        
        for(i=0;i<size;i++)
        {
            
        printf("| %d \n",lz[i]);
            
        }		
        
        //striking lines in row
            
            k=0;
            while(k<size)
            {
			repon3=mark_zero_line(cross,repon3,k,size);
			 k++;	
			}	
			
			for(j=0;j<size;j++)//initialiser conteur 
            {
             	cz[j]=0  ;
            }
					
        //calculating colomn zero
        for(j=0;j<size;j++)
        {
            for(i=0;i<size;i++)
            {
                if(cross[i][j]==0)
                {
                    cz[j]=cz[j]+1;
                }
            }	  
        }
        
        for(j=0;j<size;j++)
        {
            
        printf("| %d \n",cz[j]);
            
        }
        
        //striking lins in colomn
         	m=0;
            while(m<size)
            {
			 mark_zero_col(cross,m,size);
			 m++;	
			}	
     
        
        //calculating no of rows and columns crossed
        l=zero_encadre(cross,size);
		        
        printf("\n Nombre de zero marquee : %d \n",l);
		
		

//**************************************************************************************
        
        //cross matrix
        printf(" \n La matrice de marquage est : \n");
        affich_mat(cross,size);

        
        if (l==size)
        { 	
         costm=tache_affect(cross,cost,size);
        printf("\n Le cout minimum d'affectation est : %d ",costm);
    	}			
			
    	
	

}





}


    	
    	
    	
    	
