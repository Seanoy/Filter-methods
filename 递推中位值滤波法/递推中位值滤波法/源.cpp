#include <iostream>
using namespace std;
/************************************************
�ŵ㣺����żȻ���ֵ������Ը��ţ���������������Ĳ���ֵƫ�
�������Ը��������õ��������ã�ƽ���ȸߣ������ڸ�Ƶ��
��ϵͳ
ȱ�㣺�����ٶ���
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
		queue[i-1] = queue[i];//�������λ �����Ƚ��ȳ�
	}
	sum = sum - max - min;
	return (sum / (n - 2));

}


