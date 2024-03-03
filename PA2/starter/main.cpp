#include <iostream>
#include "deque.h"
using namespace std;

int main() {


    {
        Deque<int> x; // initialize with default constructor

        cout << endl << "Default Constructor Tests: " << endl; // test what some values are
        cout << "Size: " << x.size() << endl;
        cout << "First: " << x.first() << endl;
        cout << "Last: " << x.last() << endl;

        x.insertFirst(3); 
        x.insertFirst(2);
        x.insertFirst(1);

        // Now the deque should be [1, 2, 3]

        Deque<int> y(x); // use copy constructor
        cout << endl << "Copy Constructor Tests: " << endl;

        cout << "Size (x): " << x.size() << endl;
        cout << "First (x): " << x.first() << endl;
        cout << "Last (x): " << x.last() << endl;
        cout << endl;
        cout << "Size (y): " << y.size() << endl;
        cout << "First (y): " << y.first() << endl;
        cout << "Last (y): " << y.last() << endl;

        // x and y should be the same


        Deque<int> z = x;
        cout << endl << "Copy Assignment Tests: " << endl;
        cout << "Size (x): " << x.size() << endl;
        cout << "First (x): " << x.first() << endl;
        cout << "Last (x): " << x.last() << endl;
        cout << endl;
        cout << "Size (z): " << z.size() << endl;
        cout << "First (z): " << z.first() << endl;
        cout << "Last (z): " << z.last() << endl;

        // x and z should be the same


        z.~Deque(); // test destructor values should now be the default values
        cout << endl << "Destructor Tests: " << endl;
        cout << "Size: " << z.size() << endl;
        cout << "First: " << z.first() << endl;
        cout << "Last: " << z.last() << endl;


        // x should be false, z should be true
        cout << endl << "isEmpty() Tests: " << endl;
        cout << "x: " << x.isEmpty() << endl;
        cout << "z: " << z.isEmpty() << endl;


        // x should be 3, z should be 0
        cout << endl << "size() Tests: " << endl;
        cout << "x: " << x.size() << endl;
        cout << "z: " << z.size() << endl;


        // x should be 1, z should be 0
        cout << endl << "first() Tests: " << endl;
        cout << "x: " << x.first() << endl;
        cout << "z: " << z.first() << endl;


        // x should be 3, z should be 0
        cout << endl << "last() Tests: " << endl;
        cout << "x: " << x.last() << endl;
        cout << "z: " << z.last() << endl;


        x.insertFirst(10);
        y.insertFirst(20);
        cout << endl << "insertFirst() Tests: " << endl;
        cout << "x: " << x.first() << endl;
        cout << "y: " << y.first() << endl;


        x.insertLast(35);
        y.insertLast(87);
        cout << endl << "insertLast() Tests: " << endl;
        cout << "x: " << x.last() << endl;
        cout << "y: " << y.last() << endl;


        cout << endl << "removeFirst() Tests: " << endl;
        cout << "x: " << x.removeFirst() << endl;
        cout << "y: " << y.removeFirst() << endl;


        cout << endl << "removeLast() Tests: " << endl;
        cout << "x: " << x.removeLast() << endl;
        cout << "y: " << y.removeLast() << endl;
        cout << endl;

    
    }






    // Test insertFirst
    {
        Deque<int> q;
        q.insertFirst(3);
        q.insertFirst(2);
        q.insertFirst(1);

        // Now the deque should be [1, 2, 3]
        
        if (q.size() != 3) {
            cout << "Test insertFirst failed: Incorrect size" << endl;
            
        } else if (q.first() != 1 || q.last() != 3) {
            cout << "Test insertFirst failed: Incorrect elements" << endl;
   
        } else {
            cout << "Test insertFirst passed" << endl;
        }
        
    }
    
    // Test insertLast
    {
        Deque<int> q;
        q.insertLast(1);
        q.insertLast(2);
        q.insertLast(3);
        
        // Now the deque should be [1, 2, 3]
        
        if (q.size() != 3) {
            cout << "Test insertLast failed: Incorrect size" << endl;
        } else if (q.first() != 1 || q.last() != 3) {
            cout << "Test insertLast failed: Incorrect elements" << endl;
        } else {
            cout << "Test insertLast passed" << endl;
        }
        
    }

    return 0;
}