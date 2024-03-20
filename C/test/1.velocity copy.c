#include <stdio.h>
#include<time.h> 

int circu()
{
    
    int i=1;
    int n=1;
    clock_t t1,t2;
    t1=clock();
    for(n=1;n<=500000;n++)
    {
           printf("%d\n",n);
    }
    t2=clock();
    double duration = ((double)(t1-t2))/CLK_TCK;
    printf("\n%f",duration);
}
int main(void)
{
    circu();
    getchar();
    return 0;
}
