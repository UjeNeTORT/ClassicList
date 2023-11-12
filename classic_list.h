#ifndef CLASSIC_LIST_H
#define CLASSIC_LIST_H

#include <stdio.h>
#include <stdlib.h>

const int POISON = 0xD00D1E;

typedef int elem_t;

struct List
{
    ListElem* elem_zero;

    int size;
};

struct ListElem
{
    elem_t    data;

    ListElem* next;
    ListElem* prev;

    List*     list;
};

List ListCtor ();
int  ListDtor (List * list);

ListElem * ListInsertAfter  (List * list, ListElem * el, elem_t val);
ListElem * ListInsertBefore (List * list, ListElem * el, elem_t val);

elem_t ListPopElem (List * list, ListElem * el);


#endif // CLASSIC_LIST_H
