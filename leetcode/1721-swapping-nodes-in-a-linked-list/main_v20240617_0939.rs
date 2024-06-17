// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }


#[inline(always)]
fn linkedlist_len(head: &Option<Box<ListNode>>) -> usize {
    let mut len: usize = 0;
    let mut reader: &Option<Box<ListNode>> = head;
    while !reader.is_none() {
        len += 1;
        reader = &reader.as_ref().unwrap().next;
    }
    return len;
}


#[inline(always)]
unsafe fn linkedlist_nth(
    head: &mut Option<Box<ListNode>>, 
    n: usize
) -> *mut ListNode {
    let mut reader: *mut ListNode = {
        Box::as_mut(head.as_mut().unwrap())
    };
    for i in 0..n {
        if reader.is_null() {
            return std::ptr::null_mut();
        }
        reader = {
            Box::as_mut((*reader).next.as_mut().unwrap())
        };
    }
    return reader;
}


impl Solution {
    #[inline(always)]
    pub fn swap_nodes(
        mut head: Option<Box<ListNode>>, 
        k: i32
    ) -> Option<Box<ListNode>> {
        let len: usize = linkedlist_len(&head);
        unsafe {
            let left: *mut ListNode = linkedlist_nth(
                &mut head, k as usize - 1
            );
            let right: *mut ListNode = linkedlist_nth(
                &mut head, len - 1 - (k as usize - 1)
            );
            let left_val: i32 = (*left).val; 
            (*left).val = (*right).val;
            (*right).val = left_val;
        }
        return head;
    }
}
