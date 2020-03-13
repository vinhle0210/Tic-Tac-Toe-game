#include <iostream>
#include <cstdlib>

using namespace std;

char matrix[3][3] = { '*','*','*','*','*','*','*','*','*'};
char player1 = 'X';
char player2 = 'O';
bool Win = false;
bool player1Turn = true;
int num[50];
int index = 0;
int a;
int numTurn = 0;
char Winner;
int Check(int number);

void Draw(){
	system("cls");
	cout << "Tic Tac Toe v1.0" << endl;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void Input(char playerX){
	if (playerX == 'X'){
		cout << "Player (X) turn: ";
		cin >> a;
	}
	else if (playerX == 'O'){
		cout << "Player (O) turn: ";
		cin >> a;
	}
	a = Check(a);
	if ( a == 1){
		matrix[0][0] = playerX;
	}
	else if ( a == 2){
		matrix[0][1] = playerX;
	}
	else if ( a == 3){
		matrix[0][2] = playerX;
	}
	else if ( a == 4){
		matrix[1][0] = playerX;
	}
	else if ( a == 5){
		matrix[1][1] = playerX;
	}
	else if ( a == 6){
		matrix[1][2] = playerX;
	}
	else if ( a == 7){
		matrix[2][0] = playerX;
	}
	else if ( a == 8){
		matrix[2][1] = playerX;
	}
	else if ( a == 9){
		matrix[2][2] = playerX;
	}
	else{
		cout << "Please Enter number 1 - 9: " ;
	}
}

bool Result(char player){
	int row = 0;
	int column = 0;
	while (row++ < 3){
		if( matrix [row][0] == player && matrix [row][1] == player && matrix [row][2] == player){
			Win = true;
			Winner = player;
			
		}
	}
	while (column++ < 3){
		if( matrix [0][column] == player && matrix [1][column] == player && matrix [2][column] == player){
			Win = true;
			Winner = player;
		}
	}
	if (matrix[0][0] == player && matrix[1][1] == player && matrix [2][2] == player){
		Win = true;
		Winner = player;
	}
	if ( matrix [2][0] == player && matrix [1][1] == player && matrix [0][2] == player){
		Win = true;
		Winner = player;
	}
	return Win;
}

void TogglePlayer(){
	if (player1Turn){
		Input(player1);
	}
	else{
		Input(player2);
	}
	player1Turn = !player1Turn;
}

int Check(int number){
	int i = index;
	while ( i >= 0){
		if( num[i] == number){
			cout << "Please choose a different number: ";
			cin >> number;
			i = index + 1;
		}
		i--;
	}
	num[index++] = number;
	return number;
}

int main(){
    Draw();
    while (!Win)
    {
        TogglePlayer();
        Draw();
		numTurn++;
		if(Result(player1) || Result(player2)){
			cout << "Player " << Winner << " Win!" << endl;
		}
		else if(numTurn == 9 && !Result(player1)&& !Result(player2)){
			cout << "Draw!" << endl ;
			break;
		}	
    }
    system("pause");
    return 0;
}