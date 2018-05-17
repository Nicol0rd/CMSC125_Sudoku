#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"

#define FALSE -1
#define TRUE 1
#define PLAY 'p'
#define QUIT 'q'
int main(){
	int x,y;
	char a;
	char referenceboard[9][9]={};
	char answerboard[9][9]={};
	char key_pressed = 'p';

	randomizeBoard(referenceboard,answerboard);
	// while(printStartPage() != 'P');
	set_graphics(VGA_320X200X256);
	print_board();
	//start_page(8,5);
	
	key_pressed=(char)getch();
	if (key_pressed == PLAY	){
		drawRectangle(0,0,320,220, BLACK,-1); //clear screen
		instruction_page();
		key_pressed=(char)getch();
	}

	if(key_pressed == QUIT){
		set_graphics(VGA_TEXT80X25X16);
		clrscr();
	}	


	printPuzzle(referenceboard);
	printPuzzle(answerboard);
	do{
		getCoord(&x,&y);
		getchar();
		getInput(&a);
		insertInput(referenceboard,answerboard,x,y,a);
		printPuzzle(referenceboard);
		printPuzzle(answerboard);
	}while(checkIfFull(answerboard) == -1);

	printf("%d",checkColumn(answerboard));
	printf("%d",checkRow(answerboard));

}

