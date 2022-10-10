#include <iostream>
#include <ctime>

using namespace std;
int main() {
    int dozen = 12;
    int choice{};
    time_t start;
    time_t end;
    cout << "Hello! Let's study!" << endl;

    cout << "Choose: studying (24 min) or break (6 min) \n1.Enter 1 to Studying\n2.Enter 2 to break";
    cout << "\nInput: ";

    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            cout << "Time for studying!";

        }
        case 2:
        {
            cout << "Time for break!";
            break;
        }
    }

    switch (choice)
        {
            case 1:
            {
                time(&start);
                cout << "Time for studying!";
                time(&end);
                while (end - start != dozen) time(&end);

            }
            case 2:
            {
                cout << "Time for break!";
                break;
            }
        }

    return 0;
}
