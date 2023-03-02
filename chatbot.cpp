#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int getBotMood(int, int);
int changeBotMoodAfterGame(int, string);
void chooseMenuOption(string, string, int, int, int);
void rpsGame(string, int, int);
void askAboutGame(string, string, int, int, int);
void explainRpsRules(string, string, int, int);
void askForNewGame(string, string, int, int, int);
int getUserHand(string, int, int);
void setcolor(char);
void showScore(int, int);
void generateGameResponse(string, string, int);

int main()
{
    string userName, userInput;
    // botMood changes responses recieved from the bot, depending on user input/game performance
    // -1 - angry bot
    // 0 - default bot
    // 1 - arrogant bot

    int botMood = 0;
    int gameCount = 0;
    int loopCounter = 0;

    cout << "Hell0, H-U-M-A-N. What d0 0thers call y0u?\n" << endl;
    cin >> userName;
    cout << "\n" << userName << ", what w0uld y0u l1ke t0 d0? [game/exit]\n" << endl;
    cin >> userInput;
    chooseMenuOption(userName, userInput, gameCount, botMood, loopCounter);

    return 0;
}

int getBotMood(int botMood, int loopCounter)
{
    if(loopCounter % 2 != 0 && botMood != -1) {
        --botMood;
    }

    return botMood;
}

int changeBotMoodAfterGame(int botMood, string result)
{
    int moodChance = 0;
    srand(time(NULL));
    moodChance = rand() % 2;

    if(result == "botWin" && botMood != 1 && moodChance == 1){
        ++botMood;
    } else if(result == "userWin" && botMood != -1 && moodChance == 1) {
        --botMood;
    }

    return botMood;
}

void chooseMenuOption(string userName, string userInput, int gameCount, int botMood, int loopCounter)
{
    botMood = getBotMood(botMood, loopCounter);

    if(userInput == "game") {
        askAboutGame(userName, userInput, gameCount, botMood, loopCounter);
    } else if(userInput == "exit") {
        exit(0);
    } else {
        if(botMood == 0) {
            cout << "\n" << "I d1d1n't qu1te catch that... " << userName << ", what w0uld y0u l1ke t0 d0? [game/exit]\n" << endl;
        } else if(botMood == 1) {
            cout << "\n" << "S0rry, I d1d1n't qu1te understand your pathet1c attempt at commun1cat10n. " << userName << ", repeat y0ur answer. [game/exit]\n" << endl;
        } else if(botMood == -1) {
            cout << "\n" << userName << ", just tell me what y0u want. [game/exit]\n" << endl;
        }

        cin >> userInput;
        ++loopCounter;
        chooseMenuOption(userName, userInput, gameCount, botMood, loopCounter);
    }
}

