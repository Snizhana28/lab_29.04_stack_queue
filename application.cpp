#include "stack.h"
#include "Queue.h"

int main()
{
	cout << "Stack:" << endl;
	stack<int> s;
	cout << "<----------------------------->" << endl;
	s.push_back(1);
	s.push_back(2);
	s.push_back(3);
	s.push_back(4);
	s.print();
	cout << "<----------------------------->" << endl;
	s.pop_back();
	s.print();
	cout << "<----------------------------->" << endl << endl;


	cout << "Queue:" << endl;
	cout << "<----------------------------->" << endl;
	Queue<int> q;
	q.push_back(1);
	q.push_back(2);
	q.push_back(3);
	q.push_back(4);
	q.print();
	cout << "<----------------------------->" << endl;
	q.pop_back();
	q.print();
	cout << "<----------------------------->" << endl;
	q.pop_front();
	q.print();
	cout << "<----------------------------->" << endl;
	q.push_front(5);
	q.print();
	cout << "<----------------------------->" << endl;

	return 0;
}