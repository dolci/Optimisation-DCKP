
#include<stdio.h>
#include<stdlib.h>
#include "DCKP.c"


int main( int argc,char *argv[]) 
{    
    int i,j,k,obj_in,iter; 
    long start, end; 
    char instance[50]; 
    pdckp pb; 
    soldckp sol; 
    double objval; 
    errno_t err; 
    FILE *ff,*fw;//Flux d'ouverture des fichiers 
    if((err=fopen_s(&ff,"dckp_instances_list.txt","r"))!=0) 
        printf("Erreur d'ouverture du fichier dckp_instances_list.txt...\n"); 
      
    /////// 
    if((err=fopen_s(&fw,"resultsTR.xls","w"))!=0) 
        printf("Erreur d'ouverture du fichier solutions.xls...\n"); 
    else
        fprintf(fw,"INSTANCES\tOBJ_IN\tOBJ_RL\tITER\tCPU\tITEMS\n"); 
    fclose(fw); 
    /////// 
       population *pop;   
    for(k=0;k<16;k++) 
    {    
        printf("\n+-------------------------+-------------------------+-------------------------+\n"); 
        fscanf(ff,"%s",instance); 
        puts(instance); 
          printf( " instance %s ",instance);
        pb=chargement_prob(instance); 
		
		/*for(int i=0;i<50;i++)
		{
		  for(int j=0;j<pb->n;j++)
			  printf( " %d ",pop->tabs[i]->elem[j]);
		  printf( " \n\n obj=%d  v=%d",pop->tabs[i]->objval,pop->tabs[i]->volact);
		  system("pause");
		  
		}*/
		
		
        start=clock();

		pop=build_population(20,pb);
        sol=algo_gen_dckp(pop,pb);
		end=clock();
		printf("sol al %d \n ",sol->objval);
      //  sol=build_init_sol(pb); 
     //   obj_in=sol->objval; 
     //  printf("\nSolution Initiale %d\n", obj_in); 
      // recherche_tabou(sol,pb,&iter);
	 //  printf("sol al taboue %d \n ",sol->objval);
        //display_sol(sol,dckp); 
         
          // printf("RT =%d\n",sol->objval); 
        printf("CPU=%.3lf\n",(double)(end-start)/1000); 
      system("pause");
   if((err=fopen_s(&fw,"results_RT.xls","a+"))!=0) 
           printf("Erreur d'ouverture du fichier solutions.xls...\n"); 
          
      fprintf(fw,"%s\t%d \t%.3lf\t \n",instance,sol->objval,(double)(end-start)/1000); 
       /* for(i=0;i<pb->n;i++) 
            if(sol->elem[i]==1) 
                fprintf(fw,"%d\t",i); */
        fprintf(fw,"\n"); 
        fclose(fw); 
  
        desallouer_prob(pb); 
      
    } 
    fclose(ff); 
     system("pause"); 
    return 0;
}