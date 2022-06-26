class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int sum=0;
        int n=arr.size();
        for(int i=0;i<k;i++)
        {
            sum+=arr[i];
        }
        int res=sum;
      
        int i=k-1;
        int j=n-1;
        while(i>=0)
        {
            sum-=arr[i];
            sum+=arr[j];
            res=max(sum,res);
            i--;
            j--;
        }
        return res;
    }
};