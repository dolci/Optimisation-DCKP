#include<stdio.h>
#include<stdlib.h>
#include"DCKP.h"
#include <time.h>

void recherche_tabouBD(soldckp s,pdckp pb)
{
	
	int i,j,k,m;
	int nbre,nbre0;
	int nbre_iter=0;
	int max_taille,taille;
	int obj,volume,objT,objV,volumeV,volumeT,tmp;
	int indice[2][2];
	int **liste_taboue;
	soldckp fs,bs,bns; 
   
    nbre=nbre0=0;
	objV=volume=tmp=nbre=0;
	objT=0;
	volumeT=0;
	
	max_taille=10;
	taille=0;
	liste_taboue=(int**)malloc(sizeof(int*)*max_taille);
    for(i=0; i<max_taille; i++)
 				 liste_taboue[i]=(int*) malloc (sizeof(int)*5);
	  for(i=0; i<max_taille; i++)
		    for(j=0; j<4; j++)
				liste_taboue[i][j]=15;
	fs=build_empty_sol(pb);
	bns=build_empty_sol(pb);
	bs=build_empty_sol(pb);
	copy_sol(s,bs,pb);
	copy_sol(s,bns,pb);
	bns->objval=0;
	do{ 
		 indice[0][0]=indice[0][1]=indice[1][0]=indice[1][1]=-1;
		nbre_iter++;nbre=0;
		for(i=0;i<pb->n-1;i++)
			{				 
				for(j=0;j<pb->n-1;j++)
				{ 
					if(j!=i &&j!=i+1)
					{
				       
						  if(s->elem[i]==1 && s->elem[i+1]==1 && s->elem[j]==0 && s->elem[j+1]==0  && s->volact - pb->v[i]-pb->v[i+1] +  pb->v[j+1]+pb->v[j] <= pb->C  ) 
						 {
							
								if( test_compTB(pb,s,j,j+1,i,i+1)==0 && test_compTB(pb,s,j+1,j,i,i+1)==0 && verifie_listetabou(liste_taboue,&taille,i,j+1,i+1,j)==0)
								{
								      
									if(s->objval - pb->p[i]-pb->p[i+1]+pb->p[j+1] + pb->p[j] >=bns->objval)
									{
										//if((*nbre_iter)==2)
									//	printf("solutionaaaaa=%d %d\n",s->objval,bns->objval);
									  bns->objval=s->objval -pb->p[i]-pb->p[i+1]+pb->p[j+1] + pb->p[j];
									  bns->volact=s->volact - pb->v[i]-pb->v[i+1] +  pb->v[j+1]+pb->v[j];
									  indice[0][0]=i;indice[0][1]=j+1;
									  indice[1][0]=i+1;;indice[1][1]=j;
									  nbre++;
									 
									}
									
					
								}
						  }
					  else  if(s->elem[i]==1 && s->elem[i+1]==0 && s->elem[j]==1 && s->elem[j+1]==0  && s->volact - pb->v[i]-pb->v[j] +  pb->v[j+1]+pb->v[i+1] <= pb->C ) 
						 {
						 //	printf("verife %d \n",verifie_listetabou(liste_taboue,taille,i,j+1,i+1,j));
								if( test_compTB(pb,s,i+1,j+1,i,j)==0 && test_compTB(pb,s,j+1,i+1,i,i+1)==0 && verifie_listetabou(liste_taboue,&taille,i,j+1,i+1,j)==0)
								{
									
									if(s->objval - pb->p[i]-pb->p[j]+pb->p[j+1] + pb->p[i+1] >=bns->objval)
									{
										//if((*nbre_iter)==2)
										//	printf("solutionaaaaa=%d %d\n",s->objval,bns->objval);
									   bns->objval=s->objval - pb->p[i]-pb->p[j]+pb->p[j+1] + pb->p[i+1];
								       bns->volact= s->volact - pb->v[i]-pb->v[j] +  pb->v[j+1]+pb->v[i+1];
									   indice[0][0]=i;indice[0][1]=j+1;
								       indice[1][0]=j;indice[1][1]=i+1;
									   nbre++;
									  
									}
									
									
								}
						  }
					      else  if(s->elem[i]==1 && s->elem[i+1]==0 && s->elem[j]==0 && s->elem[j+1]==1  && s->volact -pb->v[i]-pb->v[j+1] +  pb->v[j]+pb->v[i+1] <= pb->C ) 
						 {//printf("verife %d \n",verifie_listetabou(liste_taboue,taille,i,j+1,i+1,j));
								if( test_compTB(pb,s,i+1,j,j+1,i)==0 && test_compTB(pb,s,j,i+1,i,i+1)==0 && verifie_listetabou(liste_taboue,&taille,i,j+1,i+1,j)==0)
								{
									
									if(s->objval - pb->p[i]-pb->p[j+1]+pb->p[j] + pb->p[i+1] >=bns->objval)
									{
										//if((*nbre_iter)==2)
										//	printf("solutionaaaaa=%d %d\n",s->objval,bns->objval);
									   bns->objval=s->objval - pb->p[i]-pb->p[j+1]+pb->p[j] + pb->p[i+1];
								       bns->volact= s->volact - pb->v[i]-pb->v[j+1] +  pb->v[j]+pb->v[i+1];
									   indice[0][0]=i;indice[0][1]=i+1;
								       indice[1][0]=j+1;;indice[1][1]=j;
									   nbre++;
									
									}
									

								}
						  }
						 
					  else  if(s->elem[i]==0 && s->elem[i+1]==1 && s->elem[j]==1 && s->elem[j+1]==0  && s->volact -pb->v[i+1]-pb->v[j] +  pb->v[j+1]+pb->v[i] <= pb->C ) 
						 {//printf("verife %d \n",verifie_listetabou(liste_taboue,taille,i,j+1,i+1,j));
								if( test_compTB(pb,s,i,j+1,j,i+1)==0 && test_compTB(pb,s,j+1,i,j,i+1)==0 && verifie_listetabou(liste_taboue,&taille,i,j+1,i+1,j)==0)
								{
									
									if(s->objval - pb->p[i+1]-pb->p[j]+pb->p[j+1] + pb->p[i] >=bns->objval)
									{
										//if((*nbre_iter)==2)
										//	printf("solutionaaaaa=%d %d\n",s->objval,bns->objval);
									   bns->objval=s->objval - pb->p[i+1]-pb->p[j]+pb->p[j+1] + pb->p[i];
								       bns->volact= s->volact -pb->v[i+1]-pb->v[j] +  pb->v[j+1]+pb->v[i] ;
									   indice[0][0]=i;indice[0][1]=i+1;
								       indice[1][0]=j;indice[1][1]=j+1;
									   nbre++;
									
									}
					}

				}

				
			 // system("pause");
				} 
				}}
		//printf("I+%d solution bs =%d\n",(*nbre_iter),bns->objval);
		if(bns->objval>0)
				 { 
					// bns->objval=objT;	
					// bns->volact=volumeT;
					
					 echange(s->elem,indice[0][0],indice[0][1]);
					 echange(s->elem,indice[1][0],indice[1][1]);
					 nbre++;
					 s->objval=bns->objval;
					 s->volact=bns->volact;
					// copy_sol(bns,s,pb);
					 if(taille<max_taille)
					 {
						 
						liste_taboue[taille][0]=indice[0][0];liste_taboue[taille][1]=indice[0][1];
				    	 liste_taboue[taille][2]=indice[1][0];liste_taboue[taille][3]=indice[1][1];
					     taille++;
						//printf(" %d taille %d \n", liste_taboue[0][0],taille);
					 }

				
					
					if(s->objval > bs->objval)
					copy_sol(s,bs,pb); 
				}
		// printf("nb =%d\n",( *nbre_iter));
		 //printf("solution S =%d\n",s->objval);
		  
	            bns->objval=0;
			    objV=volumeV=0;
				
			
	}while(nbre_iter<5);
	copy_sol(bs,s,pb);
	
}
void recherche_tabou(soldckp s,pdckp pb,int * nbre_iter)
{

	int i,j,k,m;
	int nbre,nbre0;
	int max_taille,taille;
	int obj,volume,objT,objV,volumeV,volumeT,tmp;
	int indice[2][2];
	int **liste_taboue;
	soldckp fs,bs,bns; 
   *nbre_iter=0;
    nbre=nbre0=0;
	objV=volume=tmp=nbre=0;
	objT=0;
	volumeT=0;
	
	max_taille=10;
	taille=0;
	liste_taboue=(int**)malloc(sizeof(int*)*max_taille);
    for(i=0; i<max_taille; i++)
 				 liste_taboue[i]=(int*) malloc (sizeof(int)*5);
	  for(i=0; i<max_taille; i++)
		    for(j=0; j<4; j++)
				liste_taboue[i][j]=15;
	fs=build_empty_sol(pb);
	bns=build_empty_sol(pb);
	bs=build_empty_sol(pb);
	copy_sol(s,bs,pb);
	copy_sol(s,bns,pb);
	bns->objval=0;
	do{ 
		 indice[0][0]=indice[0][1]=indice[1][0]=indice[1][1]=-1;
		( *nbre_iter)++;nbre=0;
		for(i=0;i<pb->n-1;i++)
			{				 
				for(j=0;j<pb->n-1;j++)
				{ 
					if(j!=i &&j!=i+1)
					{
				       
						  if(s->elem[i]==1 && s->elem[i+1]==1 && s->elem[j]==0 && s->elem[j+1]==0  && s->volact - pb->v[i]-pb->v[i+1] +  pb->v[j+1]+pb->v[j] <= pb->C  ) 
						 {
							
								if( test_compTB(pb,s,j,j+1,i,i+1)==0 && test_compTB(pb,s,j+1,j,i,i+1)==0 && verifie_listetabou(liste_taboue,&taille,i,j+1,i+1,j)==0)
								{
								      
									if(s->objval - pb->p[i]-pb->p[i+1]+pb->p[j+1] + pb->p[j] >=bns->objval)
									{
										//if((*nbre_iter)==2)
									//	printf("solutionaaaaa=%d %d\n",s->objval,bns->objval);
									  bns->objval=s->objval -pb->p[i]-pb->p[i+1]+pb->p[j+1] + pb->p[j];
									  bns->volact=s->volact - pb->v[i]-pb->v[i+1] +  pb->v[j+1]+pb->v[j];
									  indice[0][0]=i;indice[0][1]=j+1;
									  indice[1][0]=i+1;;indice[1][1]=j;
									  nbre++;
									 
									}
									
					
								}
						  }
					  else  if(s->elem[i]==1 && s->elem[i+1]==0 && s->elem[j]==1 && s->elem[j+1]==0  && s->volact - pb->v[i]-pb->v[j] +  pb->v[j+1]+pb->v[i+1] <= pb->C ) 
						 {
						 //	printf("verife %d \n",verifie_listetabou(liste_taboue,taille,i,j+1,i+1,j));
								if( test_compTB(pb,s,i+1,j+1,i,j)==0 && test_compTB(pb,s,j+1,i+1,i,i+1)==0 && verifie_listetabou(liste_taboue,&taille,i,j+1,i+1,j)==0)
								{
									
									if(s->objval - pb->p[i]-pb->p[j]+pb->p[j+1] + pb->p[i+1] >=bns->objval)
									{
										//if((*nbre_iter)==2)
										//	printf("solutionaaaaa=%d %d\n",s->objval,bns->objval);
									   bns->objval=s->objval - pb->p[i]-pb->p[j]+pb->p[j+1] + pb->p[i+1];
								       bns->volact= s->volact - pb->v[i]-pb->v[j] +  pb->v[j+1]+pb->v[i+1];
									   indice[0][0]=i;indice[0][1]=j+1;
								       indice[1][0]=j;indice[1][1]=i+1;
									   nbre++;
									  
									}
									
									
								}
						  }
					      else  if(s->elem[i]==1 && s->elem[i+1]==0 && s->elem[j]==0 && s->elem[j+1]==1  && s->volact -pb->v[i]-pb->v[j+1] +  pb->v[j]+pb->v[i+1] <= pb->C ) 
						 {//printf("verife %d \n",verifie_listetabou(liste_taboue,taille,i,j+1,i+1,j));
								if( test_compTB(pb,s,i+1,j,j+1,i)==0 && test_compTB(pb,s,j,i+1,i,i+1)==0 && verifie_listetabou(liste_taboue,&taille,i,j+1,i+1,j)==0)
								{
									
									if(s->objval - pb->p[i]-pb->p[j+1]+pb->p[j] + pb->p[i+1] >=bns->objval)
									{
										//if((*nbre_iter)==2)
										//	printf("solutionaaaaa=%d %d\n",s->objval,bns->objval);
									   bns->objval=s->objval - pb->p[i]-pb->p[j+1]+pb->p[j] + pb->p[i+1];
								       bns->volact= s->volact - pb->v[i]-pb->v[j+1] +  pb->v[j]+pb->v[i+1];
									   indice[0][0]=i;indice[0][1]=i+1;
								       indice[1][0]=j+1;;indice[1][1]=j;
									   nbre++;
									
									}
									

								}
						  }
						 
					  else  if(s->elem[i]==0 && s->elem[i+1]==1 && s->elem[j]==1 && s->elem[j+1]==0  && s->volact -pb->v[i+1]-pb->v[j] +  pb->v[j+1]+pb->v[i] <= pb->C ) 
						 {//printf("verife %d \n",verifie_listetabou(liste_taboue,taille,i,j+1,i+1,j));
								if( test_compTB(pb,s,i,j+1,j,i+1)==0 && test_compTB(pb,s,j+1,i,j,i+1)==0 && verifie_listetabou(liste_taboue,&taille,i,j+1,i+1,j)==0)
								{
									
									if(s->objval - pb->p[i+1]-pb->p[j]+pb->p[j+1] + pb->p[i] >=bns->objval)
									{
										//if((*nbre_iter)==2)
										//	printf("solutionaaaaa=%d %d\n",s->objval,bns->objval);
									   bns->objval=s->objval - pb->p[i+1]-pb->p[j]+pb->p[j+1] + pb->p[i];
								       bns->volact= s->volact -pb->v[i+1]-pb->v[j] +  pb->v[j+1]+pb->v[i] ;
									   indice[0][0]=i;indice[0][1]=i+1;
								       indice[1][0]=j;indice[1][1]=j+1;
									   nbre++;
									
									}
					}

				}

				
			 // system("pause");
				} 
				}}
		//printf("I+%d solution bs =%d\n",(*nbre_iter),bns->objval);
		if(bns->objval>0)
				 { 
					// bns->objval=objT;	
					// bns->volact=volumeT;
					
					 echange(s->elem,indice[0][0],indice[0][1]);
					 echange(s->elem,indice[1][0],indice[1][1]);
					 nbre++;
					 s->objval=bns->objval;
					 s->volact=bns->volact;
					// copy_sol(bns,s,pb);
					 if(taille<max_taille)
					 {
						 
						liste_taboue[taille][0]=indice[0][0];liste_taboue[taille][1]=indice[0][1];
				    	 liste_taboue[taille][2]=indice[1][0];liste_taboue[taille][3]=indice[1][1];
					     taille++;
						//printf(" %d taille %d \n", liste_taboue[0][0],taille);
					 }

				//intensification1(s,pb);
				   recherche_local(s,pb);
					// intensifier_solution(s,pb);
					if(nbre>nbre0)
					{nbre0=nbre;
					copy_sol(s,fs,pb);
					}
					if(nbre==0 && ( *nbre_iter)==28)
					{
						diversification(s,pb);
						printf(" difee %d \n",s->objval);
						intensification1(s,pb);
					}
					if(( *nbre_iter)==25)
					{intensifier_solution(fs,pb);  recherche_local(fs,pb);copy_sol(fs,s,pb);}
					if(s->objval > bs->objval)
					copy_sol(s,bs,pb); 
				}
		// printf("nb =%d\n",( *nbre_iter));
		 //printf("solution S =%d\n",s->objval);
		  
	            bns->objval=0;
			    objV=volumeV=0;
				
			
	}while(( *nbre_iter)<30);
	copy_sol(bs,s,pb);
	//system("pause");
}
void diversification(soldckp s,pdckp pb)
{
	int i,j;
	s->objval=0;s->volact;
	for(i=0;i<s->n;i++)
		if(s->elem[i]==1 &&pb->cp[i][0]>0)
		{
			s->elem[i]=1;
			s->volact+=pb->v[i];
			s->objval+=pb->p[i];
	    }
		else s->elem[i]=0;
		
		// Test de incompatibilite capacité
		for(i=0;i<pb->n;i++)
		{
		if(s->elem[i]==1&&test_comptBasique (pb,s,i)==1)
		   {
			   s->elem[i]=0;
			   s->objval-=pb->p[i];
			   s->volact-=pb->v[i];
		   }
		}
		if(s->volact >pb->C)
		{
			do
			{ j=rand()%s->n;
				if (s->elem[j]==1)
                   {s->elem[j]=0;
			        s->objval-=pb->p[i];
					s->volact-=pb->v[i];
				}
			}while(s->volact>pb->C);
		}


}
void recherche_local(soldckp s,pdckp pb)
{
    int objT,nbre_iter;
	int volume;
    int i, j, bi, bj, k;    
    nbre_iter=0; 
	
    do
    { 
        nbre_iter++; 
        bi=bj=-1;
		objT=s->objval;
		
        for(i=0;i<pb->n-1;i++) 
        { 
            for(j=i+1;j<pb->n;j++) 
            { 
				
                if(s->elem[i]==1 && s->elem[j]==0  && s->volact - pb->v[i] + pb->v[j] <= pb->C  
                    && s->objval - pb->p[i] + pb->p[j] >objT && test_compt(pb,s,j,i)==0) 
                { 
					
                        volume =s->volact - pb->v[i] + pb->v[j]; 
                        objT = s->objval - pb->p[i] + pb->p[j];// printf("obj0=%d  ",objT);system("pause");
                        bi = i; 
                        bj = j; 
                    
                } 
                else if(s->elem[i]==0 && s->elem[j]==1  && s->volact +pb->v[i] - pb->v[j] <= pb->C  
                    && s->objval + pb->p[i] - pb->p[j] >objT && test_compt(pb,s,i,j)==0) 
                { 
                        volume = s->volact + pb->v[i] - pb->v[j]; 
                        objT = s->objval + pb->p[i] -pb->p[j] ;// printf("obj1=%d  ",objT);system("pause");
                        bi = i; 
                        bj = j;
                   
                } 
            } 
        } 
        if(bi>=0) 
        { 
            if(s->elem[bi]==1 && s->elem[bj]==0) 
            { 
                 s->elem[bi]=0; 
                 s->elem[bj]=1; 
            } 
            else
            { 
                 s->elem[bi]=1; 
                 s->elem[bj]=0; 
            } 
            s->objval=objT; 
            s->volact=volume; 
			//printf("objt %d \n",objT);
            //copy_sol(bs,sol,pb); 
        } 
		
  
    }while(nbre_iter==4); 
 
}
void intensifier_solution(soldckp s,pdckp pb)
{
	int i,j,k,m;
	int nbre,nbre0;
	int max_taille,taille;
	int obj,volume,objT,objV,volumeV,volumeT,tmp;
	int indice[2][2];
	int **liste_taboue;
	soldckp fs,bs,bns; 
  // *nbre_iter=0;
    nbre=nbre0=0;
	objV=volume=tmp=nbre=0;
	objT=0;
	volumeT=0;
	
	max_taille=10;
	taille=0;
	liste_taboue=(int**)malloc(sizeof(int*)*max_taille);
    for(i=0; i<max_taille; i++)
 				 liste_taboue[i]=(int*) malloc (sizeof(int)*5);
	  for(i=0; i<max_taille; i++)
		    for(j=0; j<4; j++)
				liste_taboue[i][j]=15;
	fs=build_empty_sol(pb);
	bns=build_empty_sol(pb);
	bs=build_empty_sol(pb);
	copy_sol(s,bs,pb);
	copy_sol(s,bns,pb);
	bns->objval=0;
  /*for(i=1;i<pb->n-3;i++)
	{for(j=3;j<pb->n-1;j++)
				{ 
				
				if(s->elem[i-1]==1&&s->elem[i+1]==1&&s->elem[j]==1 && s->elem[i]==s->elem[j-1]==s->elem[j+1]==0 &&
							s->volact- pb->v[i-1]-pb->v[i+1]-pb->v[j] + pb->v[j+1]+pb->v[j-1]+pb->v[i] <= pb->C)
				{ 
							 tab[0]=i-1;tab[1]=i+1;tab[2]=j;tab[3]=i;tab[4]=j+1;tab[5]=j-1;
			      if( test_compatibilite(pb,s,tab)==0 && s->objval -pb->p[i-1]-pb->p[i+1]-pb->p[j]+pb->p[j+1] + pb->p[j-1]+pb->p[i]>objT )
					//	if(test_compt(pb,s,i,j-1)==0&&test_compt(pb,s,i,j+1)==0&&test_compt(pb,s,j-1,i)==0&&test_compt(pb,s,j-1,j+1)==0 &&test_compt(pb,s,j+1,j-1)==0&&test_compt(pb,s,j+1,i)==0)
								{
									  objT=s->objval -pb->p[i-1]-pb->p[i+1]-pb->p[j]+pb->p[j+1] + pb->p[j-1]+pb->p[i];
									  volumeT=s->volact- pb->v[i-1]-pb->v[i+1]-pb->v[j] + pb->v[j+1]+pb->v[j-1]+pb->v[i];
									  /*printf("%d obj =%d vol=%d vt=%d %d %d %d %d %d %d  \n %d %d  ",test_compatibilite(pb,s,tab),objT,volumeT,s->volact,pb->v[i-1],pb->v[i+1],pb->v[j] , pb->v[j+1],pb->v[j-1],pb->v[i]);
								system("pause");
									  indice[0][0]=i-1;indice[0][1]=i;
									  indice[1][0]=i+1;;indice[1][1]=j-1;
									   indice[2][0]=j;indice[2][1]=j+1;									 
							
								}
						  } 
				else if(s->elem[i-1]==s->elem[i+1]==s->elem[i]==1 && s->elem[j]==s->elem[j-1]==s->elem[j+1]==0 && s->volact- pb->v[i-1]-pb->v[i+1]-pb->v[i] + pb->v[j+1]+pb->v[j-1]+pb->v[j] <= pb->C )
						 {tab[0]=i-1;tab[1]=i+1;tab[2]=i;tab[3]=j;tab[4]=j+1;tab[5]=j-1;
								if( test_compatibilite(pb,s,tab)==0 && s->objval -pb->p[i-1]-pb->p[i+1]-pb->p[i]+pb->p[j+1] + pb->p[j-1]+pb->p[j]>objT)
								
			//	if(test_compt(pb,s,j,j-1)==0&&test_compt(pb,s,j,j+1)==0&&test_compt(pb,s,j-1,j)==0&&test_compt(pb,s,j-1,j+1)==0 &&test_compt(pb,s,j+1,j-1)==0&&test_compt(pb,s,j+1,j)==0)
				{
									  objT=s->objval -pb->p[i-1]-pb->p[i+1]-pb->p[i]+pb->p[j+1] + pb->p[j-1]+pb->p[j];
									  volumeT=s->volact- pb->v[i-1]-pb->v[i+1]-pb->v[i] + pb->v[j+1]+pb->v[j-1]+pb->v[j];
									  indice[0][0]=i-1;indice[0][1]=j;
									  indice[1][0]=i+1;;indice[1][1]=j-1;
									   indice[2][0]=i;indice[2][1]=j+1;									 
							
								}
						  } 
			  }
 
  }
  */
	for(i=0;i<pb->n-1;i++)
			{				 
				for(j=0;j<pb->n-1;j++)
				{ 
					if(j!=i &&j!=i+1)
					{
				       
						  if(s->elem[i]==0 && s->elem[i+1]==0 && s->elem[j]==1 && s->elem[j+1]==1  && s->volact + pb->v[i]+pb->v[i+1] -pb->v[j+1]-pb->v[j] <= pb->C  ) 
						 {
							
								if( test_compTB(pb,s,i,i+1,j,j+i)==0 && test_compTB(pb,s,i+1,i,j,j+1)==0 && verifie_listetabou(liste_taboue,&taille,i,j+1,i+1,j)==0)
								{
								      
									if(s->objval + pb->p[i]+pb->p[i+1]-pb->p[j+1] - pb->p[j] >=bns->objval)
									{
										//if((*nbre_iter)==2)
									//	printf("solutionaaaaa=%d %d\n",s->objval,bns->objval);
									  bns->objval=s->objval + pb->p[i]+pb->p[i+1]-pb->p[j+1] - pb->p[j];
									  bns->volact= s->volact + pb->v[i]+pb->v[i+1] -pb->v[j+1]-pb->v[j];
									  indice[0][0]=i;indice[0][1]=j+1;
									  indice[1][0]=i+1;indice[1][1]=j;
									  nbre++;
									 
									}
									
					
								}
						  }
						  else if(s->elem[i]==1 && s->elem[i+1]==1 && s->elem[j]==0 && s->elem[j+1]==0  && s->volact - pb->v[i]-pb->v[i+1] +  pb->v[j+1]+pb->v[j] <= pb->C  ) 
						 {
							
								if( test_compTB(pb,s,j,j+1,i,i+1)==0 && test_compTB(pb,s,j+1,j,i,i+1)==0 && verifie_listetabou(liste_taboue,&taille,i,j+1,i+1,j)==0)
								{
								      
									if(s->objval - pb->p[i]-pb->p[i+1]+pb->p[j+1] + pb->p[j] >=bns->objval)
									{
										//if((*nbre_iter)==2)
									//	printf("solutionaaaaa=%d %d\n",s->objval,bns->objval);
									  bns->objval=s->objval -pb->p[i]-pb->p[i+1]+pb->p[j+1] + pb->p[j];
									  bns->volact=s->volact - pb->v[i]-pb->v[i+1] +  pb->v[j+1]+pb->v[j];
									  indice[0][0]=i;indice[0][1]=j;
									  indice[1][0]=i+1;;indice[1][1]=j+1;
									  nbre++;
									 
									}
									
					
								}
						  }
					  else  if(s->elem[i]==1 && s->elem[i+1]==0 && s->elem[j]==1 && s->elem[j+1]==0  && s->volact - pb->v[i]-pb->v[j] +  pb->v[j+1]+pb->v[i+1] <= pb->C ) 
						 {
						 //	printf("verife %d \n",verifie_listetabou(liste_taboue,taille,i,j+1,i+1,j));
								if( test_compTB(pb,s,i+1,j+1,i,j)==0 && test_compTB(pb,s,j+1,i+1,i,i+1)==0 && verifie_listetabou(liste_taboue,&taille,i,j+1,i+1,j)==0)
								{
									
									if(s->objval - pb->p[i]-pb->p[j]+pb->p[j+1] + pb->p[i+1] >=bns->objval)
									{
										//if((*nbre_iter)==2)
										//	printf("solutionaaaaa=%d %d\n",s->objval,bns->objval);
									   bns->objval=s->objval - pb->p[i]-pb->p[j]+pb->p[j+1] + pb->p[i+1];
								       bns->volact= s->volact - pb->v[i]-pb->v[j] +  pb->v[j+1]+pb->v[i+1];
									   indice[0][0]=i;indice[0][1]=i+1;
								       indice[1][0]=j;indice[1][1]=j+1;
									   nbre++;
									  
									}
									
									
								}
						  }
					      else  if(s->elem[i]==1 && s->elem[i+1]==0 && s->elem[j]==0 && s->elem[j+1]==1  && s->volact -pb->v[i]-pb->v[j+1] +  pb->v[j]+pb->v[i+1] <= pb->C ) 
						 {//printf("verife %d \n",verifie_listetabou(liste_taboue,taille,i,j+1,i+1,j));
								if( test_compTB(pb,s,i+1,j,j+1,i)==0 && test_compTB(pb,s,j,i+1,i,i+1)==0 && verifie_listetabou(liste_taboue,&taille,i,j+1,i+1,j)==0)
								{
									
									if(s->objval - pb->p[i]-pb->p[j+1]+pb->p[j] + pb->p[i+1] >=bns->objval)
									{
										//if((*nbre_iter)==2)
										//	printf("solutionaaaaa=%d %d\n",s->objval,bns->objval);
									   bns->objval=s->objval - pb->p[i]-pb->p[j+1]+pb->p[j] + pb->p[i+1];
								       bns->volact= s->volact - pb->v[i]-pb->v[j+1] +  pb->v[j]+pb->v[i+1];
									   indice[0][0]=i;indice[0][1]=i+1;
								       indice[1][0]=j+1;;indice[1][1]=j;
									   nbre++;
									
									}
									

								}
						  }
						 
					  else  if(s->elem[i]==0 && s->elem[i+1]==1 && s->elem[j]==1 && s->elem[j+1]==0  && s->volact -pb->v[i+1]-pb->v[j] +  pb->v[j+1]+pb->v[i] <= pb->C ) 
						 {//printf("verife %d \n",verifie_listetabou(liste_taboue,taille,i,j+1,i+1,j));
								if( test_compTB(pb,s,i,j+1,j,i+1)==0 && test_compTB(pb,s,j+1,i,j,i+1)==0 && verifie_listetabou(liste_taboue,&taille,i,j+1,i+1,j)==0)
								{
									
									if(s->objval - pb->p[i+1]-pb->p[j]+pb->p[j+1] + pb->p[i] >=bns->objval)
									{
										//if((*nbre_iter)==2)
										//	printf("solutionaaaaa=%d %d\n",s->objval,bns->objval);
									   bns->objval=s->objval - pb->p[i+1]-pb->p[j]+pb->p[j+1] + pb->p[i];
								       bns->volact= s->volact -pb->v[i+1]-pb->v[j] +  pb->v[j+1]+pb->v[i] ;
									   indice[0][0]=i;indice[0][1]=i+1;
								       indice[1][0]=j;indice[1][1]=j+1;
									   nbre++;
									
									}
					}

				}

				
			 // system("pause");
				} 
				}}
	if(objT>s->objval && volumeT<=pb->C)
				 { 
					 s->objval=objT;	
					 s->volact=volumeT;
					  echange(s->elem,indice[0][0],indice[0][1]);
					  echange(s->elem,indice[1][0],indice[1][1]);
					  echange(s->elem,indice[2][0],indice[2][1]);
				printf("inte %d ",s->objval);
				}

}
void intensification1(soldckp s, pdckp pb )
{
	int i,k,j;	
	//printf("val sol%d %d\n ",sol_tmp->objval,sol_tmp->volact);
	for(i=0;i<pb->n;i++)
	{
		if (s->elem[i]==0 && test_comptBasique(pb,s,i)==0&& s->volact+pb->v[i]<=pb->C)
		{
		    s->elem[i]=1;
			s->objval+=pb->p[i];
			s->volact+=pb->v[i];
		}
	}
	
	
}
int verifie_listetabou(int**l,int *taille,int a,int b , int c, int d)
{ 
	
	int i;
	int m;
	if(*taille==0)
		return 0;
	else
	{	for(i=0;i<*taille;i++)
		{
			  if(l[i][0]==0) 
		{
		 for(m=0;m<*taille-1;m++)
						 {
							l[m][0]=l[m+1][0];l[m][1]=l[m+1][1];
						    l[m][2]=l[m+1][2];l[m][3]=l[m+1][3];
						 }
		( *taille)--;
		}
			if((l[i][1]==a && l[i][2]==b && l[i][3]==c && l[i][4]==d)||
				(l[i][1]==b && l[i][2]==a && l[i][3]==d && l[i][4]==c))
			{   l[i][0]--;
				return l[i][0]--;
			}

		}
	  
	return 0;}
}
int test_compt(pdckp pb,soldckp s,int bi,int bj)
{int j;
   
    if (pb->cp[bi][0]==0)
		return 0;
	else
	{
	 for(j=1;j<=pb->cp[bi][0];j++)
	        if(s->elem[pb->cp[bi][j]]==1 && pb->cp[bi][j]!=bj)
			   return 1;
		return 0;	
	}

}
int test_comptBasique(pdckp pb,soldckp s,int bi)
{int j;
   
    if (pb->cp[bi][0]==0)
		return 0;
	else
	{
	 for(j=1;j<=pb->cp[bi][0];j++)
	        if(s->elem[pb->cp[bi][j]]==1)
			   return 1;
		return 0;	
	}

}

