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
int isDelimiter(char c) {
        char delimiter[] = " \t\n!?.,\"\':;(){}[]-";
        int len = strlen(delimiter);

        for (int i = 0; i < len; i++) {
                if (delimiter[i] == c) return 1;
        }
        return 0;
}

void str_sort_n_print(char* str) {
        char* words[max_words];

        int word_count = 0;
        int len = strlen(str);
        //check if parameter is empty
        if (len == 0) {
                printf("Error: Parameter is empty\n");
                return;
        }
        char* p = str;
        char c = *p;

        //skip leading delimiters
        while (isDelimiter(*p)) p++;
        if (*p == '\0') {
                printf("Error: Parameter is empty or only whitespace\n");
                return;
        }

        words[0] = p;
        word_count = 1;

        //set pointers at the beginning  of the words
        while (*p) {
                c = *p;
                if (*p == '.') {
                        *p = '\0';
                        break;
                }
                if (isDelimiter(*p)) {
                        *p = '\0';
                        if (isDelimiter(*(p + 1))) {
                                while (isDelimiter(*(p + 1))) {
                                        p++;
                                        c = *p;
                                }
                        }

                        if (!isDelimiter(*(p + 1))) {
                                words[word_count++] = p + 1;
                        }
                }
                p++;
        }

        //sort words
        for (int i = 0; i < word_count; i++) {
                for (int j = 0; j < word_count; j++) {
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
        //char str[] = "a,          c,		b, \nabbc,abc.";

        //char str[] = "c,a,b.";

        //char str[] = "		a,          c,		b, \nabbc,abc.";

        //char str[] = "a,          c,		b, \nabbc,abc.";

        //char str[] = "12344, 123. 123.";

        //char str[] = " ";

        //char str[] = "sdf";

        char str[] = "sdf,a";

        str_sort_n_print(str);


        return 0;
}