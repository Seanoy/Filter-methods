#include <iostream>
using namespace std;

//��λֵ�˲���
/*  Nֵ�ɸ���ʵ��������� NΪ����
�������ð�ݷ�*/
/****************************************************
*�������ƣ�MiddlevalueFilter()-��λֵ�˲���
*�ŵ㣺����Ч�˷���żȻ��������Ĳ������ţ����¶ȡ�Һ
λ�ȱ仯�����ı�����������õ��˲�Ч��
*ȱ�㣺���������ٶȵȿ��ٱ仯�Ĳ�������
*****************************************************/
#define N 5

int filter(void)
{
	int *buf = (int*)malloc(N * sizeof(int));
	char count, i, j, temp;
	for (count = 0; count < N; count++)
	{
		//buf[count] = get_val();//�µĲ���ֵ
		//delay();
	}
	for (j = 0; j<N - 1; j++)
	{
		for (i = 0; i<N - j - 1; i++)
		{
			if (buf[i]>buf[i + 1])
			{
				temp = buf[i];
				buf[i] = buf[i + 1];
				buf[i + 1] = temp;
			}
		}
	}

	free(buf);
	return buf[(N - 1) / 2];

}

int main(int argc, char* argv[])
{
	int A[] = { 110,90,88,95,97,99,80,90,88,91,85,94,98,88,98,100,113 };
	int n = sizeof(A) / sizeof(int);


	system("pause");
	return 0;
}