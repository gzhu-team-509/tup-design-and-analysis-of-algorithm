#include <list>
#include <iostream>
using namespace std;

int main()
{
	list<int> mylist (5,100); 	//5��100  
	mylist.push_front(-13);
	mylist.push_back (300); 	//��β����    
	list<int> :: iterator it = mylist.begin();  
	//ɾ��Ԫ��   
	mylist.erase(it);  
	//������� 
	for (it=mylist.begin(); it!=mylist.end(); ++it)  
		cout << " " << *it;  
	cout << endl;
	mylist.clear(); 
	return 0;
}  

