/*
 * Busca em Profundidade
 * Data: 21/09/2019
 * Autor: Emanuel Souza  (https://github.com/EmanuelOSSouza) 
 * Autor: Iarley Moraes  (https://github.com/Rytokirin21)
 * Matéria: Inteligência Artifcial
 * Busca em Profundidade com retrocesso (recursivo)
 * Descrição: Dado um labirinto (com posições de entrada e saída), ache o 
 * melhor caminho utilizando a busca em profundidade (DFS - Depth-first search),
 * seguindo a ordem de prioridade: norte, leste, oeste, sul. Para tanto não é
 * possivel utilizar as diagonais.
 * Obs: A pilha será utilizada somente para dizer qual é o melhor caminho.
 * Foi utilizao a técnica POP e PUSH da pilha para armazenar ou remover os caminhos.
 * Toda busca é feita em recursividade para otimização do código, reduzindo
 * o custo da complexidade para O(bm) com m sendo o nível.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int custoTotal = 0;
int custoParcial = 0;

char labirinto[10][10]={
  '1','1','1','1','1','1','1','1','1','1',
  '1','0','0','0','1','0','0','0','0','1',
  '1','1','1','0','1','1','0','1','1','1',
  '1','0','0','0','0','0','0','0','0','1',
  '1','1','1','0','1','1','0','0','0','1',
  '1','0','1','0','0','1','0','1','0','1',
  '1','0','1','0','0','1','0','1','0','1',
  '1','0','1','0','1','1','0','1','0','1',
  '1','0','0','0','0','0','0','1','0','1',
  '1','1','1','1','1','1','1','1','1','1',
};
//**Pilha**

typedef struct {
	int linha, coluna;
} REGISTRO;

typedef struct aux {
	REGISTRO registro;
	struct aux *proximo;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
	PONT topo;
} PILHA;

//PUSH 
int inserirElementoPilha(PILHA* p, REGISTRO registro) {
	PONT novo = (PONT) malloc(sizeof(ELEMENTO));
	novo->registro = registro;
	novo->proximo = p->topo;
	p->topo = novo;
	return 1;
} /* inserirElemPILHA */

void inicializarPilha(PILHA* p) {
	p->topo = NULL;
}

//POP
int excluirElementoPilha(PILHA* p){
  if ( p->topo == NULL) return 0;
  PONT apagar = p->topo;
  p->topo = p->topo->proximo;
  free(apagar);
  return 1;
} /* excluirElemPILHA */

//*************************************
//Mostrar caminho percorrido
int verTabuleiro(){
    int i,j;
    printf("\nColunas: \t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\n\n");
    printf("\n");
    for(i=0;i<=9;i++){
        printf("Linha %d:",i);
        for(j=0;j<=9;j++){
                printf("\t%c",labirinto[i][j]);
            }
        printf("\n\n");
    }
}
// Define a posição inicial e final do labirinto
int definirPosicoes(PILHA *p){
	int x,y,n,m;
	REGISTRO registro;
    printf("Digite Linha Start: ");
    scanf("%d",&x);
    printf("Digite Coluna Start: ");
    scanf("%d",&y);
    printf("\nDigite Linha Goal: ");
    scanf("%d",&n);
    printf("Digite Coluna Goal: ");
    scanf("%d",&m);

    if(labirinto[x][y]=='1' || x>9 || y>9 || labirinto[n][m]=='1' || n>9 || m>9 ){
        printf("\nJogada invalida");
        return 0;
    }else if (x==n && y==m){
        printf("\nA origem e destino sao iguais, custo = 0.");
        return 0;
	}else{
        labirinto[x][y]='S';
        labirinto[n][m]='G';
        registro.linha = x;
        registro.coluna = y;
        inserirElementoPilha(p, registro);
        custoTotal++;
		custoParcial++;
	}
}

