// SortingAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "SortingAlgorithms.h"

using namespace std;

int selection;
int num;

vector<int> numsToSort;

bool PrintProgress;
char PrintProgressResponse;
string PrintProgressResponseString;

int main()
{
    // ASK USER WHICH SORTING ALGORITHM //

    cout << "Sorting Algorithms! Pick Which Algorithm\n";
    cout << "1: Bubble Sort\n";
    cout << "2: Selection Sort\n";
    cout << "3: Insertion Sort\n";
    cout << endl;

    cin >> selection;

    // ASK IF USER WANTS TO SEE THE ALGORITHM WORK //

    cout << "Do You Want To See The Progress Of The Sorting Algorithm Work? Y/N \n";
    cout << endl;

    cin >> PrintProgressResponse;

    PrintProgressResponse = toupper(PrintProgressResponse);

    PrintProgressResponseString = PrintProgressResponse;

    if (PrintProgressResponseString == "Y")
    {
        PrintProgress = true;
    }
    else if (PrintProgressResponseString == "N")
    {
        PrintProgress = false;
    }

    // ASK USER FOR NUMBERS TO SORT //

    cout << "Enter Numbers To Sort: To Stop Type 'STOP' Or Any Letters\n";
    cout << endl;

    string input;
    while (true)
    {
        cin >> input;
        if (input == "STOP")
        {
            cout << "STOP ENTERED, STOPPING RECEIVING NUMBER INPUT \n";
            cout << endl;

            break;
        }

        try
        {
            num = stoi(input);
        }
        catch(...)
        {
            cout << "LETTERS ENTERED, STOPPING RECEIVING NUMBER INPUT \n";
            cout << endl;

            break;
        }

        numsToSort.push_back(num);
    }

    SelectWhich();

    return 0;
}

static void SelectWhich()
{
    switch (selection)
    {
        case 1:
            BubbleSort();
            break;
        case 2:
            SelectionSort();
            break;
        case 3:
            InsertionSort();
            break;
        default:
            cout << "NOT A VALID SELECTION FOR SORTING ALGORITHM, RESTART\n";
            cout << endl;

            selection = 0;
            numsToSort.clear();
            num = 0;

            main();

            break;
    }
}

void BubbleSort()
{
    cout << "1: Bubble Sort\n";

    int size = numsToSort.size();

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (numsToSort[j] > numsToSort[j + 1]) // if numsToSort[j] > numsToSort[j + 1] swap them
            {
                int temp = numsToSort[j];
                numsToSort[j] = numsToSort[j + 1];
                numsToSort[j + 1] = temp;
            }

            if (PrintProgress == true) // print to the console the work in progress of sorting of the vector
            {
                cout << "Pass " << i + 1 << ": ";
                for (int n : numsToSort)
                {
                    cout << n << " ";
                }

                cout << endl;
            }
        }
    }
}

void SelectionSort()
{
    cout << "2: Selection Sort\n";

    int size = numsToSort.size();

    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) // iterate through numsToSort , if numsToSort[j] less then numsToSort[minIndex], set minIndex to j
        {
            if (numsToSort[j] < numsToSort[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != 1) // Swap numsToSort[i] And numsToSort[minIndex] if minIndex isn't equal to 1
        {
            int temp = numsToSort[i];
            numsToSort[i] = numsToSort[minIndex];
            numsToSort[minIndex] = temp;
        }

        if (PrintProgress == true) // print to the console the work in progress of sorting of the vector
        {
            cout << "Pass " << i + 1 << ": ";
            for (int n : numsToSort)
            {
                cout << n << " ";
            }

            cout << endl;
        }
    }
}

void InsertionSort()
{
    int size = numsToSort.size();

    for (int i = 0; i < size; i++)
    {
        int indexToCheck = numsToSort[i];

        int j = i - 1;

        while (j >= 0 && numsToSort[j] > indexToCheck) // if j is in the vector bounds and numsToSort[j] greater then indexToCheck
        {
            numsToSort[j + 1] = numsToSort[j]; // shift elements to the right and decrement j to move to the previous position
            j = j - 1;
        }
        numsToSort[j + 1] = indexToCheck; // set index to correct position

        if (PrintProgress == true) // print to the console the work in progress of sorting the vector
        {
            cout << "Pass " << i + 1 << ": ";
            for (int n : numsToSort)
            {
                cout << n << " ";
            }

            cout << endl;
        }
    }
}