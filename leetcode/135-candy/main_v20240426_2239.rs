use std::cmp;


fn vec_print(vec: &Vec<i32>) {
    for x in vec.iter() {
        print!("{} ", x);
    }
    print!("\n");
}


impl Solution {
    pub fn candy(ratings: Vec<i32>) -> i32 {
        if ratings.len() == 1 { return 1; }

        let mut out: Vec<i32> = vec![1; ratings.len()];
        for i in 1..ratings.len() {
            if ratings[i] > ratings[i - 1] {
                out[i] = out[i - 1] + 1;
            }
        }
        //vec_print(&out);
        for i in (0..=ratings.len() - 2).rev() {
            if ratings[i] > ratings[i + 1] && out[i] <= out[i + 1] {
                out[i] = out[i + 1] + 1;
            }
        }
        //vec_print(&out);
        return out.iter().sum();   
    }
}
