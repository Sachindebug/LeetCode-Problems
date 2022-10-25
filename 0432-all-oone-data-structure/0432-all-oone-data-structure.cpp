class AllOne {
    unordered_map<string ,int> mp;
    set<pair<int,string>> st;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        if(mp.find(key)==mp.end())
        {
            mp[key]++;
        }
        else
        {
            st.erase({mp[key],key});
            mp[key]++;
        }
        st.insert({mp[key],key});
    }
    
    void dec(string key) {
        st.erase({mp[key],key});
        mp[key]--;
        st.insert({mp[key],key});
        if(mp[key]==0)
        {
            mp.erase(key);
            st.erase({mp[key],key});
        }
    }
    
    string getMaxKey() {
        if(st.size()==0) return "";
        auto it=st.rbegin();
        return it->second;
    }
    
    string getMinKey() {
       if(st.size()==0) return "";
       auto it=st.begin();
       return it->second; 
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */