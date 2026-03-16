#include<stdio.h>
#include<string.h>
#define int_max 2147483647
int convert_str_to_num(char* num) {
        long long convertedNum = 0;
        int nLen = strlen(num);
        int sign = 0;
        int i = 0;

        if (nLen > 11) {
                printf("Error: Number is too big or too small\n");
                return -1;
        }
        if (num[0] == '-') {
                sign = 1;
                i = 1;
        }
        if (num[0] == '+') {
                i = 1;
        }

        for (; i < nLen; i++) {
                if (num[i] < '0' || num[i] > '9') {
                        printf("Error: Parameter contains not digit symbols\n");
                        return -1;
                }
                int digit = num[i] - '0';
                convertedNum *= 10;
                convertedNum += digit;

        }
        if (convertedNum > int_max) {
                printf("Int overflow\n");
                return -1;
        }

        if (sign) convertedNum *= -1;

        return (int)convertedNum;


}
int main() {


        char number[] = "123";
        printf("%d", convert_str_to_num(number));

        return 0;
}