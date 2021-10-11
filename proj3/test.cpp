#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;


#include "BinarySearchTree.cpp"

int main()
{
	{
		BinarySearchTree<int> bt;
		int n;
		time_t t = time(0);
		srand(t);
		for (int i = 0; i < 25; i++)
		{
			n = rand();
			cout << n << endl;
			bt.Add(n);
		}
		BinarySearchTree<int> bt2 = bt;
		bt = bt2;
		cout << "ENTER A NUMBER TO SEARCH: ";
		cin >> n;
		bool found = bt.Search(n);
		if (found)
			cout << "FOUND: " << n << endl;
		else
			cout << "NOT FOUND: " << n << endl;
		bt.Forward(DataHit);
		cout << endl;
		bt.Backward(DataHit);
		const int *p = bt.MaxValue();
		if (p)
		{
			cout << "MAX: " << *p << endl;
			cout << "MIN: " << *bt.MinValue() << endl;
		}
		cout << "COUNT: " << bt.Count() << endl;
		cout << "HEIGHT: " << bt.Height() << endl;
		cout << "BALANCING..." << endl;
		bt.Balance();
		cout << "COUNT: " << bt.Count() << endl;
		cout << "HEIGHT: " << bt.Height() << endl;
	}
	cout << endl;
	{
		BinarySearchTree<string> bt;
		string s;
		for (int i = 0; i < 20; i++)
		{
			char c[4] = { 0,0,0,0 };
			c[0] = c[1] = c[2] = ((rand() % 26) + 97);
			s = c;
			cout << s << endl;
			bt.Add(s);
		}
		cout << "ENTER A STRING TO SEARCH: ";
		cin >> s;
		bool found = bt.Search(s);
		if (found)
			cout << "FOUND: " << s << endl;
		else
			cout << "NOT FOUND: " << s << endl;
		bt.Forward(DataHit);
		cout << endl;
		bt.Backward(DataHit);
		const string *p = bt.MaxValue();
		if (p)
		{
			cout << "MAX: " << *p << endl;
			cout << "MIN: " << *bt.MinValue() << endl;
		}
	}
	{
		BinarySearchTree<Person> people;
		Person *temp[] = {
			new Person("Vince", "Young"),
			new Person("Xavier", "Taylor"),
			new Person("John", "Williams"),
			new Person("Angela", "Taylor"),
			new Person("Sam", "Smith"),
			new Person("Julie", "Simms"),
			new Person("Susie", "Williams"),
			new Person("John", "Brown"),
			new Person("Will", "White"),
			new Person("John", "White"),
			new Person("Jill", "Flowers")
		};
		for (int i = 0; i < sizeof(temp) / sizeof(Person *); i++)
		{
			people.Add(*temp[i]);
			delete temp[i];
			temp[i] = nullptr;
		}
		cout << endl;
		people.Forward(DataHit);
		cout << endl;
		people.Backward(DataHit);
		cout << endl;
	}
	return 0;
}