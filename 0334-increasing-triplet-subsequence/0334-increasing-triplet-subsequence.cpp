class Solution {
public:
    bool increasingTriplet(vector<int>& arr) {
        int n=arr.size();
        int low=INT_MAX;
        int mid=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=low) low=arr[i];
            else if(arr[i]<=mid) mid=arr[i];
            else return true;
        }
        
        return false;
        
    }
};