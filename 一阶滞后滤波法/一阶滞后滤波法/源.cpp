#include <iostream>
using namespace std;

/****************************************************
*�������ƣ�filter()-һ���ͺ��˲���
*˵����
1�����ú���
GetAD(),�ú�������ȡ�õ�ǰֵ
Delay(),������ʱ����
2������˵��
dataArr[N]:�ɼ�������
flag0��flag1:ǰһ�αȽ��뵱ǰ�Ƚϵķ���λ
coeff:�˲�ϵ��
filterCount���˲�������
3������˵��
N�����鳤��
thresholdValue���Ƚ��ż�ֵ
*****************************************************/

#define thresholdValue 10
#define N 10

float dataArr[N] = { 99,102,108,89,98,86,89,90,93,105 };
char flag0 = 0, flag1 = 0;

float abs(float first, float second)
{
	float abs_val;
	if(first>second)
	{
		abs_val = first - second;
		flag1 = 0;
	}
	else
	{
		abs_val = second - first;
		flag1 = 1;
	}
	return abs_val;
}


void filter(void)
{
	char i = 0, filterCount = 0, coeff = 0;
	float Abs = 0.00;

	//ȷ��һ���˲�ϵ��
	for (i = 1; i < N; i++)
	{
		Abs = abs(dataArr[i - 1], dataArr[i]);
		if (!flag1^flag0)
		{
			filterCount++;
			if (Abs >= thresholdValue)
			{
				filterCount += 2;
			}
			if (filterCount >= 12)
				filterCount = 12;
			coeff = 20 * filterCount;
		}
		else//����
			coeff = 5;
		//һ���˲��㷨
		if (flag1 == 0)//��ǰֵС��ǰһ��ֵ
			dataArr[i] = dataArr[i - 1] - coeff*(dataArr[i - 1] - dataArr[i]) / 256;
		else
			dataArr[i] = dataArr[i - 1] + coeff*(dataArr[i - 1] - dataArr[i]) / 256;
		filterCount = 0;
		flag0 = flag1;
	}
}

int main(int argv, char* argc)
{
	for (int i = 0; i < 10; i++)
		printf("%.3f ", dataArr[i]);
	printf("\n");
	filter();
	for (int i = 0; i < 10; i++)
		printf("%.3f ", dataArr[i]);
	system("pause");
	return 0;
}
