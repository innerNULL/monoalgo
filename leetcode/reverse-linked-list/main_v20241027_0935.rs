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


impl Solution {
    #[inline(always)]
    pub fn reverse_list(
        head: Option<Box<ListNode>>
    ) -> Option<Box<ListNode>> {
        match head {
            None => {
                return None;
            },
            Some(mut val) => {
                let mut dummy_head: Option<Box<ListNode>> = Some(
                    Box::new(ListNode::new(0))
                );
                let mut curr: Option<Box<ListNode>> = Some(val);
                while !curr.as_ref().is_none() {
                    let curr_next: Option<Box<ListNode>> = {
                        curr.as_mut().unwrap().next.take()
                    };
                    curr.as_mut().unwrap().next = {
                        dummy_head.as_mut().unwrap().next.take()
                    };
                    dummy_head.as_mut().unwrap().next = curr;
                    curr = curr_next;
                }
                return dummy_head.unwrap().next;
            }
        }
    }
}
