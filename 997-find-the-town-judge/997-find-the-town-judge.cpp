class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int p=n;
        unordered_map<int,int> indegree;
        unordered_map<int,int> outdegree;
        for(int i=0;i<trust.size();i++)
        {
            int x=trust[i][0];
            int y=trust[i][1];
            indegree[y]++;
            outdegree[x]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(outdegree[i]==0 && indegree[i]==n-1) return i;
        }
        return -1;
    }
};