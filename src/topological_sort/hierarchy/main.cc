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

// TODO(longlp, review);

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

  queue<int32_t> q{};

  for (auto i = 0; i < N; ++i) {
    if (indegree[i] == 0) {
      q.emplace(i);
    }
  }

  vector<int32_t> direct_boss(N, 0);

  auto previous_boss = 0;

  while (!q.empty()) {
    const auto current_boss = q.front();
    q.pop();

    direct_boss[current_boss] = previous_boss;
    previous_boss             = current_boss + 1;

    for (const auto sub : wishes_for_stud[current_boss]) {
      --indegree[sub];
      if (indegree[sub] == 0) {
        q.emplace(sub);
      }
    }
  }

  copy(
    direct_boss.begin(),
    direct_boss.end(),
    ostream_iterator<int32_t>(cout, "\n"));
}
