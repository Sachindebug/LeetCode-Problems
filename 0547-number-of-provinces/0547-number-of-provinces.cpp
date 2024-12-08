class DisjointSet{
    vector<int> par;
    vector<int> size;
public:
    DisjointSet(int n){
        size.resize(n+1,0);
        par.resize(n+1);
        for(int i = 0; i<=n;i++){
            par[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int u){
        if(par[u]==u) return u;
        return par[u] = findPar(par[u]);
    }

    void unionBySize(int u, int v){
        int uPar = findPar(u);
        int vPar = findPar(v);
        if(uPar==vPar) return;
        if(size[uPar]<size[vPar]){
            size[vPar]+=size[uPar];
            par[uPar] = vPar; 
        }
        else{
            size[uPar]+=size[vPar];
            par[vPar] = uPar; 
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j]){
                    ds.unionBySize(i,j);
                }
            }
        }
        int count = 0;
        for(int i = 0;i<n;i++){
            if(ds.findPar(i)==i) count++;
        }
        return count;
    }
};