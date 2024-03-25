#include "headers.hpp"

ChessPiece::ChessPiece() : type(EMPTY), color(NONE) {}
ChessPiece::ChessPiece(PieceType t, PieceColor c) : type(t), color(c) {}

PieceType ChessPiece::getType() const { return type; }
PieceColor ChessPiece::getColor() const { return color; }

    // Fonction pour calculer tous les coups possibles pour un joueur
void ChessGame::calculatePossibleMoves(PieceColor playerColor) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            ChessPiece& piece = board[i][j];

            // Vérifier si la case contient une pièce de la couleur du joueur en cours
            if (piece.getColor() == playerColor) {
                // Générer les coups possibles pour la pièce
                generateMovesForPiece(i, j, piece);
            }
        }
    }
}


void ChessGame::generateMovesForPiece(int startRow, int startCol, const ChessPiece& piece) {
    switch (piece.getType()) {
        case PAWN:
            generatePawnMoves(startRow, startCol, piece.getColor());
            break;
        case ROOK:
            generateRookMoves(startRow, startCol);
            break;
        case KNIGHT:
            generateKnightMoves(startRow, startCol);
            break;
        case BISHOP:
            generateBishopMoves(startRow, startCol);
            break;
        case QUEEN:
            generateQueenMoves(startRow, startCol);
            break;
        case KING:
            generateKingMoves(startRow, startCol);
            break;
        default:
            break;
    }
}

void ChessGame::generatePawnMoves(int startRow, int startCol, PieceColor color) {
    int direction = (color == WHITE) ? 1 : -1;
        
        // Vérifier le mouvement initial (avancer de deux cases depuis la rangée de départ)
        if ((color == WHITE && startRow == 1) || (color == BLACK && startRow == 6)) {
            if (board[startRow + 2 * direction][startCol].getType() == EMPTY &&
                board[startRow + direction][startCol].getType() == EMPTY) {
                // Mouvement initial possible
                addMove(startRow, startCol, startRow + 2 * direction, startCol);
            }
        }
        
        // Vérifier le mouvement simple (avancer d'une case)
        if (board[startRow + direction][startCol].getType() == EMPTY) {
            // Mouvement simple possible
            addMove(startRow, startCol, startRow + direction, startCol);
        }

        // Vérifier les captures diagonales
        for (int colOffset : {-1, 1}) {
            int targetCol = startCol + colOffset;

            if (isValidCoordinate(startRow + direction, targetCol)) {
                PieceColor targetColor = board[startRow + direction][targetCol].getColor();
                if (targetColor == getOpponentColor(color)) {
                    addMove(startRow, startCol, startRow + direction, targetCol);
                }
            }
        }
}

void ChessGame::generateRookMoves(int startRow, int startCol) {
    // Logique pour générer les coups possibles pour une tour
    // ...
}

void ChessGame::generateKnightMoves(int startRow, int startCol) {
    // Logique pour générer les coups possibles pour un cavalier
    // ...
}

void ChessGame::generateBishopMoves(int startRow, int startCol) {
    // Logique pour générer les coups possibles pour un fou
    // ...
}

void ChessGame::generateQueenMoves(int startRow, int startCol) {
    // Logique pour générer les coups possibles pour une dame (reine)
    // ...
}

void ChessGame::generateKingMoves(int startRow, int startCol) {
    // Logique pour générer les coups possibles pour un roi
    // ...
}

