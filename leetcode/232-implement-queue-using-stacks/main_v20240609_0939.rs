struct MyQueue {
    stack_push: Vec<i32>,
    stack_pop: Vec<i32>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyQueue {
    #[inline(always)]
    fn new() -> Self {
        return Self {
            stack_push: Vec::new(),
            stack_pop: Vec::new()
        };
    }

    #[inline(always)]
    fn push2pop(&mut self) {
        while self.stack_push.len() > 0 {
            self.stack_pop.push(
                self.stack_push.pop().unwrap()
            );
        }
    }

    #[inline(always)]
    fn pop2push(&mut self) {
        while self.stack_pop.len() > 0 {
            self.stack_push.push(
                self.stack_pop.pop().unwrap()
            );
        }
    }
    
    #[inline(always)]
    fn push(&mut self, x: i32) {
        self.stack_push.push(x);
        return;
    }
    
    #[inline(always)]
    fn pop(&mut self) -> i32 {
        self.push2pop();
        let pop_val: i32 = self.stack_pop.pop().unwrap();
        self.pop2push();
        return pop_val;
    }
    
    #[inline(always)]
    fn peek(&mut self) -> i32 {
        return self.stack_push[0];
    }
    
    #[inline(always)]
    fn empty(&self) -> bool {
        return {
            self.stack_push.len() == 0 
            && self.stack_pop.len() == 0
        };
    }
}


/**
 * Your MyQueue object will be instantiated and called as such:
 * let obj = MyQueue::new();
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.peek();
 * let ret_4: bool = obj.empty();
 */
