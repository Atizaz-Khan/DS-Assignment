#include<iostream>
#include<stdlib.h>

using namespace std;
class tictac{
    private:
    char board[3][3];
    char player1 = '2', player2 = '1';

    class Move{
        public:
        int row,col;
        };

    public:
        tictac(){
            for (int i = 0; i < 3; i++) {
                        for(int j=0;j<3;j++)
                        {
                            cin>>board[i][j];
                        } 
            }
            if(isvalid()){	
            while(gamecomplete()){
            if(board[0][0]=='2'&&board[1][1]!='1')
            check();
			Move bestMove1 = FINDBESTPOSSIBILITY();
            board[bestMove1.row][bestMove1.col]='1';
            Move bestMove2 = FINDBESTPOSSIBILITY();
            board[bestMove2.row][bestMove2.col]='2';
                    
            }
            cout<<ifsomeonewins();
        }
        else{
            cout<<-1;
        }

        }
	
        bool gamecomplete()
        {
            for (int i = 0; i<3; i++)
                for (int j = 0; j<3; j++)
                    if (board[i][j]=='0')
                        return true;
            return false;
        }

        int ifsomeonewins()
        {
            for (int row = 0; row<3; row++)
            {
                if (board[row][0]==board[row][1] && board[row][1]==board[row][2])
                {
                    if (board[row][0]==player1)
                        return 1;
                    else if (board[row][0]==player2)
                        return 2;
                }
            }

            for (int col = 0; col<3; col++)
            {
                if (board[0][col]==board[1][col] && board[1][col]==board[2][col])
                {
                    if (board[0][col]==player1)
                        return 1;
                    else if (board[0][col]==player2)
                        return 2;
                }
            }

            if (board[0][0]==board[1][1] && board[1][1]==board[2][2])
            {
                if (board[0][0]==player1)
                    return 1;
                else if (board[0][0]==player2)
                    return 2;
            }

            if (board[0][2]==board[1][1] && board[1][1]==board[2][0])
            {
                if (board[0][2]==player1)
                    return 1;
                else if (board[0][2]==player2)
                    return 2;
            }

            return 0;
        }
		void check(){
			cout<<2;
			exit(0);
		}
        int possibilities(int travarse, bool isMax)
        {


            if (gamecomplete()==false)
                return 0;

            if (isMax)
            {
                int best_possibility = -9999;

                for (int i = 0; i<3; i++)
                {
                    for (int j = 0; j<3; j++)
                    {
                        if (board[i][j]=='0')
                        {
                            board[i][j] = player1;
                            best_possibility = max( best_possibility,possibilities(travarse+1, !isMax) );
                            board[i][j] = '0';
                        }
                    }
                }
                return best_possibility;
            }

            else
            {
                int best_possibility = 9999;

                for (int i = 0; i<3; i++)
                {
                    for (int j = 0; j<3; j++)
                    {
                        if (board[i][j]=='0')
                        {
                            board[i][j] = player2;

                            best_possibility = min(best_possibility,possibilities(travarse+1, !isMax));

                            board[i][j] = '0';
                        }
                    }
                }
                return best_possibility;
            }
        }

        Move FINDBESTPOSSIBILITY()
        {
            int score = -1000;
            Move BESTPOSSIBILITY;
            BESTPOSSIBILITY.row = -1;
            BESTPOSSIBILITY.col = -1;

            for (int i = 0; i<3; i++)
            {
                for (int j = 0; j<3; j++)
                {
                    if (board[i][j]=='0')
                    {
                        board[i][j] = player1;

                        int moveVal = possibilities(0, false);

                        board[i][j] = '0';

                        if (moveVal > score)
                        {
                            BESTPOSSIBILITY.row = i;
                            BESTPOSSIBILITY.col = j;
                            score = moveVal;
                        }
                    }
                }
            }



            return BESTPOSSIBILITY;
        }



    int isvalid(){
        int ones=0,tows=0;
        for (int i = 0; i < 3; i++) {
        	
            for(int j=0;j<3;j++)
            {
            	
            	
                if(board[i][j]=='1')
                 ones++;
                else if(board[i][j]=='2')
                 tows++;
            } 
        }
       	if(ones==0&&tows==0)
		return 0;
        if(ones>tows+1)
        return 0;
        if(tows>ones+1)
        return 0;
        return 1;
}
};

int main()
{
	tictac t1;
	return 0;
}
