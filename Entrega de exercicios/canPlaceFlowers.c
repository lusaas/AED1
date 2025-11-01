#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canPlaceFlowers (int *flowerbed, int flowerbedSize, int n);

int main () {
    int flowerbed[5] = {1, 0, 1, 0, 1};
    int flowerbedSize = 5;
    int n = 1;

    bool result = canPlaceFlowers (flowerbed, flowerbedSize, n);

    if (result == false) {
        printf ("false");
    } else {
        printf ("true");
    }
}

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int i;
    int num = n;

    for (i = 0; i < flowerbedSize && num > 0; i++) {
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbedSize - 1 || flowerbed[i+1] == 0)) {
            flowerbed[i] = 1;
            num--;
        }
    }
    if (num <= 0) {
        return true;
    } else {
        return false;
    }
}
