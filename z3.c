#include <stdio.h>
#include <stdlib.h>

typedef struct ptica {

    int id;
    char naziv[30];
    struct ptica* levi;
    struct ptica* desni;

}ptica;


void ubaci_pticu(ptica **koren, ptica *nova){


    if(*koren == NULL){
        printf("Koren je NULL \n");
        *koren = nova;
        nova->desni = NULL;
        nova->levi = NULL;
    }else{
        if(nova->id < (*koren)->id ){
            ubaci_pticu( & ((*koren)->levi), nova );
        }else{
            ubaci_pticu( &((*koren)->desni), nova );
        }
    }  
}


void dodaj_cvor(ptica** koren, ptica* cvor) {
    if (*koren == NULL) {
        *koren = cvor;
        cvor->levi = NULL;
        cvor->desni = NULL;
    }
    else {
        if (cvor->id < (*koren)->id)
            dodaj_cvor(&((*koren)->levi), cvor);
        else
            dodaj_cvor(&((*koren)->desni), cvor);
    }
}


ptica* ucitaj(char fajl[30]){

    FILE* f = fopen(fajl, "r");
    ptica* koren = NULL;

    int n;
    fscanf(f, "%d", &n);

    printf("n je: %d\n", n);

  

    for(int i =0; i <n; i++){
        printf("a i=%d \n",i);

         ptica* temp = malloc(sizeof(ptica) );


        fscanf(f, "%d", &temp->id);
        fscanf(f, "%s", temp->naziv);

        printf("b i=%d \n",i);

        // ubaci_pticu(&koren, temp);  
        dodaj_cvor(&koren, temp) ;

        printf("c i=%d \n",i);     


    } 
    return koren;

}

void ispisi_pticu(ptica* koren){
    printf("id: %d  ime: %s  \n", koren->id, koren->naziv);
}

void ispisi_stablo(ptica *koren){
    ispisi_pticu(koren);
    if(koren->desni != NULL) ispisi_stablo(koren->desni);
    if(koren->levi != NULL) ispisi_stablo(koren->levi);
}

int main()
{
    printf(" KRECE PROGRAM \n");

    ptica* koren =  ucitaj("ptice.txt");


    printf("Ispisujemo \n");

    ispisi_stablo(koren);

    printf("\n KRAJ PROGRAMA ");
    return 0;
}
