#include <iostream>
using namespace std;

/************************************************************
��Ȩ����ƽ���˲���
coe:����Ϊ��Ȩϵ�������ڳ���洢����
sum_coe:��Ȩϵ����
************************************************************/


#define N 12
const char coe[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
const char sum_coe = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12;
char value_buf[N] = { 100,102,88,99,77,103,110,101,113,98,89,91 };

char filter()
{
	char i;
//	char value_buf[N];
	int sum = 0;
/*	for (i = 0; i < N; i++)
	{
		//value_buf[i] = get_val();//��ȡ��������
		//delay();
	}*/
	for (i = 0; i < N; i++)
		sum += value_buf[i] * coe[i];
	return sum / sum_coe;

}


int main(int argv, char*argc[])
{
	for (int i = 0; i < N; i++)
	{
		printf("%d ", value_buf[i]);
	}
	printf("\n");
	printf("%d ",filter());
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		printf("%d ", value_buf[i]);
	}

	system("pause");
	return 0;
}