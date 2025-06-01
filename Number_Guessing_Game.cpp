//Description :- Implement a number guessing game.
//Generate a random number and prompt the user to guess the number.
//Provide hints such as "higher" or "lower" to help the user narrow down the guess.
//Continue until the user guesses the correct number.

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void Guess_Random_Number(int random) {

    cout<<"------------------------------------------   Start Number Guessing Game   ------------------------------------------------"<<endl;

    while(true) {                           //Infinite loop till we reach a random number.
        
        int N;
        cout<<"Enter the number to guess randomly generated Number"<<endl;
        cin>>N;

        if(random == N) {
            cout<<"Random Number is Found"<<endl;
            return;
        }
        else if(random > N) {
            cout<<"Number is at higher position"<<endl;
        }
        else {
            cout<<"Number is at lower position"<<endl;
        }
    }
}


int main() {

    srand(time(0));

    int random = rand() % 30 + 1;                          //Generating random number from (1 to 30) here.
    cout<<"Random Number Generated is "<<random<<endl;

    Guess_Random_Number(random);

    return 0;
}