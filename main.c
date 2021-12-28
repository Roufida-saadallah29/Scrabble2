#include <stdio.h>
#include <stdlib.h>
#include <windows.h>  ///POUR UTILISER Changecolor
#include <time.h>     ///POUR UTILISER srand(time) (aleatoire) et Sleep
#define true  1
#define false 0
#define Dico "liste_francais.txt"  //Dictionnaire
#define lar 160                    //largeur printf_centre

void modifierCord(int x,int y)
{
   COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void Changecolor(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
int ScoreMot(char  plateau[15][15],char mot[],int ligne,int col,char Des)
{
 int MT=6,LD=2,MD=4,TL=3,CT=10,N=1;
 int gr[15][15]={
            {MT,N,N,LD,N,N,N,MT,N,N,N,LD,N,N,MT},
            {N,MD,N,N,N,TL,N,N,N,TL,N,N,N,MD,N},
            {N,N,MD,N,N,N,LD,N,LD,N,N,N,MD,N,N},
            {LD,N,N,MD,N,N,N,LD,N,N,N,MD,N,N,LD},
            {N,N,N,N,MD,N,N,N,N,N,MD,N,N,N,N },
            {N,TL,N,N,N,TL,N,N,N,TL,N,N,N,TL,N},
            {N,N,LD,N,N,N,LD,N,LD,N,N,N,LD,N,N},
            //midLDe
            {MT,N,N,LD,N,N,N,CT,N,N,N,LD,N,N,TL},
            //midLDe
            {N,N,LD,N,N,N,LD,N,LD,N,N,N,LD,N,N},
            {N,TL,N,N,N,TL,N,N,N,TL,N,N,N,TL,N},
            {N,N,N,N,MD,N,N,N,N,N,MD,N,N,N,N },
            {LD,N,N,MD,N,N,N,LD,N,N,N,MD,N,N,LD},
            {N,N,MD,N,N,N,LD,N,LD,N,N,N,MD,N,N},
            { N,MD,N,N,N,TL,N,N,N,TL,N,N,N,MD,N},
            {MT,N,N,LD,N,N,N,MT,N,N,N,LD,N,N,MT}};
    int scorCar=0;
    int scorMot=0;
    int i,j,MDD=0,MTT=0;
    char c;
    if(Des=='H' || Des=='h')
    {
        for(j=col;j<strlen(mot)+col;j++)
        {
                c=plateau[ligne][j];
                if( c == 'E' || c == 'A' || c == 'I' || c == 'O' || c == 'N' || c == 'R' || c == 'T' || c == 'L' || c == 'S' || c == 'U' ) scorCar=1;
                else if( c == 'D' || c == 'G' || c == 'M') scorCar=2;
                else if( c == 'B' || c == 'C'  || c == 'P' ) scorCar=3;
                else if( c == 'F' || c == 'H' || c == 'V'   ) scorCar=4;
                else if( c == 'J' || c == 'Q' ) scorCar=8;
                else if( c == 'K' || c == 'W'|| c == 'X' || c == 'Y'|| c == 'Z') scorCar=10;
                else if( c == '-' ) scorCar=0;
                else scorCar=0;
                if((gr[ligne][j]==LD) || (gr[ligne][j]==TL) || (gr[ligne][j]==N)) //on verifie si les case sont colorees
                    scorCar=scorCar*gr[ligne][j];
            scorMot=scorMot+scorCar;
                if(gr[ligne][j]==MD )                  // pour  double mot
                   MDD++;
                if(gr[ligne][j]==MT)                   //pour triple mot
                  MTT++;

        }
        if(MDD!=0)                                 //on va multiplier le score de mot *2 si on trouve une case de MD
            scorMot=scorMot*MD*2;
        if(MTT!=0)
            scorMot=scorMot*MT*3;
    }
    if(Des=='V' || Des=='v')
    {
        for(i=ligne;i<strlen(mot)+ligne;i++)
        {
            c=plateau[i][col];
                if( c == 'E' || c == 'A' || c == 'I' || c == 'O' || c == 'N' || c == 'R' || c == 'T' || c == 'L' || c == 'S' || c == 'U' ) scorCar=1;
                else if( c == 'D' || c == 'G' || c == 'M') scorCar=2;
                else if( c == 'B' || c == 'C'  || c == 'P' ) scorCar=3;
                else if( c == 'F' || c == 'H' || c == 'V'   ) scorCar=4;
                else if( c == 'J' || c == 'Q' ) scorCar=8;
                else if( c == 'K' || c == 'W'|| c == 'X' || c == 'Y'|| c == 'Z') scorCar=10;
                else if( c == '-' ) scorCar=0;
                else scorCar=0;
                if((gr[i][col]==LD) || (gr[i][col]==TL) || (gr[i][col]==N)) //on verifie si les case sont colorees
                    scorCar=scorCar*gr[i][col];
                scorMot=scorMot+scorCar;
                if(gr[i][col]==MD )                  // pour  double mot
                   MDD++;
                if(gr[i][col]==MT)                   //pour triple mot
                  MTT++;
        }
        if(MDD!=0)                                 //on va multiplier le score de mot *2 si on trouve une case de MD
            scorMot=scorMot*MD*2;
        if(MTT!=0)
            scorMot=scorMot*MT*3;
    }
    return scorMot;
}
void Plateau(char grille[15][15],int x,int y)
{
    int MT=6,LD=2,MD=4,TL=3,CT=10,N=1;
    int gr[15][15]={
            {MT,N,N,LD,N,N,N,MT,N,N,N,LD,N,N,MT},
            {N,MD,N,N,N,TL,N,N,N,TL,N,N,N,MD,N},
            {N,N,MD,N,N,N,LD,N,LD,N,N,N,MD,N,N},
            {LD,N,N,MD,N,N,N,LD,N,N,N,MD,N,N,LD},
            {N,N,N,N,MD,N,N,N,N,N,MD,N,N,N,N },
            {N,TL,N,N,N,TL,N,N,N,TL,N,N,N,TL,N},
            {N,N,LD,N,N,N,LD,N,LD,N,N,N,LD,N,N},
            //midLDe
            {MT,N,N,LD,N,N,N,CT,N,N,N,LD,N,N,TL},
            //midLDe
            {N,N,LD,N,N,N,LD,N,LD,N,N,N,LD,N,N},
            {N,TL,N,N,N,TL,N,N,N,TL,N,N,N,TL,N},
            {N,N,N,N,MD,N,N,N,N,N,MD,N,N,N,N },
            {LD,N,N,MD,N,N,N,LD,N,N,N,MD,N,N,LD},
            {N,N,MD,N,N,N,LD,N,LD,N,N,N,MD,N,N},
            { N,MD,N,N,N,TL,N,N,N,TL,N,N,N,MD,N},
            {MT,N,N,LD,N,N,N,MT,N,N,N,LD,N,N,MT}};
            modifierCord(x,y);
            printf("00 01 02 03 04 05 06 07 08 09 10 11 12 13 14\n");
            modifierCord(x,y+1);
           printf("_____________________________________________\n");
            for(int i=0;i<15;i++)
            {
                modifierCord(x-3,y+2+i);
                for(int j=0;j<15;j++)
                {
                    if(j==0)
                    {
                        if(i>9)
                          printf("%d|",i);
                        else
                            printf("0%d|",i);
                    }

                    switch(gr[i][j])
                    {
                    case 10:
                        Changecolor(0,14); //jaune
                        break;
                    case 6:
                        Changecolor(0,12);
                        break;
                    case 4:
                         Changecolor(0,13);
                      break;

                    case 3:
                        Changecolor(0,9);
                      break;
                    case 2:
                       Changecolor(0,11);
                      break;
                    default:
                        Changecolor(0,15);
                     break;
                    }

                  printf(" %c ",grille[i][j]);
                 Changecolor(0,15);
                 if(j==14)
                 {
                     printf("|");
                 }


            }

        printf("\n");

        }
        modifierCord(x-1,y+17);
        printf("|_____________________________________________|\n");
}
void printf_cadremenu(int x1, int x2, int y1,int y2,int col) /*Procédure qui affiche un cadre d'une couleur spécifiée sur la console*/
{
	int a,k;
	Changecolor(col,15);
	k=x2;
	for(a=x1;a<x2;a++){
	modifierCord(a,y2);
	printf("\333\333");
	modifierCord(k,y1);
	printf("\333\333");
	k--;
	}
	k=y2;
	for(a=y1;a<y2;a++){
	modifierCord(x1,a);
	printf("\333\333");
	modifierCord(x2,k);
	printf("\333\333");
	k--;
	}
	Changecolor(0,15);
}
void printf_cadremenu2(int x1, int x2, int y1,int y2,int col) /*Procédure qui affiche un cadre d'une couleur spécifiée sur la console*/
{
	int a,k;
	Changecolor(col,15);
	k=x2;
	for(a=x1;a<x2;a++){
	modifierCord(a,y2);
	printf("\333\333");
	modifierCord(k,y1);
	printf("\333\333");
	k--;
	Sleep(1);
	}
	k=y2;
	for(a=y1;a<y2;a++){
	modifierCord(x1,a);
	printf("\333\333");
	modifierCord(x2,k);
	printf("\333\333");
	k--;
	Sleep(1);
	}
	Changecolor(0,15);
}

void InitialerGrille(char grille[15][15])
{
     for(int i=0;i<15;i++)
     {
      for(int j=0;j<15;j++)
          grille[i][j]=' ';
     }
}

char*  SupprimerCar (char ch[],int index) // fonction qui supprime la lettre d'indice i dans un chaine de caractere
{
    int i=index;
    int lonongeur=strlen(ch);
    while(i<lonongeur)
     {
        ch[i]=ch[i+1];
         i++;
     }
     ch[i-1]='\0';
     return ch;
}
void  rechercheCar(char mot[],char car,int *trouv,int *i)
{
    *i=0;
    *trouv=0;
    while(((*i)<strlen(mot))&&!(*trouv))
    {
        if( mot[*i]==car )
        {
            (*trouv)=1;
        }
        (*i)++;
    }
}
void AjouterCar(char lesLettre[],char Sac[10],int nb)
{
    int alea;
    int i;
    srand(time(NULL));
    for( i=0;i<nb;i++)
    {
        alea=rand() % strlen(Sac);
        lesLettre[i]=Sac[alea];
        strcpy(Sac,SupprimerCar(Sac,alea));
    }
    lesLettre[i]='\0';
}
void Les7Lettres(char Sac[],char chaine[])
{

        char plus[8];
        AjouterCar(plus,Sac,7-strlen(chaine));
        strcat(chaine,plus);
}

int  MotExist(char nomFichier[],char mot[15]) //recherche Mot dans un fichier (dictionnaire)
{
   char chaine[50];
   int exist=false;
   FILE *pFile;
   pFile = fopen(nomFichier, "r");
   if(pFile==NULL)
   {
    printf("problm");
    return 0;
   }
   do
   {
       fscanf(pFile,"%s",chaine);
       if(strcmp(chaine,mot)==0)
        exist=true;
   }while(!feof(pFile)&&(!exist));

     fclose(pFile);
     return exist;
}

int PlateauVide(char plateau[15][15])
{
    int trouve=true;
    int i=0;
    int j=0;
    while(i<15 && trouve)
    {

        while(j<15 && trouve)
        {
            if(plateau[i][j]!=' ')
            {
                trouve=false;
            }
            j++;
        }
        i++;
        j=0;
    }
    return trouve;
}
int Verifier(char plateau[15][15],char mot[],int ligne,int col,char Des)
{
    int verif=false;
    if(ligne>15 || col>15)
    {
        return false;
    }
    if(Des=='H' || Des=='h')
    {
        if(col+strlen(mot)-1>15)
            return false;
        int i=col;
        while(i<strlen(mot)+col)
        {
           if(plateau[ligne][i]==mot[i-col])
               verif=true;
            else
            {
                if((plateau[ligne][i]!=' ') && plateau[ligne][i]!=mot[i-col] )
                {
                    verif=false;
                    break;
                }
            }
            i++;
        }
    }
    if(Des=='V' || Des=='v')
    {
        if(ligne+strlen(mot)-1>15)
            return false;
        int i=ligne;
        while(i<strlen(mot)+ligne)
        {
            if(plateau[i][col]==mot[i-ligne])
               verif=true;
            if((plateau[i][col]!=' ') &&plateau[i][col]!=mot[i-ligne] )
                {
                    verif=0;
                    break;
                }
            i++;
        }
    }
    return verif;
}
void AjouterMotDansPlateau(char plateau[15][15],char mot[],int ligne,int col,char Des)
{
  if(Des=='H' || Des=='h')
  {
      for(int j=col;j<strlen(mot)+col;j++)
      {
          plateau[ligne][j]=mot[j-col];
      }
  }
  if(Des=='V' || Des=='v')
  {
      for(int j=ligne;j<strlen(mot)+ligne;j++)
      {
          plateau[j][col]=mot[j-ligne];
      }
  }
}
void PlaceMotDanPlateau(char plateau[15][15],char LettreTire[8],char mot[],int ligne,int col,char Des,int *stop)
{

    int trouve;
    int trouve2=false;
    int i=0;
    int index;
    *stop=false;
    char LettreTireremp[8];
    sprintf(LettreTireremp,"%s",LettreTire);
    while(i<strlen(mot)&&(!*stop))
    {
       rechercheCar(LettreTireremp,mot[i],&trouve,&index);
       if(Des=='H' || Des=='h')
       {
           if(plateau[ligne][i+col]!=mot[i] && plateau[ligne][i+col]!=' ')
               *stop=false;
           if(plateau[ligne][i+col]!=mot[i])
           {

            if(!trouve)
             {
              *stop=true;
              break;
             }
             else
             {
                strcpy(LettreTireremp,SupprimerCar(LettreTireremp,index-1)) ;
             }

           }

       }
       if(Des=='V' || Des=='v')
       {
          if(plateau[ligne+i][col]!=mot[i]&& plateau[ligne+i][col]!=' ')
               *stop=false;
           if(plateau[ligne+i][col]!=mot[i])
           {
             if(trouve)
             {
                strcpy(LettreTireremp,SupprimerCar(LettreTireremp,index-1)) ;
             }
            else
             {
              *stop=true;
              break;
             }
           }

       }

       i++;
    }
    if(!*stop)
    {
     strcpy(LettreTire,LettreTireremp);
     AjouterMotDansPlateau(plateau,mot,ligne,col,Des);
    }

 }

/*************************************  choix de nombre des jeuouers  *********************************/
void Deux_Joueurs(char Sac[104])
{
    char plateau[15][15];
    char choix[2],Des[2];
    char choice,Dest;
    char LettreTire1[8]="";
    char LettreTire2[8]="";
    char mot[8];
    int stop;
    int ligne,col,bolmot=false,bolCord=false;
    int scor1=0;
    int scor2=0;
    InitialerGrille(plateau);
    printf_cadremenu(10,50,2,20,5);
    Plateau(plateau,57,2);
    printf_cadremenu2(5,105,0,25,11);
Jou1:
    system("cls");  //saute de page
    printf_cadremenu(10,50,2,20,5);
    Plateau(plateau,57,2);
    printf_cadremenu(5,105,0,25,11);
    Les7Lettres(Sac,LettreTire1);
    modifierCord(15,3);
    printf("************ JOUEUR 1 **********");
    modifierCord(14,5);
    printf("Les Lettres :  %s",LettreTire1);
    modifierCord(14,6);
    printf("-----------------------------------");
    modifierCord(14,7);
    printf("-C- continuer /-P- passer/-S- SWAP:");

    do
    {

      modifierCord(20,8);
      printf("                 ");
      modifierCord(20,8);
      scanf("%s",choix);
      choice=choix[0];
    }while(choice!='S'&& choice!='P' && choice!='C');
    if(choice=='P')
        goto Jou2;
    if(choice=='S')
    {
        srand(time(NULL));
        int alea=rand() % strlen(LettreTire1);
        Sac[strlen(Sac)]=LettreTire1[alea];
        SupprimerCar(LettreTire1,alea);
        scor1--;
        goto Jou1;
    }

    modifierCord(14,9);
    printf("--------------------------");
    modifierCord(14,10);
    printf("Donner le mot :");
    do
    {
        modifierCord(29,10);
        printf("          ");
        modifierCord(29,10);
        scanf("%s",mot);

    }while(strlen(mot)<2 || !MotExist(Dico,mot));
    modifierCord(14,11);
    printf("-----------------------");
    modifierCord(14,12);
    printf("Donner La destination :");

    do
    {
        modifierCord(38,12);
        printf("    ");
        modifierCord(38,12);
        scanf("%s",Des);
        Dest=Des[0];
    }while(Dest!='H'&&Dest!='h' && Dest!='V' && Dest!='v');
    modifierCord(14,13);
    printf("----------------------");
    modifierCord(14,14);
    printf("Donner les Cordonnes :");
    bolCord=false;
    do
    { modifierCord(23,15);
      printf("  ");
      modifierCord(34,15);
      printf("  ");
      modifierCord(14,15);
      printf(" ligne = ");
      scanf("%d",&ligne);
      modifierCord(25,15);
      printf("  col =  ");
      scanf("%d",&col);

      if(PlateauVide(plateau))
      {

          if(Dest=='H'|| Dest=='h')
          {
                if(ligne==7 )
                {
                    if (col<7 &&(col+strlen(mot)-1>=7) )
                    {
                           bolCord=true;
                    }
                    else
                    {
                        if(col==7)
                            bolCord=true;
                    }
                }
                else
                    bolCord=false;
          }
          else
          {
           if(Dest=='V'|| Dest=='v')
           {
                if(col==7 )
                {
                    if ((ligne<7 &&(ligne+strlen(mot)-1>=7))|| ligne==7)
                    {
                           bolCord=true;
                    }
                }
                else
                    bolCord=false;
           }
          }

      }
      else
      {
            bolCord=true;
      }
    }while(!bolCord);
    modifierCord(25,17);
    if(!PlateauVide(plateau))
    {
      if(Verifier(plateau,mot,ligne,col,Dest)==false)
      {
           goto Jou1;
      }
    }

    PlaceMotDanPlateau(plateau,LettreTire1,mot,ligne,col,Dest,&stop);
    if(stop)
    {
        goto Jou1;
    }
        scor1=scor1+ScoreMot(plateau,mot,ligne,col,Dest);
Jou2:
    system("cls");
    printf_cadremenu(10,50,2,20,5);
    Plateau(plateau,57,2);
    printf_cadremenu(5,105,0,25,11);
    Les7Lettres(Sac,LettreTire2);
    modifierCord(15,3);
    printf("************ JOUEUR 2 **********");
    modifierCord(14,5);
    printf("Les Lettres :  %s",LettreTire2);
    modifierCord(14,6);
    printf("-----------------------------------");
    modifierCord(14,7);
    printf("-C- continuer /-P- passer/-S- SWAP:");
    do
    {
      modifierCord(20,8);
      printf(" ");
      modifierCord(20,8);
      scanf("%s",choix);
      choice=choix[0];
    }while(choice!='S'&& choice!='P' && choice!='C');

    if(choice=='P')
        goto Jou1;
    if(choice=='S')
    {
        srand(time(NULL));
        int alea=rand() % strlen(LettreTire2);
        Sac[strlen(Sac)]=LettreTire2[alea];
        SupprimerCar(LettreTire2,alea);
        scor2--;
        goto Jou2;
    }
    modifierCord(14,9);
    printf("--------------------------");
    modifierCord(14,10);
    printf("Donner le mot :");
    bolmot=false;
    do
    {
        modifierCord(29,10);
        printf("       ");
        modifierCord(29,10);
        scanf("%s",mot);
        if(MotExist(Dico,mot))
            bolmot=true;

    }while(strlen(mot)<2 && !bolmot);
    modifierCord(14,11);
    printf("-----------------------");
    modifierCord(14,12);
    printf("Donner La destination :");
    do
    {
        modifierCord(38,12);
        printf(" ");
        modifierCord(38,12);
        scanf("%s",Des);
        Dest=Des[0];
    }while(Dest!='H'&&Dest!='h' && Dest!='V' && Dest!='v');
    modifierCord(14,13);
    printf("----------------------");
    modifierCord(14,14);
    bolCord=false;
    printf("Donner les Cordonnes :");
    do
    {
      modifierCord(14,15);
      printf(" ligne = ");
      scanf("%d",&ligne);
      modifierCord(25,15);
      printf("  col =  ");
      scanf("%d",&col);
      if(PlateauVide(plateau))
      {
          if(Dest=='H'|| Dest=='h')
          {
                if(ligne==7 )
                {
                    if ((col<7 &&(col+strlen(mot)-1>=7))|| col==7)
                    {
                           bolCord=true;
                    }
                }
          }
          if(Dest=='V'|| Dest=='v')
          {
                if(col==7 )
                {
                    if ((ligne<7 &&(ligne+strlen(mot)-1>=7))|| ligne==7)
                    {
                           bolCord=true;
                    }
                }
          }
      }
      else
      {
            bolCord=true;
      }
     }while(!bolCord);
     modifierCord(25,17);

    if(!PlateauVide(plateau))
    {
     if(Verifier(plateau,mot,ligne,col,Dest)==false)
     {
            goto Jou2;
     }
    }
    PlaceMotDanPlateau(plateau,LettreTire2,mot,ligne,col,Dest,&stop);
    modifierCord(14,20);
    if(stop)
    {
        goto Jou2;
    }
    scor2=scor2+ScoreMot(plateau,mot,ligne,col,Dest);
    system("cls");
    Plateau(plateau,57,2);
    printf_cadremenu(5,105,0,25,11);
  //  system("cls");
    printf("\n\n\n");
    modifierCord(10,3);
    printf("  ****************************************\n");
    modifierCord(10,4);
    printf("               Score joueur 1 : %d      \n",scor1);
    modifierCord(10,5);
    printf("  *****************************************\n");
    modifierCord(10,8);
    printf("  *****************************************\n");
    modifierCord(10,9);
    printf("             Score joueur 2 : %d         \n",scor2);
    modifierCord(10,10);
    printf("  ****************************************\n\n\n\n");
     modifierCord(10,15);
     printf("  [ 0 ] - QUITTER");
     modifierCord(10,16);
     printf("  [ 1 ] - CONTINUER");
     int Q;
     do
     {
         modifierCord(30,18);
         printf("Entrer Un choix :");
         modifierCord(30,19);
         scanf("%d",&Q);
     }while(Q!=0 && Q!=1);
     if(Q==1)
        goto Jou1;
}
void printf_centre (const char* str,int coltext,int colfond) /*Procédure qui permet d'imprimer un texte centré sur la console*/
{
    Changecolor(0,15);
    int n,v;
    v=(lar-strlen(str)) / 2;
    for (n = 0; n < v; n++)
    {
        putchar(' ');
    }
    Changecolor(coltext,colfond);
    printf("%s", str);
    Changecolor(0,15);
    for (n=(v+strlen(str)); n< 166;n++){
        putchar(' ');
    }
}
void MI(int x,int y) /*Procédure qui permet d'afficher le mot "1MI" sur la console*/
{
    Changecolor(1,15);
    modifierCord(x,y);
    printf("   \333\333");
    modifierCord(x,y+1);
    printf("    \333 ");
    modifierCord(x,y+2);
    printf("    \333");
    modifierCord(x,y+3);
    printf("    \333");
    modifierCord(x,y+4);
    printf("    \333");
    Sleep(500);
    ///////////////////
    modifierCord(x+8,y);
    printf("\333\333        \333\333");
    modifierCord(x+8,y+1);
    printf("\333 \333      \333 \333");
    modifierCord(x+8,y+2);
    printf("\333  \333    \333  \333");
    modifierCord(x+8,y+3);
    printf("\333   \333  \333   \333");
    modifierCord(x+8,y+4);
    printf("\333    \333\333    \333");

    ///////////////////////
    Sleep(500);
    modifierCord(x+22,y);
    printf("\333");
    modifierCord(x+22,y+1);
    printf("\333");
    modifierCord(x+22,y+2);
    printf("\333");
    modifierCord(x+22,y+3);
    printf("\333");
    modifierCord(x+22,y+4);
    printf("\333");
	Changecolor(15,0);
}
void intro() /*Procédure qui affiche des informations sur le travail entrepris*/
{
    modifierCord(1,9);
	printf_centre("Mini projet",12,11);
	modifierCord(1,11);
	Changecolor(12,15);
	printf_centre("JEUX SCRABBLE",12,15);
	modifierCord(1,14);
	Sleep(500);
	printf_centre("Ce travail vous est presente par:",8,15);
	Sleep(1000);
	modifierCord(1,16);
	Changecolor(1,15);
	printf_centre("SAADALLAH   ROUFIDA",1,15);
	modifierCord(1,17);
	modifierCord(1,20);
	//Changecolor(8,15);
	Sleep(1000);
	printf_centre("Matiere: Algorithmique et structures de donnees",0,15);
	MI(75,23);
	modifierCord(1,30);
	printf_centre("Annee universitaire: 2020/2021",0,15);
	Changecolor(0,15);
	printf_cadremenu2(50,110,7,32,4);
	Sleep(1000);
}
int main()
{
system("color f0");
intro();
modifierCord(1,34);
system("pause");
system("cls");
char SacDesLettres[104]="EEEEEEEEEEEEEEEAAAAAAAAAIIIIIIIINNNNNNOOOOOORRRRRRSSSSSSTTTTTTUUUUUULLLLLDDDMMMGGBBCCPPFFHHVV--JQKWXYZ";
Deux_Joueurs(SacDesLettres);
modifierCord(2,25);
    return 0;
}

