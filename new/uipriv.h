// 6 april 2015
#include <stdlib.h>
#include "ui.h"

typedef struct uiSize uiSize;
typedef struct uiSizing uiSizing;

struct uiSize {
	intmax_t width;
	intmax_t height;
};

// TODO handle destruction
struct uiControl {
	uintptr_t (*handle)(uiControl *);
	void (*setParent)(uiControl *, uintptr_t);
	uiSize (*preferredSize)(uiControl *, uiSizing *);
	void (*resize)(uiControl *, intmax_t, intmax_t, intmax_t, intmax_t, uiSizing *);
};

// TODO write this comment
#define uiLogAllocations

extern void *uiAlloc(size_t, const char *);
#define uiNew(T) ((T *) uiAlloc(sizeof (T), #T ))
extern void *uiRealloc(void *, size_t, const char *);
extern void uiFree(void *);
