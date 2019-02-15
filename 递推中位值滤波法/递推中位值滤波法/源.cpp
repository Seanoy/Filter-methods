#include <iostream>
using namespace std;
/************************************************
优点：对于偶然出现的脉冲性干扰，可消除由其引起的采样值偏差。
对周期性干扰有良好的抑制作用，平滑度高；适用于高频振荡
的系统
缺点：测量速度慢
*************************************************/

int filter(int val, int queue[], char n)
{
	char max, min;
	char sum;
	char i;

	queue[0] = val;
	max = queue[0];
	min = queue[0];
	sum = queue[0];

	for (i = 1; i < n; i++)
	{
		if (queue[i] > max)
			max = queue[i];
		else if (queue[i] < min)
			min = queue[i];
		sum += queue[i];
		queue[i-1] = queue[i];//丢弃最低位 队列先进先出
	}
	sum = sum - max - min;
	return (sum / (n - 2));

}


