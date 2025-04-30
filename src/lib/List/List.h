#ifndef _LIST_H_
#define _LIST_H_

#include "../types.h"

List new_List();
void del_List(List *self);
List copy_String(List self);
String str_String(List self);

#endif // !_LIST_H_