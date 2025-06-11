#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
#else
void setColor(int color) {
    printf("\033[1;%dm", color);
}
#endif

#define MAX_NAME 50
#define NUM_CARTAS 32

typedef struct {
    char nome[MAX_NAME];
    int forca;
    int velocidade;
    int inteligencia;
} Carta;

void exibirCarta(Carta c) {
    printf("--------------------------\n");
    printf("Carta: %s\n", c.nome);
    printf("1. Força: %d\n", c.forca);
    printf("2. Velocidade: %d\n", c.velocidade);
    printf("3. Inteligência: %d\n", c.inteligencia);
    printf("--------------------------\n");
}

int compararAtributo(Carta a, Carta b, int escolha) {
    switch (escolha) {
        case 1: return a.forca - b.forca;
        case 2: return a.velocidade - b.velocidade;
        case 3: return a.inteligencia - b.inteligencia;
        default: return 0;
    }
}

int main() {
    srand(time(NULL));

    Carta cartas[NUM_CARTAS] = {
        {"Curupira", 8, 9, 7}, {"Caipora", 7, 9, 8}, {"Boitatá", 9, 6, 7},
        {"Iara", 6, 7, 9}, {"Boto-cor-de-rosa", 7, 6, 8}, {"Saci-Pererê", 5, 10, 9},
        {"Cuca", 8, 6, 10}, {"Mula-sem-cabeça", 9, 7, 6}, {"Lobisomem", 9, 8, 5},
        {"Cabra-Cabriola", 8, 6, 6}, {"Negrinho do Pastoreio", 4, 5, 9},
        {"Corpo-Seco", 7, 3, 6}, {"Mapinguari", 10, 4, 5}, {"Uirapuru", 2, 9, 10},
        {"Jaci", 8, 7, 10}, {"Anhangá", 7, 7, 9}, {"Tupã", 10, 8, 10},
        {"Jurupari", 9, 7, 10}, {"Aramê", 6, 6, 9}, {"Porangaba", 7, 6, 10},
        {"Matinta Pereira", 6, 5, 9}, {"Maria Caninana", 8, 6, 8},
        {"Jurema", 7, 6, 8}, {"Papa-Figo", 5, 6, 7}, {"Pisadeira", 6, 5, 8},
        {"Comadre Fulozinha", 6, 7, 9}, {"Homem do Saco", 7, 5, 6},
        {"Velho do Rio", 6, 5, 10}, {"Cabocla Jupira", 7, 6, 9},
        {"Noiva da Lagoa", 6, 6, 8}, {"Mãe d'Água", 8, 6, 10}, {"Zarabatana", 7, 8, 8}
    };

    int opcao;
    while (1) {
        setColor(36);
        printf("\n===== SUPER TRUNFO BRAZUCA =====\n");
        setColor(0);
        printf("1. Jogar\n");
        printf("2. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 2) break;

        if (opcao == 1) {
            int idxJogador = rand() % NUM_CARTAS;
            int idxOponente = rand() % NUM_CARTAS;
            while (idxOponente == idxJogador)
                idxOponente = rand() % NUM_CARTAS;

            Carta jogador = cartas[idxJogador];
            Carta oponente = cartas[idxOponente];

            printf("\nSua carta:\n");
            exibirCarta(jogador);

            int escolha;
            printf("Escolha o atributo pra competir (1-Força, 2-Velocidade, 3-Inteligência): ");
            scanf("%d", &escolha);

            printf("\nCarta do oponente:\n");
            exibirCarta(oponente);

            int resultado = compararAtributo(jogador, oponente, escolha);

            if (resultado > 0) {
                setColor(32); printf("\nVocê venceu!\n");
            } else if (resultado < 0) {
                setColor(31); printf("\nVocê perdeu!\n");
            } else {
                setColor(33); printf("\nEmpate!\n");
            }
            setColor(0);
        }
    }

    printf("\nObrigada por jogar!\n");
    return 0;
}
