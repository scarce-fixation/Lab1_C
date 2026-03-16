#include <stdio.h>
#include <string.h>

int count_word_occurence(char* sentence, char* word) {
        int sLen = strlen(sentence);
        int wLen = strlen(word);

        int mismatch = 0;
        int count = 0;

        if (wLen == 0 || sLen == 0) {
                printf("Error: One or more parameters are empty");
                return -1;
        }

        for (int i = 0, j = 0; i <= sLen; i++) {
                mismatch = 0;
                int isCharI = (sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z') || (sentence[i] >= '0' && sentence[i] <= '9');
                int isCharJ = (sentence[j] >= 'a' && sentence[j] <= 'z') || (sentence[j] >= 'A' && sentence[j] <= 'Z') || (sentence[i] >= '0' && sentence[i] <= '9');
                if (!isCharI) {
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
                        if (!isCharJ) j++;
                }
        }
        return count;
}

int main()
{

    return 0;
}

