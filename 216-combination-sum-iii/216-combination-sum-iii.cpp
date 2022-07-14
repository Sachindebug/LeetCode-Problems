class Solution {
public:
    vector<vector<int>> result;
    void comsum(vector<int> &curr, int k, int n, int sum, int size, int index){
        if(size==k && sum == n){
            result.push_back(curr);
            return;
        }
        else if(size>k || sum>n)
            return;
        
        for(int i = index; i <= 9; i++){
            sum += i;
            curr.push_back(i);
            comsum(curr, k, n, sum, size+1, i+1);
            sum -= i;
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        comsum(curr, k, n, 0, 0, 1);
        return result;
    }
};