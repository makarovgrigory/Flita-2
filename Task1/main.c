#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int transfertodecimals(int element, int digit, int sumator, int ifcorrect, int notcorrect){
    digit = 0;
    sumator = 0;
    notcorrect = 0;
    while (element > 2) {
        ifcorrect = (element % 10);
        switch (ifcorrect) {
            case 1: case 0:
                sumator = sumator + pow(2, digit) * (element % 10);
                digit = digit + 1;
                element = element / 10;
                break;
            default:
                element = 0;
                notcorrect = 1;
                break;
        }
    }
    if (notcorrect == 0) {
        sumator = sumator + pow(2, digit) * (element);
    }
    else {
        sumator = -1;
    }
    return sumator;
}

int main(int argc, char *argv[]) {
    int lenmultitude, i, result, element, digit, sumator, ifcorrect = 0, notcorrect = 0;
    lenmultitude = atoi(argv[1]);
    int binarys[lenmultitude];
    int decimals[lenmultitude];
    printf("Your enter:\n");
    for (i = 0; i <= lenmultitude - 1; i++) {
        printf("%s\t", argv[i +2]);
        char *if_elem = argv[i + 2];
        int j = 0;
        while (if_elem[j]){
            if (!isdigit(if_elem[j]) || (if_elem[j] != '0' && if_elem[j] != '1')) {
                binarys[i] = -1;
                break;
            }
            j++;
        }
        if (binarys[i] != -1) {
            binarys[i] = atoi(argv[i + 2]);
            decimals[i] = 0;
        }
    }
    for (i = 0; i <= lenmultitude - 1; i++){
        if (binarys[i] != -1) {
            element = binarys[i];
            result = transfertodecimals(element, digit, sumator, ifcorrect, notcorrect);
            decimals[i] = result;
        }
        else {
            notcorrect = 1;
            decimals[i] = -1;
        }
    }
    printf("\nThe set of numbers in the bynary system:\n");
    for (i = 0; i <= lenmultitude - 1; i++) {
        printf("%d\t", binarys[i]);
    }
    printf("\n");
    printf("The set of numbers in the decimals system:\n");
    for (i = 0; i <= lenmultitude - 1; i++) {
        if (decimals[i] == -1)
            printf("incorrect enter data\t");
        else
            printf("%d\t", decimals[i]);
    }
    return 0;
}
