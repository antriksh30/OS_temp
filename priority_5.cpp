// Priorty Scheduling Algorithm
#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid;
    int bt;
    int priority;
};

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process proc[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Burst Time and Priority Value for Process " << i + 1 << ": ";
        cin >> proc[i].bt >> proc[i].priority;
        proc[i].pid = i + 1;
    }
    
    sort(proc, proc + n, [](Process a, Process b) {
        return a.priority > b.priority;
    });

    int t = 0;
    cout << "\nOrder of execution: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << proc[i].pid << " is executed from " << t << " to " << t + proc[i].bt << endl;
        t += proc[i].bt;
    }
    cout << endl;
    cout << "P-id\t "
         << " BT \t"
         << " WT \t"
         << " TAT\n";
    int wait_time = 0;
    float avg_wait_time = 0;

    for (int i = 0; i < n; i++)
    {
        avg_wait_time += wait_time;
        cout << "P" << proc[i].pid << "\t" << proc[i].bt << "\t " 
            << wait_time << "\t " << wait_time + proc[i].bt << endl;
        wait_time += proc[i].bt;
    }

    cout << "Average waiting time = " << (float)avg_wait_time / (float)n << endl;

    return 0;
}
