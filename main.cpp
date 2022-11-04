#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;
int main() {
    //12 - 12 min; 60 - 60 sec, CLOCKS_PER_SEC - ... maybe number of... something per second?..
    //int delay = 12 * 60 * CLOCKS_PER_SEC;
    int delay = 10 * CLOCKS_PER_SEC;
    int choice{};
    string activity{};
    ofstream fout("ListOfActivities.txt", ios::app);
    cout << "Hello! Let's study!" << endl;

    cout << "Choose: studying (24 min) or break (6 min) \n1.Enter 1 to Studying\n2.Enter 2 to break";
    cout << "\nInput: ";

    cin >> choice;

    switch (choice)
        {
            case 1:
            {
                cout << "Please, write what kind of activity are You going to do?" << endl;
                cin >> activity;
                fout << activity;
                cout << "Time for studying!" << endl;
                clock_t now = clock();
                while(clock() - now < (delay * 2));
                cout << "Good job!" << endl;
                break;
            }
            case 2:
            {
                cout << "Time for break!" << endl;
                clock_t now = clock();
                while(clock() - now < (delay / 2));
                cout << "Break had ended!" << endl;
                break;
            }
        }
    fout.close();
    return 0;
}
