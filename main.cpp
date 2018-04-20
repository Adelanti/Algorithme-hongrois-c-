
#include<stdio.h>
#include<conio.h>
#define max 20    
   /*Author : Gamane Adel 
       Date :17/04/18
   */    
   	  	
   
    int main()
    {
	  int tr,size,m,av,i,j,k,r,lg[max],ln[max],lk[max],c,li,co,diff,l=0,lz[max],cz[max],ze[max],zr[max]
        ,a[max][max],t[max][max],ad[max][max],minr[max],minc[max],ct[max][max],minnew;
        int cross[max][max],alloccount=0,minrow,mincol;
        int nbz[max],nrc[max],ncc[max],nl=0;
        int fzr[max][max],fzc[max][max];
        int fz[max][max],flag=0,alloc[max][max];
        int ffz[max][max],fffz[max][max];
        int cost[max][max],costm=0;
      
        //inputting array
        printf("*******************La taille de la matrice******************** \n ");
        printf("Donner le nombre de ligne : ");
        scanf("%d",&r);
        printf("Donner le nombre de colonne : ");
        scanf("%d",&c);
        //inputting array
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {   
			printf("Entrer l'element a[%d][%d] : ",i,j);
            scanf("%d",&a[i][j]);
            }
        }
        if(r!=c)
        {
            if(r>c)
            {
                diff=r-c;
                while(diff!=0)
                {
                    for(i=0;i<r;i++)
                    {
                        a[i][c]=0;
                    }
                    c++;
					diff--;
                }
            }
            if(r<c)
            {
                diff=c-r;
                while(diff!=0)
                {
                    for(i=0;i<c;i++)
                    {
                        a[r][i]=0;
                    }
                    r++;diff--;
                }
            }
        }
        if(r==c)
        {
            size=r;
        }
        //displaying array
        printf(" \n La matrice est : \n");
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                printf("| %d ", a[i][j]);
            }
            printf("\n");
        }
        
        //initializing all matrices
        for(i=0;i<size;i++)
        {
            lz[i]=cz[i]=0;
            nbz[i]=ncc[i]=0;
            for(j=0;j<size;j++)
            {
                fzr[i][j]=fzc[i][j]=fz[i][j]=ffz[i][j]=fffz[i][j]=0;
                alloc[i][j]=0;cost[i][j]=0;
            }
        }
        //making cost matrix
        
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                cost[i][j]=a[i][j];
            }
        }
        //calculating min row
        for(i=0;i<size;i++)
        {
            minr[i]=a[i][0];
            for(j=0;j<size;j++)
            {
                if(minr[i]>a[i][j])
                {
                    minr[i]=a[i][j];
                }
            }
        }
        //subtracting min row from respective row
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                a[i][j]=a[i][j]-minr[i];
            }
        }
        //calculating min column
        for(i=0;i<size;i++)
        {
            minc[i]=a[0][i];
            for(j=0;j<size;j++)
            {
                if(minc[i]>a[j][i])
                {
                    minc[i]=a[j][i];
                }
            }
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
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
            printf("| %d ", a[i][j]);
            }
            printf("\n");
        }
        //copying reduced matrix
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                t[i][j]=a[i][j];
                cross[i][j]=a[i][j];
                ad[i][j]=a[i][j];
                //t[i][j] is row column reduced matrix
     
            }
        }
        //calculating row zero i.e. no of zeros in row
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                if(t[i][j]==0)
                {
                    lz[i]=lz[i]+1;
                    
                } 
				  
            }
        }
            //striking lines in row
            k=0;
            while(k<size)
            {
			  if(lz[k]==1)
			   {
			 	for(j=0;j<size;j++)
			 	 {
			    	if (a[k][j]==0)
			  	     { 
					   co=j;
			  		    a[k][j]=-1 ;
			  	     }
			     }
			  	for(i=0;i<size;i++)
			  	 {
			  	   if (a[i][co]==0)
					{
					  a[i][co]=-2;
					  lz[i]=lz[i]-1;
			  	  	}
			     }
			  }
			   
			 k++;	
			}	
        //calculating colomn zero
        for(j=0;j<size;j++)
        {
            for(i=0;i<size;i++)
            {
                if(a[i][j]==0)
                {
                    cz[j]=cz[j]+1;
                }
            }	  
        }
        //striking lins in colomn
         m=0;
            while(m<size)
            {
			 if(cz[m]==1)
			 {
			 	for(i=0;i<size;i++)
			 	{
			  	 if (a[i][m]==0)
			  	  { 
					li=i;
			  		a[i][m]=-1 ;
			  	  }
			    }
			  	for(j=0;j<size;j++)
			  	{
			  		if (a[li][j]==0)
					{
					  	a[li][j]=-2;
					  	cz[j]=cz[j]-1;
					}
				}	
			 }
			 m++;	
			}	
        
        l=0;    
        //calculating no of rows and columns crossed
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                   if(a[i][j]==-1)
                   {
                    l=l+1;
                   }
            }
        }
        printf("\n Nombre de zero marquee : %d \n",l);
        //cross matrix
        printf(" \n La matrice de marquage est : \n");
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                printf("| %d ",a[i][j]);
            }
            printf("\n");
        }
        if (l==size)
        {
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
        
        printf("\n Le cout minimum d'affectation est : %d ",costm);
    	}
    	
    	if(l!=size)//if no of line striked is not equal to the size
    	{
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
    	  for(i=0;i<size;i++)
            {
              if(nbz[i]==0)
			   {
			   	lg[i]=-11;
			   	printf("\n La ligne %d est marquee ",i);
			   }
			   		
			}
			for(i=0;i<size;i++)
            {
            	printf("\n la valeur de ligne %d est : %d \n",i,lg[i]);
			}
    	  for(j=0;j<size;j++)
            {
             for(i=0;i<size;i++)
               {	
              	 if(a[i][j]==-2 && lg[i]==-11)
				   {
				   	ln[j]=-11;
				   	printf("\n La colomne %d est marquee ",j);
					}	
			   }
    		}
    	  
    	  for(i=0;i<size;i++)
            {
             for(j=0;j<size;j++)
               {	
              	 if(a[i][j]==-1 && ln[j]==-11)
				   {
				   	lg[i]=-11;
				   	printf("\n La ligne %d est marquee ",i);
					}	
			   }
    		}
    	  for(i=0;i<size;i++)
            {
             for(j=0;j<size;j++)
               {	
				cross[i][j]=t[i][j];
						
				}	  
    		}
    	  
    	  
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
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                printf("| %d ",cross[i][j]);
            }
            printf("\n");
        }	
    	 
		 
		  
		minnew=cross[0][0];	// recherche new min    
    	for(i=0;i<size;i++)
            {
			  for(j=0;j<size;j++)
            	{
				  if(cross[i][j] > 0 && cross[i][j] < minnew )
				  	{
				  	  minnew = cross[i][j];
					}
    		    }
    	    }
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
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                printf("| %d ",cross[i][j]);
            }
            printf("\n");
        }		
    	printf(" \n La matrice reduite : \n");
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                printf("| %d ",a[i][j]);
            }
            printf("\n");
        }	
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
    		
    	for(i=0;i<size;i++)
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
        for(i=0;i<size;i++)
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
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                printf("| %d ",cross[i][j]);
            }
            printf("\n");
        }		
			
		for(i=0;i<size;i++)//initialiser conteur 
            {
             	lz[i]=0  ;
            }	
						  	
		//calculating new row zero 
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                if(cross[i][j]==0)
                {
                    lz[i]=lz[i]+1;
                    
                } 	  
            }
        }
        
        for(i=0;i<size;i++)
        {
            
        printf("| %d \n",lz[i]);
            
        }		
        
        
            //striking lines in row
            k=0;
            
            while(k<size)
            {
			  if(lz[k]==1)
			   {
			 	for(j=0;j<size;j++)
			 	 {
			    	if (cross[k][j]==0)
			  	     { 
					   co=j;
			  		    cross[k][j]=-1 ;
			  	     }
			     }
			  	for(i=0;i<size;i++)
			  	 {
			  	   if (cross[i][co]==0)
					{
					  cross[i][co]=-2;
					  lz[i]=lz[i]-1;
			  	  	}
			     }
			  }
			   
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
			 if(cz[m]==1)
			 {
			 	for(i=0;i<size;i++)
			 	{
			  	 if (cross[i][m]==0)
			  	  { 
					li=i;
			  		cross[i][m]=-1 ;
			  	  }
			    }
			  	for(j=0;j<size;j++)
			  	{
			  		if (cross[li][j]==0)
					{
					  	cross[li][j]=-2;
					  	cz[j]=cz[j]-1;
					}
				}	
			 }
			 m++;	
			}	
        
        l=0;    
        //calculating no of rows and columns crossed
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                   if(cross[i][j]==-1)
                   {
                    l=l+1;
                   }
            }
        }
        printf("\n Nombre de zero marquee : %d \n",l);
        //cross matrix
        printf(" \n La matrice de marquage est : \n");
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                printf("| %d ",cross[i][j]);
            }
            printf("\n");
        }
        costm=0;
        if (l==size)
        { 	
         for(i=0;i<size;i++)
            {
                for(j=0;j<size;j++)
                {
                    if(cross[i][j]== -1)
                    {
                          printf("\n La tache %d est affecte a l'agent %d ",i,j);
                          printf("\n");
                          costm=costm+cost[i][j];
                    }
                }
            }
        
        printf("\n Le cout minimum d'affectation est : %d ",costm);
        
    	}			
			
	
	
	
    		
	}
}

    	
    	
    	
    	
    	
