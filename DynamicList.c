#include <stdio.h>
#include <stdlib.h>
#include "DynamicList.h"

void MEmpty_List(TList* List)
{
	List->first = (TCell*)malloc(sizeof(TCell));
	List->last = List->first;
	List->first->next = NULL;
	List->size = 0;
}

int Empty_List(TList List)
{
	return(List.size == 0);
}

void Inserts_Item(TItem Item, TList* List)
{
	List->last->next = (TCell*)malloc(sizeof(TCell));
	List->last = List->last->next;
	List->last->item = Item;
	List->last->next = NULL;
	List->size++;
}

void Print_List(TList List)
{
	if (Empty_List(List))
	{
		printf("\n\t\t >>>>>>>>>> MSG: The list is empty! <<<<<<<<<<\n");
	}
	else
	{
		TCell* aux;
		aux = List.first->next;
		while (aux != NULL)
		{
			printf("\t\t\t\t%d \n", aux->item.code);
			aux = aux->next;
		}
	}
}

TCell* Search_Item(TList List, TItem Item)
{
	TCell* aux;
	aux = List.first;
	while (aux->next != NULL)
	{
		if (aux->next->item.code == Item.code)
			return aux;
		aux = aux->next;
	}
	return NULL;
}

void Delete_Item(TList* List, TItem *Item)
{
	TCell* aux1, * aux2;
	aux1 = Search_Item(*List, *Item);
	if (aux1 != NULL)
	{
		aux2 = aux1->next;
		aux1->next = aux2->next;
		*Item = aux2->item;
		if (aux1->next == NULL)
		{
			List->last = aux1;
		}
		free(aux2);
		List->size--;
	}
}

void Change_Item(TList* List, TItem Item1, TItem Item2)
{
	TCell* aux;
	aux = Search_Item(*List, Item1);
	if (aux != NULL && aux->next != NULL)
	{
		aux = aux->next;
		aux->item = Item2;
	}
}

void Free_List(TList* List)
{
	TCell* aux;
	for (int i = 0; i < List->size; i++)
	{
		aux = List->first->next;
		List->first->next = aux->next;
		free(aux);
	}
	free(List->first);
	List->size = 0;
}