class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]==i+1) continue;
            else
            {
                int count=0;
                while(arr[arr[i]-1]!=arr[i])
                {
                    swap(arr[i],arr[arr[i]-1]);
                    count++;
                    if(count>n) break;
                }
            }
        }
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=i+1)
            {
                res.push_back(arr[i]);
                res.push_back(i+1);
                break;

            }
        }
        return res;
    }
};