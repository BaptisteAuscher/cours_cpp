#include "headers.hpp"

void quit(std::string input) {
    if (input == "q" || input == "Q") {
        std::cout << "Au revoir !" << std::endl;
        exit(0);
    }
} 

int columnLetterToNumber(const std::string& columnLetter) {
    static const std::map<char, int> columnMapping = {
        {'a', 1}, {'b', 2}, {'c', 3}, {'d', 4},
        {'e', 5}, {'f', 6}, {'g', 7}, {'h', 8}
    };

    if (columnLetter.length() != 1 || !islower(columnLetter[0])) {
        
        return -1; 
    }

    return columnMapping.at(columnLetter[0]);
}


int main() {
    ChessGame chessGame;

    chessGame.displayBoard();

    chessGame.movePiece(1, 2, 3, 2);

    chessGame.displayBoard();
    while (true) {
        std::string originRow;
        std::string originCol;
        std::string destRow;
        std::string destCol;

        std::cout << "Saisissez la ligne d'origine de votre pièce (1-8): ";
        std::getline(std::cin, originRow);
        quit(originRow);

        std::cout << "Saisissez la colonne d'origine de votre pièce (a-h): ";
        std::getline(std::cin, originCol);
        quit(originCol);

        std::cout << "Saisissez la ligne d'arrivé de votre pièce (1-8): ";
        std::getline(std::cin, destRow);
        quit(destRow);

        std::cout << "Saisissez la colonne d'arrivé de votre pièce (a-h): ";
        std::getline(std::cin, destCol);
        quit(destCol);
    }

    return 0;
}
