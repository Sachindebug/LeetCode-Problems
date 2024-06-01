class Solution {
public:
    int ans=0;
    void Merge(int l, int m, int r, vector<int>& nums){
        int i,j=m+1;
        for(i=l; i<=m; i++){
            while(j<=r && nums[i]/2.0 > nums[j])
                j++;
            ans+=j-m-1;
        }

        vector<int>temp;
        i=l, j=m+1;
        while(i<=m && j<=r){
            if(nums[i]<=nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }
        while(i<=m)
            temp.push_back(nums[i++]);
        while(j<=r)
            temp.push_back(nums[j++]);
        for(i=l; i<=r; i++)
            nums[i]=temp[i-l];
    }
    void MS(int l, int r, vector<int>& nums){
        if(l>=r) return;
        int m= (l+r)>>1;
        MS(l,m,nums);
        MS(m+1,r,nums);
        Merge(l,m,r,nums);
    }
    int reversePairs(vector<int>& nums) {
        int n= nums.size();
        MS(0,n-1,nums);
        return ans;
    }
};