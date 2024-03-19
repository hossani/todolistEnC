#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

int main()
{      char deadline[20];
	int op=1;
	listeTask *liste=malloc(sizeof(listeTask));
	liste->sizeT=0;
while(op!=7 && op>=1 && op<=6){
			Task *t=malloc(sizeof(Task));
		menu();
scanf("%d",&op);
// Pour gerer le caractere de retour a la ligne
getchar();
if(op>7 || op<1) exit(0);
	if(op==1){
				printf("\n\n\t\t**************************************ADD SECTION**************************************\n\n");
printf("Entrer votre nouveau task\n");
//la fonction fgets lira une ligne entière à partir de l'entrée standard (clavier dans ce cas) jusqu'au caractère de nouvelle ligne ('\n')
fgets(t->chaine,sizeof(t->chaine),stdin);
// Pour supprimer le caractère de nouvelle ligne ('\n') du bout de la chaîne lue
t->chaine[strlen(t->chaine) - 1] = '\0';
do{ printf("Entrer votre la date limite du votre nouveau tache (Example: 03/11/2024)\n");
    scanf("%d/%d/%d",&t->jour,&t->mois,&t->annee);
    sprintf(deadline,"%02d/%02d/%04d",t->jour,t->mois,t->annee);
}while(strlen(deadline)!=10 || deadline[2]!='/' || deadline[5]!='/');

do{
	printf("Priorite des taches\nFirst priorite :'F'\nSecond priorite :'S'\nThird priorite : 'T'\n");
	printf("Entrer la prirorite de votre tache : 'F' or 'S' or 'T'\n");
	scanf(" %c",&t->priority);
}while(t->priority!='F' && t->priority!='f'&& t->priority!='S' && t->priority!='s' && t->priority!='T' && t->priority!='t' );
strcpy(t->status,"In process");
add_Task(liste,t);
}
else if(op==5){
display_Task(liste);
} else if(op==2){
modify_Task(liste);
} else if(op==3){
delete_Task(liste);
}
else if(op==6){
isDone_Task(liste);
}
else if(op==4){
	filter_Task(liste);
}
free(t);
}
system("cls");
free(liste);
    return 0;
}
