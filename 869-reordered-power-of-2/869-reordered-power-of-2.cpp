class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> arr;
        int p=n;
        while(p>0)
        {
            arr.push_back(p%10);
            p/=10;
        }
        vector<int> res=allpermutation(arr);
        
        
        for(int i=0;i<res.size();i++)
        {
            if(floor(log2(res[i]))==ceil(log2(res[i]))) return true;
        }
        return false;
        
    }
    vector<int> allpermutation(vector<int> &arr)
    {
        sort(arr.begin(),arr.end());
        vector<int> res;
        do{
            if(arr[0]!=0)
            {
                vector<int> temp=arr;
                int p=1;
                int a=0;
                for(int i=temp.size()-1;i>=0;i--)
                {
                    a+=(temp[i]*p);
                    p*=10;
                }
                res.push_back(a);
            }
            
        }
        while(next_permutation(arr.begin(),arr.end()));
        
        
        
        
        return res;
    }
};