int checkWin(char arr2[200][200],int n , int m, int numberOfMines ){
    int i , j , leftCounter = 0 ;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++)
            if(arr2[i][j]=='X'||arr2[i][j]=='F'||arr2[i][j]=='?')
                leftCounter++;
    }
    if (leftCounter==numberOfMines)
        return 1 ;
    else
        return 0 ;
}

void shawAllMinesAsFlags(char arr[200][200],char arr2[200][200],int n,int m){
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(arr[i][j]=='*')
                arr2[i][j] = 'F';
        }
    }
}
