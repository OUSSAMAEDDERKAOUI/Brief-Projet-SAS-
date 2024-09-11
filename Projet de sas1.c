#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int count=0 ;
int choix, n,i,j;
int plusieur ;
int found1=0;
int conteur=0;
int nb;
char PHYSIQUE;
char CHIMIE;
char MATH ;
char GEOLOGIE;
int NEDP = 0, NEDC = 0, NEDM = 0, NEDG = 0;


typedef struct
{
    int Numero_unique;
    char Nom[50];
    char Prenom[30];
    char Date_de_naissance[30];
    char  Departement[30];
    float Note_generale;
} GESTION;
GESTION gestion [100];
GESTION temp ;
GESTION seuil;
GESTION temp1;
char nomcherche[20];
char Departement[30];
char Rechercher_depart [20];
float found3;

void ajouter ( GESTION gestion[] )
{
    // printf (" Numero unique : ===>") ;
    //  scanf ("%s",gestion[count].Numero_unique);
    //  printf("\n");
    gestion[count].Numero_unique= time(NULL);
    char Departement;

    printf (" Nom        ===>") ;
    scanf ("%s",gestion[count].Nom);
    printf("\n");
    printf (" Prenom: ===>") ;
    scanf ("%s",gestion[count].Prenom);
    printf("\n");
    printf (" Date de naissance: ===>") ;
    scanf ("%s",gestion[count].Date_de_naissance );
    printf("\n");
    printf (" Note generale: ===>") ;
    scanf ("%f",&gestion[count].Note_generale);
    printf("\n");
    do
    {
        printf("Veuillez saisir '1' pour le Département de PHYSIQUE, '2' pour CHIMIE, '3' pour MATH, '4' pour Geologie: ");
        scanf(" %d", &nb);

        switch (nb)
        {
        case '1':
            strcpy (gestion[count].Departement, "PHYSIQUE");
            break;
        case '2':
            strcpy(gestion[count].Departement , "CHIMIE");
            break;
        case '3':
            strcpy(gestion[count].Departement , "MATH");
            break;
        case '4':
            strcpy (gestion[count].Departement ,"GEOLOGIE");
            break;
        default:
            printf("Département invalide. Veuillez réessayer.\n");
        }
    }
    while (Departement != 'p' && Departement != 'c' && Departement != 'm' && Departement != 'g');

    count ++;
}


void aficher ()
{
    for (i=0; i<count; i++)
    {
        printf("##############################################################\n");
        printf("#                        L'etudiant %d                        #\n",i+1);
        printf("##############################################################\n");
        printf("#   ==>Numero unique :           #%15d            #\n",gestion[i].Numero_unique);
        printf("#   ==>Le nom                    #%15s            #\n",gestion[i].Nom );
        printf("#   ==>Le prenom                 #%15s            #\n",gestion[i].Prenom );
        printf("#   ==>La date naissance         #%15s            #\n",gestion[i].Date_de_naissance);
        printf("#   ==>Departement               #%15s            #\n",gestion[i].Departement);
        printf("#   ==>La Note generale:         #%15.2f            #\n",gestion[i].Note_generale );
        printf("##############################################################\n");

    }
}
void Tri_nom ()
{
    for (i=0; i<count-1; i++)
    {
        for (j=0; j<count-1-i; j++)
        {
            if (strcmp(gestion[j].Nom,gestion[j+1].Nom)>0)
            {
                temp=gestion[j];
                gestion[j]=gestion[j+1];
                gestion[j+1]=temp;
            }
        }

    }

}

void Tri_note()
{

    for (i = 1; i < count; i++)
    {
        temp1 = gestion[i];
        j = i - 1;

        while (j >= 0 && temp1.Note_generale < gestion[j].Note_generale)
        {
            gestion[j + 1] = gestion[j];
            j--;
        }

        gestion[j + 1] = temp1;
    }

    printf("La liste des étudiants a été triée avec succès!\n");
}


