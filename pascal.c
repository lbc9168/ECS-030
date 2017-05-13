#include <stdio.h>

void CalcPascal(int Row);

void CalcPascal(int Row){


    int myRow = 0, myCol = 0;
    int PascalTri[Row][Row];

    //if Row == 1, the triangle is 1
    for(myRow = 0; myRow < Row; ++myRow){
        PascalTri[myRow][0] = PascalTri[myRow][myRow] = 1;
    }

    //else the number of Row i, Col j is the sum of Row i-1 and Col j-1
    for(myRow = 2; myRow < Row; ++myRow){
         for(myCol = 1; myCol < myRow; myCol++)
             PascalTri[myRow][myCol] = PascalTri[myRow-1][myCol-1] + PascalTri[myRow-1][myCol];
    }

    //output the Pascal Triangle
    for(myRow = 0; myRow < Row; ++myRow){
        for(myCol = 0; myCol <= myRow; myCol++)
        {
            printf("%d ", PascalTri[myRow][myCol]);
        }
        printf("\n");
    }
}

int main(){
    int Row;

    //input the number of row of Pascal Triangle
    printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
    scanf("%d", &Row);
    CalcPascal(Row);

    return 0;
}