#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define N 1000000
#define M 10
void heapify(vector<ld> &a,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&a[left]>a[largest])
        largest=left;
    if(right<n&&a[right]>a[largest])
        largest=right;
    if(largest!=i){
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}

void heapSort(vector<ld> &a,int n){
    for(int i=n/2-1;i>=0;i--)
        heapify(a,n,i);
    for(int i=n-1;i>0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));
    freopen("test.txt", "r", stdin);
    freopen("resul_heap.txt", "w", stdout);
    vector<vector<ld>> a(M, vector<ld>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }

    }
    for (int i = 0; i < M; i++) {
        auto bd_heap = chrono::high_resolution_clock::now();
        heapSort(a[i], N - 1);
        auto kt_heap = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration_heap = kt_heap - bd_heap;
        cout<<"heapsort: \n";
        cout << "Time for test " << i + 1 << ": " << duration_heap.count() << " ms\n";
    }
    
}