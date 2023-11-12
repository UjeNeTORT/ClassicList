#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "classic_list.h"


List ListCtor()
{
    ListElem * elem_zero = (ListElem *) calloc(1, sizeof(ListElem)); // first element not used for storing values

    List list =
    {
        .elem_zero = elem_zero,
        .size = 0,
    };

    return list;
}

int ListDtor (List * list)
{
    assert(list);

    ListElem * next_el = NULL;

    for (ListElem * ptr = list->elem_zero->next; ptr != list->elem_zero; ptr = next_el)
    {
        next_el = ptr->next;
        free(ptr);
    }

    free(list->elem_zero);

    return 0;
}

ListElem * ListInsertAfter (List * list, ListElem * el, elem_t val)
{
    assert(list);
    assert(el);
    assert(el->list == list);

    ListElem * new_el = (ListElem *) calloc(1, sizeof(ListElem));

    new_el->data = val;
    new_el->list = list;

    ListElem * new_next = el->next;
    el->next->prev = new_el;

    el->next = new_el;
    new_el->next = new_next;
    new_el->prev = el;

    list->size++;

    return new_el;
}

ListElem * ListInsertBefore (List * list, ListElem * el, elem_t val)
{
    assert(list);
    assert(val);
    assert(el->list == list);

    return ListInsertAfter (list, el->prev, val);
}

elem_t ListPopElem (List * list, ListElem * el)
{
    assert(list);
    assert(el);
    assert(el->list == list);

    el->prev->next = el->next;
    el->next->prev = el->prev;

    elem_t val = el->data;

    el->data = POISON;
    el->next = NULL;
    el->prev = NULL;

    free(el);

    list->size--;

    return val;
}


