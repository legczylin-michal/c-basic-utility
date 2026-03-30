#ifndef _TYPES_H_
#define _TYPES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct cString;
typedef struct cString *String;

struct cList;
typedef struct cList *List;

struct cMatrix;
typedef struct cMatrix *Matrix;

typedef void (*deleteFunction)(void **);
typedef void *(*copyFunction)(void *);
typedef String (*toStringFunction)(void *);

#endif // !_TYPES_H_