impl Solution {
    pub fn maximum69_number (num: i32) -> i32 {
        let mut quota: i8 = 1;
        return num
            .clone()
            .to_string()
            .chars()
            .into_iter()
            .map(
                |val: char| { 
                    return match quota > 0 {
                        true => {
                            match val {
                                '6' => {
                                    quota -= 1;
                                    return '9';
                                },
                                _ => {
                                    return val;
                                }
                            }
                        },
                        false => {
                            return val;
                        }
                    }
                }
            )
            .collect::<String>()
            .parse::<i32>().unwrap();
    }
}
