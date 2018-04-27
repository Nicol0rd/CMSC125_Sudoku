char printStartPage(){
	char isStart;
	printf("Welcome To Sudoku\n");
	printf("Press 'P' to game\n");
	scanf("%c", &isStart);
	return isStart;
}

void printPuzzle(char puzzle[9][9]){
	int i, j;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			printf("%c ",puzzle[i][j]);
		}
		printf("\n");
	}
}