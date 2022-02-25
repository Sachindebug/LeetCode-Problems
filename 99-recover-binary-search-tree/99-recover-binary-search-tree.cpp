/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        vector<int> duplicate;
        stack<TreeNode*> s;
        TreeNode* curr=root;
        while(1)
        {
            if(curr!=nullptr)
            {
                s.push(curr);
                curr=curr->left;
            }
            else
            {
                if(s.empty()) break;
                curr=s.top();
                s.pop();
                inorder.push_back(curr->val);
                curr=curr->right;
            }
        }
        
        duplicate=inorder;
        sort(duplicate.begin(),duplicate.end());
        int a,b;
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]!=duplicate[i]){
                 a=inorder[i];
                 break;
            }
        }
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]!=duplicate[i] && inorder[i]!=a){
                 b=inorder[i];
                 break;
            }
        }
        cout<<a<<" "<<b<<endl;
        curr=root;
        while(1)
        {
            if(curr!=nullptr)
            {
                s.push(curr);
                curr=curr->left;
            }
            else
            {
                if(s.empty()) break;
                curr=s.top();
                s.pop();
                if(curr->val==a) curr->val=b;
                else if(curr->val==b) curr->val=a;
                curr=curr->right;
            }
        }

    }
};