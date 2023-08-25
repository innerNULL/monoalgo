class Solution {
public:
    int commonFactors(int a, int b) {
        int32_t larger = 0;
        int32_t smaller = 0;
        if (a >= b) {
            larger = a;
            smaller = b;
        } else {
            larger = b;
            smaller = a;
        }
        std::set<int32_t> cands = {};
        for (int32_t i = 1; i <= smaller; ++i) {
            if (smaller % i == 0) { cands.insert(i); }
        }
        int32_t common_factor_cnt = 0;
        for (const int32_t& cand : cands) {
            if (larger % cand == 0) { common_factor_cnt++; }
        }
        return common_factor_cnt;
    }
};
