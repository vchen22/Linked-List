#include "memwrap.h"

/* 
 * Creates new node, sets mPtr to newly malloced memory,
 * inserts node into head of list, and returns mPtr.
 */
void *apparate(size_t size){
	// TODO

	//check if allocation is valid
	void *mPtr = malloc(size);

	//allocation fail
	if (mPtr == NULL)
	{
		return NULL;
	}

	//allocation succeeds
	mRec_t *newMData = malloc(sizeof(mRec_t));
	newMData->next = head;
	head = newMData;
	newMData->size = size;
	newMData->mPtr = mPtr;
	head = newMData;
	return newMData->mPtr;
}


/*
 * Searches for an mRec with a matching mPtr. If found,
 * frees the mPtr, then removes mRec from list and frees it.
 * Returns 1 if successful, 0 if not.
 */
int reducto(void *mPtr){
	// TODO
	
	mRec_t *prevNode = NULL;
	mRec_t *currentNode = head;

	while (currentNode != NULL)
	{
		if (currentNode->mPtr == mPtr)
		{
			if (currentNode == head)
			{
				head = currentNode->next;
			}
			else
			{
				prevNode->next = currentNode->next;				
			}

			free(currentNode->mPtr);
			free(currentNode);
			return 1;
		}

		prevNode = currentNode;
		currentNode = currentNode->next;

	}
	
	return 0;

}
  

/* Frees all apparated blocks and metadata, and empties the list. */
void reductoMaximo() {
	// TODO
	mRec_t *temp;
	mRec_t *currentNode = head;
	
	while (currentNode != NULL)
	{
		temp = currentNode;
		currentNode = currentNode->next;
		free(temp->mPtr);
		free(temp);
	}

	head = NULL;
}


/* Returns total number of currently-allocated blocks. */
int totalBlocks() {
	// TODO
	mRec_t *currentNode = head;
	int blockCount = 0;

	while (currentNode != NULL)
	{
		blockCount++;
		currentNode = currentNode->next;
	}

	return blockCount;
}


/*
 * Returns total number of currently-apparated bytes (does NOT
 * include the memory used for metadata records).
 */
size_t totalBytes() {
	// TODO
	mRec_t *currentNode = head;
	int byteSize = 0;

	while (currentNode != NULL)
	{
		byteSize += currentNode->size;
		currentNode = currentNode->next;
	}

	return byteSize;
	
}
  
