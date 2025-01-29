class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>parent(edges.size()+1,0);
        vector<int>result;
        for(auto e : edges){
            int n1 = e[0], n2 = e[1];
            while(parent[n1]) n1 = parent[n1];
            while(parent[n2]) n2 = parent[n2];
            if(n1==n2) result = e;
            else parent[n1]=n2;
        }
        return result;
    }
};