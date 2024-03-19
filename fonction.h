#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

typedef struct{
	char priority;
	char status[10];
	int jour,mois,annee;
char chaine[100];
}Task;
typedef struct{
int sizeT;
Task arrayTasks[100];
}listeTask;

void menu();
void create_Task(Task *t);
void add_Task(listeTask* listeT,Task *task);
void modify_Task(listeTask* listeT);
void delete_Task(listeTask* listeT);
void filter_Task(listeTask* listeT);
void display_Task(listeTask* listeT);
void isDone_Task(listeTask* listeT);


#endif // FONCTION_H_INCLUDED
