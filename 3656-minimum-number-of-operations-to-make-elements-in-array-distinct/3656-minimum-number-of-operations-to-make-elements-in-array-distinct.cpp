class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> st;
        int duplicateIndex = -1;
        for(int i = nums.size()-1;i>=0;i--){
            if(st.find(nums[i])!=st.end()){
                duplicateIndex = i;
                break;
            }
            st.insert(nums[i]);
        }
        int noOfElements = duplicateIndex +1 ;
        return ceil(double(noOfElements)/3.0);
    }
};