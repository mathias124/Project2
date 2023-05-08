//
// Created by Felix Schmidt on 08/05/2023.
//

#ifndef UNTITLED1_GAMEBOARD_H
#define UNTITLED1_GAMEBOARD_H
#include "list.h"

typedef struct Board{
    List columns[7];
    List foundations[4];
    Card deck[52];
}Board;

Board* createBoard(List* deck);
void printShowCase(Board* board);
void printShowcaseF(Board* board);
void makeShowCaseMode(Board* board);
void makePlayMode(Board* board);

void moveColumnToFoundation(Board* board, int columnIndex, int foundationIndex);
void moveFoundationToColumn(Board* board, int foundationIndex, int columnIndex);
void moveColumnToColumn(Board* board, int fromColumnIndex, int toColumnIndex);
void printBoard(Board* board);

#endif //UNTITLED1_GAMEBOARD_H
