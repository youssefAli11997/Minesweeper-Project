int checkSave(){
    char userInput[64];
	int num = 0 , length = 0, index = 0,flag = 0,flag1 = 1;
	while( flag1 ) {
        length = 0,flag = 0,num = 0,flag1 = 0;
		printf("\n1-Continue\n2-Save and Exit\n");
		//scanf("%s",userInput);
		gets(userInput);
		length = strlen(userInput);
		if( length > 1) {
			printf("Invalid Input\n");
			flag1 = 1 ;
			continue;
		}
		for(index = 0; index < length; ++index) {
			if(userInput[index] < '1' || userInput[index] > '2') {
				flag = 1;
				break;
			}
		}
		if( flag) {
            flag1 = 1 ;
			printf("Invalid Input\n");
			continue;
		}
		if( sscanf(userInput,"%d", &num) != 1) {
			printf("Invalid Input\n");
			flag1 = 1 ;
			continue;
		}
		if( num < 1 || num > 2) {
			printf("Invalid Input\n");
			flag1 = 1 ;
			continue;
		}}
    return num;
}

int checkSize(char c){
    char userInput[64];
	int num = 0 , length = 0, index = 0,flag = 0,flag1 = 1;
	while( flag1 ) {
        length = 0,flag = 0,num = 0,flag1 = 0;
		printf("Enter %c Size:",c);
		//scanf("%s",userInput);
		gets(userInput);
		length = strlen(userInput);
		if( length > 2) {
			printf("Invalid Input\n");
			flag1 = 1 ;
			continue;
		}
		for(index = 0; index < length; ++index) {
			if(userInput[index] < '0' || userInput[index] > '9') {
				flag = 1;
				break;
			}
		}
		if( flag) {
            flag1 = 1 ;
			printf("Invalid Input\n");
			continue;
		}
		if( sscanf(userInput,"%d", &num) != 1) {
			printf("Invalid Input\n");
			flag1 = 1 ;
			continue;
		}
		if( num < 2 || num > 30) {
			printf("Invalid range\n");
			flag1 = 1 ;
			continue;
		}}
    return num;
}

int checkMode(){
    char userInput[64];
	int num = 0 , length = 0, index = 0,flag = 0,flag1 = 1;
	while( flag1 ) {
        length = 0,flag = 0,num = 0,flag1 = 0;
		//scanf("%s",userInput);
		gets(userInput);
		length = strlen(userInput);
		if( length > 1) {
			printf("Invalid Input\n");
			flag1 = 1 ;
			continue;
		}
		for(index = 0; index < length; ++index) {
			if(userInput[index] < '0' || userInput[index] > '3') {
				flag = 1;
				break;
			}
		}
		if( flag) {
            flag1 = 1 ;
			printf("Invalid Input\n");
			continue;
		}
		if( sscanf(userInput,"%d", &num) != 1) {
			printf("Invalid Input\n");
			flag1 = 1 ;
			continue;
		}
		if( num < 1 || num > 3) {
			printf("Invalid range\n");
			flag1 = 1 ;
			continue;
		}}
    return num;
}


int getNum(int n,char c){
    char userInput[64];
	int num = 0 , length = 0, index = 0,flag = 0,flag1 = 1;
	while( flag1 ) {
        length = 0,flag = 0,num = 0,flag1 = 0;
		printf("Enter %c Number:",c);
		//scanf("%s",userInput);
		gets(userInput);
		length = strlen(userInput);
		if( length > 2) {
			printf("Invalid Input\n");
			flag1 = 1 ;
			continue;
		}
		for(index = 0; index < length; ++index) {
			if(userInput[index] < '0' || userInput[index] > '9') {
				flag = 1;
				break;
			}
		}
		if( flag) {
            flag1 = 1 ;
			printf("Invalid Input\n");
			continue;
		}
		if( sscanf(userInput,"%d", &num) != 1) {
			printf("Invalid Input\n");
			flag1 = 1 ;
			continue;
		}
		if( num < 0 || num >= n) {
			printf("Invalid range\n");
			flag1 = 1 ;
			continue;
		}}
    return num;
}


char checkMove(){
    char userInput[64];
	char action = 0 , length = 0,flag = 1;
	while( flag ) {
        length = 0,flag = 0;
		printf("Enter Move :");
		//scanf("%s",userInput);
		gets(userInput);
		length = strlen(userInput);
		if( length != 1) {
			printf("Invalid Input\n");
			flag = 1 ;
			continue;
		}

        if(!(userInput[0] == 'O' || userInput[0] == 'o' || userInput[0] == 'u' ||userInput[0] == 'U' ||userInput[0] == 'F' ||userInput[0] == 'f' ||userInput[0] == '?' )) {
                flag = 1 ;
                printf("Invalid Input\n");
				continue;
			}

		if( sscanf(userInput,"%c", &action) != 1) {
			printf("Invalid Input\n");
			flag = 1 ;
			continue;
		}}
    return action;
}
