/** Bobby Richmond
    rrichmon
assignment 2 Dynamic memory */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**Code given. */
struct listNode {
   char *data;
   struct listNode *nextPtr;
};

typedef struct listNode LISTNODE;
typedef LISTNODE *LISTNODEPTR;

LISTNODEPTR myPtr=NULL;
LISTNODEPTR listPtr = NULL;
LISTNODEPTR tempPtr = NULL;
LISTNODE newLine;

void insert(LISTNODEPTR *, char *);
void justify(int);
void print(int, int);

main(){
    LISTNODEPTR start = NULL;
    FILE *filePtr = NULL;
    char *word = malloc(20 * sizeof(char));
    char fileName[20];
    int lineChars=0;
    char c;
    char inLine = '\n';
    char *newLinePtr;
    newLine.data = &inLine;
    newLinePtr = &inLine;
    printf("Enter the name of the file. \n");
    scanf("%s", fileName);

    printf("Enter how many characters per line \n");
    scanf("%d", &lineChars);

    /**find the first word in the file*/
    filePtr = fopen(fileName, "r");

    fscanf(filePtr, "%s", word);
    insert(&start, word);

    /**continue searching until the end of the file*/
    while(!feof(filePtr)){
    word = malloc(20*sizeof(char));
    c=fgetc(filePtr); 
    if(c==inLine){
	insert(&start, newLinePtr );
   }
    fscanf(filePtr, "%s", word);
    insert(&start, word);
    }
    fclose(filePtr);


    myPtr=start;
    listPtr=start;
    tempPtr=start;

    printf("Text justified to your specifications \n");
    justify(lineChars);
}


void insert(LISTNODEPTR *sptr, char *myWord){
    LISTNODEPTR tempPtr, current, previous;
    tempPtr = malloc(sizeof(LISTNODE));
    if(tempPtr!=NULL){
    tempPtr->data = myWord;
    tempPtr->nextPtr = NULL;

    previous= NULL;
    current= *sptr;
/**find the last word inserted*/
    while(current!=NULL){
    previous=current;
    current=current->nextPtr;
}
    if(previous==NULL){
    tempPtr->nextPtr=*sptr;
    *sptr= tempPtr;
    }
    else{
    previous->nextPtr=tempPtr;
    tempPtr->nextPtr=current;
    }
}
  else{
    printf("not enough space in memory. ");
  }
}


void justify(int numChars){
//    int spaceOpen =0;
//    int spaceLeft =0;
    int counter =0;
    int numSpaces=0;
    int lineChars = strlen(myPtr->data)+1;
    myPtr=myPtr->nextPtr;
    counter++;
    while((lineChars+strlen(myPtr->data)+1)< numChars){
    lineChars += strlen(myPtr->data)+1;
    counter++;

    if(myPtr->nextPtr!=NULL){
        myPtr=myPtr->nextPtr;
    	}
    }
numSpaces =numChars-lineChars;
//    while((spaceLeft-numSpaces)>0){
//        if(spaceOpen<counter){
//            spaceOpen++;
//           spaceLeft--;
//       }
//       else{
//            spaceOpen=0;
//       }
//   }
    print(counter, numSpaces);

    if(myPtr->nextPtr==NULL){
        tempPtr=myPtr;
    }
//if theres more words continue justifying.
    else{
	justify(numChars);
   }
}

void print(int numWords, int numSpaces){
int i=0;
int j=0;
   for(i=0;i<numWords;i++){
    if(numWords>0){
        printf("%s ", listPtr->data);
        for(j=0;(j*numWords)<numSpaces;j++){
 	printf(" ");
	numSpaces--;
    }
}
    else{
    printf("%s\n", listPtr->data);
    }
    if(listPtr->nextPtr!=NULL){
	if(numSpaces>0){
	printf(" ");
numSpaces--;
}
        listPtr=listPtr->nextPtr;
    }
}
printf("\n");
}

