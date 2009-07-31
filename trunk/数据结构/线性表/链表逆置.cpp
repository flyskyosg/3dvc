#include<iostream>
///Á´±íÄæÖÃ
using namespace std;

struct node
{
	int	data;
	struct node * next;
};


void rehub(node *  & head)
{
	if(head == NULL) return;
      
	node * last,* current,* next;
	last = head;
	current = last->next;
	while(current)
	{
		next = current->next;
		current->next = last;
		if(last = head) last->next = NULL;

		last = current;
		current = next;
	}

	head = last;
}

int main()
{
	node * head = new node;
	head->data = 1;
	head->next = NULL;
	node * cur = head;

	for(int i = 2; i < 11; i++)
	{
		node * temp = new node;
		temp->data = i;
		temp->next = NULL;
		cur->next = temp;
		cur = temp;
	}

	rehub(head);

	cur = head;
	while(cur)
	{
		cout << cur->data << endl;
		cur = cur->next;
	}

	getchar();

}
	