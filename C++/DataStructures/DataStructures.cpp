#include "DataStructures.h"

int Choice;
string ChoiceStr;
int num;

int main()
{
    cout << "Data Structures" << endl;

    cout << "1: Linked List" << endl;

    cout << "2: Stack" << endl;

    cout << "3: Queue" << endl;

    cout << "4: Binary Tree" << endl;

    cout << "5: Vector" << endl;

    cout << "Choose Which Data Structure" << endl;

    cin >> ChoiceStr;

    Choice = stoi(ChoiceStr);

    cout << "Enter Numbers To Be In The List, Type STOP Or Any Letters To Stop Input" << endl;

    SelectWhich();

    return 0;
}

void SelectWhich()
{
    switch (Choice)
    {
        case 1:
            LinkedListFunc();
            break;

        case 2:
            StackFunc();
            break;

        case 3:
            QueueFunc();
            break;

        case 4:
            BinaryTreeFunc();
            break;

        case 5:
            VectorFunc();
            break;

        default:
            cout << "Choice isn't valid, quitting...";
            break;
    }
}

void LinkedListFunc()
{
    LinkedList<int> List;

    string input;
    while (true)
    {
        cin >> input;
        if (input == "STOP")
        {
            cout << "Stop entered, stopping recieving input\n";
            cout << endl;

            break;
        }

        try
        {
            num = stoi(input);
        }
        catch (...)
        {
            cout << "Letters entered, stopping recieving input\n";
            cout << endl;

            break;
        }

        List.PushFront(num);
    }

    cout << "Front element: " << List.Front() << endl;
    cout << "Size of the list: " << List.GetSize() << endl;

    List.PopFront();

    cout << endl;

    cout << "Front element after pop: " << List.Front() << endl;
    cout << "Size of the list after pop: " << List.GetSize() << endl;

    cout << "Size of the list after pop: " << List.GetSize() << endl;

    cout << "What Element Index Do You Want To Get?" << endl;

    int elementnum;
    string elementnumstr;

    cin >> elementnumstr;

    try
    {
        elementnum = stoi(elementnumstr);
        cout << "Get Element Data: " << List.GetElement(elementnum) << endl;
    }
    catch(...)
    {
        cout << "Input entered is not a number, quitting" << endl;
    }

    cout << "Print Out Entire List? Y/N" << endl;

    char printlistchar;

    cin >> printlistchar;

    printlistchar = toupper(printlistchar);

    if (printlistchar == 'Y')
    {
        List.PrintList();
    }
    else
    {
        return;
    }
}

void StackFunc()
{
    stack<int> Stack;
    string input;
    while (true)
    {
        cin >> input;
        if (input == "STOP")
        {
            cout << "Stop entered, stopping recieving input\n";
            cout << endl;

            break;
        }

        try
        {
            num = stoi(input);
        }
        catch (...)
        {
            cout << "Letters entered, stopping recieving input\n";
            cout << endl;

            break;
        }

        Stack.push(num);
    }

    cout << "Top element of stack: " << Stack.top() << std::endl;

    Stack.pop();

    cout << "Top element of stack after pop: " << Stack.top() << std::endl;

    if (Stack.empty())
    {
        cout << "Stack is empty" << std::endl;
    }
    else
    {
        cout << "Stack is not empty" << std::endl;
    }

    cout << "Size of stack: " << Stack.size() << std::endl;

    cout << "Print Out Entire Stack? Y/N" << endl;

    char printstackchar;

    cin >> printstackchar;

    printstackchar = toupper(printstackchar);

    if (printstackchar == 'Y')
    {
        while (Stack.empty() == false)
        {
            cout << Stack.top() << endl;
            Stack.pop();
        }
    }
    else
    {
        return;
    }
}

