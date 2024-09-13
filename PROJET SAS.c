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

int etajouter = 0;

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
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
void ajouter ( GESTION gestion[] )
{
    char Departement;
    int num_tmp ;
    int num_trouve=0;

    printf("\n");


debut:
        printf (" numero unique    ===>") ;
        scanf ("%d",&num_tmp);
        for(int i=0 ; i< count ; i++)
        {

            if(gestion[i].Numero_unique==num_tmp)
            {
                printf("cette numero deja exist\n");

                goto debut ;
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
                printf("Département invalide. Veuillez réessayer.\n");
            }
        }
        while ( nb!= 1 && nb != 2 && nb != 3 && nb != 4);

        count ++;
    }
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

    void aficher ()
    {
        for (i=0; i<count; i++)
        {
            printf("##############################################################\n");
            printf("#                        L'etudiant                          #\n");
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
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
// RECHERCHE PAR NOM
    void Rechercher ()
    {
        printf("vous avez choisissez rechercher un etudiant (recherche sequensielle)");
        printf ("veuillez entrer le nom cherche .");
        scanf("%s",nomcherche);
        for (i=0; i<count; i++)
        {
            if (strcmp(gestion[i].Nom,nomcherche)==0)
            {
                printf("##############################################################\n");
                printf("#                        L'etudiant                           #\n");
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
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
    void Rechercher_departement ()
    {

        char Rechercher_depart[40];
        do
        {
            printf("Veuillez entrer un département spécifique 'PHYSIQUE', 'CHIMIE', 'MATH' ou 'GEOLOGIE': \n");
            scanf(" %s", Rechercher_depart);
        }
        while (strcmp(Rechercher_depart, "PHYSIQUE") != 0 && strcmp(Rechercher_depart, "CHIMIE") != 0 && strcmp(Rechercher_depart, "MATH") != 0 && strcmp(Rechercher_depart, "GEOLOGIE") != 0);
        int found = 0;
        for (i = 0; i < count; i++)
        {
            if (strcmp(gestion[i].Departement,Rechercher_depart )==0)
            {
                printf("##############################################################\n");
                printf("#                        L'étudiant                          #\n");
                printf("##############################################################\n");
                printf("#   ==> Numéro unique :           #%15d            #\n", gestion[i].Numero_unique);
                printf("#   ==> Le nom                    #%15s            #\n", gestion[i].Nom);
                printf("#   ==> Le prénom                 #%15s            #\n", gestion[i].Prenom);
                printf("#   ==>Departement               #%15s            #\n",gestion[i].Departement);
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
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
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
        printf("Geologie: %d\n", NEDG);
    }
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
    void tri_reussite ()
    {
        Tri_note();
        for (i=0; i<count; i++)
        {
            if(gestion[i].Note_generale>=10)
            {
                printf("##############################################################\n");
                printf("#                        L'étudiant                           #\n");
                printf("##############################################################\n");
                printf("#   ==> Numero unique :           #%15d            #\n", gestion[i].Numero_unique);
                printf("#   ==> Le nom                    #%15s            #\n", gestion[i].Nom);
                printf("#   ==> Le prenom                 #%15s            #\n", gestion[i].Prenom);
                printf("#   ==> Departement               #%15s            #\n",gestion[i].Departement);
                printf("#   ==> La date de naissance      #%15s            #\n", gestion[i].Date_de_naissance);
                printf("#   ==> La Note generale :        #%15.2f            #\n", gestion[i].Note_generale);
                printf("##############################################################\n");
            }
        }
    }
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

    int main ()
    {
        do
        {
            printf("#################################################################################\n");
            printf("#                 Projet : Gestion des etudiants dans une universite            #\n");
            printf("#################################################################################\n");
            printf("#                                                                               #\n");
            printf("#     1 ==> Ajouter un etudiant .                                               #\n");
            printf("#                                                                               #\n");
            printf("#     2 ==> Afficher les details d'un etudiant .                                #\n");
            printf("#                                                                               #\n");
            printf("#     3 ==> Trier un etudiant.                                                  #\n");
            printf("#                                                                               #\n");
            printf("#     4 ==> Rechercher un etudiant  .                                           #\n");
            printf("#                                                                               #\n");
            printf("#     5 ==> Statistiques  .                                                     #\n");
            printf("#                                                                               #\n");
            printf("#     6 ==> Modifier ou supprimer les informations d'un etudiant .              #\n");
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
                    if (etajouter == 0)
                    {
                        // Étudiant 1
                        gestion[count++] = (GESTION)
                        {
                            1454870,  "RADI", "Marie",  "15/03/2001", "PHYSIQUE", 14.5
                        };

                        // Étudiant 2
                        gestion[count++] = (GESTION)
                        {
                            1454871,  "SAMI",  "MERYEM",  "22/11/1999", "CHIMIE",12.0
                        };

                        // Étudiant 3
                        gestion[count++] = (GESTION)
                        {
                            1454872,  "EDDERKAOUI",  "OUSSAMA",  "05/07/2000", "MATH",19.5
                        };

                        // Étudiant 4
                        gestion[count++] = (GESTION)
                        {
                            1454873,  "TAKI",  "ALI",  "30/09/2002",   "GEOLOGIE",11.5
                        };

                        // Étudiant 5
                        gestion[count++] = (GESTION)
                        {
                            1454874,  "DAMI", "AHMED",  "12/12/2001",  "PHYSIQUE", 19.0
                        };

                        // Étudiant 6
                        gestion[count++] = (GESTION)
                        {
                            1454875, "SAJI", "SAMIR",  "17/02/2000", "CHIMIE", 8.0
                        };

                        // Étudiant 7
                        gestion[count++] = (GESTION)
                        {
                            1454876,  "AMAOUI",  "HAMZA",  "20/04/2002",  "MATH",9.5
                        };

                        // Étudiant 8
                        gestion[count++] = (GESTION)
                        {
                            1454877,"DARI", "AMIR", "18/08/1999","GEOLOGIE",13.75
                        };
                        // Étudiant 9
                        gestion[count++] = (GESTION)
                        {
                            1454878,  "MAZI",  "SAID",  "21/04/2000", "MATH",  10.0
                        };

                        // Étudiant 10
                        gestion[count++] = (GESTION)
                        {
                            1454879, "BOUTAIB", "ANASS",  "27/08/1989",  "PHYSIQUE",  18.0
                        };

                        etajouter = 1;


                    }
                    else
                    {
                        printf("\nLes etudiants sont deja ajouter\n");
                    }

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
                printf (" 3 ==> Tri des étudiants selon leur statut de réussite . \n") ;

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
                printf (" 1 ==> Rechercher un etudiant par son nom . \n") ;
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
                printf (" 3 ==> Afficher les etudiants ayant une moyenne generale superieure a un certain seuil.\n") ;
                printf (" 4 ==> Afficher les 3 etudiants ayant les meilleures notes.\n") ;
                printf (" 5 ==> Afficher le nombre d'etudiants ayant reussi dans chaque departement. \n") ;
                printf (" 6 ==> Afficher la moyenne generale de chaque departement et de l'universite entiere. \n") ;
                scanf (" %d",&n);
                char Rechercher_depart ;
                char nbr ;
                switch ( n )
                {
                case 1:
                    printf(" le nombre total d'etudiants inscrits est %d .\n",count);
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
                                printf("#       Les etudiants avec une note generale supérieure à %.2f         #\n", seuil);
                                printf("##############################################################\n");
                                found = 1;
                            }

                            printf("##############################################################\n");
                            printf("#                        L'etudiant                         #\n");
                            printf("##############################################################\n");
                            printf("#   ==> Numero unique :           #%15d            #\n", gestion[i].Numero_unique);
                            printf("#   ==> Le nom                    #%15s            #\n", gestion[i].Nom);
                            printf("#   ==> Le prénom                 #%15s            #\n", gestion[i].Prenom);
                            printf("#   ==> La date de naissance      #%15s            #\n", gestion[i].Date_de_naissance);
                            printf("#   ==>Departement               #%15s            #\n",gestion[i].Departement);
                            printf("#   ==> La Note generale :        #%15.2f            #\n", gestion[i].Note_generale);
                            printf("##############################################################\n");
                        }
                    }

                    if (found3==0)
                        printf("Aucun etudiant n'a une note generale superieure à %.2f.\n", seuil);

                    break;
                case 4 :
                    Tri_note();
                    for(i=count-1; i>count-4; i--)
                    {
                        printf("##############################################################\n");
                        printf("#                        L'etudiant                          #\n");
                        printf("##############################################################\n");
                        printf("#   ==> Numero unique :           #%15d            #\n", gestion[i].Numero_unique);
                        printf("#   ==> Le nom                    #%15s            #\n", gestion[i].Nom);
                        printf("#   ==> Le prenom                 #%15s            #\n", gestion[i].Prenom);
                        printf("#   ==> La date de naissance      #%15s            #\n", gestion[i].Date_de_naissance);
                        printf("#   ==> Departement               #%15s            #\n",gestion[i].Departement);
                        printf("#   ==> La Note generale :        #%15.2f            #\n", gestion[i].Note_generale);
                        printf("##############################################################\n");
                    }
                    break;
                case 5 :
                    NEVP = 0;
                    NEVC= 0;
                    NEVM = 0;
                    NEVG = 0;

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
                    printf("#             Le nombre d'etudiants ayant réussi             #\n");
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
                        printf("#   ==> Aucun etudiant dans l'université pour calculer la moyenne generale. #\n");
                    }

                    printf("#                                                            #\n");
                    printf("##############################################################\n");
                    break;
                }
                break;
            case 6 :
                printf ("veuillez entrer votre choix : \n");
                printf (" 1 ==> Modifier les informations d'un étudiant en fonction de son numéro unique . \n") ;
                printf (" 2 ==> Supprimer les informations d'un étudiant en fonction de son numéro unique . \n") ;
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
                                    printf("Departement invalide. Veuillez reessayer.\n");
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
