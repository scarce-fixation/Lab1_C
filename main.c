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
    char delimiter[] = " \t\n!?,\"\':;(){}[]-";
    int len = strlen(delimiter);

    for (int i = 0; i < len; i++) {
        if (delimiter[i] == c) return 1;
    }
    return 0;
}

int str_sort(const char* src,char* str, char** words) {
    if (src == NULL || words == NULL || str == NULL) return -2;
    strcpy_s(str, max_len,src);

    int word_count = 0;
    int len = strlen(str);
    //check if parameter is empty
    if (len == 0) {
        return -1;
    }
    char* p = str;


    //skip leading delimiters
    while (isDelimiter(*p)) p++;
    if (*p == '\0' || *p == '.') {
        return -1;
    }

    words[0] = p;
    word_count = 1;

    //set pointers at the beginning  of the words
    while (*p) {

        if (*p == '\0' || *p == '.') {
            *p = '\0';
            break;
        }
        if (isDelimiter(*p)) {
            *p = '\0';
            if (isDelimiter(*(p + 1))) {
                while (isDelimiter(*(p + 1))) {
                    p++;

                }
            }

            if (!isDelimiter(*(p + 1)) && *(p + 1) != '\0' && *(p + 1) != '.') {
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
    return word_count;
}
int main() {
    //char str[] = "a,          c,		b, \nabbc,abc.";

    //char str[] = "c,a,b.";

    //char str[] = "		a,          c,		b, \nabbc,abc.";

    //char str[] = "a,          c,		b, \nabbc,abc.";

    //char str[] = "12344, 123. 123.";

    //char str[] = " \t\n."

    //char str[] = "one,,,two three.";
    //char str[] = "one two three ";
    //char str[] = "a . b";



    //char str[] = "";

    // char str[] = "hello";

    // char str[] = "hello.";


    // char str[] = "world hello.";

    // char str[] = "one two three ";

    // char str[] = "a\tb\nc.";

    // char str[] = "a b. c";

    // char str[] = "a . b";


    // char str[] = "a .";


    // char str[] = "a..b";


    // char str[] = ".hello";

    // char str[] = "a  .  b";

    // char str[] = "a. b";

    char str[] = "a b ab ";
    char copy[max_len];
    char* words[max_words];
    int cnt = str_sort(str,copy, words);
    if (cnt >= 0) {
        for (int i = 0; i < cnt; i++) printf("%s\n", words[i]);
    }
    else {
        printf("Error");
    }


    return 0;
}