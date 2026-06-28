#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

vector<string> ans, temp;
map<string, vector<pair<string, bool>>> graph;
int N;
bool found;

void dfs(string cur, int cnt)
{
    if (found)
        return;
    if (cnt == N)
    {
        ans = temp;
        found = true;
        return;
    }

    for (int i = 0; i < graph[cur].size(); i++)
    {
        if (!graph[cur][i].second)
        { // 아직 방문 안한 간선
            graph[cur][i].second = true;
            string next = graph[cur][i].first;
            temp.push_back(next);
            dfs(next, cnt + 1);
            temp.pop_back();
            graph[cur][i].second = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    sort(tickets.begin(), tickets.end());
    N = tickets.size();

    for (int i = 0; i < N; i++)
    {
        string from = tickets[i][0];
        string end = tickets[i][1];
        graph[from].push_back({end, false});
    }

    temp.push_back("ICN");
    dfs("ICN", 0);

    return ans;
}