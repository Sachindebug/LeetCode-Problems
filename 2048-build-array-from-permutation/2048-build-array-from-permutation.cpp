class Solution {
public:
    vector<int> buildArray(vector<int>& arr) {
        int n=arr.size();
        vector<int> res(n);
        for(int i=0;i<n;i++)
        {
            res[i]=arr[arr[i]];
        }
        return res;
        
    }
};