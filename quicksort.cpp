#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define N 1000000
#define M 10

int partition(vector<ld> &a,int l,int r){
    int rand_id=l+rand()%(r-l+1);
    swap(a[rand_id],a[r]);
    ld pivot=a[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<=pivot){
            swap(a[++i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void quickSort(vector<ld> &a,int left,int right){
    stack<pair<int,int>> stk;
    stk.push({left,right});
    while(!stk.empty()){
        auto [l,r]=stk.top();
        stk.pop();
        while(l<r){
            int pi=partition(a,l,r);
            if(pi-l<r-pi){
                stk.push({pi+1,r});
                r=pi-1;
            }else{
                stk.push({l,pi-1});
                l=pi+1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));
    freopen("test.txt","r",stdin);
    freopen("QuickSort_result.txt","w",stdout);
    vector<vector<ld>> a(M,vector<ld>(N));
    for(int i=0;i<M;++i){
        for(int j=0;j<N;++j){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<M;i++){
        auto bd=chrono::high_resolution_clock::now();
        quickSort(a[i],0,N-1);
        auto kt=chrono::high_resolution_clock::now();
        chrono::duration<double,milli> duration=kt-bd;
        cout<<"Time for test "<<i+1<<": "<<duration.count()<<" ms\n";
    }
    return 0;
}