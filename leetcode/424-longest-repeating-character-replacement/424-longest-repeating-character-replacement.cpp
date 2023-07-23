

typedef struct Context {
    std::unordered_map<char, int32_t> recorder;
    int32_t max_count = 0;
    int32_t distinct_num = 0;
    int32_t window_size = 0;
} Context;


void context_set_max_count(Context* ctx) {
    std::unordered_map<char, int32_t>::iterator iter;
    iter = ctx->recorder.begin();
    while (iter != ctx->recorder.end()) {
        if (iter->second > ctx->max_count) {
            ctx->max_count = iter->second;
        }
        iter++;
    }
}


void context_register(Context* ctx, char c) {
    ctx->window_size += 1;

    if (ctx->recorder.find(c) == ctx->recorder.end()) {
        ctx->recorder[c] = 0;
        ctx->distinct_num += 1;
    }
    ctx->recorder[c] += 1;
    if (ctx->recorder[c] > ctx->max_count) {
        ctx->max_count = ctx->recorder[c]; 
    }
}


void context_deregister(Context* ctx, char c) {
    if (ctx->recorder.find(c) != ctx->recorder.end()) {
        ctx->window_size -= 1;

        ctx->recorder[c] -= 1;
        if (ctx->recorder[c] == 0) { 
            ctx->distinct_num -= 1;
        }
        context_set_max_count(ctx); 
    }
}


class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.size() == 1) { return 1; }

        int32_t max_repeating = 0;
        Context* ctx = new Context();
        int32_t left_idx = 0;
        int32_t right_idx = 1;

        context_register(ctx, s.at(left_idx)); 
        while (right_idx < s.size()) {
            //printf("dbg: new iteration\n");
            //printf("dbg: left=%i, right=%i\n", left_idx, right_idx);
            //printf("dbg: window_size=%i\n", ctx->window_size);
            //printf("dbg: max_count=%i\n", ctx->max_count);
            if (ctx->window_size - ctx->max_count > k) {
                if (ctx->window_size - 1 > max_repeating) {
                   max_repeating = ctx->window_size - 1; 
                }
                //printf("dbg: deregistering\n");
                context_deregister(ctx, s.at(left_idx));
                left_idx++; 
            } else {
                //printf("dbg: registering\n");
                if (ctx->window_size > max_repeating) {
                    max_repeating = ctx->window_size;
                }
                context_register(ctx, s.at(right_idx)); 
                right_idx++;
            }
        }
        if (ctx->window_size > max_repeating 
                && ctx->window_size - ctx->max_count <= k) {
           max_repeating = ctx->window_size;  
        } 
        return max_repeating; 
    }
};