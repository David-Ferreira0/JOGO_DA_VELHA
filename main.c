#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void iniciar(char tab[3][3]) {
    char inicio[3][3] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'},
    };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tab[i][j] = inicio[i][j];
        }
    }
}

void mostrarTab(char tab[3][3]) {
    printf("%c |  %c  |  %c\n", tab[0][0], tab[0][1], tab[0][2]);
    printf("----------------\n");
    printf("%c |  %c  |  %c\n", tab[1][0], tab[1][1], tab[1][2]);
    printf("----------------\n");
    printf("%c |  %c  |  %c\n", tab[2][0], tab[2][1], tab[2][2]);
}

int menu() {
    int escolha;
    printf("_#________________________\n");
    printf("_______JOGO DA VELHA___\n");
    printf("________________________\n");
    printf("______MENU DE OPCOES_____\n");
    printf("1 - INICIAR JOGO\n");
    printf("0 - SAIR\n");
    scanf("%d", &escolha);
    
    while (escolha != 1 && escolha != 0) {
        printf("OPCAO INVALIDA, DIGITE NOVAMENTE:");
        scanf("%d", &escolha);
    }
    return escolha;
}

char verificar_vencedor(char tab[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2]) {
            return tab[i][0];
        }
        if (tab[0][i] == tab[1][i] && tab[1][i] == tab[2][i]) {
            return tab[0][i];
        }
    }
    if (tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2]) {
        return tab[0][0];
    }
    if (tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0]) {
        return tab[0][2];
    }
    return 0;  // Nenhum vencedor
}

void jogar_partida(char tab[3][3]) {
    int lin, col, posicao, cont;
    for (cont = 0; cont < 9; cont++) {
        system("cls");
        mostrarTab(tab);
        
        char marcador = (cont % 2 == 0) ? 'x' : 'o';
        
        printf("Jogador '%c', escolha uma posicao livre [1-9]:", marcador);
        scanf("%d", &posicao);
        
        switch (posicao) {
            case 1: lin = 0; col = 0; break;
            case 2: lin = 0; col = 1; break;
            case 3: lin = 0; col = 2; break;
            case 4: lin = 1; col = 0; break;
            case 5: lin = 1; col = 1; break;
            case 6: lin = 1; col = 2; break;
            case 7: lin = 2; col = 0; break;
            case 8: lin = 2; col = 1; break;
            case 9: lin = 2; col = 2; break;
            default: printf("Posicao invalida!"); cont--; continue;
        }
        
        if (tab[lin][col] == 'x' || tab[lin][col] == 'o') {
            printf("Posicao ja ocupada! Tente novamente.\n");
            cont--;
            system("pause");
            continue;
        }
        tab[lin][col] = marcador;
        
        char vencedor_atual = verificar_vencedor(tab);
        
        if (vencedor_atual) {
            system("cls");
            printf("\nJogador '%c' venceu!\n", vencedor_atual);
            mostrarTab(tab);
            break;
        }
        else if (cont == 8) {
            system("cls");
            printf("Empate!\n");
            mostrarTab(tab);
            break;
        }
    }
}

int main() {
    char tabuleiro[3][3];
    
    int opcao = menu();
    if (opcao == 0) {
        printf("FIM DO JOGO");
        return 0;
    }
    iniciar(tabuleiro);
    jogar_partida(tabuleiro);
    printf("FIM DE JOGO");
    return 0;
}