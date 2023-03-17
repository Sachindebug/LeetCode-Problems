class Node{
    Node *arr[26];
    bool flag=false;
    public:
    bool contains(char ch)
    {
        return (arr[ch-'a']!=NULL);
    }
    Node* get(char ch)
    {
        return arr[ch-'a'];
    }
    void put(char ch,Node* node)
    {
        arr[ch-'a']=node;
    }
    void setEnd()
    {
        flag=true;
    }
    bool isEnd()
    {
        return flag;
    }
};
class Trie {
    private:
    Node *root;
    
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->contains(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
        
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->contains(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
     }
    
    bool startsWith(string prefix) {
        Node *node=root;
        for(int i=0;i<prefix.length();i++)
        {
            if(!node->contains(prefix[i])) return false;
            node = node->get(prefix[i]);
        }
        return root;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */