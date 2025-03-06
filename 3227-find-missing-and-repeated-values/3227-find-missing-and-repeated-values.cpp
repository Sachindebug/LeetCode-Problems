class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> arr;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                arr.push_back(grid[i][j]);
            }
        }
        for(int i=0;i<arr.size();){
            if(arr[i]!=arr[arr[i]-1])
            swap(arr[i],arr[arr[i]-1]);
            else
            ++i;
        }
        vector<int> res;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=i+1){
                res.push_back(arr[i]);
                res.push_back(i+1);
                break;
            }
        }
        return res;
    }
};