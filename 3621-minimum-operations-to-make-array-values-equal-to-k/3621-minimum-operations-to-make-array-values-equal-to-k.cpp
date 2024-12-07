class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mn = *min_element(nums.begin(),nums.end());
        if(mn<k) return -1;
        set<int> st(nums.begin(),nums.end());
        if(st.find(k)!=st.end()) return st.size()-1;
        return st.size();
    }
};