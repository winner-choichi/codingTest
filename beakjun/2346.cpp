#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    deque<int> mydeque;
    for (int i = 1; i <= n; ++i)
    {
        mydeque.push_back(i);
    }

    vector<int> nums(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        nums[i] = x;
    }

    cout << mydeque.front() << " ";
    mydeque.pop_front();
    int card_num = nums[1];

    for (int i = 0; i < n - 1; ++i)
    {
        if (card_num == 0)
        {
            card_num = nums[mydeque.front()];
            cout << mydeque.front() << " ";
            mydeque.pop_front();
        }
        else if (card_num > 0)
        {
            for (int j = 0; j < card_num; ++j)
            {
                if (j == (card_num - 1))
                {
                    card_num = nums[mydeque.front()];
                    cout << mydeque.front() << " ";
                    mydeque.pop_front();
                    // cout << "card_num: " << card_num;
                    break;
                }
                int temp = mydeque.front();
                mydeque.pop_front();
                mydeque.push_back(temp);
            }
        }
        else if (card_num < 0)
        {
            for (int j = 0; j >= card_num; --j)
            {
                if (j == card_num)
                {
                    card_num = nums[mydeque.front()];
                    cout << mydeque.front() << " ";
                    mydeque.pop_front();
                    break;
                }
                int temp = mydeque.back();
                mydeque.pop_back();
                mydeque.push_front(temp);
            }
        }
    }

    cout << '\n';

    return 0;
}