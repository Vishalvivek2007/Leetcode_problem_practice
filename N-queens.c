int checkattack(int** grid, int n, int r, int c){
    for(int i = r - 1; i >= 0; i--){
        if(grid[i][c] == 1) return 1;
    }

    int i = r - 1, j = c - 1;
    while(i >= 0 && j >= 0){
        if(grid[i][j] == 1) return 1;
        i--; j--;
    }

    i = r - 1; j = c + 1;
    while(i >= 0 && j < n){
        if(grid[i][j] == 1) return 1;
        i--; j++;
    }

    return 0;
}

void backtrack(char**** arr, int* arrlen, int** grid, int n, int r, int** returnColumnSizes){
    if(r == n){
        *arr = realloc(*arr, sizeof(char**) * (*arrlen + 1));
        (*arr)[*arrlen] = malloc(sizeof(char*) * n);

        for(int i = 0; i < n; i++){
            (*arr)[*arrlen][i] = malloc(sizeof(char) * (n + 1));
            for(int j = 0; j < n; j++){
                (*arr)[*arrlen][i][j] = grid[i][j] ? 'Q' : '.';
            }
            (*arr)[*arrlen][i][n] = '\0';
        }

        *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * (*arrlen + 1));
        (*returnColumnSizes)[*arrlen] = n;

        (*arrlen)++;
        return;
    }

    for(int c = 0; c < n; c++){
        if(!checkattack(grid, n, r, c)){
            grid[r][c] = 1;
            backtrack(arr, arrlen, grid, n, r + 1, returnColumnSizes);
            grid[r][c] = 0;
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    int** grid = malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++){
        grid[i] = calloc(n, sizeof(int));
    }

    char*** arr = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;

    backtrack(&arr, returnSize, grid, n, 0, returnColumnSizes);

    for(int i = 0; i < n; i++){
        free(grid[i]);
    }
    free(grid);

    return arr;
}
