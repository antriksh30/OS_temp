// First Come First Serve Scheduling Algorithm
#include <bits/stdc++.h>
using namespace std;

void firstComeFirstServe(int at[], int bt[], int n)
{
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> process;
        process.first = at[i];
        process.second = bt[i];
        ans.push_back(process);
    }
    float avg = 0;
    sort(ans.begin(), ans.end());
    int wt[n], ct[n], st[n];
    wt[0] = 0, st[0] = 0, ct[0] = ans[0].second;
    for (int i = 1; i < n; i++)
    {
        st[i] = ct[i - 1];
        wt[i] = st[i] - ans[i].first;
        if (wt[i] < 0)
        {
            wt[i] = 0;
        }
        ct[i] = st[i] + ans[i].second;
        avg += wt[i];
    }
    cout << "\nProcess schedule" << endl;
    for (int i = 0; i < n; i++)
    {
        cout <<"p"<<i << " ->  start time: " << st[i] << "s completion time: " << ct[i] << "s waiting time :" << wt[i] << endl;
    }
    cout << "\naverage waiting time : " << avg / n << "s" << endl;
}

int main()
{
    int n;
    cout << "Enter the no of processes: ";
    cin >> n;
    int at[n], bt[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> at[i];
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> bt[i];
    }
    firstComeFirstServe(at, bt, 5);
    return 0;
}
