

def is_self_dividing(num: int) -> bool:
    num_str: str = str(num)
    for letter in num_str:
        if letter == "0" or num % int(letter) != 0:
            return False
    return True


class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        output: List[int] = []
        num: int = left
        while num <= right:
            if is_self_dividing(num):
                output.append(num)
            num += 1
        return output
            
        
