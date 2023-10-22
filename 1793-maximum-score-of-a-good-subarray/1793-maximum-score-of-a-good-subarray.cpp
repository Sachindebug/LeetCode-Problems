class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        vector<int> l(n,-1),r(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(st.size() && nums[i]<nums[st.top()]){
                int tp=st.top(); 
                st.pop();
                
                r[tp]=i;
            }
            if(st.size()) l[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            if(l[i]<k && r[i]>k)
                ans=max(ans,nums[i]*(r[i]-l[i]-1));
        }
        return ans;
    }
};