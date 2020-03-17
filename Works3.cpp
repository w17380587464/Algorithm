#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int MAXN=1010;
vector<int> ame;
int Val;
int PR(int low,int high){

    //low high 闭区间
    int mid=(low+high)/2;
    int temp=ame[mid];
    if(temp>Val)
        PR(low,mid);
    else if(temp<Val)
        PR(mid,high);
    else
        return mid;

    return -1;
}   


int main(){

    
    for(int i=0;i<MAXN;i++){
        int temp=rand()%1000;
        if(i==666)
            Val=temp;
        ame.push_back(temp);
    
    }
    sort(ame.begin(),ame.end());

    int result=PR(0,MAXN-1); 
    if(result==-1)
        cout<<0<<endl;
    else 
        cout<<(++result)<<endl;

}
