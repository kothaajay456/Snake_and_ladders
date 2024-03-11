#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>

using namespace std;

// Function to roll a six-sided die
int rollDie() {
    return rand() % 6 + 1;
}

// Function to move the player
int movePlayer(int currentPlayer, int roll, map<int, int>& snakesAndLadders) {
    int newPosition = currentPlayer + roll;
    
    // Check if there's a snake or ladder at the newPosition
    if (snakesAndLadders.find(newPosition) != snakesAndLadders.end()) {
        cout << "You've encountered a snake or ladder!" << endl;
        newPosition = snakesAndLadders[newPosition];
    }

    // Player cannot move beyond square 100
    if (newPosition > 100) {
        return currentPlayer;
    }

    return newPosition;
}

int main() {
    srand(time(0)); // Initialize random seed

    int numPlayers;
    cout << "Welcome to Snake and Ladders!" << endl;
    cout << "Enter the number of players (1 or 2): ";
    cin >> numPlayers;

    if (numPlayers != 1 && numPlayers != 2) {
        cout << "Invalid number of players. Exiting the game." << endl;
        return 1;
    }

    vector<int> playerPositions(numPlayers, 0);
    vector<string> playerNames = {"Player 1", "Player 2"};
    bool gameWon = false;

    // Define the positions of snakes and ladders on the board
    map<int, int> snakesAndLadders;
    snakesAndLadders[6] = 40;
    snakesAndLadders[23] = 10;
    snakesAndLadders[45] = 7;
    snakesAndLadders[61] = 18;
    snakesAndLadders[65] = 8;
    snakesAndLadders[77] = -5;
    snakesAndLadders[98] = 10;

    while (!gameWon) {
        for (int i = 0; i < numPlayers; ++i) {
            cout << "\n" << playerNames[i] << ", press Enter to roll the die...";
            cin.ignore(); // Ignore any remaining characters in input buffer
            cin.get(); // Wait for the player to press Enter
            int roll = rollDie();
            cout << "You rolled a " << roll << "." << endl;

            playerPositions[i] = movePlayer(playerPositions[i], roll, snakesAndLadders);
            cout << playerNames[i] << " is now at square " << playerPositions[i] << "." << endl;

            if (playerPositions[i] == 100) {
                cout << playerNames[i] << " wins!" << endl;
                gameWon = true;
                break; // Exit the loop if any player wins
            }
        }
    }

    return 0;
}

