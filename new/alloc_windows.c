// 4 december 2014
#include "uipriv_windows.h"

// wrappers for allocator of choice
// panics on memory exhausted, undefined on heap corruption or other unreliably-detected malady (see http://stackoverflow.com/questions/28761680/is-there-a-windows-api-memory-allocator-deallocator-i-can-use-that-will-just-giv)
// new memory is set to zero
// passing NULL to tableRealloc() acts like tableAlloc()
// passing NULL to tableFree() is a no-op

void *uiAlloc(size_t size, const char *type)
{
	void *out;

	out = malloc(size);
	if (out == NULL)
		abort();	// TODO figure this part out
	ZeroMemory(out, size);
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
	if (out == NULL)
		abort();
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
