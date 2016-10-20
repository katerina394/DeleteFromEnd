#include "structandfunction.h"
void DeleteFromEnd(CNode **list, int n)
{
	if ((n>0)&&(*list!=0))
	{
		CNode *tmp=*list,*temp;
		int k=0;
		while (tmp!=0)
		{k++; tmp=tmp->next;}
		if (n<=k)
		{
			tmp=*list;
			if (k==n)
			{*list=(*list)->next; delete tmp;}
			else
			{
				for (int i=0; i<k-n; i++)
				{
					temp=tmp;
					tmp=tmp->next;
				}
				temp->next=tmp->next;
				delete tmp;
			}
		}
		else throw 1;
	}
	else throw 1;
}