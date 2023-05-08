#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>

namespace {
using namespace std;
}    // namespace

auto main() -> int {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int32_t m{};
  int32_t n{};
  cin >> n >> m;

  vector<vector<int>> graph(n, vector<int>());
  vector<int> in_degree(n, 0);

  for (; m > 0; --m) {
    auto x = 0;
    auto y = 0;
    cin >> x >> y;

    graph[x - 1].push_back(y - 1);
    ++in_degree[y - 1];
  }

  vector<int32_t> path{};
  path.reserve(n);

  priority_queue<int, vector<int>, greater<>> zero_in_degree{};
  for (auto vertex = 0; vertex < in_degree.size(); ++vertex) {
    if (in_degree[vertex] == 0) {
      zero_in_degree.emplace(vertex);
    }
  }

  for (; !zero_in_degree.empty();) {
    const auto current_vertex = zero_in_degree.top();
    zero_in_degree.pop();

    path.emplace_back(current_vertex + 1);

    for (auto& neighbor : graph[current_vertex]) {
      --in_degree[neighbor];
      if (in_degree[neighbor] == 0) {
        zero_in_degree.push(neighbor);
      }
    }
  }

  if (all_of(in_degree.cbegin(), in_degree.cend(), [](int32_t i) {
        return i == 0;
      })) {
    copy_n(path.cbegin(), n - 1, ostream_iterator<int>(cout, " "));
    cout << path.back();
  }
  else {
    cout << "Sandro fails.";
  }
}
