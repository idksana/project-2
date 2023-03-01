#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //tolower()

#define TRUE 1
#define FALSE 0

int debugMode = 0;

typedef struct Stack {
    char*   darr;
    int     size;
    int     inUse;
} Stack ;


void init(Stack *S){
  //initializing the stack
    S->size = 0;
    S->inUse = 4;
    S->darr = (char*) malloc(S->inUse * sizeof(char));
}

int is_empty(Stack *S){
  //checking if the stack is empty

    if(S->size == 0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}


void Clear(Stack *S){
  //clearthe stack so that it is empty and ready to be used again
    // we make the variable free
    free(S->darr);
}

char top(Stack *S){
  //accessing/returningthe top element on the stack
    return S->darr[S->size-1];
}

void push(Stack *S, char d){
  //pushing/addingan element onto the stack

    if (S->size == S->inUse){
        // to see if the stack has grown.
        char *temp = S->darr;
        int oldSize = S->inUse;
        int newSize = oldSize + 4;
        int numElemenets = S->size;
        
        printf("The stack has grown from %d to %d, and a total of %d values were copied into the larger array.\n", oldSize, newSize, numElemenets);
        S->inUse += 4;
        S->darr = (char*) malloc(sizeof(char) * oldSize);
        int x;
        for ( x = 0; x < oldSize; x++){
             S->darr[x] = temp[x];
        }
        free (temp);
    }
    if (debugMode == 1){
        printf("Character %c was pushed into the stack.\n", d);
    }
    if (S->size < S->inUse)
        S->darr[(S->size)++] = d;
}

void pop(Stack *S){
  //popping/removingan element off of the stack  (typically named:
    if (debugMode == 1){
        char charr = top(S);
        printf("Character %c was popped from the stack.\n", charr);
    }
    (S->size)--;
}


int pushtop(char *ptr){
  // seeing if L and L2 should be push or top
    Stack S;
    init(&S);
    int i;
    //char *ptr;
    
    for(i = 0; i < strlen(ptr); i++){
      // for L, push
        if(ptr[i] == 'a'){
            push(&S, ptr[i]);
        }
        else if(ptr[i] == 'b'){
            push(&S, ptr[i]);
        }
        else if(ptr[i] == 'c'){
            push(&S, ptr[i]);
        }
        else if(ptr[i] == 'd'){
            push(&S, ptr[i]);
        }
        else if(ptr[i] == 'm'){
            if(is_empty(&S) == 1){
                return 0;
            }
            if(top(&S) == 'a'){
                pop(&S);
            }
            else{
                return 0;
            }
        }
        else if(ptr[i] == 'n'){
          // if L2,  top
            if(is_empty(&S) == 1){
                return 0;
            }
            if(top(&S) == 'b'){
                pop(&S);
            }
            else{
                return 0;
            }
        }
        else if(ptr[i] == 'o'){
            if(is_empty(&S) == 1){
                return 0;
            }
            if(top(&S) == 'c'){
                pop(&S);
            }
            else{
                return 0;
            }
        }
        else if(ptr[i] == 'p'){
            if(is_empty(&S) == 1){
                return 0;
            }
            if(top(&S) == 'd'){
                pop(&S);
            }
            else{
                return 0;
            }
        }
    }
    if (is_empty(&S) == 1){
      //empty it out
        return 1;
    }
    else{
        return 0;
    }
}

void removeExtraLetters(char *str, int j, int x){
    //Once you find all the meaningful words that form our encrypted message, you have to clean them to display the final message.Remove any character except {a, b, c, d} from every letter.You can use a function like RemoveExtraLetter() which takes in an array of character and properly trims it
    
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == 'a'){
            printf("%c", str[i]);
        }
        if (str[i] == 'b'){
            printf("%c", str[i]);
        }
        if (str[i] == 'c'){
            printf("%c", str[i]);
        }
        if (str[i] == 'd'){
            printf("%c", str[i]);
        }
    }
    if(x < j){
        printf( " ");
    }
    else{ //x >= j
        printf("\n");
    }
}

int main(int argc, char const *argv[]){
    /*
    if( argc == 2 ) {
      if ( argv[1][1] == 'd' ){// make it 2d array
        debugMode = 1;
      }
    }*/

    int val;

    for(int j = 0 ; j < argc ; j++){
        if(atoi(argv[j]) != 0){
            val = atoi(&argv[j][j]);
            debugMode = 1;
        }
    }


    for(int k =0; k < argc ; k++){

        if(strcmp(argv[k], "-d")==0){
            printf("-d flag detected.\n");
        }
    }

    char input[300];
    
    
    /* set up an infinite loop */
 while (1){
     /* get line of input from standard input */
   printf ("\nEnter input to check or q to quit\n");
   fgets(input, 300, stdin);
   int i = 0;
   while (input[i] != '\n' && input[i] != '\0'){
      i++;
   }
   input[i] = '\0';
   if ( (strcmp (input, "q") == 0) || (strcmp (input, "Q") == 0) )
     break;
   printf ("%s\n", input);
   
   /*Start tokenizing the input into words separated by space
    We use strtok() function from string.h*/
   /*The tokenized words are added to an array of words*/

   char delim[] = " ";
   char *ptr = strtok(input, delim);
   int j = 0 ;
   //Needs proper allocation
   char *wordList[15];
     //allocate wordList
     //wordList[j] = (char*) malloc(sizeof(char) * strlen(wordList[i]));
    // wordList[j] = wordList[i];

    while (ptr != NULL){
      wordList[j] = (char *) malloc(sizeof(char) * 300);
      strcpy(wordList[j], ptr);
      ptr = strtok(NULL, delim);
      j++;
    }
     
    int x;
    int r = 0;
    for (i = 0; i < j; i++){
        int word = 0;
        for (x = 0; x < strlen(wordList[i]); x++){
            wordList[i][x] = tolower(wordList[i][x]);
        }
        word = pushtop(wordList[i]);
        if ( word == 1){
            removeExtraLetters(wordList[i], j, i);
            r = 1;
        }
    }
    if (r == 0){
        printf("No valid word decoded.\n");
    }
   /*Run the algorithm to decode the message*/
     free(ptr);
 }


 printf ("\nGoodbye\n");





    return 0;
}
