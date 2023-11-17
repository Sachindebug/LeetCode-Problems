class Solution {
public:
    int minPairSum(vector<int>& arr) {
    int n= arr.size();
    
    sort(arr.begin(), arr.end());
     int max=-1;   
        int sum;
    for(int i=0;i<n/2;i++)
    {
        sum=arr[i]+arr[n-i-1];
        if(sum>max)
        {
            max=sum;
        }
        
    }
        return max;
        
    }
};