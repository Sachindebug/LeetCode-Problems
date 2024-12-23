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
    int minimumOperations(TreeNode* root) {
        int count=0;
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int res=0;
            vector<int> a;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                a.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            count+=cycleSort(a);
        }
        return count;
    }
    int cycleSort(vector<int>& arr){
        vector<int> copy = arr;
        sort(copy.begin(), copy.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) mp[copy[i]] = i; 
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            while (mp[arr[i]] != i) {
                swap(arr[i], arr[mp[arr[i]]]);
                count++;
            }
        }
        return count;
    }

};