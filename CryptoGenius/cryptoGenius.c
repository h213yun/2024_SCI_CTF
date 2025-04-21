#include <stdio.h>

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);

    long long int pw = 100010002024;
    long long int s1 = 0;

    printf("Oops! The RSA key was too short.\n\n");
    printf("encrypted message c: 17\ndecrypted message m: ?\n\n");
    printf("*hint: When the remainder is 1, the quotient is also 1.*\n");

    printf("\npassword: ");

    // 여러 개의 숫자를 입력받음
    if (scanf("%lld", &s1) == 1) {
        // 입력 성공
        if (pw == s1) {
            printf("\nCongratulations! You've got a golden ticket. \n\n");
            printf("  .+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.\n");
            printf("  |                                     |\n");
            printf("  |           *GOLDEN TICKET*           |\n");
            printf("  |                                     |\n");
            printf("  |   You really are a cipher genius.   |\n");
            printf("  | SCI{h4ppy_n3w_y3Ar!_2024_1S_yOur5}  |\n");
            printf("  |                                     |\n");
            printf("  .+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.\n\n");
        } else {
            printf("\nPlease try again\n");
        }
    } else {
        // 입력 실패
        printf("\nNumbers only, please\n");
    }

    return 0;
}