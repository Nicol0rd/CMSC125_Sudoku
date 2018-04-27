#include <stdio.h>
#include "sudoku.h"
#include "sudoku-printing.h"

int main(){
	int x,y;
	char a;
	char puzzle[9][9] = {
		{'1','2','3','4','5','7','9','2','6'},
		{'5','4','2','7','3','6','1','8','1'},
		{'2','7','8','9','5','7','3','1','4'},
		{'3','5','2','2','8','9','4','5','3'},
		{'9','6','3','7','4','6','8','8','9'},
		{'1','2','6','3','8','1','2','4','5'},
		{'7','7','5','4','1','2','3','6','9'},
		{'3','6','1','4','7','9','7','8','2'},
		{'8','9','3','4','6','1','2','3','7'}
	};
	// while(printStartPage() != 'P');
	printPuzzle(puzzle);
	do{
		getCoord(&x,&y);
		getchar();
		getInput(&a);
		insertInput(puzzle,x,y,a);
		printPuzzle(puzzle);
	}while(checkIfBlank(puzzle) == -1);

	printf("%d",checkColumn(puzzle));
	printf("%d",checkRow(puzzle));

}



