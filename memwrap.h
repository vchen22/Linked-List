#include <malloc.h>

/* mRec (metadata record) structure */
typedef struct mRec {
	void *mPtr;			// pointer to block mallocced for caller
	size_t size;		// size of the block allocated
	struct mRec *next;	// pointer to the next mRec in the linked list
} mRec_t;

/* pointer to the start of the mRec linked list */
static mRec_t *head = NULL;

/* 
 * Creates new node, sets mPtr to newly malloced memory,
 * inserts node into head of list, and returns mPtr.
 */
void *apparate(size_t);

/*
 * Searches for an mRec with a matching mPtr. If found,
 * frees the mPtr, then removes mRec from list and frees it.
 * Returns 1 if successful, 0 if not.
 */
int reducto(void *);

/* Frees all apparated blocks and metadata, and empties the list. */
void reductoMaximo();

/* Returns total number of currently-allocated blocks. */
int totalBlocks();

/*
 * Returns total number of currently-apparated bytes (does NOT
 * include the memory used for metadata records).
 */
size_t totalBytes();