int test_compTB(pdckp pb,soldckp s, int a,int b,int c, int d)
{
	int i;
	if(pb->cp[a][0]>0)
	{
	 for(i=0;i<=pb->cp[a][0];i++)
		 if((s->elem[pb->cp[a][i]]==1 && pb->cp[a][i]!=c && pb->cp[a][i]!=d )|| pb->cp[a][i]==b)
			   return 1;
	}
	if(pb->cp[b][0]>0)
	{
	 for(i=0;i<=pb->cp[b][0];i++)
		 if(s->elem[pb->cp[b][i]]==1 && pb->cp[b][i]!=c && pb->cp[b][i]!=d || pb->cp[b][i]==a)
			   return 1;
	}

 return 0;
}
int test_compatibilite(pdckp pb,soldckp s,int tab[])
 {int i,j,k;
   int *elem;

   elem=(int*)malloc(sizeof(int)*pb->n);
   for(k=0;k<pb->n;k++)
	   elem[k]=s->elem[k];
   elem[tab[0]]=0;elem[tab[1]]=0;elem[tab[2]]=0;
   elem[tab[3]]=1;elem[tab[4]]=1;elem[tab[5]]=1;
  
   
   for(i=3;i<6;i++)
   {
	   //printf("pb %d ",tab[i]);system("pause");
	 if(pb->cp[tab[i]][0]>0)
	 {  for(j=1;j<=pb->cp[tab[i]][0];j++)
	     {   if (elem[pb->cp[tab[i]][j]]==1 /*&& pb->cp[tab[i]][j]!=tab[0]&&pb->cp[tab[i]][j]!=tab[1]&&pb->cp[tab[i]][j]!=tab[2]*/)
				return 1;
		   // if(	pb->cp[tab[i]][j]==tab[3] || pb->cp[tab[i]][j]==tab[4] || pb->cp[tab[i]][j]==tab[5])
				//return 1;
	   }
	 }

  
   }
   
   return 0;
}
soldckp  build_init_sol(pdckp pb)
{
	int i,j,k;
	soldckp s;int *tab;
	s=build_empty_sol(pb);
	
	
	pb->tabindice=(int*)malloc(pb->n*sizeof(int));
	tab=(int*)malloc(pb->n*sizeof(int));
	for(i=0;i<pb->n;i++)
	{pb->tabindice[i]=i;}
	
	//tri_rapide_bis(pb->v,pb->p,pb->tabindice,0,pb->n-1);
	//for(i=0;i<pb->n;i++)
	//	printf("-%d  ",pb->tabindice[i]);
	//tri_rapide_bis(pb->v,tab,pb->tabindice,0,pb->n-1);
	for(i=0;i<pb->n;i++) 
        tab[i]=i; 
    for(i=0;i<pb->n-1;i++) 
        for(j=i+1;j<pb->n;j++) 
            if((float)pb->v[tab[i]]/pb->p[tab[i]]>(float)pb->v[tab[j]]/pb->p[tab[j]]) 
            { 
                k=tab[i]; 
                tab[i]=tab[j]; 
                tab[j]=k; 
            }
			
	 i=0; 
    while(i <pb->n && s->volact+pb->v[tab[i]]<=pb->C) 
    { 
        for(j=0;j<pb->n;j++) 
        { 
            if(s->elem[j]==1 && pb->cp1[tab[i]][j]==1) 
                break; 
        } 
        if(j==pb->n) 
        { 
            s->elem[tab[i]]=1; 
            s->volact+=pb->v[tab[i]]; 
            s->objval+=pb->p[tab[i]]; 
        } 
        i++; 
    } 
	//system("pause");
	free(tab);
	return s;
}
void copy_sol(soldckp s1, soldckp s2, pdckp pb)
{
	int i;
	for(i=0;i<pb->n;i++)
		s2->elem[i]=s1->elem[i];
	s2->objval=s1->objval;
	s2->volact=s1->volact;
}
soldckp  build_empty_sol(pdckp pb)
{
	int i;
	soldckp s;
	s=(struct solution *)malloc(sizeof( struct solution));
	s->elem=(int*)malloc(pb->n*sizeof(int));
	s->n=pb->n;
	for(i=0;i<pb->n;i++)
		s->elem[i]=0;
	s->objval=s->volact=0;
	return s;	
}
pdckp chargement_prob(char* fichier)
{
	int i,j,k,indice1,indice2;
    pdckp pb;
    FILE *fp;
    errno_t err;

	if((err=fopen_s(&fp,fichier,"r"))!=0)
		printf("Erreur d'ouverture du fichier %s...\n", fichier);

	pb=(struct probleme *)malloc(sizeof( struct probleme));

	
	fscanf(fp,"%d %d",&pb->n,&pb->nc);
  
		
	pb->v= (int*)malloc(pb->n * sizeof(int));
	pb->p= (int*)malloc(pb->n * sizeof(int));
	pb->cp= (int**)malloc(pb->n * sizeof(int*));
	pb->cp1= (int**)malloc(pb->n * sizeof(int*));
	for(i=0;i<pb->n;i++)
		{
			pb->cp[i]=(int*)malloc(pb->n * sizeof(int));
			pb->cp1[i]=(int*)malloc(pb->n * sizeof(int));
	}
	
	for(i=0;i<pb->n;i++)
		for(j=0;j<pb->n;j++)
		{
			pb->cp1[i][j]=0;
			pb->cp[i][j]=0;
	     }

	for(j=0; j<pb->n; j++) 
		fscanf(fp,"%d", &(pb->p[j]));
		
	
	fscanf(fp, "%d", &pb->C);
	
    for(j=0; j<pb->n; j++)
		fscanf(fp, "%d ", &pb->v[j]);

	  for(i=0;i<pb->nc;i++)
			{
				 fscanf(fp,"%d  %d", &indice1,&indice2);
				//
				 pb->cp1[indice1][indice2]=pb->cp1[indice2][indice1]=1;
				if(pb->cp[indice1][0]==0)
				{
				  pb->cp[indice1][1]=indice2;
				  pb->cp[indice1][0]= pb->cp[indice1][0]+1;
				}
				else
				{pb->cp[indice1][pb->cp[indice1][0]+1]=indice2;
				 pb->cp[indice1][0]= pb->cp[indice1][0]+1;
				}
			  if(pb->cp[indice2][0]==0)
				{
				  pb->cp[indice2][1]=indice1;
				   pb->cp[indice2][0]= pb->cp[indice2][0]+1;
				}
				else
                 {pb->cp[indice2][pb->cp[indice2][0]+1]=indice1;pb->cp[indice2][0]= pb->cp[indice2][0]+1;}
			}
		/*for(i=0;i<pb->n;i++)
		{printf("%d  \n",i);
			for(j=0;j<=pb->cp[i][0];j++)
		  printf(" %d  ",pb->cp[i][j]);
		printf("\n");
		system("pause");
		}*/
    fclose(fp);   
    return pb;
}
void echange (int *tab, int i, int j)
{
  int tampon = tab[i];

  tab[i] = tab[j];
  tab[j] = tampon;
 
}
int partition(int tab1[],int tab2[],int tab3[], int deb, int fin)
    {
    int compt=deb;
    float pivot=(float)tab1[deb]/tab2[deb];
    int i;

    for(i=deb+1;i<=fin;i++)
        {
        if((float)tab1[i]/tab2[i]>pivot)
            {
            compt++;
            echange(tab3,compt,i);
            }
        }
    echange(tab3,compt,deb);
    return(compt);
    }
