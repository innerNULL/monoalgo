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
    pub fn reverse_list(
        head: Option<Box<ListNode>>
    ) -> Option<Box<ListNode>> {
        let mut new_head: Option<Box<ListNode>> = None;
        let mut curr_node: Option<Box<ListNode>> = head;
        while let Some(mut node) = curr_node {
            let next: Option<Box<ListNode>> = node.as_mut().next.take();
            match new_head {
                None => {
                    new_head = Some(node);
                },
                _ => {
                    node.next = new_head;
                    new_head = Some(node);
                }
            }
            curr_node = next;
        }
        return new_head;
    }
}
