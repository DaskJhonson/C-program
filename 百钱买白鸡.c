#include <stdio.h>
#include<time.h>
#include<stdlib.h>

int check(int array[][5], int n, int checknum);
int main()
{
	int y = 0,x=0;
	int a[5][5];    //构建一个二维数组存放满足条件的数组，并排除重复项
	srand((unsigned)time(NULL));
	while (y<4) {
		int i = (int)rand() % 20; //利用取余限制随机数范围
		int j = (int)rand() % 33;
		int k = 100 - i - j;
		printf("%d  %d %d  %d \n", i, j,k, (5 * i + 3 * j + k / 3));
		if (k % 3 == 0 && (5 * i + 3 * j + k / 3) == 100) {
			if (check(a, 4, i)) {
				a[y][0] = i;
				a[y][1] = j;
				a[y][2] = k;
				y++;
				printf("*************************找到第%d个*************************\n",y);
				Sleep(1000);    //当找到满足项时，程序睡眠1.5s
			}
		}
		x++;
	}
	for (int plan = 1; plan<y+1; plan++) {
		printf("方案%d：公鸡有%d只，母鸡有%d只，小鸡有%d只.\n", plan, a[plan - 1][0], a[plan - 1][1], a[plan - 1][2]);
	}
	printf("总循环次数：%d\n",x);   //统计循环次数与穷举法进行比较效率
}

int check(int array[][5], int n, int checknum) { //检查在数组中是否含有重复项，只需检查第一项即可
	for (int x = 0; x<n; x++) {
		if (array[x][0] == checknum) {
			return 0;	
		}
	}
	return 1;
}
