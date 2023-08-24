
const std::vector<char> letters = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 
    'y', 'z'
};

class Solution {
public:
    inline bool checkIfPangram(string sentence) {
        std::set<char> recorder = {};
        for (char letter : sentence) {
            recorder.insert(letter);
        }
        for (char letter : letters) {
            if (recorder.find(letter) == recorder.end()) { return false; }
        }
        return true;
    }
};
