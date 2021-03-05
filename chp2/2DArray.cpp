#include <iostream>
using namespace std;

int main()
{
    int l2DArray[3][2];
    int k = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            l2DArray[i][j] = k++;
            cout << l2DArray[i][j] << "\t";
        }
        cout << endl;
    }
    int **l2DArrayInHeap = new int *[4];

    for (int i = 0; i < 4; i++)
    {
        l2DArrayInHeap[i] = new int[3];
    }
    int k2 = 100;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            l2DArrayInHeap[i][j] = k++;
            cout<<l2DArrayInHeap[i][j] <<"\t" ;
        }
        cout <<endl;
    }
    for (int i = 0; i < 4; i++)
    {
         delete[] l2DArrayInHeap[i];
    }
   delete[] l2DArrayInHeap;
    return 0;
}