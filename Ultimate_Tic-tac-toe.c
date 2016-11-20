#include "Ultimate_Tic-tac-toe.h"

int main(int argc, char const *argv[])
	{
		while (counter)
			runProgram();
		return 0;
	}
	
void runProgram()
	{
		printf("\n\n\n\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf(":::::::::::::::::::::::::::: UTLIMATE TIC TAC TOE ::::::::::::::::::::::::::::::\n");
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf("\n\n\tSelect from the following Options:\n\t1. Play Ultimate Tac-Tac-Toe (2 players)\n\t2. Read the rules\n\t3. Quit Game\n\t\t\t\t\t     Your option<1, 2 or 3>:");
		int option;
		scanf("%d",&option);
		if (option==3)
		{
			counter = 0;
			exit(0);	
		}
		else if (option==1)
		{
			printf("\n\nEnter Player 1 Name (Max. 10 letters): ");
			scanf("%s",Player1); printf("Welcome, %s!!!\n",Player1);

			printf("\nEnter Player 2 Name (Max. 10 letters): ");
			scanf("%s",Player2); printf("Welcome, %s!!!\n\n",Player2);

			initialize_to_zero();

			display_game();
			printf("\n\t\t\t\tLets Begin!!!\n");

			printf("\n%s gets to choose the first board.\n\nChoose board <row:0,1or2><space><column:0,1or2>: ",Player1);
			scanf("%d %d",&act_row,&act_col);

			while(1)
			{
				if (game_full()) {
					display_game();
					printf("Match is a draw!!!!\n\n");
					break;
				}
				else {								
					if (in_charge==1)
						printf("\n%s's turn....\n",Player1);
					else if (in_charge==2)
						printf("\n%s's turn....\n",Player2);

					while (array_full(act_row,act_col)){
						if (in_charge==1)
							printf("board [%d][%d] is full!!\n%s gets to choose the new board.\nChoose board <row><space><column>: ",act_row,act_col,Player1);
						else if (in_charge==2)
							printf("board [%d][%d] is full!!\n%s gets to choose the new board.\nChoose board <row><space><column>: ",act_row,act_col,Player2);
					scanf("%d %d",&act_row,&act_col);}

					input_n_newtile(in_charge);
					// display_game();
					turntable();
				}
			}
		}
		else if (option==2) {
			system("cls");
			system("start http://mathwithbaddrawings.com/2013/06/16/ultimate-tic-tac-toe/");}
	}

void initialize_to_zero()
	{
		int i,j,k,l;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				game[i][j].sign=0;
				for (k = 0; k < 3; k++)
				{
					for (l = 0; l < 3; l++)
					{
						game[i][j].array[k][l]=0;
					}
				}
			}
		}
	}

void turntable() 
	{
		if (in_charge==1)
			in_charge=2;
		else 
			in_charge=1;
	}

