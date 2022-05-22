#include <stdio.h>
#include <string.h>
#include <math.h>


char positionsOccupied[65] = {' ','O',' ','O',' ','O',' ','O',' ',' ','O',' ','O',' ','O',' ','O','O',' ','O',' ','O',' ','O',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ','X',' ','X',' ','X','X',' ','X',' ','X',' ','X',' ',' ','X',' ','X',' ','X',' ','X'};
int playerOnePositions[65] = {0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int playerTwoPositions[65] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1};	int loopConditionOne = 1, loopConditionTwo = 1;
int signBits[65] = {1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0};
int kingBits[65] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int boundaryPositions[48] = {0,1,9,17,25,33,41,49,57,58,59,60,61,62,63,64,56,48,40,32,24,16,8,7,6,5,4,3,2};///interestingly, the difference between the vertical numbers is 8, and 1 for horizontal.
int playerOneScore = 12, playerTwoScore = 12;
int oldPos;
int newPos;
int newPosTwo;
int selectedPos;
int i = 1;
int checkForJumpsInvoked;
int main () {
	int skippedPositionForward, positionDeltaForward;
	float skippedPositionForwardFloat;
	int signSum;
	printf("poop: %i", boundaryPositions[1]);
	while (loopConditionOne == 1) {
		while (loopConditionTwo == 1 && playerTwoScore > 0) {
			getPositionPlayerOne();
			playerOneCheckForJumps();
			positionDeltaForward = (newPos - oldPos);
			skippedPositionForward = (newPos - (positionDeltaForward/2));
			skippedPositionForwardFloat = (newPos-(positionDeltaForward/2));
			signSum = signBits[oldPos] + signBits[newPos];
			if (positionDeltaForward == 18 && signSum != 1 && playerTwoPositions[newPos] == 0 && playerTwoPositions[newPos] == 0 && playerOnePositions[oldPos] == 1 && playerOnePositions[newPos] == 0) {///Lets go light on the logic right now. get the simple conditions working
				moveChipPlayerOne();
				playerOneKingOnEdge();
				playerOneCheckForJumps();
				playerOneScoreUpdate();
				stealPlayerTwosChip();
				kingPlayerOne();
				winningConditionsCheck();
				loopConditionTwo = 2;
			}
			else if (positionDeltaForward == 14 && signSum != 1 && playerTwoPositions[newPos] == 0 && playerTwoPositions[newPos] == 0 && playerOnePositions[oldPos] == 1 && playerOnePositions[newPos] == 0) {
				moveChipPlayerOne();
				playerOneKingOnEdge();
				playerOneCheckForJumps();
				playerOneScoreUpdate();
				stealPlayerTwosChip();
				kingPlayerOne();
				winningConditionsCheck();
				loopConditionTwo = 2;
			}
			else if (positionDeltaForward == -18 && signSum != 1 && playerTwoPositions[newPos] == 0 && playerTwoPositions[newPos] == 0 && playerOnePositions[oldPos] == 1 && playerOnePositions[newPos] == 0 && kingBits[oldPos] == 1) {
				moveChipPlayerOne();
				playerOneKingOnEdge();
				playerOneCheckForJumps();
				playerOneScoreUpdate();
				stealPlayerTwosChip();
				kingPlayerOne();
				winningConditionsCheck();
				loopConditionTwo = 2;
			}
			else if (positionDeltaForward == -14 && signSum != 1 && playerTwoPositions[newPos] == 0 && playerTwoPositions[newPos] == 0 && playerOnePositions[oldPos] == 1 && playerOnePositions[newPos] == 0  && kingBits[oldPos] == 1) {
				moveChipPlayerOne();
				playerOneKingOnEdge();
				playerOneCheckForJumps();
				playerOneScoreUpdate();
				stealPlayerTwosChip();
				kingPlayerOne();
				winningConditionsCheck();
				loopConditionTwo = 2;
			}
			else if (positionDeltaForward == 9 && signSum == 1 && playerTwoPositions[newPos] == 0 && playerTwoPositions[newPos] == 0 && playerOnePositions[oldPos] == 1 && playerOnePositions[newPos] == 0) {
				moveChipPlayerOne();
				playerOneKingOnEdge();
				playerOneCheckForJumps();
				printBoard();
				loopConditionTwo = 2;
			}
			else if (positionDeltaForward == 7 && signSum == 1 && playerTwoPositions[newPos] == 0 && playerTwoPositions[newPos] == 0 && playerOnePositions[oldPos] == 1 && playerOnePositions[newPos] == 0) {
				playerOneKingOnEdge();
				moveChipPlayerOne();
				playerOneCheckForJumps();
				printBoard();
				loopConditionTwo = 2;
			}
			else if (positionDeltaForward == -9 && signSum == 1 && playerTwoPositions[newPos] == 0 && playerTwoPositions[newPos] == 0 && playerOnePositions[oldPos] == 1 && playerOnePositions[newPos] == 0 && kingBits[oldPos] == 1) {
				moveChipPlayerOne();
				playerOneKingOnEdge();
				playerOneCheckForJumps();;
				printBoard();
				loopConditionTwo = 2;
			}
			else if (positionDeltaForward == -7 && signSum == 1 && playerTwoPositions[newPos] == 0 && playerTwoPositions[newPos] == 0 && playerOnePositions[oldPos] == 1 && playerOnePositions[newPos] == 0  && kingBits[oldPos] == 1) {
				playerOneKingOnEdge();
				moveChipPlayerOne();
				playerOneCheckForJumps();
				printBoard();
				loopConditionTwo = 2;
			}
			else {
				printf("\nError");
				printf("\npositiondeltaforward: %i", positionDeltaForward);
				printf("\nsignSum: %i", signSum);
				printf("\nplayerTwoPositions[newPos]: %i", playerTwoPositions[newPos]);
				printf("\nplayerOnePosition[oldPos]: %i", playerOnePositions[oldPos]);
				printf("\nplayerOnePositions[newPos]: %i", playerOnePositions[newPos]);

			}
		}
		while (loopConditionTwo == 2) {
			getPositionPlayerTwo();
			playerTwoCheckForJumps();
			positionDeltaForward = (newPos - oldPos);
			skippedPositionForward = (newPos - (positionDeltaForward/2));
			skippedPositionForwardFloat = (newPos-(positionDeltaForward/2));
			signSum = signBits[oldPos] + signBits[newPos];
			if (positionDeltaForward == 18 && signSum != 1 && playerTwoPositions[newPos] == 0 && playerTwoPositions[oldPos] == 1 && playerOnePositions[newPos] == 0) {///Lets go light on the logic right now. get the simple conditions workingz
				moveChipPlayerTwo();
				playerTwoKingOnEdge();
				playerTwoCheckForJumps();
				printf("Chip Stolen!");
				playerTwoScoreUpdate();
				stealPlayerOnesChip();
				kingPlayerTwo();
				winningConditionsCheck();
				loopConditionTwo = 1;
				}	
			else if (positionDeltaForward == 14 && signSum != 1 && playerTwoPositions[newPos] == 0 && playerTwoPositions[oldPos] == 1 && playerOnePositions[newPos] == 0) {
				moveChipPlayerTwo();
				playerTwoKingOnEdge();
				playerTwoCheckForJumps();
				printf("Chip Stolen!");
				playerTwoScoreUpdate();
				stealPlayerOnesChip();
				kingPlayerTwo();
				winningConditionsCheck();
				loopConditionTwo = 1;	
			}	
			else if (positionDeltaForward == -18 && signSum != 1 && playerTwoPositions[newPos] == 0 && playerTwoPositions[oldPos] == 1 && playerOnePositions[newPos] == 0) {
				moveChipPlayerTwo();
				playerTwoKingOnEdge();
				playerTwoCheckForJumps();
				printf("Chip Stolen!");
				playerTwoScoreUpdate();
				stealPlayerOnesChip();
				kingPlayerTwo();
				winningConditionsCheck();
				loopConditionTwo = 1;
			}	
			else if (positionDeltaForward == -14 && signSum != 1 && playerTwoPositions[newPos] == 0 && playerTwoPositions[oldPos] == 1 && playerOnePositions[newPos] == 0) {
				moveChipPlayerTwo();
				playerTwoKingOnEdge();
				playerTwoCheckForJumps();
				printf("Chip Stolen!");
				playerTwoScoreUpdate();
				stealPlayerOnesChip();
				kingPlayerTwo();
				winningConditionsCheck();
				loopConditionTwo = 2;
			}	
			else if (positionDeltaForward == 9 && signSum == 1 && playerTwoPositions[newPos] == 0 && playerTwoPositions[oldPos] == 1 && playerOnePositions[newPos] == 0) {
				moveChipPlayerTwo();
				playerTwoKingOnEdge();
				playerTwoCheckForJumps();
				printBoard();
				loopConditionTwo = 1;
			}
			else if (positionDeltaForward == 7 && signSum == 1 && playerTwoPositions[newPos] == 0 && playerTwoPositions[oldPos] == 1 && playerOnePositions[newPos] == 0) {
				moveChipPlayerTwo();
				playerTwoKingOnEdge();
				playerTwoCheckForJumps();
				printBoard();
				loopConditionTwo = 1;
			}
			else if (positionDeltaForward == -9 && signSum == 1 && playerTwoPositions[newPos] == 0 && playerTwoPositions[oldPos] == 1 && playerOnePositions[newPos] == 0 && kingBits[oldPos] != 1) {
				moveChipPlayerTwo();
				playerTwoKingOnEdge();
				playerTwoCheckForJumps();
				printBoard();
				loopConditionTwo = 1;
			}
			else if (positionDeltaForward == -7 && signSum == 1 && playerTwoPositions[newPos] == 0 && playerTwoPositions[oldPos] == 1 && playerOnePositions[newPos] == 0 && kingBits[oldPos] != 1) {
				moveChipPlayerTwo();
				playerTwoKingOnEdge();
				playerTwoCheckForJumps();
				printBoard();
				loopConditionTwo = 1;	
			}
			else {
				printf("Error\n");
			}
		}
		
	}
	return 0;
}

void moveChipPlayerOne() {
	int positionDeltaForward = (newPos - oldPos);
	int skippedPositionForward = (newPos - (positionDeltaForward/2));
	if (ceilf(positionDeltaForward/2) == (positionDeltaForward/2)); {
		playerTwoPositions[skippedPositionForward] = 0;
		positionsOccupied[skippedPositionForward] = ' ';
		kingBits[skippedPositionForward] = 0;
	}
	playerOnePositions[oldPos] = 0;
	playerOnePositions[newPos] = 1;
	positionsOccupied[newPos] = positionsOccupied[oldPos];
	positionsOccupied[oldPos] = ' ';
}

void moveChipPlayerTwo() {// movechipplayertwo and movechiplayer one needs consolidating, i think its only possible to call it when skippedposforward is an int
	int positionDeltaForward = (newPos - oldPos);
	int skippedPositionForward = (newPos - (positionDeltaForward/2));
	if (ceilf(positionDeltaForward/2) == (positionDeltaForward/2)); {
		playerOnePositions[skippedPositionForward] = 0;
		positionsOccupied[skippedPositionForward] = ' ';
		kingBits[skippedPositionForward] = 0;
	}
	playerTwoPositions[oldPos] = 0;
	playerTwoPositions[newPos] = 1;
	positionsOccupied[newPos] = positionsOccupied[oldPos];
	positionsOccupied[oldPos] = ' ';
}

void getPositionPlayerTwo() {
	printf("Player Two, Enter a chip to move. ");
	scanf("%i", &oldPos);
	printf("Player Two, Enter a new position. ");
	scanf("%i", &newPos);
}

void getPositionPlayerOne() {
	printf("Player One, Enter a chip to move. ");
	scanf("%i", &oldPos);
	printf("Player One, Enter a new position. ");
	scanf("%i", &newPos);
}

void stealPlayerOnesChip() {
	int positionDeltaForward;
	int skippedPositionForward;
	positionDeltaForward = (newPos - oldPos);
	skippedPositionForward = (newPos - (positionDeltaForward/2));
	double skippedPositionForwardFloat = (newPos-(positionDeltaForward/2));

	if (kingBits[skippedPositionForward] == 0) {
		printf("stealPlayerTwosChip invoked!");
		playerOnePositions[selectedPos] = 0;
		positionsOccupied[selectedPos] = ' ';
		positionsOccupied[skippedPositionForward] = ' ';
		playerOnePositions[skippedPositionForward] = 0;
		positionsOccupied[newPos] = '$';////Overwriting from moveChipPlayerX, fix later
		kingBits[newPos] = 1;
		printf("\nChip given up.");
		printBoard();
	if (kingBits[skippedPositionForward] == 1){
		printf("stealPlayerTwosChip invoked! case 2");
		positionsOccupied[selectedPos] = ' ';
		positionsOccupied[skippedPositionForward] = ' ';
		playerOnePositions[skippedPositionForward] = 0;
		positionsOccupied[newPos] = '$';////Overwriting from moveChipPlayerX, fix later
		kingBits[newPos] = 1;
		printf("\nChip given up.");
		printBoard();
	}
	}
	}
	
void stealPlayerTwosChip() {
	int positionDeltaForward;
	int skippedPositionForward;
	positionDeltaForward = (newPos - oldPos);
	skippedPositionForward = (newPos - (positionDeltaForward/2));
	double skippedPositionForwardFloat = (newPos-(positionDeltaForward/2));
	if (kingBits[skippedPositionForward] == 0) {
		printf("\nstealPlayerTwosChip invoked!");
		playerTwoPositions[selectedPos] = 0;
		positionsOccupied[selectedPos] = ' ';
		positionsOccupied[skippedPositionForward] = ' ';
		playerTwoPositions[skippedPositionForward] = 0;
		positionsOccupied[newPos] = 'K';////Overwriting from moveChipPlayerX, fix later
		kingBits[newPos] = 1;
		printf("\nChip given up.");
		printBoard();
	if (kingBits[skippedPositionForward] == 1){
		printf("\nstealPlayerTwosChip invoked!");
		positionsOccupied[selectedPos] = ' ';
		positionsOccupied[skippedPositionForward] = ' ';
		playerTwoPositions[skippedPositionForward] = 0;
		positionsOccupied[newPos] = 'K';////Overwriting from moveChipPlayerX, fix later
		kingBits[newPos] = 1;
		printf("\nChip given up.");
		printBoard();
		playerOneScore +=2;
		playerTwoScore -=2;
	}
	}
}

void playerOneKingOnEdge() { ///only applicable moving forward
	if (newPos > 56 && oldPos < 56 && kingBits[oldPos] == 0) {
		printf("/nPlayer Two, Select a chip to king the other player.");
		scanf("%i", &newPosTwo);
		kingBits[newPosTwo] = 0; ///Unkings if applicable
		playerTwoPositions[newPosTwo] = 0;
		positionsOccupied[newPosTwo] = ' ';
		positionsOccupied[newPos] = '$';
		kingBits[newPos] = 1;
		printf("Player Twos Position Kinged!");
		loopConditionTwo = 2;
	}
}

void playerTwoKingOnEdge() {
	if (newPos > 56 && oldPos < 56 && kingBits[oldPos] == 0) {
		printf("/nPlayer One, Select a chip to king the other player.");
		scanf("%i", &newPosTwo);
		kingBits[newPosTwo] = 0; ///Unkings if applicable
		playerOnePositions[newPosTwo] = 0;
		positionsOccupied[newPosTwo] = ' ';
		positionsOccupied[newPos] = 'K';
		kingBits[newPos] = 1;
		printf("\nPlayer Ones Position Kinged!");
		loopConditionTwo = 1;
	}
}

void playerTwoScoreUpdate() {///do fuckin what? trash.
	int positionDeltaForward;
	int skippedPositionForward;
	positionDeltaForward = (newPos - oldPos);
	skippedPositionForward = (newPos - (positionDeltaForward/2));
	playerTwoScore++;
	playerOneScore--;
	if (playerOnePositions[skippedPositionForward] = 1) {///do fuckin what? trash.
		playerTwoScore++;
		playerOneScore--;
	}
}	

void playerOneScoreUpdate() {///do fuckin what? trash.
	int positionDeltaForward;
	int skippedPositionForward;
	positionDeltaForward = (newPos - oldPos);
	skippedPositionForward = (newPos - (positionDeltaForward/2));
	playerOneScore++;
	playerTwoScore--;
	if (playerTwoPositions[skippedPositionForward] = 1) {
		playerOneScore++;
		playerTwoScore--;
	}
}

void kingPlayerOne() { ////no
	playerOnePositions[newPos] = 1;
	positionsOccupied[newPos] = 'K';
	kingBits[newPos] = 1;
}

void kingPlayerTwo() { ////no
	playerTwoPositions[newPos] = 1;
	positionsOccupied[newPos] = '$';
	kingBits[newPos] = 1;
}

void winningConditionsCheck() { ///no
	if (playerTwoScore == 0) {
		printf("\n Player Two Wins!");
		return 0;
	}
	if (playerOneScore == 0) {
		printf("\n Player One Wins!");
		return 0;
	}
}

void printBoard() { /// no
	printf("\n |%c|%c|%c|%c|%c|%c|%c|%c|", positionsOccupied[57], positionsOccupied[58], positionsOccupied[59], positionsOccupied[60], positionsOccupied[61], positionsOccupied[62], positionsOccupied[63], positionsOccupied[64]);
	printf("\n |%c|%c|%c|%c|%c|%c|%c|%c|", positionsOccupied[49], positionsOccupied[50], positionsOccupied[51], positionsOccupied[52], positionsOccupied[53], positionsOccupied[54], positionsOccupied[55], positionsOccupied[56]);
	printf("\n |%c|%c|%c|%c|%c|%c|%c|%c|", positionsOccupied[41], positionsOccupied[42], positionsOccupied[43], positionsOccupied[44], positionsOccupied[45], positionsOccupied[46], positionsOccupied[47], positionsOccupied[48]);
	printf("\n |%c|%c|%c|%c|%c|%c|%c|%c|", positionsOccupied[33], positionsOccupied[34], positionsOccupied[35], positionsOccupied[36], positionsOccupied[37], positionsOccupied[38], positionsOccupied[39], positionsOccupied[40]);
	printf("\n |%c|%c|%c|%c|%c|%c|%c|%c|", positionsOccupied[25], positionsOccupied[26], positionsOccupied[27], positionsOccupied[28], positionsOccupied[29], positionsOccupied[30], positionsOccupied[31], positionsOccupied[32]);
	printf("\n |%c|%c|%c|%c|%c|%c|%c|%c|", positionsOccupied[17], positionsOccupied[18], positionsOccupied[19], positionsOccupied[20], positionsOccupied[21], positionsOccupied[22], positionsOccupied[23], positionsOccupied[24]);
	printf("\n |%c|%c|%c|%c|%c|%c|%c|%c|", positionsOccupied[9], positionsOccupied[10], positionsOccupied[11], positionsOccupied[12], positionsOccupied[13], positionsOccupied[14], positionsOccupied[15], positionsOccupied[16]);
	printf("\n |%c|%c|%c|%c|%c|%c|%c|%c|\n", positionsOccupied[1], positionsOccupied[2], positionsOccupied[3], positionsOccupied[4], positionsOccupied[5], positionsOccupied[6], positionsOccupied[7], positionsOccupied[8]);
}

void playerOneCheckForJumps() {
	i = 1;
	char choice;
	while (i < 65 && i + 9 < 65) {
        if (playerOnePositions[i] == 1 && playerTwoPositions[(i + 9)] == 1 && playerTwoPositions[(i + 18)] == 0 && signBits[i] + signBits[(i + 9)] == 1) {
			int antiloop = 0;
			if (i < 48) {
			if (boundaryPositions[i] == (newPos-oldPos) || -(newPos-oldPos && antiloop == 0))
				printf("Boundary Condition Detected!\n");
				
			}
			printf("Player One, You can skip %i, Do you want to? Y/N \n", (i - 7));
			scanf(" %c", &choice);
			if (choice == 'Y') {
				i = 66;
			}
        }
		if (playerOnePositions[i] == 1 && playerTwoPositions[(i + 7)] == 1 && playerTwoPositions[(i + 14)] == 0 && signBits[i] + signBits[(i + 7)] == 1) {
			printf("Player One, You can skip %i, Do you want to? Y/N \n", (i + 7));
			scanf(" %c", &choice);
			if (i < 48) {
			int antiloop = 0;
			if (i < 48) {
			int positionDeltaForward;
			int skippedPositionForward;
			if (boundaryPositions[i] == (newPos-oldPos) || -(newPos-oldPos && antiloop == 0))
				printf("Boundary Condition Detected!\n");
				
			}
			if (choice == 'Y') {
				i = 66;
			}
			}
        }
		if (playerOnePositions[i] == 1 && playerTwoPositions[(i - 9)] == 1 && playerTwoPositions[(i - 18)] == 0 && signBits[i] + signBits[(i - 9)] == 1) {
			printf("Player One, You can skip %i, Do you want to? Y/N \n", (i - 9));
			scanf(" %c", &choice);
			int antiloop = 0;
			if (i < 48) {
			int positionDeltaForward;
			int skippedPositionForward;
			if (boundaryPositions[i] == (newPos-oldPos) || -(newPos-oldPos && antiloop == 0))
				printf("Boundary Condition Detected!\n");
				
			}
			if (choice == 'Y') {
				i = 66;
			}
        }
		if (playerOnePositions[i] == 1 && playerTwoPositions[(i - 7)] == 1 && playerTwoPositions[(i - 14)] == 0 && signBits[i] + signBits[(i - 7)] == 1) {
			printf("Player One, You can skip %i, Do you want to? Y/N \n", (i - 7));
			scanf(" %c", &choice);
			int antiloop = 0;
			if (i < 48) {
			int positionDeltaForward;
			int skippedPositionForward;
			if (boundaryPositions[i] == (newPos-oldPos) || -(newPos-oldPos && antiloop == 0))
				printf("Boundary Condition Detected!\n");
				
			}
			if (choice == 'Y') {
				i = 66;
			}
        }
	i++;
    }
	
}

void playerTwoCheckForJumps() {
		i = 1;
		char choice;
		while (i < 65 && i + 9 < 65) {
        if (playerTwoPositions[i] == 1 && playerOnePositions[(i + 9)] == 1 && playerOnePositions[(i+18)] == 0 && signBits[i] + signBits[(i + 9)] == 1) {
			int antiloop = 0;
			if (i < 48) {
			int positionDeltaForward;
			int skippedPositionForward;
			if (boundaryPositions[i] == (newPos-oldPos) || -(newPos-oldPos && antiloop == 0))
				printf("Boundary Condition Detected!\n");
				
			}
			printf("Player Two, You can skip %i, Do you want to? Y/N \n", (i + 9));
			scanf(" %c", &choice);
			if (choice == 'Y') {
				i = 66;
			}
        }
		if (playerTwoPositions[i] == 1 && playerOnePositions[(i + 7)] == 1 && playerOnePositions[(i + 14)] == 0 && signBits[i] + signBits[(i + 7)] == 1) {
			int antiloop = 0;
			if (i < 48) {
			int positionDeltaForward;
			int skippedPositionForward;
			if (boundaryPositions[i] == (newPos-oldPos) || -(newPos-oldPos && antiloop == 0))
				printf("Boundary Condition Detected!\n");
				
			}
			printf("Player Two, You can skip %i, Do you want to? Y/N \n", (i + 7));
			scanf(" %c", &choice);
			if (choice == 'Y') {
				i = 66;
			}
        }
		 if (playerTwoPositions[i] == 1 && playerOnePositions[(i - 9)] == 1 && playerOnePositions[(i - 18)] == 0 && signBits[i] + signBits[(i - 9)] == 1) {
			
			int antiloop = 0;
			
			if (i < 48) {
			int positionDeltaForward;
			int skippedPositionForward;
			if (boundaryPositions[i] == (newPos-oldPos) || -(newPos-oldPos && antiloop == 0))
				printf("Boundary Condition Detected!\n");
				
			}
			printf("Player Two, You can skip %i, Do you want to? Y/N \n", (i - 9));
			scanf(" %c", &choice);
			if (choice == 'Y') {
				i = 66;
			}
        }
		if (playerTwoPositions[i] == 1 && playerOnePositions[(i - 7)] == 1 && playerOnePositions[(i - 14)] == 0 && signBits[i] + signBits[(i - 7)] == 1) {
			int antiloop = 0;
			if (i < 48) {
				if (boundaryPositions[i] == (newPos-oldPos) || -(newPos-oldPos && antiloop == 0))
					printf("Boundary Condition Detected!\n");
					
				}
			printf("Player Two, You can skip %i, Do you want to? Y/N \n", (i - 7));
			scanf(" %c", &choice);
			if (choice == 'Y') {
				i = 66;
			}
        }
		//printf("\nplayerTwoPositions[i]: %i", playerTwoPositions[i]);
		//printf("\nplayerOnePositions[i - 9]: %i", playerOnePositions[i - 9]);
		//printf("\nplayerOnePositions[i - 18]: %i\n", playerOnePositions[i- 18]);
		i++;
	}
}

void BoundaryChecker() {
	int iterator = 1;
	if (i < 48) {
		int positionDeltaForward;
		int skippedPositionForward;
		if (boundaryPositions[i] == (newPos-oldPos) || -(newPos-oldPos))
			printf("Boundary Condition Detected!\n");
	}
}
