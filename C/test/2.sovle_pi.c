#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    clock_t t1, t2;
    double time_taken;
    int x, a, b, amount = 0;
    double pi0 = M_PI;
    double result;

    printf("需要多少分辨率的网格？（输入正整数）\n");
    scanf("%d", &x);
    getchar();
    t1 = clock();

    for (a = 0; a < x; a++) {
        for (b = 0; b < x; b++) {
            if ((a > (x / 2) || b > (x / 2)) && pow(a + (50.0 / x), 2) + pow(b + (50.0 / x), 2) < pow(x, 2)) {
                amount++;
            }
        }
    }

    amount += (int) (pow(x, 2) / 4);
    result = (double) amount * 4 / pow(x, 2);

    t2 = clock();

    time_taken = ((double)t2 - t1) / CLOCKS_PER_SEC;

    printf("在分辨率为%d*%d的情况下\n", x, x);
    printf("结果为%.10f\n", result);
    printf("pi值应为%.10f\n", pi0);
    printf("运行时间为%.6fs\n", time_taken);
    getchar();
    return 0;
}
