#include "Node_t.h"

struct List_t
{
	Node_t* first;

	List_t(int val);
	~List_t();

	void push_back(int val);
	void print();
    void pop_back();

	void insert(int pos, int val)
	{
	    Node_t* node = first;
	    Node_t* next_node = first;


        if(1 == pos){
            next_node = node;
            first = new Node_t(val);
            first-> next = next_node;

        }else{
		for(int i = 0; i<pos-1; i++){

            node = node -> next;
            }

        next_node = node;
        node = first;

        for(int i = 0; i<pos-2; i++){
            node = node->next;
        }

        node -> next = new Node_t(val);
        node = node -> next;
        node -> next = next_node;

        }
	}

	int size()
	{
	    int list_size = 0;
	    Node_t* node = first;
		while(node)
        {
            list_size++;
            node = node -> next;

        }
        //std::cout << list_size << '\n';
        return list_size;
        }


	void erase(int pos) ///delete element with pos
	{
		Node_t* node = first;
		Node_t* prev = first;

        if(1 == pos){
            first = node-> next;
            delete node;
        }

        else{
        for(int i = 0; i<pos-1; i++){
            prev = node;
            node = node -> next;
        }

         prev -> next = node -> next;
        delete node;

        }
	}

	int clear()
	{
		Node_t*  node = first;
		Node_t* prev = first;
		while(node -> next)
        {
            prev = node;
            node = node->next;
            delete prev;
        }
        }


	int sort()   ///FIXME
	{
	    int k = size();
	    Node_t* node;
	    Node_t* node2;

	    for(node = first; node; node = node -> next){
            for(node2 = first; node2; node2 = node2 -> next){
                if(node -> value > node2 -> value){
                    int i = node -> value;
                    node -> value = node2 -> value;
                    node2 -> value = i;
                }
            }
	    }

		//TODO: Need to implement: Sort element in the list by ascending order
		//NOTE: It is really easy to do, if you have implemented push_back(), insert(), size(), and erase()
	}

	int reverse()
	{
	    Node_t* node = first;
	    Node_t* mem;
	    int k = size();


	    for(int i = k+1; i>0; i--){
            insert(i, node->value);
            node = node -> next;
            erase(1);

	    }

            }

};

List_t::List_t(int val)
{
	first = new Node_t(val);
}

List_t::~List_t()
{
	delete first;
}

void List_t::push_back(int val)
{
	Node_t* node = first;

	while(node -> next)
	{
		node = node -> next;
	}

	node -> next = new Node_t(val);
}


void List_t::pop_back() ///delete last element
{
    erase(size());
}



void List_t::print()
{
	Node_t* node = first;

	std::cout << "[";

	while(node)
	{
		std::cout << '\'' << node -> value << '\'';
		node = node -> next;
		if (node)
		{
			std::cout << ", ";
		}
	}

	std::cout << "]\n";
}
