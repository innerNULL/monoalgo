use std::collections::HashMap;
use std::collections::HashSet;


#[inline(always)]
fn dfs(
    dest: &mut Vec<HashSet<i32>>, 
    direct_children: &HashMap<i32, Vec<i32>>,
    parent_node: i32,
    root_node: i32
) {
    let entry: Option<&Vec<i32>> = direct_children.get(&root_node);
    match entry {
        None => {
            return;
        },
        Some(children) => {
            children
                .iter()
                .for_each(
                    |child: &i32| {
                        if !dest[*child as usize].contains(&parent_node) {
                            dest[*child as usize].insert(parent_node);
                            dfs(dest, direct_children, parent_node, *child);
                        }
                    }
                );
        }
    }
}


impl Solution {
    #[inline(always)]
    pub fn get_ancestors(
        n: i32, 
        edges: Vec<Vec<i32>>
    ) -> Vec<Vec<i32>> {
        let mut out: Vec<HashSet<i32>> = vec![
            HashSet::<i32>::new(); n as usize
        ];
        let mut direct_children: HashMap<i32, Vec<i32>> = HashMap::new();
        edges
            .iter()
            .for_each(
                |edge: &Vec<i32>| {
                    let from: i32 = edge[0];
                    let to: i32 = edge[1];
                    let entry: Option<&mut Vec<i32>> = {
                        direct_children.get_mut(&from)
                    };
                    match entry {
                        None => {
                            direct_children.insert(from, vec![to]);
                        },
                        Some(x) => {
                            (*x).push(to);
                        }
                    }
                }
            );
        for node in 0..=n {
            dfs(&mut out, &direct_children, node, node);
        }
        return out
            .iter()
            .map(
                |x: &HashSet<i32>| {
                    let mut out: Vec<i32> = x
                        .iter()
                        .map(|x: &i32| { return x.clone(); })
                        .collect::<Vec<i32>>();
                    out.sort();
                    return out;
                }
            )
            .collect::<Vec<Vec<i32>>>();
    }
}
