#include <iostream>
using namespace std;


#define N 12
char value;					//上次采样到的数据
char get_val()
{
	char data = 0;
	//采样数据相关程序
	//...
	
	return data;
}

char filter() 
{
	char count = 0;
	char new_value;
	new_value = get_val();//获取采样数据
	while (value != new_value)
	{
		count++;
		if (count >= N)
			return new_value;
		//delay();//适当延时
		new_value = get_val();//获取下一个采样数据

	}
	return value;
}