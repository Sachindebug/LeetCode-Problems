class CustomStack {
public:
    vector<int> arr;
    int n;
    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
       if(arr.size()<n) arr.push_back(x); 
    }
    
    int pop() {
        if(arr.size()==0) return -1;
        int sz = arr.size();
        int x = arr[sz-1];
        arr.pop_back();
        return x;
    }
    
    void increment(int k, int val) {
        int sz = arr.size();
        for(int i = 0;i<min(k,sz);i++) arr[i] = arr[i]+val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */