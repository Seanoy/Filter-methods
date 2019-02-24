#include <iostream>
using namespace std;

/************************************************	
限幅平均滤波法
优点：对于偶然出现的脉冲性干扰，可消除由其引起的采样值偏差。
*************************************************/
#define E 10         //误差允许值
#define N 12        //采样数据数目
char value_init = 100;  //采样参考值
char temp;
char getval();
char filter(void)
{
	char i, value_now, value_before, sum, count = 0;
	//count:防止传感器出错而陷入死循环
	char *buf = (char*)malloc(N * sizeof(char));
	while (1)//直到取得有效值为止
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
			buf[0] = temp;            //获取采样值用作上一次的值
			break;
		}
	}

	for (i = 1; i < N; i++)     //过滤超出范围的值
	{
		value_now = getval();     //获取采样值用作上一次的值
		if ((value_now - buf[i - 1]) > E || (buf[i - 1] - value_now) > E)
		{
			buf[i] = buf[i - 1];        //本次数据等于上一数据
		}
		else
			buf[i] = value_now;           //本次数据有效
	}

	for (i = 0; i < N; i++)
	{
		buf[i] = buf[i + 1];
		sum += buf[i];
	}
	return (sum / N);
}
