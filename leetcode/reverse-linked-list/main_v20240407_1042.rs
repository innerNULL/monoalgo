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
        let mut dummy: Option<Box<ListNode>> = None;
        let mut current: Option<Box<ListNode>> = head;
        while !current.as_ref().is_none() {
            let mut node: Box<ListNode> = current.unwrap();
            let mut next: Option<Box<ListNode>> = node.next.take();
            if !dummy.is_none() { node.next = dummy.take(); }
            dummy = Some(node);
            current = next;
        }
        return dummy
    }
}
