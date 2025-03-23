#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define N 1000000
#define M 10

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("test.txt","r",stdin);
    freopen("Sort_result.txt","w",stdout);
    vector<vector<ld>> a(M,vector<ld>(N));
    for(int i=0;i<M;++i){
        for(int j=0;j<N;++j){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<M;i++){
        auto bd=chrono::high_resolution_clock::now();
        sort(a[i].begin(),a[i].end());
        auto kt=chrono::high_resolution_clock::now();
        chrono::duration<double,milli> duration=kt-bd;
        cout<<"Time for test "<<i+1<<": "<<duration.count()<<" ms\n";
    }
    return 0;
}