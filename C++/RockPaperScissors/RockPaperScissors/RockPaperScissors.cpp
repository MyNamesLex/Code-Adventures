#include <iostream>
#include <cstdlib>

using namespace std;

void Player();
void AI();
void Final();
void srand(unsigned int seed);

string yesorno;
string yes = "Yes";
string no = "No";

string aichoice;
string choice;

string press;

string rock = "Rock";
string paper = "Paper";
string scissors = "Scissors";

int main()
{
    cout << "Rock Paper Scissors" << endl;

    cout << "This game is you versus an AI" << endl;

    cout << "Enter any key to start" << endl;

    cin >> press;
    Player();
}


void Player()
{
    cout << endl;

    cout << "Choose either rock, paper or scissors by typing 'Rock' , 'Paper' or 'Scissors' into the console (Capitalise) ";
    cin >> choice;

    if (choice == rock)
    {
        AI();
        return;
    }
    if (choice == paper)
    {
        AI();
        return;
    }
    if (choice == scissors)
    {
        AI();
        return;
    }

    cout << "Choice not found, you typed " + choice << endl;
    Player();
}

void AI()
{
    int max;
    max = 3;

    srand(time(0));

    int rng = (rand() % max) + 1;

    switch (rng)
    {
        case 1:
            aichoice = rock;
            Final();
            break;

        case 2:
            aichoice = paper;
            Final();
            break;

        case 3:
            aichoice = scissors;
            Final();
            break;
    }
}

void Final()
{
    cout << endl;

    if (aichoice == choice)
    {
        cout << "The game was a draw" << endl;
        cout << "AI chose " + aichoice << endl;
        cout << "You chose " + choice << endl;

        cout << endl;
        cout << "Would you like to play again? Please type 'Yes' or 'No'(Capitalise) ";
        cin >> yesorno;

        if (yesorno == yes)
        {
            Player();
        }
        if (yesorno == no)
        {
            return;
        }

    }
    if (aichoice == rock)
    {
        if (choice == scissors)
        {
            cout << "You lost!" << endl;
            cout << "AI chose " + aichoice << endl;
            cout << "You chose " + choice << endl;

            cout << endl;
            cout << "Would you like to play again? Please type 'Yes' or 'No'(Capitalise) ";
            cin >> yesorno;

            if (yesorno == yes)
            {
                Player();
            }
            if (yesorno == no)
            {
                return;
            }
        }

        if (choice == paper)
        {
            cout << "You won!" << endl;
            cout << "AI chose " + aichoice << endl;
            cout << "You chose " + choice << endl;

            cout << endl;
            cout << "Would you like to play again? Please type 'Yes' or 'No'(Capitalise) ";
            cin >> yesorno;

            if (yesorno == yes)
            {
                Player();
            }
            if (yesorno == no)
            {
                return;
            }
        }

    }

    if (aichoice == paper)
    {
        if (choice == scissors)
        {
            cout << "You won!" << endl;
            cout << "AI chose " + aichoice << endl;
            cout << "You chose " + choice << endl;

            cout << endl;
            cout << "Would you like to play again? Please type 'Yes' or 'No'(Capitalise) ";
            cin >> yesorno;

            if (yesorno == yes)
            {
                Player();
            }
            if (yesorno == no)
            {
                return;
            }
        }

        if (choice == rock)
        {
            cout << "You lost!" << endl;
            cout << "AI chose " + aichoice << endl;
            cout << "You chose " + choice << endl;

            cout << endl;
            cout << "Would you like to play again? Please type 'Yes' or 'No'(Capitalise) ";
            cin >> yesorno;

            if (yesorno == yes)
            {
                Player();
            }
            if (yesorno == no)
            {
                return;
            }
        }

    }

    if (aichoice == scissors)
    {
        if (choice == rock)
        {
            cout << "You won!" << endl;
            cout << "AI chose " + aichoice << endl;
            cout << "You chose " + choice << endl;

            cout << endl;
            cout << "Would you like to play again? Please type 'Yes' or 'No'(Capitalise) ";
            cin >> yesorno;

            if (yesorno == yes)
            {
                Player();
            }
            if (yesorno == no)
            {
                return;
            }
        }

        if (choice == paper)
        {
            cout << "You lost!" << endl;
            cout << "AI chose " + aichoice << endl;
            cout << "You chose " + choice << endl;

            cout << endl;
            cout << "Would you like to play again? Please type 'Yes' or 'No'(Capitalise) ";
            cin >> yesorno;

            if (yesorno == yes)
            {
                Player();
            }
            if (yesorno == no)
            {
                return;
            }
        }

    }
}