#include <iostream>
using namespace std;

//��λֵƽ���˲������ֳƷ��������ƽ���˲�����
/********************************************
˵������һ�����ȥ�����ֵ����Сֵ
�ŵ㣺�ں��������˲����ŵ㡣����żȻ���ֵ������Ը��ţ�����
����������Ĳ���ֵƫ������ڸ��������õ��������ã�
ƽ���ȸߣ����ڸ�Ƶ�񵴵�ϵͳ��
ȱ�㣺�����ٶ���
*********************************************/
#define N 12

int filter()
{
	char count, i, j;
	char buf[N];
	int sum = 0, temp;
	for (count = 0; count < N; count++)
	{
		//buf[count] = get_val();//��ȡ����ֵ
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
		sum += buf[count];//���������Ѿ������ˣ�����ȥ��ͷβ����ȥ����Сֵ�����ֵ
	}
	return (sum / (N - 2));
}

int main(int argv, char* argc[])
{
	
	return 0;
}