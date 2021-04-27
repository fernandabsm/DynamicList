#include <stdio.h>
#include <stdlib.h>

#ifndef DYNAMIC_LIST_H

#define DYNAMIC_LIST_H


typedef struct
{
	int code;
}TItem;

typedef struct cell
{
	TItem item;
	struct cell* next;
}TCell;

typedef struct
{
	TCell* first;
	TCell* last;
	int size;
}TList;

void MEmpty_List(TList* List);

void Inserts_Item(TItem Item, TList* List);

void Print_List(TList List);

TCell* Search_Item(TList List, TItem Item);

void Delete_Item(TList* List, TItem* Item);

void Change_Item(TList* List, TItem Item1, TItem Item2);

void Free_List(TList* List);


#endif // !DYNAMIC_LIST_H