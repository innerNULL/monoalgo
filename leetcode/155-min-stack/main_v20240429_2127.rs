struct MinStack {
    stack: Vec<i32>,
    min_stack: Vec<i32>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MinStack {

    fn new() -> Self {
        MinStack {
            stack: Vec::new(),
            min_stack: Vec::new()
        }
    }
    
    fn push(&mut self, val: i32) {
        unsafe {
            let self_ptr: *mut MinStack = self as *mut MinStack;
            (*self_ptr).stack.push(val);
            if (*self_ptr).min_stack.len() == 0 {
                (*self_ptr).min_stack.push(val);
            } else if (*self_ptr).min_stack.last().unwrap() >= &val {
                (*self_ptr).min_stack.push(val);
            }
        }
    }
    
    fn pop(&mut self) {
        unsafe {
            let self_ptr: *mut MinStack = self as *mut MinStack;
            if (*self_ptr).stack.len() == 0 { return; }
            let last_val: i32 = *((*self_ptr).stack.last().unwrap());
            (*self_ptr).stack.pop();
            if &last_val == (*self_ptr).min_stack.last().unwrap() {
                (*self_ptr).min_stack.pop();
            }
        }
    }
    
    fn top(&self) -> i32 {
        return *(self.stack.last().unwrap());   
    }
    
    fn get_min(&self) -> i32 {
        return *(self.min_stack.last().unwrap());
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * let obj = MinStack::new();
 * obj.push(val);
 * obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: i32 = obj.get_min();
 */
