// O(n + k) -> n: size of array, k = size of the interval
// of the numbers
// v: 0-indexed array to be sorted
// n: size of v
// l: min range element
// r: max range element
void couting_sort(int v[], int n, int l, int r){
  int k = r-l+1, f[k], ret[n];
  memset(f, 0, sizeof f);
  for(int i = 0; i < n; ++i)
    ++f[v[i]-l];
  for(int i = 1; i < k; ++i)
    f[i] = f[i] + f[i-1];
  for(int i = n-1; i >= 0; --i){
    ret[f[v[i]-l]-1] = v[i];
    --f[v[i]-l];
  }
  for(int i = 0; i < n; ++i)
    v[i] = ret[i];
}