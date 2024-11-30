class Solution {
public:
    int totalNQueens(int n) {
        vector<pair<int,int>> pos;
        return recurse(n,0,pos);
    }
    int recurse(int n, int i, vector<pair<int,int>> &pos){
        if(i==n) return 1;
        int res = 0;
        for(int j = 0;j<n;j++){
            if(isPossible(pos,i,j)){
                pos.push_back({i,j});
                res+=recurse(n,i+1,pos);
                pos.pop_back();
            }
        }
        return res;
    }
    bool isPossible(vector<pair<int,int>> &pos, int i, int j){
        for(auto p: pos){
            int x = p.first;
            int y = p.second;
            if (x == i || y == j || abs(x - i) == abs(y - j)) return false;
        }
        return true;
    }
};