#include<iostream>
#include<queue>
#include<map>
#include<cstring>
#include<string>

#define MAXN 1010
using namespace std;
int Inmap[MAXN];
int result;
int NumRodes;
class Rode {
public:
    int miles;
    int townA;
    int townB;
    Rode(int a, int b, int c) :miles(a), townA(b), townB(c) {};
    bool operator <(const Rode& a)const {
        return (this->miles) > (a.miles);
    }

};


priority_queue<Rode> que;

void Kruskal() {
    while (!que.empty()) {
        Rode r = que.top();
        que.pop();

        if (Inmap[r.townA] || Inmap[r.townB]) {
            result += r.miles;
            NumRodes++;
            Inmap[r.townA] = 0;
            Inmap[r.townB] = 0;
        }
    }
}


int main() {
    int N, M, a, b, c;
    while (cin >> N >> M) {
        memset(Inmap, 0, sizeof(Inmap));
        result = 0;
        NumRodes = 0;
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> c;
            Rode temp(c, a, b);
            que.push(temp);
            Inmap[a] = 1;
            Inmap[b] = 1;
        }
        Kruskal();
        for (int i = 1; i <= N; i++)
            if (Inmap[i]) {
                result = -1;
            }
        if (NumRodes + 1 != N)
            result = -1;

        cout << result << endl;
    }

}