//sudoku problems
void randomizeBoard(char referencboard[9][9],char answerboard[9][9]){
	//srand(time(NULL));
	int r = rand() % 10;
	printf("randmoized %d\n", r);
	if (r==0){
		char newboard[9][9] = {		
			{'-','6','-','-','7','2','-','-','1'},
			{'8','-','-','1','3','6','5','-','-'},
			{'-','-','3','4','-','-','-','-','-'},
			{'2','-','-','6','5','-','-','3','-'},
			{'-','-','6','-','-','7','-','1','-'},
			{'-','-','-','2','-','-','8','6','4'},
			{'9','-','7','-','8','4','-','-','-'},
			{'-','-','8','-','-','9','-','7','-'},
			{'-','-','-','7','2','1','-','8','3'}
		};	
	copyboard(newboard,referencboard);
	copyboard(newboard,answerboard);
	}else if(r==1){
		char newboard[9][9] = {	
			{'6','5','9','-','1','-','2','8','-'},
			{'1','-','-','-','5','-','-','3','-'},
			{'2','-','-','8','-','-','-','1','-'},
			{'-','-','-','1','3','5','-','7','-'},
			{'8','-','-','9','-','-','-','-','2'},
			{'-','-','3','-','7','8','6','4','-'},
			{'3','-','2','-','-','9','-','-','4'},
			{'-','-','-','-','-','1','8','-','-'},
			{'-','-','8','7','6','-','-','-','-'}
		};
	copyboard(newboard,referencboard);
	copyboard(newboard,answerboard);
	}else if(r==2){
		char newboard[9][9] = {		
			{'-','-','-','-','-','-','9','2','-'},
			{'5','4','-','-','3','-','1','-','-'},
			{'-','-','8','-','5','7','-','-','4'},
			{'-','5','-','-','8','-','-','-','3'},
			{'9','-','3','-','4','6','8','-','-'},
			{'1','-','-','3','-','-','-','4','-'},
			{'-','7','-','4','-','-','-','-','-'},
			{'3','6','1','-','7','9','-','8','-'},
			{'-','-','-','-','6','-','-','3','7'}
		};	
	copyboard(newboard,referencboard);
	copyboard(newboard,answerboard);
	}else if(r==3){
		char newboard[9][9] ={
			{'7','-','-','8','4','-','2','-','5'},
			{'-','3','-','1','5','-','4','-','-'},
			{'-','-','5','-','6','-','-','7','-'},
			{'-','9','-','-','3','4','5','8','-'},
			{'-','2','8','7','-','-','9','-','3'},
			{'5','-','3','9','-','-','6','-','-'},
			{'-','-','4','5','2','-','-','9','-'},
			{'-','-','9','4','-','8','-','-','-'},
			{'8','-','-','-','-','1','7','-','-'}
		};	
	copyboard(newboard,referencboard);
	copyboard(newboard,answerboard);	
	}else if(r==4){
		char newboard[9][9] = {		
			{'-','-','-','-','-','-','7','-','-'},
			{'3','9','-','7','-','8','5','4','-'},
			{'8','6','-','-','5','4','-','-','-'},
			{'9','-','6','-','4','7','-','-','-'},
			{'1','3','4','2','-','-','-','9','-'},
			{'-','5','8','1','-','9','-','-','4'},
			{'5','4','-','9','2','3','-','-','8'},
			{'-','-','-','-','7','-','9','-','5'},
			{'-','-','-','-','-','1','-','3','-'}
		};	
	copyboard(newboard,referencboard);
	copyboard(newboard,answerboard);
	}else if(r==5){
		char newboard[9][9] = {		
			{'8','9','-','7','6','4','5','-','-'},
			{'-','4','-','3','-','-','-','-','9'},
			{'3','2','7','9','-','-','-','-','-'},
			{'-','8','-','-','5','3','-','1','-'},
			{'-','-','-','6','-','1','-','-','-'},
			{'6','-','-','-','-','-','-','4','-'},
			{'7','-','-','4','9','-','8','3','-'},
			{'-','-','9','-','-','8','2','7','-'},
			{'-','-','-','-','-','-','-','-','-'}
		};
	copyboard(newboard,referencboard);
	copyboard(newboard,answerboard);
	}else if(r==6){
		char newboard[9][9] = {		
			{'-','-','-','-','-','-','-','7','-'},
			{'-','7','-','-','1','-','5','9','-'},
			{'-','8','-','3','-','2','-','1','6'},
			{'6','5','-','4','-','9','-','-','3'},
			{'-','-','4','-','-','-','-','-','-'},
			{'-','-','-','7','6','-','-','-','-'},
			{'9','1','-','6','-','-','-','-','-'},
			{'-','2','7','9','-','-','-','4','-'}, 
			{'4','-','5','1','-','-','-','-','-'}
		};	
	copyboard(newboard,referencboard);
	copyboard(newboard,answerboard);	
	}else if(r==7){
		char newboard[9][9] = {		
			{'-','-','-','5','4','2','-','1','9'},
			{'1','-','-','-','-','6','-','-','-'},
			{'-','2','9','-','-','-','6','-','-'},
			{'-','-','-','-','9','-','-','6','4'},
			{'-','3','2','6','-','7','-','9','8'},
			{'-','-','-','-','3','-','-','-','-'},
			{'2','-','7','-','1','8','-','5','-'},
			{'-','-','-','-','-','9','-','3','-'},
			{'-','-','3','7','6','5','9','-','1'}
		};	
	copyboard(newboard,referencboard);
	copyboard(newboard,answerboard);
	}else if(r==8){
		char newboard[9][9] = {		
			{'3','5','1','-','-','8','7','-','6'},
			{'-','4','-','7','-','-','1','-','-'},
			{'-','7','-','-','-','-','9','5','4'},
			{'8','-','4','-','2','-','6','-','-'},
			{'-','3','2','-','-','-','-','-','-'},
			{'-','-','-','-','1','-','-','-','3'},
			{'7','1','-','-','4','6','-','-','5'},
			{'-','-','6','-','5','9','-','7','-'},
			{'-','-','-','-','-','-','-','-','-'}
		};
	copyboard(newboard,referencboard);
	copyboard(newboard,answerboard);
	}else if(r==9){
		char newboard[9][9] = {		
			{'-','5','7','1','-','-','-','-','8'},
			{'1','8','3','-','-','-','-','9','-'},
			{'4','-','-','-','-','-','-','-','-'},
			{'8','-','2','-','3','-','-','-','-'},
			{'-','7','-','-','1','-','8','-','-'},
			{'5','-','-','4','8','9','-','-','-'},
			{'-','4','9','-','-','-','7','6','-'},
			{'-','6','-','-','7','-','9','-','-'},
			{'7','1','5','3','9','-','-','-','-'}
		};
	copyboard(newboard,referencboard);
	copyboard(newboard,answerboard);
	}

}

