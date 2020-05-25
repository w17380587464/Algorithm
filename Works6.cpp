#include <stdio.h>
#include <stdlib.h>
int FindMinK(int data[], int l, int r, int k)
{
	int m = data[l + k - 1], t = 0;
	int i, j;
	data[l + k - 1] = data[r], data[r] = m;
	for (i = l - 1, j = l; j != r; ++j)
		if (data[j] < m)
			t = data[++i], data[i] = data[j], data[j] = t;
	t = data[++i], data[i] = data[j], data[j] = t;
	if (k == i - l + 1) return m;
	if (k > i - l + 1) return FindMinK(data, i + 1, r, k - i + l - 1);
	else    return FindMinK(data, l, i - 1, k);
}

int main()
{

	//初始化
	int data[100];
	int k = 30;
	for (int i = 0; i < 100; i++)
		data[i] = rand()%1000+1;

	//寻找第k小的元素 
	printf("%d\n", FindMinK(data, 0, 99, k));
	return 0;
}
