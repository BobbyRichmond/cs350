/*Path created by Bobby Richmond CS350 
non-recursive by project definition.
*/
#include <stdio.h>
void solveMaze(char [200][200], int, int);
char puzzle[200][200] = {0};
int entRow,entCol,exRow,exCol;
/*creates a maze and attempts to find a path to the exit. */
void main() {
	int pRow=0, pCol=0;
	printf("Please enter the number of rows ");
	scanf("%d", &pRow);
	printf("Please enter the number of columns ");
	scanf("%d", &pCol);
	/*code for reading the file */
	char array[200][200]={0};
      FILE *fptr;
     char c;
     char file_name[20];
     int i,j;

  printf("Type in the name of the file containing the Field\n");
  scanf("%s",file_name);
  fptr=fopen(file_name,"r");
  for (i=0; i<pRow; i++)
   for (j=0; j<pCol; j++){
     c=fgetc(fptr);
     while ( !((c == '1')||(c =='0')) ) c=fgetc(fptr);
     array[i][j]=c;
   }
  fclose(fptr);
  for (i=0; i<pRow; i++)
   for (j=0; j<pCol; j++)  {
    if (j == 0) printf("\n");
    printf("%c  ",array[i][j]);
   }
  printf("\n");

    for(i=0; i<pRow;i++){
        for(j=0;j<pCol;j++){
            puzzle[i][j]=array[i][j];
        }
    }
	solveMaze(puzzle,pRow,pCol);
	 traverse(entRow, entCol);
	for(i=0; i<pRow; i++){
	  for(j=0; j<pCol; j++){
	   if(j==0) printf("\n");
		printf("%c ", puzzle[i][j]);
	  }
	}
	printf("\n");
}

