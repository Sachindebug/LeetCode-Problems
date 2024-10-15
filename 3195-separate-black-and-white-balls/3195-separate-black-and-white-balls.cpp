class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int n = s.length();
        vector<int> temp;
        for(int i=n-1;i>=0;i--) if(s[i]=='1') temp.push_back(i);
        int j=n-1;
        for(auto x:temp)
        {
            ans+=(j-x);
            j--;
        }
        return ans;
    }
};