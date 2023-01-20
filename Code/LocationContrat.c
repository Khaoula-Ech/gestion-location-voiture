#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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


//fontion Saisie_contrat() permet de faire entrer et enregistrer les infos des contrats dans le fichier contrat

void Saisie_contrat()
 {
 	FILE *f;
 	int i,n;
 	Contrat co;
 	
 	 printf("Entrer le nombre des contrats:");
 	 scanf("%d",&n);
 	 f=fopen("contrat.txt","a");

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
		fprintf(f,"%.2f %d %d %d/%d/%d %d/%d/%d %d \n",co.numContrat,co.idVoiture,co.idClient,co.debut.jour,co.debut.moix,co.debut.annee,co.fin.jour,co.fin.moix,co.fin.annee,co.cout);}	 
		fclose(f);}
 	   
//fonction visualisation_contrat permet de lister les infos contenues dans une contrat à partir de numéro du contrat
void visualisation_contrat()
{   int test=0;
	Contrat co,co_rech;
	system("cls");
	FILE *f;
	f=fopen("contrat.txt","r");
	
	  printf("\n\t\t\t   Veuillez saisir le numero de contrat que vous desirez voir: ");
	  scanf("%f",&co_rech.numContrat);
	  while(fscanf(f,"%f %d %d %d/%d/%d %d/%d/%d %d \n",&co.numContrat,&co.idVoiture,&co.idClient,&co.debut.jour,&co.debut.moix,&co.debut.annee,&co.fin.jour,&co.fin.moix,&co.fin.annee,&co.cout)!=EOF)
	  {
	  	if(co.numContrat==co_rech.numContrat){
	  		test++;
		    printf("\n\t\t\t\t\t**********  Contrat  **********\t\t\t\n");
 	        printf("\n\t             NUM  | ID_VOITURE | ID_CLIENT |   DATE_DEBUT  |    DATE_FIN   |   COUT(DH) \n ");
 	        printf(" \t          ---------------------------------------------------------------------------------\n");
		    printf("\n\t             %.2f |     %2d     |    %2d     |   %d/%d/%d   |   %d/%d/%d   |    %2d  \n",co.numContrat,co.idVoiture,co.idClient,co.debut.jour,co.debut.moix,co.debut.annee,co.fin.jour,co.fin.moix,co.fin.annee,co.cout);
		   }
     }
     if(test==0){ printf("\n\n\t\t\t\t\t =======> Pas de Contrat !!! <======= ");}
fclose(f);
}

void suppression_contrat()
{   Contrat co;
    Voiture v_ret;
    int test2,n;
   FILE *ancienco=fopen("contrat.txt","r");
   FILE *nouveauco=fopen("nouveau_contrat.txt","w");
   printf("\n\n\t\t    Veuillez saisir l'identifiant de la voiture que vous desirez retourner: ");
   scanf("%d",&v_ret.idVoiture);
	while(fscanf(ancienco,"%f %d %d %d/%d/%d %d/%d/%d %d \n",&co.numContrat,&co.idVoiture,&co.idClient,&co.debut.jour,&co.debut.moix,&co.debut.annee,&co.fin.jour,&co.fin.moix,&co.fin.annee,&co.cout)!=EOF)	 
      {  if(co.idVoiture!=v_ret.idVoiture)
          {
		   fprintf(nouveauco,"%.2f %d %d %d/%d/%d %d/%d/%d %d \n",co.numContrat,co.idVoiture,co.idClient,co.debut.jour,co.debut.moix,co.debut.annee,co.fin.jour,co.fin.moix,co.fin.annee,co.cout);	 
          }
        else { test2=1;
               printf("\n\n\t\t\t\t =======> Contrat Supprimee ! <=======");}
      }
   if(test2!=1){printf("\n\n\t\t\t\t   !!!  Contrat inexistable !!!");}
    
    fclose(ancienco);
    fclose(nouveauco);
    remove("contrat.txt");
    rename("nouveau_contrat.txt","contrat.txt");
}

void main()
{
	suppression_contrat();
}
