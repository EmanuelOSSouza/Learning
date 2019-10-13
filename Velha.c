/*
 * Jogo da velha
 * Data: 27/02/2018
 * Autor: Emanuel Souza (https://github.com/EmanuelOSSouza/Learning)
 * Matéria: Linguagem de programação (C)
 * Descrição: Fazer o jogo da velha em linguagem C, para 2 players.
 * OBS: O objetivo desta atividade é a utilização de matrizes e vetores, 
 * portanto não foi utilizado ponteiros, o que poderia otimizar este código.
*/

#include <stdio.h>
char posicao[4][4];
int count=0;
char player1[20];
char player2[20];

//exibição da interface no inicio do jogo
int interface(void){
system("color 17");
printf("\n\t  #   #   \n");
printf("\t######### \n ");
printf("\t  #   #    \n");
printf("\t######### \n");
printf("\t  #   #   \n\n");
}

//Pegar as posições no tabuleiro do player 1
int ask1 (void){
int x, y, z;
system("color 07");
printf("\n%s, Digite a linha: ",player1);
scanf("%d", &x);
printf("\n%s, Digite a coluna: ",player1);
scanf("%d", &y);
z=1;
check(x,y,z);
}

//Pegar as posições no tabuleiro do player 2
int ask2 (void){
int a,b,c;
system("color 07");
printf("\n%s, Digite a linha: ", player2);
scanf("%d", &a);
printf("\n%s, Digite a coluna: ", player2);
scanf("%d", &b);
c=0;
check(a,b,c);
}

//Verificar se a posicão é válida
void check (int x, int y, int z, int ini){
//count++;
if(posicao[x][y]=='x' || posicao[x][y]=='o'){
      if(z==1){
            system("color 04");
            printf("\nPosicao ja ocupada, Tente novamente\n");
            system("pause");
            return ask1();
        }
        else
            {
            system("color 04");
            printf("\nPosicao ja ocupada, Tente novamente\n");
            system("pause");
            return ask2();
            }
        }
    else
    {
        game(x,y,z,ini);
    }
}
//Após a verificação, inserir no tabuleiro
int game (int x, int y,int z, int ini){
int i, t;
if((x>0) && (x<=3)){
    if((y>0) && (y<=3)){
            if (z==1){
                posicao[x][y]='x';
                system("cls");
                printf("\n\t_%c_|_%c_|_%c_\n",posicao[1][1],posicao[1][2],posicao[1][3]);
                printf("\t_%c_|_%c_|_%c_\n",posicao[2][1],posicao[2][2],posicao[2][3]);
                printf("\t_%c_|_%c_|_%c_\n",posicao[3][1],posicao[3][2],posicao[3][3]);
                system("color 07");
                win(z);
                return 1;
            }
            else
            {
                posicao[x][y]='o';
                system("cls");
                printf("\n\t_%c_|_%c_|_%c_\n",posicao[1][1],posicao[1][2],posicao[1][3]);
                printf("\t_%c_|_%c_|_%c_\n",posicao[2][1],posicao[2][2],posicao[2][3]);
                printf("\t_%c_|_%c_|_%c_\n",posicao[3][1],posicao[3][2],posicao[3][3]);
                system("color 07");
                win(z);
                return 1;
            }
}
    else
    {
        if(z==1){
            system("color 04");
            printf("\nJogada errada Y!\n");
            system("pause");
            return ask1();
        }
        else
        {
            system("color 04");
            printf("\nJogada errada Y!\n");
            system("pause");
            return ask2();
        }
    }
}
else
{
    if (z==1){
        system("color 04");
        printf("\nJogada errada X!\n");
        system("pause");
        return ask1();
    }
    else
    {
            system("color 04");
            printf("\nJogada errada X!\n");
            system("pause");
            return ask2();
    }
}
}

//Verifica qual dos players ganhou o jogo, ou deu velha 
int win(int player){
int i, t, p1_l1=0, p2_l1=0, p1_l2=0, p2_l2=0, p1_l3=0, p2_l3=0, p1_c1=0, p2_c1=0, p1_c2=0, p2_c2=0, p1_c3=0, p2_c3=0, p1_d1=0, p2_d1=0, p1_d2=0, p2_d2=0;
count++;
if (count==9){
    system("cls");
    system("color 06");
    printf("\n\tDeu velha!!\n");
    interface();
    exit(0);
}
for(t=1;t<=3;t++){
    if(posicao[1][t]=='x'){
        p1_l1++;
        }
    if (posicao[1][t]=='o'){
        p2_l1++;
        }
    if(posicao[2][t]=='x'){
        p1_l2++;
        }
    if (posicao[2][t]=='o'){
        p2_l2++;
        }
    if(posicao[3][t]=='x'){
        p1_l3++;
        }
    if (posicao[3][t]=='o'){
        p2_l3++;
        }
}
for(t=1;t<=3;t++){
    if(posicao[t][1]=='x'){
        p1_c1++;
        }
    if (posicao[t][1]=='o'){
        p2_c1++;
        }
    if(posicao[t][2]=='x'){
        p1_c2++;
        }
    if (posicao[t][2]=='o'){
        p2_c2++;
        }
    if(posicao[t][3]=='x'){
        p1_c3++;
        }
    if (posicao[t][3]=='o'){
        p2_c3++;
        }
}
for(i=1;i<=3;i++){
    for(t=1;t<=3;t++){
            if (i=t){
                if(posicao[i][t]=='x'){
                    p1_d1++;
                }
                if(posicao[i][t]=='o'){
                    p2_d1++;
                }
            }
    }
}
if(posicao[1][3]=='x'){
p1_d2++;
}
if(posicao[1][3]=='o'){
p2_d2++;
}
if(posicao[3][1]=='x'){
p1_d2++;
}
if(posicao[3][1]=='o'){
p2_d2++;
}
if(posicao[2][2]=='o'){
p1_d2++;
}
if(posicao[2][2]=='o'){
p2_d2++;
}
if(p1_l1==3 || p1_l2==3 || p1_l3==3 || p1_c1==3 || p1_c2==3 || p1_c3==3 || p1_d2==3 || p1_d1==3){
    system("color 02");
    printf("Parabens %s !! \n", player1);
    interface();
    system("pause");
    exit(0);
}
if(p2_l1==3 || p2_l2==3 || p2_l3==3 || p2_c1==3 || p2_c2==3 || p2_c3==3 || p2_d2==3 || p2_d1==3){
    system("color 02");
    printf("Parabens %s !! \n",player2);
    interface();
    system("pause");
    exit(0);
}

}

//Inicialização do jogo
int main(){
int i,n=100, ini, t;
interface();
printf("\nDigite o seu nome: (Player 1): ");
scanf("%s",&player1);
printf("\nDigite o seu nome: (Player 2): ");
scanf("%s",&player2);
system("cls");
for(ini =0; ini<=7;ini++){
    if(ini==0){
    for(i=1;i<=3;i++){
        for(t=1;t<=3;t++){
                posicao[i][t]='_';
    }
}
}
    ask1();
    ask2();
}
return 0;
}
