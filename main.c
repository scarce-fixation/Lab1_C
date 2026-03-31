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

int str_sort( char* str) {
    if (str == NULL) return -2;
    char* words[max_words];

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

    char buffer[max_len];
    char* buff_ptr = buffer;
    int first_word = 1;

    for (int i = 0; i < word_count; i++) {
        if (!first_word) *buff_ptr++ = ' ';

        first_word = 0;

        char* word_ptr = words[i];
        while (*word_ptr != '\0') {
            *buff_ptr++ = *word_ptr++;

        }

    }
    *buff_ptr = '\0';

    strcpy(str, buffer);
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

    //new test cases
    // char str[] = "A a AC ac aBd Abd";

    // char str[] = "zyx xyz fedcba abcdef";

    // char str[] = "z q w e r r t y u i o p a s d f g h j k l z x c v b n m";


    // char str[] = "qwertyuio lkjhgfds qazwsxc";


    // char str[] = "a ab abc abcde";
    //char str[] = "pneumonoultramicroscopicsilicovolcanoconiosis antidisestablishmentalism floccinaucinihilipilification a aa aaa";
    //char str[] = "test test test case case duplicate duplicate unique";
    //char str[] = "ab AA aB Ab aBc Abc";
    char str[] = "a b c d e f g h i j k l m n o p q r s t u v w x y z a b c d e f g h i j k l m n o p q r s t u v w x y z"; // 52 words
    // char str[] = "19 1 11 21 2 23 85 58 75 57 ";

    // char str[] = "a aa aaa aaaa aaca aaaza aaaaa ";

    //char str[] = "a b ab ";

    int cnt = str_sort(str);
    if (cnt >= 0) {
        printf("%s\n", str);
    }
    else {
        printf("Error");
    }


    return 0;
}