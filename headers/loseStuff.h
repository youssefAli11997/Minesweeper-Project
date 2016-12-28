int checkLose(char arr2[200][200],int n , int m){
    int i , j ;
    for(i=0; i<n; i++){
            for(j=0; j<m; j++)
                if (arr2[i][j]=='*' || arr2[i][j]=='!')
                    return 1 ;
    }
    return 0 ;
}

void shawLoseCase(char arr[200][200],char arr2[200][200],int x, int y,int n,int m){
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(arr[i][j]=='*'){
                if(i==x&&j==y)
                    arr2[i][j] = '!';
                else if(arr2[i][j]!='F'&&arr2[i][j]!='!')
                    arr2[i][j] = 'M';
            }
            else if(arr2[i][j]=='F'){
                if(arr[i][j]!='*')
                    arr2[i][j] = '-';
            }
            else if(arr2[i][j]=='X'){
                arr2[i][j] = arr[i][j];
            }
        }
    }
}
