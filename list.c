//
// Created by Felix Schmidt on 08/05/2023.
//

#include "list.h"

List* makeList(){
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

void insertCard(List* list, Card card, int index){
    if(index < 0 || index > list->size){
        return;
    }
    Node* newNode = malloc(sizeof (Node));
    newNode->card = card;
    if(index == 0){
        newNode->next = list->head;
        list->head = newNode;
    }else{
        Node* before = list->head;
        //
        for(int i = 1; i < index; i++){
            before = before->next;
        }
        newNode->next = before->next;
        before->next = newNode;
    }
    list-> size++;

}
void addCard(List* list,Card card){
    insertCard(list,card,0);
}
void addCardEnd(List* list,Card card){
    insertCard(list,card,list->size);
}
void removeCard(List* list, Card card){
    int index = getIndexOf(list,card);
    if(index == -1){
        return;
    }
    removeCardAt(list,index);
}
void removeCardAt(List* list, int index){
    if(index < 0 || index > list->size){
        return;
    }
    Node* toRemove;
    if(index == 0){
        toRemove = list->head;
        list->head = toRemove->next;
    }else{
        Node* before = list->head;
        //
        for(int i = 1; i < index; i++){
            before = before->next;
        }
        toRemove = before->next;
        before->next = toRemove->next;
    }
    list->size--;
    free(toRemove);
}
int  getIndexOf(List* list, Card card){
    Node* current = list->head;
    for (int i = 0; i < list->size; ++i) {
        if(current->card.cardValue == card.cardValue && current->card.cardSuit == card.cardSuit){
            return i;
        }
        current = current->next;
    }

    return -1;
}
Card getCardAt(List* list, int index){
    if(index < 0 || index > list->size){
        Card* emptyCard = malloc(sizeof (Card));
        emptyCard->cardSuit  = ' ';
        emptyCard->cardValue = ' ';
        emptyCard->Hidden = 0;
        return *emptyCard;
    }
    Node* current = list->head;
    for (int i = 0; i < list->size; ++i) {
        if(index == i){
            return current->card;
        }
        current = current->next;
    }
    return current->card;
}
Card popCardAt(List* list, int index){
    Card card = getCardAt(list, index);
    removeCardAt(list,index);
    return card;
}
int getListSize(List* list) {
    return list->size;
}
int isListEmpty(List* list) {
    return list->head == NULL;
}