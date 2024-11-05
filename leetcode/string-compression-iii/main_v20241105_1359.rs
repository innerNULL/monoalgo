#[inline(always)]
fn seg_info_print(seg_info: &Vec<(char, usize)>) {
    println!("Printing `seg_info`:");
    for seg in seg_info {
        println!("({}, {})", seg.0, seg.1);
    }
}


impl Solution {
    #[inline(always)]
    pub fn compressed_string(word: String) -> String {
        let mut seg_info: Vec<(char, usize)> = Vec::new();
        let mut curr_char: char = word.chars().nth(0).unwrap();
        let mut curr_cnt: usize = 1;
        word.chars()
            .into_iter()
            .enumerate()
            .for_each(
                |x: (usize, char)| {
                    if x.0 != 0 {
                        if x.1 == curr_char {
                            curr_cnt += 1;
                        } else {
                            seg_info.push((curr_char, curr_cnt));
                            curr_char = x.1;
                            curr_cnt = 1;
                        }    
                    } else {
                        curr_char = x.1;
                        curr_cnt = 1;
                    }
                    return;
                }
            );
        if (
            seg_info.len() == 0 
            || curr_char != (&(seg_info[seg_info.len() - 1]).0).clone()
        ) {
            seg_info.push((curr_char, curr_cnt));
        }
        //seg_info_print(&seg_info);
        let mut out: Vec<char> = Vec::new();
        for i in 0..seg_info.len() {
            let curr_seg: &(char, usize) = &(seg_info[i]);
            let mut curr_cnt: usize = curr_seg.1;
            while curr_cnt > 9 {
                out.push(
                    std::char::from_digit(9 as u32, 10).unwrap()
                );
                out.push(curr_seg.0);
                curr_cnt -= 9;
            }
            out.push(
                std::char::from_digit(curr_cnt as u32, 10).unwrap()
            );
            out.push(curr_seg.0);
        }
        return out.into_iter().collect::<String>();
    }
}
