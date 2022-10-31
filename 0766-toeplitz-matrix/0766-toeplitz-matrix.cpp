class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& v) {
       for(int i = 1; i < v.size(); i++)
            for(int j = 1; j < v[0].size(); j++)
                if(v[i][j] != v[i-1][j-1])
                    return false;
        return true; 
    }
};