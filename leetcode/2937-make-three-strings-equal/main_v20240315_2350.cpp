class Solution {
public:
    int findMinimumOperations(
        const string& s1, const string& s2, const string& s3
    ) {
        if (
            s1.size() == 0 || s2.size() == 0 || s3.size() == 0 
            || s1[0] != s2[0] 
            || s1[0] != s3[0]
            || s2[0] != s3[0]
        ) {
            return -1;
        }
        int32_t min_len = std::min(
            std::min(
                static_cast<int32_t>(s1.size()), 
                static_cast<int32_t>(s2.size())
            ), static_cast<int32_t>(s3.size())
        );
        int32_t idx = 0;
        while (
            idx < min_len 
            && s1[idx] == s2[idx] && s2[idx] == s3[idx]
        ) {
            idx++;
        }
        return s1.size() - idx + s2.size() - idx + s3.size() - idx;
    }
};
