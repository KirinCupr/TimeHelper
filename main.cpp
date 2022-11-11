#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

//12 - 12 min; 60 - 60 sec,
//CLOCKS_PER_SEC - ... maybe number of... something per second?..
//const int DUNE(){ return 12 * 60 * CLOCKS_PER_SEC; }

//todo in final version replace 'DUNE' on upper 'DUNE'
const int DUNE(){ return 10 * CLOCKS_PER_SEC; }

// input data (count): time in min
void Delay(float count)
{
    clock_t now = clock();
    while(clock() - now < (DUNE() * (count/12)));
}

void WriteNote(string activity){
    ofstream fout("ListOfActivities.txt", ios::app);
    fout << "Kind of activity: " << activity << endl;
    time_t now = time(0);
    string dt = ctime(&now);
    fout << "Start time: " << dt << "------------";
    fout << endl;
    fout.close();
}
int main() {
    int choice{};
    int countOfPomodoros{1};
    string activity{};
    // buffer for writing activity for further comparing
    string buffer{};

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
                    WriteNote(activity);
                }
                cout << "Time for studying!" << endl;
                Delay(24);
                cout << "Good job!" << endl;
                break;
            }
            case 2:
            {
                cout << "Time for break!\n";
                Delay(6);
                cout << "Break had ended!\n";
                break;
            }
            default:
            {
                cout << "Exit from program..." << endl;
            }
        }
        if (countOfPomodoros % 2 == 0){
            cout << "You study 2 pomodoro.\nTime for big break!\n";
            Delay(12);
        }
    } while (choice == 1 || choice == 2);

    //todo remade writing of PomodoroCount
    ofstream fout("ListOfActivities.txt", ios::app);
    //fout << '\t' << countOfPomodoros << '\n';
    fout << "------------" << endl;
    fout.close();
    return 0;
}
