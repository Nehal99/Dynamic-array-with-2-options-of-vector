// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 2 - Problem 8
// Program: Dynamic Array
// Purpose: Dynamic Array with two options of vector
// Author:  Nehal Akram Ahmed
// Date:    22 September  2018
// Version: 1.0

#include <iostream>

using namespace std;

string* addEntry(string *dynamicArray, int &siz, string newEntry)
{
    string* name1 = new string[siz+1] ;

    for (int i = 0 ; i < siz ; i++)
    {
        name1[i] = dynamicArray[i] ;
    }
    name1[siz] = newEntry;

    delete [] dynamicArray ;

    return name1 ;
}

int isFound (string *dynamicArray, int &siz, string entryToDelete)
{
    for (int i = 0 ; i < siz ; i++)
    {
        if (dynamicArray[i] == entryToDelete)
        {
            return (i+1) ;
        }
    }
    return 0 ;
}

string* deleteEntry(string *dynamicArray, int &siz, string entryToDelete)
{
    int x ;

    x = isFound(dynamicArray, siz, entryToDelete) ;

    if( x != 0 )
    {
        string* name2 = new string[siz-1] ;

        --x ;

        for (int j = x ; j < siz-1 ; j++)
        {
            dynamicArray[j] = dynamicArray[j+1] ;
        }

        for (int k = 0 ; k < (siz - 1) ; k++)
        {
            name2[k] = dynamicArray[k] ;
        }

        delete [] dynamicArray ;

        return name2 ;
    }

    if ( x==0 )
    {
        return dynamicArray ;
    }
}

int main()
{
    int x=5 , choice ;

    string word ;

    string* name = new string [x] ;

    cout << "Enter 5 names of your choice " << endl;

    for (int i = 0 ; i < 5 ; i++)
    {
        cin >> name[i] ;
    }

    cout << "1- Add New Entry " << endl << "2- Delete Entry " << endl ;
    cin >> choice ;

    if (choice == 1)
    {
        cout << "New Entry : " ;
        cin >> word ;

        name = addEntry(name, x, word ) ;

        for (int i = 0 ; i < 6 ; i++)
        {
            cout << name[i] << " " ;
        }
    }

    if (choice == 2)
    {
        cout << "Enter word to be deleted : "  ;
        cin >> word ;

        name = deleteEntry(name, x, word ) ;

        for (int i = 0 ; i < x ; i++)
        {
            cout << name[i] << " " ;
        }
    }

    delete [] name ;
}
