/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        map<Node*,Node*> copy;
        queue<Node*> q;
        q.push(node);
        Node *rootCopy = new Node(node->val,{});
        copy[node] = rootCopy;
        while(!q.empty())
        {
            Node *top = q.front();
            q.pop();
            for(auto child: top->neighbors)
            {
                if(copy.find(child)==copy.end())
                {
                    copy[child] = new Node(child->val,{});
                    q.push(child);
                }
                copy[top]->neighbors.push_back(copy[child]);
            }
        }
        return rootCopy;
    }
};