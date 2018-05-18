#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"

#define FALSE -1
#define TRUE 1
#define PLAY 'p'
#define QUIT 'q'
#define CHECK 'c'
#define MENU 'm'
#define RIGHT 'd'
#define LEFT 'a'
#define UP 'w'
#define DOWN 's'
#define INSTRUCTION 'i'
#define RESET 'r'
#define NEW 'n'
#define BACK 'b'


char referenceboard[9][9]={};
char answerboard[9][9]={};
char highlight_i = -1;
char highlight_j = -1;
char key_pressed;
int main(){
	int x,y;
	char a;
	key_pressed = PLAY;
	set_graphics(VGA_320X200X256);

	start_page();
	do{
		key_pressed=(char)getch();
		if (key_pressed == PLAY	){
			randomizeBoard(referenceboard,answerboard);
			gameproper();
		}if(key_pressed == INSTRUCTION){
			instruction_page();
		}
	}while(key_pressed!=QUIT);
	quit();

 }

//sudoku problems
void randomizeBoard(char referencboard[9][9],char answerboard[9][9]){
	//srand(time(NULL));
	int r = rand() % 10;
	printf("randomized %d\n", r);
	r=0;
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

int checkIfFull(){
	int i,j;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			if (answerboard[i][j] == '-')
				return FALSE;
		}
	}return TRUE;
}


int checkRow(){
	int i,j,k = 1;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			do{
				if(answerboard[i][j] == answerboard[i][k]){
					return	-1;
				}else k++;
			}while(k < 9);
		}
		k = 1;
	}
	return TRUE;
}



int checkColumn(){
	int i,j,k=1;
	for(i = 0; i < 9; i ++){
		for(j = 0; j < 9; j++){
			do{
				if(answerboard[i][j] == answerboard[k][j]){
					return FALSE;
				}else k++;
			}while(k < 9);
		}
		k = 1;
	}
	return TRUE;
}

