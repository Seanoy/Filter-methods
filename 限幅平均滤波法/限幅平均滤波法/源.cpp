#include <iostream>
using namespace std;

/************************************************	
�޷�ƽ���˲���
�ŵ㣺����żȻ���ֵ������Ը��ţ���������������Ĳ���ֵƫ�
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


