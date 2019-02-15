#include <iostream>
using namespace std;

/****************************************************
*函数名称：filter()-一阶滞后滤波法
*说明：
1、调用函数
GetAD(),该函数用来取得当前值
Delay(),基本延时函数
2、变量说明
dataArr[N]:采集的数据
flag0、flag1:前一次比较与当前比较的方向位
coeff:滤波系数
filterCount：滤波计数器
3、常量说明
N：数组长度
thresholdValue：比较门槛值
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

	//确定一阶滤波系数
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
		else//消抖
			coeff = 5;
		//一阶滤波算法
		if (flag1 == 0)//当前值小于前一个值
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
