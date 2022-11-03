#include<bits/stdc++.h>

using namespace std;

template<typename T, int base>
void radix_sort(T *arr, int n){ 
    if(n==0) return;
    T *narr = new T[n], *wt = new T[n], *nwt = new T[n]; 
    T *bucket = new T[base], iter=0, mx = 0;

    for(int i=0;i<n;i++) wt[i] = abs(arr[i]), mx = ((mx<wt[i]) ? wt[i] : mx);
    while(mx) ++iter, mx/=base;

    while(iter--){
        for(int i=0;i<n;i++)
            bucket[wt[i]%base]++;
        for(int i=1;i<base;i++) 
            bucket[i]+=bucket[i-1];
        for(int i=n-1;i>=0;i--)
            narr[--bucket[wt[i]%base]] = arr[i], nwt[bucket[wt[i]%base]] = wt[i]/base;
        for(int i=0;i<base;i++) 
            bucket[i] = 0;
        swap(narr,arr), swap(nwt,wt);
    }
    
    int ptr = 0;
    for(int i=n-1;i>=0;i--) if(arr[i]<0) narr[ptr++] = arr[i];
    for(int i=0;i<n;i++) if(arr[i]>0) narr[ptr++] = arr[i];
    for(int i=0;i<n;i++) arr[i] = narr[i];
}

int main(){
  int *v = new int[6];
  v[0] = 2;
  v[1] = 5;
  v[2] = 3;
  v[3] = 3;
  v[4] = 2;
  v[5] = 2;
  radix_sort<int, 10>(v, 6);
  for(int i = 0; i < 6; ++i)
    cout << v[i] << ' ';
  cout << '\n';
}