/*find the entrance and exit of the maze along the edges. */
 void solveMaze(char puzzle[200][200], int pRow, int pCol){
	int count=0;
	entRow=0, entCol=0, exRow=0, exCol=0;
	int i=0,j=0,x=0,y=0;
	for ( ; i < pRow; i++) {
		if (puzzle[i][0] == '0') {
			if(count==1){
			exRow=i;
			exCol=0;
			count++;
			}
			else{
			entRow =i;
			entCol =0;
			puzzle[i][0]='X';
			count++; }
		}
	}
	for ( ; x < pCol; x++) {
		if (puzzle[pRow-1][x] == '0') {
		if(count==1){
            exRow = pRow-1;
            exCol = x;
            count++;
}
			else{
            entRow=pRow-1;
            entCol=x;
            puzzle[pRow-1][x]='X';
			count++; }
	}
}
	for (y = pRow; y>=0; y--) {
		if (puzzle[y][pCol-1] == '0') {
			if(count==1){
			exRow=y;
			exCol=pCol-1;
			count++;
			}
			else{
            entRow=y;
            entCol=pCol-1;
            puzzle[y][pCol-1]='X';
			count++; }
		}
	}
	for (j = pCol-1; j>=0; j--) {
		if (puzzle[0][j] == '0') {
			if(count==1){
            exRow=0;
            exCol=j;
            count++;
			}
			else{
            entRow=0;
            entCol=j;
            puzzle[0][j]='X';
			count++; }
		}
	}
	if(count<2){
	printf("Could not find either an exit or entrance");
	}
}

    /**This method will go through the maze and look for an exit*/
    void traverse(int row, int col){
    row = entRow;
    col= entCol;
    int direction = 0, i=0;
   for( ;i<40001; i++){
    if(row==exRow && col==exCol){
    printf("found an exit");
    return;
    }
    if(direction==0){/**East*/
    if(puzzle[row+1][col]=='1'){
        if(puzzle[row][col+1]=='0'){
        puzzle[row][col+1]='X';
        direction=0;
        col=col+1;
                }
        else if(puzzle[row-1][col]=='0'){
        puzzle[row-1][col]='X';
        direction=1;
        row=row-1;
                }
        else if(puzzle[row][col-1]=='0'){
        puzzle[row][col-1]='X';
        direction=2;
        col=col-1;
                }
        else if(puzzle[row][col+1]=='X'){
        direction=0;
        col=col+1;
                }
	else if(puzzle[row-1][col]=='X'){
        direction=1;
        row=row-1;
                }
 	else if(puzzle[row][col-1]=='X'){
        direction=2;
        col=col-1;
                }
        }
        else if(puzzle[row+1][col]=='0'){
        puzzle[row+1][col]='X';
        direction=3;
        row=row+1;
                }
        else if(puzzle[row+1][col]=='X'){
            direction=3;
            row=row+1;
  	      }
	else{
	  direction=1;
	}
        }
    else if(direction==1){/**North*/
    if(puzzle[row][col+1]=='1'){
        if(puzzle[row-1][col]=='0'){
        puzzle[row-1][col]='X';
        direction=1;
        row=row-1;
                }
        else if(puzzle[row][col-1]=='0'){
        puzzle[row][col-1]='X';
        direction=2;
        col=col-1;
                }
        else if(puzzle[row+1][col]=='0'){
        puzzle[row+1][col]='X';
        direction=3;
        row=row+1;
                }
        else if(puzzle[row-1][col]=='X'){
        direction=1;
        row=row-1;
                }
        else if(puzzle[row][col-1]=='X'){
        direction=2;
        col=col-1;
                }
        else if(puzzle[row+1][col]=='X'){
        direction=3;
        row=row+1;
                }
        }
        else if(puzzle[row][col+1]=='0'){
	puzzle[row][col+1]='X';
        direction=0;
        col=col+1;
        }
        else if(puzzle[row][col+1]=='X'){
        direction=0;
        col=col+1;
        }
    }
    else if(direction==2){/**West*/
    if(puzzle[row-1][col]=='1'){
        if(puzzle[row][col-1]=='0'){
        puzzle[row][col-1]='X';
        direction=2;
        col=col-1;
                }
        else if(puzzle[row+1][col]=='0'){
        puzzle[row+1][col]='X';
        direction=3;
        row=row+1;
                }
        else if(puzzle[row][col+1]=='0'){
        puzzle[row][col+1]=='X';
        direction=0;
        col=col+1;
        }
	else if(puzzle[row][col+1]=='X'){
	direction=0;
	col=col+1;
	}
        else if(puzzle[row][col-1]=='X'){
        direction=2;
        col=col-1;
                }
        else if(puzzle[row+1][col]=='X'){
        direction=3;
        row=row+1;
                }
        else if(puzzle[row][col+1]=='X'){
        direction=0;
        col=col+1;
        }
    }
        else if(puzzle[row-1][col]=='0'){
        puzzle[row-1][col]='X';
        direction=1;
        row=row-1;
                }
        else if(puzzle[row-1][col]=='X'){
        direction=1;
        row=row-1;
         }
    }
     else if(direction==3){/**South*/
    if(puzzle[row][col-1]=='1'){
        if(puzzle[row+1][col]=='0'){
        puzzle[row+1][col]='X';
        direction=3;
        row=row+1;
                }
        else if(puzzle[row][col+1]=='0'){
        puzzle[row][col+1]='X';
        direction=0;
        col=col+1;
                }
        else if(puzzle[row-1][col]=='0'){
        puzzle[row-1][col]=='X';
        direction=1;
        row=row-1;
        }
	else if( puzzle[row+1][col]=='X'){
        puzzle[row+1][col]='X';
        direction=3;
        row=row+1;
            }
        else if(puzzle[row][col+1]=='X'){
        direction=0;
        col=col+1;
                }
        else if(puzzle[row-1][col]=='X'){
        direction=1;
        row=row-1;
        }

    }
        else if(puzzle[row][col-1]=='0'){
        puzzle[row][col-1]='X';
        direction=2;
        col=col-1;
        }
        else if(puzzle[row][col-1]=='X'){
        direction=2;
        col=col-1;
                }
        }
    }
    printf("could not complete the maze");
}

