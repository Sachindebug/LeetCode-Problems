class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.end(),nums.begin(),nums.end());
        stack<int> st;
        vector<int> res(2*n);
        for(int i = nums.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(st.empty()) res[i] = -1;
            else res[i] = st.top();
            st.push(nums[i]);
        }
        return {res.begin(),res.begin()+n};
    }
};