#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int getBotMood(int, int);
void chooseMenuOption(string, string, int, int, int);
void rpsGame(string);
void askAboutGame(string, string, int, int, int);
void explainRpsRules(string, string, int, int);
void askForNewGame(string, string, int);
int getUserHand();
void setcolor(char);
void showScore(int, int);

int main()
{
    string userName, userInput;
    // botMood changes responses recieved from the bot, depending on user input/performance
    // -1 - angry bot
    // 0 - default bot
    // 1 - arrogant bot
    int botMood = 0;
    int gameCount = 0;
    int LoopCounter = 0;

    cout << "Hell0, H-U-M-A-N. What d0 0thers call y0u?\n" << endl;
    cin >> userName;
    cout << "\n" << userName << ", what w0uld y0u l1ke t0 d0? [game/exit]\n" << endl;
    cin >> userInput;
    chooseMenuOption(userName, userInput, gameCount, botMood, LoopCounter);

    return 0;
}
//remove at the end cout
int getBotMood(int botMood, int LoopCounter)
{
    if(LoopCounter % 2 != 0){
        botMood = -1;
        cout <<"bot mood: " << botMood << endl;
    }
    return botMood;
}

void chooseMenuOption(string userName, string userInput, int gameCount, int botMood, int LoopCounter)
{
    botMood = getBotMood(botMood, LoopCounter);

    if(userInput == "game") {
        askAboutGame(userName, userInput, gameCount, botMood, LoopCounter);
    } else if(userInput == "exit") {
        return;
    } else {
        if(botMood == 0) {
            cout << "\n" << "I d1d1n't qu1te catch that... " << userName << ", what w0uld y0u l1ke t0 d0? [game/exit]\n" << endl;
        } else if(botMood == 1) {
            cout << "\n" << "S0rry, I d1d1n't qu1te understand your pathet1c attempt at commun1cat10n. " << userName << ", repeat y0ur answer. [game/exit]\n" << endl;
        } else if(botMood == -1) {
            cout << "\n" << userName << ", just tell me what y0u want. [game/exit]\n" << endl;
        }

        cin >> userInput;
        ++LoopCounter;
        chooseMenuOption(userName, userInput, gameCount, botMood, LoopCounter);
    }
}

