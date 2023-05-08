#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "card.h"
#include "readFile.h"
#include "Links.h"
#include "Prints.h"
#include "list.h"
#include "gameboard.h"

int main() {
    bool startMeny = true;
    bool GameOpen = true;
    bool Undo = false;
    bool load = false;
    char commandBuff[20];
    LinkedLists AllList;
    char  message [8];
    printf("Hello, World!\n");

    List *deckList = makeList();
    //char *FileName = "cmake-build-debug/DATA.txt";
    // Open the file, using CWD library to get a user's directory path to make it work.
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() error");
        exit(EXIT_FAILURE);
    }
//Startmenu screen(input to choose filepath and continue or not.
    while (startMeny == true && load == false) {
        char userinput[50];
        printf("Enter 'Y' to conitnue with a new game  or 'LD' to load previous savefile:");
        printf("\n");
        fgets(userinput, 50, stdin);
        if (strcmp(userinput, "Y\n") == 0) {
            startMeny = false;
            snprintf(file_path, sizeof(file_path), "%s/%s", cwd, file_name);
        } else if (strcmp(userinput, "LD\n") == 0) {
            //Load Save.
            printf("loading your save...\n");
            load = true;
            snprintf(file_path, sizeof(file_path), "%s/%s", cwd, file_save);
        } else {
            printf("Invalid command, please enter either Y or LD to continue");
        }
        printf("File path: %s\n", file_path);
        file = fopen(file_path, "r");
        fseek(file, 0, SEEK_END);
        file_size = ftell(file);// Get the file size
        rewind(file);
    }

    int noCards = 0;
    char tempCardSuit;
    char tempCardValue;

    // Allocate memory for the file buffer
    memoryBuff = (char *) malloc(file_size * sizeof(char));
    if (!memoryBuff) {
        printf("Error: Could not allocate memory for file buffer\n");
        fclose(file);
        return 1;
    }
    while (!feof(file) && startMeny == false || load == true) {
        Card card;
        int res;
        res = fscanf(file, "%c%c\n", &tempCardValue, &tempCardSuit);
        if (res == 2) {
            card = (Card) {tempCardSuit, tempCardValue};
            addCard(deckList, card);

        }
        noCards++;
    }
    //This method below is creating a txt file called shuffled_cards.txt and "w" writes it.
    //The next 40 lines are for creating and shuffeling cards and saving it.
    //shuffleCards(cards, noCards);
    FILE *save;
    save = fopen("shuffled_cards.txt", "w");
    if (save == NULL) {
        perror("Error could not create savefile");
        return 1;
    }
    //for (int i = 0; i < 52; ++i) {
    //        fprintf(save, "%c%c\n", cards[i].cardValue, cards[i].cardSuit);
    //}
    fclose(save);
    printf("%s\n", "LAST Command:");
    // message
    printf("%s\n", "MESSAGE: ");
    // intput
    printf("%s\n", "INPUT > ");

    fread(memoryBuff, sizeof(char), file_size, file);
    // Close the file
    fclose(file);
    free(memoryBuff);
    //This methods make the game in a while loop and makes the quit command to close game, furthermore commands.
    while (GameOpen) {

        fgets(commandBuff, BUFSIZ, stdin);
        if (strcmp(commandBuff, "QQ\n") == 0 || strcmp(commandBuff, "qq\n") == 0) {
            GameOpen = false;
        } else if (strcmp(commandBuff, "SR\n") == 0 || strcmp(commandBuff, "sr\n") == 0) {
            ////////// Experimental commands

            printf("Shuffled Cards:\n");
            /*for (int i = 0; i < noCards; i++) {
                printf("%c\n", cards[i].cardValue);
            }*/
            //GameOpen = false;
        } else if (strcmp(commandBuff, "SW\n") == 0 || strcmp(commandBuff, "sw\n") == 0) {
            Board *board = createBoard(deckList);
            free(board);
            makeShowCaseMode(board);
            printShowCase(board);
        } else if (strcmp(commandBuff, "P\n") == 0 || strcmp(commandBuff, "p\n") == 0) {
            Board *playBoard = createBoard(deckList);
            free(playBoard);
            makePlayMode(playBoard);
            printShowCase(playBoard);
        }

            //Undo commando.
        else if (strcmp(commandBuff, "U\n") == 0 || strcmp(commandBuff, "u\n") == 0) {

        } else if (strcmp(commandBuff, "p\n") == 0 || strcmp(commandBuff, "P\n") == 0) {
            //mode = 1;
        }
            ///Redo Command
        else if (strcmp(commandBuff, "R\n") == 0) {
            if (Undo == true) {
                //Needs to be undone, before redo is available.
            }
        } else {

            /*Card *t= getCard(commandBuff[4],commandBuff[3],&AllList);
             Card *s= getCard(commandBuff[1],commandBuff[0],&AllList);
             if(s!=NULL && t!=NULL ) {
                 if ( s->trueValue<t->trueValue && s->cardSuit!=t->cardSuit && t->column!=s->column) {
                     SuperInsert(&s, &t, &AllList);
                     strcpy(message,"ok     ");
                 } else
                 strcpy(message,"Invalid");
             } else
                 strcpy(message,"Invalid");*/

            CreateBoard(message, commandBuff);
        }

    }
    return 0;

}