void QueueFunc()
{
    queue<int> Queue;
    string input;
    while (true)
    {
        cin >> input;
        if (input == "STOP")
        {
            cout << "Stop entered, stopping recieving input\n";
            cout << endl;

            break;
        }

        try
        {
            num = stoi(input);
        }
        catch (...)
        {
            cout << "Letters entered, stopping recieving input\n";
            cout << endl;

            break;
        }

        Queue.push(num);
    }

    cout << "Front element: " << Queue.front() << endl;
    cout << "Back element: " << Queue.back() << endl;

    Queue.pop();

    cout << "Front element after pop: " << Queue.front() << endl;

    if (Queue.empty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }

    cout << "Size of the queue: " << Queue.size() << endl;

    cout << "Print Out Entire Queue? Y/N" << endl;

    char printqueuechar;

    cin >> printqueuechar;

    printqueuechar = toupper(printqueuechar);

    if (printqueuechar == 'Y')
    {
        while (Queue.empty() == false)
        {
            cout << Queue.front() << endl;
            Queue.pop();
        }
    }
    else
    {
        return;
    }
}

void BinaryTreeFunc()
{
    BinaryTree tree(1);
    string input;
    while (true)
    {
        cin >> input;
        if (input == "STOP")
        {
            cout << "Stop entered, stopping recieving input\n";
            cout << endl;

            break;
        }

        try
        {
            num = stoi(input);
        }
        catch (...)
        {
            cout << "Letters entered, stopping recieving input\n";
            cout << endl;

            break;
        }

        tree.Insert(num);
    }

    cout << "Enter A Number To Search For In The Binary Tree: " << endl;

    cin >> ChoiceStr;

    try
    {
        Choice = stoi(ChoiceStr);


        bool isFound = tree.Search(tree.root, Choice);
        if (isFound)
        {
            cout << "Value " << Choice << " is found in the binary tree." << endl;
        }
        else {
            cout << "Value " << Choice << " is not found in the binary tree." << endl;
        }
    }
    catch (...)
    {
        cout << "Entered Value Is Not A Number... Skipping. \n";
        cout << endl;
    }

    // Removing a value from the binary tree
    cout << "Enter A Value To Remove: " << endl;

    cin >> ChoiceStr;

    try
    {
        Choice = stoi(ChoiceStr);

        tree.RemoveElement(tree.root, Choice);

        // Printing all nodes in the binary tree
        cout << "Printing all nodes in the binary tree:" << endl;
        tree.SearchAllNodes(tree.root);
    }
    catch (...)
    {
        cout << "Entered Value Is Not A Number, quitting \n";
        cout << endl;
    }
}

void VectorFunc()
{
    vector<int> vec;
    string input;

    int* i = 0;

    while (true)
    {
        cin >> input;
        if (input == "STOP")
        {
            cout << "Stop entered, stopping recieving input\n";
            cout << endl;

            break;
        }

        try
        {
            num = stoi(input);
        }
        catch (...)
        {
            cout << "Letters entered, stopping recieving input\n";
            cout << endl;

            break;
        }
    }

    cout << "Print All Elements Of Vector: " << endl;

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }

    cout << endl;

    // Modify elements //

    cout << "Modify Element At Which Index?: " << endl;
    string vecelementindex;
    cin >> vecelementindex;

    int vecelementindexint = stoi(vecelementindex);

    cout << "Change Element To What?: " << endl;
    string vecelement;
    cin >> vecelement;

    int vecelementint = stoi(vecelement);

    vec[vecelementindexint] = vecelementint;
    cout << "Modified element at index " << vecelementindex << " : " << vec[vecelementindexint] << endl;

    // Size and capacity //

    cout << "Size of the vector: " << vec.size() << endl;
    cout << "Capacity of the vector: " << vec.capacity() << endl;

    cout << endl;

    // Resize the vector //

    cout << "Resize Vector Too? : " << endl;
    string resizevec;
    cin >> resizevec;

    int resizevecint = stoi(resizevec);
    vec.resize(resizevecint);

    cout << "Size of the vector after resizing: " << vec.size() << endl;

    cout << endl;

    // Sorting elements //

    sort(vec.begin(), vec.end());
    cout << "Sorted vector elements: ";

    for (int num : vec)
    {
        cout << num << endl;
    }

    cout << endl;

    // Check if vector is empty //

    if (vec.empty())
    {
        cout << "Vector is empty" << endl;
    }
    else
    {
        cout << "Vector is not empty" << endl;
    }

    cout << endl;

    // Clear the vector//

    vec.clear();
    cout << "Size of the vector after clearing: " << vec.size() << endl;
}