void tri_rapide_bis(int tab1[],int tab2[],int tab3[],int debut,int fin)
    {
    if(debut<fin)
        {
        int pivot=partition(tab1,tab2,tab3,debut,fin);
        tri_rapide_bis(tab1,tab2,tab3,debut,pivot-1);
        tri_rapide_bis(tab1,tab2,tab3,pivot+1,fin);
        }
    }
void desallouer_prob(pdckp pb)
{int i;
	free(pb->v);
	free(pb->p);
	free(pb->tabindice);
	for(i=0;i<pb->n;i++)
		{
			free(pb->cp[i]);
	        free(pb->cp1[i]);
	   }
	free(pb->cp);
	free(pb->cp1);
	//free(pb);
}
void desallouer_sol(soldckp s)
{
	free(s->elem);
	free(s);
}
/*****************************************************/
/* CREATION DE POPULATION DUI SERA CHOISIT AU HASARD */
/*****************************************************/
population * build_population(int n, pdckp pb)
{
	int i, j, k,m, r, s, lim, *t;
	population *pop;
	t=(int*)malloc(pb->n*sizeof(int));

	//Allocation de la mémoire
	pop=(population*)malloc(sizeof( population));
	pop->n=n;
	pop->tabs=(soldckp*)malloc(n*sizeof(soldckp));
	for(i=0;i<n;i++)
		pop->tabs[i]=build_empty_sol(pb);

	//Génération aléatoire des solutions de la population
	for(i=0;i<pop->n;i++)
	{
		for(j=0;j<pb->n;j++)
			t[j]=j;
		k=0;
		lim=pb->n-1;
		r=rand()%(lim+1);
		while(k<pb->n)
		{
			//printf("n=%d\tk=%d\tr=%d\n",pb->n,k,r);
			if(pop->tabs[i]->volact+pb->v[t[r]]<=pb->C)
			{
				
				if( test_comptBasique(pb,pop->tabs[i],t[r])==0)
				
				{
					//printf("%d\t%d\n",pop->tabs[i]->V,pop->tabs[i]->P);
					pop->tabs[i]->elem[t[r]]=1;
					pop->tabs[i]->volact+=pb->v[t[r]];
					pop->tabs[i]->objval+=pb->p[t[r]];
				}
			}
			
			t[r]=t[lim];
			//t[lim]=s;
			lim--;
			k++;
			if(lim>=0)
				r=rand()%(lim+1);
		}
		//display_sol(pop->tabs[i],pb);
		
	}
	//system("pause");
	return pop;
}

