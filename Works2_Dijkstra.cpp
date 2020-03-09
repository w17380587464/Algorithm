#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#define MAXN 1008611
#define MAX_SIZE 10086
using namespace std;
int dist[MAX_SIZE];
int collected[MAX_SIZE];
int path[MAX_SIZE];
int map[MAX_SIZE][MAX_SIZE];

void Dijkstra(int M){

    while(true){
        int min=MAXN;
        int minTown=0;
        for(int i=2;i<=M;i++)
            if(!collected[i] && dist[i]<min){
                min=dist[i];
                minTown=i;
            }

        for(int i=2;i<=M;i++)
            if(!collected[i] &&dist[i]>map[minTown][i]+dist[minTown]){
                path[i]=minTown;
                dist[i]=map[minTown][i]+dist[minTown];
            }
    }

}

int main(){
    //城市数目，公路数，起点，终点
    int M,N,S,D;
    cin>>M>>N>>S>>D;

    memset(map,0,sizeof(map));
    int a,b,c;
    for(int i=0;i<N;i++)
        cin>>a>>b>>c;
        map[a][b]=c;
    for(int i=1;i<=M;i++){
        dist[i]=MAXN;
        path[i] = 0;
        collected[i]=0;
    }

    //先定初始点
    collected[1]=1;
    dist[1]=0;

    for(int i=2;i<=M;i++)
        if(map[1][i])
            dist[i]=map[1][i];

    Dijkstra(M);


}
