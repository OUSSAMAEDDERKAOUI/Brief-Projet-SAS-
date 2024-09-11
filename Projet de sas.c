#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int count=0 ;
int choix, n,i,j;
int plusieur ;
int found1=0;
typedef enum
{
    PHYSIQUE,
    CHIMIE,
    MATH,
    GEOLOGIE
} Department;
typedef struct
{
    int Numero_unique;
    char Nom[50];
    char Prenom[30];
    char Date_de_naissance[30];
    Department Departement;
    float Note_generale;
} GESTION;
GESTION gestion [100];
GESTION temp ;
GESTION temp1;
char nomcherche[20];
char Departement;
char Rechercher_depart [20];

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
        printf("Veuillez saisir 'p' pour le D�partement de PHYSIQUE, 'c' pour CHIMIE, 'm' pour MATH, 'g' pour G�ologie: ");
        scanf(" %c", &Departement);

        switch (Departement)
        {
        case 'p':
            gestion[count].Departement = PHYSIQUE;
            break;
        case 'c':
            gestion[count].Departement = CHIMIE;
            break;
        case 'm':
            gestion[count].Departement = MATH;
            break;
        case 'g':
            gestion[count].Departement = GEOLOGIE;
            break;
        default:
            printf("D�partement invalide. Veuillez r�essayer.\n");
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
        switch (gestion[i].Departement)
        {
        case PHYSIQUE:
            printf("    ==>  Departement             #           PHYSIQUE        #\n");
            break;
        case CHIMIE:
            printf("    ==>   Departement            #            CHIMIE        #\n");
            break;
        case MATH:
            printf("    ==>   Departement            #             MATH          #\n");
            break;
        case GEOLOGIE:
            printf("Departement                      #             GEOLOGIE       #\n");
            break;
        default:
            printf("D�partement inconnu\n");
        }
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

    printf("La liste des �tudiants a �t� tri�e avec succ�s!\n");
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


    char Rechercher_depart;

    printf("Veuillez entrer un d�partement sp�cifique : ");
    scanf(" %c", &Rechercher_depart);

    // Convertir le caract�re entr� en valeur de l'�num�ration Department
    switch (Rechercher_depart)
    {
        case 'p':
            Rechercher_depart = PHYSIQUE;
            break;
        case 'c':
            Rechercher_depart = CHIMIE;
            break;
        case 'm':
            Rechercher_depart = MATH;
            break;
        case 'g':
            Rechercher_depart = GEOLOGIE;
            break;
        default:
            printf("D�partement invalide. Veuillez entrer 'p', 'c', 'm' ou 'g'.\n");
            return;
    }

    int found = 0;
    for (i = 0; i < count; i++)
    {
        if (gestion[i].Departement == Rechercher_depart)
        {
            printf("##############################################################\n");
            printf("#                        L'�tudiant %d                        #\n", i + 1);
            printf("##############################################################\n");
            printf("#   ==> Num�ro unique :           #%15d            #\n", gestion[i].Numero_unique);
            printf("#   ==> Le nom                    #%15s            #\n", gestion[i].Nom);
            printf("#   ==> Le pr�nom                 #%15s            #\n", gestion[i].Prenom);
            printf("#   ==> La date de naissance      #%15s            #\n", gestion[i].Date_de_naissance);
            printf("#   ==> D�partement               #%15s            #\n", (gestion[i].Departement == PHYSIQUE ? "PHYSIQUE" :
                                                                      gestion[i].Departement == CHIMIE ? "CHIMIE" :
                                                                      gestion[i].Departement == MATH ? "MATH" : "GEOLOGIE"));
            printf("#   ==> La Note g�n�rale :        #%15.2f            #\n", gestion[i].Note_generale);
            printf("##############################################################\n");
            found = 1;
        }
    }

    if (!found)
    {
        printf("Aucun �tudiant trouv� dans le d�partement sp�cifi�.\n");
    }
}




int main ()
{
    do
    {
        printf("#################################################################################\n");
        printf("#                 Projet : Gestion des etudiants dans une universite            #\n");
        printf("#################################################################################\n");
        printf("#                                                                               #\n");
        printf("#     1 ==> Ajouter un �tudiant .                                               #\n");
        printf("#                                                                               #\n");
        printf("#     2 ==> Afficher les d�tails d'un �tudiant .                                #\n");
        printf("#                                                                               #\n");
        printf("#     3 ==> Trier un �tudiant.                                                  #\n");
        printf("#                                                                               #\n");
        printf("#     4 ==> Rechercher un �tudiant  .                                           #\n");
        printf("#                                                                               #\n");
        printf("#     5 ==> Modifier ou supprimer les informations d'un �tudiant .              #\n");
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
{
    // �tudiant 1
    gestion[count++] = (GESTION){ .Numero_unique = time(NULL), .Nom = "RADI", .Prenom = "Marie", .Date_de_naissance = "15/03/2001", .Note_generale = 14.5, .Departement = PHYSIQUE };

    // �tudiant 2
    gestion[count++] = (GESTION){ .Numero_unique = time(NULL), .Nom = "SAMI", .Prenom = "MERYEM", .Date_de_naissance = "22/11/1999", .Note_generale = 12.0, .Departement = CHIMIE };

    // �tudiant 3
    gestion[count++] = (GESTION){ .Numero_unique = time(NULL), .Nom = "KARI", .Prenom = "OUSSAMA", .Date_de_naissance = "05/07/2000", .Note_generale = 19.5, .Departement = MATH };

    // �tudiant 4
    gestion[count++] = (GESTION){ .Numero_unique = time(NULL), .Nom = "TAKI", .Prenom = "ALI", .Date_de_naissance = "30/09/2002", .Note_generale = 11.5, .Departement = GEOLOGIE };

    // �tudiant 5
    gestion[count++] = (GESTION){ .Numero_unique = time(NULL), .Nom = "DAMI", .Prenom = "AHMED", .Date_de_naissance = "12/12/2001", .Note_generale = 19.0, .Departement = PHYSIQUE };

    // �tudiant 6
    gestion[count++] = (GESTION){ .Numero_unique = time(NULL), .Nom = "SAJI", .Prenom = "SAMIR", .Date_de_naissance = "17/02/2000", .Note_generale = 13.0, .Departement = CHIMIE };

    // �tudiant 7
    gestion[count++] = (GESTION){ .Numero_unique = time(NULL), .Nom = "RAZI", .Prenom = "HAMZA", .Date_de_naissance = "23/04/2002", .Note_generale = 18.0, .Departement = MATH };

    // �tudiant 8
    gestion[count++] = (GESTION){ .Numero_unique = time(NULL), .Nom = "PARI", .Prenom = "REDOUAN", .Date_de_naissance = "08/08/1999", .Note_generale = 10.0, .Departement = GEOLOGIE };
}

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
        
            break;
        case 6:
            break;

        }
        system ("pause");
        system ("cls");
    }
    while (choix!=0);


    return 0;
}
