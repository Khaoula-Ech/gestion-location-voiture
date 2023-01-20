#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Client
{
int idClient;
char nom[20];
char prenom[20];
int cin;
char adresse[15];
int telephone;
}Client;

//fontion Saisie_client() permet de faire entrer et enregistrer les infos des clients dans le fichier

void Saisie_client()
 {
 	FILE *f;
 	int i,n;
 	Client c;
 	
 	 printf("Entrer le nombre de clients:");
 	 scanf("%d",&n);
 	 f=fopen("client.txt","w");


	  for(i=0;i<n;i++)
 	 {  printf("\n client Num %d",i+1);
	   
 	 	printf("\n Entrer l'identifiant du client:");
 	 	scanf("%d",&c.idClient);
 	 	printf("\n Le nom du client:");
		scanf("%s",c.nom);
		printf("\n Le prenom du client:");
		scanf("%s",c.prenom);
		printf("\n Le cin du client:");
		scanf("%d",&c.cin);
	    printf("\n L'adresse du client:");
		scanf("%s",c.adresse);
		printf("\n le telephone du client:");
		scanf("%d",&c.telephone);  
		printf("\n");
		fprintf(f,"%d %s %s %d %s %d \n",c.idClient,c.nom,c.prenom,c.cin,c.adresse,c.telephone);}	 
		fclose(f);}
 	   
 
 //fonction : liste_client permet d'afficher la liste des clients déjà enregistrées dans le fichier Client
 void liste_client()
 {  Client c;
    FILE *liste;
 	liste=fopen("client.txt","r");
 	system("cls");
 	printf("\t\t\t\t**********Liste Des Clients**********\t\t\t\n");
 	printf("\n        Id  |        NOM        |      PRENOM      |    CIN      |      ADRESSE       |   TELEPHONE \n ");
 	printf("     ---------------------------------------------------------------------------------------------------\n");

	if(liste!=NULL) 
	{
        while(fscanf(liste,"%d %s %s %d %s %d ",&c.idClient,c.nom,c.prenom,&c.cin,c.adresse,&c.telephone) != EOF)
		{ printf("\n        %2d  |      %8s     |     %8s     |    %6d   |    %10s      |     %10d     \n",c.idClient,c.nom,c.prenom,c.cin,c.adresse,c.telephone);}	 
		
			}	 }

//fonction : ajout_client() permet d'ajouter une client au fichier client.
void ajout_client()
{ Client new_c,c;
  FILE *p;
  system("cls");
  int test=0;
  
  printf("\n\t\t\t\t\t**********Ajouter un client**********\t\t\t\n");
        printf("\n\t\t\t\t  Veuillez saisir l'identifiant du client a ajouter: ");
 	 	scanf("%d",&new_c.idClient);
 	 	p=fopen("client.txt","r+");

        while(fscanf(p,"%d %s %s %d %s %d ",&c.idClient,c.nom,c.prenom,&c.cin,c.adresse,&c.telephone) != EOF)
        {  if(c.idClient==new_c.idClient) { test++; }}
        if(test==0){
		        printf("\n\t\t\t\t  Veuillez saisir le nom du client a ajouter :");
		        scanf("%s",new_c.nom);
		        printf("\n\t\t\t\t  Veuillez saisir le prenom du client a ajouter:");
		        scanf("%s",new_c.prenom);
		        printf("\n\t\t\t\t  Veuillez saisir le cin du client a ajouter:");
		        scanf("%s",&new_c.cin);
		        printf("\n\t\t\t\t  Veuillez saisir l'adresse du client a ajouter:");
		        scanf("%s",new_c.adresse);
	            printf("\n\t\t\t\t  Veuillez saisir le telephone du client a ajouter:");
		        scanf("%d",&new_c.telephone);
		        
        fprintf(p,"\n%d %s %s %d %s %d ",new_c.idClient,new_c.nom,new_c.prenom,new_c.cin,new_c.adresse,new_c.telephone);
        system("cls");
		printf("\n\n\t\t\t\t\t =======> Ajout En Succes! <=======\n");	
        fclose(p);}
		else { 		        printf("\n\n\t\t\t\t\t =======> client existe deja  ! <======= \n\n"); 		}
		

		}
//fonction : modification_client() permet de modifier une ou plusieurs informations concernants une voiture choisie du fichier voiture.

