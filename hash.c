#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000

typedef struct produto{
	int id;
	int quantidade;
	char nome[50];
	char descricao[50];
	int preco;
}produto;

typedef struct hash{
	produto dado;
	struct hash *prox;
}hash_t;

void create(hash_t *tab[], int n){
	for(int i=0; i<n; i++)
		tab[i]=NULL;
}

int hash(int x){
	return x%MAXN;
}

void insere(produto p, hash_t *tab[MAXN]){
	int h=hash(p.id);
	hash_t *ins = (hash_t *) malloc(sizeof(hash_t));

	ins->dado=p;
	ins->prox=tab[h];
	tab[h]=ins;
}

hash_t *busca(int id, hash_t *tab[MAXN]){
	int h=hash(id%MAXN);
	hash_t *no = tab[h];

	while(no!=NULL){
		if(no->dado.id==id)
			return no;
		no=no->prox;
	}
	return NULL;
}

int main(){
	hash_t *tab[MAXN];
	produto prod;
	hash_t *p;

	create(tab, MAXN);
	printf("id: ");
	while(scanf("%d", &prod.id) && prod.id){
		printf("Nome: ");
		scanf(" %s", prod.nome);
		printf("Descricao: ");
		scanf(" %s", prod.descricao);
		printf("Preco: ");
		scanf("%d", &prod.preco);
		printf("Quantidade: ");
		scanf("%d", &prod.quantidade);

		insere(prod, tab);
		printf("\nid: ");
	}

	while(scanf("%d", &prod.id) && prod.id){
		p=busca(prod.id, tab);
		if(p==NULL)
			printf("Elemento nao encontrado!\n");
		else
			printf("Codigo: %d\nNome: %s\nDescricao: %s\nPreco: %d\nQuantidade: %d\n", 
					p->dado.id, p->dado.nome, p->dado.descricao, p->dado.preco, p->dado.quantidade);
	}
	return 0;
}
