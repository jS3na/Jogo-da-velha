#include <stdio.h>
#include <stdbool.h> 

bool vitverif(char jog[3][3]){
    
    for (int i = 0; i < 3; i++) {
        if (jog[i][0] == jog[i][1] && jog[i][1] == jog[i][2] && jog[i][0] != '_')
            return true;
    }

    for (int j = 0; j < 3; j++) {
        if (jog[0][j] == jog[1][j] && jog[1][j] == jog[2][j] && jog[0][j] != '_')
            return true;
    }

    if ((jog[0][0] == jog[1][1] && jog[1][1] == jog[2][2] && jog[0][0] != '_') ||
        (jog[0][2] == jog[1][1] && jog[1][1] == jog[2][0] && jog[0][2] != '_'))
        return true;

    return false;
}

int main(void) {
  
    bool verif = true;
    int opcol, oplin, count = 0;
    char lin[3] = {'1', '2', '3'};
    char jog[3][3] = {
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}
    };

    printf("  1 2 3\n1 _|_|_\n2 _|_|_\n3 _|_|_\n");

    while (1) {
        while (verif) {
            printf("\nJogador 1 (X), escolha, respectivamente, a coluna e a linha: ");
            scanf("%d", &opcol);
            scanf("%d", &oplin);

            if (opcol < 1 || opcol > 3 || oplin < 1 || oplin > 3) {
                printf("\nOpção inválida! Jogue novamente!\n");
                continue;
            }

            if (jog[oplin - 1][opcol - 1] == 'X' || jog[oplin - 1][opcol - 1] == 'O') 
                printf("\nLocal ocupado! Jogue novamente!\n");
              
            else {
                jog[oplin - 1][opcol - 1] = 'X';
                count += 1;
                verif = false;
            }
        }

        printf("  1 2 3\n1 %c|%c|%c\n2 %c|%c|%c\n3 %c|%c|%c\n",
            jog[0][0], jog[0][1], jog[0][2],
            jog[1][0], jog[1][1], jog[1][2],
            jog[2][0], jog[2][1], jog[2][2]);

        if (vitverif(jog)) {
            printf("\nJogador 1 (X) venceu!\n");
            break;
        }
         else if(count == 9){
            printf("\nO jogo deu empate/velha!!");
            break;
        }

        verif = true;

        while (verif) {
            printf("\nJogador 2 (O), escolha, respectivamente, a coluna e a linha: ");
            scanf("%d", &opcol);
            scanf("%d", &oplin);

            if (opcol < 1 || opcol > 3 || oplin < 1 || oplin > 3) {
                printf("\nOpção inválida! Jogue novamente!\n");
                continue;
            }

            if (jog[oplin - 1][opcol - 1] == 'X' || jog[oplin - 1][opcol - 1] == 'O') 
                printf("\nLocal ocupado! Jogue novamente!\n");
              
            else {
                jog[oplin - 1][opcol - 1] = 'O';
                count += 1;
                verif = false;
              
            }
          
        }

        printf("  1 2 3\n1 %c|%c|%c\n2 %c|%c|%c\n3 %c|%c|%c\n",
            jog[0][0], jog[0][1], jog[0][2],
            jog[1][0], jog[1][1], jog[1][2],
            jog[2][0], jog[2][1], jog[2][2]);
      
        if (vitverif(jog)) {
            printf("\nJogador 2 (O) venceu!\n");
            break;
        }
        else if(count == 9){
            printf("\nO jogo deu empate/velha!!");
            break;
        }

      verif = true;
      
    }

    return 0;
}