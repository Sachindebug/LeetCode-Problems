class MyQueue {
    stack<int> s1,s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty())
        {
            s1.push(x);
        }
        else
        {
            while(!s1.empty())
            {
                int p=s1.top();
                s1.pop();
                s2.push(p);
            }
            s1.push(x);
            while(!s2.empty())
            {
                int p=s2.top();
                s2.pop();
                s1.push(p);
            }
        }
        
    }
    
    int pop() {
        int p=s1.top();
        s1.pop();
        return p;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
       return s1.empty(); 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */