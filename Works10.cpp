#include<iostream>
#include<time.h>
#include<iomanip>
#include<fstream>
#include<algorithm>

using namespace std;

struct a{
    int si;//开始时间
    int fi;//结束时间
    int ii;//编号
};

bool compare(a x,a y){
    return x.fi<=y.fi;
}
int main(){
    int m=10;
    a action[m];

    for(int i = 0; i < m; i++){
        cin>>action[i].si>>action[i].fi;
        action[i].ii = i+1;
    }
    int num=1;
    int b[m];
    sort(action,action+m,compare);
    b[num++]=action[0].ii;
    int k=0;
    for(int i=1;i<m;i++){
        if(action[i].si>=action[k].fi){
            b[num++]=action[i].ii;
            k=i;
        }
    }
    ofstream fout;
    fout.open("output1.txt");
    for(int i=0;i<num;i++)
        fout<<b[i]<<' ';

    return 0;

}
