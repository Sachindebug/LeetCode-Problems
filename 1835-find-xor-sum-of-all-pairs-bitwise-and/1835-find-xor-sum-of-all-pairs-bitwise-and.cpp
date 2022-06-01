class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int res1=0;
        int res2=0;
        for(auto x:arr1) res1^=x;
        for(auto x:arr2) res2^=x;
        return res1&res2;

    }
};