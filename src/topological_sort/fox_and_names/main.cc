#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <vector>

namespace {
using namespace std;
}    // namespace

auto main() -> int32_t {
  int32_t n{};
  cin >> n;

  array<vector<int32_t>, 26> adj{};
  array<int32_t, 26> in_degree{};
  in_degree.fill(0);

  string prev;
  string current;
  for (auto i = 0; i < n; ++i) {
    cin >> current;
    if (i > 0) {
      auto first_diff_idx = -1;
      for (
        first_diff_idx = 0;
        first_diff_idx < prev.size() && first_diff_idx < current.size() &&
        prev[first_diff_idx] == current[first_diff_idx];
        ++first_diff_idx) {}

      // reached the string end in one of them
      // at this point, they are all the same character
      if (first_diff_idx == prev.size() || first_diff_idx == current.size()) {
        // however, if the previous has larger size than the current, it would
        // be invalid Lexicographical order
        if (prev.size() > current.size()) {
          cout << "Impossible" << endl;
          return 0;
        }

        // otherwise, skip to next string
        prev = current;
        continue;
      }

      // found first diff
      // add relations to the graph
      const auto from = prev[first_diff_idx] - 'a';
      const auto to   = current[first_diff_idx] - 'a';
      adj[from].push_back(to);
      ++in_degree[to];

      prev = current;
      continue;
    }
    prev = current;
  }

  queue<int32_t> q{};
  for (auto i = 0; i < in_degree.size(); ++i) {
    if (in_degree[i] == 0) {
      q.push(i);
    }
  }

  vector<char> order{};
  order.reserve(26);

  while (!q.empty()) {
    const auto current_char = q.front();
    q.pop();

    order.emplace_back(current_char + 'a');

    for (const auto neighbor_char : adj[current_char]) {
      --in_degree[neighbor_char];
      if (in_degree[neighbor_char] == 0) {
        q.push(neighbor_char);
      }
    }
  }

  if (order.size() != 26) {
    cout << "Impossible" << endl;
    return 0;
  }

  copy(order.begin(), order.end(), ostream_iterator<char>(cout));
  cout << endl;
}
