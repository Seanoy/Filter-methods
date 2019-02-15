#include <iostream>
using namespace std;

//中位值平均滤波法（又称防脉冲干扰平均滤波法）
/********************************************
说明：采一组队列去掉最大值和最小值
优点：融合了两种滤波的优点。对于偶然出现的脉冲性干扰，可消
除有其引起的采样值偏差。对周期干扰有良好的抑制作用，
平滑度高，适于高频振荡的系统。
缺点：测量速度慢
*********************************************/
#define N 12

int filter()
{
	char count, i, j;
	char buf[N];
	int sum = 0, temp;
	for (count = 0; count < N; count++)
	{
		//buf[count] = get_val();//获取采样值
		//delay();
	}
	for (i = 0; i < N - 1; i++)
	{ 
		for (j = 0; j < N - j - 1; j++)
		{
			if (buf[i] > buf[i + 1])
			{
				temp = buf[i];
				buf[i] = buf[i+1];
				buf[i + 1] = temp;
			}
		}
	}
	for (count = 1; count < N - 1; count++)
	{
		sum += buf[count];//由于数列已经排序了，所以去掉头尾就是去掉最小值和最大值
	}
	return (sum / (N - 2));
}

int main(int argv, char* argc[])
{
	
	return 0;
}