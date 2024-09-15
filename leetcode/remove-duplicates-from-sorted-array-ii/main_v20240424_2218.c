int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) { return numsSize; }
    int reader = 2;
    int writer = 1;
    while (reader < numsSize) {
        //printf("reader=%i\n", *(nums + reader));
        if ( *(nums + reader) != *(nums + writer - 1) ) {
            writer += 1;
            *(nums + writer) = *(nums + reader);
            //printf("writer=%i\n", *(nums + writer));
        }
        reader += 1;
    }
    return writer + 1;
}
