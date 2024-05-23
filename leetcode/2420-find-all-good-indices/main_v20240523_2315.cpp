#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")


template<typename T>
constexpr void dbg_vec_print(const std::vector<T>& vec) {
    for (const T& x : vec) {
        std::cout << x << " ";
    }
    printf("\n");
}


class Solution {
public:
    inline std::vector<int32_t> 
    goodIndices(
        const std::vector<int32_t>& nums, const int32_t k
    ) {
        std::vector<int32_t> dp_left_cons_inc(nums.size(), 0);
        std::vector<int32_t> dp_right_cons_desc(nums.size(), 0);
        dp_left_cons_inc[1] = 1;
        dp_right_cons_desc[nums.size() - 2] = 1;
        for (size_t i = 2; i < nums.size(); ++i) {
            if (nums[i - 2] >= nums[i - 1]) {
                dp_left_cons_inc[i] = dp_left_cons_inc[i - 1] + 1;
            } else {
                dp_left_cons_inc[i] = 1;
            }
        }
        for (int32_t i = nums.size() - 3; i >= 0; --i) {
            if (nums[i + 1] <= nums[i + 2]) {
                dp_right_cons_desc[(size_t)i] = (
                    dp_right_cons_desc[(size_t)i + 1] + 1
                );
            } else {
                dp_right_cons_desc[(size_t)i] = 1;
            }
        }
        //dbg_vec_print(dp_left_cons_inc);
        //dbg_vec_print(dp_right_cons_desc);
        std::vector<int32_t> out(0);
        for (size_t i = 0; i < nums.size(); ++i) {
            if (
                dp_left_cons_inc[i] >= k && dp_right_cons_desc[i] >= k
            ) {
                out.emplace_back((int32_t)i);
            }
        }
        return out;
    }
};
