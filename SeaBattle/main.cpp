#include <iostream>
#include <cmath>
using namespace std;

void enterNextPlayer(){
    string str;
    cout << "Press enter for the next move.";
    getline(cin, str);
}

void initSeaSpace(char seaSpace[][10][10]) {
    for(int i = 0; i < 4; ++i){
        for(int j =0; j < 10; ++j){
            for(int k = 0; k < 10; ++k){
                seaSpace[i][j][k] = ' ';
            }
        }
    }
}

int CheckingWings(char seaSpace[][10][10], int player){
    int sumX = 0;
    for(int j =0; j < 10; ++j){
        for(int k = 0; k < 10; ++k){
            if(seaSpace[(player==1)? 2:3][j][k] == 'X')
                ++sumX;
        }
    }
    return sumX;
}

void showSeaSpace(char seaSpace[][10][10], int player){
    system("cls");
    cout << "  -=Played by player " << ((player==0 || player ==2)? 1 : 2) << "=-" << "\n";
    for(int i = 0; i < 11; ++i){
        for(int j = 0; j < 12; ++j){
            if(i == 0 && j < 1) cout << "  ";
            if(i == 0 && j > 1){
                cout << j - 2 << " ";
            }
            if(i>=1 && j>=1 && j<=10){
                cout << seaSpace [player][i-1][j-1] << " ";
            }
        }
        if(i>=0 && i<=9) cout << "\n" << i << " ";
    }
    cout << "\n";
}

int setSheep(char seaSpace[][10][10],int player,int row, int col) {
    if(!((row>=0 && row <= 9) && (col >=0 && col <=9))) return 1;
    if(seaSpace[player][row][col]!=' ') return 2;
    seaSpace[player][row][col] = '#';
    return 0;
}

int setSheep(char seaSpace[][10][10], int player, int rowOne, int rowTwo, int colOne, int colTwo, int size){
    if(!((rowOne>=0 && rowOne <= 9) && (colOne >=0 && colOne <=9))) return 1;
    if(!((rowTwo>=0 && rowTwo <= 9) && (colTwo >=0 && colTwo <=9))) return 1;
    if(rowOne!=rowTwo && colOne != colTwo) return 3;
    if(rowOne == rowTwo) {
        if(abs(colOne-colTwo) != size-1) return 4;
        if(colOne>colTwo) {int temp =colOne; colOne = colTwo; colTwo=temp;}
    }else{
        if(abs(rowOne-rowTwo) != size-1) return 4;
        if(rowOne>rowTwo) {int temp =rowOne; rowOne = rowTwo; rowTwo=temp;}
    }
    for(int i = rowOne; i <= rowTwo; ++i){
        for(int j = colOne; j <= colTwo; ++j){
            if(seaSpace[player][i][j]!=' ') return 2;
        }
    }
    for(int i = rowOne; i <= rowTwo; ++i) {
        for(int j = colOne; j <= colTwo; ++j) {
            seaSpace[player][i][j]='#';
        }
    }
    return 0;
}


