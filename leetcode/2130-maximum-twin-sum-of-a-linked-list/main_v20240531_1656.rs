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
    pub fn pair_sum(head: Option<Box<ListNode>>) -> i32 {
        let mut reader: &Option<Box<ListNode>> = &head;
        let mut nodes: Vec<&Option<Box<ListNode>>> = Vec::new();
        while !reader.is_none() {
            let next: &Option<Box<ListNode>> = &reader.as_ref().unwrap().next;
            nodes.push(reader);
            reader = next;
        }
        let len: usize = nodes.len();
        let mut left_idx: usize = len / 2 - 1;
        let mut right_idx: usize = len / 2;
        let mut max_sum: i32 = i32::MIN;
        while left_idx as i32 >= 0 && right_idx < len {
            let left_val: i32 = (&nodes)[left_idx].as_ref().unwrap().val;
            let right_val: i32 = (&nodes)[right_idx].as_ref().unwrap().val;
            max_sum = std::cmp::max(max_sum, left_val + right_val);
            left_idx -= 1;
            right_idx += 1;
        }
        return max_sum;
    }
}
