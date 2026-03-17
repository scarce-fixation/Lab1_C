#include <stdio.h>
#include <string.h>

int isDelimiter(char c) {
        char delimiter[] = " \t\n!?.,\"\':;(){}[]-";
        int len = strlen(delimiter);

        for (int i = 0; i < len; i++) {
                if (delimiter[i] == c) return 1;
        }
        return 0;
}

int count_word_occurence(char* sentence, char* word) {
        if(sentence == NULL || word == NULL) return -1;
        int sLen = strlen(sentence);
        int wLen = strlen(word);


        int mismatch = 0;
        int count = 0;

        if (wLen == 0 || sLen == 0) {                
                return -1;
        }

        for (int i = 0, j = 0; i <= sLen; i++) {
                mismatch = 0;
                int isIDiv = isDelimiter(sentence[i]);

                if (isIDiv || sentence[i] == '\0') {
                        if ((i - j) == wLen) {
                                for (int k = 0; j < i; j++, k++) {
                                        if (sentence[j] != word[k]) {
                                                mismatch = 1;
                                                break;
                                        }
                                }
                                if (!mismatch) count++;
                        }
                        j = i;
                        int isJDiv = isDelimiter(sentence[j]);
                        if (isJDiv) j++;
                }
        }
        return count;
}

int main()
{
        ////expected output is 4
        //char sentence[] = "abbc abbbc abbc abbc		abbc";
        //char word[] = "abbc";
        //expected output is 4
        /*char sentence[] = "(a) {a} {{{a";
        char word[] = "a";*/

        //expected output is 8
        char sentence[] = "abbc, abbc.abbc!abbc	(abbca ) (abbc) {abbc} [abbc] abbc-ddef";
        char word[] = "abbc";

        ////expected output is -1
        //char sentence[] = "";
        //char word[] = "";

        ////expected output is 0
        //char sentence[] = "  ";
        //char word[] = "abbc";
        //
        ////expected output is 1
        //char sentence[] = "	abbc	";
        //char word[] = "abbc";

        printf("%d", count_word_occurence(sentence, word));
    return 0;
}

