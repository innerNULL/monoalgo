#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")


void vec_print(std::vector<int32_t>& vec) {
    for (auto x : vec) {
        printf("%i ", x);
    }
    printf("\n");
}


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) {
            return true;
        } else if (flowerbed.size() == 0) {
            return false;
        } else if (flowerbed.size() == 1) {
            return (flowerbed[0] == 0);
        }
        size_t valid_slots_cnt = 0;
        for (size_t i = 0; i < flowerbed.size(); ++i) {
            if (i == 0) {
                if (
                    flowerbed[i] == 0 && flowerbed[i + 1] == 0
                ) {
                    //printf("dbg0: i=%i\n", i);
                    valid_slots_cnt += 1;
                    flowerbed[i] = 1;
                }
            } else if (i == flowerbed.size() - 1) {
                if (
                    flowerbed[i] == 0 && flowerbed[i - 1] == 0
                ) {
                    //printf("dbg1: i=%i\n", i);
                    valid_slots_cnt += 1;
                    flowerbed[i] = 1;
                }
            } else {
                if (
                    flowerbed[i] == 0 
                    && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0
                ) {
                    //printf("dbg2: i=%i\n", i);
                    valid_slots_cnt += 1;
                    flowerbed[i] = 1;
                }
            }
            if (valid_slots_cnt == n) {
                return true;
            }
        }
        return (valid_slots_cnt == n);
    }
};
