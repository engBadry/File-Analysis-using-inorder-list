/*
 * inord_list.cpp
 *
 *  Created on: May 6, 2021
 *      Author: student
 */
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include "inord_list.h"
using namespace std;

int removeDuplicates(string arr[], int n)
{
	if (n==0 || n==1)
		return n;

	// To store index of next unique element
	int j = 0;

	// Doing same as done in Method 1
	// Just maintaining another updated index i.e. j
	for (int i=0; i < n-1; i++)
		if (arr[i] != arr[i+1])
			arr[j++] = arr[i];

	arr[j++] = arr[n-1];

	return j;
}

void removeDuplicatesint(int arr[], int n)
{

	int i;

	// Initialise a set
	// to store the array values
	set<int> s;

	// Insert the array elements
	// into the set
	for (i = 0; i < n; i++) {

		// insert into set
		s.insert(arr[i]);
	}

	set<int>::iterator it;

	// Print the array with duplicates removed
	for (it = s.begin(); it != s.end(); ++it)
		cout<< " " << *it ;
	cout << '\n';
}
List ::List()
{
	head= NULL;
	current= NULL;
}

bool List::insert(const ListElemType &e,int l)
{
	link addedNode;
	link pred;
	addedNode = new node; //step 1
	if (addedNode == NULL)
		return false;
	else {
		addedNode->item = e; //step 2
		addedNode->line= l;
		addedNode->occ=1;
		current=head;
		while(current!=NULL)
		{
			if(e==current->item)
			{
				addedNode->occ++;
				//current->occ++;
			}
			current=current->next;
		}
		//step 3
		if(head==NULL||e<=head->item)
		{
			addedNode -> next = head;
			//step 4
			head = addedNode;
			return true;
		} // end of if condition
		else { //search for proper position
			pred = head;
			while (pred-> next != NULL && pred-> next -> item < e) {

				pred = pred -> next;
			}
			//step 3 (2nd case)
			addedNode -> next = pred -> next;
			//step 4 (2nd case)
			pred -> next = addedNode;
			return true;
		}


	}
}

bool List::first(ListElemType &e,int &l)
{
	if(head==NULL)
	{
		return false;
	}else
	{
		current=head;
		e=current->item;
		l=current->line;
		return true;
	}
}

bool List::next(ListElemType &e,int &l)
{
	if(current==NULL||current->next==NULL)
	{
		return false;
	}else
	{
		current=current->next;
		e=current->item;
		l=current->line;
		return true;
	}
}

void List::distWords(int &num)
{
	num=0;
	current=head;
	while(current!=NULL)
	{
		if(current->occ==1)
		{
			num++;
		}
		current=current->next;
	}
}

void List::frequentWord(string &freq)
{
	int max=0;
	current=head;
	while(current!=NULL)
	{
		if(current->occ>=max)
		{
			max=current->occ;
		}//a, an, the, in, on, of, and, is , are
		current=current->next;}
	current=head;
	while(current!=NULL)
	{
		if((current->occ==max)&&(current->item!="a")&&(current->item!="an")&&(current->item!="the")&&(current->item!="in")&&(current->item!="on")&&(current->item!="of")&&(current->item!="and")&&(current->item!="is")&&(current->item!="are"))
		{
			freq.append(" ");
			freq.append(current->item);
			max=current->occ;
		}
		current=current->next;}
}

void List::countWord(const string word,int &num)
{
	current=head;
	num=0;
	while(current!=NULL)
	{
		if(current->item == word)
		{
			num++;
		}
		current=current->next;
	}
}

void List::starting(const string &key,string arr1[],int &i)
{
	current=head;
	i=0;
	while(current!=NULL)
	{
		if (current->item.rfind(key, 0) == 0) {
			arr1[i]=current->item;
			i++;
		}
		current=current->next;
	}

	i=removeDuplicates(arr1,i);
}

void List::containing(const string &key,string arr2[],int &i)
{
	current=head;
	i=0;
	while(current!=NULL)
	{
		if (current->item.find(key) != std::string::npos) {
			arr2[i]=current->item;
			i++;

		}
		current=current->next;
	}
	i=removeDuplicates(arr2,i);

}
void List::getLine(const string&word)
{
	current=head;
	int i=0;
	int arr[1000];
	while(current!=NULL)
	{
		if(word==current->item)
		{
			arr[i]=current->line;
			i++;
		}
		current=current->next;
	}
	cout<<word<<":\tlines";
	removeDuplicatesint(arr,i);
}

List ::~List()
{
	current=head;
	while(current!=NULL)
	{
		link ptr=current;
		current=current->next;
		delete ptr;
	}
}