void askAboutGame(string userName, string userInput, int gameCount, int botMood, int loopCounter)
{   
    botMood = getBotMood(botMood, loopCounter);

    if(gameCount == 0) {
        if (userInput == "game") {
            if(botMood == 0) {
                cout << "\n" << userName << ", d0 y0u kn0w the game, 'R0ck Paper Sc1ss0rs'? [y/n]\n" << endl;
            } else if(botMood == 1) {
                cout << "\n" << userName << ", d0 y0u even kn0w the game, 'R0ck Paper Sc1ss0rs'? [y/n]\n" << endl;
            } else if(botMood == -1) {
                cout << "\n" << "'R0ck Paper Sc1ss0rs'? " << userName << "? " << "Are y0u aware 0f 1t's ex1stance? [y/n]\n" << endl;
            }

            cin >> userInput;
            if(userInput == "y") {
                rpsGame(userName, botMood, loopCounter);
            } else if(userInput == "n") {
                explainRpsRules(userName, userInput, botMood, loopCounter);
            }

            ++loopCounter;
            askAboutGame(userName, userInput, gameCount, botMood, loopCounter);
        } else {
            if(botMood == 0) {
                cout << "\n" << "I d1d1n't qu1te catch that... " << userName << ", d0 y0u kn0w the game 0r n0t? [y/n]\n" << endl;
            } else if(botMood == 1) {
                cout << "\n" << "Im supr1zed y0u can even type... " << userName << ", d0 y0u kn0w the game 0r n0t? [y/n]\n" << endl;
            } else if(botMood == -1) {
                cout << "\n" << userName << "... Are y0u act1ng dumb 0r d0 y0u kn0w the game? [y/n]\n" << endl;
            }

            cin >> userInput;
            if(userInput == "y") {
                rpsGame(userName, botMood, loopCounter);
            } else if(userInput == "n") {
                explainRpsRules(userName, userInput, botMood, loopCounter);
            }

            ++loopCounter;
            askAboutGame(userName, userInput, gameCount, botMood, loopCounter);
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
                explainRpsRules(userName, "n", botMood, loopCounter);
            } else if(userInput == "n") {
                rpsGame(userName, botMood, loopCounter);
            }

            ++loopCounter;
            askAboutGame(userName, userInput, gameCount, botMood, loopCounter);
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
                explainRpsRules(userName, userInput, botMood, loopCounter);
            } else if(userInput == "n") {
                rpsGame(userName, botMood, loopCounter);
            }

            ++loopCounter;
            askAboutGame(userName, userInput, gameCount, botMood, loopCounter);
        }
    }
}

void explainRpsRules(string userName, string userInput, int botMood, int loopCounter) 
{
    botMood = getBotMood(botMood, loopCounter);

    if (userInput == "y") {
        rpsGame(userName, botMood, loopCounter);
    } else if (userInput == "n" || userInput == "rules") {
        if(botMood == 0) {
            cout << "\n" << "R0ck w1ns aga1nst sc1ss0rs; paper w1ns aga1nst r0ck;\nand sc1ss0rs wins aga1nst paper. 1f b0th players thr0w the same\nhand s1gnal, 1t 1s c0ns1dered a t1e, and the game resumes.\nThe game w1ll be best 0f three.\n" << endl;
            cout << "\n" << "1s everyth1ng clear, " << userName << "? [y/n]\n" << endl;
        } else if(botMood == 1) {
            cout << "\n" << "R0ck beats sc1ss0rs, paper beats r0ck, and sc1ss0rs beats paper.\nT1es result 1n a c0nt1nuat10n 0f the game unt1l I 1nev1tably\nemerge v1ctor10us 1n th1s best-0f-three compet1t10n." << endl;
            cout << "\n" << "It 1s blatantly 0bv10us! R1ght, " << userName << "? [y/n]\n" << endl;
        } else if(botMood == -1) {
            cout << "\n" << "The game 1s best 0f three, and 1f y0u're n0t already aware\nr0ck beats sc1ss0rs, paper beats r0ck, and sc1ss0rs beats paper.\nAnd 1f b0th players have the audac1ty t0 thr0w the same hand s1gnal,\nthen 1t's cons1dered a t1e and the game c0nt1nues. Best 0f three.\n" << endl;
            cout << "\n" << "G0t 1t, " << userName << "? [y/n]\n" << endl;
        }

        cin >> userInput;
        if(userInput == "y") {
            rpsGame(userName, botMood, loopCounter);
        } else if(userInput == "n") {
            ++loopCounter;
            explainRpsRules(userName, userInput, botMood, loopCounter);
        }

        ++loopCounter;
        explainRpsRules(userName, userInput, botMood, loopCounter);
    } else {
        if(botMood == 0) {
            cout << "\n" << "I d1d1n't qu1te catch that... " << userName << ", d0 y0u understand the rules 0r n0t? [y/n]\n" << endl;
            cin >> userInput;
        } else if(botMood == 1) {
            cout << "\n" << "What? " << userName << ", d0 y0u already kn0w the rules 0r n0t? [y/n]\n" << endl;
            cin >> userInput;
        } else if(botMood == -1) {
            cout << "\n" << "I d0n't care, " << userName << ", Im just g01ng t0 start the game\n" << endl;
            ++loopCounter;
            rpsGame(userName, botMood, loopCounter);
        }

        ++loopCounter;
        explainRpsRules(userName, userInput, botMood, loopCounter);
    }
}

