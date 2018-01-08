#include <stdio.h>
#include <stdlib.h>
/*重要思想：
	可以把各个变量形象化的看成一个个的小盒子，我们在进行迭代时可以想象
	动态的把这些小盒子套到变量上，随着迭代逐层移动
*/
/*
巴贝奇差分机
差分法用来计算一元二次多项式，符合计算机的计算方式
num		square	alpha		beta
0			0
1			1				1
2			4				3				2
3			9				5				2
*/

/*
下面的方法用数组存储差分计算得到的所有值
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
其实不用把所有的数都存到数组中 避免占用内存
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

