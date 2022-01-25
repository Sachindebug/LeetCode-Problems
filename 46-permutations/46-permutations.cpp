class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res=recurse(nums,nums.size()-1);
        return res;
    }
    vector<vector<int>> recurse(vector<int> arr,int idx)
    {
        int n=arr.size();
        vector<vector<int>> res;
        if(idx==0)
        {
            res.push_back({arr[0]});
            return res;
        }
        vector<vector<int>> res1=recurse(arr,idx-1);
        int size=res1.size();
        int x=arr[idx];
        for(int i=0;i<size;i++)
        {
            vector<int> temp=res1[i];
            vector<int> p=temp;
            for(int i=0;i<=p.size();i++)
            {
                p.insert(p.begin()+i,x);
                res.push_back(p);
                p=temp;
                
            }
            
        }
        return res;
    }
    
};