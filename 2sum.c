typedef struct {
    int key;
    int index;
} HashNode;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int size = numsSize * 2;
    HashNode* hashTable = (HashNode*)calloc(size, sizeof(HashNode));
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int hash = abs(complement) % size;

        while (hashTable[hash].index != 0) {
            if (hashTable[hash].key == complement) {
                result[0] = hashTable[hash].index - 1;
                result[1] = i;
                free(hashTable);
                return result;
            }
            hash = (hash + 1) % size;
        }

        int currHash = abs(nums[i]) % size;
        while (hashTable[currHash].index != 0) {
            currHash = (currHash + 1) % size;
        }
        hashTable[currHash].key = nums[i];
        hashTable[currHash].index = i + 1; 
    }

    free(hashTable);
    return result;
}