#include <stdio.h>

int my_strcmp(char* a, char* b) {
        while (*a && *b && *a == *b) {
                a++;
                b++;
        }
        return (char)a - (char)b;
}
int main()
{

    return 0;
}

