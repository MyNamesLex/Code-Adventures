#include <iostream>
#include <cstdlib>

using namespace std;

//start choice string
string press;

//bools for strings

bool Gamer = false;
bool Being = false;
bool MadeWord = false;

//words

string G = "G";
string A = "A";
string M = "M";
string E = "E";
string R = "R";


//
string B = "B";
string I = "I";
string N = "N";

//two player
string firstletter;
string secondletter;
string thirdletter;
string fourthletter;
string fifthletter;


//chances

string guess1;
string guess2;
string guess3;
string guess4;
string guess5;

//placeholder for none guess letters

string blank = "*";

//flags to replace blanks when letter found
bool letter1 = false;
bool letter2 = false;
bool letter3 = false;
bool letter4 = false;
bool letter5 = false;

//hangman bools
bool fail1 = false;
bool fail2 = false;
bool fail3 = false;
bool fail4 = false;
bool fail5 = false;
bool fail6 = false;
bool fail7 = false;


//functions
void srand(unsigned int seed);

//ai make word
void MakeWord();

//Two player, player makes word for person to guess
void TwoWord();

//guess loop
void Guess();

//drawing hangman
void Hangman();

//win lose functions
void Lose();
void Win();

int main()
{
    cout << "Hangman" << endl;

    cout << "This game is you versus an AI which will pick a random word out of a prechosen list" << endl;

    cout << "Enter 'S' to play against the AI or 'T' for two player" << endl;

    cin >> press;

    //singleplayer
    if (press == "S")
    {
        MakeWord();
    }
    //two player
    else if(press == "T")
    {
        TwoWord();
    }
    //failsafe
    else
    {
        cout << endl;
        cout << "Letter entered was " + press + " Please try again" << endl;
        cout << endl;
        main();
    }
}

void TwoWord()
{
    MadeWord = true;

    cout << "Enter a five letter word by entering a letter every line (No repeating letters)" << endl;

    cin >> firstletter;
    cin >> secondletter;
    cin >> thirdletter;
    cin >> fourthletter;
    cin >> fifthletter;
    Guess();
}

void MakeWord()
{
    int max;
    max = 2;

    srand(time(0));

    int rng = (rand() % max) + 1;

    switch (rng)
    {
        case 1:
            Gamer = true;
            Guess();
            break;
        case 2:
            Being = true;
            Guess();
            break;
    }
}

