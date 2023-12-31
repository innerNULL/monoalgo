class Solution {
public:
    static constexpr auto comp = [](
        const std::vector<int32_t>& a, const std::vector<int32_t>& b
    ) -> bool {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        } else {
            return a[0] < b[0];
        }
    };

    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        std::sort(properties.begin(), properties.end(), comp);
        const int32_t size = static_cast<int32_t>(properties.size());
        int32_t weak_cnt = 0;
        int32_t max_till_curr = INT_MIN;
        for (int32_t i = size - 1; i >= 0; --i) {
            const std::vector<int32_t>& curr = properties[i];
            //printf("[%i, %i]\n", curr[0], curr[1]);
            if (curr[1] < max_till_curr) {
                //printf("weak!\n");
                weak_cnt++;
            } else {
                max_till_curr = curr[1];
                //printf("non-weak!\n");
            }
        }
        return weak_cnt;
    }
};
