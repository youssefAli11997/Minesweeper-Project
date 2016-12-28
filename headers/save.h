void saveGame(char arr[200][200], char arr2[200][200], int numberOfMines, int numberOfMoves, int numberOfFlags, int numberOfQuestionMarks, int sec1, int n, int m){
    int i,j;

    FILE* intStuff = fopen("intStuff.txt","w");
    FILE* charStuff = fopen("charStuff.txt","w");

    // int stuff

    /*
        n raws
        m cols
        isCellVisited
        time
        number of mines
        number of moves
        number of flags
        number of ?

    */
    fprintf(intStuff,"%d %d ",n,m);

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            fprintf(intStuff,"%d ",isCellVisited[i][j]);
        }
    }

    fprintf(intStuff,"%d ",sec1);

    fprintf(intStuff,"%d ",numberOfMines);
    fprintf(intStuff,"%d ",numberOfMoves);
    fprintf(intStuff,"%d ",numberOfFlags);
    fprintf(intStuff,"%d ",numberOfQuestionMarks);


    // charStuff

    /*
        hidden grid
        shown grid
    */

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            fprintf(charStuff,"%c",arr[i][j]);
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            fprintf(charStuff,"%c",arr2[i][j]);
        }
    }
    printf("The game is saved successfully :-)\n");

    fclose(intStuff);
    fclose(charStuff);
}
