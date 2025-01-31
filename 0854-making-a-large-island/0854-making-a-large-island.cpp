class Disjoint{
    public:
    vector<int> par,size,rank;
    Disjoint(int n)
    {
        par.resize(n+1);
        size.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<n;i++)
        {
            par[i] = i;
            size[i] = 1;
        }
    }
    
    int findUPar(int u)
    {
        if(par[u]==u) return u;
        return par[u] = findUPar(par[u]);
    }
    
    void unionByRank(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu==pv) return;
        if(rank[pu]>rank[pv])
        {
            par[pv] = pu;
        }
        else if(rank[pv]>rank[pu])
        {
            par[pu] = par[pv];
        }
        else
        {
            par[pu] = par[pv];
            rank[pv]++;
        }
    }
    
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            par[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            par[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    
};
class Solution {
private:
    bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int nn = n*n;
        Disjoint ds(nn);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==0) continue;
                else
                {
                    int dr[] = { -1, 0, 1, 0};
                    int dc[] = {0, -1, 0, 1};
                    for (int ind = 0; ind < 4; ind++) {
                        int newr = i + dr[ind];
                        int newc = j + dc[ind];
                        if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                            int nodeNo = i * n + j;
                            int adjNodeNo = newr * n + newc;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
        }
        
        // do brute force and try to convert 0 to 1
        int mx = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==1) continue;
                else
                {
                    int dr[] = { -1, 0, 1, 0};
                    int dc[] = {0, -1, 0, 1};
                    set<int> components;
                    for (int ind = 0; ind < 4; ind++) {
                        int newr = i + dr[ind];
                        int newc = j + dc[ind];
                        if (isValid(newr, newc, n)) {
                            if (grid[newr][newc] == 1) {
                                components.insert(ds.findUPar(newr * n + newc));
                            }
                        }
                    }
                    int sizeTotal = 0;
                    for (auto it : components) {
                        sizeTotal += ds.size[it];
                    }
                    mx = max(mx, sizeTotal + 1);
                }
            }
        }
        
        // handling case of all 1s or maybe it is not possible to connect 2 components by any 0
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }
        
        return mx;
    }
};