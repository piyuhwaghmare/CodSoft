#include<iostream>
using namespace std;

const int R = 3;
const int C = 3;

char matrix[R][C];

char Player;

void InitializeGameBoard() {
    Player = 'X';

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            matrix[i][j] = '1'+i*3+j;
        }
    }
}

void DisplayGameBoard() {
    cout<<"\n";
    for(int i=0; i<R; i++) {
        cout<<" ";
        for(int j=0; j<C; j++) {
            cout<<matrix[i][j];
            if(j < 2) {
                cout<<" | ";
            }
        }
        if(i < 2) {
            cout<<"\n-------------\n";
        }
    }

    cout<<"\n\n";
}

bool isValid(int move) {
    int row = (move-1) / 3;
    int col = (move-1) % 3;

    return matrix[row][col] != 'X' && matrix[row][col] != 'O';
}

void Makemove(int move) {
    int row = (move-1) / 3;
    int col = (move-1) % 3;
    matrix[row][col] = Player;
}

bool chkWin() {
    
    for(int i=0; i<R; i++) {
        if(matrix[i][0] == Player && matrix[i][1] == Player && matrix[i][2] == Player) {
            return true;
        }
    }

    for(int j=0; j<C; j++) {
        if(matrix[0][j] == Player && matrix[1][j] == Player && matrix[2][j] == Player) {
            return true;
        }
    }

    if(matrix[0][0] == Player && matrix[1][1] == Player && matrix[2][2] == Player) {
        return true;
    }

    if(matrix[0][2] == Player && matrix[1][1] == Player && matrix[2][0] == Player) {
        return true;
    }

    return false;
}

bool chkDraw() {
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(matrix[i][j] != 'X' || matrix[i][j] != 'O') {
                return false;
            }
        }
    }

    return true;
}

void switchPlayer() {
    Player = (Player == 'X' ? 'O' : 'X');
}

void PlayGame() {
    InitializeGameBoard();

    int move;
    bool gameover = false;

    while(!gameover) {
        DisplayGameBoard();

        cout<<"Player "<<Player<<" Enter your move (1-9)"<<endl;
        cin>>move;

        if(move < 1 || move > 9 || !isValid(move)) {
            cout<<"Enter the move from (1-9) only"<<endl;
            return;
        }

        Makemove(move);

        if(chkWin()) {
           DisplayGameBoard();
           cout<<"Player "<<Player<<" Wins"<<endl;
           gameover = true;
        }
        else if(chkDraw()) {
           DisplayGameBoard();
           cout<<"It's a Draw"<<endl;
           gameover = true;
        }
        else {
            switchPlayer();
        }
    }
}

int main() {

   char playagain;

   do {
    PlayGame();

    cout<<"If want to Play Again (Y/N)"<<endl;
    cin>>playagain;

   }while(playagain == 'Y' || playagain == 'y');
   
   cout<<"Thanks for Playing"<<endl;

    return 0;
}