
typedef struct Context {
    int32_t start_idx = 0;
    int32_t end_idx = 1;
    int32_t max_len = 0;
    std::unordered_map<char, int32_t> recorder = {};
    int32_t dup_num = 0;
} MetaData;


void register_str(Context* ctx, const char& str) {
    if (ctx->recorder.find(str) != ctx->recorder.end()) {
        ctx->recorder[str] += 1;
    } else {
        ctx->recorder[str] = 1;
    }
    if (ctx->recorder[str] > 1) { ctx->dup_num += 1; }
}


void deregister_str(Context* ctx, const char& str) {
    if (ctx->recorder.find(str) != ctx->recorder.end()) {
        if (ctx->recorder[str] >= 1) { 
            ctx->recorder[str] -= 1;
        }
        if (ctx->recorder[str] == 1) {
            ctx->dup_num -= 1;
        }
        
    }
}


void print_ctx(const Context* ctx) {
    printf(
        "start: %i, end: %i, dup_num: %i, max_len: %i\n", 
        ctx->start_idx, ctx->end_idx, 
        ctx->dup_num, ctx->max_len
    );
}


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) { return 0; }
        
        Context* ctx = new Context();
        ctx->start_idx = 0;
        ctx->end_idx  = 0;
        ctx->max_len = 1;
        
        register_str(ctx, s.at(0));
        
        while (ctx->end_idx < s.size() - 1) {
            //printf("step 1\n");
            while (ctx->end_idx < s.size() - 1) {
                ctx->end_idx += 1;
                if (ctx->end_idx >= s.size()) { break; }
                
                register_str(ctx, s.at(ctx->end_idx));
                //print_ctx(ctx);
                int32_t curr_len = ctx->end_idx - ctx->start_idx + 1;
                if (ctx->dup_num >= 1 || ctx->end_idx >= s.size()) { 
                    break; 
                }
                if (curr_len > ctx->max_len) {
                    ctx->max_len = curr_len;
                }
            }
            //printf("step 2\n");
            while (ctx->start_idx < ctx->end_idx) {
                deregister_str(ctx, s.at(ctx->start_idx));
                ctx->start_idx += 1;
                //print_ctx(ctx);
                if (ctx->dup_num == 0) { break; }
            }
        }
        //printf("end\n");
        return ctx->max_len;
    }
};