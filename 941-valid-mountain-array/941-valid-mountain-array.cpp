class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool dec=false;
        int n=arr.size();
        if(n<=2) return false;
        if(arr[1]<=arr[0]) return false;
        for(int i=2;i<n;i++)
        {
            if(!dec && arr[i]>arr[i-1])
            {
                continue;
            }
            else if(arr[i]<arr[i-1])
            {
                dec=true;
            }
            else if(dec && arr[i]<arr[i-1]) continue;
            else return false;
        }
        if(!dec) return false;
        return true;
    }
};