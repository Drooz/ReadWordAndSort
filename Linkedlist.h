#include <string>
using namespace std;

/* The structure of our node */
struct node {
	/* String to hold data */
	string data;
	/* "num" represent the frequency of this data */
	int num;
	/* This pointer point to the next cell */
	node * next;
	/* The pervious cell */
	node * previous;
};

class LinkedList
{
public:
	LinkedList(void);/* DONE */
	~LinkedList(void);/* DONE */
	bool isEmpty() const;/* DONE */
	void print() const;/* DONE */
	void add(string newitem);/* DONE */
	void del();/* DONE */
	bool doesexist(const string newtiem);/* DONE */
	void sort();/* DONE */


private:
	int count;
	node * first;
	node * last;
};

