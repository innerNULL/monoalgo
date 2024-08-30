use std::collections::HashMap;


/**
 Most existing are too obscure fo this simple question.
 Here's a much easy-to-understand solution.

 The basic idea is:
 1. The ideal case is in original `nums`, the digits are 
    in the decend order, in this case we do not need swap.
 2. For non-ideal case, we should find the first digit to
    swap, then swap it with maximum digit ranked at later.
 3. To find the first digit to swap, we just compare each 
    digit in origin order with each difit in decending 
    sorted order, the first non-equal one is the first 
    digit to swap.
 */
impl Solution {
    pub fn maximum_swap(num: i32) -> i32 {
        let mut digits: Vec<i8> = num
            .to_string()
            .chars()
            .into_iter()
            .map(|x: char| { 
                return x
                    .clone()
                    .to_string()
                    .parse::<i8>()
                    .unwrap()
            })
            .collect::<Vec<i8>>();
        let sorted_digits: Vec<i8> = {
            let mut out: Vec<i8> = digits.clone();
            out.sort_by(|a: &i8, b: &i8| { b.cmp(a) });
            out
        };
        let mut digit2idx: HashMap<i8, usize> = digits
            .clone()
            .into_iter()
            .enumerate()
            .map(
                |x: (usize, i8)| { (x.1.clone(), x.0.clone()) }
            )
            .collect::<HashMap<i8, usize>>();
        for i in 0..digits.len() {
            if digits[i] != sorted_digits[i] {
                let max_idx: usize = digit2idx
                    .get(&sorted_digits[i])
                    .unwrap()
                    .clone();
                let tmp: i8 = digits[i];
                digits[i] = digits[max_idx];
                digits[max_idx] = tmp;
                break;
            }
        }
        return digits
            .into_iter()
            .map(|x: i8| { x.to_string() })
            .collect::<String>()
            .parse::<i32>()
            .unwrap();
    }
}
