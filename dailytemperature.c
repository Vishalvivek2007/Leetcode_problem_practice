int* dailyTemperatures(int* temperatures, int len, int* returnSize) {
    *returnSize = len;
    
    int* result = (int*)malloc(sizeof(int) * len);
    int* stack = (int*)malloc(sizeof(int) * len);  // store indices
    
    int top = -1;
    
    for(int i = 0; i < len; i++)
        result[i] = 0;
    
    for(int i = 0; i < len; i++) {
        
        while(top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int prevIndex = stack[top--];
            result[prevIndex] = i - prevIndex;
        }
        
        stack[++top] = i;
    }
    
    free(stack);
    return result;
}

