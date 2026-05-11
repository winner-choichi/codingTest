#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    queue<int> q;
    vector<int> is_stack(n, 0);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        is_stack[i] = x;
    }

    vector<int> temp;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (!is_stack[i])
        {
            temp.push_back(x);
        }
    }

    int size = temp.size();
    for (int i = 0; i < size; ++i)
    {
        q.push(temp[size - i - 1]);
    }

    int m;
    cin >> m;

    while (m--)
    {
        int x;
        cin >> x;

        q.push(x);

        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}