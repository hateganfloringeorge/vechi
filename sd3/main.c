/*  HATEGAN Florin George - 311CB */
#include "header.h"



int main(int argc, char *argv[])
{
	void* coada;
	coada = (void*)InitQ(sizeof(TCoada));
	
	TC tree;
	Initializare(&tree);
	
	FILE *f1, *f2;
	f1 = fopen(argv[1] , "r");
	f2 = fopen(argv[3] , "w");
	if (f1 == NULL)
		return -1;
						
	char semn,link; 		// link = linkerul de elemente
	char cod[30],mod[30],aux[30];		
	fscanf(f1,"%s",aux);
	int i = 0,N = atoi(aux);
	for( ; i < N; i++)
		{
		fscanf(f1,"%s",aux);	// citire litera intr-un auxiliar
		semn = aux[0];		// apoi atribuire
		fscanf(f1,"%s",cod);
		add(tree,cod,semn);
		}
		Show(tree,coada,f2);
	fscanf(f1,"%s",aux);
	link = aux[0];
	fscanf(f1,"%s",aux);
	int M = atoi(aux);
	i = 0;
	for( ; i < M; i++)
	{
		fscanf(f1,"%s",mod);
		fscanf(f1,"%s",aux);
		semn = aux[0];
		if ( strcmp("add",mod) == 0) 
		{
			fscanf(f1,"%s",cod);
			if ( Search(tree,cod,semn) == -1){
				Delete(tree->jos,tree,semn);
				add(tree,cod,semn);
				Show(tree,coada,f2);
				}
		} else {
			Delete(tree->jos,tree,semn);
			Show(tree,coada,f2);
		}
	}
	
	
	FILE *f3, *f4;
	f3 = fopen(argv[2] , "r");
	f4 = fopen(argv[4] , "w");
	if (f3 == NULL)
	return -1;
	
	int c;
	i = 0;
	memset(aux,0,30);		//initializare sir de decodificare
	while ((c = fgetc(f3)) != EOF) {
		if ( (char)c == ' ') {
			fprintf(f4," ");	
		} else { 
			if ( (char)c == '\n') {
				fprintf(f4,"\n");
			} else {
			
					if( (char)c == link){
						semn = Decode(tree,aux);
						fprintf(f4,"%c",semn); 
						memset(aux,0,30);
						i = 0;
					} else {
						aux[i++] = (char)c;
					}
					
			}
		}
	}

fclose(f1);
fclose(f2);
fclose(f3);
fclose(f4);
return 0;
}