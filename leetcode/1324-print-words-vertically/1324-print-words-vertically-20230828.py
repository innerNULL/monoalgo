class Solution:
    def printVertically(self, s: str) -> List[str]:
        words: List[str] = s.split(" ")
        max_len: int = max([len(x) for x in words])
        results: List[str] = []
        for i in range(max_len):
            curr_col: str = ""
            for word in words:
                if i >= len(word):
                    curr_col += " "
                else:
                    curr_col += word[i]
            results.append(curr_col.rstrip(" "))
        return results
