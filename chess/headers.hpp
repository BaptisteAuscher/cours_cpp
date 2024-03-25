#ifndef HEADERS_HPP
#define HEADERS_HPP

#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#include <tuple>

enum PieceType {
    EMPTY,
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

enum PieceColor {
    NONE,
    WHITE,
    BLACK
};

class ChessPiece {
public:
    ChessPiece();
    ChessPiece(PieceType t, PieceColor c);

    PieceType getType() const;
    PieceColor getColor() const;

private:
    PieceType type;
    PieceColor color;
};

class ChessGame {
    public:
        ChessGame();

        void displayBoard();
        void movePiece(int startRow, int startCol, int endRow, int endCol);
        void calculatePossibleMoves(PieceColor playerColor);

    private:
        ChessPiece board[8][8];
        std::vector<std::tuple<int, int, int, int>> possibleMoves;

        char pieceToChar(const ChessPiece& piece);
        bool isValidCoordinate(int row, int col);
        bool isValidMove(const ChessPiece& piece, int startRow, int startCol, int endRow, int endCol);
        void generateMovesForPiece(int startRow, int startCol, const ChessPiece& piece);
        void generatePawnMoves(int startRow, int startCol, PieceColor color);
        void generateRookMoves(int startRow, int startCol);
        void generateKnightMoves(int startRow, int startCol);
        void generateBishopMoves(int startRow, int startCol);
        void generateQueenMoves(int startRow, int startCol);
        void generateKingMoves(int startRow, int startCol);
        PieceColor getOpponentColor(PieceColor color);
        void addMove(int startRow, int startCol, int endRow, int endCol);
};

#endif
