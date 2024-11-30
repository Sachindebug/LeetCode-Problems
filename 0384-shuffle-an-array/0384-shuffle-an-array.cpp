class Solution {
public:
    vector<int> original, shuffled;
    Solution(vector<int>& nums) {
        original = nums;
        shuffled = nums;
    }
    
    vector<int> reset() {
        shuffled = original;
        return shuffled;
    }
    
    vector<int> shuffle() {
        for(int i = 0;i<shuffled.size();i++){
            int n = shuffled.size();
            int randomIndex = i + rand()%(n-i);
            int temp = shuffled[i];
            shuffled[i] = shuffled[randomIndex];
            shuffled[randomIndex] = temp;
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */