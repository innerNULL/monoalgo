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
    pub fn reorder_list(mut head: &mut Option<Box<ListNode>>) {
        if head.is_none() || head.as_ref().unwrap().next.is_none() {
            return;
        }
        let mut nodes: Vec<Option<Box<ListNode>>> = Vec::new();
        let mut reader: Option<Box<ListNode>> = head.take();
        while !reader.is_none() {
            let mut next: Option<Box<ListNode>> = reader
                .as_mut()
                .unwrap()
                .next
                .take();
            let mut node: Box<ListNode> = reader.unwrap();
            nodes.push(Some(node));
            reader = next;
        }
        //println!("(dbg) nodes.len()={}", nodes.len());
        let mut dummy_head: Option<Box<ListNode>> = {
            Some(Box::new(ListNode::new(0)))
        };
        let mut dummy_tail: &mut Option<Box<ListNode>> = &mut dummy_head;
        let mut left_idx: usize = 0;
        let mut right_idx: usize = nodes.len() - 1;
        while left_idx <= right_idx {
            let mut left: Box<ListNode> = nodes
                .get_mut(left_idx)
                .unwrap()
                .take()
                .unwrap();
            left.next = None; 
            dummy_tail.as_mut().unwrap().next = Some(left);
            dummy_tail = &mut dummy_tail.as_mut().unwrap().next;
            if left_idx != right_idx {
                let mut right: Box<ListNode> = nodes
                    .get_mut(right_idx)
                    .unwrap()
                    .take()
                    .unwrap();
                right.next = None;
                dummy_tail.as_mut().unwrap().next = Some(right);
                dummy_tail = &mut dummy_tail.as_mut().unwrap().next;
            }
            left_idx += 1;
            right_idx -= 1;
        }
        let mut dummy_next: Option<Box<ListNode>> = dummy_head
            .as_mut()
            .unwrap()
            .next
            .take();
        dummy_head.as_mut().unwrap().next = None;
        *head = dummy_next;
        return;
    }
}
