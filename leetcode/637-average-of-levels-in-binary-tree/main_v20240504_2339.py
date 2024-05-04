# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


def tree_val_group_by_level(
    dest: Dict[int, List[int]], 
    level: int, 
    node: Optional[TreeNode]
) -> None:
    if node is not None:
        if level not in dest:
            dest[level] = []
        dest[level].append(node.val)
        tree_val_group_by_level(dest, level + 1, node.left)
        tree_val_group_by_level(dest, level + 1, node.right)
    return


class Solution:
    def averageOfLevels(
        self, root: Optional[TreeNode]
    ) -> List[float]: 
        recorder: Dict[int, List[int]] = {}
        tree_val_group_by_level(recorder, 0, root)
        out: List[float] = [0] * len(recorder)
        for i in range(len(out)):
            out[i] = sum(recorder[i]) / len(recorder[i])
        return out
        
