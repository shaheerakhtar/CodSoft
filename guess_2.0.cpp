#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
int main()
{
    cout<<"\t\t\tWelcome To Number Guessing Game"<<endl;
    int ran_num, guess;
    int count = 0;
    srand(time(NULL));
    ran_num = rand()%100;
    do
    {
        cout << "Please, Enter Your Guess: ";
        cin >> guess;
        if (ran_num == guess)
        {
            cout << "Wohoo! You Won\n";
        }
        else if (ran_num < guess - 5)
        {
            cout << "TOO HIGH!\n";
        }
        else if (ran_num > guess + 5)
        {
            cout << "TOO LOW!\n";
        }
        else
        {
            cout << "You were close, but you loose XD.\n";
        }
        count++;
    } while (ran_num != guess);
    cout << "You guesssed it right in " << count << " turn/s";
    return 0;
}