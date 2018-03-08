#include<stdio.h>
#define Combination co

int Factorial(int n); //定义一个阶乘的函数
int Combination(int m, int n);  //定义一个计算组合的函数
void Triangle(int n); 

int main() {
	Triangle(11);
}

int Factorial(int n) {  
	if (n < 0) {
		printf("error\n");  //防止出现特殊情况，导致程序错误
		return 0;
	}else if (n==0||n==1){
		return 1;
	}
	else
	{
		return Factorial(n - 1)*n;    //利用函数递归调用实现阶乘
	}
	
}

int Combination(int m, int n) {
	int c = Factorial(m) / (Factorial(n)*Factorial(m - n)); //根据组合的算法：Cmn（m为下标，n为上标）=m！/(n！*(m-n)！)
	return c;
}

void Triangle(int m){   //m为需要产生三角的行数，默认最多为13
	for (int n = 1; n <=m; n++)
	{
		for (int i = 1; i <= m - n; i++)
		{
			printf("   ");    //为每个数预留三个空格的位置，以便容纳三位数，样式简洁
		}
		for (int j = 1; j <= n - 1; j++)
		{	
			int c = co(n - 1, j - 1);
			if (c < 10) {
				printf(" %d    ",c );   //根据产生数的位数，适当调节数两边空格
			}
			else if (c<100)
			{
				printf(" %d   ", c);
			}
			else
			{
				printf("%d   ", c);
			}
		}
		printf(" 1 \n");
	}
}