ChessGame::ChessGame() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (i == 1) {
                board[i][j] = ChessPiece(PAWN, WHITE);
            } else if (i == 0) {
                switch (j) {
                    case 0:
                    case 7:
                        board[i][j] = ChessPiece(ROOK, WHITE);
                        break;
                    case 1:
                    case 6:
                        board[i][j] = ChessPiece(KNIGHT, WHITE);
                        break;
                    case 2:
                    case 5:
                        board[i][j] = ChessPiece(BISHOP, WHITE);
                        break;
                    case 3:
                        board[i][j] = ChessPiece(QUEEN, WHITE);
                        break;
                    case 4:
                        board[i][j] = ChessPiece(KING, WHITE);
                        break;
                    default:
                        break;
                }
            } else if (i == 6) {
                board[i][j] = ChessPiece(PAWN, BLACK);
            } else if (i == 7) {
                switch (j) {
                    case 0:
                    case 7:
                        board[i][j] = ChessPiece(ROOK, BLACK);
                        break;
                    case 1:
                    case 6:
                        board[i][j] = ChessPiece(KNIGHT, BLACK);
                        break;
                    case 2:
                    case 5:
                        board[i][j] = ChessPiece(BISHOP, BLACK);
                        break;
                    case 3:
                        board[i][j] = ChessPiece(QUEEN, BLACK);
                        break;
                    case 4:
                        board[i][j] = ChessPiece(KING, BLACK);
                        break;
                    default:
                        break;
                }
            } else {
                board[i][j] = ChessPiece();
            }
        }
    }
}

void ChessGame::displayBoard() {
    std::cout << "  | a | b | c | d | e | f | g | h |" << std::endl;
    std::cout << "--+--------------------------------" << std::endl;
    for (int i = 7; i >= 0; --i) {
        std::cout << i + 1 << " | ";
        for (int j = 0; j < 8; ++j) {
            char pieceChar = pieceToChar(board[i][j]);
            if (pieceChar == ' ') {
                std::cout << "* | ";
            } else {
                std::cout << pieceChar << " | ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void ChessGame::movePiece(int startRow, int startCol, int endRow, int endCol) {
    if (isValidCoordinate(startRow, startCol) && isValidCoordinate(endRow, endCol)) {
        if (board[startRow][startCol].getType() != EMPTY) {
             if (isValidMove(board[startRow][startCol], startRow, startCol, endRow, endCol)) {
                if (board[endRow][endCol].getType() == EMPTY || 
                    board[startRow][startCol].getColor() != board[endRow][endCol].getColor()) {

                    board[endRow][endCol] = board[startRow][startCol];
                    board[startRow][startCol] = ChessPiece();

                    std::cout << "Déplacement effectué avec succès." << std::endl;
                    return;
                } else {
                    std::cout << "Il y a déjà une pièce de votre couleur à la case de destination." << std::endl;
                }
            } else {
                std::cout << "Déplacement non autorisé pour cette pièce." << std::endl;
            }
        } else {
            std::cout << "Aucune pièce à la position de départ." << std::endl;
        }
    } else {
        std::cout << "Coordonnées invalides." << std::endl;
    }
}

bool ChessGame::isValidCoordinate(int row, int col) {
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

bool ChessGame::isValidMove(const ChessPiece& piece, int startRow, int startCol, int endRow, int endCol) {
    return true;
}

char ChessGame::pieceToChar(const ChessPiece& piece) {
    char pieceChar = ' ';

    switch (piece.getType()) {
        case EMPTY:
            pieceChar = ' ';
            break;
        case PAWN:
            pieceChar = 'P';
            break;
        case ROOK:
            pieceChar = 'R';
            break;
        case KNIGHT:
            pieceChar = 'N';
            break;
        case BISHOP:
            pieceChar = 'B';
            break;
        case QUEEN:
            pieceChar = 'Q';
            break;
        case KING:
            pieceChar = 'K';
            break;
        default:
            break;
    }

    if (piece.getColor() == WHITE) {
        pieceChar = std::tolower(pieceChar);
    }

    return pieceChar;
}

PieceColor ChessGame::getOpponentColor(PieceColor color) {
    return (color == WHITE) ? BLACK : WHITE;
}

void ChessGame::addMove(int startRow, int startCol, int endRow, int endCol) {
    possibleMoves.push_back(std::make_tuple(startRow, startCol, endRow, endCol));
}
