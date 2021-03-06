// 4 december 2014
#import <stdio.h>
#import "uipriv_darwin.h"

// TODO is there a better alternative to NSCAssert()? preferably a built-in allocator that panics on out of memory for us?

void *uiAlloc(size_t size, const char *type)
{
	void *out;

	out = malloc(size);
	NSCAssert(out != NULL, @"out of memory in uiAlloc()");
	memset(out, 0, size);
#ifdef uiLogAllocations
	fprintf(stderr, "%p alloc %s\n", out, type);
#endif
	return out;
}

void *uiRealloc(void *p, size_t size, const char *type)
{
	void *out;

	if (p == NULL)
		return uiAlloc(size, type);
	out = realloc(p, size);
	NSCAssert(out != NULL, @"out of memory in uiRealloc()");
	// TODO zero the extra memory
#ifdef uiLogAllocations
	fprintf(stderr, "%p realloc %p\n", p, out);
#endif
	return out;
}

void uiFree(void *p)
{
	if (p == NULL)
		return;
	free(p);
#ifdef uiLogAllocations
	fprintf(stderr, "%p free\n", p);
#endif
}