void Rechercher ()
{
    printf("vous avez choisissez rechercher un etudiant (recherche sequensielle)");
    printf ("veuillez entrer le nom cherche .");
    scanf("%s",nomcherche);
    for (i=0; i<count; i++)
    {
        if (strcmp(gestion[i].Nom,nomcherche)==0)
        {
            found1=1;
            break;
        }


    }
    if (found1==1)
    {
        printf("##############################################################\n");
        printf("#                        L'etudiant %d                        #\n",i+1);
        printf("##############################################################\n");
        printf("#   ==>Numero unique :           #%15d            #\n",gestion[i].Numero_unique);
        printf("#   ==>Le nom                    #%15s            #\n",gestion[i].Nom );
        printf("#   ==>Le prenom                 #%15s            #\n",gestion[i].Prenom );
        printf("#   ==>La date naissance         #%15s            #\n",gestion[i].Date_de_naissance);
        printf("#   ==>Departement               #%15s            #\n",gestion[i].Departement);
        printf("#   ==>La Note generale:         #%15.2f            #\n",gestion[i].Note_generale );
        printf("##############################################################\n");
    }
    else
        printf("le nom cherche n'existe pas au contact  .");
}

void Rechercher_departement ()
{

    char Rechercher_depart[40];
do{
     printf("Veuillez entrer un département spécifique 'PHYSIQUE', 'CHIMIE', 'MATH' ou 'GEOLOGIE': \n");
    scanf(" %s", Rechercher_depart);
}while (strcmp(Rechercher_depart, "PHYSIQUE") != 0 && strcmp(Rechercher_depart, "CHIMIE") != 0 && strcmp(Rechercher_depart, "MATH") != 0 && strcmp(Rechercher_depart, "GEOLOGIE") != 0);
    int found = 0;
    for (i = 0; i < count; i++)
    {
        if (strcmp(gestion[i].Departement,Rechercher_depart )==0)
        {
            printf("##############################################################\n");
            printf("#                        L'étudiant %d                        #\n", i + 1);
            printf("##############################################################\n");
            printf("#   ==> Numéro unique :           #%15d            #\n", gestion[i].Numero_unique);
            printf("#   ==> Le nom                    #%15s            #\n", gestion[i].Nom);
            printf("#   ==> Le prénom                 #%15s            #\n", gestion[i].Prenom);
            printf("#   ==> La date de naissance      #%15s            #\n", gestion[i].Date_de_naissance);
            printf("#   ==> La Note générale :        #%15.2f            #\n", gestion[i].Note_generale);
            printf("##############################################################\n");
            found = 1;
        }
    }

    if (!found)
    {
        printf("Aucun étudiant trouvé dans le département spécifié.\n");
    }
}

void nbr_dans_departement()
{
    for (i = 0; i < count; i++)
    {
        if (strcmp(gestion[i].Departement,"PHYSIQUE" )==0)
            NEDP++;
           if (strcmp(gestion[i].Departement,"CHIMIE" )==0)
            NEDC++;
           if (strcmp(gestion[i].Departement,"MATH" )==0)
            NEDM++;
            if (strcmp(gestion[i].Departement,"GEOLOGIE")==0)
            NEDG++;
        }

    printf("Nombre d'étudiants dans chaque département:\n");
    printf("Physique: %d\n", NEDP);
    printf("Chimie: %d\n", NEDC);
    printf("Math: %d\n", NEDM);
    printf("Géologie: %d\n", NEDG);
}



