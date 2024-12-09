class Solution {
public:
    int helper(vector<int> &nums,int k,vector<vector<int>> &q){
        int n=nums.size();
        int m=q.size();
        vector<int> diff(n,0);
        for(int i=0;i<k;i++){
            diff[q[i][0]]-=q[i][2];
            if((q[i][1]+1)<n){
                diff[q[i][1]+1]+=q[i][2];
            }
        }
        int sub=0;
        for(int i=0;i<n;i++){
            sub+=diff[i];
            if((nums[i]+sub)>0){
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m=queries.size();
        int i=0;
        int j=m;
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(helper(nums,mid,queries)){
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return ans;
    }
};