void Guess()
{
    if (MadeWord == true)
    {
        if (letter1 && letter2 && letter3 && letter4 && letter5 == true)
        {
            cout << "The word is " + firstletter + secondletter + thirdletter + fourthletter + fifthletter;
            Win();
            return;
        }
        if (fail1 && fail2 && fail3 && fail4 && fail5 && fail6 && fail7)
        {
            cout << "The word is " + firstletter + secondletter + thirdletter + fourthletter + fifthletter;
            Lose();
            return;
        }
        cout << endl;

        cout << "Word has been entered, please try to guess it by typing in a letter and pressing enter" << endl;

        cout << "The word is ";

        if (letter1 == true)
        {
            cout << firstletter;
        }
        if (letter1 == false)
        {
            cout << blank;
        }

        if (letter2 == true)
        {
            cout << secondletter;
        }
        if (letter2 == false)
        {
            cout << blank;
        }

        if (letter3 == true)
        {
            cout << thirdletter;
        }
        if (letter3 == false)
        {
            cout << blank;
        }

        if (letter4 == true)
        {
            cout << fourthletter;
        }
        if (letter4 == false)
        {
            cout << blank;
        }

        if (letter5 == true)
        {
            cout << fifthletter;
        }
        if (letter5 == false)
        {
            cout << blank;
        }

        cin >> guess1;

        if (guess1 == firstletter)
        {
            cout << endl;
            cout << "That was correct, the word " + firstletter + blank + blank + blank + blank << endl;
            letter1 = true;
            Guess();
        }
        else if (guess1 == secondletter)
        {
            cout << endl;
            cout << "That was correct, the word " + blank + secondletter + blank + blank + blank << endl;
            letter2 = true;
            Guess();
        }
        else if (guess1 == thirdletter)
        {
            cout << endl;
            cout << "That was correct, the word " + blank + blank + thirdletter + blank + blank << endl;
            letter3 = true;
            Guess();
        }
        else if (guess1 == fourthletter)
        {
            cout << endl;
            cout << "That was correct, the word " + blank + blank + blank + fourthletter + blank << endl;
            letter4 = true;
            Guess();
        }
        else if (guess1 == fifthletter)
        {
            cout << endl;
            cout << "That was correct, the word " + blank + blank + blank + blank + fifthletter << endl;
            letter5 = true;
            Guess();
        }
        else
        {
            cout << endl;
            cout << "That letter is not in the word the AI chose, please choose again" << endl;
            Hangman();
        }
    }

    if (Gamer == true)
    {
        if (letter1 && letter2 && letter3 && letter4 && letter5 == true)
        {
            cout << "The word is " + B + E + I + N + G;
            Win();
            return;
        }
        if (fail1 && fail2 && fail3 && fail4 && fail5 && fail6 && fail7)
        {
            cout << "The word is " + B + E + I + N + G;
            Lose();
            return;
        }
        cout << endl;

        cout << "The Ai has chosen a word, please guess the word by typing a letter into the console and confirming it by pressing ENTER (Type in capitals) " << endl;

        cout << "The word is ";

        if (letter1 == true)
        {
            cout << G;
        }
        if (letter1 == false)
        {
            cout << blank;
        }

        if (letter2 == true)
        {
            cout << A;
        }
        if (letter2 == false)
        {
            cout << blank;
        }

        if (letter3 == true)
        {
            cout << M;
        }
        if (letter3 == false)
        {
            cout << blank;
        }

        if (letter4 == true)
        {
            cout << E;
        }
        if (letter4 == false)
        {
            cout << blank;
        }

        if (letter5 == true)
        {
            cout << R;
        }
        if (letter5 == false)
        {
            cout << blank;
        }

        cin >> guess1;

        if (guess1 == G)
        {
            cout << endl;
            cout << "That was correct, the word " + G + blank + blank + blank + blank << endl;
            letter1 = true;
            Guess();
        }
        else if (guess1 == A)
        {
            cout << endl;
            cout << "That was correct, the word " + blank + A + blank + blank + blank << endl;
            letter2 = true;
            Guess();
        }
        else if (guess1 == M)
        {
            cout << endl;
            cout << "That was correct, the word " + blank + blank + M + blank + blank << endl;
            letter3 = true;
            Guess();
        }
        else if (guess1 == E)
        {
            cout << endl;
            cout << "That was correct, the word " + blank + blank + blank + E + blank << endl;
            letter4 = true;
            Guess();
        }
        else if (guess1 == R)
        {
            cout << endl;
            cout << "That was correct, the word " + blank + blank + blank + blank + R << endl;
            letter5 = true;
            Guess();
        }
        else
        {
            cout << endl;
            cout << "That letter is not in the word the AI chose, please choose again" << endl;
            Hangman();
        }
    }

    if (Being == true)
    {
        if (letter1 && letter2 && letter3 && letter4 && letter5 == true)
        {
            cout << "The word is " + B + E + I + N + G;
            Win();
            return;
        }
        if (fail1 && fail2 && fail3 && fail4 && fail5 && fail6 && fail7)
        {
            cout << "The word is " + B + E + I + N + G;
            Lose();
            return;
        }
        cout << endl;

        cout << "The Ai has chosen a word, please guess the word by typing a letter into the console and confirming it by pressing ENTER (Type in capitals) " << endl;

        cout << "The word is ";

        if (letter1 == true)
        {
            cout << B;
        }
        if (letter1 == false)
        {
            cout << blank;
        }

        if (letter2 == true)
        {
            cout << E;
        }
        if (letter2 == false)
        {
            cout << blank;
        }

        if (letter3 == true)
        {
            cout << I;
        }
        if (letter3 == false)
        {
            cout << blank;
        }

        if (letter4 == true)
        {
            cout << N;
        }
        if (letter4 == false)
        {
            cout << blank;
        }

        if (letter5 == true)
        {
            cout << G;
        }
        if (letter5 == false)
        {
            cout << blank;
        }

        cin >> guess1;

        if (guess1 == B)
        {
            cout << endl;
            cout << "That was correct, the word " + B + blank + blank + blank + blank << endl;
            letter1 = true;
            Guess();
        }
        else if (guess1 == E)
        {
            cout << endl;
            cout << "That was correct, the word " + blank + E + blank + blank + blank << endl;
            letter2 = true;
            Guess();
        }
        else if (guess1 == I)
        {
            cout << endl;
            cout << "That was correct, the word " + blank + blank + I + blank + blank << endl;
            letter3 = true;
            Guess();
        }
        else if (guess1 == N)
        {
            cout << endl;
            cout << "That was correct, the word " + blank + blank + blank + N + blank << endl;
            letter4 = true;
            Guess();
        }
        else if (guess1 == G)
        {
            cout << endl;
            cout << "That was correct, the word " + blank + blank + blank + blank + G << endl;
            letter5 = true;
            Guess();
        }
        else
        {
            cout << endl;
            cout << "That letter is not in the word the AI chose, please choose again" << endl;
            Hangman();
        }
    }
}

void Hangman()
{
    //making next stage true
    if (fail1 == false)
    {
        fail1 = true;
    }
    else if (fail2 == false)
    {
        fail2 = true;
    }
    else if (fail3 == false)
    {
        fail3 = true;
    }
    else if (fail4 == false)
    {
        fail4 = true;
    }
    else if (fail5 == false)
    {
        fail5 = true;
    }
    else if (fail6 == false)
    {
        fail6 = true;
    }
    else if (fail7 == false)
    {
        fail7 = true;
    }

    //drawing hangman

    if (fail1 == true)
    {
        cout << " |" << endl;
        if (fail2 == true)
        {
            cout << " O" << endl;
            if (fail3 == true)
            {
                if (fail6 == true)
                {
                    if (fail7 == true)
                    {
                        cout << "-|-" << endl;
                        cout << "| ";
                        cout << "| ";
                        Guess();
                    }
                    cout << "-|" << endl;
                    cout << "| ";
                    cout << "| ";
                    Guess();
                }
                if (fail4 == true)
                {
                    cout << " |";
                    if (fail5 == true)
                    {
                        cout << " |";
                        Guess();
                    }
                    Guess();
                }

                cout << " |" << endl;
                Guess();

            }
            Guess();
        }
        Guess();
    }
}

void Win()
{
    cout << endl;
    cout << endl;
    cout << "You win!" << endl;
}
void Lose()
{
    cout << endl;
    cout << endl;
    cout << "You lose!" << endl;
}