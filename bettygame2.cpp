#include <iostream>
#include <string> // needed to use strings
#include <cstdlib> //needed to use random numbers
#include <ctime>
using namespace std;


void rules()
{
    system("cls");
    cout <<"\t\t==========Casino Number Guessing Rules=========\n";
    cout << "\t1. Choose a number between 1 and 6 \n";
    cout << "\t2. If you guess the number, you get 10 times the money you bet \n";
    cout << "\t3. Guess wrong, and you lose your cash!\n\n";

}

int main()
{
        string playerName;
        int balance; //stores player's balance
        int bettingAmount;
        int guess;
        int dice; //stores the random number
        char choice;
        srand(time(0)); //seeds the random generator
        cout << "\n\t\t=======Welcome to Casino World=============\n\n";
        cout << "\n\n What's your name:  ";
        getline(cin, playerName);
        cout << "\n\n Enter the starting balance to play the game : $";
        cin >> balance;
        
    do 
    {
        system("cls");
        rules();
        cout << "\n\n Your current balance is £ " << balance << "\n";
        
        //get betting balance
        
        do
        {
        cout << "Hey, " << playerName << ". enter amount to bet : £";
        cin >> bettingAmount;
        if(bettingAmount > balance)
            cout << "Betting balance can't be more than current balance\n"
                 << "\n Re-enter balance \n";            
        }

        while (bettingAmount > balance);
    
    //get player's numbers

        do 
        {
        cout << "Guess any betting number between 1 and 6 :";
        cin >> guess;
        if(guess <=0 || guess > 6)
            cout << "\n Number should be between 1 and 6 \n" << "Re-enter number: \n";
        }
    
        while(guess <= 0 || guess > 6);
        
        dice = rand()%6 + 1;
        if (dice == guess)
            {
            cout << "\n\n It's your lucky day! You have won £ " << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
            }
        else
            {
            cout << "Oops, better luck next time! You lost £ " << bettingAmount <<"\n";
            balance = balance - bettingAmount;
            }

        cout << "\n The winning number was : " << dice << "\n";
        cout << "\n" << playerName << ", you have a balance of £ " << balance << "\n";

        if(balance ==0)
            {
            cout << "You have no money left to play";
            break;
            }

    cout << "\n\n --> Do you want to play again (y/n)?";
    cin >> choice;

    }
    
    while(choice =='Y' || choice == 'y');
    
    cout << "\n\n\n";
    cout << "\n\n Thanks for playing the game. Your balance is £ " << balance << "\n\n";
    return 0;
}