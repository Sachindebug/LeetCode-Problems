class RandomizedSet {
private:
    vector<int> arr;
    unordered_map<int,int> ump;
   
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(ump.find(val)!=ump.end())
        {
          return false;
        }
        arr.emplace_back(val);
        ump[val]=arr.size()-1;
        return true;
        
    }
    
    bool remove(int val) {
        if(ump.find(val)==ump.end()) return false;
        int l=arr.back();
        ump[l]=ump[val];
        arr[ump[val]]=l;
        arr.pop_back();
        ump.erase(val);
        return true;
    }
    
    int getRandom() {
        int n=arr.size();
        int x=rand()%n;
        return arr[x];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */