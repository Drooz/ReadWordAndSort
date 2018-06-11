#include "LinkedList.h"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

LinkedList::LinkedList(void)
{
	/* Start by the default constructor to set everything up
	NULL for the pointers and 0 for integers */

	first = NULL;
	last = NULL;
	count = 0;
}

LinkedList::~LinkedList(void)
{
	/* Simply we call the delete function*/
	del();
}

bool LinkedList::isEmpty()const {
	/* Since we keep track of the number of elements we can check count */
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void LinkedList::print()const {
	/* We create pointer TEMP just for print  */
	node * temp;
	temp = first;
	/* As long as it's not pointing to NULL "Which is the end of the list"
	Print and go to the next cell */
	while (temp != NULL)
	{
		cout << temp->data << " " << temp->num << endl;
		temp = temp->next;
	}
	cout << "Total number of unique words " << count << endl;
}

void LinkedList::add(string newitem) {

	/* Transform it to lower caes so both "Example" and "example" are the same
	DISABLE IT IF I'M NOT ALLOWED TO USE ITS LIB AND MAKE THE FUNCTION CONST */
	transform(newitem.begin(), newitem.end(), newitem.begin(),tolower);

	if (!isEmpty())
	{


		/* After we checked the list we need to check if the newitem exist */
		if (!doesexist(newitem)) {
			/* NOTE IF IT DOES EXIST THE DOES EXIST FUNCTION WILL INCREASE ITS NUM */
			/* Since it does not exist we add new cell at the end */
			node *newNode = new node;
			newNode->data = newitem;
			newNode->num = 1;
			newNode->previous = last;
			newNode->next = NULL;
			last->next = newNode;
			last = newNode;
			count++;
		}
	}
	else
	{
		node *newNode = new node;
		newNode->data = newitem;
		newNode->num = 1;
		first = newNode;
		last = newNode;
		newNode->next = NULL;
		newNode->previous = NULL;
		count++;
	}
}

bool LinkedList::doesexist(const string newitem) {
	node* temp = first;
	while (temp != NULL)
	/* While we not at the end */
	{
		if (newitem.compare(temp->data) != 0)
		{
			/* If string is not equal move on*/
			temp = temp->next;
		}
		else
		{
			/*If it does exist increase its value by one */
			temp->num++;
			return true;
		}
	}
	/* return false if it does not exist */
	return false;
}

void LinkedList::sort() {
	node *insertion = first;
	node *current = first;
	current = current->next;
	/* While we are not at the end KEEP GOING*/
	while (current != NULL)
	{
		/* Reset insertion at the first */
		insertion = first;
		/* While the pointer insertion is not before current */
		while (insertion->next != current) {
			/* If insertion less that current swap  */
			if (insertion->num < current->num) {

				node *temp = new node;
				temp->data = current->data;
				temp->num = current->num;

				current->data = insertion->data;
				current->num = insertion->num;

				insertion->data = temp->data;
				insertion->num = temp->num;
			}
			else {
				/* Else move on */
				insertion = insertion->next;

			}

		}
		/* Move current one cell a head */
		current = current->next;

	}
	/* Simple swap to fix the first two cell bug
	  BUG COMES FROM   while (insertion->next != current) */
	node *temp = new node;
	temp->data = first->data;
	temp->num = first->num;

	first->data = first->next->data;
	first->num = first->next->num;

	first->next->data = temp->data;
	first->next->num = temp->num;

}

void LinkedList::del(){

	node* temp;

	while (first != NULL)
	{
		temp = first;
		first = first->next;
		delete temp;
	}
	/* NOTE : First will be equal to NULL because of the while loop */
	/* Set the last pointer to NULL */
	last = NULL;
	/* Initialize the number of element to 0 */
	count = 0;


}



