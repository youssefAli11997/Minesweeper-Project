/*
    Project: MineSweeper Game - CMD Version

    Created By: Youssef Ali Hassan Ali
                Mohamed Mashaal El-Agha
                Ahmed Mohamed El-Bawab
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

int isCellVisited[200][200]; // global to be seen for every function
int numberOfFlags = 0;
int numberOfQuestionMarks = 0;

// our header files
#include "headers/newGameStuff.h"
#include "headers/inputValidation.h"
#include "headers/save.h"
#include "headers/graphicsStuff.h"
#include "headers/dealingWithCells.h"
#include "headers/winStuff.h"
#include "headers/loseStuff.h"
#include "headers/printingAndOther.h"

// in our header-file functions: arr==hidden_field , arr2==shown_field

int main(){
    welcomeScreen();
    int mode,i,j,n,m,numberOfMoves = 0,time_interval=0,gameEnd=0,raw,col,ContOrSave;
    char action;
    char a ='X',b='Y';
    char hidden_field[200][200],shown_field[200][200],playerName[1000];

    double playerScore;
    int numberOfMines;

    struct playerStuff{
        char name[1000];
        double score;
    };
    struct playerStuff player[1000];

    //TIME 1
    time_t sec1,extra = 0;
    sec1 = time (NULL);

    mainMenu();
    mode = checkMode();

    if(mode==1){
        n = checkSize(a);
        m = checkSize(b);
        numberOfMines = 1 + (n * m)/10 ;
        newGame(shown_field,n,m);
        newGame(hidden_field,n,m);
        isVisitedInitialize();

        // printing the field to start playing
        printArr(shown_field,n,m);
        printf("Number of moves: %d\n",numberOfMoves);
        printf("Number of flags: %d\n",numberOfFlags);
        printf("Number of question marks: %d\n",numberOfQuestionMarks);
        printf("Time Passed: 0H:0M:0S\n");
    }
    else if(mode==2){
        // load game part // we made it in main() to make it easy to update variables

        FILE* intStuffLoading = fopen("intStuff.txt","r");
        FILE* charStuffLoading = fopen("charStuff.txt","r");

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
        fscanf(intStuffLoading,"%d %d ",&n,&m);

        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                fscanf(intStuffLoading,"%d ",&isCellVisited[i][j]);
            }
        }

        fscanf(intStuffLoading,"%d ",&extra);

        fscanf(intStuffLoading,"%d ",&numberOfMines);
        fscanf(intStuffLoading,"%d ",&numberOfMoves);
        fscanf(intStuffLoading,"%d ",&numberOfFlags);
        fscanf(intStuffLoading,"%d ",&numberOfQuestionMarks);


        // charStuff

        /*
            hidden grid
            shown grid
        */

        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                fscanf(charStuffLoading,"%c",&hidden_field[i][j]);
            }
        }

        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                fscanf(charStuffLoading,"%c",&shown_field[i][j]);
            }
        }
        printf("The game is loaded successfully :-)\n");
        fclose(intStuffLoading);
        fclose(charStuffLoading);
        // end of load game part

        //GETTING HOURS,MIN,SEC
        int hoursL,minL,secondsL;
        time_interval = extra;
        hoursL=extra/360;
        minL=(extra%360)/60;
        secondsL=(extra%360)%60;
        // printing the field to start playing
        printArr(shown_field,n,m);
        printf("Number of moves: %d\n",numberOfMoves);
        printf("Number of flags: %d\n",numberOfFlags);
        printf("Number of question marks: %d\n",numberOfQuestionMarks);
        printf("Time Passed: %dH:%dM:%dS\n",hoursL,minL,secondsL);
    }

    else if(mode==3){
        FILE* printBoard = fopen("scoreboard.txt","r");
        int x=0,y;
        while(fscanf(printBoard,"%s %lf",player[x].name,&player[x].score)==2)
            x++;

        fclose(printBoard);
        printf("\t\t---------- ScoreBoard ----------\n");
        for(y=0; y<x; y++){
            printf("%04d) %s --> %lf\n",y+1,player[y].name,player[y].score);
        }
        gameEnd = 1;
    }

    // the game loop
    int gameWin = 0 , gameLose = 0 ;
    int firstOpenAction = 1; //indicator to generate random mines after the first open from the user;
    while(!gameWin && !gameLose && !gameEnd){
        printf("-----------------------\n");
        ContOrSave = checkSave();
        if(ContOrSave==2){
            saveGame(hidden_field,shown_field,numberOfMines,numberOfMoves,numberOfFlags,numberOfQuestionMarks,time_interval,n,m);
            break;
        }
        // time 2;
        time_t sec2;
        sec2 = time (NULL);
        raw = getNum(n,a);
        col = getNum(m,b);
        action = checkMove();
        numberOfMoves++;
        if( (action=='O' || action=='o') && firstOpenAction){
            mineIntialize(hidden_field,numberOfMines,raw,col,n,m);
            revealNums(hidden_field,n,m); //generating the hidden_field
            FILE * Debug ;   //Printing Debug File
            Debug = fopen("Debug.txt","w");
            for(i=0;i<n;i++){
                for(j=0;j<m;j++){
                    fprintf(Debug,"%c ",hidden_field[i][j]);}
            fprintf(Debug,"\n");}
            fclose(Debug);
            firstOpenAction = 0;
        }
        gameMoves(hidden_field,shown_field,raw,col,action,n,m);

        gameLose = checkLose(shown_field,n,m);
        gameWin  = checkWin(shown_field,n,m,numberOfMines);

        printArr(shown_field,n,m);

        printf("Number of moves: %d\n",numberOfMoves);
        printf("Number of flags: %d\n",numberOfFlags);
        printf("Number of question marks: %d\n",numberOfQuestionMarks);

        //GETTING TOTAL TIME INTERVAL
        time_interval=sec2-sec1+extra;

        //GETTING HOURS,MIN,SEC
        int hours,min,seconds;
        hours=time_interval/360;
        min=(time_interval%360)/60;
        seconds=(time_interval%360)%60;

        //PRINTING TIME INTERVAL
        printf("Time Passed: %dH:%dM:%dS\n",hours,min,seconds);
    }

    if(gameLose){
        system("cls");
        printf("Sorry, You Lose :(\n");
        shawLoseCase(hidden_field,shown_field,raw,col,n,m);
        printArr(shown_field,n,m);
    }
    else if(gameWin){
        printf("You Win :)\n");
        congratulate();
        shawAllMinesAsFlags(hidden_field,shown_field,n,m);
        printArr(shown_field,n,m);
        playerScore = (pow(n,4)*pow(m,4))/(time_interval*numberOfMoves);
        printf("Enter your name:\n");
        scanf("%s",playerName);
        toLowerCase(playerName);
        FILE* scoreboard = fopen("scoreboard.txt","r");
        int x=0,y,z;
        while(fscanf(scoreboard,"%s %lf",player[x].name,&player[x].score)!=EOF)
            x++;

        fclose(scoreboard);
        int found=0;
        for(y=0; y<x; y++){
            if(namesAreEqual(playerName,player[y].name)){
                if(playerScore>player[y].score){
                    player[y].score = playerScore;
                }
                found = 1;
            }
        }
        if(!found){
            strcpy(player[x].name,playerName);
            player[x++].score = playerScore;
        }
        // sorting
        char tempName[1000];
        double tempScore;
        for(y=0; y<x; y++){
            for(z=y+1; z<x; z++){
                if(player[z].score>player[y].score){
                    tempScore = player[y].score;
                    player[y].score = player[z].score;
                    player[z].score = tempScore;

                    strcpy(tempName,player[y].name);
                    strcpy(player[y].name,player[z].name);
                    strcpy(player[z].name,tempName);
                }
            }
        }
        scoreboard = fopen("scoreboard.txt","w");
        for(y=0; y<x; y++){
            fprintf(scoreboard,"%s ",player[y].name);
            fprintf(scoreboard,"%lf ",player[y].score);
        }
        fclose(scoreboard);
    }
    return 0;
}
