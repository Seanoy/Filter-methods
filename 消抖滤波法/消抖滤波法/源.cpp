#include <iostream>
using namespace std;


#define N 12
char get_val();
char filter()
{
	char count = 0;
	char value_now;
	char value_before = get_val();	//获取上一个采样数据
	while (value_now != value_before)
	{
		value_before = value_now;
		count++;
		if (count >= N)
			return value_before;
		//delay();//适当延时
		value_now = get_val();//获取下一个采样数据
	}
	return value_now;
}
