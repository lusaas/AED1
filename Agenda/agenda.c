#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void insertPerson();
void removePerson();
void searchPerson();
void printAll();


void **pBuffer;


int main () {
    pBuffer = (void **)malloc(sizeof(void *) * 36);

    pBuffer[0] = (void*)(int *)0; // menu
    pBuffer[1] = (void*)(int *)0;  // contador
    pBuffer[2] = (void*)(int *)36; // espaco alocado atual
    pBuffer[3] = (void*)(int *)6; // indice proximo disponivel
    pBuffer[4] = (void*)(int *)0; // indice auxiliar do for
    pBuffer[5] = NULL; // temporario

    do {
        menu();
        switch ((int) pBuffer[0]) {
            case 1:
                insertPerson();
                break;
            case 2:
                removePerson();
                break;
            case 3:
                searchPerson();
                break;
            case 4:
                printAll();
                break;
            case 5:
                free(pBuffer);
                exit(0);
                break;
        } 
    } while (1);
}

void menu () {
    printf ("1 - Adicionar Pessoa\n");
    printf ("2 - Remover pessoa\n");
    printf ("3 - Buscar Pessoa\n");
    printf ("4 - Listar todos\n");
    printf ("5 - Sair\n");
    printf ("Digite a opcao: ");
    scanf("%d", &pBuffer[0]);
}


void insertPerson () {
    if (pBuffer[3] > pBuffer[2]) {
        realocar ();
    }

    printf("Nome: ");
    pBuffer[5] = malloc(sizeof(char*) * 1023);
    scanf(" %[^\n]", pBuffer[5]);

    pBuffer[(int)pBuffer[3]] = malloc(sizeof(char) * (1 + strlen(pBuffer[5])));
    memcpy (pBuffer[(int)pBuffer[3]], pBuffer[5], (1 + (strlen(pBuffer[5]))));
    
    printf("Idade: ");
    scanf("%d", (int *)&pBuffer[(int)pBuffer[3]+1]);

    printf("E-mail: ");
    scanf(" %[^\n]", pBuffer[5]);
    pBuffer[(int)pBuffer[3] + 2] = malloc(sizeof(char) * (1 + strlen(pBuffer[5])));
    memcpy (pBuffer[(int)pBuffer[3] + 2], pBuffer[5], (1 + (strlen(pBuffer[5]))));

    pBuffer[2] += 3;
    pBuffer[3] += 3;

    printf ("contato adicionado!\n");
    pBuffer[1]++;

    free(pBuffer[5]);

}

void removePerson () {
    if (pBuffer[1] == 0) {
        printf("a lista esta vazia\n");
        return 0;
    }

    printf ("digite o nome do contato a ser apagado: ");
    scanf (" %[^\n]", pBuffer[5]);

    for (pBuffer[4] = 0; (int)pBuffer[4] < (int)pBuffer[1]; pBuffer[4]++) {
        if (strcmp(pBuffer[5], pBuffer[6 + (int)pBuffer[4] * 3]) == 0) {
            printf ("contato encontrado!\n");
            getchar();

            /*free(pBuffer[6 + (int)pBuffer[4] * 3]);
            free(pBuffer[6 + (int)pBuffer[4] * 3 + 1]);
            free(pBuffer[6 + (int)pBuffer[4] * 3 + 2]); */
            
            for (pBuffer[4]; (int)pBuffer[4] < (int)pBuffer[1]; pBuffer[4]+=3) {
                pBuffer[(int)pBuffer[6 + (int)pBuffer[4] * 3]] = pBuffer[(int)pBuffer[4]+3];
                pBuffer[(int)pBuffer[6 + (int)pBuffer[4] * 3 + 1]] = pBuffer[(int)pBuffer[4]+4];
                pBuffer[(int)pBuffer[6 + (int)pBuffer[4] * 3 + 2]] = pBuffer[(int)pBuffer[4]+5];
            }
            realocarMenos();
        }
    }
    pBuffer[1]--;
    return;
}

void searchPerson () {
    if (pBuffer[1] == 0) {
        printf ("lista vazia\n");
        return 0;
    }

    printf ("Quem deseja buscar: ");
    getchar();
    scanf (" %[^\n]", pBuffer[5]);

    for (pBuffer[4]; (int) pBuffer[4] < (int) pBuffer[1]; pBuffer[4] + 3) {
        if (strcmp(pBuffer[5], pBuffer[6 + (int)pBuffer[4] * 3]) == 0) {
            printf ("Nome encontrado\n");
            printf ("%s\n%d\n%s", pBuffer[6 + (int)pBuffer[4] * 3], pBuffer[6 + (int)pBuffer[4] * 3 + 1], pBuffer[6 + (int)pBuffer[4] * 3] + 2);
            return;
        }
        else {
            printf ("Nome nao encontrado\n");
            return;
        }
    }
}
void printAll () {
    printf("Total de contatos: %d\n", (int)pBuffer[1]);

    for (pBuffer[4] = 0; (int)pBuffer[4] < (int)pBuffer[1]; pBuffer[4]++) {
        printf ("Nome: %s\n", pBuffer[6 + (int)pBuffer[4] * 3]);
        printf ("Idade: %d\n", pBuffer[6 + (int)pBuffer[4] * 3 + 1]);
        printf ("E-mail: %s\n", pBuffer[6 + (int)pBuffer[4] * 3 + 2]);
    }
}

void realocar () {
    pBuffer = realloc(pBuffer, (int)pBuffer[2] + 30 * sizeof(void*));
    pBuffer[2] = (int)pBuffer[2] + 30; 
}

void realocarMenos () {
    pBuffer = realloc(pBuffer, (int)pBuffer[2] - 3 * sizeof(void*));
    pBuffer[2] = (int)pBuffer[2] - 3;
}