#include <iostream>
using namespace std;


#define N 12
char value;					//�ϴβ�����������
char get_val()
{
	char data = 0;
	//����������س���
	//...
	
	return data;
}

char filter() 
{
	char count = 0;
	char new_value;
	new_value = get_val();//��ȡ��������
	while (value != new_value)
	{
		count++;
		if (count >= N)
			return new_value;
		//delay();//�ʵ���ʱ
		new_value = get_val();//��ȡ��һ����������

	}
	return value;
}