class MyHashSet {
public:
    int n;
    vector<list<int>> mp;
    
    MyHashSet() {
        n=10007;
        mp=vector<list<int>>(n);
        
    }
    
    void add(int key) {
        int h = key%n;
        if(!contains(key))
        mp[h].push_back(key);
    }
    
    void remove(int key) {
        int h = key%n;
        auto it  = find(mp[h].begin(),mp[h].end(),key);
        if(it!=mp[h].end())
        {
            mp[h].erase(it);
        }
        
    }
    
    bool contains(int key) {
        int h = key%n;
        if(find(mp[h].begin(),mp[h].end(),key)!=mp[h].end())
        {
           return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */