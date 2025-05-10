/*
 * File: Ex21.c
 * Author: 202311336,pedro mendonca,pedro.202311336@unilasalle.edu.br'	
 * Created on: 2025-05-10
 */
 
// MOD-001 - INI - Pedro
#include <stdio.h>
#include <stdlib.h>

typedef struct {
int ID;
float g1,g2,media;
} Aluno;

typedef struct {
Aluno *aluno;
int top;
} Stack;


int main() {
    Stack stack;
    int cap;
    
    printf("capacidade: ");
    scanf("%d", &cap);
	
	stack.aluno = (Aluno *)malloc(cap * sizeof(Aluno));
	stack.top = -1;
	
	int opt;
	do {
		
		printf("1 - push \n2 - pop \n3 - find \n0 - exit ");
		scanf("\n qual?%d", &opt);
		
		switch (opt) {
			
			case 1:
			
			
			//push();
			case 2:
			//pop();
			case 3:
			int id;
			printf("qual id? ");
			scanf("%d", &id);
			//find();
			
		}
		
		
	} while(opt !=0);
	
	return 0;
}
// MOD-001 - FIM - Pedro
