class MapSum {
public:
    unordered_map<string,int> ump;
    unordered_map<string,int> ump1;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        if(ump1.find(key)!=ump1.end())
        {
            string s="";
            int v=ump1[key];
            int temp=val-v;
            for(auto x:key)
            {
                s+=x;
                ump[s]+=temp;
            }
            ump1[key]=val;
            return;
            
        }
        else
        {
            string s="";
            for(auto x:key)
            {
                s+=x;
                ump[s]+=val;
            }
            ump1[key]=val;
            
        }
        
       
        
    }
    
    int sum(string prefix) {
        return ump[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */