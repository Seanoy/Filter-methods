#include <iostream>
using namespace std;

/************************************************	
�޷�ƽ���˲���
�ŵ㣺����żȻ���ֵ������Ը��ţ���������������Ĳ���ֵƫ�
*************************************************/
#define E 10         //�������ֵ
#define N 12        //����������Ŀ
char value_init = 100;  //�����ο�ֵ
char temp;
char getval();
char filter(void)
{
	char i, value_now, value_before, sum, count = 0;
	//count:��ֹ�����������������ѭ��
	char *buf = (char*)malloc(N * sizeof(char));
	while (1)//ֱ��ȡ����ЧֵΪֹ
	{
		temp = getval();
		if ((temp - value_init >E) || (temp - value_init <E))
		{
			temp = getval();
			count++;
				if (count == 5) {
					buf[0] = value_init;
					break;
				}
		}
		else
		{
			buf[0] = temp;            //��ȡ����ֵ������һ�ε�ֵ
			break;
		}
	}

	for (i = 1; i < N; i++)     //���˳�����Χ��ֵ
	{
		value_now = getval();     //��ȡ����ֵ������һ�ε�ֵ
		if ((value_now - buf[i - 1]) > E || (buf[i - 1] - value_now) > E)
		{
			buf[i] = buf[i - 1];        //�������ݵ�����һ����
		}
		else
			buf[i] = value_now;           //����������Ч
	}

	for (i = 0; i < N; i++)
	{
		buf[i] = buf[i + 1];
		sum += buf[i];
	}
	return (sum / N);
}
