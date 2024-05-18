// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }


use std::collections::HashMap;
use std::rc::Rc;
use std::cell::RefCell;
use std::cell::RefMut;


unsafe fn opt_rc_refcell_to_mut_raw_ptr<T>(
    mut smart_ptr: &Option<Rc<RefCell<T>>>
) -> *mut T {
    match smart_ptr {
        Some(x) => {
            let mut ref_ptr: RefMut<T> = x.borrow_mut();
            return &mut *ref_ptr as *mut T;
        },
        None => {
            return std::ptr::null_mut();
        }
    }
}


fn tree_to_levals(
    dest: &mut HashMap<usize, Vec<*mut TreeNode>>, 
    node: &Option<Rc<RefCell<TreeNode>>>,
    level: usize
) {
    if node.is_none() {
        return;
    }
    let raw_ptr: *mut TreeNode = unsafe { 
        opt_rc_refcell_to_mut_raw_ptr(&node)
    };
    if !dest.contains_key(&level) {
        dest.insert(level, vec![]);
    }
    if let Some(mut val) = dest.get_mut(&level) {
        val.push(raw_ptr);
    }
    let left: &Option<Rc<RefCell<TreeNode>>> = unsafe { 
        &((*raw_ptr).left) 
    };
    let right: &Option<Rc<RefCell<TreeNode>>> = unsafe { 
        &((*raw_ptr).right) 
    };
    tree_to_levals(dest, left, level + 1);
    tree_to_levals(dest, right, level + 1);
    return;
}


impl Solution {
    pub fn reverse_odd_levels(
        root: Option<Rc<RefCell<TreeNode>>>
    ) -> Option<Rc<RefCell<TreeNode>>> {
        let mut levels: HashMap<usize, Vec<*mut TreeNode>> = HashMap::new();
        tree_to_levals(&mut levels, &root, 1);
        //println!("dbg: levels.len={}", (&levels).len());
        let mut level: usize = 1;
        while (&levels).contains_key(&level) {
            if level % 2 != 0 {
                level += 1;
                continue;
            }
            let nodes: &mut Vec<*mut TreeNode> = levels.get_mut(&level).unwrap();
            let mut left: usize = 0;
            let mut right: usize = nodes.len() - 1;
            while left < right {
                unsafe {
                    let left_val: i32 = (*nodes[left]).val;
                    (*nodes[left]).val = (*nodes[right]).val;
                    (*nodes[right]).val = left_val;
                }  
                left += 1;
                right -= 1;
            }
            level += 1;
        }
        return root;
    }
}
