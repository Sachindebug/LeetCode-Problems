class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int curr = 1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<curr) continue;
            else if(arr[i]==curr)
            {
                curr++;
            }
            else
            {
                arr[i]=curr;
                curr++;
            }
        }
        return arr[n-1];
    }
};