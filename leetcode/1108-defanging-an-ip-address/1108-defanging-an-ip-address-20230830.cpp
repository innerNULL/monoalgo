class Solution {
public:
    inline string defangIPaddr(const string& address) {
        std::string output = "";
        for (char letter : address) {
            if (letter == '.') {
                output += "[.]";
            } else {
                output += letter;
            }
        }
        return output;
    }
};
