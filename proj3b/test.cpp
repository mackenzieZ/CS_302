//main.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//BinarySearchTree.h

#include "binarySearchTree.hpp"


template <class ItemType>
void my_visit(ItemType& val);


int main()
{

    //seed random number generator, allocate arrays, declare variables
    srand( time(NULL) );

    int tree1Values[100];

    int index;

    int index2;

    int temp;

    bool unique;

    bool overlap;

    //print title

    cout << endl << "CBinary Search Tree Testing Program" << endl << endl;

    //generate 100 random values, put them in tree1Values array



    for ( int i  = 1; i <= 100; i++ )
    {

        //generate a unique value

        unique = false;

        while ( !unique )
        {

            unique = true;

            temp = 1 + ( rand() % 200 );

            for ( int j  = 0; j < i - 1; j++ )
            {

                if ( temp == tree1Values[j] )
                    unique = false;

            }

        }

        //add the unique value to the array

        tree1Values[i-1] = temp;

        //display the value



    }

    cout << endl;

    //create BST 1 and add the values from the tree1Values array

    cout << "Adding the values to BST 1 ..." << endl << endl;

    BinarySearchTree<int> test1;

    for ( int i = 0; i < 100; i++ ){
        test1.add( tree1Values[i] );
    }
    //print the height of the tree

    cout << "BST 1 height = " << test1.getHeight() << endl << endl;
 


    //print the preorder, inorder, and postorder outputs of BST1

    cout << "BST 1 print (preorder): " << endl;

    test1.preorderTraverse(my_visit);

    cout << endl << endl;

    cout << "BST 1 print (inorder): " << endl;

    test1.inorderTraverse(my_visit);

    cout << endl << endl;

    cout << "BST 1 print (postorder): " << endl;

    test1.postorderTraverse(my_visit);

    cout << endl << endl;


    //end program

    cout << "Ending Binary Search Tree Testing Program ..." << endl << endl;

    return 0;

}

template <class ItemType>
void my_visit(ItemType& val)
{
    cout << val << ' ';
}

