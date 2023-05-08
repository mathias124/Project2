//
// Created by Abdis on 5/1/2023.
//

#ifndef UNTITLED1_LINKS_H
#define UNTITLED1_LINKS_H

#include "card.h"




typedef struct Link {
    Card start;
    Card end;
    int Coloumn;
} Link;
typedef struct LinkedLists {
    Link *list[11];
} LinkedLists;

int SuperInsert(Card** card1, Card** card2,LinkedLists*lists);

int InsertAllowd(Card *card,Card *card2);
int charConverter(char c);
int insert(Card *card, Link *link);
int RemoveLastCard(Link * link);
Card *getCard(char suit, char value, LinkedLists* lists);
Card getLastCard(Link link1);









//
// Created by Abdis on 5/1/2023.
//


// mangler nogen ting.Pototype.

int insert(Card *card, Link *link) {


    // Add the card to the end of the list
    if (link->start.next == &(link->end)) { // List is empty
        card->prev = &(link->start);
        card->next = &(link->end);
        link->start.next = card;
        link->end.prev = card;
    } else { // List is non-empty
        card->prev = link->end.prev;
        card->next = &(link->end);
        link->end.prev->next = card;
        link->end.prev = card;
    }

    card->column = link->Coloumn;

    return 0;
}


int charConverter(char c) {
    if (c == 'A') {
        return 1;
    } else if (c == '2') {
        return 2;
    } else if (c == '3') {
        return 3;
    } else if (c == '4') {
        return 4;
    } else if (c == '5') {
        return 5;
    } else if (c == '6') {
        return 6;
    } else if (c == '7') {
        return 7;
    } else if (c == '8') {
        return 8;
    } else if (c == '9') {
        return 9;
    } else if (c == 'T') {
        return 10;
    } else if (c == 'J') {
        return 11;
    } else if (c == 'Q') {
        return 12;
    } else if (c == 'K') {
        return 13;
    } else {
        return -1; // invalid input
    }
}

int remove_last_card( Link *link) {
    Card *cur = link->end.prev;
    Card *prev = link->end.prev->prev;



    // Remove the last card from the list
    prev->next = &(link->end);
    link->end.prev = prev;
    cur->next = &(link->end);

    return 0;
}
int SuperInsert(Card** card1, Card** card2, LinkedLists* lists) {
    Card * card10 =*card1;
    Card * card20 =*card2;
    Card * pre =card10->prev;
    Card * ne=card20->next;
    Card * L=lists->list[card10->column]->end.prev;



// remove cards from the old list
   pre->next= &lists->list[card10->column]->end;
    lists->list[card10->column]->end.prev=card10->prev->next;




// insert cards into the new list

 card10->prev=card20;
 card20->next=card10;
    ne->prev=L;
    L->next=ne;



 //update the column of the moved cards
Card* curr = card10;
while (curr->cardSuit!='n') {
curr->column = card20->column;
curr = curr->next;
}



return 1;

}

Card * getCard(char suit, char value, LinkedLists* lists) {
    for (int i = 0; i < 7; i++) {
        Link* link = lists->list[i];
        Card* current = &(link->start);
        while (current != NULL) {
            if (current->cardSuit == suit && current->cardValue == value) {
                return current;
            }
            if (current == &(link->end)) {
                break;
            }
            current = current->next;
        }
    }
    return NULL;
}






Link c1 = {
        .start = {'m', 0,0, 0,0, &c1.end, NULL},
        .end = {'n', 0, 0,0,0, NULL, &c1.start},
        .Coloumn=1

};
Link c2 = {
        .start = {'m', 0, 0,1,0, &c2.end, NULL},
        .end = {'n', 0, 0,1,0, NULL, &c2.start},
        .Coloumn=0
};
Link c3 = {
        .start = {'m', 0, 0,2,0, &c3.end, NULL},
        .end = {'n', 0, 0,2,0, NULL, &c3.start},
        .Coloumn=1
};
Link c4 = {
        .start = {'m', 0, 0,3,0, &c4.end, NULL},
        .end = {'n', 0, 0,3,0, NULL, &c4.start},
        .Coloumn=2
};
Link c5 = {
        .start = {'m', 0, 0,4,0, &c5.end, NULL},
        .end = {'n', 0, 0,4,0, NULL, &c5.start},
        .Coloumn=3
};
Link c6 = {
        .start = {'m', 0, 0,5,0, &c6.end, NULL},
        .end = {'n', 0, 0,5,0, NULL, &c6.start},
        .Coloumn=5
};
Link c7 = {
        .start = {'m', 0, 0,6,0, &c7.end, NULL},
        .end = {'n', 0, 0,6,0, NULL, &c7.start},
        .Coloumn=6
};
Link a1 = {
        .start = {'m', 0, 0,7,0, &a1.end, NULL},
        .end = {'n', 0, 0,7,0, NULL, &a1.start},
        .Coloumn=7
};
Link a2 = {
        .start = {'m', 0, 0,8,0, &a2.end, NULL},
        .end = {'n', 0, 0,8,0, NULL, &a2.start},
        .Coloumn=8
};Link a3 = {
        .start = {'m', 0, 0,9,0, &a3.end, NULL},
        .end = {'n', 0, 0,9,0, NULL, &a3.start},
        .Coloumn=9
};Link a4 = {
        .start = {'m', 0, 0,10,0, &a4.end, NULL},
        .end = {'n', 0, 0,10,0, NULL, &a4.start},
        .Coloumn=10
};



#endif //UNTITLED1_LINK_H
