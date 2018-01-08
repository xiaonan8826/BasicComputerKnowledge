#include <stdio.h>
#include <stdlib.h>

int main( )
{
	int k,n,square[10],alpha[10],beta[10];
    scanf("%d",&k);
    square[0] = 0;
    square[1] = 1;
    square[2] = 4;
	alpha[1] = 1;
    for(n=2;n<k;n++){
		alpha[n] = square[n] - square[n-1];
        beta[n] = alpha[n] - alpha[n-1];
		square[n+1] = square[n] + alpha[n] + beta[n];
    }
    printf("output:%d",square[k]);
}
