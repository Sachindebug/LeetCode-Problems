class NumberContainers {
private:
    map<int,int> ump;
    map<int,set<int>> st;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(ump.find(index)!=ump.end()){
            int existing = ump[index];
            st[existing].erase(index);
            if(st[existing].size()==0) st.erase(existing);
        }
        ump[index] = number;
        st[number].insert(index);
    }
    
    int find(int number) {
        if(st.find(number)==st.end()) return -1;
        return *st[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */