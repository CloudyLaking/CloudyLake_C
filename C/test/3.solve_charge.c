#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define LE 5

double solve_p(double xy[4][2]) {

    double sum = 0.0;
    for (int i1 = 0; i1 < 4; i1++) {
        double pi[4] = {0.0, 0.0, 0.0, 0.0};
        for (int i2 = 0; i2 < 4; i2++) {
            double d = sqrt(pow(xy[i1][0] - xy[i2][0], 2) + pow(xy[i1][1] - xy[i2][1], 2));
            
            if (d != 0) {
                pi[i1] += 10.0 / d;
                
            }
        }
        sum += pi[i1];
    }
    if (sum==0){
        return 10000000.0;
    }
    else{
        return sum;
    }

    
}

void xyarray() {
    double min_xy[2] = {0.0, 0.0};
    double xy[4][2] = {{0.0,0.0}, {0.0,0.0}, {0.0,0.0},{0.0,0.0}};
    double pmin =10000000.0;

    for (int a1 = 0; a1 <= LE; a1++) {
        for (int b1 = 0; b1 <= LE; b1++) {
            xy[0][0] = a1; xy[0][1] = b1;

            for (int a2 = 0; a2 <= LE; a2++) {
                for (int b2 = 0; b2 <= LE; b2++) {
                    xy[1][0] = a2; xy[1][1] = b2;

                    for (int a3 = 0; a3 <= LE; a3++) {
                        for (int b3 = 0; b3 <= LE; b3++) {
                            xy[2][0] = a3; xy[2][1] = b3;

                            for (int a4 = 0; a4 <= LE; a4++) {
                                for (int b4 = 0; b4 <= LE; b4++){
                                    xy[3][0] = a4; xy[3][1] = b4;
                                    double p = solve_p(xy);
                                    
                                    if (p < pmin) {
                                        pmin = p;
                                        
                                        min_xy[0] = xy[0][0]; min_xy[1]= xy[0][1];
                                    elif(p>pmin){
                                        continue;
                                    else{
                                        continue;
                                    }

                                    }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Minimum xy: [%f, %f]\n", min_xy[0], min_xy[1]);
    printf("Minimum potential: %f\n", pmin);
}

int main() {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    xyarray();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);
    getchar();
    return 0;
}
