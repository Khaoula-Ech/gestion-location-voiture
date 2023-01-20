#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Voiture
{
int idVoiture;
char marque[15];
char nomVoiture[15];
char couleur[7];
int nbplaces;
int prixJour;
char EnLocation[4];
} Voiture;

//fontion Saisie_voiture() permet de faire entrer et enregistrer les infos des voitures dans le fichier
 void Saisie_voiture()
 {
 	FILE *f;
 	int i,n;
 	Voiture v;
 	
 	 printf("Entrer le nombre de voitures:");
 	 scanf("%d",&n);
 	f=fopen("voiture.txt","w");


	  for(i=0;i<n;i++)
 	 {  printf("\n voiture Num %d",i+1);
	   
 	 	printf("\n Entrer l'identifiant du voiture:");
 	 	scanf("%d",&v.idVoiture);
 	 	printf("\n La marque de la voiture:");
		scanf("%s",v.marque);
		printf("\n Le nom de la voiture:");
		scanf("%s",v.nomVoiture);
		printf("\n La couleur de la voiture:");
		scanf("%s",v.couleur);
		printf("\n le nombre de places de la voiture:");
		scanf("%d",&v.nbplaces);
	    printf("\n Le prix du jour:");
		scanf("%d",&v.prixJour);
		printf("\n la voiture est-elle loue?");
		scanf("%s",v.EnLocation);  
		printf("\n");
		fprintf(f,"%d %s %s %s %d %d %s\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);}	 
		fclose(f);}
 	   
 
 //fonction : liste_voiture permet d'afficher la liste des voitures déjà enregistrées dans le fichier Voiture
 void liste_voiture()
 {  Voiture v;
    FILE *liste;
 	liste=fopen("voiture.txt","r");
 	system("cls");
 	printf("\t\t\t\t**********Liste Des Voitures**********\t\t\t\n");
 	printf("\n        Id  |     MARQUE       |       NOM       |  COULEUR   | NB_PLACES | PRIX_DU_JOUR | EN_LOCATION\n ");
 	printf("\n      ---------------------------------------------------------------------------------------------------\n");

	if(liste!=NULL) 
	{
        while(fscanf(liste,"%d %s %s %s %d %d %s",&v.idVoiture,v.marque,v.nomVoiture,v.couleur,&v.nbplaces,&v.prixJour,v.EnLocation) != EOF)
		{ printf("\n        %2d  |      %7s     |     %7s     |    %5s   |    %d      |     %d      |      %s     \n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);}	 
		
			}	 }
//fonction : ajout_voiture permet d'ajouter une voiture au fichier Voiture//
void ajout_voiture()
{ Voiture new_v,v;
  FILE *p;
  int test=0;
  system("cls");
  printf("\t\t\t\t**********Ajouter une voiture**********\t\t\t\n");
        printf("\n Veillez saisir l'identifiant de la voiture: ");
 	 	scanf("%d",&new_v.idVoiture);
 	 	p=fopen("voiture.txt","r+");

 	 	while(fscanf(p,"%d %s %s %s %d %d %s",&v.idVoiture,v.marque,v.nomVoiture,v.couleur,&v.nbplaces,&v.prixJour,v.EnLocation) != EOF)
        {  if(v.idVoiture==new_v.idVoiture) {
		        printf("\n\n\t\t\t\t =======> voiture deja existee ! <======= \n\n"); 
		        test=1; }}
        if(test==0){
		        printf("\n Veuillez saisir la marque de la voiture:");
		        scanf("%s",new_v.marque);
		        printf("\n Veuillez saisir le nom de la voiture:");
		        scanf("%s",new_v.nomVoiture);
		        printf("\n Veuillez saisir la couleur de la voiture:");
		        scanf("%s",new_v.couleur);
		        printf("\n Veuillez saisir le nombre de places de la voiture:");
		        scanf("%d",&new_v.nbplaces);
	            printf("\n Veuillez saisir le prix du jour:");
		        scanf("%d",&new_v.prixJour);
		        printf("\n la voiture est-elle louee?");
		        scanf("%s",new_v.EnLocation);  
		        printf("\n");
        fprintf(p,"\n%d %s %s %s %d %d %s",new_v.idVoiture,new_v.marque,new_v.nomVoiture,new_v.couleur,new_v.nbplaces,new_v.prixJour,new_v.EnLocation);
        system("cls");
		printf("\n\n\t\t\t\t =======> Ajout En Succes! <=======\n");	

		fclose(p);}
		}

void modification_voiture()
{   int choix,test;
   Voiture newv,v;
	FILE *ancien,*nouveau;
	system("cls");
    ancien=fopen("voiture.txt","r");
    nouveau=fopen("nouveau_voiture.txt","w");
    
	printf("\t\t\t\t********** Modification d'une voiture**********\n");
    printf("\n\t\t\t Veuillez saisir l'identifiant de la voiture que vous desirez modifier : ");
    scanf("%d",&newv.idVoiture);
 	while(fscanf(ancien,"%d %s %s %s %d %d %s",&v.idVoiture,v.marque,v.nomVoiture,v.couleur,&v.nbplaces,&v.prixJour,v.EnLocation)!= EOF)
 	 {   
		if(v.idVoiture==newv.idVoiture)
 	       { test=1;
			 printf("\n\t\tQuelle information desirez-vous modifier?\n\t\t1-MARQUE\n\t\t2-NOM\n\t\t3-COULEUR\n\t\t4-NB_PLACES\n\t\t5-PRIX_DU_JOUR\n\t\t6-EN_LOCATION\n");
 	         printf("\n\t\t\t\t Entrer votre choix : ");
 	         scanf("%d",&choix);
 	         system("cls");
 	           
 	         if(choix==1) {printf("\n\t\t  Veuillez saisir la nouvelle marque de la voiture : ");
 	                        scanf("%s",newv.marque);
 	                        fprintf(nouveau,"%d %s %s %s %d %d %s\n",v.idVoiture,newv.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);	 
                            system("cls");
                            printf("\n\n\t\t\t\t=======> modifications Bien Sauvegardees ! <=======");} 	
         
		     else if(choix==2) {printf("\n\t\t  Veuillez saisir le nouveau nom de la voiture : ");
 	                        scanf("%s",newv.nomVoiture);
 	                        fprintf(nouveau,"%d %s %s %s %d %d %s\n",v.idVoiture,v.marque,newv.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);	 
                            system("cls");
                            printf("\n\n\t\t\t\t=======> modifications Bien Sauvegardees ! <=======");} 	
         
		     else if(choix==3) {printf("\n\t\t  Veuillez saisir la nouvelle couleur de la voiture : ");
 	                        scanf("%s",newv.couleur);
 	                        fprintf(nouveau,"%d %s %s %s %d %d %s\n",v.idVoiture,v.marque,v.nomVoiture,newv.couleur,v.nbplaces,v.prixJour,v.EnLocation);	 
                            system("cls");
                            printf("\n\n\t\t\t\t=======> modifications Bien Sauvegardees ! <=======");} 	
 	       
 	         else if(choix==4) {printf("\n\t\t  Veuillez saisir le nouveau nombre de places de la voiture : ");
 	                        scanf("%d",&newv.nbplaces);
 	                        fprintf(nouveau,"%d %s %s %s %d %d %s\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,newv.nbplaces,v.prixJour,v.EnLocation);	 
                            system("cls");
                            printf("\n\n\t\t\t\t=======> modifications Bien Sauvegardees ! <=======");} 	
 	       
 	         else if(choix==5) {printf("\n\t\t  Veuillez saisir le nouveau prix du jour de la voiture : ");
 	                        scanf("%d",&newv.prixJour);
 	                        fprintf(nouveau,"%d %s %s %s %d %d %s\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,newv.prixJour,v.EnLocation);	 
                            system("cls");
                            printf("\n\n\t\t\t\t=======> modifications Bien Sauvegardees ! <=======");} 	
         
		     else if(choix==6) {printf("\n\t\t  la voiture est-elle louee? ");
 	                        scanf("%s",newv.EnLocation);
 	                        fprintf(nouveau,"%d %s %s %s %d %d %s\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,newv.EnLocation);	 
                            system("cls");
                            printf("\n\n\t\t\t\t=======> modifications Bien Sauvegardees ! <=======");} }	
         else   fprintf(nouveau,"%d %s %s %s %d %d %s\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);	} 
   
	fclose(ancien);
    fclose(nouveau);
    remove("voiture.txt");
    rename("nouveau_voiture.txt","voiture.txt");
    if(test!=1)
      { system("cls");
        printf("\n\n\t\t\t\t =======> Voiture introuvable !!! <======= ");	  }
}

void suppression_voiture()
{   int choix,test=0;
   Voiture vsupr,v;
	FILE *ancien,*nouveau;
	system("cls");
    ancien=fopen("voiture.txt","r");
    nouveau=fopen("nouveau_voiture.txt","w");
    
	printf("\t\t\t\t********** Suppression d'une voiture**********\n");
    printf("\n\t\t\t Veuillez saisir l'identifiant de la voiture que vous desirez supprimer : ");
    scanf("%d",&vsupr.idVoiture);
    system("cls");
 	while(fscanf(ancien,"%d %s %s %s %d %d %s",&v.idVoiture,v.marque,v.nomVoiture,v.couleur,&v.nbplaces,&v.prixJour,v.EnLocation)!= EOF)
 	 {   
		if(v.idVoiture!=vsupr.idVoiture)
 	       { fprintf(nouveau,"%d %s %s %s %d %d %s\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);	} 
		else{ test++;
		      printf("\n\n\t\t\t\t =======> Voiture Bien supprimee ! <=======");}}
         
	fclose(ancien);
    fclose(nouveau);
    remove("voiture.txt");
    rename("nouveau_voiture.txt","voiture.txt");
    if(test!=1)
      { system("cls");
	    printf("\n\n\t\t\t\t =======> Voiture introuvable !!! <======= ");
	  }
    
 
}
 void main()
 {  liste_voiture();
    ajout_voiture();
	modification_voiture();
	suppression_voiture();
	}
