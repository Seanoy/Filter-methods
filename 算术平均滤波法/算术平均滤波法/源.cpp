#include <iostream>
using namespace std;

//算术平均滤波法
/*  N值可根据实际情况调整*/
/*********************************************************
说明：连续取N个采样值进行算术平均运算
优点：试用于对一般具有随机干扰的信号进行滤波。这种信号的特点是
有一个平均值，信号在某一数值范围附近上下波动。
缺点：对于测量速度较慢或要求数据计算较快的实时控制不适用。
**********************************************************/
#define N 10

int filter(void)
{
	int sum = 0, count;
	for (count = 0; count < N; count++)
	{
		//sum += get_val();获取采样值并求和
		//delay();
	}
	return (sum / N);

}

int main(int argc, char* argv[])
{
	int A[] = { 110,90,88,95,97,99,80,90,88,91,85,94,98,88,98,100,113 };
	int n = sizeof(A) / sizeof(int);

 

	system("pause");
	return 0;
}