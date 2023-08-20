class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        if (min_vals_.size() == 0) {
            this->min_vals_.push(val);
        } else if (val <= this->min_vals_.top()) {
            this->min_vals_.push(val);
        }
        this->vals_.push(val);
    }
    
    void pop() {
        if (this->vals_.size() == 0) { return; }
        if (this->vals_.top() == this->min_vals_.top()) {
            this->min_vals_.pop();
        }
        this->vals_.pop();
    }
    
    int top() {
        return this->vals_.size() == 0 ? NULL : this->vals_.top();
    }
    
    int getMin() {
        return this->min_vals_.size() == 0 ? NULL : this->min_vals_.top();
    }

private:
    std::stack<int32_t> vals_;
    std::stack<int32_t> min_vals_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
