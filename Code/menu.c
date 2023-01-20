#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//********************
//  Les structures: **
//  Date            **
//  ContratLocation **
//  Voiture         **
//  Client          **
//********************

typedef struct date{
	int jour;
	int moix;
	int annee;
} Date;

typedef struct contratLocation
{
float numContrat;
int idVoiture;
int idClient;
Date debut;
Date fin;
int cout;
} Contrat;

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

typedef struct Client
{
int idClient;
char nom[20];
char prenom[20];
int cin;
char adresse[15];
int telephone;
}Client;

//****Liste des fonctions****

void Chapeau(void);
void Fin1(void);void Fin2(void);void Fin3(void);

void Menu_Principal(void);

void Gestion_Voitures(void);
void Saisie_voiture(void);
void liste_voiture(void);
void ajout_voiture(void);
void modification_voiture(void);
void suppression_voiture(void);

void Gestion_Clients(void);
void liste_client(void);
void ajout_client(void);
void modification_client(void);
void suppression_client(void);

void Location_Voiture(void);
void visualisation_contrat(void);
void louer_voiture(void);
void retourner_voiture(void);
void modifier_contrat(void);

//*********************************************************************
//**	Fonction : Chapeau()					                     **
//**	Traitement: elle dessine l'entete en haut de chaque interface**
//**	Utilise   : _strtime et _strdate                             **
//*********************************************************************

void Chapeau()
{
system("cls");
system("color 70");
char bufftime[9];
char buffdate[9];
_strtime(bufftime);
_strdate(buffdate);

printf("                 \xc9"); 
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xbb");

printf("\n                 \xba      %s      \xba         Location de voitures            \xba      %s      \xba \n",bufftime,buffdate);

printf("                 \xc8"); 
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
printf("\xbc");
printf("\n\n");}



//************************************************************************
//**	Fonctions : Fin1(),Fin2(),Fin3()					            **					    
//**	Traitement: elle permet de sortir de l'application ou de revenir** 
//**                              au menu précédent                     **  
//************************************************************************

void Fin1(){  int exit;
                 printf("\n\n\t\t\t\t         Entrer 1 pour revenir ou 0 pour sortir : ");
	             scanf("%d",&exit);
	             if(exit==1) Gestion_Voitures();
	             else close();   }

void Fin2(){  int exit;
                 printf("\n\n\t\t\t\t         Entrer 1 pour revenir ou 0 pour sortir : ");
	             scanf("%d",&exit);
	             if(exit==1) Gestion_Clients();
	             else close();   }

void Fin3(){  int exit;
                 printf("\n\n\t\t\t\t         Entrer 1 pour revenir ou 0 pour sortir : ");
	             scanf("%d",&exit);
	             if(exit==1) Location_Voiture();
	             else close();   }

//***************************************************************************************
//**	Fonction  : Menu_Principal()					                               **					    
//**	Traitement: elle affiche le menu principal: la page d'accueil de l'application.**
//***************************************************************************************

void Menu_Principal()
{
int choix;
Chapeau();
printf("\n                                                \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
printf("\n                                                \xb3  Menu Principal  \xb3");
printf("\n                                                \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
printf("\n\n");

printf("                                     \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
printf("\n                                     \xba                                         \xba ");
printf("\n                                     \xba    Location.........................1   \xba ");
printf("\n                                     \xba    Gestion Voitures.................2   \xba ");
printf("\n                                     \xba    Gestion Clients..................3   \xba ");
printf("\n                                     \xba    Quitter..........................4   \xba ");
printf("\n                                     \xba                                         \xba ");
printf("\n                                     \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");

printf("\n\n");
printf("                                                    votre choix : "); 
scanf("%d",&choix); 
switch(choix)
    { case 1: Location_Voiture();
         break;
      case 2:  Gestion_Voitures();
         break;
      case 3:  Gestion_Clients();
         break;
	  case 4:  exit (0);
	     break;
	  default:	if(choix>4) printf("\n\t\t\t\t=======> SVP reessayez autre option (1-->4) !!! <=======\n\n");
    }
}

//******************* Menu Gestion des voitures ******************

//****************************************************************
//**	Fonction  : Gestion_Voitures()					        **					    
//**	Traitement: elle affiche le menu Gestion des Voitures.  **
//****************************************************************

void Gestion_Voitures()
{
int choix;
Chapeau();

printf("\n                                                \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
printf("\n                                                \xb3 Gestion des Voitures \xb3");
printf("\n                                                \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
printf("\n\n");

printf("                                     \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
printf("\n                                     \xba                                            \xba ");
printf("\n                                     \xba    Liste des voitures...................1  \xba ");
printf("\n                                     \xba    Ajouter voiture......................2  \xba ");
printf("\n                                     \xba    Modifier voiture.....................3  \xba ");
printf("\n                                     \xba    Supprimer voiture....................4  \xba ");
printf("\n                                     \xba    Retour...............................5  \xba ");
printf("\n                                     \xba                                            \xba ");
printf("\n                                     \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");

printf("\n\n");
printf("                                                     votre choix : ");
scanf("%d",&choix);
switch(choix)
{
	case 1: liste_voiture();
	   break;
	case 2: ajout_voiture();
	   break;
	case 3: modification_voiture();
	   break;
	case 4: suppression_voiture();
       break;
	case 5: Menu_Principal();
	   break;
	default: if(choix>5) printf("\n\t\t\t\t=======> SVP reessayer autre option (1-->5)!!! <=======\n\n");}
Fin1();
}	             
	             
//*********************************************************************
//**	Fonction  : Saisie_voiture()					             **					    
//**	Traitement: elle permet d'enregistrer les infos des voitures **
//**                            dans le fichier Voiture.             **
//*********************************************************************

 void Saisie_voiture()
 {  FILE *f;
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
 	   
 
//**********************************************************************
//**	Fonction  : liste_voiture()					                  **					    
//**	Traitement: elle permet d'afficher la liste des voitures déjà ** 
//**                        enregistrer dans le fichier Voiture       **
//**********************************************************************
 
 void liste_voiture()
 {  Voiture v;
    Chapeau();
    FILE *liste;
    int exit;
 	liste=fopen("voiture.txt","r");
 	
 	printf("\t\t\t\t\t**********Liste Des Voitures**********\t\t\t\n");
 	printf("\n        Id  |      MARQUE      |       NOM       |  COULEUR   | NB_PLACES | PRIX_DU_JOUR | EN_LOCATION ");
 	printf("\n      ---------------------------------------------------------------------------------------------------");

	if(liste!=NULL) 
	{
        while(fscanf(liste,"%d %s %s %s %d %d %s",&v.idVoiture,v.marque,v.nomVoiture,v.couleur,&v.nbplaces,&v.prixJour,v.EnLocation) != EOF)
		{ printf("\n        %2d  |      %7s     |     %7s     |    %5s   |    %d      |     %d      |      %s     \n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);}	 
	}	 
    fclose(liste);
	Fin1();
}

//*********************************************************************
//**	Fonction  : ajout_voiture()					                 **					    
//**	Traitement: elle permet d'ajouter une nouvelle voiture       **
//**                        au fichier voiture.                      **
//*********************************************************************
 
void ajout_voiture()
{ Voiture new_v,v;
  FILE *p;
  int test=0;
  Chapeau();
        printf("\n\t\t\t\t\t**********Ajouter une voiture**********\t\t\t\n");
        printf("\n\t\t\t\t  Veuillez saisir l'identifiant de la voiture a ajouter: ");
 	 	scanf("%d",&new_v.idVoiture);
 	 	p=fopen("voiture.txt","r+");

 	 	while(fscanf(p,"%d %s %s %s %d %d %s",&v.idVoiture,v.marque,v.nomVoiture,v.couleur,&v.nbplaces,&v.prixJour,v.EnLocation) != EOF)
        {  if(v.idVoiture==new_v.idVoiture) { test++;} }
        if(test==0){
		        printf("\n\t\t\t\t  Veuillez saisir la marque de la voiture a ajouter:");
		        scanf("%s",new_v.marque);
		        printf("\n\t\t\t\t  Veuillez saisir le nom de la voiture a ajouter:");
		        scanf("%s",new_v.nomVoiture);
		        printf("\n\t\t\t\t  Veuillez saisir la couleur de la voiture a ajouter:");
		        scanf("%s",new_v.couleur);
		        printf("\n\t\t\t\t  Veuillez saisir le nombre de places de la voiture a ajouter:");
		        scanf("%d",&new_v.nbplaces);
	            printf("\n\t\t\t\t  Veuillez saisir le prix du jour de la voiture a ajouter:");
		        scanf("%d",&new_v.prixJour);
		        printf("\n\t\t\t\t  la voiture ajoutee est-elle louee?");
		        scanf("%s",new_v.EnLocation);  
		   fprintf(p,"%d %s %s %s %d %d %s",new_v.idVoiture,new_v.marque,new_v.nomVoiture,new_v.couleur,new_v.nbplaces,new_v.prixJour,new_v.EnLocation);
           Chapeau();
		   printf("\n\n\t\t\t\t\t =======> Ajout En Succes! <=======\n");	
           fclose(p);}
		else { 		        printf("\n\n\t\t\t\t\t =======> voiture deja existee ! <======= \n\n"); 		}
Fin1();
}

//*********************************************************************
//**	Fonction  : modification_voiture()					         **					    
//**	Traitement: elle permet de mdifier les infos d'une voiture   **
//**                   déjà enregistrées dans le fichier voiture.    **
//*********************************************************************

void modification_voiture()
{   int choix,test=0;
    Voiture newv,v;
    Chapeau();
	FILE *ancien,*nouveau;
    ancien=fopen("voiture.txt","r");
    nouveau=fopen("nouveau_voiture.txt","w");
    
	printf("\n\t\t\t\t\t********** Modification d'une voiture**********\n");
    printf("\n\t\t\t Veuillez saisir l'identifiant de la voiture que vous desirez modifier : ");
    scanf("%d",&newv.idVoiture);
 	while(fscanf(ancien,"%d %s %s %s %d %d %s",&v.idVoiture,v.marque,v.nomVoiture,v.couleur,&v.nbplaces,&v.prixJour,v.EnLocation)!= EOF)
 	 {   
		if(v.idVoiture==newv.idVoiture)
 	       { test=1;
			 printf("\n\t\tQuelle information desirez-vous modifier?\n\n\t\t1-MARQUE\n\t\t2-NOM\n\t\t3-COULEUR\n\t\t4-NB_PLACES\n\t\t5-PRIX_DU_JOUR\n\t\t6-EN_LOCATION\n");
 	         printf("\n\t\t\t\t\t Entrer votre choix : ");
 	         scanf("%d",&choix);
 	         
 	           
 	          if(choix==1) {printf("\n\t\t\t    Veuillez saisir la nouvelle marque de la voiture : ");
 	                        scanf("%s",newv.marque);
 	                        fprintf(nouveau,"%d %s %s %s %d %d %s\n",v.idVoiture,newv.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);	 
                            printf("\n\n\t\t\t\t=======> modifications Bien Sauvegardees ! <=======");} 	
         
		     else if(choix==2) {printf("\n\t\t\t    Veuillez saisir le nouveau nom de la voiture : ");
 	                        scanf("%s",newv.nomVoiture);
 	                        fprintf(nouveau,"%d %s %s %s %d %d %s\n",v.idVoiture,v.marque,newv.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);	 
                            printf("\n\n\t\t\t\t=======> modifications Bien Sauvegardees ! <=======");} 	
         
		     else if(choix==3) {printf("\n\t\t\t    Veuillez saisir la nouvelle couleur de la voiture : ");
 	                        scanf("%s",newv.couleur);
 	                        fprintf(nouveau,"%d %s %s %s %d %d %s\n",v.idVoiture,v.marque,v.nomVoiture,newv.couleur,v.nbplaces,v.prixJour,v.EnLocation);	 
                            printf("\n\n\t\t\t\t=======> modifications Bien Sauvegardees ! <=======");} 	
 	       
 	         else if(choix==4) {printf("\n\t\t\t    Veuillez saisir le nouveau nombre de places de la voiture : ");
 	                        scanf("%d",&newv.nbplaces);
 	                        fprintf(nouveau,"%d %s %s %s %d %d %s\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,newv.nbplaces,v.prixJour,v.EnLocation);	 
                            printf("\n\n\t\t\t\t=======> modifications Bien Sauvegardees ! <=======");} 	
 	       
 	         else if(choix==5) {printf("\n\t\t\t    Veuillez saisir le nouveau prix du jour de la voiture : ");
 	                        scanf("%d",&newv.prixJour);
 	                        fprintf(nouveau,"%d %s %s %s %d %d %s\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,newv.prixJour,v.EnLocation);	 
                            printf("\n\n\t\t\t\t=======> modifications Bien Sauvegardees ! <=======");} 	
         
		     else if(choix==6) {printf("\n\t\t\t\t      la voiture est-elle louee? ");
 	                        scanf("%s",newv.EnLocation);
 	                        fprintf(nouveau,"%d %s %s %s %d %d %s\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,newv.EnLocation);	 
                            printf("\n\n\t\t\t\t=======> modifications Bien Sauvegardees ! <=======");} 
		     else if(choix>6) { printf("\n\t\t\t\t=======> SVP choisir autre choix (1-->6)!!! <=======\n\n");}
			}	
         else  {fprintf(nouveau,"%d %s %s %s %d %d %s\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);}
	 } 
      fclose(ancien);
      fclose(nouveau);
      remove("voiture.txt");
      rename("nouveau_voiture.txt","voiture.txt");
    if(test!=1) { printf("\n\n\t\t\t\t\t =======> Voiture introuvable !!! <======= \n\n");  }
Fin1();
}

//****************************************************************************
//**	Fonction  : suppression_voiture()					                **					    
//**	Traitement: elle permet de supprimer une voiture de fichier voiture.**
//****************************************************************************

void suppression_voiture()
{   int choix,test=0;
    Voiture vsupr,v;
    Chapeau();
	FILE *ancien,*nouveau;
	ancien=fopen("voiture.txt","r");
    nouveau=fopen("nouveau_voiture.txt","w");
    
	printf("\n\t\t\t\t\t********** Suppression d'une voiture**********\n");
    printf("\n\t\t\t    Veuillez saisir l'identifiant de la voiture que vous desirez supprimer : ");
    scanf("%d",&vsupr.idVoiture);
    
 	   while(fscanf(ancien,"%d %s %s %s %d %d %s",&v.idVoiture,v.marque,v.nomVoiture,v.couleur,&v.nbplaces,&v.prixJour,v.EnLocation)!= EOF)
 	    {   
		   if(v.idVoiture!=vsupr.idVoiture)
 	             { fprintf(nouveau,"%d %s %s %s %d %d %s\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);	} 
		   else{ test=1;
		          printf("\n\n\t\t\t\t\t =======> Voiture Bien supprimee ! <=======");}
	    }
      fclose(ancien);
      fclose(nouveau);
      remove("voiture.txt");
      rename("nouveau_voiture.txt","voiture.txt");
    
	if(test==0) { printf("\n\n\t\t\t\t\t =======> Voiture introuvable !!! <======= ");}

Fin1();
}

//****************** Menu Gestion des clients ********************

//****************************************************************
//**	Fonction  : Gestion_Clients()					        **					    
//**	Traitement: elle affiche le menu Gestion des Clients.   **
//****************************************************************

void Gestion_Clients()
{
int choix;
Chapeau();
printf("\n                                                \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
printf("\n                                                \xb3 Gestion des Clients \xb3");
printf("\n                                                \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
printf("\n\n");

printf("                                     \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
printf("\n                                     \xba                                            \xba ");
printf("\n                                     \xba    Liste des clients....................1  \xba ");
printf("\n                                     \xba    Ajouter client.......................2  \xba ");
printf("\n                                     \xba    Modifier client......................3  \xba ");
printf("\n                                     \xba    Supprimer client.....................4  \xba ");
printf("\n                                     \xba    Retour...............................5  \xba ");
printf("\n                                     \xba                                            \xba ");
printf("\n                                     \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");

printf("\n\n");
printf("                                                     votre choix : ");
scanf("%d",&choix);
switch(choix)
{
	case 1: liste_client();
	   break;
	case 2: ajout_client();
	   break;
	case 3: modification_client();
	   break;
	case 4: suppression_client();
       break;
	case 5: Menu_Principal();
	   break;
	default: if(choix>5) printf("\n\t\t\t\t=======> SVP reessayer autre option (1-->5)!!! <=======\n\n");}
Fin2();
}

//********************************************************************
//**	Fonction  : Saisie_client()					                **					    
//**	Traitement: elle permet d'enregistrer les infos des clients **
//**                            dans le fichier Client.             **
//********************************************************************

void Saisie_client()
 {  FILE *f;
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
		fclose(f);
}
 	   
//*********************************************************************
//**	Fonction  : liste_client()					                 **					    
//**	Traitement: elle permet d'afficher la liste des clients déjà ** 
//**                        enregistrer dans le fichier client       **
//*********************************************************************
 
 void liste_client()
 {  Client c;
    Chapeau();
    FILE *liste;
 	liste=fopen("client.txt","r");
 	printf("\t\t\t\t\t**********Liste Des Clients**********\t\t\t\n");
 	printf("\n        Id  |        NOM        |      PRENOM      |    CIN      |      ADRESSE       |   TELEPHONE \n ");
 	printf("     ---------------------------------------------------------------------------------------------------\n");

	if(liste!=NULL) 
	{
        while(fscanf(liste,"%d %s %s %d %s %d ",&c.idClient,c.nom,c.prenom,&c.cin,c.adresse,&c.telephone) != EOF)
		{ printf("\n        %2d  |      %8s     |     %8s     |    %6d   |    %10s      |     %10d     \n",c.idClient,c.nom,c.prenom,c.cin,c.adresse,c.telephone);}	 
	}
    fclose(liste);
 
 Fin2();	 
 }

//********************************************************************
//**	Fonction  : ajout_client()					                **					    
//**	Traitement: elle permet d'ajouter un nouveau client         **
//**                        au fichier client.                      **
//********************************************************************

void ajout_client()
{ Client new_c,c;
  FILE *p;
  Chapeau();
  int test=0;
  
        printf("\n\t\t\t\t\t**********Ajouter un client**********\t\t\t\n");
        printf("\n\t\t\t\t  Veuillez saisir l'identifiant du client a ajouter: ");
 	 	scanf("%d",&new_c.idClient);
 	 	p=fopen("client.txt","r+");

          while(fscanf(p,"%d %s %s %d %s %d ",&c.idClient,c.nom,c.prenom,&c.cin,c.adresse,&c.telephone) != EOF)
          {  if(c.idClient==new_c.idClient) { test++;} }
          if(test==0){
		        printf("\n\t\t\t\t  Veuillez saisir le nom du client a ajouter :");
		        scanf("%s",new_c.nom);
		        printf("\n\t\t\t\t  Veuillez saisir le prenom du client a ajouter:");
		        scanf("%s",new_c.prenom);
		        printf("\n\t\t\t\t  Veuillez saisir le cin du client a ajouter:");
		        scanf("%d",&new_c.cin);
		        printf("\n\t\t\t\t  Veuillez saisir l'adresse du client a ajouter:");
		        scanf("%s",new_c.adresse);
	            printf("\n\t\t\t\t  Veuillez saisir le telephone du client a ajouter:");
		        scanf("%d",&new_c.telephone);
		        
              fprintf(p,"%d %s %s %d %s %d ",new_c.idClient,new_c.nom,new_c.prenom,new_c.cin,new_c.adresse,new_c.telephone);
              Chapeau();
		      printf("\n\n\t\t\t\t =======> Ajout En Succes! <=======\n");	
              fclose(p);}
		  else { 		        printf("\n\n\t\t\t\t\t =======> client existe deja  ! <======= \n\n"); 		}
Fin2();
}

//*******************************************************************
//**	Fonction  : modification_client()					       **					    
//**	Traitement: elle permet de mdifier les infos d'un client   **
//**                  déjà enregistrées dans le fichier client.    **
//*******************************************************************

void modification_client()
{   int choix,test=0;
    Client newc,c;
    Chapeau();
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
  
  if(test!=1) { printf("\n\n\t\t\t\t\t =======> Client introuvable !!! <======= \n\n");  }

Fin2();
}

//**************************************************************************
//**	Fonction  : suppression_client()					              **					    
//**	Traitement: elle permet de supprimer un client de fichier client. **
//**************************************************************************

void suppression_client()
{   int choix,test=0;
    Client csupr,c;
    Chapeau();
	FILE *ancien,*nouveau;
	ancien=fopen("client.txt","r");
    nouveau=fopen("nouveau_client.txt","w");
    
	printf("\n\t\t\t\t\t********** Suppression d'un client**********\n");
    printf("\n\t\t\t    Veuillez saisir l'identifiant du client que vous desirez supprimer : ");
    scanf("%d",&csupr.idClient);
    
        while(fscanf(ancien,"%d %s %s %d %s %d ",&c.idClient,c.nom,c.prenom,&c.cin,c.adresse,&c.telephone) != EOF)
 	    {   
		  if(c.idClient!=csupr.idClient) { fprintf(nouveau,"%d %s %s %d %s %d \n",c.idClient,c.nom,c.prenom,c.cin,c.adresse,c.telephone);} 
		  else {test++;
		        printf("\n\n\t\t\t\t\t =======> Client Bien supprime ! <=======");}
		}
     fclose(ancien);
     fclose(nouveau);
     remove("client.txt");
     rename("nouveau_client.txt","client.txt");
   if(test==0){ printf("\n\n\t\t\t\t\t =======>  Client introuvable !!! <======= ");}

Fin2();
}

//******************** Menu Location d'une voiture ********************

//*****************************************************************
//**	Fonction  : Location_Voiture()					         **					    
//**	Traitement: elle affiche le menu Location d'une voiture. **
//*****************************************************************

void Location_Voiture()
{
int choix;
Chapeau();
printf("\n                                                \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
printf("\n                                                \xb3 Location d'une Voiture \xb3");
printf("\n                                                \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
printf("\n\n");

printf("                                     \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
printf("\n                                     \xba                                            \xba ");
printf("\n                                     \xba    Visualiser contrat...................1  \xba ");
printf("\n                                     \xba    Louer voiture........................2  \xba ");
printf("\n                                     \xba    Retourner voiture....................3  \xba ");
printf("\n                                     \xba    Modifier contrat.....................4  \xba ");
printf("\n                                     \xba    Retour...............................5  \xba ");
printf("\n                                     \xba                                            \xba ");
printf("\n                                     \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");

printf("\n\n");
printf("                                                     votre choix : ");
scanf("%d",&choix);
switch(choix)
{
	case 1: visualisation_contrat();
	   break;
	case 2: louer_voiture();
	   break;
	case 3: retourner_voiture();
	   break;
	case 4: modifier_contrat();
	   break;
	case 5: Menu_Principal();
	   break;
	default: if(choix>5) printf("\n\t\t\t\t=======> SVP reessayer autre option (1-->5)!!! <=======\n\n");}
Fin3();
}

//*********************************************************************
//**	Fonction  : Saisie_contrat()					             **					    
//**	Traitement: elle permet d'enregistrer les infos des contrats **
//**                            dans le fichier Client.              **
//*********************************************************************

void Saisie_contrat()
 {  FILE *f;
 	int i,n;
 	Contrat co;
 	printf("Entrer le nombre des contrats:");
 	scanf("%d",&n);
 	f=fopen("contrat.txt","w");

      for(i=0;i<n;i++)
 	 {  printf("\n contrat Num : ");
	    scanf("%f",&co.numContrat);
 	 	printf("\n Entrer l'identifiant de la voiture:");
 	 	scanf("%d",&co.idVoiture);
 	 	printf("\n Fntrer l'identifiant du client:");
		scanf("%d",&co.idClient);
		printf("\n Entrer la date du debut:");
		printf("\n Jour");
		scanf("%d",&co.debut.jour);
		printf("\n Mois:");
		scanf("%d",&co.debut.moix);
	    printf("\n Annee:");
		scanf("%d",&co.debut.annee);
		printf("\n Entrer la date de la fin:");
		printf("\n Jour");
		scanf("%d",&co.fin.jour);
		printf("\n Mois:");
		scanf("%d",&co.fin.moix);
	    printf("\n Annee:");
		scanf("%d",&co.fin.annee);
		printf("\n Entrer le cout de location: ");
		scanf("%d",&co.cout);
		fprintf(f,"%.2f %d %d %d/%d/%d %d/%d/%d %d \n",co.numContrat,co.idVoiture,co.idClient,co.debut.jour,co.debut.moix,co.debut.annee,co.fin.jour,co.fin.moix,co.fin.annee,co.cout);
	 }	 
   fclose(f);
}
 	   
//***********************************************************************
//**	Fonction  : visualisation_contrat()					            **					    
//**	Traitement: elle permet d'afficher les informations contenues   **
//**                dans un contrat à partir de son numéro(numContrat). **
//************************************************************************
 
void visualisation_contrat()
{   int test=0;
	Contrat co,co_rech;
	Chapeau();
	FILE *f;
	f=fopen("contrat.txt","r");
	
	  printf("\n\t\t\t   Veuillez saisir le numero de contrat que vous desirez voir: ");
	  scanf("%f",&co_rech.numContrat);
	  while(fscanf(f,"%f %d %d %d/%d/%d %d/%d/%d %d \n",&co.numContrat,&co.idVoiture,&co.idClient,&co.debut.jour,&co.debut.moix,&co.debut.annee,&co.fin.jour,&co.fin.moix,&co.fin.annee,&co.cout)!=EOF)
	  {
	  	if(co.numContrat==co_rech.numContrat)
		  { test=1;
		    printf("\n\t\t\t\t\t**********  Contrat  **********\t\t\t\n");
 	        printf("\n\t             NUM  | ID_VOITURE | ID_CLIENT |   DATE_DEBUT  |    DATE_FIN   |   COUT(DH) \n ");
 	        printf(" \t          ---------------------------------------------------------------------------------\n");
		    printf("\n\t             %.2f |     %2d     |    %2d     |   %d/%d/%d   |   %d/%d/%d   |    %2d  \n",co.numContrat,co.idVoiture,co.idClient,co.debut.jour,co.debut.moix,co.debut.annee,co.fin.jour,co.fin.moix,co.fin.annee,co.cout);
		  }
     }
   fclose(f);
   if(test!=1){ printf("\n\n\t\t\t\t\t =======> Pas de Contrat !!! <======= ");}

Fin3();
}

//*************************************************************************
//**	Fonction  : louer_voiture()					                     **					    
//**	Traitement: elle permet au client de louer une voiture qui est   **
//**                          enregistrée dans le fichier voiture.       **
//*************************************************************************

void louer_voiture()
{     Chapeau();
        FILE *ancien=fopen("voiture.txt","r");
        FILE *nouveau=fopen("nouveau_voiture.txt","w");
        FILE *p=fopen("client.txt","r");
        FILE *ptr;
        Client c,c_rech;
        Voiture v,v_rech;
        Contrat co;
        int test1=0,test2=0,test3=0;

        printf("\n\t\t\t\t\t  ********** Location d'une voiture**********\n");
        printf("\n\n\t\t\t\t\t =======> Soyez le Bienvenue cher client .<=======\n");
        printf("\n\n\t    **** Veuillez saisir vos infos ****\n");
        printf("\n\t     Veuillez entrer votre identifiant:");
 	 	scanf("%d",&c_rech.idClient);
 	 	printf("\n\t     Veuillez entrer votre nom :");
		scanf("%s",c_rech.nom);
		printf("\n\t     Veuillez entrer votre prenom :");
		scanf("%s",c_rech.prenom);
   
    while(fscanf(p,"%d %s %s %d %s %d ",&c.idClient,c.nom,c.prenom,&c.cin,c.adresse,&c.telephone) != EOF)
         {if(c_rech.idClient==c.idClient) test1=1;}
          
	if(test1!=1) printf("\n\n    **Client introuvable!! Veuillez enregistrer d'abord vos informations a travers l'option 'Ajouter client' \n\t\t\t\t   du menu <<Gestion clients>>**\n");
	else{		
		    Chapeau();	
		    printf("\n\n\t           **** Veuillez saisir les infos de la voiture que vous desirez louer ****	\n");
		    printf("\n\t     Veuillez entrer l'identifiant de la voiture:");
 	 	    scanf("%d",&v_rech.idVoiture);
 	 	    printf("\n\t     Veuillez entrer la marque de la voiture:");
		    scanf("%s",v_rech.marque);
		    printf("\n\t     Veuillez entrer le nom de la voiture:");
		    scanf("%s",v_rech.nomVoiture);
		    printf("\n\t     Veuillez entrer la couleur de la voiture:");
		    scanf("%s",v_rech.couleur);
		    printf("\n\t     Veuillez entrer le nombre de places de la voiture:");
		    scanf("%d",&v_rech.nbplaces);
		
	  while(fscanf(ancien,"%d %s %s %s %d %d %s",&v.idVoiture,v.marque,v.nomVoiture,v.couleur,&v.nbplaces,&v.prixJour,v.EnLocation)!= EOF)
       {  if(v_rech.idVoiture==v.idVoiture) 
		   { test2=1;
             if(strcmpi(v.EnLocation,"OUI")==0) { printf("\n\n\t\t\t\t     *** Excusez-nous voiture indisponible !! ***");
                                                 fprintf(nouveau,"%d %s %s %s %d %d %s \n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);
											    }
			 else if(strcmpi(v.EnLocation,"NON")==0) 
			  {      test3=1;
			         fprintf(nouveau,"%d %s %s %s %d %d OUI \n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);
			         Chapeau();		       
              }
          }
		else fprintf(nouveau,"%d %s %s %s %d %d %s \n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);
	   }
		
		  fclose(ancien);
		  fclose(nouveau);
		  remove("voiture.txt");
		  rename("nouveau_voiture.txt","voiture.txt");
          fclose(p);
          
		  if (test3==1)
		  {    printf("\n\n\t\t\t\t *** Veuillez remplir le contrat SVP ***\n");
		           ptr=fopen("contrat.txt","a");
                         printf("\n\t\t     Veuillez saisir le numero de votre contrat : ");
	                     scanf("%f",&co.numContrat);
 	 	                 printf("\n\t\t     Veuillez saisir l'identifiant de la voiture: ");
 	 	                 scanf("%d",&co.idVoiture);
 	 	                 printf("\n\t\t     Veuillez saisir votre identifiant : ");
		                 scanf("%d",&co.idClient);
		                 printf("\n\t\t     Veuillez saisir la date du debut: ");
		                 printf("\n\t\t\t Jour: ");
		                 scanf("%d",&co.debut.jour);
		                 printf("\n\t\t\t Mois: ");
		                 scanf("%d",&co.debut.moix);
	                     printf("\n\t\t\t Annee: ");
		                 scanf("%d",&co.debut.annee);
		                 printf("\n\t\t Veuillez saisir la date de la fin: ");
		                 printf("\n\t\t\t Jour: ");
		                 scanf("%d",&co.fin.jour);
		                 printf("\n\t\t\t Mois: ");
		                 scanf("%d",&co.fin.moix);
	                     printf("\n\t\t\t Annee: ");
		                 scanf("%d",&co.fin.annee);
		                 printf("\n\t\t     Veuillez saisir le cout de location: ");
		                 scanf("%d",&co.cout);
		                 printf("\n\n\t\t\t\t\t =======>  Ajout de contrat en succes. <======= ");
		      
			          fprintf(ptr,"%.2f %d %d %d/%d/%d %d/%d/%d %d \n",co.numContrat,co.idVoiture,co.idClient,co.debut.jour,co.debut.moix,co.debut.annee,co.fin.jour,co.fin.moix,co.fin.annee,co.cout);	 
		              fclose(ptr);
		  }
	        
	   if(test2!=1) printf("\n\n\t\t\t\t     *** La voiture demandee n'existe pas ***");
    }
Fin3();
}

//**************************************************************************
//**	Fonction  : retourner_voiture()					                  **					    
//**	Traitement: elle permet au client de retourner une voiture qui a  **
//**                            déjà louée.                               **
//**************************************************************************

void retourner_voiture()
{  Chapeau();
   Voiture v_ret,v;
   Contrat co;
   int test1=0,test2=0;
   FILE *ancienv=fopen("voiture.txt","r");
   FILE *nouveauv=fopen("nouveau_voiture.txt","w");
   FILE *ancienco=fopen("contrat.txt","r");
   FILE *nouveauco=fopen("nouveau_contrat.txt","w");

   printf("\n\t\t\t\t  ********** Retour d'une voiture**********\n");
   printf("\n\n\t\t    Veuillez saisir l'identifiant de la voiture que vous desirez retourner: ");
   scanf("%d",&v_ret.idVoiture);
    
	while(fscanf(ancienv,"%d %s %s %s %d %d %s",&v.idVoiture,v.marque,v.nomVoiture,v.couleur,&v.nbplaces,&v.prixJour,v.EnLocation)!= EOF)
        {   if(v.idVoiture==v_ret.idVoiture) { test1=1;
			                                   fprintf(nouveauv,"%d %s %s %s %d %d NON\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);	 
                                               printf("\n\n\t\t\t\t =======> Voiture Retournee ! <=======");
                                             }
		    else fprintf(nouveauv,"%d %s %s %s %d %d %s\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);
		}
    
	   fclose(ancienv);
       fclose(nouveauv);
       remove("voiture.txt");
       rename("nouveau_voiture.txt","voiture.txt");

	while(fscanf(ancienco,"%f %d %d %d/%d/%d %d/%d/%d %d \n",&co.numContrat,&co.idVoiture,&co.idClient,&co.debut.jour,&co.debut.moix,&co.debut.annee,&co.fin.jour,&co.fin.moix,&co.fin.annee,&co.cout)!=EOF)	 
       {  if(co.idVoiture!=v_ret.idVoiture) { fprintf(nouveauco,"%.2f %d %d %d/%d/%d %d/%d/%d %d \n",co.numContrat,co.idVoiture,co.idClient,co.debut.jour,co.debut.moix,co.debut.annee,co.fin.jour,co.fin.moix,co.fin.annee,co.cout);}
       
          else { test2=1;
                 printf("\n\n\t\t\t\t =======> Contrat Supprimee ! <=======\n\n");}
       }
      
	  fclose(ancienco);
      fclose(nouveauco);
      remove("contrat.txt");
      rename("nouveau_contrat.txt","contrat.txt");
   
   if(test1!=1){printf("\n\n\t\t\t\t   !!! Voiture inexistable !!!");}
   if(test2!=1){printf("\n\n\t\t\t\t   !!!  Contrat inexistable !!!\n\n");}

Fin3();
} 

//*********************************************************************************************
//**	Fonction  : modifier_contrat()					                                     **					    
//**	Traitement: elle permet au client de modifier les informations d'un contrat qui est  **
//**                          déjà enregistré dans le fichier "contrat".                     **
//*********************************************************************************************

void modifier_contrat()
{   int choix,test1=0,test2=0,test3=0,test4=0;
    Contrat newco,pastco,co;
    Voiture v;
    Client c;
	FILE *ancienco,*nouveauco;
	FILE *ancienv,*nouveauv,*p;
	Chapeau();
    ancienco=fopen("contrat.txt","r");
    nouveauco=fopen("nouveau_contrat.txt","w");
   
    
	printf("\n\t\t\t\t  ********** Modification d'une Contrat**********\n");
    printf("\n\t\t\t Veuillez saisir le numero du contrat que vous desirez modifier : ");
    scanf("%f",&newco.numContrat);
	while(fscanf(ancienco,"%f %d %d %d/%d/%d %d/%d/%d %d \n",&co.numContrat,&co.idVoiture,&co.idClient,&co.debut.jour,&co.debut.moix,&co.debut.annee,&co.fin.jour,&co.fin.moix,&co.fin.annee,&co.cout)!=EOF)	 
 	 {   
		if(co.numContrat==newco.numContrat)
 	      {   test1=1;
			  printf("\n\t\tQuelle information desirez-vous modifier?\n\t\t1-ID_VOITURE\n\t\t2-ID_CLIENT\n\t\t3-DATE_DEBUT\n\t\t4-DATE_FIN\n\t\t5-COUT\n");
 	          printf("\n\t\t\t\t Entrer votre choix : ");
 	          scanf("%d",&choix);
 	          Chapeau();
 	         
	        if(choix==1) 
			{              ancienv=fopen("voiture.txt","r");
                           nouveauv=fopen("nouveau_voiture.txt","w");
	                       printf("\n\t\t Veuillez saisir l'identifiant de la nouvelle voiture que vous souhaite louer : ");
 	                       scanf("%d",&newco.idVoiture);
 	                       printf("\n\t\t Veuillez saisir l'identifiant de l'ancienne voiture que vous avez deja louee : ");
 	                       scanf("%d",&pastco.idVoiture);
 	                        
 	            while(fscanf(ancienv,"%d %s %s %s %d %d %s",&v.idVoiture,v.marque,v.nomVoiture,v.couleur,&v.nbplaces,&v.prixJour,v.EnLocation)!= EOF)
                 { if(v.idVoiture==newco.idVoiture)
                        {test2=1;
                         if(strcmpi(v.EnLocation,"OUI")==0){printf("\n\n\t\t\t\t     *** Excusez-nous voiture indisponible !! ***");
                                                            Fin3();
                                                            fprintf(nouveauv,"%d %s %s %s %d %d %s \n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);
														   }
			             else if(strcmpi(v.EnLocation,"NON")==0) {test4=1;
						                                          fprintf(nouveauv,"%d %s %s %s %d %d OUI \n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);
                                                                  printf("\n\n\t\t\t\t  =======> modifications Bien Sauvegardees ! <=======");
				                                                  }
			            }
		  
		               else if (v.idVoiture==pastco.idVoiture) { fprintf(nouveauv,"%d %s %s %s %d %d NON\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);}
		   
		               else  fprintf(nouveauv,"%d %s %s %s %d %d %s\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);
				 }
            
			                fclose(ancienv);
                            fclose(nouveauv);
                            remove("voiture.txt");
                            rename("nouveau_voiture.txt","voiture.txt");
                    
                if(test4==1){ fprintf(nouveauco,"%.2f %d %d %d/%d/%d %d/%d/%d %d \n",co.numContrat,newco.idVoiture,co.idClient,co.debut.jour,co.debut.moix,co.debut.annee,co.fin.jour,co.fin.moix,co.fin.annee,co.cout);}
		        else        { fprintf(nouveauco,"%.2f %d %d %d/%d/%d %d/%d/%d %d \n",co.numContrat,co.idVoiture,co.idClient,co.debut.jour,co.debut.moix,co.debut.annee,co.fin.jour,co.fin.moix,co.fin.annee,co.cout);}
	                
					 if(test2!=1){ Chapeau();
                                    printf("\n\n\t\t\t\t =======> Voiture Introuvable !!! <======= ");} 
            }
		    
	
	        else if(choix==2) 
			{         printf("\n\t\t\t  Veuillez saisir votre nouveau identifiant de la location : ");
	                  scanf("%d",&newco.idClient);
	        
			     p=fopen("client.txt","r");
                 
				 while(fscanf(p,"%d %s %s %d %s %d ",&c.idClient,c.nom,c.prenom,&c.cin,c.adresse,&c.telephone) != EOF)
                 { if(c.idClient==newco.idClient) {test3=1;
		                                           fprintf(nouveauco,"%.2f %d %d %d/%d/%d %d/%d/%d %d \n",co.numContrat,co.idVoiture,newco.idClient,co.debut.jour,co.debut.moix,co.debut.annee,co.fin.jour,co.fin.moix,co.fin.annee,co.cout);	 
                                                   printf("\n\n\t\t\t\t  =======> modifications Bien Sauvegardees ! <=======");}
				 } 

                   if(test3!=1) { printf("\n\n   *** Client introuvable!! Veuillez enregistrer d'abord vos informations a travers l'option 'Ajouter client' du menu <<Gestion clients>> ***\n");
				                  fprintf(nouveauco,"%.2f %d %d %d/%d/%d %d/%d/%d %d \n",co.numContrat,co.idVoiture,co.idClient,co.debut.jour,co.debut.moix,co.debut.annee,co.fin.jour,co.fin.moix,co.fin.annee,co.cout);	 
                                }
                 fclose(p);
		    } 
					 
           else if(choix==3) 
           {           printf("\n\t\t  Veuillez saisir la nouvelle date du debut de la location : ");
		               printf("\n\t\t\t Entrer le jour: ");
 	                   scanf("%d",&newco.debut.jour);
 	                   printf("\n\t\t\t Entrer le mois: ");
 	                   scanf("%d",&newco.debut.moix);
 	                   printf("\n\t\t\t Entrer l'annee: ");
 	                   scanf("%d",&newco.debut.annee);

                  fprintf(nouveauco,"%.2f %d %d %d/%d/%d %d/%d/%d %d \n",co.numContrat,co.idVoiture,co.idClient,newco.debut.jour,newco.debut.moix,newco.debut.annee,co.fin.jour,co.fin.moix,co.fin.annee,co.cout);	 
                  printf("\n\n\t\t\t\t=======> modifications Bien Sauvegardees ! <=======");
		   } 
   
          else if(choix==4) 
		  {            printf("\n\t\t  Veuillez saisir la nouvelle date du fin de la location : ");
		               printf("\n\t\t\t Entrer le jour: ");
 	                   scanf("%d",&newco.fin.jour);
 	                   printf("\n\t\t\t Entrer le mois: ");
                       scanf("%d",&newco.fin.moix);
 	                   printf("\n\t\t\t Entrer l'annee: ");
 	                   scanf("%d",&newco.fin.annee);
	             
				 fprintf(nouveauco,"%.2f %d %d %d/%d/%d %d/%d/%d %d \n",co.numContrat,co.idVoiture,co.idClient,co.debut.jour,co.debut.moix,co.debut.annee,newco.fin.jour,newco.fin.moix,newco.fin.annee,co.cout);	 
                 printf("\n\n\t\t\t\t=======> modifications Bien Sauvegardees ! <=======");
		  } 
  
          else if(choix==5) 
		  {            printf("\n\t\t\t  Veuillez saisir le nouveau cout de la location : ");
                       scanf("%d",&newco.cout);
		             
				fprintf(nouveauco,"%.2f %d %d %d/%d/%d %d/%d/%d %d \n",co.numContrat,co.idVoiture,co.idClient,co.debut.jour,co.debut.moix,co.debut.annee,co.fin.jour,co.fin.moix,co.fin.annee,newco.cout);	 
                printf("\n\n\t\t\t\t=======> modifications Bien Sauvegardees ! <=======");
		  } 
            
          else if(choix>5) { printf("\n\t\t\t\t=======> SVP choisir autre choix (1-->5)!!! <=======\n\n");}
         }

      else fprintf(nouveauco,"%.2f %d %d %d/%d/%d %d/%d/%d %d \n",co.numContrat,co.idVoiture,co.idClient,co.debut.jour,co.debut.moix,co.debut.annee,co.fin.jour,co.fin.moix,co.fin.annee,co.cout);	 
     }
   
     fclose(ancienco);
     fclose(nouveauco);
     remove("contrat.txt");
     rename("nouveau_contrat.txt","contrat.txt");
   
   if(test1!=1){   Chapeau();
                   printf("\n\n\t\t\t\t =======> Contrat Introuvable !!! <======= ");}
    
Fin3();
}

  
void main()
{ 
  Menu_Principal();
}
