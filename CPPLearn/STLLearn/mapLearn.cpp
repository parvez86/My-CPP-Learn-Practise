#include <string.h>
#include <iostream>
#include <map>
#include <utility>

using namespace std;
int main()
{
   map<int, string> Employees;
   // 1) Assignment using array index notation
   Employees[101] = "Nikita";
   Employees[105] = "John";
   Employees[103] = "Dolly";
   Employees[104] = "Deep";
   Employees[102] = "Aman";

   cout << "Employees[104]=" << Employees[104] << endl;
   cout << "Map size: " << Employees.size() << endl;
   cout << endl << "Natural Order:" << endl;
   for( map<int,string>::iterator it=Employees.begin(); it!=Employees.end(); ++it)
   {
       cout << (*it).first << ": " << (*it).second << endl;
   }
   cout << endl << "Reverse Order:" << endl;
   for( map<int,string>::reverse_iterator it=Employees.rbegin(); it!=Employees.rend(); ++it)
   {
       cout << (*it).first << ": " << (*it).second << endl;
   }

   cout<< endl<< "Using auto: "<< endl;
   for(const auto item:Employees) cout<< item.first<< ": "<< item.second<< endl;

   cout<< endl<< endl;
   for(auto item=Employees.begin(); item!=Employees.end(); ++item) cout<< item->first<< ": "<< item->second<< endl;


   cout<< endl<< "Using reverse auto: "<< endl;
   for(auto item=Employees.rbegin(); item!=Employees.rend(); ++item) cout<< item->first<< ": "<< item->second<< endl;

   /*
    functions: insert, emplace, emplace_hint, erase, clear,
    at, swap, find, count
   */
   Employees.insert(pair<int, string> (106, "Ariyan"));
   cout<< endl<< endl;
   for(auto item=Employees.cbegin(); item!=Employees.cend(); ++item) cout<< item->first<< ": "<< item->second<< endl;

   Employees.erase(106);
   cout<< endl<< "After removing an element: "<< endl;
   for(auto item=Employees.cbegin(); item!=Employees.cend(); ++item) cout<< item->first<< ": "<< item->second<< endl;

   Employees.clear();
   cout<< endl<<"After deleting all files"<< endl;
   for(auto item=Employees.cbegin(); item!=Employees.cend(); ++item) cout<< item->first<< ": "<< item->second<< endl;

}
