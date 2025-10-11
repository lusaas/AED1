#include <stdio.h>
#include <stdlib.h>

int main () {
    int i = 3, *i2;
    float f = 2.2, *f2;
    char c[3] = "oie", *c2;

    c2 = (char *)malloc(sizeof(char));

    i2 = &i;
    f2 = &f;
    c2 = &c;

    printf ("%d\n%f\n%s\n", i, f, c);

    *i2 = 8;
    *f2 = 4.4;
    *c2 = "oii";

    printf("%d\n%f\n%s", i, f, c);
}