void modification_client()
{   int choix,test;
    Client newc,c;
    system("cls");
    FILE *ancien,*nouveau;
    ancien=fopen("client.txt","r");
    nouveau=fopen("nouveau_client.txt","w");
    
	printf("\n\t\t\t\t\t********** Modification d'un client**********\n");
    printf("\n\t\t\t Veuillez saisir l'identifiant du client que vous desirez modifier : ");
    scanf("%d",&newc.idClient);
      while(fscanf(ancien,"%d %s %s %d %s %d ",&c.idClient,c.nom,c.prenom,&c.cin,c.adresse,&c.telephone) != EOF)
 	 {   
		if(c.idClient==newc.idClient)
 	       { test=1;
			 printf("\n\t\tQuelle information desirez-vous modifier?\n\n\t\t1-NOM\n\t\t2-PRENOM\n\t\t3-CIN\n\t\t4-ADRESSE\n\t\t5-TELEPHONE\n");
 	         printf("\n\t\t\t\t\t Entrer votre choix : ");
 	         scanf("%d",&choix);
 	         
 	        if(choix==1) {printf("\n\t\t\t    Veuillez saisir le nouveau nom du client : ");
 	                        scanf("%s",newc.nom);
                            fprintf(nouveau,"%d %s %s %d %s %d \n",c.idClient,newc.nom,c.prenom,c.cin,c.adresse,c.telephone);
                            printf("\n\n\t\t\t\t=======> modifications Bien Sauvegardees ! <=======");} 	
         
		     else if(choix==2) {printf("\n\t\t\t    Veuillez saisir le nouveau prenom du client : ");
 	                        scanf("%s",newc.prenom);
                            fprintf(nouveau,"%d %s %s %d %s %d \n",c.idClient,c.nom,newc.prenom,c.cin,c.adresse,c.telephone);
                            printf("\n\n\t\t\t\t=======> modifications Bien Sauvegardees ! <=======");} 	
         
		     else if(choix==3) {printf("\n\t\t\t    Veuillez saisir le nouveau cin du client : ");
 	                        scanf("%d",&newc.cin);
                            fprintf(nouveau,"%d %s %s %d %s %d \n",c.idClient,c.nom,c.prenom,newc.cin,c.adresse,c.telephone);
                            printf("\n\n\t\t\t\t=======> modifications Bien Sauvegardees ! <=======");} 	
 	       
 	         else if(choix==4) {printf("\n\t\t\t    Veuillez saisir la nouvelle adresse du client : ");
 	                        scanf("%s",newc.adresse);
                            fprintf(nouveau,"%d %s %s %d %s %d \n",c.idClient,c.nom,c.prenom,c.cin,newc.adresse,c.telephone);
                            printf("\n\n\t\t\t\t=======> modifications Bien Sauvegardees ! <=======");} 	
 	       
 	         else if(choix==5) {printf("\n\t\t\t    Veuillez saisir le nouveau telephone du client : ");
 	                        scanf("%d",&newc.telephone);
                            fprintf(nouveau,"%d %s %s %d %s %d \n",c.idClient,c.nom,c.prenom,c.cin,c.adresse,newc.telephone);
                            printf("\n\n\t\t\t\t=======> modifications Bien Sauvegardees ! <=======");} 	
             else if(choix>5) { printf("\n\t\t\t\t=======> SVP choisir autre choix (1-->5)!!! <=======\n\n");}
		    }
            else{  fprintf(nouveau,"%d %s %s %d %s %d \n",c.idClient,c.nom,c.prenom,c.cin,c.adresse,c.telephone);}
           } 
    fclose(ancien);
    fclose(nouveau);
    remove("client.txt");
	rename("nouveau_client.txt","client.txt");

    if(test!=1)
      { printf("\n\n\t\t\t\t\t =======> Client introuvable !!! <======= \n\n");  }

}
//fonction : suppression_client() permet de supprimer un client choisi du fichier client.

void suppression_client()
{   int choix,test=0;
    Client csupr,c;
    system("cls");
	FILE *ancien,*nouveau;
	ancien=fopen("client.txt","r");
    nouveau=fopen("nouveau_client.txt","w");
    
	printf("\n\t\t\t\t\t********** Suppression d'un client**********\n");
    printf("\n\t\t\t    Veuillez saisir l'identifiant du client que vous desirez supprimer : ");
    scanf("%d",&csupr.idClient);
    
      while(fscanf(ancien,"%d %s %s %d %s %d ",&c.idClient,c.nom,c.prenom,&c.cin,c.adresse,&c.telephone) != EOF)
 	 {   
		if(c.idClient!=csupr.idClient)
 	       { fprintf(nouveau,"%d %s %s %d %s %d \n",c.idClient,c.nom,c.prenom,c.cin,c.adresse,c.telephone);	} 
		else{ test++;
		      printf("\n\n\t\t\t\t\t =======> Client Bien supprimee ! <=======");
			  }}
         
	fclose(ancien);
    fclose(nouveau);
    remove("client.txt");
    rename("nouveau_client.txt","client.txt");
    if(test==0)
      { printf("\n\n\t\t\t\t\t =======>  Client introuvable !!! <======= ");}

}

	void main()
	{ 
	  
	  
	  modification_client();
	}
