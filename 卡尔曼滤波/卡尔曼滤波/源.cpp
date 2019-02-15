#include <iostream>
using namespace std;

/*-----------------------------------------------*\
|  Kalman Filter equations                        |
|                                                 |
|  state equation״̬����							  |
|  x(k) = A��x(k-1) + B��u(k) + w(k-1)              |
|  ���û�п�������B��u(k)=0���絥�������¶�ʪ��֮��ģ�	  |
|												  |
|  observations equation�۲ⷽ�̣�������������ݣ�	  |
|  z(k) = H��x(k) + y(k)                           |
|                                                 |
|  prediction equationsԤ�ⷽ��					  |
|  x(k|k-1) = A��x(k-1|k-1) + B��u(k)               |
|  P(k|k-1) = A��P(k-1|k-1)��A^T + Q                |
|                                                 |
|  correction equations��������					  |
|  K(k) = P(k|k-1)��H^T��(H��P(k|k-1)��H^T + R)^(-1)  |
|  x(k|k) = x(k|k-1) + K(k)��(z(k) - H��x(k|k-1))   |
|  P(k|k) = (I - K(k)��H)��P(k|k-1)                 |

x��Pֻ��Ҫ����ֵ��ÿ�ε����������ֵ��K�ò��Ÿ���ֵ��
Q��R��ֵ�Ժ���֮��ĵ�����Ҳ���Ըġ�
x��P�ĳ�ֵ�ǿ��������ģ�ǿ��Ŀ������˲������Ͼ���Ĩ��������֮����
����ע�⣬P�ĳ�ֵ����Ϊ0�������˲�������Ϊ�Ѿ�û�������
RԽ������Խƽ��������ʹ�˲�����ò����У������ͺ�
��Q��RȡֵҲ������ʱ��ģ�����ʶ�����䣬��������Ӧ��

Q:����������Q���󣬶�̬��Ӧ��죬�����ȶ��Ա仵
R:����������R���󣬶�̬��Ӧ�����������ȶ��Ա��
\*-----------------------------------------------*/


#define KalmanQ 0.000001
#define KalmanR 0.0004

static double KalmanFilter(const double ResourceData, double ProcessNoiseQ, double MeasureNoiseR)
{
	double R = MeasureNoiseR;
	double Q = ProcessNoiseQ;

	static double x_last=-60;
	double x_mid = x_last;
	double x_now;

	static double p_last=1;
	double p_mid;
	double p_now;

	double K;

	x_mid = x_last;				//x_last=x(k-1|k-1),x_mid=x(k|k-1)
	p_mid = p_last;				//p_mid=p(k|k-1),p_last=p(k-1|k-1),Q=��������

	K = p_mid / (p_mid + R);
	x_now = x_mid + K*(ResourceData - x_mid);
	p_now = (1 - K)*p_mid + Q;
	p_last = p_now;
	x_last = x_now;

	return x_now;
}


int main(int argv, char* argc[])
{
	int a=0;
	double data[] = { -59,-60,-55,-56,-56,-56,-57,-57,-59,-61,
					  -57,-57,-57,-57,-57,-58,-57,-61,-57,-61,
					  -59,-61,-60,-60,-59,-57,-56,-58,-58,-57,
					  -57,-57,-57,-57,-60,-58,-61,-60,-60,-60,
					  -57,-57,-57,-57,-58,-57,-58,-57,-58,-57,
					  -58,-61,-58,-61,-62,-61,-61,-57,-57,-57,
					  -57,-58,-57,-58,-57,-58,-61,-61,-60,-60,
					  -58,-57,-57,-57,-57,-58,-58,-58,-58,-60,
					  -61,-60,-57,-57,-57,-57,-57,-58,-58,-57,
					  -57,-57,-60,-57,-60,-60,-59,-60,-57,-56 };
	int length = sizeof(data) / sizeof(double);
	for (int i = 1; i < length; i++)
	{
		printf("%.1f ", KalmanFilter(data[i], KalmanQ, KalmanR));
		a++;
		if (a == 10) { printf("\n"); a = 0; }
	}a = 0;
		

	system("pause");
	return 0;
}
