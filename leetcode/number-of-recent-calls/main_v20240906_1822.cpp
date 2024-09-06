/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */


#include <algorithm>
#include <deque>


class RecentCounter {
public:
    int32_t cnt = 0;
    std::deque<int32_t> ts = {};
    const int32_t window = 3000;

    inline RecentCounter() {}
    
    inline int32_t ping(const int32_t t) {
        this->ts.push_back(t);
        int32_t threshold = t - this->window;
        while (this->ts.size() > 0) {
            if (this->ts[0] >= threshold) {
                break;
            }
            this->ts.pop_front();
        }
        return this->ts.size();
    }
};
