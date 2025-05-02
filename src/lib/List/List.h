#ifndef _LIST_H_
#define _LIST_H_

#include "../types.h"

List new_List(size_t size, deleteFunction delete, copyFunction copy, toStringFunction toString);
void del_List(List *self);
List copy_List(List self);
String str_List(List self);

size_t List_GetSize(List self);
void *List_Get(List self, int index);

void List_Append(List self, void *value);

#endif // !_LIST_H_