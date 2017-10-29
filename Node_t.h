struct Node_t
{
	int value;
	Node_t* next;

	Node_t(int val);
	~Node_t();
};

Node_t::Node_t(int val)
{
	value = val;
	next  = 0;
}

Node_t::~Node_t()
{
	value = 666;
	next  = 0;
}




