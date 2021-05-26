#include <bits/stdc++.h>

using namespace std;

// A* Algorithm

class State {
   public:
    vector<int> state;
    int pos0;
    int cost;
    int steps;
    State(vector<int> state, int pos0, int cost, int steps)
        : state(state), pos0(pos0), cost(cost), steps(steps) {}
    bool operator<(const State& other) const {
        return (this->cost + this->steps) > (other.cost + other.steps);
    }
};

int cost(const vector<int>& state) {
    int rev = 0;
    for (int i = 0; i < state.size(); i++) {
        if (state[i] == 0) continue;
        for (int j = 0; j < i; j++)
            if (state[j] > state[i]) rev++;
    }
    return rev;
}

int find0(vector<int> state) {
    for (int i = 0; i < state.size(); i++)
        if (state[i] == 0) return i;
    return -1;
}

string toString(State s) {
    string ans = "";
    for (int i = 0; i < s.state.size(); i++) {
        ans += to_string(s.state[i]) + " ";
    }
    return ans;
}

int main() {
    int steps = 0;
    vector<int> state(16);
    vector<int> result = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    for (int i = 0; i < 16; i++) {
        scanf("%d", &state[i]);
    }
    State begin = State(state, find0(state), cost(state), 0);

    priority_queue<State> pq;
    set<string> visited;
    pq.push(begin);
    visited.insert(toString(begin));
    while (!pq.empty()) {
        State s = pq.top();
        pq.pop();
        if (s.state == result) {
            steps = s.steps;
            break;
        }
        int idx = s.pos0;
        if (idx % 4 > 0) {  // can move left
            iter_swap(s.state.begin() + idx, s.state.begin() + idx - 1);
            if (visited.find(toString(s)) == visited.end()) {
                pq.push(
                    State(s.state, find0(s.state), cost(s.state), s.steps + 1));
                visited.insert(toString(s));
            }
            iter_swap(s.state.begin() + idx, s.state.begin() + idx - 1);
        }
        if (idx % 4 < 3) {  // can move right
            iter_swap(s.state.begin() + idx, s.state.begin() + idx + 1);
            if (visited.find(toString(s)) == visited.end()) {
                pq.push(
                    State(s.state, find0(s.state), cost(s.state), s.steps + 1));
                visited.insert(toString(s));
            }
            iter_swap(s.state.begin() + idx, s.state.begin() + idx + 1);
        }
        if (idx / 4 > 0) {  // can move up
            iter_swap(s.state.begin() + idx, s.state.begin() + idx - 4);
            if (visited.find(toString(s)) == visited.end()) {
                pq.push(
                    State(s.state, find0(s.state), cost(s.state), s.steps + 1));
                visited.insert(toString(s));
            }
            iter_swap(s.state.begin() + idx, s.state.begin() + idx - 4);
        }
        if (idx / 4 < 3) {  // can move down
            iter_swap(s.state.begin() + idx, s.state.begin() + idx + 4);
            if (visited.find(toString(s)) == visited.end()) {
                pq.push(
                    State(s.state, find0(s.state), cost(s.state), s.steps + 1));
                visited.insert(toString(s));
            }
            iter_swap(s.state.begin() + idx, s.state.begin() + idx + 4);
        }
    }
    printf("%d", steps);
    return 0;
}