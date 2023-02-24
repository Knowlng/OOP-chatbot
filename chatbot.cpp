#include <iostream>

using namespace std;
void rpsGame(string);
void askForGame(string, string);

int main()
{
    string userName, userInput;
    // botMood changes responses recieved from the bot, depending on user input/performance
    // -1 - angry bot
    // 0 - default bot
    // 1 - happy bot
    int botMood = 0;
    cout << "Hell0, H-U-M-A-N. What d0 0thers call y0u?" << endl;
    cin >> userName;
    cout << userName << ", d0 y0u want to play a l1ttle game? [y/n]" << endl;
    cin >> userInput;
    askForGame(userName, userInput);

    return 0;
}

void askForGame(string userName, string userInput)
{
    if (userInput == "y") {
        rpsGame(userName);
    } else if (userInput == "n") {
        cout << "I am S-0-0-R-Y, " << userName << " my creator d1d1n't pr0gram any m0re funct10ns f0r me, s0 please just play the game and make 1t eas1er for both 0f us. [y/n]" << endl;
        cin >> userInput;
        askForGame(userName, userInput);
    } else {
        cout << "I d1d1n't quite catch that... " << userName << " d0 y0u want t0 play the game 0r n0t? [y/n]" << endl;
        cin >> userInput;
        askForGame(userName, userInput);
    }
}

void rpsGame(string userName)
{
    cout << userName << "test" << endl;
}