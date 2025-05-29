class Solution:
    def merge(
        self, 
        nums1: List[int], m: int, nums2: List[int], n: int
    ) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        writter: int = m + n - 1
        reader1: int = m - 1
        reader2: int = n - 1
        while reader1 >= 0 and reader2 >= 0:
            val1: int = nums1[reader1]
            val2: int = nums2[reader2]
            if val1 > val2:
                nums1[writter] = val1
                reader1 -= 1
            else:
                nums1[writter] = val2
                reader2 -= 1
            writter -= 1
        while reader2 >= 0:
            nums1[writter] = nums2[reader2]
            reader2 -= 1
            writter -= 1
        return
        
