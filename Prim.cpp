#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<vector>
#define MAXN 1020

using  namespace std;

//1 2 5
int Map[MAXN][MAXN];
int inMap[MAXN];
int NumTown, NumRode;
int price = 0;
int NumInTowns = 1;

class Rode {

public:
	int townA, townB, miles;
	Rode(int a, int b, int c) {
		townA = a;
		townB = b;
		miles = c;
	};
	//重载比较操作符时的注意事项
	bool operator <(const Rode& r1)const {
		return this->miles > r1.miles;
	}

};

void Prim() {

	//首先找到初始节点
	inMap[1] = 0;
	//已经重载了小于操作符，不使用其自带的比较器
	//priority_queue<Rode,vector<Rode>,greater<Rode>> que;
	priority_queue<Rode> que;
	//找到初始边
	for (int i = 2; i <= NumTown; i++) {
		if (Map[1][i]) {
			que.push(Rode(1, i, Map[i][1]));
			//price += Map[i][2];
			//Map[i][0] = Map[0][i] = 0;
		}
	}

	//边队列中找到最短边，添加相应节点,标记。再添加边
	while (true) {

		if (que.empty())
			break;
		//每次拿出一个城镇后，再将其标记为0，
		//为不是在将城镇送入队列后标记为0
		Rode r = que.top();
		que.pop();
		int tempTown;
		if (inMap[r.townA])
			tempTown = r.townA;
		else if (inMap[r.townB])
			tempTown = r.townB;
		else
			continue;
		price += r.miles;
		NumInTowns += 1;
		inMap[tempTown] = 0;
		for (int i = 2; i <= NumTown; i++) {
			if (inMap[i] && Map[tempTown][i]) {
				//找到节点 添加边 后标记节点
				for (int j = 2; j < NumTown; j++)
					if (inMap[j] && Map[i][j]) {
						que.push(Rode(i, j, Map[i][j]));
						//inMap[i] = 0;
					}
			}

		}

	}

}

int main() {

	while (cin >> NumTown >> NumRode) {
		int a, b, c;
		price = 0;
		memset(Map, 0, sizeof(Map));
		memset(inMap, 0, sizeof(inMap));
		NumInTowns = 1;
		for (int i = 0; i < NumRode; i++) {
			cin >> a >> b >> c;
			Map[a][b] = c;
			Map[b][a] = c;
			inMap[a] = 1;
			inMap[b] = 1;
		}

		Prim();

		if (NumInTowns < NumTown)
			cout << -1 << endl;
		else
			cout << price << endl;

	}
}
