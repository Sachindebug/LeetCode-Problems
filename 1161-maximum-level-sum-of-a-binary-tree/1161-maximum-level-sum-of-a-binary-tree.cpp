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
    int maxLevelSum(TreeNode* root) {
        long long int res=INT_MIN;
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans=1;
        int count=1;
        while(!q.empty())
        {
            int n=q.size();
            long long int sum=0;
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                sum+=(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);

            }
            if(res<sum)
            {
                res=sum;
                ans=count;
            }
            
            count++;
        }
        return ans;
    }
};