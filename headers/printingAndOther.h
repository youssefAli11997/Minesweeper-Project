
void printArr(char arr[200][200], int n, int m){
    int i,j,x;
    // column numbers
    printf("\\  ");
    for(i=0; i<m; i++)
        printf(" %d  ",i);
    printf("\n  ");
    for(x=0; x<2*m+1; x++){
        if(x%2==0)
            printf("+");
        else
            printf("---");
    }
    printf("\n");

    for(i=0; i<n; i++){
        printf("%d |",i);
        for(j=0; j<m; j++){
            if(arr[i][j]=='0')
                printf("   |");
            else
                printf(" %c |",arr[i][j]);
        }
        printf("\n  ");
        for(x=0; x<2*m+1; x++){
            if(x%2==0)
                printf("+");
            else
                printf("---");
        }
        printf("\n");
    }
}

void toLowerCase(char name[]){
    int i;
    for(i=0; i<strlen(name); i++)
        if(name[i]>='A' && name[i]<='Z')
            name[i]+=32;
}

int namesAreEqual(char name1[], char name2[]){
    int i;
    if(strlen(name1)!=strlen(name2))
       return 0;
    for(i=0; i<strlen(name1); i++)
        if(name1[i]!=name2[i])
            return 0;
    return 1;
}
