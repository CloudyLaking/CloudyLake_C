#include <stdio.h>
#include<time.h> 


int main(void)
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
    getchar();
	return 0;
}