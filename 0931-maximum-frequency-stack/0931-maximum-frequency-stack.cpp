class FreqStack {
public:
    priority_queue<vector<int>> pq;
    map<int,int> mp;
    int count;
    FreqStack() {
        count = 0;
    }
    
    void push(int val) {
        count++;
        mp[val]++;
        int frq = mp[val];
        pq.push({frq,count,val});
    }
    
    int pop() {
        auto tp = pq.top();
        pq.pop();
        mp[tp[2]]--;
        return tp[2];
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */