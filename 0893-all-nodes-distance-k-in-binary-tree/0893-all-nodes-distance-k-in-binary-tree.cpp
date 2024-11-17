/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> parent_track;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tp = q.front();
            q.pop();
            if(tp->left){
                parent_track[tp->left] = tp;
                q.push(tp->left);
            }
            if(tp->right){
                parent_track[tp->right] = tp;
                q.push(tp->right);
            }
        }
        unordered_map<TreeNode*,bool>visited;
        q.push(target);
        visited[target]=true;
        int curr_level=0;
        while(!q.empty()){
            int size=q.size();
            if(curr_level++==k)break;
            for(int i=0;i<size;i++){
                TreeNode* current=q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left]=true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right]=true;
                }
                if(parent_track[current] && !visited[parent_track[current]]){
                    q.push(parent_track[current]);
                    visited[parent_track[current]]=true;
                }
            }
        }
        vector<int>result;
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;
    }
};