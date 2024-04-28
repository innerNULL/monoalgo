class Solution {
public:
    std::vector<std::vector<int32_t>> 
    merge(std::vector<std::vector<int32_t>>& intervals) {
        std::sort(
            intervals.begin(), intervals.end(),
            [](
                const std::vector<int32_t>& a, 
                const std::vector<int32_t>& b
            ) {
                return a[0] < b[0];
            }
        );
        std::vector<std::vector<int32_t>> out = {};
        for (const std::vector<int32_t>& interval : intervals) {
            if (out.size() == 0) {
                out.emplace_back(std::move(interval));
            } else {
                if (out[out.size() - 1][1] < interval[0]) {
                    out.emplace_back(std::move(interval));
                } else {
                    out[out.size() - 1][1] = std::max(
                        interval[1], out[out.size() - 1][1]
                    );
                }
            }
        }
        return out;
    }
};
