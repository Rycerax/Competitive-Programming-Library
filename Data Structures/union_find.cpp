struct UnionFind{
    vector<int> p, rank, setSize;
    int sets;

    UnionFind(int n){
        p.assign(n, 0); for(int i = 0; i < n; ++i) p[i] = i;
        rank.assign(n, 0);              // Optional Speedup
        setSize.assign(n, 1);           // Optional feature
        sets = n;                       // Optional feature
    }

    int find(int i){return (p[i] == i) ? i : (p[i] = find(p[i]));}

    void join(int i, int j){
        i = p[i]; j = p[j];
        if(i == j) return;
        if(rank[j] > rank[i]) swap(i, j);
        p[j] = i;
        rank[i] += (rank[i] == rank[j]);
        setSize[i] += setSize[j];
        --sets;
    }
};