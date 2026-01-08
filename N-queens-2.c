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

void backtrack(int** grid, int n, int r, int* count){
    if(r == n){
        (*count)++;
        return;
    }

    for(int c = 0; c < n; c++){
        if(!checkattack(grid, n, r, c)){
            grid[r][c] = 1;
            backtrack(grid, n, r + 1, count);
            grid[r][c] = 0;
        }
    }
}

int totalNQueens(int n) {
    int** grid = malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++){
        grid[i] = calloc(n, sizeof(int));
    }

    int count = 0;
    backtrack(grid, n, 0, &count);

    for(int i = 0; i < n; i++){
        free(grid[i]);
    }
    free(grid);

    return count;
}
