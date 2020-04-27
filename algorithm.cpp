#include <iostream>
#include<stdlib.h>

using namespace std;
void initializeBoard(char board[][3]);
void displayBoard(char board[][3]);
//gets input from user returns character number of location chosen by user

void getInput(char board[][3], char marker,int& x,int& y);
/* mark character marker of player on chosen character pos of board*/

void markBoard(char board[][3],int x,int y, char marker);
//checks to see if someone has won returns true or false

bool gameOver(char board[][3]);
//checks to see if someone won on rows of board

bool checkHorizontal(char board[][3], char marker);
//checks to see if someone won on columns of board

bool checkVertical(char board[][3], char marker);
//checks to see if someone won on diagonal of board

bool checkDiagonal(char board[][3], char marker);
//checks to see if players have tied

bool checkTie(char board[][3]);
//prints winner as marker or ties

void printWinner(char marker);
//checks to see if selected location is available returns false when location has already been taken or is an invalid number

bool validMove(char board[][3], int x,int y);

int main()
{
  srand(time(0));
  int start=rand()%2;
  char board[3][3];
  char exit;
  char f,s;
  int x,y;
  f='X';
  s='O';
  
  initializeBoard(board);
  displayBoard(board);
  
    while(true)
    {
      f = '1';
      getInput(board,f,x,y);
      f = 'X';
      markBoard(board, x,y, f);
      displayBoard(board);
      
      if (gameOver(board))
      break;
      s = '2';
      
      getInput(board,s,x,y);
      s='O';
      markBoard(board, x,y, s);
      displayBoard(board);
      
      if (gameOver(board))
      break;
    }
  system("pause");
  return 0;
  }
  
  
void initializeBoard(char board[][3])
  {
  char count = '1';
    for (int i = 0; i<3; i++)
    {
      for (int j = 0; j<3; j++)
      {
          board[i][j]= count;
          count++;
      }
    }
  }
  
  
bool validMove(char board[][3], int x, int y)
  {
  if(x<0||x>2||y<0||y>2)
  return false;
  
  if(board[x][y]=='X'||board[x][y]=='O')
  return false;
  
  else
  return true;
  }
  
  
void displayBoard(char board[][3])
  { 
  int t;
  for(t=0; t<3; t++) 
    {
    cout<<" "<<board[t][0]<<" | "<< board[t][1]<<" | "<< board[t][2];
    if(t!=2) cout<<"\n---|---|---\n";
    }
  cout<<"\n";
  }
  
  
void getInput(char board[][3], char marker,int& x,int& y)
  {
  for(;;)
    {
    cout << "Player "<< marker << " Enter a Row and Column (between 1-3): ";
    cin >> x>>y;
    x--;
    y--;
    
    if (validMove(board,x,y))
    return;
    cout << "Invalid Move: Please Try Again\n\n";
    }
  }
  
  
void markBoard(char board[][3], int x,int y, char marker)
  { 
  board[x][y]=marker;
  }
  
bool gameOver(char board[][3])
  {
  if (checkHorizontal(board,'X'))
    {
    printWinner('X');
    return true;
    }
  if (checkVertical(board, 'X'))
    {
    printWinner('X');
    return true;
    }
  if (checkDiagonal(board, 'X'))
    { 
    printWinner('X');
    return true;
    }
  if (checkHorizontal(board,'O'))
    {
    printWinner('O');
    return true;
    }
  if (checkVertical(board, 'O'))
    {
    printWinner('O');
    return true;
    }
  if (checkDiagonal(board, 'O'))
    {
    printWinner('O');
    return true;
    }
  if (checkTie(board))
    {
    printWinner('T');
    return true;
    }
  return false;
  }
  
  
bool checkHorizontal(char board[][3], char marker)
  {
  int i,j,count;
  for(i=0; i<3; i++)
    {
    count=0;
    for(j=0;j<3;j++)
    if(board[i][j]==marker)
    count++;
    if(count==3)
    return true;
    }
  return false;
  }
  
  
bool checkVertical(char board[][3], char marker)
  {
  int i,j,count;
  for(i=0; i<3; i++)
    {
    count=0;
    for(j=0;j<3;j++)
    
    if(board[j][i]==marker)
    count++;
    
    if(count==3)
    return true;
    }
  return false;
  }
  
  
bool checkDiagonal(char board[][3], char marker)
  {
  if(board[0][0]==board[1][1] && board[1][1]==board[2][2]&& board[0][0]==marker)
  return true;
  if(board[0][2]==board[1][1] && board[1][1]==board[2][0]&& board[0][2]==marker)
  return true;
  return false;
  }
  
  
bool checkTie(char board[][3])
  {
  int i,j;
  for(i=0;i<3;i++)
  for(j=0;j<3;j++)
  if(isdigit(board[i][j]))
  return false;
  return true;
  }
  
  
void printWinner(char marker)
  { 
  if(marker=='T')
  cout<<"TIE GAME!\n";
  else 
    {
    if(marker =='X') 
      {
      marker = '1';
      }
    else
    {
    marker = '2';
    }
    cout<<"The winner is player "<<marker<<"!!!\n";
    }
  }

