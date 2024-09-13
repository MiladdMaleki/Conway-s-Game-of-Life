#include <stdio.h>
#include <stdlib.h>

#define H 20 
#define W 80 

int board[H][W];
int board2[H][W];
void show()
{
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			if(board[i][j]==0) printf(" ");
			else printf("@");
     	}	
	   printf("\n");
	}
}
int countNeighbor(int i,int j)
{
	
	int cnt=0;
	if(i<H-1 && board[i+1][j]==1)cnt++;
	if (i>0  && board[i-1][j]==1)cnt++;
	if(j<W-1 && board[i][j+1]==1)cnt++;
	if(j>0   && board[i][j-1]==1)cnt++;
	//-----------------------------
	if(i<H-1 && j<W-1 && board[i+1][j+1]==1)cnt++;
	if(i>0  && j>0 && board[i-1][j-1]==1)cnt++;
	if(i<H-1 && j>0 && board[i+1][j-1]==1)cnt++;
	if(i>0  && j<W-1 && board[i-1][j+1]==1)cnt++;	

	return cnt;
}
void check()
{
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			if(board[i][j]==0 && countNeighbor(i,j)==3)board2[i][j]=1;
			else if(board[i][j]==1 && countNeighbor(i,j)<2 || board[i][j]==1 && countNeighbor(i,j)>3) board2[i][j]=0;
			else board2[i][j]=board[i][j];		
     	}	
	}	
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			board[i][j]=board2[i][j];		
     	}	
	}
	
}

void init()
{
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
	    	board[i][j]=(rand()<(RAND_MAX/2))?1:0;
		 // board[i][j]=0;
		}
	}	
	    board[10][9]=1;
	    board[10][10]=1;
	    board[10][11]=1;
	
}
int main() {
	
	init();
	while(1)
	{
	  show();
	  sleep(1);
	  check();
	  system("cls");	
    }

	return 0;
}
