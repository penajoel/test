//============================================================================
// Name        : TicTacToe.cpp
// Author      : Joel Peña
// Copyright   : Your copyright notice
// Description : class program creates a game of tic tac toe for two players. First displays board 
// with spots to insert, when three are in a row a play is declared to be winner.
//============================================================================

#include <iostream>
using namespace std;

class TTT{

public :
TTT()
{}
void DisplayBoard();// function for board
char board[3][3]={'1','2','3','4','5','6','7','8','9',}; // created array of board to display
char player='X';//created a character 'X' and 'O'
void insert();//function to let player where they want to go while checking if it is empty
void switchPlayer();// function swtiches player
char IsWinner();//function to know when a player has won

};
int main() {
	TTT game;
	int turn=0;//variable to store amount of moves that can be made.
				//at most 9 moves can be made in the game
	game.DisplayBoard();//display board function is called to show all spaces
	while (1)//created a continous loop for game
	{
		turn++;// as soon as a user picks a spot, add 1 to variable turn
		game.insert();//insert function allows a player to pick a spot to go in only if neither player
				//has picked that spot

		game.DisplayBoard();//display board for the continious loop
							//while
		if (game.IsWinner()=='X')//if x has three in a row, x is declared winner
		{
			cout<< "X wins";
			break;//once it is known that x has won, stop the game
		}
		else if( game.IsWinner()=='O')// if O has three in a row, O is declared winner
		{
			cout << "O wins";
			break;//once O has three in a row stop the game
		}
		else if(game.IsWinner()=='/' && turn==9)// if neither play has three in a row and the turns
										  // have added to 9 then it is a draw since no more moves are left
		{
				cout << "Draw";
		}

		game.switchPlayer();//once a player has picked a spot, it is the next players turn and the loop goes
						//through the whole algorithim again
	}
	return 0;
}
void TTT::DisplayBoard()//displays board in three rows,three columns
{					//two for loops to print out the array of what was stored in board
	for (int i=0;i<3;i++) ///first for loop creates the rows

	{
		for (int j=0;j<3;j++)//second for loop creates the columns

			cout << board[i][j]<<' ';
			cout<<endl;//skip to new line for each row containing three columns

	}

}
void TTT::insert()//function to let player where they want to go
{
	int a;//created varaible for user
	cout << "Its player "<<player <<" Turn, "<< "pick a spot ";//instructions for player to know what to do
	cin >> a;//enter the spot players want to go in while checking if the spot is used or not
	if (a== 1  )
	{	if(board[0][0]=='1')
		board[0][0]= player  ;
	else
	{
		cout<< "Spot is taken, Pick a different spot"<<endl;
		insert();
	}
	}

	else if (a== 2 )
	{	if(board[0][1]=='2')
			board[0][1]= player  ;
		else
		{
			cout<< "Spot is taken, Pick a different spot"<<endl;
			insert();
		}
	}

	else if (a== 3 )
	{	if(board[0][2]=='3')
			board[0][2]= player  ;
		else
		{
			cout<< "Spot is taken, Pick a different spot"<<endl;
			insert();
		}
	}

	else if (a== 4 )
	{	if(board[1][0]=='4')
				board[1][0]= player  ;
			else
			{
				cout<< "Spot is taken, Pick a different spot"<<endl;
				insert();
			}
		}
	else if (a== 5 )
	{	if(board[1][1]=='5')
				board[1][1]= player  ;
			else
			{
				cout<< "Spot is taken, Pick a different spot"<<endl;
				insert();
			}
		}
	else if (a== 6 )
	{	if(board[1][2]=='6')
				board[1][2]= player  ;
			else
			{
				cout<< "Spot is taken, Pick a different spot"<<endl;
				insert();
			}
		}
	else if (a== 7 )
	{	if(board[2][0]=='7')
				board[2][0]= player  ;
			else
			{
				cout<< "Spot is taken, Pick a different spot"<<endl;
				insert();
			}
		}
	else if (a== 8 )
	{	if(board[2][1]=='8')
				board[2][1]= player  ;
			else
			{
				cout<< "Spot is taken, Pick a different spot"<<endl;
				insert();
			}
		}
	else if (a== 9 )
	{	if(board[2][2]=='9')
				board[2][2]= player  ;
			else
			{
				cout<< "Spot is taken, Pick a different spot"<<endl;
				insert();
			}
		}

}
void TTT::switchPlayer()//function to switch players
{
	if (player =='X')// when player is X change to O
	{
		player ='O';
	}
	else//when player is O change to X
		player='X';
}
char TTT:: IsWinner(){// function to see if a player has won by checking if a player has three in a row


	if (board[0][0]=='X' && board[0][1]=='X' && board[0][2]=='X' )
	{
		return 'X';

	}


	 if (board[1][0]=='X' && board[1][1]=='X' && board[1][2]=='X')
	{
		return 'X';
	}


	 if (board[2][0]=='X' && board[2][1]=='X' && board[2][2]=='X'  )
	{
		return 'X';
	}
	 if (board[0][0]=='X' && board[1][0]=='X' && board[2][0]=='X' )
	{
		return 'X';

	}
	 if (board[0][1]=='X' && board[1][1]=='X' && board[2][1]=='X')
	{
		return 'X';
	}
	 if (board[0][2]=='X' && board[1][2]=='X' && board[2][2]=='X'  )
		return 'X';

	 if (board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X' )
	{
		return 'X';

	}
	 if (board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='X')
	{
		return 'X';
	}
	 if (board[0][0]=='O' && board[0][1]=='O' && board[0][2]=='O' )
	 	{
	 		return 'O';

	 	}


	 	 if (board[1][0]=='O' && board[1][1]=='O' && board[1][2]=='O')
	 	{
	 		return 'O';
	 	}


	 	 if (board[2][0]=='O' && board[2][1]=='O' && board[2][2]=='O'  )
	 	{
	 		return 'O';
	 	}
	 	 if (board[0][0]=='O' && board[1][0]=='O' && board[2][0]=='O' )
	 	{
	 		return 'O';

	 	}
	 	 if (board[0][1]=='O' && board[1][1]=='O' && board[2][1]=='O')
	 	{
	 		return 'O';
	 	}
	 	 if (board[0][2]=='O' && board[1][2]=='O' && board[2][2]=='O'  )
	 		return 'O';

	 	 if (board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O' )
	 	{
	 		return 'O';

	 	}
	 	 if (board[0][2]=='O' && board[1][1]=='O' && board[2][0]=='O')
	 	{
	 		return 'O';
	 	}

	return '/';
}

