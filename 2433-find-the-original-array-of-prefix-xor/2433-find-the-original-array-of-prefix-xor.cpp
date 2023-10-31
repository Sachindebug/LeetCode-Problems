class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res;
        res.push_back(pref[0]);
        int val=pref[0];
        int n=pref.size();
        for(int i=1;i<n;i++)
        {
            res.push_back(val^pref[i]);
            val=val^res[i];
        }
        return res;
    }
};