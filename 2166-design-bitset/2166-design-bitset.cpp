class Bitset {
public:
    vector<int> bitset;
    int cnt;
    bool flipped;
    Bitset(int size) {
        bitset.resize(size);
        cnt=0;
        flipped=false;
    }
    
    void fix(int idx) {
        if((bitset[idx] + flipped)%2==0){
            cnt++;
            bitset[idx]=!bitset[idx];  
        }
        
    }
    
    void unfix(int idx) {
        if((bitset[idx] + flipped)%2!=0){
            cnt--;
            bitset[idx]=!bitset[idx];  
        }
    }
    
    void flip() {
        flipped=!flipped;
        cnt=bitset.size()-cnt;
        
    }
    
    bool all() {
        return cnt==bitset.size();
    }
    
    bool one() {
        return cnt>=1;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        string s;
        for(auto x:bitset)
        {
            s.push_back((x+flipped)%2?'1':'0')  ;
        }
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */