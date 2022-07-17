class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int q=queries.size();
        int n=nums.size();
        for(int i=0;i<q;i++)
        {
            int k=queries[i][0];
            int t=queries[i][1];
            vector<pair<string,int>> temp;
            for(int j=0;j<n;j++)
            {
                int p=nums[j].length();
                string s=nums[j].substr((p-t),t);
                temp.push_back({s,j});
            }
            sort(temp.begin(),temp.end());
            int b=temp[k-1].second;
            res.push_back(b);
        }
        return res;
    }
};