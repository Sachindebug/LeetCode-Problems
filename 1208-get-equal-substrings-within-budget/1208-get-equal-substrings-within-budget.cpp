class Solution {
public:
    int equalSubstring(string s, string t, int k) {
        vector<int> arr;
        for(int i=0;i<s.length();i++)
        {
            arr.push_back(abs(s[i]-t[i]));
        }
        int res = 0;
        int sum = 0;
        int i = 0,j = 0;
        while(j<arr.size())
        {
            sum+=arr[j];
            while(sum>k)
            {
                sum-=arr[i];
                i++;
            }
            res = max(res,j-i+1);
            j++;
        }
        return res;
    }
};