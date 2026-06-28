#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
#define MAX 10

unordered_set<int> s[MAX];

int solution(int N, int number)
{

    for (int i = 1; i < MAX; i++)
    {
        int res = N;
        for (int j = 2; j <= i; j++)
        {
            res = res * 10 + N;
        }
        s[i].insert(res);
    }

    for (int i = 2; i < MAX - 1; i++)
    {
        for (int j = 1; j < i; j++)
        {
            for (auto a : s[j])
            {
                for (auto b : s[i - j])
                {
                    s[i].insert(a + b);
                    s[i].insert(a - b);
                    s[i].insert(a * b);
                    if (b != 0)
                    {
                        s[i].insert(a / b);
                    }
                }
            }
        }
    }

    int ans = -1;
    for (int i = 1; i < MAX - 1; i++)
    {
        if (s[i].find(number) != s[i].end())
        {
            ans = i;
            break;
        }
    }

    return ans;
}