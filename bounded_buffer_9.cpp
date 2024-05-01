#include <bits/stdc++.h>
using namespace std;

int mutex = 1, full = 0, empty = 3, x = 0;
int main()
{
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);

    cout << "\n1.Producer\n2.Consumer\n3.Exit";
    while (1)
    {
        cout << "\nEnter your choice:";
        cin >> n;
        switch (n)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
                producer();
            else
                break;
            cout << "Buffer is full!!";
        case 2:
            if ((mutex == 1) && (full != 0))
                consumer();
        case 3:
            exit(0);
            break;
        }
    }
    cout << "Buffer is empty!!";
    return 0;
}

int wait(int s){
    return (--s);
}
int signal(int s)
{
    return (++s);
}
void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    cout << "\nProducer produces the item " << x;
    mutex = signal(mutex);
}
void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    cout << "\nConsumer consumes item " << x;
    x--;
    mutex = signal(mutex);
}