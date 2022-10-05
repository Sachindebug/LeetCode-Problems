class Solution {
public:
    long long minimumRemoval(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        unordered_map<int,int> ump;
        long long sum=0;
        long long sum1=0;
        long long res=1e14;
        for(auto x:arr) sum+=x;
        for(int i=0;i<n;i++)
        {
            long long temp=0;
            temp+=sum1;
            sum1+=arr[i];
            temp-=((long long)ump[arr[i]]*(long long)arr[i]);
            ump[arr[i]]++;
            sum-=arr[i];
            temp+=(sum-(long long)((long long)arr[i]*(long long)(n-i-1)));
            res=min(res,temp);
        }
        return res;
    }
};