#include<stdio.h>
#include<string.h>
#define int_max 2147483647
#define int_min -2147483648
int convert_str_to_num(char* num) {
        long long convertedNum = 0;
        int nLen = strlen(num);
        int sign = 0;
        int i = 0;

        if (nLen > 11) {
                printf("Error: Number is too big or too small\n");
                return -1;
        }
        if (nLen == 0) {
                printf("Error: Parameter is empty \n");
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
        if (sign) convertedNum *= -1;

        if (convertedNum > int_max) {
                printf("Int overflow\n");
                return -1;
        }

        if (convertedNum < int_min) {
                printf("Int overflow\n");
                return -1;
        }

        return (int)convertedNum;


}
int main() {
        //expected output is 123
        char number[] = "123";

        //expected output is Error: Parameter is empty
        //char number[] = "";
        //
        ////expected output is -123
        //char number[] = "-123";

        ////expected output is 2147483647
        //char number[] = "2147483647";

        ////expected output is -2147483648
        //char number[] = "-2147483648";

        ////expected output is Error: Parameter contains not digit symbols
        //char number[] = "ab dc";

        ////expected output is Error: Parameter contains not digit symbols
        //char number[] = "123cf3245";

        ////expected output is Error: Parameter contains not digit symbols
        //char number[] = "\t";

        ////expected output is Error: Parameter contains not digit symbols
        //char number[] = "\n";

        ////expected output is Error: Parameter contains not digit symbols
        //char number[] = ".g";

        ////expected output is Error: Number is too big or too small
        //char number[] = "99999999999999999";

        ////expected output is Int overflow
        //char number[] = "2147483649";



        printf("%d", convert_str_to_num(number));

        return 0;
}