void copyboard(char fromBoard[9][9],char toBoard[9][9]){
	for (int i =0 ;i <9; i++){
		for (int j =0 ;j <9; j++){
			toBoard[i][j] = fromBoard[i][j];
		}

	}
}

//

int checkIfFull(char answerboard[9][9]){
	int i,j;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			if (answerboard[i][j] == '-')
				return FALSE;
		}
	}return TRUE;
}

void getInput(char * a){
	printf("Get Input\n");
	// scanf("%c", a);
}

void insertInput(char referenceboard[9][9],char answerboard[9][9],int x, int y, char a){
	if (referenceboard[x][y] == '-')
		answerboard[x][y]=a;
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
					return FALSE;
				}else k++;
			}while(k < 9);
		}
		k = 1;
	}
}


// int checkColumn(char puzzle[9][9]){
// 	for (int i = 0; i < 9; i++){
// 		for (int j = 0; j < 9; j++){
// 			for (int k = 1; k < 10; k++){
// 				if (k )
// 			}
// 		}

// 	}
// }
int checkSquare(char puzzle[9][9]){
	char squareElements[9];
	for (int k = 0; k < 9; k++){
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				squareElements[i*j] = puzzle[k/3*3+i][k/3*3+j];
			}
		}
		if (checker(squareElements) == FALSE)
			return FALSE;
	}
	return TRUE;
}

int checker(char tobeCheck[9]){
	for (int i=1; i < 10; i++){
		for (int j=0; j < 9; j++){
			if (i == tobeCheck[j])
				continue;
		}
	}
	return FALSE;
}

void getCoord(int* x, int* y){
	printf("Get Coordinates\n");
	printf("X: \n");
	// scanf("%d", x);
	printf("Y: \n");
	// scanf("%d", y);
}

//

char printStartPage(){
	char isStart;
	printf("Welcome To Sudoku\n");
	printf("Press 'P' to game\n");
	// scanf("%c", &);
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
	printf("-------------------------------\n");
}



//gui
//displays header
start_page(int x, int y){	
	write_text("Welcome to Sudoku",100,40,YELLOW,1); //title

	//menu options
	write_text("Press 'P' to start game",100,140,WHITE,0); 
	write_text("Press 'Q' to quit",100,160,WHITE,0);
}

instruction_page(){
	write_text("Instruction",100,160,WHITE,1); 
}
void drawRectangle(int x, int y, int w, int h, int color,int num){
   int i,j;
   char* snum;
   for (i=y;i<=(y+h);i++)
      for (j=x;j<=(x+w);j++)
         write_pixel(j,i,color);
    switch (num){
     	case 1:
    	write_text("1",x+2,y+2,BLACK,0);
    	break;
     	case 2:
    	write_text("2",x+2,y+2,BLACK,0);
    	
    	 break;
     	case 3:
    	write_text("3",x+2,y+2,BLACK,0);
    	
    	 break;
     	case 4:
    	write_text("4",x+2,y+2,BLACK,0);
    	
    	 break;
     	case 5:
    	write_text("5",x+2,y+2,BLACK,0);

    	 break;
     	case 6:
    	write_text("6",x+2,y+2,BLACK,0);
    	break;
     	case 7:
    	write_text("7",x+2,y+2,BLACK,0);
    	break;
     	case 8:
    	write_text("8",x+2,y+2,BLACK,0);
    	break;
     	case 9:
	    write_text("9",x+2,y+2,BLACK,0);
    	break;
    }
}


void print_board(){

 for (int i = 0; i < 9; i++){
 	for (int j = 0; j < 9; j++){
 		drawRectangle(i*20,j*20, 20, 20,BLUE,j+1);
 		drawRectangle(i*20-10,j*20-10, 10, 10,YELLOW,j+1);
 	}
 }
  drawRectangle(145,145, 20, 20,BLUE,0);
  drawRectangle(150,150, 10, 10,WHITE,9);
  // drawRectangle(145,150, 5, 10,BLUE,0);
  // drawRectangle(160,150, 5, 10,BLUE,0);
  // drawRectangle(150,145, 10, 5,BLUE,0);
  // drawRectangle(150,160, 10, 5,BLUE,0);


}