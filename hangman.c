#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main ()
{
   //lista de cuvinte 
    char cuvinte[][20]={
        "calculator",
        "programare",
        "informatica",
        "algoritm",
        "monitor",
    };

    int totalCuvinte =5;
    srand(time(NULL));
    int randomIndex = rand()% totalCuvinte;
    char cuvant[20];
    strcpy(cuvant, cuvinte[randomIndex]);
    int lungime = strlen(cuvant);
    char cuvantAscuns[20];
     

    for(int i=0; i < lungime; i++)
    {
        cuvantAscuns[i] = '_';
    }

    cuvantAscuns[lungime] = '\0';
    int incercari = 6;

    char probabil; //variabila pt litera intr
    int JocTerminat = 0;

    printf("=====HANGMAN=====");

    //BUCLA PRINCIPALA
    while(incercari>0 && JocTerminat == 0)
    {   
        printf("\nCuvant: %s\n", cuvantAscuns);
        printf("Incercari ramase: %d\n", incercari);

        printf("Introduce litera:");
        scanf(" %c", &probabil);
       

        int descoperit =0 ;
        for(int i=0; i<lungime; i++)
        {  
            //daca litera exista
            if(cuvant[i] == probabil)
            {
                cuvantAscuns[i]= probabil;
                descoperit = 1;
            }
        }
        //daca litera  nu exista 
        if(descoperit == 0)
        {
            incercari --;
            printf("Litera gresita!\n");
        }else{
            printf("Corecta!\n");
        }
        
        if(strcmp(cuvant, cuvantAscuns) == 0)
        {
            JocTerminat = 1;
            printf("\n Felicitari! Ai ghicit cuvantul: %s\n", cuvant);
        }

    }

    return 0;
}