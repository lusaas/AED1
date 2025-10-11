//maior endereço de memoria entre dois inteiros

#include <stdio.h>

int main () {
    int i = 0, j = 1;
    int *i1, *j1;
    int *maior;

    i1 = &i;
    j1 = &j;

    if (j1 > i1) {
        maior = j1;
    } else {
        maior = i1;
    }

    printf ("%d", maior);
}