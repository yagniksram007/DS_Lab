#include<stdio.h>
#include<stdbool.h>

#define N 4

void printMaze(int sol[N][N])
{
    //printf("\nThe soln to the maze:\n");
    for(int i=0;i<=N-1;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%d  ",sol[i][j]);
        }
        printf("\n");
    }
}
bool mazeFn(int maze[N][N], int x, int y, int sol[N][N])
{
    if(x==N-1 && y==N-1)
    {
        sol[x][y]=1;
        return true;
    }
    
    if(x>=0 && x<N && y>=0 && y<N && maze[x][y]==true)
    {
        sol[x][y]=1;
        
        if(mazeFn(maze,x+1,y,sol)==true)
            return true;
        
        if(mazeFn(maze,x,y+1,sol)==true)
            return true;
            
        sol[x][y]=0;
        return false;
    }
    return false;
}

bool solveMaze(int maze[N][N],int i)
{
    int sol[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    
    if(mazeFn(maze,i,0,sol)==false)
    {
        printf("Solution doesn't exists!");
        return false;
    }
    printMaze(sol);
    return true;
}

int main()
{
    int maze[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},i;
    //int maze[N][N] = {{1,1,1,0},{1,1,0,1},{1,1,1,0},{0,1,1,1}}, i;
    printf("\nEnter the 4x4 maze:\n");
    for(int i=0;i<=N-1;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&maze[i][j]);
        }
        printf("\n");
    }
    printf("The Maze is given as follows:\n\n");
    printMaze(maze);
    
    printf("\nNote: Mouse can only move via the 1's and not 0's");
    
    printf("\n\nEnter the position to enter(0 to 3): ");
    scanf("%d",&i);
    
    printf("\nThe Solution to the maze:\n\n");
    solveMaze(maze,i);
    
    return 0;
}

