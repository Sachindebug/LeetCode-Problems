class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxChunks = 0;
        int maxIndex = -1;
        for(int i = 0;i<arr.size();i++){
            maxIndex = max(maxIndex,arr[i]);
            if(maxIndex<=i){
                maxChunks+=1;
                maxIndex = -1;
            }
        }
        return maxChunks;
    }
};