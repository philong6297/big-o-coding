#include <iostream>
#include <queue>
#include <vector>

namespace {
using namespace std;
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
      --lower;
      --higher;

      relations[higher].emplace_back(lower);
      ++indegree[lower];
    }

    priority_queue<int32_t, vector<int32_t>, greater<>> queue{};
    for (auto i = 0; i < N; ++i) {
      if (indegree[i] == 0) {
        queue.push(i);
      }
    }
  }
}
