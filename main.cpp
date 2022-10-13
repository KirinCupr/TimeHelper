#include <iostream>
#include <ctime>

using namespace std;
int main() {
    int delay = 12 * 60 * CLOCKS_PER_SEC;
    int choice{};
    cout << "Hello! Let's study!" << endl;

    cout << "Choose: studying (24 min) or break (6 min) \n1.Enter 1 to Studying\n2.Enter 2 to break";
    cout << "\nInput: ";

    cin >> choice;

    switch (choice)
        {
            case 1:
            {
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

    return 0;
}
