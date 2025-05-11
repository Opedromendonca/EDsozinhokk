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
    float g1, g2, media;
} Aluno;

typedef struct {
    Aluno *aluno;
    int top, cap;
} Stack;

int empty(Stack *stack)
{
    return stack->top == -1;
}

int malloqueiro(Stack *stack, int cap)
{

    stack->aluno = (Aluno *) malloc(cap * sizeof(Aluno));

    if (stack->aluno == NULL) {
	return 1;
    }

    stack->top = -1;
    stack->cap = cap;

    return 0;
}

void push(Stack *stack, Aluno aluno)
{
    if (stack->top + 1 >= stack->cap) {
	printf("pilha cheia\n");
	return;
    } else {
	stack->aluno[++stack->top] = aluno;
    }
}

Aluno pop(Stack *stack)
{
    if (empty(stack)) {
	Aluno vazio = { -1, 0, 0, 0 };
	return vazio;
    }

    return stack->aluno[stack->top--];
}

Aluno find(Stack *stack, int id)
{
    if (empty(stack)) {
	Aluno vazio = { -1, 0, 0, 0 };
	return vazio;
    }

    Aluno aux = pop(stack);

    if (id == aux.id) {
	push(stack, aux);
	return aux;
    }

    Aluno re = find(stack, id);
    push(stack, aux);

    return re;
}

void show(Aluno aluno)
{
    if (aluno.id == -1) {
	printf("não encontrado\n");
    } else {
	printf("ID: %d | G1: %.2f | G2: %.2f | Média: %.2f\n",
	       aluno.id, aluno.g1, aluno.g2, aluno.media);
    }
}

int main()
{
    Stack stack;
    int cap;

    printf("capacidade: ");
    scanf("%d", &cap);

    if (malloqueiro(&stack, cap)) {
	printf("ERRO no malloc\n");
	return 1;
    }

    int opt;
    do {
	printf("\n1 - push \n2 - pop \n3 - find \n0 - exit \n");
	printf("Escolha uma opção: ");
	scanf("%d", &opt);

	switch (opt) {
	case 1:{
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
	    }
	case 2:{
		Aluno rm = pop(&stack);
		printf("removido: ");
		show(rm);
		break;
	    }
	case 3:{
		int id;
		printf("qual id? ");
		scanf("%d", &id);
		Aluno achado = find(&stack, id);
		show(achado);
		break;
	    }
	}

    } while (opt != 0);

    free(stack.aluno);
    return 0;
}

// MOD-001 - FIM - Pedro
