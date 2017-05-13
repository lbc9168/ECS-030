#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//make a copy of input
char* make_copy(char* str, int size){

    char* copy = (char*)malloc(size * sizeof(char));
    int i;

    for(i = 0; i < size; ++i){
        copy[i] = str[i];
    }

    return copy;
    }


//input function
char* ReadWord(){
    char* str = NULL;
    int size = 0;
    do{
        size++;
        str = (char*)realloc(str, size * sizeof(char));
        scanf("%c", &str[size - 1]);
    }while(str[size - 1] != '\n');

    str[size - 1] = '\0';
    return str;
}


//inser function, insert a letter at the end of string
char* Insert(char** sorted_ar, int size, char val){
    *sorted_ar = realloc(*sorted_ar, size * sizeof(char));
    (*sorted_ar)[size - 1] = val;

    return *sorted_ar;
}


//check and insert letter
char* CheckAndChange(char* UserWord){

    int size = strlen(UserWord);

    //if end with ch or sh, add es
    if(UserWord[size - 1] == 'h'){
        if(UserWord[size - 2] == 'c' || UserWord[size - 2] == 's'){
            UserWord = Insert(&UserWord, size + 1, 'e');
            UserWord = Insert(&UserWord, size + 2, 's');
        }
        else{
            UserWord = Insert(&UserWord, size + 1, 's');
        }
    }

    //if end with s, x, or z, add es
    else if(UserWord[size - 1] == 's' || UserWord[size - 1] == 'x' || UserWord[size - 1] == 'z'){
        UserWord = Insert(&UserWord, size + 1, 'e');
        UserWord = Insert(&UserWord, size + 2, 's');
    }

    //if end with vowel and y, add s, if end with a constant and y, y becomes ies
    else if(UserWord[size - 1] == 'y'){
        if(UserWord[size - 2] == 'a' || UserWord[size - 2] == 'e' || UserWord[size - 2] == 'i' || UserWord[size - 2] == 'o' || UserWord[size - 2] == 'u'){
            UserWord = Insert(&UserWord, size + 1, 's');
        }
        else{
            UserWord = Insert(&UserWord, size, 'i');
            UserWord = Insert(&UserWord, size + 1, 'e');
            UserWord = Insert(&UserWord, size + 2, 's');
        }
    }

    //if end with f or fe, becomes ves
    else if(UserWord[size - 1] == 'f'){
        UserWord = Insert(&UserWord, size, 'v');
        UserWord = Insert(&UserWord, size + 1, 'e');
        UserWord = Insert(&UserWord, size + 2, 's');
    }

    else if(UserWord[size - 1] == 'e' && UserWord[size - 2] == 'f'){
        UserWord[size - 2] = 'v';
        UserWord = Insert(&UserWord, size, 'e');
        UserWord = Insert(&UserWord, size + 1, 's');
    }


    //else, add s
    else{
        UserWord = Insert(&UserWord, size + 1, 's');
    }


    return UserWord;
}


int main(void){

    //define userword and the changed userword
    char* UserWord = NULL;
    char* NewUserWord = NULL;

    printf("Please enter a word: ");
    UserWord = ReadWord();

    char* copy = make_copy(UserWord, strlen(UserWord));


    //check and change, then print results
    NewUserWord = CheckAndChange(copy);
    printf("The plural form of %s is %s.\n", UserWord, NewUserWord);
}