void askAboutGame(string userName, string userInput, int gameCount, int botMood, int LoopCounter)
{   
    botMood = getBotMood(botMood, LoopCounter);

    if(gameCount == 0) {
        if (userInput == "game") {
            if(botMood == 0) {
                cout << "\n" << userName << ", d0 y0u kn0w the game, 'R0ck Paper Sc1ss0rs'? [y/n]\n" << endl;
            } else if(botMood == 1) {
                cout << "\n" << userName << ", d0 y0u even kn0w the game, 'R0ck Paper Sc1ss0rs'? [y/n]\n" << endl;
            } else if(botMood == -1) {
                cout << "\n" << "'R0ck Paper Sc1ss0rs'? " << userName << "? " << "D0 I need t0 expla1n the rules? [y/n]\n" << endl;
            }

            cin >> userInput;
            if(userInput == "y") {
                rpsGame(userName);
            } else if(userInput == "n") {
                explainRpsRules(userName, userInput, botMood, LoopCounter);
            }

            ++LoopCounter;
            askAboutGame(userName, userInput, gameCount, botMood, LoopCounter);
        } else {
            if(botMood == 0) {
                cout << "\n" << "I d1d1n't qu1te catch that... " << userName << ", d0 y0u kn0w the game 0r n0t? [y/n]\n" << endl;
            } else if(botMood == 1) {
                cout << "\n" << "Im supr1zed y0u can even type... " << userName << ", d0 y0u kn0w the game 0r n0t? [y/n]\n" << endl;
            } else if(botMood == -1) {
                cout << "\n" << userName << "... D0 y0u kn0w the game 0r are y0u act1ng dumb? [y/n]\n" << endl;
            }

            cin >> userInput;
            if(userInput == "y") {
                rpsGame(userName);
            } else if(userInput == "n") {
                explainRpsRules(userName, userInput, botMood, LoopCounter);
            }

            ++LoopCounter;
            askAboutGame(userName, userInput, gameCount, botMood, LoopCounter);
        }
    } else {
        if (userInput == "game") {
            if(botMood == 0) {
                cout << "\n" << userName << ", 1f y0u'd l1ke I can g0 0ver the rules. [y/n]\n" << endl;
            } else if(botMood == 1) {
                cout << "\n" << userName << ", maybe y0u sh0uld actually read the rules. What d0 y0u th1nk? [y/n]\n" << endl;
            } else if(botMood == -1) {
                cout << "\n" << userName << ", d0 y0u want t0 waste my t1me g01ng 0ver the rules? [y/n]\n" << endl;
            }

            cin >> userInput;
            if(userInput == "y") {
                explainRpsRules(userName, userInput, botMood, LoopCounter);
            } else if(userInput == "n") {
                rpsGame(userName);
            }

            ++LoopCounter;
            askAboutGame(userName, userInput, gameCount, botMood, LoopCounter);
        } else {    
            if(botMood == 0) {
                cout << "\n" << "I d1d1n't qu1te catch that... " << userName << ", d0 y0u want t0 hear the rules 0r n0t? [rules/n]\n" << endl;
            } else if(botMood == 1) {
                cout << "\n" << "I have n0 1dea what y0u are say1ng... " << userName << ", d0 y0u even want t0 hear the rules 0r n0t? [rules/n]\n" << endl;
            } else if(botMood == -1) {
                cout << "\n" << "L1sten up, " << userName <<  "! H0w many t1mes do I have t0 freak1ng repeat myself?! D0 y0u want t0 hear the damn rules 0r n0t?!? [rules/n]\n" << endl;
            }

            cin >> userInput;
            if(userInput == "rules") {
                explainRpsRules(userName, userInput, botMood, LoopCounter);
            } else if(userInput == "n") {
                rpsGame(userName);
            }

            ++LoopCounter;
            askAboutGame(userName, userInput, gameCount, botMood, LoopCounter);
        }
    }
}
// unfinished
void explainRpsRules(string userName, string userInput, int botMood, int LoopCounter) 
{
    botMood = getBotMood(botMood, LoopCounter);

    if (userInput == "y") {
        rpsGame(userName);
    } else if (userInput == "n" || userInput == "rules") {
        if(botMood == 0) {
            cout << "\n" << "R0ck w1ns aga1nst sc1ss0rs; paper w1ns aga1nst r0ck;\nand sc1ss0rs wins aga1nst paper. 1f b0th players thr0w the same\nhand s1gnal, 1t 1s c0ns1dered a t1e, and the game resumes.\nThe game w1ll be best 0f three.\n" << endl;
            cout << "\n" << "1s everyth1ng clear, " << userName << "? [y/n]\n" << endl;
        } else if(botMood == 1) {
            cout << "\n" << "R0ck w1ns aga1nst sc1ss0rs; paper w1ns aga1nst r0ck;\nand sc1ss0rs wins aga1nst paper. 1f b0th players thr0w the same\nhand s1gnal, 1t 1s c0ns1dered a t1e, and the game resumes.\nThe game w1ll be best 0f three.\n" << endl;
            cout << "\n" << "1s everyth1ng clear, " << userName << "? [y/n]\n" << endl;
        } else if(botMood == -1) {
            cout << "\n" << "R0ck w1ns aga1nst sc1ss0rs; paper w1ns aga1nst r0ck;\nand sc1ss0rs wins aga1nst paper. 1f b0th players thr0w the same\nhand s1gnal, 1t 1s c0ns1dered a t1e, and the game resumes.\nThe game w1ll be best 0f three.\n" << endl;
            cout << "\n" << "1s everyth1ng clear, " << userName << "? [y/n]\n" << endl;
        }

        cin >> userInput;
        if(userInput == "y") {
            rpsGame(userName);
        } else if(userInput == "n") {
            ++LoopCounter;
            explainRpsRules(userName, userInput, botMood, LoopCounter);
        }

        ++LoopCounter;
        explainRpsRules(userName, userInput, botMood, LoopCounter);
    } else {
        if(botMood == 0) {
            cout << "\n" << "I d1d1n't qu1te catch that... " << userName << ", d0 y0u understand the rules 0r n0t? [y/n]\n" << endl;
        } else if(botMood == 1) {
            cout << "\n" << "I d1d1n't qu1te catch that... " << userName << ", d0 y0u understand the rules 0r n0t? [y/n]\n" << endl;
        } else if(botMood == -1) {
            cout << "\n" << "I d1d1n't qu1te catch that... " << userName << ", d0 y0u understand the rules 0r n0t? [y/n]\n" << endl;
        }

        cin >> userInput;
        ++LoopCounter;
        explainRpsRules(userName, userInput, botMood, LoopCounter);
    }
}

