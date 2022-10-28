class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> ump;
        string t;
        for(int i=0;i<strs.size();i++)
        {
            t=strs[i];
            sort(t.begin(),t.end());
            ump[t].push_back(i);
        }
        vector<vector<string>> res;
        for(auto x:ump)
        {
            vector<string> temp;
            for(auto p:(x.second))
            {
                temp.push_back(strs[p]);
            }
            res.push_back(temp);
        }
        return res;
        
    }
};