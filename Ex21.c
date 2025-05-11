/*
 * File: Ex21.c
 * Author: 202311336,pedro mendonca,pedro.202311336@unilasalle.edu.br'	
 * Created on: 2025-05-10
 */
 
// MOD-001 - INI - Pedro
#include <stdio.h>
#include <stdlib.h>

typedef struct {
int id;
float g1,g2,media;
} Aluno;

typedef struct {
Aluno *aluno;
int top;
} Stack;

void push( Stack *stack, Aluno aluno ) {
	
	stack->aluno[++stack->top] = aluno;
	
}

int main() {
    Stack stack;
    int cap;
    
    printf("capacidade: ");
    scanf("%d", &cap);
	
	stack.aluno = (Aluno *)malloc(cap * sizeof(Aluno));
	stack.top = -1;
	
	int opt;
	do {
		
		printf("1 - push \n2 - pop \n3 - find \n0 - exit \n");
		scanf("%d", &opt);
		
		switch (opt) {
			
			case 1:
			Aluno aluno;
			
			printf("ID: ");
			scanf("%d", &aluno.id);
			
			printf("G1: ");	
			scanf("%f", &aluno.g1);
			
			printf("G2: ");	
			scanf("%f", &aluno.g2);
		
			aluno.media = (aluno.g1 + aluno.g2) / 2;
		
			push(&stack, aluno);
		
			break;
			
			case 2:
			//pop();
			break;
			case 3:
			int id;
			printf("qual id? ");
			scanf("%d", &id);
			//find();
			break;
			
		}
		
		
	} while(opt !=0);
	
	return 0;
}
// MOD-001 - FIM - Pedro
