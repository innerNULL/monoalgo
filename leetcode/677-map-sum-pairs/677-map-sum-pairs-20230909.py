class MapSum:

    def __init__(self):
        self.recorder: Dict[str, int] = {}

    def insert(self, key: str, val: int) -> None:
        self.recorder[key] = val

    def sum(self, prefix: str) -> int:
        result: int = 0
        for k, v in self.recorder.items():
            if prefix in k and k.index(prefix) == 0:
                result += v
        return result

        


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
