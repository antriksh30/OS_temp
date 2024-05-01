#include <bits/stdc++.h>
using namespace std;
int main()
{
    int choice;
    set<string> reader;
    set<string> writer;
    char ch = 'y';
    while (ch == 'y')
    {
        cout << "Enter " << endl
             << " Add reader-1 \n"
             << " Add writer-2 \n"
             << " Remove reader-3\n";
        cout << "Remove writer-4\n";
        cin >> choice;
        if (choice == 3)
        {
            if (reader.size() == 0)
            {
                cout << "\nThere are no readers\n";
            }
            else
            {
                cout << "Enter reader: ";
                string s;
                cin >> s;
                reader.erase(s);
                cout << "reader " << s << " was removed \n";
            }
        }
        else if (choice == 1)
        {
            if (writer.size() != 0)
            {
                cout << "\nCan't add reader as the data is being written by a writer.\n";
            }
            else
            {
                cout << "Enter reader: ";
                string s;
                cin >> s;
                reader.insert(s);
                cout << "The reader " << s << " was added \n";
            }
        }
        else if (choice == 4)
        {
            if (writer.size() == 0)
            {
                cout << "\nThere are no writers\n";
            }
            else
            {
                cout << "Enter writer: ";
                string s;
                cin >> s;
                writer.erase(s);
                cout << "The writer " << s << " was removed \n";
            }
        }
        else
        {
            if (writer.size() != 0)
            {
                cout << "\nCan't add writer as the data is being written by a writer.\n";
            }
            else if (reader.size() != 0)
            {
                cout << "\nThe data is currently being reader by " << reader.size() << " readers.\n";
                cout << "remove reader to add writer.\n";
            }
            else
            {
                cout << "Enter name of writer: ";
                string s;
                cin >> s;
                writer.insert(s);
                cout << "The writer " << s << " was added \n";
            }
        }
        cout << "press y to do again, n to exit\n";
        cin >> ch;
    }
    return 0;
}