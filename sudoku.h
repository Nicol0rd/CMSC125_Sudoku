int checkIfBlank(char puzzle[9][9]){
	int i,j;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			if (puzzle[i][j] == '-')
				return -1;
		}
	}return 1;
}

void getCoord(int* x, int* y){
	printf("Get Coordinates\n");
	printf("X: \n");
	scanf("%d", x);
	printf("Y: \n");
	scanf("%d", y);
}

void getInput(char * a){
	printf("Get Input\n");
	scanf("%c", a);
}

void insertInput(char puzzle[9][9],int x, int y, char a){
	if (puzzle[x][y] == '-')
		puzzle[x][y]=a;
}

int checkRow(char puzzle[9][9]){
	int i,j,k = 1;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			do{
				if(puzzle[i][j] == puzzle[i][k]){
					return	-1;
				}else k++;
			}while(k < 9);
		}
		k = 1;
	}
}



int checkColumn(char puzzle[9][9]){
	int i,j,k=1;
	for(i = 0; i < 9; i ++){
		for(j = 0; j < 9; j++){
			do{
				if(puzzle[i][j] == puzzle[k][j]){
					return -1;
				}else k++;
			}while(k < 9);
		}
		k = 1;
	}
}

// int checkSquare(char puzzle[9][9]){
	// char squareElements[9];
	// char checked;
	// int i,j,elementsCounter,checkedSquares = 0;
	// while(checkedSquares < 9){
	// 	for(i = 0;i < 3; i++){
	// 		for(j = 0; j < 3; j++){
	// 			elementsCounter = 0;
	// 			squareElements[elementsCounter] = puzzle[i][j];
	// 			elementsCounter++;
	// 			}
	// 		}elementsCounter++;
	// 	}
	

// }
