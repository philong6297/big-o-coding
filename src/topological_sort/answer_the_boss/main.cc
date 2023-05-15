#include <iostream>
#include <queue>
#include <vector>

namespace {
using namespace std;

struct Employee {
  int32_t rank{0};
  int32_t id{0};

  // smaller ranking means larger level
  friend auto operator<(const Employee& a, const Employee& b) -> bool {
    return a.rank == b.rank ? a.id > b.id : a.rank > b.rank;
  }
};
}    // namespace

auto main() -> int32_t {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int32_t T{0};
  cin >> T;
  for (auto test_case = 1; test_case <= T; ++test_case) {
    int32_t N{0};
    int32_t R{0};

    cin >> N >> R;

    vector<vector<int32_t>> relations(N, std::vector<int>());
    vector<int32_t> indegree(N, 0);

    for (auto i = 0; i < R; ++i) {
      int32_t higher{0};
      int32_t lower{0};
      cin >> lower >> higher;

      relations[higher].emplace_back(lower);
      ++indegree[lower];
    }

    priority_queue<Employee> q{};
    for (auto i = 0; i < N; ++i) {
      if (indegree[i] == 0) {
        q.push({1, i});
      }
    }

    cout << "Scenario #" << test_case << ":\n";
    while (!q.empty()) {
      const auto current_boss = q.top();
      q.pop();
      cout << current_boss.rank << " " << current_boss.id << "\n";

      for (auto bullied_one : relations[current_boss.id]) {
        --indegree[bullied_one];
        if (indegree[bullied_one] == 0) {
          q.push({current_boss.rank + 1, bullied_one});
        }
      }
    }
  }
}
