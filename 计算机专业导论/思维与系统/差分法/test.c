#include <stdio.h>
#include <stdlib.h>
/*
�ͱ����ֻ�
��ַ���������һԪ���ζ���ʽ�����ϼ�����ļ��㷽ʽ
num		square	alpha		beta
0			0
1			1				1
2			4				3				2
3			9				5				2
*/

/*
����ķ���������洢��ּ���õ�������ֵ
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
*/

/*
��ʵ���ð����е������浽������ ����ռ���ڴ�
*/
int main( )
{
	int k,n,square_m,square,alpha_m,alpha,beta,square_p;
  scanf("%d",&k);
  square_m = 1;
	alpha_m = 1;
	square = 4;  
  for(n=2;n<k;n++){
		alpha = square - square_m;
		beta = alpha - alpha_m;
		square_p = square + alpha + beta;
		square_m = square;
		square = square_p;
		alpha_m = alpha;
  }
  printf("output:%d",square);
}

