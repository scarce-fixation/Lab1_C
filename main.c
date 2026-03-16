#include<stdio.h>
#include<string.h>
#define max_len 1000
#define max_words 100
int my_strcmp(char* a, char* b) {
        while (*a && *b && *a == *b) {
                a++;
                b++;
        }
        return *b - *a;
}
void str_sort_n_print(char* str) {
        char* words[max_words];

        int word_count = 0;
        int len = strlen(str);

        if (len == 0) {
                printf("Error: Parameter is empty\n");
                return;
        }
        char* p = str;

        //skip leading spaces
        while (*p == ' ' || *p == '\t' || *p == '\n') p++;
        if (*p == '\0') {
                printf("Error: Parameter is empty or only whitespace\n");
                return;
        }

        words[0] = p;
        word_count = 1;

        while (*p) {
                if (*p == ',' || *p == '.') {
                        *p = '\0';
                        if (*(p + 1) == ' ' || *(p + 1) == '\t' || *(p + 1) == '\n') {
                                while (*p && !(*(p + 1) >= 'a' && *(p + 1) <= 'z')) p++;

                                if (!*p) break;
                        }
                        if (*(p + 1) >= 'a' && *(p + 1) <= 'z') {
                                words[word_count++] = p + 1;
                        }
                }
                p++;
        }

        for (int i = 0; i < word_count - 1; i++) {
                for (int j = i + 1; j < word_count; j++) {
                        if (my_strcmp(words[i], words[j]) > 0) {
                                char* temp = words[i];
                                words[i] = words[j];
                                words[j] = temp;
                        }
                }
        }

        for (int i = 0; i < word_count; i++) {
                printf("%s\n", words[i]);
        }
}
int main() {
        char str[] = "a,          c,		b, \nabbc,abc.";

        /*char str[] = "c,a,b.";

        char str[] = "		a,          c,		b, \nabbc,abc.";

        char str[] = "a,          c,		b, \nabbc,abc.";

        char str[] = "12344, 123, 123.";

        char str[] = " ";

        char str[] = "sdf";

        char str[] = "sdf,a";*/

        str_sort_n_print(str);


        return 0;
}