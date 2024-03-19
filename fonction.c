#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

void menu(){
printf("\n\n\n\n\n\n\t\t\t\t\t\tIn To Do List Select:\n\n");
printf("\t\t\t\t\t\t1. Add New Task:\n\t\t\t\t\t\t2. Modify A Task\n\t\t\t\t\t\t3. Delete A Task\n\t\t\t\t\t\t4. Filter Your Tasks\n\t\t\t\t\t\t5. Display Your Tasks\n\t\t\t\t\t\t6. Mark Your Task As Done\n\t\t\t\t\t\t7. Exit\n\t\t\t\t\t\t");
printf("Select an option :\t");
}
void add_Task(listeTask *listeT,Task *task){
if(listeT->sizeT<100){
		listeT->arrayTasks[listeT->sizeT].jour=task->jour;
	listeT->arrayTasks[listeT->sizeT].mois=task->mois;
		listeT->arrayTasks[listeT->sizeT].annee=task->annee;
		strcpy(listeT->arrayTasks[listeT->sizeT].chaine,task->chaine);
strcpy(listeT->arrayTasks[listeT->sizeT].status,task->status);
listeT->arrayTasks[listeT->sizeT].priority=task->priority;
listeT->sizeT++; }
else { printf("La liste des taches est pleine\n"); } }

void display_Task(listeTask* listeT){
 printf("\n\n\t\t**************************************DISPLAY SECTION**************************************\n\n");
	if(listeT->sizeT==0){ printf("La liste des tasks est vide.\n"); }
	else{ for(int i=0;i<listeT->sizeT;i++){
printf("ID: %d. %s |Deadline : %02d/%02d/%02d |Priority : %c  |Status : %s\n", (i+1), listeT->arrayTasks[i].chaine, listeT->arrayTasks[i].jour,listeT->arrayTasks[i].mois,listeT->arrayTasks[i].annee,listeT->arrayTasks[i].priority, listeT->arrayTasks[i].status);
	} }}

void modify_Task(listeTask *listeT){
	char modifyTask[100]; int index; int mod;
	display_Task(listeT);
printf("\n\n\t\t**************************************MODIFY SECTION**************************************\n\n");
	printf("\n\nEntrez l'ID de la tâche à modifier (Exemple : pour modifier la première tâche, saisissez 1)\n");
	scanf("%d",&index);
	getchar();
	if(index<1 || index>listeT->sizeT){ printf("La tâche que vous avez choisie n'existe pas dans la liste des tâches\n"); }
	else{
	printf("\nEntrez votre modification pour la tâche:\n");
	fgets(modifyTask,sizeof(modifyTask),stdin);
    modifyTask[strlen(modifyTask) - 1] = '\0';
	strcpy(listeT->arrayTasks[index-1].chaine,modifyTask);
	printf("Si vous souhaitez changer la date limite de la tâche, appuyez sur 1\n");
	scanf("%d",&mod);
	if(mod==1){
			int j,m,a;
		printf("Entrez le nouveau jour pour la nouvelle date limite (Exemple : 15)\n");
		scanf("%02d",&j);
		listeT->arrayTasks[index-1].jour=j;
	printf("Entrez le nouveau mois pour la nouvelle date limite (Exemple : 05)\n");
		scanf("%02d",&m);
		listeT->arrayTasks[index-1].mois=m;
		printf("Entrez la nouvelle année pour la nouvelle date limite (Exemple : 2024)\n");
		scanf("%04d",&a);
		listeT->arrayTasks[index-1].annee=a;
	}
	printf("\nTache modifiee avec succes.\n"); } }

void delete_Task(listeTask *listeT){
	display_Task(listeT);
	int index;
	printf("\n\n\t\t**************************************DELETE SECTION**************************************\n\n");
	printf("\n\nEntrez l'ID de la tâche à supprimer (Exemple : pour supprimer la première tâche, appuyez sur 1)\n");
	scanf("%d",&index);
if(index<1||index>listeT->sizeT){
	printf("La tâche que vous avez sélectionnée n'existe pas dans la liste des tâches\n");
	return listeT;
}
	for(int i=index-1;i<listeT->sizeT-1;i++){
			strcpy(listeT->arrayTasks[i].chaine,listeT->arrayTasks[i+1].chaine);
	}
		printf("La suppression de la tâche a été effectuée avec succès\n");
listeT->sizeT--; }

void isDone_Task(listeTask* listeT){
	display_Task(listeT);
	int index;
		printf("\n\n\t\t**************************************MARKS SECTION**************************************\n\n");
	printf("\n\nEntrez l'ID de la tâche qui a été terminée (Exemple : pour changer le statut de la première tâche, appuyez sur 1)\n");
	scanf("%d",&index);
	if(index<1 || index>listeT->sizeT){
		printf("Id que vous avez choisi n'est pas correct\n\n");
	}else {
			strcpy(listeT->arrayTasks[index-1].status,"Done");
	}
display_Task(listeT);
}
void filter_Task(listeTask* listeT) {
    char choix;
    char dateIndiceJ[20];
    char dateIndiceI[20];

    do {
        printf("Click sur 'P' pour trier selon la priorite ou Click sur 'D' pour trier selon la date d'echeance\n");
        scanf(" %c", &choix);

        if (choix == 'P' || choix == 'p') {
            for (int i=1; i<listeT->sizeT ; i++) {
                for (int j=0; j<listeT->sizeT-1; j++) {
                    if (listeT->arrayTasks[j].priority > listeT->arrayTasks[j+1].priority) {
                        Task temp = listeT->arrayTasks[j];
                        listeT->arrayTasks[j] = listeT->arrayTasks[j+1];
                        listeT->arrayTasks[j+1] = temp;
                    }
                }
            }
        } else if (choix == 'D' || choix == 'd') {

            for (int i=0; i<listeT->sizeT; i++) {
				sprintf(dateIndiceI, "%04d/%02d/%02d", listeT->arrayTasks[i].annee, listeT->arrayTasks[i].mois, listeT->arrayTasks[i].jour);
                for (int j=i+1; j<listeT->sizeT; j++) {
                    sprintf(dateIndiceJ, "%04d/%02d/%02d", listeT->arrayTasks[j].annee, listeT->arrayTasks[j].mois, listeT->arrayTasks[j].jour);
                    if (strcmp(dateIndiceJ, dateIndiceI) < 0) {
                        Task tempTask = listeT->arrayTasks[i];
                        listeT->arrayTasks[i] = listeT->arrayTasks[j];
                        listeT->arrayTasks[j] = tempTask;
                    }
                }
            }
        }
    } while (choix != 'D' && choix != 'd' && choix != 'P' && choix != 'p');
    display_Task(listeT);
}
