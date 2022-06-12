class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int m=potions.size();
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++)
        {
            long long temp=(success+spells[i]-1)/spells[i];
            int pos=lower_bound(potions.begin(),potions.end(),temp)-potions.begin();
            int count=max(0,m-pos);
            ans.push_back(count);
        }
        return ans;
    }
};