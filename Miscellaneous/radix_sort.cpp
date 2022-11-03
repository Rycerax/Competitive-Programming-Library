// O(nLogb(n)) -> n: size of array, b = base
// arr: 0-indexed array to be sorted
// n: size of arr
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
