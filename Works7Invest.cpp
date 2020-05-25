#include <iostream>
#include <math.h>
using namespace std;
int func1(int dp[5][6], int f[5][6], int n, int money) {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= money; j++) {
			dp[i][j] = 0;
			for (int k = 0; k <= j; k++) {
				if (dp[i][j] < f[i][k] + dp[i - 1][j - k])
					dp[i][j] = f[i][k] + dp[i - 1][j - k];
			}
		}
	}
	return dp[n][money];
}
int dp[5][6];
int main() {
	
	int f[5][6] = { 0,0,0,0,0,0,
					0,11,12,13,14,15,
					0,0,5,10,15,20,
					0,2,10,30,32,40,
					0,20,21,22,23,24
	};
	cout << func1(dp, f, 4, 5);
	return 0;
}