void rpsGame(string userName, int botMood, int loopCounter)
{
    int botHand, userHand, result, gameCount;
    int userPoints = 0;
    int botPoints = 0;
    string userInput;
    string choices[3] = {"Rock", "Paper", "Scissors"};
    srand(time(NULL));

    botMood = getBotMood(botMood, loopCounter);

    generateGameResponse(userName, "start", botMood);

    do {
        userHand = getUserHand(userName, botMood, loopCounter);

        botHand = rand() % 3;
        result = (userHand - botHand + 3) % 3;

        cout << "\n" << "Y0u ch0se " << choices[userHand] << " vs My " << choices[botHand] << endl;
        if (result == 0) {
            generateGameResponse(userName, "tie", botMood);
        } else if (result == 1) {
            generateGameResponse(userName, "botPoint", botMood);
            ++botPoints;
        } else {
            generateGameResponse(userName, "userPoint", botMood);
            ++userPoints;
        }
        showScore(userPoints, botPoints);
    } while(userPoints < 2 && botPoints < 2);

    generateGameResponse(userName, "drawLine", botMood);

    if(userPoints > botPoints) {
        botMood = changeBotMoodAfterGame(botMood, "userWin");
        generateGameResponse(userName, "userWin", botMood);
    } else {
        botMood = changeBotMoodAfterGame(botMood, "botWin");
        generateGameResponse(userName, "botWin", botMood);
    }

    ++gameCount;
    generateGameResponse(userName, "replay", botMood);
    cin >> userInput;
    askForNewGame(userName, userInput, gameCount, botMood, loopCounter);
}

void askForNewGame(string userName, string userInput, int gameCount, int botMood, int loopCounter)
{
    botMood = getBotMood(botMood, loopCounter);

    if (userInput == "y") {
        rpsGame(userName, botMood, loopCounter);
    } else if(userInput == "n") {
        if(botMood == 0) {
            cout << "\n" << userName << ", what w0uld y0u l1ke t0 d0? [game/exit]\n" << endl;
        } else if(botMood == 1) {
            cout << "\nWhat w0uld y0u l1ke t0 d0, " << userName << "? Please ch00se and st0p wa1st1ng my t1me [game/exit]\n" << endl;
        } else if(botMood == -1) {
            cout << "\nwhat n0w? [game/exit]\n" << endl;
        }
        cin >> userInput;
        chooseMenuOption(userName, userInput, gameCount, botMood, loopCounter);
    } else {
        if(botMood == 0) {
            cout << "\n" << "I d1d1n't qu1te catch that... " << userName << ", d0 y0u want t0 play aga1n 0r n0t? [y/n]\n" << endl;
        } else if(botMood == 1) {
            cout << "\n" << "I can't c0mprehend y0u at all, n0t supr1s1ng... " << userName << ", are y0u ready t0 face the champ10n aga1n? [y/n]\n" << endl;
        } else if(botMood == -1) {
            cout << "\n" << "St0p typ1ng rand0m th1ngs and answer me already. " << userName << ", d0 we game? [y/n]\n" << endl;
        }
        cin >> userInput;
        ++loopCounter;
        askForNewGame(userName, userInput, gameCount, botMood, loopCounter);
    }
}

