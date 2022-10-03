class Solution {
public:
    int minCost(string colors, vector<int>& arr) {
        int sum=0;
        int i=0;
        int j=0;
        int n=arr.size();
        while(i<n && j<n)
        {
            int ct=0,cm=0;
            while(j<n && colors[i]==colors[j])
            {
                ct+=arr[j];
                cm=max(cm,arr[j]);
                j++;
            }
            sum+=(ct-cm);
            i=j;
        }
        return sum;
    }
};