soldckp algo_gen_dckp(population *pop, pdckp pb)
{
	int i,k,j,amel,min,m,Pmin,indice,nbre;
	int* masque;
	int *iter;
	soldckp bs,s1,s2;
	population *npop,*npop_int;
	bs=build_empty_sol(pb);
	bs->objval=bs->volact=0;
	s1=build_empty_sol(pb);
	//Allocation de la mémoire pour la nouvelle population
	npop=(population*)malloc(sizeof(population));
	npop_int=(population*)malloc(sizeof(population));
	masque=(int*)malloc(sizeof(int));
	npop->n=pop->n;
	npop_int->n=pop->n;
	npop->tabs=(soldckp*)malloc(pop->n*sizeof(soldckp));
	npop_int->tabs=(soldckp*)malloc(pop->n*sizeof(soldckp));

	for(i=0;i<npop->n;i++)
		{
			npop->tabs[i]=build_empty_sol(pb);
			npop_int->tabs[i]=build_empty_sol(pb);
	   }
	//npop->tabs[npop->n-1]=build_empty_sol(pb);
	//Intialisation de bs
	for(i=0;i<pop->n;i++)
		if(pop->tabs[i]->objval >bs->objval)
			copy_sol(pop->tabs[i],bs,pb);
	// Initialisation de masque 
	for (i = 0; i<pb->n; i++)
		masque[i]=0;
		//allocation du matrice d'incompatibilité de la population
	//	npop->icouples = (int**)malloc(pb->n*sizeof(int*));
		//for (i = 0; i<pb->n; i++)
			//npop->icouples[i] = (int*)malloc(pb->n*sizeof(int));
	//creation du masque pour le croisement
	min=i=m=0;
	 do{
		 indice= min+rand()%(pb->n/5);
		// printf("indice %d ",indice); 
		 if(i%2==0)
		  {
			  for(i=min;i<indice;i++)
			   masque[i]=1;
		  }
		 i++;
		 min=indice;
	 }while(indice<pb->n);
	nbre=0;

	/*for(i=0;i<pb->n;i++)
		printf("%d ",masque[i]);*/

	 //Alogorithme genetique
	do
	{
		nbre++;
		amel=0;
		//printf("AG Iter %d\n",iter);
		//////////////////////////////////////////////////////////////////////////////////
		//Génération de la nouvelle population (croisement)
		//////////////////////////////////////////////////////////////////////////////////
		for(i=0;i<pop->n;i++)
		{
			//////////////////////////////////////////////////////////////////////////////////
			//Coisement de pop->tabs[i] avec pop->tabs[i+1] 
			//pour avoir deux enfants npop->tabs[i] et npop->tabs[i+1]
			//////////////////////////////////////////////////////////////////////////////////
            npop->tabs[i]->objval= npop->tabs[i]->volact  = 0;
			for(k=0;k<pop->n;k++)
	    	{
				if(k!=i)
				{
					 npop_int->tabs[k]->objval= npop_int->tabs[k]->volact  = 0;
					  for(j=0;j<pb->n;j++)
					    {
						   if(masque[j]==1)
						   {
							   npop_int->tabs[k]->elem[j] = pop->tabs[i]->elem[j];
							 //  npop_int->tabs[k]->elem[j] = pop->tabs[k]->elem[j];
						   }
						   else
							    npop_int->tabs[k]->elem[j] = pop->tabs[k]->elem[j];
					   }
				
				//////////////////////////////////////////////////////////////////////////////////
				//Maj des P et V de deux enfants npop->tabs[i] et npop->tabs[i+1]
				//////////////////////////////////////////////////////////////////////////////////
			
				/*	for(j=0;j<pb->n;j++)
					{
						if(npop_int->tabs[k]->elem[j]==1)
						{
							npop_int->tabs[k]->objval+=pb->p[j];
							npop_int->tabs[k]->volact+=pb->v[j];
						}
					
					}*/
			 
			//////////////////////////////////////////////////////////////////////////////////
			//Correction de npop->tabs[i] si c'est necessaire (incompatibilité, capacité)
			//////////////////////////////////////////////////////////////////////////////////

			//Détermination et ellimination des couples incompatible
			
			for(j=0;j<pb->n;j++)
			{
				if(npop_int->tabs[k]->elem[j]==1&& pb->cp[j][0]>0)
				{
				  for(m=1;m<=pb->cp[j][0];m++)
					
						if(npop_int->tabs[k]->elem[m]==1 )
						{
							npop_int->tabs[k]->elem[MIN(j,m)]=0;
							if(MIN(j,m)==j) break;
						}
				}						
			}
					for(j=0;j<pb->n;j++)
					{
						if(npop_int->tabs[k]->elem[j]==1)
						{
							npop_int->tabs[k]->objval+=pb->p[j];
							npop_int->tabs[k]->volact+=pb->v[j];
						}
					
					}
			//Insertion de nouvels objets si npop->tabs[i]->V<pb->C, 
			//Suppression des objets les moin profitables si npop->tabs[i]->V>pb->C
			if(npop_int->tabs[k]->volact<pb->C)
			{
				for(j=0;j<pb->n && npop_int->tabs[k]->volact<pb->C;j++)
				{
					if(npop_int->tabs[k]->elem[j]==0 && npop->tabs[k]->volact+pb->v[j]<=pb->C && test_comptBasique(pb,npop_int->tabs[k],j)==0)
					{
						
							npop_int->tabs[k]->elem[j]=1;
							npop_int->tabs[k]->volact+=pb->v[j];
							npop_int->tabs[k]->objval+=pb->p[j];
					}
					
				}
				
			}
			if(npop_int->tabs[k]->volact>pb->C)
			{  m=0;
				do
				{
					Pmin=MAXN;
					for(j=0;j<pb->n;j++)
					{
						if(npop_int->tabs[k]->elem[j]==1 && pb->p[j]<Pmin)
						{
							Pmin=pb->p[j];
							m=j;
						}
					}
					npop_int->tabs[k]->elem[m]=0;
					npop_int->tabs[k]->volact-=pb->v[m];
					npop_int->tabs[k]->objval-=pb->p[m];
				}
				while(npop_int->tabs[k]->volact>pb->C);
				
			}
		 
				}
				// printf("sol obj %d v%d  | ",npop_int->tabs[k]->objval,npop_int->tabs[k]->volact);
			}
  // *iter=0;
/* for(j=0;j<npop_int->n;j++)
 {  		   
		recherche_tabouBD(npop_int->tabs[j],pb);
		//printf(" sol% d ",npop_int->tabs[j]->objval);
 }*/
	 copy_sol(npop_int->tabs[0],s1,pb);	 
	
       for(j=1;j<npop_int->n;j++)
	   {		   
		   if(npop_int->tabs[j]->objval>s1->objval)
			    copy_sol(npop_int->tabs[j],s1,pb);	   
	   }
	    
	   for(j=0;j<npop_int->n;j++)	
	   {	
	    npop_int->tabs[j]->objval=npop_int->tabs[j]->volact=0;
		for(m=0;m<pb->n;m++)
			npop_int->tabs[j]->elem[m]=0;
	   }
	   recherche_tabouBD(s1,pb);
	   copy_sol(s1,npop->tabs[i],pb);
	   s1=build_empty_sol(pb);
	   }
		
		//////////////////////////////////////////////////////////////////////////////////
		//Selectionner les meilleurs individus et les stocker dans pop
		//////////////////////////////////////////////////////////////////////////////////
		s1==build_empty_sol(pb);
		for(i=0;i<npop->n;i++)
		{indice=0;
			s1=pop->tabs[0];
			for(j=1;j<pop->n;j++)
				if(pop->tabs[j]->objval<s1->objval)
				{s1=pop->tabs[j]; indice=i;}
			
			  if(npop->tabs[i]->objval >s1->objval)		
			copy_sol(npop->tabs[i],pop->tabs[indice],pb);
		}
		//////////////////////////////////////////////////////////////////////////////////
		//Evacuer npop
		//////////////////////////////////////////////////////////////////////////////////
		 for(j=0;j<npop_int->n;j++)	
	   {	
	    npop_int->tabs[j]->objval=npop_int->tabs[j]->volact=0;
		for(m=0;m<pb->n;m++)
			npop_int->tabs[j]->elem[m]=0;
	   }
		//////////////////////////////////////////////////////////////////////////////////
		//Comparer bs par rapport à la nouvelle population et maj de bs si necessaire
		//////////////////////////////////////////////////////////////////////////////////
		for(i=0;i<pop->n;i++)
		{
			if(bs->objval<pop->tabs[i]->objval)
			{
				copy_sol(pop->tabs[i],bs,pb);
				amel=1;
				
			}
		}
	printf(" bset %d ",bs->objval);
	}
	while(nbre<50);
   for(i=0;i<npop->n;i++)
		{
			desallouer_sol(pop->tabs[i]);
			//pop->tabs[i]=build_empty_sol(pb);
		}
	return bs;
}








