class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n=arr.size();
        if(n<=2) return n;
        int l=0;
        int r=1;
        int res=INT_MIN;
        unordered_map<int,int> ump;
        ump[arr[l]]++;
        while(r<n)
        {
            ump[arr[r]]++;
            if(ump.size()>2)
            {
                res=max(res,r-l);
                while(ump.size()>2)
                {
                    ump[arr[l]]=ump[arr[l]]-1;
                    if(ump[arr[l]]==0) ump.erase(arr[l]);
                    l++;
                }
            }
            r++;
        }
        res=max(res,r-l);
        return res;
        
        
    }
};