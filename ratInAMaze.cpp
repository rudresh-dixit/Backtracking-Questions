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


bool hasPath(int x,int y,int maze[N][N]){
    if (x<N && x>=0 && y>=0 && y<N && maze[x][y]==1){
        return true;
    }else return false;
}

bool ratInAMazeUtil(int x,int y,int maze[N][N],int solution[N][N]){
    if (x==N-1 && y==N-1){
        solution[x][y]=1;
        return true;
    }


        if (hasPath(x,y,maze)) {
        solution[x][y]=1;

            if (ratInAMazeUtil(x,y+1,maze,solution)) return true;
            if (ratInAMazeUtil(x+1,y,maze,solution)) return true;


                solution[x][y]=0;
                return false;


    }
    return false;
}

void ratInAMaze(int maze[N][N]){
    int solution[N][N];

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            solution[i][j]=0;
        }
    }

    solution[0][0]=1;

    if (ratInAMazeUtil(0,0,maze,solution)){
        std::cout<<"solution exists:"<<std::endl;
        printMatrix(solution);
    }else{
        std::cout<<"no solution.";
    }
}

int main()
{
    int maze[N][N]={{1,1,0,0},{1,1,0,0},{0,1,0,0},{1,1,1,1}};
    printMatrix(maze);
    ratInAMaze(maze);
	return 0;
}















