/*
 * inord_list.h
 *
 *  Created on: May 6, 2021
 *      Author: student
 */

#ifndef INORD_LIST_H_
#define INORD_LIST_H_
#include <iostream>
#include <string>
using namespace std;


typedef string ListElemType;

class List{
public:
	List();
	bool insert(const ListElemType &e,const int l);
	bool first(ListElemType &e,int &l);
	bool next(ListElemType &e,int &l);
	void distWords(int &num);
	void frequentWord(string &freq);
	void countWord(const string word,int &num);
	void starting(const string &key,string arr1[],int &i);
	void containing(const string &key,string arr2[],int &i);
	void getLine(const string&word);
	~List();

private:
	struct node;
	typedef node* link;
	struct node{
		ListElemType item;
		int line;
		int occ;
		link next;
	};
	link head;
	link current;
};


#endif /* INORD_LIST_H_ */
