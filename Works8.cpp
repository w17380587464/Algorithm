#include <iostream>
using namespace std;

#define N 6
#define MAXVALUE 1000000

void matrix_chain_order(int* p, int len, int m[N + 1][N + 1], int s[N + 1][N + 1]);
void print_optimal_parents(int s[N + 1][N + 1], int i, int j);

int main()
{
	int p[N + 1] = { 30,35,15,5,10,20,25 };
	int m[N + 1][N + 1] = { 0 };
	int s[N + 1][N + 1] = { 0 };
	int i, j;
	matrix_chain_order(p, N + 1, m, s);
	cout << "m value is: " << endl;
	for (i = 1; i <= N; ++i)
	{
		for (j = 1; j <= N; ++j)
			cout << m[i][j] << " ";
		cout << endl;
	}
	cout << "s value is: " << endl;
	for (i = 1; i <= N; ++i)
	{
		for (j = 1; j <= N; ++j)
			cout << s[i][j] << " ";
		cout << endl;
	}
	cout << "The result is:" << endl;
	print_optimal_parents(s, 1, N);
	return 0;
}

void matrix_chain_order(int* p, int len, int m[N + 1][N + 1], int s[N + 1][N + 1])
{
	int i, j, k, t;
	for (i = 0; i <= N; ++i)
		m[i][i] = 0;
	for (t = 2; t <= N; t++)  //当前链乘矩阵的长度
	{
		for (i = 1; i <= N - t + 1; i++)  //从第一矩阵开始算起，计算长度为t的最少代价
		{
			j = i + t - 1;//长度为t时候的最后一个元素
			m[i][j] = MAXVALUE;  //初始化为最大代价
			for (k = i; k <= j - 1; k++)   //寻找最优的k值，使得分成两部分k在i与j-1之间
			{
				int temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (temp < m[i][j])
				{
					m[i][j] = temp;   //记录下当前的最小代价
					s[i][j] = k;      //记录当前的括号位置，即矩阵的编号
				}
			}
		}
	}
}

//s中存放着括号当前的位置
void print_optimal_parents(int s[N + 1][N + 1], int i, int j)
{
	if (i == j)
		cout << "A" << i;
	else
	{
		cout << "(";
		print_optimal_parents(s, i, s[i][j]);
		print_optimal_parents(s, s[i][j] + 1, j);
		cout << ")";
	}

}
