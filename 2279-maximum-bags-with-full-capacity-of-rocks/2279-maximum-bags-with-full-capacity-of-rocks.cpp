class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int as) {
        vector<int> arr;
        int n=cap.size();
        for(int i=0;i<n;i++)
        {
            arr.push_back(cap[i]-rocks[i]);
        }
        sort(arr.begin(),arr.end());
        int count=0;
        for(int i=0;i<n;i++)
        {
            int a=arr[i];
            
            if(a==0) count++;
            else
            {
                if((a)<=as)
                {
                    count++;
                    as-=a;
                }
            }
        }
        return count;
        
    }
};