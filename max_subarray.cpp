/*  You are given "N" cities. There are "M" roads - each of the "M" roads connects two different cities directly.
When you go by a car from city 'x' to city 'y' via any one of the "M" roads - it costs you 1kg of fuel.
The car starts from the 'source' city and the goal of the car is to reach the 'destination' city. Initially the car has 'P' kgs of fuel. Some cities have re-fueling stations in them - whenever you visit a city which has a re-fueling station in it - it is necessary to re-fuel your car to exactly 'P' kgs again. You are allowed to visit the same road multiple times. If you visit a road for 5 times - then it is counted as 5 times in the final answer as well. Source city will never be a station.
 
Your task is to go from 'source' city to 'destination' city -
1)First of all prioritize the fact that in your path you should never reach negative fuel at any point of time.
2)Secondly, prioritize visiting the minimum number of stations in the path.
3)Thirdly, prioritize using the minimum number of direct roads in your path.
Output {min_stations,min_roads} which you would have to go through to go from 'source' to 'destination' and if it is not possible to do - report that as well(as you might run out of fuel in the path)
*/


/* Approach 1 :- 
-> dp[u] = minimum number of roads to go from “S”->”u” 
-> dp[u][k][e] = minimum number of roads to go from “S”->”u” such that you have done re-fueling for exactly “k” times and currently you have fuel “e” 
-> Multi-state BFS with tuples(u,k,e) stored in a normal queue. 


-> If you are going from “u”->”v” and “v” is not a re-fueling cell(city) && e>=1 
-> dp[v][k][e-1] = 1 + dp[u][k][e] 
-> push(v,k,e-1) in the queue
-> -> If you are going from “u”->”v” and “v” is a re-fueling cell(city) && e>=1  
-> dp[v][k+1][C] = 1 + dp[u][k][e]
-> push(v,k+1,C) in the queue
-> Final answer :- dp[T][k=0,1,2,...keep checking][all e>=0 are valid]
*/


/* Approach 2 :- Multi-state dijkstra :- to maintain (k,roads) as the output in lexicographic minimum order. 
-> dp[u][e] -> we travelled from “S”->”u” in such a way that our current fuel is “e” -> if you travel in this way what could the minimum value of this pair {k,roads} -> such that “k” is minimized first and then the minimizing priority is given to roads.  
PQ will store {k,roads,u,e}
Further part is explained in the video 
Final answer :- dp[T][e>=0] ->{k,roads} 
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Structure to represent the state in BFS: (u, k, e)
// u: current city
// k: number of refuelings done so far
// e: current fuel remaining
struct State {
    int u, k, e;
};

void solve() {
    int N, M, S, T, P;
    // N: number of cities, M: roads, S: source, T: destination, P: initial/refuel capacity
    cin >> N >> M >> S >> T >> P;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Assuming directed graph; use both if undirected
    }

    int num_stations;
    cin >> num_stations;
    vector<bool> is_station(N + 1, false);
    for (int i = 0; i < num_stations; ++i) {
        int city;
        cin >> city;
        is_station[city] = true;
    }

    // dp[u][k][e] stores the minimum number of roads to reach city 'u' 
    // with 'k' refuelings and 'e' fuel remaining.
    // Dimensions can be adjusted based on constraints (e.g., max_k around 50).
    const int MAX_K = 50;
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(MAX_K, vector<int>(P + 1, INF)));

    queue<State> q;

    // Initial state at source S: 0 refuelings, P fuel, 0 roads
    dp[S][0][P] = 0;
    q.push({S, 0, P});

    int min_k = -1;
    int min_roads = INF;

    while (!q.empty()) {
        auto [u, k, e] = q.front();
        q.pop();

        // If we reached the destination T, we can record the answer for this k
        if (u == T) {
            if (min_k == -1 || k < min_k) {
                min_k = k;
                min_roads = dp[u][k][e];
            } else if (k == min_k) {
                min_roads = min(min_roads, dp[u][k][e]);
            }
            continue;
        }

        // Try moving to all neighbor cities v
        for (int v : adj[u]) {
            if (e >= 1) {
                if (!is_station[v]) {
                    // Normal city: fuel decreases by 1, refuel count k remains same
                    int next_e = e - 1;
                    if (dp[u][k][e] + 1 < dp[v][k][next_e]) {
                        dp[v][k][next_e] = dp[u][k][e] + 1;
                        q.push({v, k, next_e});
                    }
                } else {
                    // Refueling station: refuel count increases by 1, fuel resets to P
                    int next_k = k + 1;
                    if (next_k < MAX_K) {
                        if (dp[u][k][e] + 1 < dp[v][next_k][P]) {
                            dp[v][next_k][P] = dp[u][k][e] + 1;
                            q.push({v, next_k, P});
                        }
                    }
                }
            }
        }
    }

    if (min_k != -1) {
        cout << "Minimum Stations (k): " << min_k << ", Minimum Roads: " << min_roads << endl;
    } else {
        cout << "Not possible to reach destination." << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}