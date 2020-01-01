#include <bits/stdc++.h>
#define N 8

void printMatrix(int matrix[N][N]){
    for (int row=0;row<N;row++){
        for (int column=0;column<N;column++){
            std::cout<<matrix[row][column]<<"  ";
        }
        std::cout<<std::endl;
    }
}

bool isSafe(int xPosition,int yPosition,int solutionMatrix[N][N]){
    if (xPosition>=0  &&  xPosition<N  &&  yPosition>=0  &&  yPosition<N  &&  solutionMatrix[xPosition][yPosition]==-1){
        return true;
    }else return false;
}

bool solveKnightsTourUtil(int xPosition,int yPosition,int moveI,int knightsMoveAlongX[8],int knightsMoveAlongY[8],
                          int solutionMatrix[N][N]){
    if (moveI==N*N){
        return true;
    }

    int nextX;
    int nextY;

    for (int i=0;i<8;i++){
        nextX=xPosition+knightsMoveAlongX[i];
        nextY=yPosition+knightsMoveAlongY[i];

        if (isSafe(nextX,nextY,solutionMatrix)){
            solutionMatrix[nextX][nextY]=moveI;

            if (solveKnightsTourUtil(nextX,nextY,moveI+1,knightsMoveAlongX,knightsMoveAlongY,solutionMatrix)){
                return true;
            }else{
                solutionMatrix[nextX][nextY]=-1;
            }
        }
    }
    return false;
}

void solveKnightsTour(){
    int solutionMatrix[8][8];

    for (int row=0;row<N;row++){
        for (int column=0;column<N;column++){
            solutionMatrix[row][column]=-1;
        }
    }

    solutionMatrix[0][0]=0;

    int knightsMoveAlongX[8]={2,1,-1,-2,-2,-2,1,2};
    int knightsMoveAlongY[8]={1,2,2,1,-1,-2,-2,-1};

    if (solveKnightsTourUtil(0,0,1,knightsMoveAlongX,knightsMoveAlongY,solutionMatrix)){
        std::cout<<"Solution exists : "<<std::endl;
        printMatrix(solutionMatrix);
    }else{
        std::cout<<"No solution exists.";
    }

}



int main(){
    solveKnightsTour();
    return 0;
}
