class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        int j=n-1;
        while(i<j)
        {
            if(arr[i]%2==1 && arr[j]%2==0)
            {
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
            else if(arr[i]%2==1 && arr[j]%2==1)
            {
                j--;
                
            }
            else if(arr[i]%2==0 && arr[j]%2==0)
            {
                i++;
            }
            else
            {
                i++;
                j--;
                
            }
        }
        return arr;
        
        
    }
};