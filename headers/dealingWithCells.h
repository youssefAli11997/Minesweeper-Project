void gameMoves(char arr[200][200],char arr2[200][200],int x,int y,char m,int r,int c){
    // f/F --> flag , u/U --> Unmark , o/O --> Open , ? --> Question
    if (m == 'f'||m == 'F'){
        if(arr2[x][y]=='?'){
            numberOfQuestionMarks--;
            numberOfFlags++;
            arr2[x][y]='F';
        }
        if(arr2[x][y]=='X'){
            numberOfFlags++;
            arr2[x][y]='F';
        }
    }
    if (m == 'u'||m == 'U'){
        if(arr2[x][y]=='F'){
            arr2[x][y]='X';
            numberOfFlags--;
        }
        if(arr2[x][y]=='?'){
            arr2[x][y]='X';
            numberOfQuestionMarks--;
        }
    }
    if (m == '?'){
        arr2[x][y]='?';
        numberOfQuestionMarks++;
    }
    if (m == 'O'||m == 'o'){
        if((arr2[x][y] != 'X')&&(arr2[x][y] !='F')&&(arr2[x][y] != '?'))
            openOpenedCell(arr,arr2,x,y,r,c);
        else if(arr2[x][y] !='F'){
            openThisCell(arr,arr2,x,y);
            openAllReachable(arr,arr2,x,y,r,c);
        }
    }
}
void openOpenedCell(char arr[200][200], char arr2[200][200], int i , int j, int n, int m){
    int x , y , flags_counter = 0 ;
    for(x=i-1; x<=i+1; x++){
        if(x<0 || x>=n)
            continue;
        for(y=j-1; y<=j+1; y++){
            if(y<0 || y>=m)
                continue;
            if(arr2[x][y]=='F')
                flags_counter++;
        }
    }
    if(flags_counter==(int)(arr2[i][j]-'0')){
        for(x=i-1; x<=i+1; x++){
            if(x<0 || x>=n)
                continue;
            for(y=j-1; y<=j+1; y++){
                if(y<0 || y>=m)
                    continue;
                if (arr2[x][y]!='F')
                    arr2[x][y]=arr[x][y]; // reveal all non-flag adjacent cells
            }
        }
        for(x=i-1; x<=i+1; x++){
            if(x<0 || x>=n)
                continue;
            for(y=j-1; y<=j+1; y++){
                if(y<0 || y>=m)
                    continue;
            if (arr2[x][y]=='*')
                    arr2[x][y]='!';
            }
        }

    }
}

void openThisCell(char arr[200][200], char arr2[200][200], int i, int j){
    arr2[i][j] = arr[i][j];
}

void openAllReachable(char arr[200][200], char arr2[200][200], int i, int j, int n, int m){
    int x,y,counter=0;
    // check whether any mine is adjacent to the cell
    for(x=i-1; x<=i+1; x++){
        if(x<0 || x>=n)
            continue;
        for(y=j-1; y<=j+1; y++){
            if(y<0 || y>=m)
                continue;
            if(arr[x][y]=='*')
                counter++;
        }
    }
    if(counter==0){
        arr2[i][j] = arr[i][j];
        for(x=i-1; x<=i+1; x++){
            if(x<0 || x>=n)
                continue;
            for(y=j-1; y<=j+1; y++){
                if(y<0 || y>=m)
                    continue;
                if(x==i && y==j)
                    continue;
                if(isCellVisited[x][y]!=0)
                    continue;
                arr2[x][y] = arr[x][y];
                isCellVisited[x][y] = 1;
                openAllReachable(arr,arr2,x,y,n,m);
            }
        }
    }
}

int checkAdjacent(char arr[200][200], int i, int j, int n, int m){
    int x,y,counter=0;
    for(x=i-1; x<=i+1; x++){
        if(x<0 || x>=n)
            continue;
        for(y=j-1; y<=j+1; y++){
            if(y<0 || y>=m)
                continue;
            if(arr[x][y]=='*')
                counter++;
        }
    }
    return counter;
}

void revealNums(char arr[200][200], int n, int m){
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            //check adjacent cells
            if(arr[i][j]!='*')
                arr[i][j] = checkAdjacent(arr,i,j,n,m) + '0';
        }
    }
}
