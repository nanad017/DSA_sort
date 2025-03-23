#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define N 1000000
#define M 10
void merge(vector<ld> &a,int l,int r){
    int mid=l+(r-l)/2;
    int n1=mid-l+1;
    int n2=r-mid;
    ld *b=new ld[n1];
    ld *c=new ld[n2];
    for(int i=0;i<n1;i++){
        b[i]=a[l+i];
    }
    for(int i=0;i<n2;i++){
        c[i]=a[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=l;
    while(i<n1&&j<n2){
        if(b[i]<=c[j])a[k++]=b[i++];
        else a[k++]=c[j++];
    }
    while(i<n1)a[k++]=b[i++];
    while(j<n2)a[k++]=c[j++];
    delete[] b;
    delete[] c;
}

void mergeSort(vector<ld> &a,int l,int r){
    if(l<r){
        int mid=l+(r-l)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,r);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));
    freopen("test.txt", "r", stdin);
    freopen("result_merge.txt", "w", stdout);
    vector<vector<ld>> a(M, vector<ld>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        auto bd_merge = chrono::high_resolution_clock::now();
        mergeSort(a[i], 0, N - 1);
        auto kt_merge = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration_merge = kt_merge - bd_merge;
        cout<<"mergesort: \n";
        cout << "Time for test " << i + 1 << ": " << duration_merge.count() << " ms\n";
       
    }
    
}