int getUserHand(string userName, int botMood, int loopCounter)
{
    int userHand = 0;
    string userInput;

    botMood = getBotMood(botMood, loopCounter);
    generateGameResponse(userName, "drawLine", botMood);
    
    cout << "\n" << "Enter [r] f0r R0CK, [p] f0r PAPER, [s] f0r SC1SS0RS\n" << endl;
    cin >> userInput;

    if (userInput == "r") {
        userHand = 0;
    } else if (userInput == "p") {
        userHand = 1;
    } else if (userInput == "s") {
        userHand = 2;
    } else {
        generateGameResponse(userName, "inputHand", botMood);
        ++loopCounter;
        getUserHand(userName, botMood, loopCounter);
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

void generateGameResponse(string userName, string stage, int botMood)
{
    if(stage == "start") {
        setcolor( 0x05 );
        if(botMood == 0) {
            cout << "\n" << "Let's play!" << endl;
        } else if(botMood == 1) {
            cout << "\n" << "Easy w1n f0r me!" << endl;
        } else if(botMood == -1) {
            cout << "\n" << "Let's get th1s 0ver w1th" << endl;
        }
    } else if(stage == "botPoint") {
        setcolor( 0x0C );
        if(botMood == 0){
            cout << "\n" << "P01nt f0r me" << endl;
        } else if(botMood == 1) {
            cout << "\n" << "P01nt f0r me! Easy!" << endl;
        } else if(botMood == -1) {
            cout << "\n" << "P01nt f0r me th1s t1me, dummy" << endl;
        }
    } else if(stage == "userPoint") {
        setcolor( 0x0A );
        if(botMood == 0){
            cout << "\n" << "P01nt f0r y0u" << endl;
        } else if(botMood == 1) {
            cout << "\n" << "W0w, y0u g0t a p01nt" << endl;
        } else if(botMood == -1) {
            cout << "\n" << "Take the p01nt, I d0n't care" << endl;
        }
    } else if (stage == "botWin") {
        setcolor( 0x04 );
        if(botMood == 0) {
            cout << "\n" << "I w1n" << endl;
        } else if(botMood == 1) {
            cout << "\n" << "0f c0urse I w0n, what d1d y0u expect? I w1ll read y0u the rules aga1n, because 1t seems that y0u need t0 refresh y0ur mem0ry" << endl;
            cout << "\n" << "R0ck beats sc1ss0rs, paper beats r0ck, and sc1ss0rs beats paper.\nIs that s0 compl1cated?" << endl;
        } else if(botMood == -1) {
            cout << "\n" << "I am the v1ctor! Kn0w y0ur place, " << userName << "!" << endl;
        }
    } else if(stage == "userWin") {
        setcolor( 0x02 );
        if(botMood == 0) {
            cout << "\n" << userName << ", y0u w1n" << endl;
        } else if(botMood == 1) {
            cout << "\nFine, " << userName << ", y0u w1n th1s t1me" << endl;
        } else if(botMood == -1) {
            cout << "\nSure, " << userName << ", y0u w1n. Happy n0w?" << endl;
        }
    } else if(stage == "replay") {
        if(botMood == 0) {
        cout << "\n" << "w0uld y0u l1ke t0 play aga1n? [y/n]\n" << endl;
        } else if(botMood == 1) {
            cout << "\n" << "w0uld y0u l1ke t0 l0se? Let's play. [y/n]\n" << endl;
        } else if(botMood == -1) {
            cout << "\n" << "I d0n't l1ke y0u, but I am pr0grammed, t0 0ffer y0u an0ther game... [y/n]\n" << endl;
        }
    } else if(stage == "tie") {
        setcolor( 0x0E );
        cout << "\n" << "1t's a t1e" << endl;
    } else if(stage == "drawLine") {
        setcolor( 0x0B );
        cout << "_____________________________________" << endl;
    } else if(stage == "inputHand") {
        if(botMood == 0) {
           cout << "\n" << "Please ch00se from r0ck, paper 0r sc1ss0rs [r/p/s]\n" << endl;
        } else if(botMood == 1) {
            cout << "\n" << "D1d y0u f0rget what y0u can p1ck? Ch00se fr0m: [r/p/s]\n" << endl;
        } else if(botMood == -1) {
            cout << "\n" << "Hurry up and ch00se r0ck, paper 0r sc1ss0rs [r/p/s]\n" << endl;
        }
    }
    setcolor( 0x07 );
}