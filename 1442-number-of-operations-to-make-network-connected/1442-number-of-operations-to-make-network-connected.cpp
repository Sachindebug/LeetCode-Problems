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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int count = 0;
        DisjointSet ds(n);
        for(auto x:connections){
            int u = x[0];
            int v = x[1];
            if(ds.findPar(u)==ds.findPar(v)){
                count++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        int count1 = 0;
        for(int i = 0;i<n;i++){
            if(ds.findPar(i)==i) count1++;
        }
        if(count<count1-1) return -1;
        return count1-1;
    }
};