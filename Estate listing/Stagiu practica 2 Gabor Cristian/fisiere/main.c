#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct imobil{
    char tip[50];
    int pret, nrBai,nrCamere;
}imobil;
typedef struct node{
    struct imobil val;
    struct node*next;

}node;
typedef struct list{
    struct node*head;
    struct node*tail;
}list;
imobil createImobil(char *tip,int nrCamere, int nrBai, int pret){
    imobil i;
    strcpy(i.tip, tip);
    i.pret=pret;
    i.nrBai=nrBai;
    i.nrCamere=nrCamere;
    return i;
}
void antet()
{
    printf("1. Afisare lista imobile disponibile.\n");
    printf("2. Selecteaza un anunt.\n");
    printf("3. Afiseaza anunturi salvate.\n");
    printf("0. Iesire aplicatie.\n");
    printf("\n");

}

void adaugareAnunt(list *l, imobil i){
   node*temp1,*temp2,*nodulmeu;
   nodulmeu=(node*)malloc(sizeof(node));
   nodulmeu->val=i;
   nodulmeu->next=NULL;
   temp1=NULL;
   temp2=l->head;
   while(temp2!=NULL){
        if(nodulmeu->val.pret<temp2->val.pret)
            break;
        temp1=temp2;
        temp2=temp2->next;
   }
   nodulmeu->next=temp2;
   if(temp1!=NULL){
    if(temp2==NULL){
        l->tail=nodulmeu;
    }
    temp1->next=nodulmeu;
   }
   else{
        l->head=nodulmeu;
        l->tail=nodulmeu;
   }
}
void salveazaAnunt(list l, int nr){
    node*prim=l.head;
    int i=1;
    while(prim!=NULL)
    {
        if(i==nr)
        {
            FILE *fp;
            fp=fopen("lista salvate.txt","a");
            fprintf(fp,"%s %d %d %d\n",prim->val.tip,prim->val.nrCamere,prim->val.nrBai,prim->val.pret);
            fclose(fp);
        }
        i++;
        prim=prim->next;
    }

}
void print(list l)
{
    node *p;
    p=l.head;

    while(p!= NULL)
    {
     printf("Imobil de tip: %s; numar camere: %d; numar bai: %d; pret: %d",p->val.tip,p->val.nrCamere,p->val.nrBai,p->val.pret);
     printf("\n");
     p=p->next;
     }
}
void cumparaAnunt(list *l, int nr){
    int i=1;
    node*prim;
    char tip[50];
    int nrCamere,nrBai,pret;
    node*poz;
    prim=l->head;
    while(prim->next!=NULL){
        if(i==nr)
            poz=prim;
        prim=prim->next;
        i=i+1;
    }
    prim=l->head;
    if(nr==1)
        {
            node*tmp;
            tmp=l->head;
            l->head=tmp->next;
            free(tmp);
        }
        else
    while(prim->next!=NULL){
        if(prim->next==poz)
        {

            prim->next=prim->next->next;
            free(poz);
        }
        prim=prim->next;
    }
    FILE* fp=fopen("lista imobile.txt","r");
    FILE* fp2=fopen("lista imobileTMP.txt","w");
    i=1;
    while(fscanf(fp,"%s %d %d %d",tip,&nrCamere,&nrBai,&pret)!=EOF){
        if(i!=nr)
            fprintf(fp2,"%s %d %d %d\n",tip,nrCamere,nrBai,pret);
        i++;
    }
    fclose(fp);
    fclose(fp2);
    FILE* fp3=fopen("lista imobile.txt","w");
    FILE* fp4=fopen("lista imobileTMP.txt","r");
    while(fscanf(fp4,"%s %d %d %d",tip,&nrCamere,&nrBai,&pret)!=EOF)
    {
        fprintf(fp3,"%s %d %d %d\n",tip,nrCamere,nrBai,pret);
    }
    fclose(fp3);
    fclose(fp4);


}

int main()
{
    int op;
    int run=1;
    list l;
    l.head=NULL;
     int nrBai,nrCamere,pret;
    char tip[101];
    FILE * filePointer;
    filePointer = fopen("lista imobile.txt","r");
     if ( filePointer == NULL )
        {
            printf( "Fisierul nu poate fi accesat." ) ;
        }
    else
        while(fscanf(filePointer,"%s %d %d %d",tip,&nrCamere,&nrBai,&pret)!=EOF)
           {
                adaugareAnunt(&l,createImobil(tip,nrCamere,nrBai,pret));
           }
           fclose(filePointer);

    while(run==1)
    {

        antet();
        scanf("%d",&op);

  if(op==1){
            print(l);
            printf("\n");
  }

else
    if(op==2){
        int i=1;
        printf("Introduceti numarul anuntului pe care doriti sa-l selectati: ");
        int nrAnunt;
        scanf("%d",&nrAnunt);
            printf("1. Cumpara imobil.\n");
            printf("2. Salveaza anunt.\n");
        int choice;
        scanf("%d",&choice);
        if(choice==2)
            salveazaAnunt(l,nrAnunt);
        else
        {
            cumparaAnunt(&l,nrAnunt);

        }

    }
else
    if(op==0)
    run=0;
else
    if(op==3)
{
     char tipul[101];
    FILE* fp;
    list listaSalvate;
    listaSalvate.head=NULL;
    int nCamere,nBai,price;
    fp=fopen("lista salvate.txt","r");
    if(fp==NULL)
        printf("Fisierul nu poate fi accesat");
    else
    {
        while(fscanf(fp,"%s %d %d %d",tipul,&nCamere,&nBai,&price)!=EOF)
        {

            adaugareAnunt(&listaSalvate,createImobil(tipul,nCamere,nBai,price));
        }

        print(listaSalvate);
    }
    fclose(fp);
}

}
    return 0;
}
