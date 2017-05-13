#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <memory.h>

//checking to see if two words are anagrams of each other.

char* ReadWord();
char* Capitalize(char* str);

void swap(char* a, char* b);
void make_sorted(char* str, int size);
char* make_copy(char* str, int size);
char* get_sorted(char* str, int size);

int JudgeAnagram(char* UpperFirstWord, char* UpperSecondWord);
void PrintResults(int check, char* FirstWord, char* SecondWord);



//define the swap function
void swap(char* a, char* b){

    char temp = *a;
    *a = *b;
    *b = temp;
}


//This function is to sort the string
void make_sorted(char* str, int size){

    int i, j;
    char* min;

    for(i = 0; i < size; ++i){
        min = &str[i];                      //min = &str[i]

        for(j = i + 1; j < size; ++j){       //locating the smallest
            if(strcmp(&str[j],min) < 0){
                min = &str[j];
            }
        }
        swap(min, &str[i]);                 //swap(min, &str[i])
    }
}


//this function is to make a copy of a string
char* make_copy(char* str, int size){

    char* copy = (char*)malloc(size * sizeof(char));
    int i;

    for(i = 0; i < size; ++i){
        copy[i] = str[i];
    }

    return copy;
}


//this function is to sort the sting using the copy
char* get_sorted(char* str, int size){

    char* copy = make_copy(str, size);

    make_sorted(copy, size);

    return copy;
}


//change all the letters into upper case
char* Capitalize(char* str){

    char* cap = (char*)malloc((strlen(str) + 1) * sizeof(char));
    int i;

    for(i = 0; i <= strlen(str); ++i){
        cap[i] = toupper(str[i]);
    }
    return cap;
}


//input the string
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


//judge if the two sorted strings are the same, if yes, return 1, if not, return 0
int JudgeAnagram(char* UpperFirstWord, char* UpperSecondWord) {

    int size = strlen(UpperFirstWord);

    for (int i = 0; i <= size; ++i) {
        if (UpperFirstWord[i] != UpperSecondWord[i]){
            return 0;
        }
    }

    return 1;
}


//check and print the result
void PrintResults(int check, char* FirstWord, char* SecondWord){
    if(check == 1){
        printf("%s is an anagram of %s\n", FirstWord, SecondWord);
    }
    else{
        printf("%s is NOT an anagram of %s\n", FirstWord, SecondWord);
    }
}


//main body
int main(void){

    //define two words
    char* FirstWord = NULL;
    char* SecondWord = NULL;

    //define the upper case of two words
    char* UpperFirstWord = NULL;
    char* UpperSecondWord = NULL;

    int check;

    //print the introduction and input
    printf("Please enter the first word: ");
    FirstWord = ReadWord();
    printf("Please enter the second word: ");
    SecondWord = ReadWord();

    //check if the length of two words are the same, if not, print result and end
    if(strlen(FirstWord) != strlen(SecondWord)){
        printf("%s is NOT an anagram of %s\n", FirstWord, SecondWord);
        return 0;
    }

    //capitalize and sort
    UpperFirstWord = Capitalize(FirstWord);
    UpperSecondWord = Capitalize(SecondWord);

    UpperFirstWord = get_sorted(UpperFirstWord, strlen(UpperFirstWord));
    UpperSecondWord = get_sorted(UpperSecondWord, strlen(UpperSecondWord));

    //check and print
    check = JudgeAnagram(UpperFirstWord, UpperSecondWord);

    PrintResults(check, FirstWord, SecondWord);

    //free the storage
    free(FirstWord);
    free(SecondWord);
    free(UpperFirstWord);
    free(UpperSecondWord);

    return 0;

}