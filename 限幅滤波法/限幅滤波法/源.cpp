#include <iostream>
using namespace std;

//�޷��˲�
/*  Nֵ�ɸ���ʵ���������
valueΪ���һ����Ч��ֵ ��
new_valueΪ��ǰ����ֵ
�˲����򷵻���Ч��ʵ��ֵ  
*�ŵ㣺����Ч�˷���żȻ����������������
*ȱ�㣺�޷��������������Եĸ��ţ���ƽ���Ȳ�	*/

#define N 10
int value = 100;

int filter(int new_value)
{
	if ((new_value - value > N) || (value - new_value) > N)
	{
		return value;
	}
	return new_value;
}

int main(int argc, char* argv[])
{
	int A[] = { 110,90,88,95,97,99,80 };
	int n = sizeof(A) / sizeof(int);

	printf("�˲�ǰ����Ϊ��");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n�˲�������Ϊ��");
	for(int i = 0;i<n;i++)
	{
		printf("%d ", filter(A[i]));
	}

	system("pause");
	return 0;
}