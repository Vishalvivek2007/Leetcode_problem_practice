

int getbox(int x){
    if(x <= 2) return 0;
    else if(x <= 5) return 1;
    else return 2;
}

bool isValidSudoku(char** board, int len, int* col) {

    
    int** rowhash = (int**)calloc(9, sizeof(int*));
    for(int i = 0; i < 9; i++){
        rowhash[i] = (int*)calloc(10, sizeof(int));
    }

    
    int** colhash = (int**)calloc(9, sizeof(int*));
    for(int i = 0; i < 9; i++){
        colhash[i] = (int*)calloc(10, sizeof(int));
    }

    int*** boxhash = (int***)calloc(3, sizeof(int**));
    for(int i = 0; i < 3; i++){
        boxhash[i] = (int**)calloc(3, sizeof(int*));
        for(int j = 0; j < 3; j++){
            boxhash[i][j] = (int*)calloc(10, sizeof(int));
        }
    }

    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){

            if(board[i][j] != '.'){

                int val = board[i][j] - '0';

                int bi = getbox(i);
                int bj = getbox(j);

                if(rowhash[i][val] == 1 ||
                   colhash[j][val] == 1 ||
                   boxhash[bi][bj][val] == 1){

                    return false;
                }

                rowhash[i][val] = 1;
                colhash[j][val] = 1;
                boxhash[bi][bj][val] = 1;
            }
        }
    }

    return true;
}
