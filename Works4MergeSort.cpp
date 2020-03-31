#include<iostream>
#define MAXN 10
using namespace std;
int a[MAXN];
int save[MAXN];

void Merge(int lines[],int low,int mid,int high){
    int a=low;
    int i=0;
    int b=mid+1;

    while(a<=mid && b<=high){
        save[i++]=lines[a]<lines[b]?lines[a++]:lines[b++];
    }
    while(a<=mid)
        save[i++]=lines[a++];
    while(b<=high)
        save[i++]=lines[b++];

    //归并排序后，每次结束生成的新序列要还给原数组。
    int cnt=0;
    for(int i=low;i<=high;i++)
        lines[i]=save[cnt++];

}

void MergeSort(int lines[],int low,int high){

    if(low==high)
        return;

    int mid = (low+high)/2;
    MergeSort(lines,low,mid);
    MergeSort(lines,mid+1,high);
    Merge(lines,low,mid,high);

}

int main(){
    
    for(int i=0;i<MAXN;i++)
        a[i]=rand()%1000;
    
    MergeSort(a,0,MAXN-1);

    for(int i=0;i<MAXN;i++)
        cout<<save[i]<<"\t";
    
}
