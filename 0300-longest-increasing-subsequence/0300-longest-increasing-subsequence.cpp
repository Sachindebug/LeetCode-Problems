class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> next(n+1,0);
    
        vector<int> cur(n+1,0);

        for(int ind = n-1; ind>=0; ind --){
            for (int prev_index = ind-1; prev_index >=-1; prev_index --){

                int notTake = 0 + next[prev_index +1];

                int take = 0;

                if(prev_index == -1 || arr[ind] > arr[prev_index]){

                    take = 1 + next[ind+1];
                }

                cur[prev_index+1] = max(notTake,take);
            }
            next = cur;
        }

        return cur[0];
    }
    
};