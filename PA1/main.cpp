#include <iostream>
using namespace std;
#include "AbstractStack.h"
#include "StackArrayDouble.h"
#include "StackArrayLinear.h"
#include "StackLinkedList.h"
#include <chrono> 
using namespace std;

int main() {
    // Write your own tests here

   StackLinkedList<int> *test;

   for (int i = 0; i < 100; i++)
   {
    auto start = std::chrono::high_resolution_clock::now();

    test->push(1);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;

    cout << duration.count() << endl;
   }
   

    return 0;
}