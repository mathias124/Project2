//
// Created by Abdis on 5/5/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>


#include "Links.h"


#ifndef UNTITLED1_PRINTS_H
#define UNTITLED1_PRINTS_H




void CreateBoard(char *message, char *lastCommand);

void CreateBoard(char *message, char *lastCommand){
Card *curr1 = c1.start.next;
Card *curr2 = c2.start.next;
Card *curr3 = c3.start.next;
Card *curr4 = c4.start.next;
Card *curr5 = c5.start.next;
Card *curr6 = c6.start.next;
Card *curr7 = c7.start.next;
Card *f1 = a1.start.next;
Card *f2 = a2.start.next;
Card *f3 = a3.start.next;
Card *f4 = a4.start.next;


printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "A", "F");
printf("\n");
int i=0;
int tru=1;
while(tru){
i++;
if(curr1->cardSuit!='n') {
    if (curr1->Hidden == 0)
        printf("%c%c\t", curr1->cardValue, curr1->cardSuit);
    else {
    printf("[]\t");
}
curr1 = curr1->next;
} else{
    printf("\t");
}
if(curr2->cardSuit!='n'){
    if (curr2->Hidden == 0)
        printf("%c%c\t", curr2->cardValue, curr2->cardSuit);
    else {
        printf("[]\t");
    }
curr2 = curr2->next;
}
else{
    printf("\t");
}


if(curr3->cardSuit!='n'){
    if (curr3->Hidden == 0)
        printf("%c%c\t", curr3->cardValue, curr3->cardSuit);
    else {
        printf("[]\t");
    }curr3 = curr3->next;
}
else{
    printf("\t");
}

if(curr4->cardSuit!='n'){
    if (curr4->Hidden == 0)
        printf("%c%c\t", curr4->cardValue, curr4->cardSuit);
    else {
        printf("[]\t");
    }curr4 = curr4->next;
}
else{
    printf("\t");
}
if(curr5->cardSuit!='n'){
    if (curr5->Hidden == 0)
        printf("%c%c\t", curr5->cardValue, curr5->cardSuit);
    else {
        printf("[]\t");
    }
curr5 = curr5->next;
}
else{
    printf("\t");
}

if(curr6->cardSuit!='n'){
    if (curr6->Hidden == 0)
        printf("%c%c\t", curr6->cardValue, curr6->cardSuit);
    else {
        printf("[]\t");
    }
curr6 = curr6->next;
}
else{
    printf("\t");
}

if(curr7->cardSuit!='n'){
    if (curr7->Hidden == 0)
        printf("%c%c\t", curr7->cardValue, curr7->cardSuit);
    else {
        printf("[]\t");
    }
curr7 = curr7->next;
}

if(i==1) {
printf("%c%c\t", f1->cardValue, f1->cardSuit);
printf("F1");
}

if(i==2) {
printf("%c%c\t", f2->cardValue, f2->cardSuit);
printf("F2");
}

if(i==3) {
printf("%c%c\t", f3->cardValue, f3->cardSuit);
printf("F3");
}
if(i==4) {
printf("%c%c\t", f4->cardValue, f4->cardSuit);
printf("F4");
}

printf("\n");

if(i>13)
tru=0;

}
printf("\n");
// INITIAL VIEW
printf("LAST Command: %s",lastCommand);
// message
printf("MESSAGE: %s\n", message);
// intput
printf("%s\n", "INPUT > ");


}

#endif //UNTITLED1_PRINTS_H

