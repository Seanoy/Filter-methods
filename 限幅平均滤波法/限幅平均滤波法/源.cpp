#include <iostream>
using namespace std;

/************************************************	
限幅平均滤波法
优点：对于偶然出现的脉冲性干扰，可消除由其引起的采样值偏差。
*************************************************/

#define A 10
#define N 12

char filter(char data[])
{
	char i, value, sum;
	//data[N] = getval();
	if ((data[N] - data[N - 1]) > A || (data[N - 1] - data[N]) > A)
	{
		data[N] = data[N - 1];
	}
	//else
		//data[N] = newval;
	for (i = 0; i < N; i++)
	{
		data[i] = data[i + 1];
		sum += data[i];
	}
	return (sum / N);
}


