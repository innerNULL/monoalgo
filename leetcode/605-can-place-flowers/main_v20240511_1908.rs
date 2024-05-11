fn vec_print(vec: &Vec<i32>) {
    for x in vec {
        print!("{} ", x);
    }
    print!("\n");
}


impl Solution {
    pub fn can_place_flowers(
        mut flowerbed: Vec<i32>, mut n: i32
    ) -> bool {
        if n == 0 {
            return true;
        } else if (&flowerbed).len() == 0 {
            return false;
        } else if (&flowerbed).len() == 1 {
            return ((&flowerbed)[0] == 0);
        } 
        let mut valid_slot_cnt: usize = 0;
        for i in 0..(&flowerbed).len() {
            if i == 0 {
                if (
                    (&flowerbed)[i] == 0 && (&flowerbed)[i + 1] == 0
                ) {
                    //println!("dbg0: valid_idx={}", i);
                    valid_slot_cnt += 1;
                    (&mut flowerbed)[i] = 1;
                }
            } else if i == (&flowerbed).len() - 1 {
                if (
                    (&flowerbed)[i] == 0 && (&flowerbed)[i - 1] == 0
                ) {
                    //println!("dbg1: valid_idx={}", i);
                    valid_slot_cnt += 1;
                    (&mut flowerbed)[i] = 1;
                }
            } else {
                if (
                    (&flowerbed)[i] == 0 
                    && (&flowerbed)[i + 1] == 0 && (&flowerbed)[i - 1] == 0
                ) {
                    //println!("dbg2: valid_idx={}", i);
                    valid_slot_cnt += 1;
                    (&mut flowerbed)[i] = 1;
                }
            }
            //vec_print(&flowerbed);
            if valid_slot_cnt as i32 == n {
                return true;
            }
        }
        return (valid_slot_cnt as i32 == n);
    }
}
