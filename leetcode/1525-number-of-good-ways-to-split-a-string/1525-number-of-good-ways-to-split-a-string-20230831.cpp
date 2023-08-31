

typedef struct Context {
    std::unordered_map<char, int32_t> recorder = {};
    int32_t distinct_cnt = 0;
} Context;


inline void context_push(Context* ctx, char letter) {
    std::unordered_map<char, int32_t>& recorder = ctx->recorder;
    if (recorder.find(letter) == recorder.end()) {
        recorder[letter] = 0;
    }
    recorder[letter]++;
    if (recorder[letter] == 1) { ctx->distinct_cnt++; }
}


inline void context_pop(Context* ctx, char letter) {
    std::unordered_map<char, int32_t>& recorder = ctx->recorder;
    if (recorder.find(letter) != recorder.end()) {
        recorder[letter]--;
        if (recorder[letter] == 0) { ctx->distinct_cnt--; }
    }
}


inline void context_push_str(Context* ctx, const std::string& str) {
    for (char letter : str) {
        context_push(ctx, letter);
    }
}


class Solution {
public:
    int numSplits(string s) {
        if (s.size() <= 1) { return 0; }
        int32_t cnt = 0;
        Context* left_ctx = new Context();
        Context* right_ctx = new Context();
        context_push_str(right_ctx, s);
        for (int32_t i = 0; i <= s.size() - 1; ++i) {
            context_push(left_ctx, s[i]);
            context_pop(right_ctx, s[i]);
            if (left_ctx->distinct_cnt == right_ctx->distinct_cnt) {
                cnt++;
            }
        }
        return cnt; 
    }
};
