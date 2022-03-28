//============================================================================
// Name        : a2.cpp
// Author      : Mina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "inord_list.h"
using namespace std;



/*--------------------------------------------------------------------------*/
int main(int argc, char * argv[]) {

	if(argc!=3)
	{
		cout<<"Incorrect number of arguments";
	}else
	{
		int wordnum=0,charnum=0,linenum=0;
		List store;
		string arr[2000];
		/******************************************************************************************/

		/*to calculate the number of characters*/
		char ch;
		fstream fin(argv[1], fstream::in);
		while (fin >> noskipws >> ch) {
			charnum++;
		}

		/*-------------------------------------------------------*/
		string sep="?!,;:'`&.[]{}()";
		ifstream infile(argv[1]);
		if (infile.is_open())
		{	string line;
		while (getline(infile, line))
		{
			linenum++;
			for(unsigned char k=0; k<sep.length();k++)
			{
				replace( line.begin(), line.end(), sep[k], ' ' );
			}
			replace( line.begin(), line.end(), '"', ' ' );
			/*-------------------------------------------------------*/
			// Used to split string around spaces.
			istringstream ss(line);

			string word; // for storing each word

			// Traverse through all words
			// while loop till we get
			// strings to store in string word

			while (ss >> word)
			{
				wordnum++; //calculate the number of words

				for(unsigned char j=0; j<word.length();j++)
				{
					word[j]=tolower(word[j]);
				}

				store.insert(word,linenum);

			}
		}
		string test;
		int m;
		store.first(test,m);
		//cout<<test<<"\t"<<m<<endl;
		while(store.next(test,m))
		{
			//cout<<test<<"\t"<<m<<endl;
		}
		/******************************************************************************/
		ifstream commfile(argv[2]);
		if (commfile.is_open())
		{
			string line;
			while (getline(commfile, line))
			{int argn=0;
			// Used to split string around spaces.
			istringstream ss(line);

			string word[10]; // for storing each word

			// Traverse through all words
			// strings to store in string word
			while(ss>>word[argn])
			{
				argn++;
				//cout <<argn<<"\n";
			}
			if(word[0].compare("wordCount")==0)
			{
				if(argn==1)
				{
					cout <<wordnum<<" "<<"words"<<"\n";
				}
				else
				{
					cout <<"Incorrect number of arguments"<<"\n";
				}
				/************************************************************/
			}else if(word[0].compare("distWords")==0)
			{
				if(argn==1)
				{
					int x;
					store.distWords(x);
					cout<<x<<" distinct words\n";
				}
				else
				{
					cout <<"Incorrect number of arguments"<<"\n";
				}
				/************************************************************/
			}else if(word[0].compare("charCount")==0)
			{
				if(argn==1)
				{
					cout <<charnum<<" "<<"characters"<<"\n";
				}
				else
				{
					cout <<"Incorrect number of arguments"<<"\n";
				}
				/************************************************************/
			}else if(word[0].compare("frequentWord")==0)
			{
				if(argn==1)
				{
					string freq;
					store.frequentWord(freq);
					cout<<"Most frequent word is:"<<freq<<"\n";
				}
				else
				{
					cout <<"Incorrect number of arguments"<<"\n";
				}
				/************************************************************/
			}else if(word[0].compare("countWord")==0)
			{
				if(argn==2)
				{
					for(unsigned char j=0; j<word[1].length();j++)
					{
						word[1][j]=tolower(word[1][j]);
					}
					int count;
					store.countWord(word[1],count);
					if(count!=0)
					{
						cout <<word[1]<<" is repeated "<<count<<" times"<<"\n";
					}
					else
					{
						cout <<word[1]<<" is repeated "<<"0"<<" times"<<"\n";
					}
				}
				else
				{
					cout <<"Incorrect number of arguments"<<"\n";
				}
				/************************************************************/
			}else if(word[0].compare("starting")==0)
			{
				if(argn==2)
				{
					for(unsigned char j=0; j<word[1].length();j++)
					{
						word[1][j]=tolower(word[1][j]);
					}
					int i;
					store.starting(word[1],arr,i);
					int count[i];
					if(i!=0){
						for(int j=0;j<i;j++)
						{
							store.countWord(arr[j],count[j]);
							cout<<arr[j]<<": "<<count[j]<<"\t";
						}
						cout<<"\n";}
					else
					{
						cout<<"Word not found\n";
					}
				}
				else
				{
					cout <<"Incorrect number of arguments"<<"\n";
				}
				/************************************************************/
			}else if(word[0].compare("containing")==0)
			{
				if(argn==2)
				{
					for(unsigned char j=0; j<word[1].length();j++)
					{
						word[1][j]=tolower(word[1][j]);
					}
					int i;
					store.containing(word[1],arr,i);
					int count[i];
					if(i!=0){
						for(int j=0;j<i;j++)
						{
							store.countWord(arr[j],count[j]);
							cout<<arr[j]<<": "<<count[j]<<"\t";
						}
						cout<<"\n";}
					else
					{
						cout<<"Word not found\n";
					}

				}
				else
				{
					cout <<"Incorrect number of arguments"<<"\n";
				}
				/************************************************************/
			}else if(word[0].compare("search")==0)
			{
				if(argn==2)
				{
					for(unsigned char j=0; j<word[1].length();j++)
					{
						word[1][j]=tolower(word[1][j]);
					}
					int i;
					store.containing(word[1],arr,i);
					if(i!=0)
					{
						for(int j=0;j<i;j++)
						{
							store.getLine(arr[j]);
						}
					}else
					{
						cout<<"Word not found\n";
					}
				}
				else
				{
					cout <<"Incorrect number of arguments"<<"\n";
				}
				/************************************************************/
			}else
			{
				cout <<"Undefined command"<<"\n";
			}
			}
			commfile.close(); //close the file object.
		}else
		{
			cout <<"File not found"<<"\n";
		}
		infile.close(); //close the file object.
		}else{
			cout <<"File not found"<<"\n";
		}

	}
	return 0;
}
