class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& arr) {
        int n=arr.size();
        vector<int> res;
        vector<int> left(n);
        vector<int> right(n);
        int count0=0;
        for(int i=0;i<n;i++)
        {
            left[i]=count0;
            if(arr[i]==0) count0++;
        }
        int count1=0;
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]==1) count1++;
            right[i]=count1;
        }
        int mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,left[i]+right[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(left[i]+right[i]==mx) res.push_back(i);
        }
        if(mx==count0) res.push_back(n);
        else if(mx<count0) 
        {
            return {n};
        }
        return res;
        
    }
};