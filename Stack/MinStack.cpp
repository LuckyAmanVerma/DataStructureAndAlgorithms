class MinStack {
public:
    vector<int> stack; //[3,4,2,5]
    vector<int> minStack; 
    int topVal = -1;
    int min=0;
    MinStack() {
        
    }
    
    void push(int val) {
        topVal++;
            stack.push_back(val);
            if(minStack.empty()){
                minStack.push_back(val);
            }
            else if(val < minStack[minStack.size()-1]){
                minStack.push_back(val);
            }
    }
    
    void pop() {
        stack.erase(stack.begin() + topVal);
        topVal--;
    }
    
    int top() {
        if (topVal < 0) {
            throw std::out_of_range("Stack is empty");
        }
        return stack[topVal];
    }
    
    int getMin() {
        if(topVal < 0){
            throw std::out_of_range("Stack is empty");
        }
        int minValue = stack[0];
        for (int i = 1; i <= topVal; i++) {
            if (stack[i] < minValue) {
                minValue = stack[i];
            }
        }
        return minValue;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */