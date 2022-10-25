class LFUCache {
    int cap;
    int minfreq;
    unordered_map<int,pair<int,int>> m;
    unordered_map<int,list<int>> fm;
    unordered_map<int,list<int>::iterator> mitr;
public:
    LFUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        int freq=m[key].second;
        fm[freq].erase(mitr[key]);
        freq++;
        fm[freq].push_front(key);
        mitr[key]=fm[freq].begin();
        m[key].second=freq;
        if(fm[minfreq].empty()) minfreq=freq;
        return m[key].first;
    }
    
    void put(int key, int value) {
        if(cap<=0) return;
        if(get(key)!=-1) 
        {
            m[key].first=value;
            return;
        }
        if(m.size()==cap)
        {
            int del=fm[minfreq].back();
            fm[minfreq].pop_back();
            m.erase(del);
            mitr.erase(del);
        }
        minfreq=1;
        m[key]={value,minfreq};
        fm[minfreq].push_front(key);
        mitr[key]=fm[minfreq].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */