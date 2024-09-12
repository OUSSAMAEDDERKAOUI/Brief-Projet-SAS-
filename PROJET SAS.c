#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int count=0 ;
int count2=0 ;
int choix,n,i,j;
int plusieur ;
int found1=0;
int conteur=0;
int nb;
int num_modifie;

char PHYSIQUE;
char CHIMIE;
char MATH ;
char GEOLOGIE;
int NEDP = 0, NEDC = 0, NEDM = 0, NEDG = 0;
int NEVP = 0, NEVC = 0, NEVM = 0, NEVG = 0;
float  MGDP = 0,MGDC = 0,MGDM =0,MGDG =0, MGUE =0;
int num_supp;

int CP=0,CC =0,CM=0,CG=0;
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
GESTION temp_supp[50] ;

char nomcherche[20];
char Departement[30];
char Rechercher_depart [20];
float found3;

void ajouter ( GESTION gestion[] )
{
    char Departement;
    int num_tmp ;
    int num_trouve=0;

    printf("\n");
    printf (" numero unique         ===>") ;

    scanf ("%d",&num_tmp);

    for(int i=0 ; i< count ; i++)
    {

        if(gestion[i].Numero_unique==num_tmp)
        {
            printf("cette numero deja exist");

            return;
        }
    }
    gestion[count].Numero_unique=num_tmp;

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
        printf("Veuillez saisir le Departement :\n'1' pour  PHYSIQUE .\n'2' pour CHIMIE .\n'3' pour MATH .\n'4' pour Geologie: \n ");
        scanf(" %d", &nb);

        switch (nb)
        {
        case 1:
            strcpy (gestion[count].Departement, "PHYSIQUE");
            break;
        case 2:
            strcpy(gestion[count].Departement, "CHIMIE");
            break;
        case 3:
            strcpy(gestion[count].Departement, "MATH");
            break;
        case 4:
            strcpy (gestion[count].Departement,"GEOLOGIE");
            break;
        default:
            printf("D�partement invalide. Veuillez r�essayer.\n");
        }
    }
    while ( nb!= 1 && nb != 2 && nb != 3 && nb != 4);

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
        {printf("##############################################################\n");
        printf("#                        L'etudiant %d                        #\n",i+1);
        printf("##############################################################\n");
        printf("#   ==>Numero unique :           #%15d            #\n",gestion[i].Numero_unique);
        printf("#   ==>Le nom                    #%15s            #\n",gestion[i].Nom );
        printf("#   ==>Le prenom                 #%15s            #\n",gestion[i].Prenom );
        printf("#   ==>La date naissance         #%15s            #\n",gestion[i].Date_de_naissance);
        printf("#   ==>Departement               #%15s            #\n",gestion[i].Departement);
        printf("#   ==>La Note generale:         #%15.2f            #\n",gestion[i].Note_generale );
        printf("##############################################################\n");
       found1==1;
        }
    }
    if (found1==0)
        printf("le nom cherche n'existe pas au contact  .");
}

void Rechercher_departement ()
{

    char Rechercher_depart[40];
    do
    {
        printf("Veuillez entrer un d�partement sp�cifique 'PHYSIQUE', 'CHIMIE', 'MATH' ou 'GEOLOGIE': \n");
        scanf(" %s", Rechercher_depart);
    }
    while (strcmp(Rechercher_depart, "PHYSIQUE") != 0 && strcmp(Rechercher_depart, "CHIMIE") != 0 && strcmp(Rechercher_depart, "MATH") != 0 && strcmp(Rechercher_depart, "GEOLOGIE") != 0);
    int found = 0;
    for (i = 0; i < count; i++)
    {
        if (strcmp(gestion[i].Departement,Rechercher_depart )==0)
        {
            printf("##############################################################\n");
            printf("#                        L'�tudiant %d                        #\n", i + 1);
            printf("##############################################################\n");
            printf("#   ==> Num�ro unique :           #%15d            #\n", gestion[i].Numero_unique);
            printf("#   ==> Le nom                    #%15s            #\n", gestion[i].Nom);
            printf("#   ==> Le pr�nom                 #%15s            #\n", gestion[i].Prenom);
            printf("#   ==>Departement               #%15s            #\n",gestion[i].Departement);
            printf("#   ==> La date de naissance      #%15s            #\n", gestion[i].Date_de_naissance);
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

    printf("Nombre d'�tudiants dans chaque d�partement:\n");
    printf("Physique: %d\n", NEDP);
    printf("Chimie: %d\n", NEDC);
    printf("Math: %d\n", NEDM);
    printf("G�ologie: %d\n", NEDG);
}
void tri_reussite ()
{
    Tri_note();
    for (i=0; i<count; i++)
    {
        if(gestion[i].Note_generale>=10)
        {
            printf("##############################################################\n");
            printf("#                        L'�tudiant %d                        #\n", i + 1);
            printf("##############################################################\n");
            printf("#   ==> Num�ro unique :           #%15d            #\n", gestion[i].Numero_unique);
            printf("#   ==> Le nom                    #%15s            #\n", gestion[i].Nom);
            printf("#   ==> Le pr�nom                 #%15s            #\n", gestion[i].Prenom);
            printf("#   ==>Departement               #%15s            #\n",gestion[i].Departement);
            printf("#   ==> La date de naissance      #%15s            #\n", gestion[i].Date_de_naissance);
            printf("#   ==> La Note g�n�rale :        #%15.2f            #\n", gestion[i].Note_generale);
            printf("##############################################################\n");
        }
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
        printf("#     5 ==> Statistiques  .                                                     #\n");
        printf("#                                                                               #\n");
        printf("#     6 ==> Modifier ou supprimer les informations d'un �tudiant .              #\n");
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
            printf (" 1 ==> Ajouter un etudiant : \n") ;
            printf (" 2 ==> Ajouter plusieures etudiants : \n") ;
            printf (" 3 ==> Ajouter  automatique des etudiants : \n") ;

            scanf (" %d",&n);

            switch ( n )
            {
            case 1 :
                ajouter(gestion);
                break;
            case 2:
                printf ("veuillez entrer le nombre des etidiants :");
                scanf("%d",&plusieur);
                for (i=0; i<plusieur; i++)
                {
                    ajouter ( gestion );
                }
                break;
            case 3 :

                // �tudiant 1
                gestion[count++] = (GESTION)
                {
                    .Numero_unique =1454870, .Nom = "RADI", .Prenom = "Marie", .Date_de_naissance = "15/03/2001", .Note_generale = 14.5, .Departement = "PHYSIQUE"
                };

                // �tudiant 2
                gestion[count++] = (GESTION)
                {
                    .Numero_unique =1454871, .Nom = "SAMI", .Prenom = "MERYEM", .Date_de_naissance = "22/11/1999", .Note_generale = 12.0, .Departement = "CHIMIE"
                };

                // �tudiant 3
                gestion[count++] = (GESTION)
                {
                    .Numero_unique = 1454872, .Nom = "KARI", .Prenom = "OUSSAMA", .Date_de_naissance = "05/07/2000", .Note_generale = 19.5, .Departement = "MATH"
                };

                // �tudiant 4
                gestion[count++] = (GESTION)
                {
                    .Numero_unique = 1454873, .Nom = "TAKI", .Prenom = "ALI", .Date_de_naissance = "30/09/2002", .Note_generale = 11.5, .Departement = "GEOLOGIE"
                };

                // �tudiant 5
                gestion[count++] = (GESTION)
                {
                    .Numero_unique = 1454874, .Nom = "DAMI", .Prenom = "AHMED", .Date_de_naissance = "12/12/2001", .Note_generale = 19.0, .Departement = "PHYSIQUE"
                };

                // �tudiant 6
                gestion[count++] = (GESTION)
                {
                    .Numero_unique = 1454875, .Nom = "SAJI", .Prenom = "SAMIR", .Date_de_naissance = "17/02/2000", .Note_generale = 13.0, .Departement = "CHIMIE"
                };

                // �tudiant 7
                gestion[count++] = (GESTION)
                {
                    .Numero_unique = 1454876, .Nom = "TAKI", .Prenom = "HAMZA", .Date_de_naissance = "20/04/2002", .Note_generale = 9.5, .Departement = "MATH"
                };

                // �tudiant 8
                gestion[count++] = (GESTION)
                {
                    .Numero_unique = 1454877,
                    .Nom = "DARI",
                    .Prenom = "AMIR",
                    .Date_de_naissance = "18/08/1999",
                    .Note_generale = 13.75,
                    .Departement = "GEOLOGIE"
                };
                // �tudiant 9
                gestion[count++] = (GESTION)
                {
                    .Numero_unique = 1454878, .Nom = "MAZI", .Prenom = "SAID", .Date_de_naissance = "21/04/2000", .Note_generale = 18.0, .Departement = "MATH"
                };

                // �tudiant 10
                gestion[count++] = (GESTION)
                {
                    .Numero_unique = 1454879, .Nom = "YARI", .Prenom = "MOHAMED", .Date_de_naissance = "27/08/1989", .Note_generale = 10.0, .Departement = "PHYSIQUE"
                };

                break;
            }
            break;
        case 2 :
            aficher ();
            break;
        case  3 :
            printf ("veuillez entrer votre choix : \n");
            printf (" 1 ==> Tri alphabetique des etudiants en fonction de leur nom . \n") ;
            printf (" 2 ==> Tri des etudiants par moyenne generale, du plus eleve au plus faible . \n") ;
            printf (" 3 ==> Tri des �tudiants selon leur statut de r�ussite . \n") ;

            scanf (" %d",&n);

            switch ( n )
            {
            case 1 :
                Tri_nom ();
                aficher ();
                break;
            case 2:
                Tri_note ();
                aficher ();
                break;
            case 3 :
                tri_reussite();
                break;
            }
            break;
        case 4 :
            printf ("veuillez entrer votre choix : \n");
            printf (" 1 ==> Rechercher un �tudiant par son nom . \n") ;
            printf (" 2 ==> Afficher la liste des etudiants inscrits dans un departement specifique. \n") ;
            scanf (" %d",&n);
            switch ( n )
            {
            case 1:
                Rechercher ();
                break;
            case 2:
                Rechercher_departement();
                break;
            }
            break;
        case 5 :
            printf ("veuillez entrer votre choix : \n");
            printf (" 1 ==> Afficher le nombre total d'etudiants inscrits. \n") ;
            printf (" 2 ==> Afficher le nombre d'etudiants dans chaque departement. \n") ;
            printf (" 3 ==> Afficher les etudiants ayant une moyenne generale superieure � un certain seuil.\n") ;
            printf (" 4 ==> Afficher les 3 etudiants ayant les meilleures notes.\n") ;
            printf (" 5 ==> Afficher le nombre d'etudiants ayant r�ussi dans chaque departement. \n") ;
            printf (" 6 ==> Afficher la moyenne generale de chaque departement et de l'universite entiere. \n") ;
            scanf (" %d",&n);
            char Rechercher_depart ;
            char nbr ;
            switch ( n )
            {
            case 1:
                printf(" le nombre total d'�tudiants inscrits est %d .\n",count);
                break;
            case 2:
                nbr_dans_departement();
                break;
            case 3:
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
                            printf("#       Les �tudiants avec une note g�n�rale sup�rieure � %.2f         #\n", seuil);
                            printf("##############################################################\n");
                            found = 1;
                        }

                        printf("##############################################################\n");
                        printf("#                        L'�tudiant %d                        #\n", i + 1);
                        printf("##############################################################\n");
                        printf("#   ==> Num�ro unique :           #%15d            #\n", gestion[i].Numero_unique);
                        printf("#   ==> Le nom                    #%15s            #\n", gestion[i].Nom);
                        printf("#   ==> Le pr�nom                 #%15s            #\n", gestion[i].Prenom);
                        printf("#   ==> La date de naissance      #%15s            #\n", gestion[i].Date_de_naissance);
                        printf("#   ==>Departement               #%15s            #\n",gestion[i].Departement);
                        printf("#   ==> La Note g�n�rale :        #%15.2f            #\n", gestion[i].Note_generale);
                        printf("##############################################################\n");
                    }
                }

                if (found3==0)
                    printf("Aucun �tudiant n'a une note g�n�rale sup�rieure � %.2f.\n", seuil);

                break;
            case 4 :
                Tri_note();
                for(i=count-1; i>count-4; i--)
                {
                    printf("##############################################################\n");
                    printf("#                        L'�tudiant %d                        #\n", i + 1);
                    printf("##############################################################\n");
                    printf("#   ==> Num�ro unique :           #%15d            #\n", gestion[i].Numero_unique);
                    printf("#   ==> Le nom                    #%15s            #\n", gestion[i].Nom);
                    printf("#   ==> Le pr�nom                 #%15s            #\n", gestion[i].Prenom);
                    printf("#   ==> La date de naissance      #%15s            #\n", gestion[i].Date_de_naissance);
                    printf("#   ==>Departement               #%15s            #\n",gestion[i].Departement);
                    printf("#   ==> La Note g�n�rale :        #%15.2f            #\n", gestion[i].Note_generale);
                    printf("##############################################################\n");
                }
                break;
            case 5 :
                for (i = 0; i < count; i++)
                {
                    if (strcmp(gestion[i].Departement,"PHYSIQUE" )==0)
                    {
                        if (gestion[i].Note_generale>=10)
                            NEVP++;
                    }
                    if (strcmp(gestion[i].Departement,"CHIMIE")==0)
                    {
                        if (gestion[i].Note_generale>=10)
                            NEVC++;
                    }
                    if (strcmp(gestion[i].Departement,"MATH" )==0)
                    {
                        if (gestion[i].Note_generale>=10)
                            NEVM++;
                    }
                    if (strcmp(gestion[i].Departement,"GEOLOGIE" )==0)
                    {
                        if (gestion[i].Note_generale>=10)
                            NEVG++;
                    }
                }
                printf("##############################################################\n");
                printf("#             Le nombre d'�tudiants ayant r�ussi             #\n");
                printf("##############################################################\n");
                printf("#                                                            #\n");
                printf("#   ==> Le nombre  dans departement de PHYSIQUE :   #   %d    #\n", NEVP);
                printf("#                                                            #\n");
                printf("#   ==> Le nombre  dans departement de CHIMIE :     #   %d    #\n", NEVC);
                printf("#                                                            #\n");
                printf("#   ==> Le nombre  dans departement de MATHEMATIQUE:#   %d    #\n", NEVM);
                printf("#                                                            #\n");
                printf("#   ==> Le nombre  dans departement de GEOLOGIE :   #   %d    #\n", NEVG);
                printf("#                                                            #\n");
                printf("##############################################################\n");

                break;
            case 6 :
                for (i = 0; i < count; i++)
                {
                    MGUE = MGUE +gestion[i].Note_generale ;

                    MGUE = MGUE + gestion[i].Note_generale;
                    if (strcmp(gestion[i].Departement,"PHYSIQUE" )==0)
                    {
                        MGDP  = MGDP + gestion[i].Note_generale;
                        CP++;
                    }
                    if (strcmp(gestion[i].Departement,"CHIMIE")==0)
                    {
                        MGDC += gestion[i].Note_generale;
                        CC++;
                    }
                    if (strcmp(gestion[i].Departement,"MATH" )==0)
                    {
                        MGDM += gestion[i].Note_generale;
                        CM++;
                    }
                    if (strcmp(gestion[i].Departement,"GEOLOGIE" )==0)
                    {
                        MGDG += gestion[i].Note_generale;
                        CG++;
                    }
                }
                printf("##########################################################################\n");
                printf("#          la moyenne generale de chaque departement                     #\n");
                printf("##########################################################################\n");
                printf("#                                                                        #\n");
                printf("#   ==> La moyenne generale du departement de PHYSIQUE :     #   %.2f   #\n", MGDP/CP);
                printf("#                                                                        #\n");
                printf("#   ==> La moyenne generale du departement de CHIMIE :       #   %.2f   #\n", MGDC/CC);
                printf("#                                                                        #\n");
                printf("#   ==> La moyenne generale du departement de MATHEMATIQUE:  #   %.2f   #\n", MGDM/CM);
                printf("#                                                                        #\n");
                printf("#   ==> La moyenne generale du departement de  GEOLOGIE :    #   %.2f   #\n", MGDG/CG);
                printf("#                                                                        #\n");
                printf("##########################################################################\n");
                printf ("\n");
                float MGUE = 0;

                for (int i = 0; i < count; i++)
                {
                    MGUE += gestion[i].Note_generale;
                }

                printf("##############################################################\n");
                printf("#         la moyenne generale de l'universite entiere.       #\n");
                printf("##############################################################\n");
                printf("#                                                            #\n");

                if (count > 0)
                {
                    printf("#   ==> La moyenne generale de l'universite entiere :# %.2f #\n", MGUE / (count));
                }
                else
                {
                    printf("#   ==> Aucun �tudiant dans l'universit� pour calculer la moyenne g�n�rale. #\n");
                }

                printf("#                                                            #\n");
                printf("##############################################################\n");
                break;
            }
            break;
        case 6 :
            printf ("veuillez entrer votre choix : \n");
            printf (" 1 ==> Modifier les informations d'un �tudiant en fonction de son num�ro unique . \n") ;
            printf (" 2 ==> Supprimer les informations d'un �tudiant en fonction de son num�ro unique . \n") ;
            scanf ("%d",&n);
            switch (n)
            {
            case 1 :
                printf ("veuillez entrer le numero a modifie : \n");
                scanf ("%d",&num_modifie);
                int count_modifie=0;
                for (i=0; i<count; i++)
                {
                    if(num_modifie==gestion[i].Numero_unique)
                    {
                        count_modifie++;
                        printf (" Nouveau Nom        ===>") ;
                        scanf ("%s",gestion[i].Nom);
                        printf("\n");
                        printf ("  Nouveau Prenom: ===>") ;
                        scanf ("%s",gestion[i].Prenom);
                        printf("\n");
                        printf (" Nouvelle Date de Naissance: ===>") ;
                        scanf ("%s",gestion[i].Date_de_naissance );
                        printf("\n");
                        printf (" Nouveau Note Generale: ===>") ;
                        scanf ("%f",&gestion[i].Note_generale);
                        printf("\n");
                        do
                        {
                            printf("Veuillez saisir le Departement :\n'1' pour  PHYSIQUE .\n'2' pour CHIMIE .\n'3' pour MATH .\n'4' pour Geologie: \n ");
                            scanf(" %d", &nb);

                            switch (nb)
                            {
                            case 1:
                                strcpy (gestion[count].Departement, "PHYSIQUE");
                                break;
                            case 2:
                                strcpy(gestion[count].Departement, "CHIMIE");
                                break;
                            case 3:
                                strcpy(gestion[count].Departement, "MATH");
                                break;
                            case 4:
                                strcpy (gestion[count].Departement,"GEOLOGIE");
                                break;
                            default:
                                printf("D�partement invalide. Veuillez reessayer.\n");
                            }
                        }
                        while ( nb!= 1 && nb != 2 && nb != 3 && nb != 4);

                    }

                }
                if (count_modifie==0)
                {
                    printf ("le numero unique n'existe pas \n");
                }
                break;
            case 2 :
                printf ("veuillez entrer le numero a supprimer : \n");
                scanf ("%d",&num_supp);
                int count_supp=0;
                for (i=0; i<count; i++)
                {
                    if(num_supp==gestion[i].Numero_unique)
                    {
                        count_supp++;
                        for (j=i; j<count ; j++)
                        {
                            temp_supp[j] =gestion[j];
                            gestion [j] = gestion [j+1];
                            gestion [j+1] = temp_supp[j];
                            printf("Les information est supprimer avec succes !\n");
                            count --;
                        }
                    }
                }
                if (count_supp==0)
                {
                    printf("le numero unique invalide. Veuillez reessayer.!\n");
                }
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
