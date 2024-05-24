class Solution {
public:
    constexpr int32_t 
    findContentChildren(
        std::vector<int32_t>& g, std::vector<int32_t>& s
    ) {
        constexpr auto ranker = [](int32_t& a, int32_t& b) { return a < b; };
        std::sort(g.begin(), g.end(), ranker);
        std::sort(s.begin(), s.end(), ranker);
        size_t g_idx = 0;
        size_t s_idx = 0;
        int32_t cnt = 0;
        while (g_idx < g.size() && s_idx < s.size()) {
            const int32_t g_val = g[g_idx];
            const int32_t s_val = s[s_idx];
            if (s_val >= g_val) {
                cnt += 1;
                g_idx += 1;
                s_idx += 1;
            } else {
                s_idx += 1;
            }
        }
        return cnt;
    }
};
