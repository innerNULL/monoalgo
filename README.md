## Introduction
Contains
* leetcode solutions
* hackerrank solutions
* codewar solutions

## Clasical Problems
### LeetCode
* Backtracking
    * `leetcode/39-combination-sum`
* General
    * `leetcode/1550-three-consecutive-odds`

## References
### Rust
#### Very Functional Style
* `leetcode/648-replace-words/main_v20240607_1311.rs`
* `leetcode/2192-all-ancestors-of-a-node-in-a-directed-acyclic-graph/main_v20240629_1302.rs`
* `leetcode/1935-maximum-number-of-words-you-can-type/main_v20240629_1802.rs`
* `leetcode/350-intersection-of-two-arrays-ii/main_v20240702_2139.rs`
#### Global Variable
* `leetcode/45-jump-game-ii/main_v20240602_1515.rs`
#### Dancing With `Rc<RefCell<>>`
* Tree
    * Classical Cases
        * `leetcode/1382-balance-a-binary-search-tree/main_v20240626_2350.rs`
    * Read-Only
        * `leetcode/1448-count-good-nodes-in-binary-tree/main_v20240531_1750.rs`
        * `leetcote/1161-maximum-level-sum-of-a-binary-tree/main_v20240601_0935.rs`
    * Writable
        * `leetcode/700-search-in-a-binary-search-tree/main_v20240606_2151.rs`
#### Fighting With `Box`
* Hack `Box<_>` with `unsafe`
    * `leetcode/1721-swapping-nodes-in-a-linked-list/main_v20240617_0939.rs`
* Deal Lifetime Issue with `Box<ListNode>`
    * `leetnote/leetcode/143-reorder-list/main_v20240521_2052.rs`
#### Iterator Magics
* `leetcode/22-generate-parentheses/main_v20240612_2335.rs`
#### Iterator + Lambda 
* Make operations on iterator like structions concise
    * `leetcode/2455-average-value-of-even-numbers-that-are-divisible-by-three/main_v20240518_2309.rs`
#### Typical Unsafe Usage
* Play `unsafe` with `Option<&Rc<RefCell<TreeNode>>>`
    * `leetcode/2415-reverse-odd-levels-of-binary-tree/main_v20240518_1912.rs`
    * `leetcode/104-maximum-depth-of-binary-tree/main_v20240508_2339.rs`
    * `leetcode/104-maximum-depth-of-binary-tree/main_v20240509_0001.rs`
* Global Variable Usage
    * `leetcode/345-reverse-vowels-of-a-string/main_v20240511_1606_nac.rs`
* `String` Characters Update with `unsafe`
    * `leetcode/345-reverse-vowels-of-a-string/main_v20240511_1606_nac.rs`
