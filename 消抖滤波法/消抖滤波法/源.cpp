#include <iostream>
using namespace std;


#define N 12
char get_val();
char filter()
{
	char count = 0;
	char value_now;
	char value_before = get_val();	//��ȡ��һ����������
	while (value_now != value_before)
	{
		value_before = value_now;
		count++;
		if (count >= N)
			return value_before;
		//delay();//�ʵ���ʱ
		value_now = get_val();//��ȡ��һ����������
	}
	return value_now;
}