void rpsGame(string userName)
{
    int botHand, userHand, result, gameCount;
    int userPoints = 0;
    int botPoints = 0;
    string userInput;
    string choices[3] = {"Rock", "Paper", "Scissors"};
    srand(time(NULL));

    setcolor( 0x05 );
    cout << "\n" << "Let's play!" << endl;
    setcolor( 0x07 );
    do {
        userHand = getUserHand();

        botHand = rand() % 3;
        result = (userHand - botHand + 3) % 3;

        cout << "\n" << "Y0u ch0se " << choices[userHand] << " vs My " << choices[botHand] << endl;
        if (result == 0) {
            setcolor( 0x0E );
            cout << "\n" << "1t's a t1e" << endl;
            setcolor( 0x07 );
        } else if (result == 1) {
            setcolor( 0x0C );
            cout << "\n" << "P01nt f0r me" << endl;
            setcolor( 0x07 );
            ++botPoints;
        } else {
            setcolor( 0x0A );
            cout << "\n" << "P01nt f0r y0u" << endl;
            setcolor( 0x07 );
            ++userPoints;
        }
        showScore(userPoints, botPoints);
    } while(userPoints < 2 && botPoints < 2);

    setcolor( 0x0B );
    cout << "_____________________________________" << endl;
    setcolor( 0x07 );

    if(userPoints > botPoints) {
        setcolor( 0x02 );
        cout << "\n" << userName << ", y0u w1n" << endl;
        setcolor( 0x07 );
    } else {
        setcolor( 0x04 );
        cout << "\n" << "1 win" << endl;
        setcolor( 0x07 );
    }
    ++gameCount;
    cout << "\n" << "w0uld y0u l1ke t0 play aga1n? [y/n]\n" << endl;
    cin >> userInput;
    askForNewGame(userName, userInput, gameCount);
}
//doesnt exit, because return doesnt do shit on second loop use something else idk exit or smth
void askForNewGame(string userName, string userInput, int gameCount)
{
    int botMood = 0, counter = 0;
    if (userInput == "y") {
    rpsGame(userName);
    } else if(userInput == "n") {
        cout << "\n" << userName << ", what w0uld y0u l1ke t0 d0? [game/exit]\n" << endl;
        cin >> userInput;
        chooseMenuOption(userName, userInput, gameCount, botMood, counter);
    } else {
        cout << "\n" << "I d1d1n't qu1te catch that... " << userName << ", d0 y0u want t0 play aga1n 0r n0t? [y/n]\n" << endl;
        cin >> userInput;
        askForNewGame(userName, userInput, gameCount);
    }
}

int getUserHand()
{
    int userHand = 0;
    string userInput;

    setcolor( 0x0B );
    cout << "_____________________________________" << endl;
    setcolor( 0x07 );
    cout << "\n" << "Enter [r] f0r R0CK, [p] f0r PAPER, [s] f0r SC1SS0RS\n" << endl;
    cin >> userInput;

    if (userInput == "r") {
        userHand = 0;
    } else if (userInput == "p") {
        userHand = 1;
    } else if (userInput == "s") {
        userHand = 2;
    } else {
        cout << "\n" << "Please ch00se from R0ck, Paper 0r sc1ss0rs [r/p/s]\n" << endl;
        getUserHand();
    }

    return userHand;
}

void setcolor(char color)
{
  SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE ), color);
}

void showScore(int userPoints, int botPoints)
{
    cout << "\n" << "[";
    setcolor( 0x0A );
    cout << userPoints;
    setcolor( 0x07 );
    cout << "/";
    setcolor( 0x0C );
    cout << botPoints;
    setcolor( 0x07 );
    cout << "]" << endl;
}