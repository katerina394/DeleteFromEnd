#include "stdlib.h"
struct CNode{
	int data;
	CNode *next;
};
void DeleteFromEnd(CNode **list, int n);