void display_game()
	{
		system("cls");

		printf("\n\t\t\t\tDisplaying table:\n\n");
		printf("\t\t------------------------------------------------\n");
		printf("\t\t  %c   %c   %c    |    %c   %c   %c   |    %c   %c   %c\n",charactify(game[0][0].array[0][0]),charactify(game[0][0].array[0][1]),charactify(game[0][0].array[0][2]),charactify(game[0][1].array[0][0]),charactify(game[0][1].array[0][1]),charactify(game[0][1].array[0][2]),charactify(game[0][2].array[0][0]),charactify(game[0][2].array[0][1]),charactify(game[0][2].array[0][2]));
		printf("\t\t  %c   %c   %c    |    %c   %c   %c   |    %c   %c   %c\n",charactify(game[0][0].array[1][0]),charactify(game[0][0].array[1][1]),charactify(game[0][0].array[1][2]),charactify(game[0][1].array[1][0]),charactify(game[0][1].array[1][1]),charactify(game[0][1].array[1][2]),charactify(game[0][2].array[1][0]),charactify(game[0][2].array[1][1]),charactify(game[0][2].array[1][2]));
		printf("\t\t  %c   %c   %c    |    %c   %c   %c   |    %c   %c   %c\n",charactify(game[0][0].array[2][0]),charactify(game[0][0].array[2][1]),charactify(game[0][0].array[2][2]),charactify(game[0][1].array[2][0]),charactify(game[0][1].array[2][1]),charactify(game[0][1].array[2][2]),charactify(game[0][2].array[2][0]),charactify(game[0][2].array[2][1]),charactify(game[0][2].array[2][2]));
		printf("\t\t------------------------------------------------\n");

		printf("\t\t  %c   %c   %c    |    %c   %c   %c   |    %c   %c   %c\n",charactify(game[1][0].array[0][0]),charactify(game[1][0].array[0][1]),charactify(game[1][0].array[0][2]),charactify(game[1][1].array[0][0]),charactify(game[1][1].array[0][1]),charactify(game[1][1].array[0][2]),charactify(game[1][2].array[0][0]),charactify(game[1][2].array[0][1]),charactify(game[1][2].array[0][2]));
		printf("\t\t  %c   %c   %c    |    %c   %c   %c   |    %c   %c   %c\n",charactify(game[1][0].array[1][0]),charactify(game[1][0].array[1][1]),charactify(game[1][0].array[1][2]),charactify(game[1][1].array[1][0]),charactify(game[1][1].array[1][1]),charactify(game[1][1].array[1][2]),charactify(game[1][2].array[1][0]),charactify(game[1][2].array[1][1]),charactify(game[1][2].array[1][2]));
		printf("\t\t  %c   %c   %c    |    %c   %c   %c   |    %c   %c   %c\n",charactify(game[1][0].array[2][0]),charactify(game[1][0].array[2][1]),charactify(game[1][0].array[2][2]),charactify(game[1][1].array[2][0]),charactify(game[1][1].array[2][1]),charactify(game[1][1].array[2][2]),charactify(game[1][2].array[2][0]),charactify(game[1][2].array[2][1]),charactify(game[1][2].array[2][2]));
		printf("\t\t------------------------------------------------\n");

		printf("\t\t  %c   %c   %c    |    %c   %c   %c   |    %c   %c   %c\n",charactify(game[2][0].array[0][0]),charactify(game[2][0].array[0][1]),charactify(game[2][0].array[0][2]),charactify(game[2][1].array[0][0]),charactify(game[2][1].array[0][1]),charactify(game[2][1].array[0][2]),charactify(game[2][2].array[0][0]),charactify(game[2][2].array[0][1]),charactify(game[2][2].array[0][2]));
		printf("\t\t  %c   %c   %c    |    %c   %c   %c   |    %c   %c   %c\n",charactify(game[2][0].array[1][0]),charactify(game[2][0].array[1][1]),charactify(game[2][0].array[1][2]),charactify(game[2][1].array[1][0]),charactify(game[2][1].array[1][1]),charactify(game[2][1].array[1][2]),charactify(game[2][2].array[1][0]),charactify(game[2][2].array[1][1]),charactify(game[2][2].array[1][2]));
		printf("\t\t  %c   %c   %c    |    %c   %c   %c   |    %c   %c   %c\n",charactify(game[2][0].array[2][0]),charactify(game[2][0].array[2][1]),charactify(game[2][0].array[2][2]),charactify(game[2][1].array[2][0]),charactify(game[2][1].array[2][1]),charactify(game[2][1].array[2][2]),charactify(game[2][2].array[2][0]),charactify(game[2][2].array[2][1]),charactify(game[2][2].array[2][2]));
		printf("\t\t------------------------------------------------\n\n");
	}

int checkwin_game(int y)
	{
		if (
			((game[0][0].sign==y)&&(game[0][1].sign==y)&&(game[0][2].sign==y))||
			((game[1][0].sign==y)&&(game[1][1].sign==y)&&(game[1][2].sign==y))||
			((game[2][0].sign==y)&&(game[2][1].sign==y)&&(game[2][2].sign==y))||
			((game[0][0].sign==y)&&(game[1][0].sign==y)&&(game[2][0].sign==y))||
			((game[0][1].sign==y)&&(game[1][1].sign==y)&&(game[2][1].sign==y))||
			((game[0][2].sign==y)&&(game[1][2].sign==y)&&(game[2][2].sign==y))||
			((game[0][0].sign==y)&&(game[1][1].sign==y)&&(game[2][2].sign==y))||
			((game[2][0].sign==y)&&(game[1][1].sign==y)&&(game[0][2].sign==y))
			)
		{
			return 1;
		}
		else
			return 0;
	}

