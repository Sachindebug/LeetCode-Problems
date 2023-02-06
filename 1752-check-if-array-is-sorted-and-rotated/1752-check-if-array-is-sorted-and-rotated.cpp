class Solution {
public:
    bool check(vector<int>& arr) {
        int count=0;
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            if(arr[i]<arr[i-1]) count++;
        }
        if(count>1) return false;
        if(count==0) return true;
        return (count==1 && arr[0]>=arr[n-1]);
    }
};