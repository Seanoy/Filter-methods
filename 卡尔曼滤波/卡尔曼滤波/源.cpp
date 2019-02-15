#include <iostream>
using namespace std;

/*-----------------------------------------------*\
|  Kalman Filter equations                        |
|                                                 |
|  state equation状态方程							  |
|  x(k) = A·x(k-1) + B·u(k) + w(k-1)              |
|  如果没有控制量则B·u(k)=0（如单纯测量温度湿度之类的）	  |
|												  |
|  observations equation观测方程（传感器测得数据）	  |
|  z(k) = H·x(k) + y(k)                           |
|                                                 |
|  prediction equations预测方程					  |
|  x(k|k-1) = A·x(k-1|k-1) + B·u(k)               |
|  P(k|k-1) = A·P(k-1|k-1)·A^T + Q                |
|                                                 |
|  correction equations修正方程					  |
|  K(k) = P(k|k-1)·H^T·(H·P(k|k-1)·H^T + R)^(-1)  |
|  x(k|k) = x(k|k-1) + K(k)·(z(k) - H·x(k|k-1))   |
|  P(k|k) = (I - K(k)·H)·P(k|k-1)                 |

x和P只需要赋初值，每次迭代会产生新值；K用不着赋初值；
Q和R赋值以后在之后的迭代中也可以改。
x和P的初值是可以随便设的，强大的卡尔曼滤波器马上就能抹除不合理之处。
但需注意，P的初值不能为0，否则滤波器会认为已经没有误差了
R越大曲线越平滑，但会使滤波器变得不敏感，存在滞后
（Q和R取值也可以是时变的，可以识别跳变，可以自适应）

Q:过程噪声，Q增大，动态响应变快，收敛稳定性变坏
R:测量噪声，R增大，动态响应变慢，收敛稳定性变好
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
	p_mid = p_last;				//p_mid=p(k|k-1),p_last=p(k-1|k-1),Q=过程噪声

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
