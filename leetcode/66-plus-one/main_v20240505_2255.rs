impl Solution {
    pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
        let mut carry: i32 = 1;
        for i in (0..=(&digits).len() - 1).rev() {
            let tmp: i32 = (&digits)[i] + carry;
            if tmp >= 10 {
                carry = 1;
                (&mut digits)[i] = tmp - 10;
            } else {
                carry = 0;
                (&mut digits)[i] = tmp;
                break;
            }
        }
        if carry == 1 {
            (&mut digits).insert(0, 1);
        }
        return digits;
    }
}
