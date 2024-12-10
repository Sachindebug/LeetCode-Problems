/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    int checkAllSame(vector<vector<int>>& grid, int topx, int topy, int bottomx, int bottomy){
        bool allOne = true;
        bool allZero = true;
        for(int i = topx;i<=bottomx;i++){
            for(int j = topy;j<=bottomy;j++){
                if(grid[i][j]==1) allZero = false;
                else allOne = false;
            }
        }
        if(allOne) return 1;
        if(allZero) return 0;
        return -1;
    }
    Node* contructTree(vector<vector<int>>& grid, int topx, int topy, int bottomx, int bottomy){
        int allSame = checkAllSame(grid,topx,topy,bottomx,bottomy);
        if(allSame!=-1){
            return new Node(allSame,true);
        }
        Node* root = new Node(0,false);
        int midx = (topx+bottomx)/2;
        int midy = (topy+bottomy)/2;
        root->topLeft = contructTree(grid,topx,topy,midx,midy);
        root->topRight = contructTree(grid,topx,midy+1,midx,bottomy);
        root->bottomLeft = contructTree(grid,midx+1,topy,bottomx,midy);
        root->bottomRight = contructTree(grid,midx+1,midy+1,bottomx,bottomy);
        return root;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return contructTree(grid,0,0,n-1,n-1);
    }
};