void playerPlaces(char seaSpace[][10][10], int player) {
    int rowOne, rowTwo, colOne, colTwo, refund;
    showSeaSpace(seaSpace, player-1);
    for(int i = 1; i < 5; ++i) {
        cout << "We place four single-deck ships (#).\n";
        cout << "Install " << i << " ship out of 4.\n";
        do{
            cout << "Enter the x and y coordinates: ";
            cin >> rowOne >> colOne;
            refund = setSheep(seaSpace, player-1, rowOne, colOne);
            if(refund == 1) {
                cout<<"Invalid coordinates, please try again.\n";
            }else if(refund == 2) {
                cout<<"There is already a ship here, try again.\n";
            }
        }while(refund != 0);
        showSeaSpace(seaSpace, player-1);
    }

    for(int i = 1; i < 4; ++i){
        cout << "We place three two-deck ships (##).\n";
        cout << "Install " << i << " ship out of 3.\n";
        do{
            cout << "Enter the start x and start y coordinates: ";
            cin >> rowOne >> colOne;
            cout <<"Enter the end x and end y coordinates: ";
            cin >> rowTwo >> colTwo;
            refund = setSheep(seaSpace, player-1, rowOne, rowTwo, colOne, colTwo, 2);
            if(refund == 1){
                cout<<"Invalid coordinates, please try again.\n";
            }else if(refund == 2){
                cout<<"There is already a ship here, try again.\n";
            }else if(refund == 3){
                cout<<"You can't place it diagonally, so try again.\n";
            }else if(refund == 4){
                cout<<"The ship size is set incorrectly, so try again.\n";
            }
        }while(refund != 0);
        showSeaSpace(seaSpace, player-1);
    }
    for(int i = 1; i < 3; ++i) {
        cout << "We place two three-deck ships (###).\n";
        cout << "Install " << i << " ship out of 2.\n";
        do{
            cout << "Enter the start x and start y coordinates: ";
            cin >> rowOne >> colOne;
            cout << "Enter the end x and end y coordinates: ";
            cin >> rowTwo >> colTwo;
            refund = setSheep(seaSpace, player-1, rowOne, rowTwo, colOne, colTwo, 3);
            if(refund == 1){
                cout<<"Invalid coordinates, please try again.\n";
            }else if(refund == 2){
                cout<<"There is already a ship here, try again.\n";
            }else if(refund == 3){
                cout<<"You can't place it diagonally, so try again.\n";
            }else if(refund == 4){
                cout<<"The ship size is set incorrectly, so try again.\n";
            }
        }while(refund != 0);
        showSeaSpace(seaSpace, player-1);
    }
    for(int i = 1; i < 2; ++i){
        cout << "We place one four-deck ships (####).\n";
        cout << "Install " << i << " ship out of 1.\n";
        do{
            cout << "Enter the start x and start y coordinates: ";
            cin >> rowOne >> colOne;
            cout << "Enter the end x and end y coordinates: ";
            cin >> rowTwo >> colTwo;
            refund = setSheep(seaSpace, player-1, rowOne, rowTwo, colOne, colTwo, 4);
            if(refund == 1){
                cout<<"Invalid coordinates, please try again.\n";
            }else if(refund == 2){
                cout<<"There is already a ship here, try again.\n";
            }else if(refund == 3){
                cout<<"You can't place it diagonally, so try again.\n";
            }else if(refund == 4){
                cout<<"The ship size is set incorrectly, so try again.\n";
            }
        }while(refund != 0);
        showSeaSpace(seaSpace, player-1);
    }
}

bool shot(char seaSpace[][10][10], int player){
    int x, y;
    showSeaSpace(seaSpace,(player==1)? 2:3);
    cout << "Player " << player << " shot" << "\n";
    cout << "Enter the x, y coordinates for the shot: ";
    cin >> x >> y;
    while(!((x>=0 && x <= 9) && (y >=0 && y <= 9))){
        cout<<"Invalid coordinates try again: ";
        cin >> x >> y;
    }

    bool hit = false;
    if(seaSpace[(player==1)? 1:0][x][y] == ' '){
        seaSpace[(player==1)? 2:3][x][y] = '*';
        hit = false;
    }else{
        seaSpace[(player==1)? 2:3][x][y] = 'X';
        hit = true;
    }
    showSeaSpace(seaSpace,(player==1)? 2:3);
    cout << ((hit)? "The shot hit the target" : "The shot missed its target") << "\n";
    enterNextPlayer();
    return hit;
}


int main() {
    char seaSpace[4][10][10];
    initSeaSpace(seaSpace);
    int player, x, y;
    do {
        system("clear");
        cout << "-= Sea Battle =-" << "\n";
        cout << "(1) The first player places the ships" << "\n";
        cout << "(2) The second player places the ships" << "\n";
        cout << "Please select a player:";
        cin >> player;
    }while(player != 1 && player != 2);

    playerPlaces(seaSpace, player);
    enterNextPlayer();
    playerPlaces(seaSpace, (player==1)? 2:1);
    enterNextPlayer();
    int win = 0;
    while(win != 20){
        bool hit = true;
        while(hit){
            hit = shot(seaSpace, player);
            win = CheckingWings(seaSpace, player);
        }
        if(win !=20){
            if(player == 1){
                player = 2;
            }else {
                player = 1;
            }
        }
    }
    cout << "Win, the player " << player << " won" << "\n";
}