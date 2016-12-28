void newGame(char arr[200][200], int n, int m){
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            arr[i][j] = 'X';
        }
    }
}

void isVisitedInitialize(){
    int i,j;
    for(i=0; i<200; i++){
        for(j=0; j<200; j++)
            isCellVisited[i][j] = 0;
    }
}

void mineIntialize(char arr[200][200], int l, int r, int c, int n , int m ){
    int x , y , i ;
    time_t t;
    // seeding the rand() built-in function
    srand((unsigned) time(&t));
    for (i=0;i<l;i++){
        x = rand()%n;
        y = rand()%m;
        if (arr[x][y] =='*' || (x==r && y==c))
            i--;
        else
            arr[x][y]='*';
    }
}