char charactify(int x)
	{
		if (x==0)
			return 45;
		else if (x==1)
			return 88;
		else if (x==2)
			return 79;
	}

int checkwin(int a,int b,int y)
	{
		if (
			((game[a][b].array[0][0]==y)&&(game[a][b].array[0][1]==y)&&(game[a][b].array[0][2]==y))||
			((game[a][b].array[1][0]==y)&&(game[a][b].array[1][1]==y)&&(game[a][b].array[1][2]==y))||
			((game[a][b].array[2][0]==y)&&(game[a][b].array[2][1]==y)&&(game[a][b].array[2][2]==y))||
			((game[a][b].array[0][0]==y)&&(game[a][b].array[1][0]==y)&&(game[a][b].array[2][0]==y))||
			((game[a][b].array[0][1]==y)&&(game[a][b].array[1][1]==y)&&(game[a][b].array[2][1]==y))||
			((game[a][b].array[0][2]==y)&&(game[a][b].array[1][2]==y)&&(game[a][b].array[2][2]==y))||
			((game[a][b].array[0][0]==y)&&(game[a][b].array[1][1]==y)&&(game[a][b].array[2][2]==y))||
			((game[a][b].array[2][0]==y)&&(game[a][b].array[1][1]==y)&&(game[a][b].array[0][2]==y))
			)
		{
			game[a][b].sign=y;
			return 1;
		}
		else
			return 0;
	}

int array_full(int x,int y)
	{
		int l;
		for (l = 3; l >= 1; l--)
			{
				int p;
				for (p = 3; p >= 1; p--)
					{
						if (game[x][y].array[p-1][l-1]==0)
						return 0;
					}
			}
		return 1;
	}

int game_full()
	{
		int x,y;
		for (x= 0; x < 3; x++)
		{
			for (y= 0; y < 3; y++)
			{
				if (array_full(x,y)!=1)
					return 0;
			}
		}
		return 1;
	}
 
void input_n_newtile(int s) 
	{
		int array_row,array_col;

		printf("\nEnter your location for game[%d][%d] (<row> <column>):",act_row,act_col);
		scanf("%d %d",&array_row,&array_col);
		
		if ( ( (array_row>=0)&&(array_row<=2) ) && ( (array_col>=0)&&(array_col<=2) ) )
		{
			if (game[act_row][act_col].array[array_row][array_col]==0)
			{	
				game[act_row][act_col].array[array_row][array_col] = s;
				if (!(game[act_row][act_col].sign))
				{	
					if (checkwin(act_row,act_col,s))	
						game[act_row][act_col].sign = s;

					// display_game();

					if (game[act_row][act_col].sign == 1)
						{printf("\n\n%s owns board[%d][%d]!!!\n",Player1,act_row,act_col);}
					else if (game[act_row][act_col].sign == 2)
						{printf("\n\n%s owns board[%d][%d]!!!\n",Player2,act_row,act_col);}

					if (checkwin_game(s))
					{
						if (s==1)
							printf("\n\n%s wins!!!!!\n\n",Player1);
						else if (s==2)
							printf("\n\n%s wins!!!!!\n\n",Player2);
						// int out=restartProgram();
						exit(0);
					}
				}
				display_game();
				change_act(array_row,array_col);
			}
			else {
				printf("\n\nOye!! dekhke khel!!!!\n");
				printf("\nRe-enter your move..........\n");
		    	input_n_newtile(s);
		    }
		}
		else
		{
			printf("\n\nInsert correct grid location\n");
			input_n_newtile(s);
		}
	}

void change_act(int a, int b) 
	{
		act_row=a;
		act_col=b;
		printf("\nActive board is game[%d][%d]\n",act_row,act_col);
	}
