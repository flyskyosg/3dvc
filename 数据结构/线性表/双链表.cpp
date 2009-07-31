//Ë«Á´±í

#include<iostream>

using namespace std;

struct node
{
	int data;
	struct node * pre;
	struct node * next;
};

void create(node * & head)
{
	if(head == NULL) return ;

     node * last,* temp = new node;
	 last = head;
	 cout <<"cin datat" << endl;
	 cin >> temp->data;
	 while(temp->data != 0)
	 {
		 temp->next = head;
		 temp->pre = last;
		 last->next = temp;
		 last = temp;
		 head->pre = last;
		 
		 temp = new node;
		 cout << "cin data" << endl;		 
		 cin >> temp->data;
	 }
}


void del(node * & head,int data)
{
	if(head == NULL) return ;

	node * cur,* last;
	cur = head;
	while( cur != NULL && cur->data != data ) cur = cur->next;
	if(!cur) return ;//Ã»ÕÒµ½
	if(cur == head)
	{
		head = head->next;
		head->pre = NULL;
		cur->next = NULL;

		delete cur;
	}
	else
	{
		if(cur->next != NULL)
		{
			last = cur->pre;
			cur->next->pre = last;
			last->next = cur->next;
		}
		else
		{
			cur->pre->next  = NULL;
		}
		cur->next = NULL;
		cur->pre = NULL;
		delete cur;


	}
}


	


		



int main()
{
	node * head = new node;
	head->data = 0;
	head->next = NULL;
	head->pre = NULL;
	create(head);
	del(head,2);
	

loop:char c;
	cin >> c;
	if(c == 'c') return 0;
	else
	goto loop;
	

}





