#include <iostream>
using namespace std;

//限幅滤波
/*  N值可根据实际情况调整
value为最近一次有效的值 ，
new_value为当前采样值
滤波程序返回有效的实际值  
*优点：能有效克服因偶然因素引起的脉冲干扰
*缺点：无法抑制那种周期性的干扰，且平滑度差	*/

#define N 10
int value = 100;

int filter(int new_value)
{
	if ((new_value - value > N) || (value - new_value) > N)
	{
		return value;
	}
	return new_value;
}

int main(int argc, char* argv[])
{
	int A[] = { 110,90,88,95,97,99,80 };
	int n = sizeof(A) / sizeof(int);

	printf("滤波前数组为：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n滤波后数组为：");
	for(int i = 0;i<n;i++)
	{
		printf("%d ", filter(A[i]));
	}

	system("pause");
	return 0;
}