int main ()
{
    do
    {
        printf("#################################################################################\n");
        printf("#                 Projet : Gestion des etudiants dans une universite            #\n");
        printf("#################################################################################\n");
        printf("#                                                                               #\n");
        printf("#     1 ==> Ajouter un étudiant .                                               #\n");
        printf("#                                                                               #\n");
        printf("#     2 ==> Afficher les détails d'un étudiant .                                #\n");
        printf("#                                                                               #\n");
        printf("#     3 ==> Trier un étudiant.                                                  #\n");
        printf("#                                                                               #\n");
        printf("#     4 ==> Rechercher un étudiant  .                                           #\n");
        printf("#                                                                               #\n");
        printf("#     5 ==> Modifier ou supprimer les informations d'un étudiant .              #\n");
        printf("#                                                                               #\n");
        printf("#     6 ==> Statistiques  .                                                     #\n");
        printf("#                                                                               #\n");
        printf("#     7 ==> ..........................                                          #\n");
        printf("#                                                                               #\n");
        printf("#     8 ==> ....................                                                #\n");
        printf("#                                                                               #\n");
        printf("#     0 ==> fermer le programme .                                               #\n");
        printf("#                                                                               #\n");
        printf("#################################################################################\n");
        printf("\n");

        printf ("veuillez entrer votre choix :");
        scanf ("%d",&choix) ;


        switch (choix)
        {
        case 0 :
            break;
        case 1 :
            printf ("veuillez entrer votre choix : \n");
            printf (" a ==> Ajouter un etudiant : \n") ;
            printf (" b ==> Ajouter plusieures etudiants : \n") ;
            printf (" c ==> Ajouter  automatique des etudiants : \n") ;

            scanf (" %c",&n);

            switch ( n )
            {
            case 'a' :
                ajouter(gestion);
                break;
            case 'b':
                printf ("veuillez entrer le nombre des etidiants :");
                scanf("%d",&plusieur);
                for (i=0; i<plusieur; i++)
                {
                    ajouter ( gestion );
                }
                break;
            case 'c' :

                // Étudiant 1
                gestion[count++] = (GESTION)
                {
                    .Numero_unique = time(NULL), .Nom = "RADI", .Prenom = "Marie", .Date_de_naissance = "15/03/2001", .Note_generale = 14.5, .Departement = "PHYSIQUE"
                };

                // Étudiant 2
                gestion[count++] = (GESTION)
                {
                    .Numero_unique = time(NULL), .Nom = "SAMI", .Prenom = "MERYEM", .Date_de_naissance = "22/11/1999", .Note_generale = 12.0, .Departement = "CHIMIE"
                };

                // Étudiant 3
                gestion[count++] = (GESTION)
                {
                    .Numero_unique = time(NULL), .Nom = "KARI", .Prenom = "OUSSAMA", .Date_de_naissance = "05/07/2000", .Note_generale = 19.5, .Departement = "MATH"
                };

                // Étudiant 4
                gestion[count++] = (GESTION)
                {
                    .Numero_unique = time(NULL), .Nom = "TAKI", .Prenom = "ALI", .Date_de_naissance = "30/09/2002", .Note_generale = 11.5, .Departement = "GEOLOGIE"
                };

                // Étudiant 5
                gestion[count++] = (GESTION)
                {
                    .Numero_unique = time(NULL), .Nom = "DAMI", .Prenom = "AHMED", .Date_de_naissance = "12/12/2001", .Note_generale = 19.0, .Departement = "PHYSIQUE"
                };

                // Étudiant 6
                gestion[count++] = (GESTION)
                {
                    .Numero_unique = time(NULL), .Nom = "SAJI", .Prenom = "SAMIR", .Date_de_naissance = "17/02/2000", .Note_generale = 13.0, .Departement = "CHIMIE"
                };

                // Étudiant 7
                gestion[count++] = (GESTION)
                {
                    .Numero_unique = time(NULL), .Nom = "RAZI", .Prenom = "HAMZA", .Date_de_naissance = "20/04/2002", .Note_generale = 9.5, .Departement = "MATH"
                };

                // Étudiant 8
    gestion[count++] = (GESTION){
                    .Numero_unique = time(NULL), .Nom = "DARI", .Prenom = "AMIR", .Date_de_naissance = "18/08/1999", .Note_generale = 13.75, .Departement = "GEOLOGIE"
                };
                // Étudiant 9
                gestion[count++] = (GESTION)
                {
                    .Numero_unique = time(NULL), .Nom = "MAZI", .Prenom = "SAID", .Date_de_naissance = "21/04/2000", .Note_generale = 18.0, .Departement = "MATH"
                };

                // Étudiant 10
    gestion[count++] = (GESTION){
                    .Numero_unique = time(NULL), .Nom = "YARI", .Prenom = "MOHAMED", .Date_de_naissance = "27/08/1989", .Note_generale = 10.0, .Departement = "PHYSIQUE"
                };

                break;
            }
            break;
        case 2 :
            aficher ();
            break;
        case  3 :
            printf ("veuillez entrer votre choix : \n");
            printf (" a ==> Tri alphabetique des etudiants en fonction de leur nom . \n") ;
            printf (" b ==> Tri des étudiants par moyenne générale, du plus élevé au plus faible . \n") ;

            scanf (" %c",&n);

            switch ( n )
            {
            case 'a':
                Tri_nom ();
                aficher ();
                break;
            case 'b':
                Tri_note ();
                aficher ();

                break;
            }
            break;
        case 4 :
            printf ("veuillez entrer votre choix : \n");
            printf (" a ==> Rechercher un étudiant par son nom . \n") ;
            printf (" b ==> Afficher la liste des étudiants inscrits dans un département spécifique. \n") ;
            scanf (" %c",&n);
            switch ( n )
            {
            case 'a':
                Rechercher ();
                break;
            case 'b':
                Rechercher_departement();
                break;
            }
            break;
        case 5 :
            printf ("veuillez entrer votre choix : \n");
            printf (" a ==> Afficher le nombre total d'étudiants inscrits. \n") ;
            printf (" b ==> Afficher le nombre d'étudiants dans chaque département. \n") ;
            printf (" c ==>Afficher les étudiants ayant une moyenne générale supérieure à un certain seuil.\n") ;
            printf (" d ==> Afficher les 3 étudiants ayant les meilleures notes.\n") ;
            printf (" e ==> Afficher le nombre d'étudiants ayant réussi dans chaque département. \n") ;
            scanf (" %c",&n);
            char Rechercher_depart ;
            char nbr ;
            switch ( n )
            {
            case 'a':
                printf(" le nombre total d'étudiants inscrits est %d .\n",count);
                break;
            case 'b':
                nbr_dans_departement();
                break;
            case 'c':
                printf ("veuillez entrer un certain seuil ");
                float seuil;
                scanf("%f",&seuil);
                int found = 0;
                for (int i = 0; i < count; i++)
                {
                    if (gestion[i].Note_generale > seuil)
                    {
                        found3++;
                        {

                            printf("##############################################################\n");
                            printf("#       Les étudiants avec une note générale supérieure à %.2f         #\n", seuil);
                            printf("##############################################################\n");
                            found = 1;
                        }

                        printf("##############################################################\n");
                        printf("#                        L'étudiant %d                        #\n", i + 1);
                        printf("##############################################################\n");
                        printf("#   ==> Numéro unique :           #%15d            #\n", gestion[i].Numero_unique);
                        printf("#   ==> Le nom                    #%15s            #\n", gestion[i].Nom);
                        printf("#   ==> Le prénom                 #%15s            #\n", gestion[i].Prenom);
                        printf("#   ==> La date de naissance      #%15s            #\n", gestion[i].Date_de_naissance);
                        printf("#   ==> Département               #%15s            #\n",
                               (gestion[i].Departement == PHYSIQUE ? "PHYSIQUE" :
                                gestion[i].Departement == CHIMIE ? "CHIMIE" :
                                gestion[i].Departement == MATH ? "MATH" : "GEOLOGIE"));
                        printf("#   ==> La Note générale :        #%15.2f            #\n", gestion[i].Note_generale);
                        printf("##############################################################\n");
                    }
                }

                if (found3==0)
                    printf("Aucun étudiant n'a une note générale supérieure à %.2f.\n", seuil);

                break;
            case 'd':
                Tri_note();
                for(i=count-1; i>count-4; i--)
                {
                    printf("##############################################################\n");
                    printf("#                        L'étudiant %d                        #\n", i + 1);
                    printf("##############################################################\n");
                    printf("#   ==> Numéro unique :           #%15d            #\n", gestion[i].Numero_unique);
                    printf("#   ==> Le nom                    #%15s            #\n", gestion[i].Nom);
                    printf("#   ==> Le prénom                 #%15s            #\n", gestion[i].Prenom);
                    printf("#   ==> La date de naissance      #%15s            #\n", gestion[i].Date_de_naissance);
                    printf("#   ==> Département               #%15s            #\n", (gestion[i].Departement == PHYSIQUE ? "PHYSIQUE" :
                            gestion[i].Departement == CHIMIE ? "CHIMIE" :
                            gestion[i].Departement == MATH ? "MATH" : "GEOLOGIE"));
                    printf("#   ==> La Note générale :        #%15.2f            #\n", gestion[i].Note_generale);
                    printf("##############################################################\n");
                }
                break;
            case 'e':

                break;

            }
            break;
        }

        system ("pause");
        system ("cls");
    }
    while (choix!=0);


    return 0;
}
