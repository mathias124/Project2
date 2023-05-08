//
// Created by Felix Schmidt on 08/05/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "gameboard.h"
#include "list.h"



Board* createBoard(List* deck) {
    Board* board = malloc(sizeof (Board));
    // size of column, foundation and deck is already allocated
    for (int i = 0; i < 7; i++) {
        board->columns[i] = *makeList();
    }
    for (int i = 0; i < 4; ++i) {
        board->foundations[i] = *makeList();
    }
    for (int i = 0; i < 52; ++i) {
        Card cardToBe = getCardAt(deck,i);
        board->deck[i] = cardToBe;

    }
    return board;
}

void makeShowCaseMode(Board* board) {
    // Implementation of makeShowCaseMode function
    for (int i = 0; i < 52; i++){
        addCard(&board->columns[i % 7],board->deck[i]);
    }
}


void makePlayMode(Board* board) {
    // Deal 1 card in first column
    addCard(&(board->columns[0]), board->deck[0]);

    // Deal 6 cards in second column
    for (int i = 1; i <= 6; i++) {
        addCard(&(board->columns[1]), board->deck[i]);
    }

    // Deal 7 cards in third column
    for (int i = 7; i <= 13; i++) {
        addCard(&(board->columns[2]), board->deck[i]);
    }

    // Deal 8 cards in fourth column
    for (int i = 14; i <= 21; i++) {
        addCard(&(board->columns[3]), board->deck[i]);
    }

    // Deal 9 cards in fifth column
    for (int i = 22; i <= 30; i++) {
        addCard(&(board->columns[4]), board->deck[i]);
    }

    // Deal 10 cards in sixth column
    for (int i = 31; i <= 40; i++) {
        addCard(&(board->columns[5]), board->deck[i]);
    }

    // Deal 11 cards in seventh column
    for (int i = 41; i <= 51; i++) {
        addCard(&(board->columns[6]), board->deck[i]);
    }
}


void moveColumnToFoundation(Board* board, int columnIndex, int foundationIndex) {
    // Implementation of moveColumnToFoundation function
    Card card = popCardAt(&board->columns[columnIndex],columnIndex);
    addCard(&board->foundations[foundationIndex], card);

}

void moveFoundationToColumn(Board* board, int foundationIndex, int columnIndex) {
    Card card = popCardAt(&board->foundations[foundationIndex],foundationIndex);
    addCardEnd(&board->columns[columnIndex],card);
}

void moveColumnToColumn(Board* board, int fromColumnIndex, int toColumnIndex) {
    Card card = popCardAt(&board->columns[fromColumnIndex],fromColumnIndex);
    addCardEnd(&board->columns[toColumnIndex],card);
}

int getMaxRowCount(Board* board) {
    int maxRowCount = 0;
    for (int i = 0; i < 7; i++) {
        int rowCount = board->columns[i].size;
        if (rowCount > maxRowCount) {
            maxRowCount = rowCount;
        }
    }
    return maxRowCount;
}
void printShowCase(Board* board) {
    printf("C1 \t C2  C3  C4  C5  C6  C7\t\t\n");
    printf("==========================\n");
    int maxRowCount = getMaxRowCount(board);
    for (int i = 0; i < maxRowCount; i++) {
        for (int j = 0; j < 7; j++) {
            if (i < getListSize(&(board->columns[j]))) {
                Card card = getCardAt(&(board->columns[j]), i);
                printf("%c%c\t ", card.cardValue, card.cardSuit);
            } else {
                printf("[]  ");
            }
        }
/*
        if (i == 0) {
            printf("  [%c%c] F1 ", isListEmpty(&(board->foundations[0].head)) ? ' ' : board->foundations[0].head->card.cardValue,
                                isListEmpty(&(board->foundations[0].head)) ? ' ' : board->foundations[0].head->card.cardSuit);
        }else if(i == 1){
            printf("  [%c%c] F2", isListEmpty(&(board->foundations[1].head)) ? ' ' : board->foundations[1].head->card.cardValue,
                                isListEmpty(&(board->foundations[1].head)) ? ' ' : board->foundations[1].head->card.cardSuit);
        }else if(i == 2){
            printf("  [%c%c] F3", isListEmpty(&(board->foundations[2].head)) ? ' ' : board->foundations[2].head->card.cardValue,
                                isListEmpty(&(board->foundations[2].head)) ? ' ' : board->foundations[2].head->card.cardSuit);
        }else if(i == 3){
            printf("  [%c%c] F4 ", isListEmpty(&(board->foundations[3].head)) ? ' ' : board->foundations[3].head->card.cardValue,
                                isListEmpty(&(board->foundations[3].head)) ? ' ' : board->foundations[3].head->card.cardSuit);
        }*/
        printf("\n");
    }
}
void printShowcaseF(Board* board) {
    printf("   C1  C2  C3  C4  C5  C6  C7   A       F\n");
    printf("===========================================\n");

    // get the maximum row count across all columns
    int maxRowCount = getMaxRowCount(board);

    // print each row
    for (int i = 0; i < maxRowCount; i++) {
        printf("%c  ", 'A' + i);

        // print each column for the current row
        for (int j = 0; j < 7; j++) {
            List *column = &(board->columns[j]);
            int columnSize = getListSize(column);

            // print the card value and suit if it exists in the current column and row
            if (columnSize > i) {
                Card card = getCardAt(column, i);
                printf("%c%c ", card.cardValue, card.cardSuit);
            } else {
                printf("   ");
            }
        }

        // print the foundations for the current row
        if (i == 0) {
            printf("  [%c1] ", isListEmpty(&(board->foundations[0])) ? ' ' : 'A');
        }else if(i == 1){
            printf("  [%c2] ", isListEmpty(&(board->foundations[1])) ? ' ' : 'B');
        }else if(i == 2){
            printf("  [%c2] ", isListEmpty(&(board->foundations[1])) ? ' ' : 'B');
        }else if(i == 3){
            printf("  [%c3] ", isListEmpty(&(board->foundations[2])) ? ' ' : 'C');
        }
        printf("\n");
    }
}