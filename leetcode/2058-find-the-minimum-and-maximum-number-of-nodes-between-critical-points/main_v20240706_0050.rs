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
    pub fn nodes_between_critical_points(
        mut head: Option<Box<ListNode>>
    ) -> Vec<i32> {
        let mut out: Vec<i32> = Vec::new();
        let mut nodes: Vec<Option<Box<ListNode>>> = Vec::new();
        while !head.is_none() {
            let next: Option<Box<ListNode>> = {
                head.as_mut().unwrap().next.take()
            };
            nodes.push(head.take());
            head = next;
        }
        let mut critial_points: Vec<i32> = (0..nodes.len())
            .map(
                |i: usize| {
                    if i == 0 || i == nodes.len() - 1 {
                        return -1;
                    } else {
                        let val: i32 = nodes[i]
                            .as_ref()
                            .unwrap()
                            .val;
                        let left: i32 = nodes[i - 1]
                            .as_ref()
                            .unwrap()
                            .val;
                        let right: i32 = nodes[i + 1]
                            .as_ref()
                            .unwrap()
                            .val;
                        return {
                            if (
                               (val > left && val > right)
                               || (val < left && val < right)
                            ) {
                                i as i32
                            } else {
                                -1
                            }
                        };
                    }
                }
            )
            .filter(|x: &i32| { return x.clone() >= 0; })
            .collect::<Vec<i32>>();
        if critial_points.len() < 2 {
            return vec![-1, -1];
        }
        let min: i32 = (1..critial_points.len())
            .map(
                |i: usize| {
                    return {
                        critial_points[i] - critial_points[i - 1]
                    };
                }
            )
            .min()
            .unwrap();
        let max: i32 = {
            critial_points[critial_points.len() - 1] - critial_points[0]
        };
        return vec![min, max];
    }
}
