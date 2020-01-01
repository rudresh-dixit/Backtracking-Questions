#include <bits/stdc++.h>
#define N 4

void printMatrix(int matrix[N][N]){
    for (int row=0;row<N;row++){
        for (int column=0;column<N;column++){
            std::cout<<matrix[row][column]<<"  ";
        }
        std::cout<<std::endl;
    }
}

bool isSafeHorizontally(int row,int column,int matrix[N][N]){
    for (int i=column;i>=0;i++){
        if (matrix[row][i]){
            return false;
        }
    }
    return true;
}


bool isSafeUpperDiagonally(int row,int column,int matrix[N][N]){
    for (int i=row,j=column;i>=0 && j>=0;i--,j--){
        if (matrix[i][j]){
            return false;
        }
    }
    return true;
}


bool isSafeLowerDiagonally(int row,int column,int matrix[N][N]){
    for (int i=row,j=column;i<N && j>=0;i++,j--){
        if (matrix[i][j]){
            return false;
        }
    }
    return true;
}

bool isSafe(int row,int column,int matrix[N][N]){
    return isSafeHorizontally(row,column,matrix) && isSafeLowerDiagonally(row,column,matrix) &&
           isSafeUpperDiagonally(row,column,matrix);
}


bool NQueenUtil(int matrix[N][N],int column){
    if (column>=N){
        return true;
    }

    for (int i=0;i<N;i++){
       // matrix[i][col]=1;
        if (isSafe(i,column,matrix)){
            matrix[i][column]=1;
            if (NQueenUtil(matrix,column+1)){
                return true;
            }
            matrix[i][column]=0;
        }
    }
    return false;
}

void NQueen(){
    int solutionMatrix[N][N];
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            solutionMatrix[i][j]=0;
        }
    }

    if (NQueenUtil(solutionMatrix,0)){
        std::cout<<"solution exists"<<std::endl;
        printMatrix(solutionMatrix);
    }else{
        std::cout<<"not exists";
    }
}

int main()
{
    NQueen();
	return 0;
}













