class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients,
                                     vector<string>& supplies) {
        set<string> st(recipes.begin(),recipes.end());
        vector<string> res;
        map<string,int> indegree;
        map<string,vector<string>> adj;
        for(int i = 0;i<recipes.size();i++){
            string item = recipes[i];
            for(auto s: ingredients[i]) adj[s].push_back(item);
            indegree[item] = ingredients[i].size();
        }
        queue<string> q;
        for(auto s: supplies) q.push(s);
        while(!q.empty()){
            string t = q.front();
            q.pop();
            for(auto s: adj[t]){
                indegree[s]--;
                if(indegree[s]==0){
                    q.push(s);
                    if(st.find(s)!=st.end()) res.push_back(s);
                }
            }
        }
        return res;
    }
};