class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        recorder: Dict[str, int] = {}
        for pair in dominoes:
            key: str = "-".join([str(x) for x in sorted(pair)])
            if key not in recorder:
                recorder[key] = 0
            recorder[key] += 1
        cnt : float = 0
        for k, v in recorder.items():
            if v > 1:
                # Arithmetic sequence fomular
                cnt = cnt + ((v - 1) + 0) * v / 2
        return int(cnt)

        
