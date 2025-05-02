#include "List.h"

#include "../String/String.h"

struct cNode;
typedef struct cNode *Node;

Node new_Node(void *value, deleteFunction delete, copyFunction copy, toStringFunction toString);
void del_Node(Node *self);
Node copy_Node(Node self);
String str_Node(Node self);

struct cNode
{
    void *_value;
    deleteFunction _delete;
    copyFunction _copy;
    toStringFunction _toString;
};

Node new_Node(void *value, deleteFunction delete, copyFunction copy, toStringFunction toString)
{
    Node result = (Node)malloc(sizeof(struct cNode));

    result->_value = value;
    result->_delete = delete;
    result->_copy = copy;
    result->_toString = toString;

    return result;
}

void del_Node(Node *self)
{
    if (*self == NULL)
        return;

    (*self)->_delete(&((*self)->_value));

    free(*self);

    *self = NULL;

    return;
}

Node copy_Node(Node self)
{
    return new_Node(self->_copy(self->_value), self->_delete, self->_copy, self->_toString);
}

String str_Node(Node self)
{
    return str("Node::ToString() not implemented yet.");
}

struct cList
{
    size_t _size;
    Node *_values;
    deleteFunction _delete;
    copyFunction _copy;
    toStringFunction _toString;
};

List new_List(size_t size, deleteFunction delete, copyFunction copy, toStringFunction toString)
{
    List result = (List)malloc(sizeof(struct cList));

    result->_size = size;
    result->_values = (Node *)malloc(sizeof(Node) * result->_size);
    result->_delete = delete;
    result->_copy = copy;
    result->_toString = toString;

    for (size_t i = 0; i < result->_size; i++)
        result->_values[i] = NULL;

    return result;
}

void del_List(List *self)
{
    if (*self == NULL)
        return;

    for (size_t i = 0; i < (*self)->_size; i++)
        del_Node(&((*self)->_values[i]));

    free((*self)->_values);
    free(*self);

    *self = NULL;

    return;
}

List copy_List(List self)
{
    List result = new_List(self->_size, self->_delete, self->_copy, self->_toString);

    for (size_t i = 0; i < result->_size; i++)
        result->_values[i] = copy_Node(self->_values[i]);

    return result;
}

String str_List(List self)
{
    return str("List::ToString() not implemented yet.");
}

size_t List_GetSize(List self)
{
    return self->_size;
}

void *List_Get(List self, int index)
{
    return self->_values[index]->_value;
}

void List_Append(List self, void *value)
{
    self->_size += 1;
    self->_values = realloc(self->_values, sizeof(Node) * self->_size);
    self->_values[self->_size - 1] = new_Node(value, self->_delete, self->_copy, self->_toString);
}