#include<stdio.h>
#include<string.h>
#define int_max 2147483647
#define int_min -2147483648
int convert_str_to_int32(char* num, int* res) {
    if (num == NULL || res == NULL)return -2;
    long long convertedNum = 0;
    int nLen = strlen(num);
    int sign = 0;
    int i = 0;

    if (nLen > 11) {
        return -1;
    }
    if (nLen == 0) {
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

            return -1;
        }
        int digit = num[i] - '0';
        convertedNum *= 10;
        convertedNum += digit;

    }
    if (sign) convertedNum *= -1;

    if (convertedNum > int_max) {
        return -1;
    }

    if (convertedNum < int_min) {
        return -1;
    }
    *res = (int)convertedNum;

    return 0;


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
    int res = 0;
    int err = convert_str_to_int32(number, &res);
    if (err != 0) printf("error");
    else printf("%d", res);


    return 0;
}