int checkSquare(){
	char squareElements[9];
	for (int k = 0; k < 9; k++){
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				squareElements[i*j] = answerboard[k/3*3+i][k/3*3+j];
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



//gui
//displays header
void start_page(){	
	write_text("Welcome to Sudoku",100,40,YELLOW,1); //title

	//menu options
	write_text("[P] - Start Game",70,140,WHITE,0); 
	write_text("[I] - Instruction",70,160,WHITE,0);
	write_text("[Q] - Quit",70,180,WHITE,0);
}

void instruction_page(){
	drawRectangle(0,0,320,220,BLACK,0);
	write_text("HOTKEYS!!!!!",100,10,WHITE,1); 
	write_text("[C]-Check",5,20,WHITE,0);
	write_text("[R]-Reset",5,40,WHITE,0);
	write_text("[N]-NewGame",5,60,WHITE,0);
	write_text("[B]-MainMenu",5,80,WHITE,0);
	write_text("[W]-UP,[A]-LEFT",5,100,WHITE,0);
	write_text("[S]-DOWN,[D]-RIGHT",5,120,WHITE,0);
	write_text("[1-9]-INPUT",5,140,WHITE,0);
    write_text("[0]-Erase",5,160,WHITE,0);
}

void solved_page(){
	drawRectangle(0,0,320,220, BLACK,' '); //clear screen
	write_text("Puzzle Solved! Congratulations!",100,40,YELLOW,1); //title
	write_text("Press 'N' to start new game",100,140,WHITE,0); 
	write_text("Press 'Q' to quit",100,160,WHITE,0);
	switch(key_pressed){
		case NEW:
			randomizeBoard(referenceboard,answerboard);
			gameproper();
			break;
		case QUIT:
			quit();

	}
}

void unsolved_page(){
	
	drawRectangle(0,0,320,220, BLACK,' '); //clear screen
	write_text("Incorrect answers",100,40,YELLOW,1); //title
	write_text("Press 'N' to start new game",70,140,WHITE,0); 
	write_text("Press 'B' to go back",70,160,WHITE,0);
	write_text("Press 'Q' to quit",70,180,WHITE,0);	
	key_pressed=(char)getch();
	switch(key_pressed){
		case NEW:
			randomizeBoard(referenceboard,answerboard);
			gameproper();
			break;
		case BACK:
			gameproper();
			break;
		case QUIT:
			quit();

	}
}
void dummy_page(char * dummy){
	drawRectangle(0,0,320,220, BLACK,' '); //clear screen
	write_text(dummy,100,160,WHITE,1); 
}

void drawRectangle(int x, int y, int w, int h, int color,char num){	
   int i,j;
   char* snum;
   for (i=y;i<=(y+h);i++)
      for (j=x;j<=(x+w);j++)
         write_pixel(j,i,color);
    switch (num){
     	case '1':
    	write_text("1",x+2,y+2,BLACK,0);
    	break;
     	case '2':
    	write_text("2",x+2,y+2,BLACK,0);
    	
    	 break;
     	case '3':
    	write_text("3",x+2,y+2,BLACK,0);
    	
    	 break;
     	case '4':
    	write_text("4",x+2,y+2,BLACK,0);
    	
    	 break;
     	case '5':
    	write_text("5",x+2,y+2,BLACK,0);

    	 break;
     	case '6':
    	write_text("6",x+2,y+2,BLACK,0);
    	break;
     	case '7':
    	write_text("7",x+2,y+2,BLACK,0);
    	break;
     	case '8':
    	write_text("8",x+2,y+2,BLACK,0);
    	break;
     	case '9':
	    write_text("9",x+2,y+2,BLACK,0);
    	break;
    }
}


void print_board(){
	drawRectangle(0,0,320,220, BLACK,' '); //clear screen

	draw_board_border();
	 for (int i = 0; i < 9; i++){
	 	for (int j = 0; j < 9; j++){
	 		if (referenceboard[j][i] == '-')
	 			drawRectangle((i+5.5)*20-2,(j+0.5)*20-2, 10, 10,LIGHTBLUE,answerboard[j][i]);
	 		else
	 			drawRectangle((i+5.5)*20-2,(j+0.5)*20-2, 10, 10,BLUE,answerboard[j][i]);
	 	}
	 }
}

void draw_board_border(){
 drawRectangle(105,3,180,1,YELLOW,' ');
 drawRectangle(105,63,180,1,YELLOW,' ');
 drawRectangle(105,123,180,1,YELLOW,' ');
 drawRectangle(105,183,180,1,YELLOW,' ');
 drawRectangle(105,3,1,180,YELLOW,' ');
 drawRectangle(163,3,1,180,YELLOW,' ');
 drawRectangle(223,3,1,180,YELLOW,' ');
 drawRectangle(283,3,1,180,YELLOW,' ');
}

void gameproper(){
	print_board();
	init_highlight();
	move();

}

void init_highlight(){
	for (int i =0; i < 9; i++){
		for (int j =0; j < 9; j++){
			if (referenceboard[j][i] == '-'){
				highlight(i,j);
				break;
			}
		}
		if (highlight_i != -1 && highlight_j != -1)
			break;
	}	
}

void highlight(int i, int j){	
	if(i < 0){ 
		highlight_i = 8;
		highlight_j = j;
		i = 8;
	}if(j < 0){
		highlight_i = i;
		highlight_j = 8;
		j = 8;
	}else{
	highlight_i = i;
	highlight_j = j;
	}
	drawRectangle((i+5.5)*20-2,(j+0.5)*20-2, 10, 10,LIGHTMAGENTA,answerboard[j][i]);
}

void unhighlight(int i, int j){	
	drawRectangle((i+5.5)*20-2,(j+0.5)*20-2, 10, 10,LIGHTBLUE,answerboard[j][i]);
}

void check(){
	if(checkRow()==TRUE && checkColumn()==TRUE && checkSquare()==TRUE && checkIfFull()==TRUE){
		solved_page();
	}else unsolved_page();
}

void move(){

	while(1){
		key_pressed=(char)getch();
		switch(key_pressed){
			case UP:
					unhighlight(highlight_i,highlight_j);
					highlight(highlight_i,(highlight_j-1)%9);
			break;
			case DOWN:
					unhighlight(highlight_i,highlight_j);
					highlight(highlight_i,(highlight_j+1)%9);
			break;
			case LEFT:
					unhighlight(highlight_i,highlight_j);
					highlight((highlight_i-1)%9,highlight_j);
			break;
			case RIGHT:
					unhighlight(highlight_i,highlight_j);
					highlight((highlight_i+1)%9,highlight_j);
			break;
			case MENU:
				start_page();
			break;
			case CHECK:
				check();
			break;
			case RESET:
				copyboard(referenceboard,answerboard);
			break;
			case NEW:
				randomizeBoard(referenceboard,answerboard);
			break;
			case QUIT:
				quit();
			break;
			case '0':
				if(referenceboard[highlight_j][highlight_i] = '-' ){
				drawRectangle((highlight_i+5.5)*20-2,(highlight_j+0.5)*20-2, 10, 10,LIGHTBLUE,' ');
				answerboard[highlight_j][highlight_i]='-';
				}
			break;
			case '1':
				if(referenceboard[highlight_j][highlight_i] = '-'){
					drawRectangle((highlight_i+5.5)*20-2,(highlight_j+0.5)*20-2, 10, 10,LIGHTBLUE,'1');
					answerboard[highlight_j][highlight_i]='1';
				}
			break;
			case '2':
				if(referenceboard[highlight_j][highlight_i] = '-'){
				drawRectangle((highlight_i+5.5)*20-2,(highlight_j+0.5)*20-2, 10, 10,LIGHTBLUE,'2');
				answerboard[highlight_j][highlight_i]='2';
				}
			break;
			case '3':
				if(referenceboard[highlight_j][highlight_i] = '-'){
				drawRectangle((highlight_i+5.5)*20-2,(highlight_j+0.5)*20-2, 10, 10,LIGHTBLUE,'3');
				answerboard[highlight_j][highlight_i]='3';
				}
			break;
			case '4':
				if(referenceboard[highlight_j][highlight_i] = '-'){
				drawRectangle((highlight_i+5.5)*20-2,(highlight_j+0.5)*20-2, 10, 10,LIGHTBLUE,'4');
				answerboard[highlight_j][highlight_i]='4';		
				}
			break;
			case '5':
				if(referenceboard[highlight_j][highlight_i] = '-'){
				drawRectangle((highlight_i+5.5)*20-2,(highlight_j+0.5)*20-2, 10, 10,LIGHTBLUE,'5');
				answerboard[highlight_j][highlight_i]='5';
				}
			break;
			case '6':
				if(referenceboard[highlight_j][highlight_i] = '-'){
				drawRectangle((highlight_i+5.5)*20-2,(highlight_j+0.5)*20-2, 10, 10,LIGHTBLUE,'6');
				answerboard[highlight_j][highlight_i]='6';
				}
			break;
			case '7':
				if(referenceboard[highlight_j][highlight_i] = '-'){
				drawRectangle((highlight_i+5.5)*20-2,(highlight_j+0.5)*20-2, 10, 10,LIGHTBLUE,'7');
				answerboard[highlight_j][highlight_i]='7';
				}
			break;
			case '8':
				if(referenceboard[highlight_j][highlight_i] = '-'){
				drawRectangle((highlight_i+5.5)*20-2,(highlight_j+0.5)*20-2, 10, 10,LIGHTBLUE,'8');
				answerboard[highlight_j][highlight_i]='8';
				}
			break;
			case '9':
				if(referenceboard[highlight_j][highlight_i] = '-'){
				drawRectangle((highlight_i+5.5)*20-2,(highlight_j+0.5)*20-2, 10, 10,LIGHTBLUE,'9');
				answerboard[highlight_j][highlight_i]='9';
				}
			break;
		}
	}
}





void quit(){
	set_graphics(VGA_TEXT80X25X16);
	clrscr();
	exit(0);
}