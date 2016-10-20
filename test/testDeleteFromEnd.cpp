#include <gtest/gtest.h>
#include "structandfunction.h"

TEST(DeleteFromEnd,function_delete_n_element)
{
	CNode *list=0;
	CNode **List=&list;
	int a[4]={1,2,3,5};
	int b[4];
    for (int i=5; i>0; i--)
	{
		CNode *node=new CNode;
		node->next=list;
		node->data=i;
		list=node;
	}
	DeleteFromEnd(List,2);
	CNode *tmp=list;
	for(int i=0; tmp!=0; i++)
	{
		b[i]=tmp->data;
		tmp=tmp->next;
	}
	for (int i=0; i<4; i++) 
		EXPECT_EQ(a[i],b[i]);
	while (list!=0)
	{
		CNode *node=list;
		list=list->next;
		delete node;
	}
}

TEST(DeleteFromEnd, throws_when_delete_element_with_negative_length)
{
	CNode *list=new CNode;
	CNode **List=&list;
	EXPECT_ANY_THROW(DeleteFromEnd(List, -1));
	delete list;
}

TEST(DeleteFromEnd,throws_when_delete_a_nonexistent_element)
{
	CNode *list=0;
	CNode **List=&list;
	for (int i=5; i>0; i--)
	{
		CNode *node=new CNode;
		node->next=list;
		node->data=i;
		list=node;
	}
	EXPECT_ANY_THROW(DeleteFromEnd(List,6));
	while (list!=0)
	{
		CNode *node=list;
		list=list->next;
		delete node;
	}
}
TEST(DeleteFromEnd,throws_when_a_pointer_to_the_beginning_of_the_list_points_to_NULL)
{ 
	CNode *list=0;
	CNode **List=&list;
	EXPECT_ANY_THROW(DeleteFromEnd(List, 3));
}
TEST(DeleteFromEnd,delete_the_first_element)
{
	CNode *list=0;
	CNode **List=&list;
	int a[4]={2,3,4,5};
	int b[4];
	for (int i=5; i>0; i--)
	{
		CNode *node=new CNode;
		node->next=list;
		node->data=i;
		list=node;
	}
	DeleteFromEnd(List,5);
	CNode *tmp=list;
	for(int i=0; tmp!=0; i++)
	{
		b[i]=tmp->data;
		tmp=tmp->next;
	}
	for (int i=0; i<4; i++) 
		EXPECT_EQ(a[i],b[i]);
	while (list!=0)
	{
		CNode *node=list;
		list=list->next;
		delete node;
	}
}

TEST(DeleteFromEnd,delete_the_last_element)
	{
	CNode *list=0;
	CNode **List=&list;
	int a[4]={1,2,3,4};
	int b[4];
	for (int i=5; i>0; i--)
	{
		CNode *node=new CNode;
		node->next=list;
		node->data=i;
		list=node;
	}
	DeleteFromEnd(List,1);
	CNode *tmp=list;
	for(int i=0; tmp!=0; i++)
	{
		b[i]=tmp->data;
		tmp=tmp->next;
	}
	for (int i=0; i<4; i++) 
		EXPECT_EQ(a[i],b[i]);
	while (list!=0)
	{
		CNode *node=list;
		list=list->next;
		delete node;
	}
}
