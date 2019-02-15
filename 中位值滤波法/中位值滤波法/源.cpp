#include <iostream>
using namespace std;

//中位值滤波法
/*  N值可根据实际情况调整 N为奇数
排序采用冒泡法*/
/****************************************************
*函数名称：MiddlevalueFilter()-中位值滤波法
*优点：能有效克服因偶然因素引起的波动干扰；对温度、液
位等变化缓慢的被测参数有良好的滤波效果
*缺点：对流量，速度等快速变化的参数不宜
*****************************************************/
#define N 5

int filter(void)
{
	int *buf = (int*)malloc(N * sizeof(int));
	char count, i, j, temp;
	for (count = 0; count < N; count++)
	{
		//buf[count] = get_val();//新的采样值
		//delay();
	}
	for (j = 0; j<N - 1; j++)
	{
		for (i = 0; i<N - j - 1; i++)
		{
			if (buf[i]>buf[i + 1])
			{
				temp = buf[i];
				buf[i] = buf[i + 1];
				buf[i + 1] = temp;
			}
		}
	}

	free(buf);
	return buf[(N - 1) / 2];

}

int main(int argc, char* argv[])
{
	int A[] = { 110,90,88,95,97,99,80,90,88,91,85,94,98,88,98,100,113 };
	int n = sizeof(A) / sizeof(int);


	system("pause");
	return 0;
}