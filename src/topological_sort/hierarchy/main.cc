#include <algorithm>
#include <cstdint>
#include <execution>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>

namespace {
using namespace std;
}    // namespace

auto main() -> int32_t {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int32_t N{};
  int32_t K{};
  cin >> N >> K;

  vector<vector<int32_t>> wishes_for_stud(N);

  vector<int32_t> indegree(N, 0);

  for (auto stud_id = 0; stud_id < K; ++stud_id) {
    int32_t W{};
    cin >> W;
    vector<int32_t> wishes{};
    wishes.reserve(W);

    generate_n(back_inserter(wishes_for_stud[stud_id]), W, [&] {
      int32_t id{};
      cin >> id;
      --id;
      ++indegree[id];
      return id;
    });
  }

  auto main_boss = -1;
  for (auto stud_id = 0; stud_id < N; ++stud_id) {
    if (indegree[stud_id] == 0) {
      if (main_boss == -1) {
        main_boss = stud_id;
      }
      else {
        ++indegree[stud_id];
        wishes_for_stud[main_boss].emplace_back(stud_id);
      }
    }
  }

  queue<int32_t> q{};
  q.emplace(main_boss);

  vector<int32_t> direct_boss(N, -1);

  while (!q.empty()) {
    const auto current_boss = q.front();
    q.pop();

    for (const auto sub : wishes_for_stud[current_boss]) {
      --indegree[sub];
      if (indegree[sub] == 0) {
        q.emplace(sub);
        direct_boss[sub] = current_boss;
      }
    }
  }

  for (auto stud_id = 0; stud_id < N; ++stud_id) {
    cout << direct_boss[stud_id] + 1 << endl;
  }
}