int buscaEmProfundidade(PILHA *p){
    int x, y; //Linha e Coluna
	REGISTRO registro;
    PONT endereco = p->topo;
    x = endereco->registro.linha;
    y = endereco->registro.coluna;
    printf("\nLinha: %d - Coluna: %d", x,y);
    if(labirinto[x][y]=='G'){
        printf("\nParabens!!\n");
        return 0;
    }
	else{
		// Norte (cima)
        if(labirinto[x-1][y]=='0' || labirinto[x-1][y]=='G'){
            printf("\nNorte");
            registro.linha = x-1;
            registro.coluna = y;
            if(inserirElementoPilha(p, registro)){
            	printf("\nElemento inserido na pilha com sucesso, Ao Norte!");
    			if(labirinto[x-1][y]=='G') return 0;
				labirinto[x-1][y]='#';
			}
			custoTotal++;
			custoParcial++;
			return 1;

        }
        else{
        	// Leste (direita)
			if(labirinto[x][y+1]=='0' || labirinto[x][y+1]=='G'){
	        	printf("\nLeste");
            	registro.linha = x;
                registro.coluna = y+1;
                if(inserirElementoPilha(p, registro)){
            		printf("\nElemento inserido na pilha com sucesso, Ao Leste!");
    				if(labirinto[x][y+1]=='G') return 0;
					labirinto[x][y+1]='#';
				}
				custoTotal++;
				custoParcial++;
				return 1;
	        }
        	else{
        		//Oeste (Esquerda)
				if(labirinto[x][y-1]=='0' || labirinto[x][y-1]=='G'){
		            printf("\nOeste");
	            	registro.linha = x;
                	registro.coluna = y-1;
	                if(inserirElementoPilha(p, registro)){
            			printf("\nElemento inserido na pilha com sucesso, Ao Oeste!");
    					if(labirinto[x][y-1]=='G') return 0;
						labirinto[x][y-1]='#';
					}
					custoParcial++;
					custoTotal++;
					return 1;
	        	}
        		else{
        			//Sul (baixo)
					if(labirinto[x+1][y]=='0' || labirinto[x+1][y]=='G') {
	           			printf("\nSul");
					    registro.linha = x+1;
	                	registro.coluna = y;
		                if(inserirElementoPilha(p, registro)){
            				printf("\nElemento inserido na pilha com sucesso, Ao Sul!");
            				if(labirinto[x+1][y]=='G') return 0;
    						labirinto[x+1][y]='#';
						}
						custoTotal++;
						custoParcial++;
						return 1;
        			}
        			else{
        				//remover a elemento da pilha, caso nao seja possivel continuar
        				if(excluirElementoPilha(p)){
        					printf("\nElemento removido\n");
        					if(labirinto[x][y]=='G') return 0;
        					if(labirinto[x][y]=='S'){
                                    system("cls");
                                    printf("Nao foi possivel chegar ao fim, labirinto fechado!!");
        					}
        					labirinto[x][y]='*';
        				}
						custoParcial--;
						return 1;
					}
        		}
			}
		}
    }
}
//Exibir melhor caminho
void exibirPilha(PILHA* p) {
    PONT end = p->topo;
    printf("Pilha: \n ");
    while (end != NULL) {
    	printf("\n[");
        printf("%d, ", end->registro.linha);
        printf("%d", end->registro.coluna);
        printf("]\t");
        end = end->proximo;
        Sleep(1000);
    }
    printf("\n");
}

int main(){
	//setlocale(LC_ALL, "Portuguese");
    int x = 1;
    PILHA p;
    system("mode 100,80");
    inicializarPilha(&p);
    verTabuleiro();
    if(definirPosicoes(&p) == 0) exit(0);
    verTabuleiro();
    while(x){
        x = buscaEmProfundidade(&p);
        verTabuleiro();
        getchar();
        system("cls");
    }
    exibirPilha(&p);
    printf("Custo total: %d", custoTotal);
	printf("\nCusto do caminho: %d", custoParcial);
	system("pause");
	return 0;
}
