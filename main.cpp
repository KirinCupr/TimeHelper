#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;
int main() {
    //12 - 12 min; 60 - 60 sec,
    //CLOCKS_PER_SEC - ... maybe number of... something per second?..
    //int delay = 12 * 60 * CLOCKS_PER_SEC;
    int delay = 10 * CLOCKS_PER_SEC;
    int choice{};
    int countOfPomodoros{1};
    string activity{};
    // buffer for writing activity for further comparing
    string buffer{};
    ofstream fout("ListOfActivities.txt", ios::app);


    cout << "Hello! Let's study!" << endl;

    do {
        cout << "Choose: studying (24 min) or break (6 min) "
                "\n1.Enter 1 to Studying"
                "\n2.Enter 2 to break"
                "\n3.Enter any other key to exit";
        cout << "\nInput: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                cout << "Please, write what kind of activity are You going to do?";
                cout << "\nInput: "; cin >> activity;
                if (buffer == activity)
                    countOfPomodoros++;
                else
                {
                    buffer = activity;
                    fout << '\t' << activity;
                }
                cout << "Time for studying!" << endl;
                clock_t now = clock();
                while(clock() - now < (delay * 2));
                cout << "Good job!" << endl;
                break;
            }
            case 2:
            {
                cout << "Time for break!\n";
                clock_t now = clock();
                while(clock() - now < (delay / 2));
                cout << "Break had ended!\n";
                break;
            }
        }
        if (countOfPomodoros % 2 == 0){
            cout << "You study 2 pomodoro.\nTime for big break!\n";
            clock_t now = clock();
            while(clock() - now < (delay));
        }
    } while (choice == 1 || choice == 2);

    fout << '\t' << countOfPomodoros << '\n';
    fout.close();
    return 0;
}
