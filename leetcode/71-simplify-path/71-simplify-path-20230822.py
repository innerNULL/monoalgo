class Solution:
    def simplifyPath(self, path: str) -> str:
        tokens: List[str] = path.split("/")
        simplified_tokens: List[str] = []
        for i, token in enumerate(tokens):
            print(simplified_tokens)
            if i != 0 and token == ".":
                continue
            elif i != 0 and token == "":
                continue
            elif token == "..":
                if len(simplified_tokens) > 1:
                    simplified_tokens = simplified_tokens[:-1]
            else:
                simplified_tokens.append(token)
        result: str = "/".join(simplified_tokens)
        return result if result != "" else "/"
