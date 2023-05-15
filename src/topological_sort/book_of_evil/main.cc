#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>

namespace {
using namespace std;

// TODO(longlp, review);
auto dfs(
  int32_t from,
  int32_t current_distance,
  vector<bool>& visited,
  vector<int32_t>& distance,
  const set<int32_t>& affected_nodes,
  const vector<vector<int32_t>>& adj) -> void {
  visited[from] = true;
  for (auto to : adj[from]) {
    if (!visited[to]) {
      dfs(to, current_distance + 1, visited, distance, affected_nodes, adj);
    }
  }
  if (affected_nodes.find(from) != affected_nodes.end()) {
    distance[from] = current_distance;
  }
}

auto dfs_2(
  int32_t from,
  int32_t current_distance,
  vector<bool>& visited,
  vector<int32_t>& distance,
  const vector<vector<int32_t>>& adj) -> void {
  visited[from] = true;
  for (auto to : adj[from]) {
    if (!visited[to]) {
      dfs_2(to, current_distance + 1, visited, distance, adj);
    }
  }

  distance[from] = current_distance;
}
}    // namespace

auto main() -> int32_t {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  auto n = 0;
  auto m = 0;
  auto d = 0;

  cin >> n >> m >> d;

  set<int32_t> affected_nodes{};
  for (auto i = 0; i < m; ++i) {
    auto x = 0;
    cin >> x;
    affected_nodes.emplace(--x);
  }

  vector<vector<int32_t>> adj(n, vector<int32_t>());
  for (auto i = 0; i < n - 1; ++i) {
    auto a = 0;
    auto b = 0;
    cin >> a >> b;
    --a;
    --b;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }

  vector<int32_t> distance(n, -1);

  vector<bool> visited(n, false);

  // 0 -> p1 in affected nodes
  dfs(0, 0, visited, distance, affected_nodes, adj);

  auto p1 = std::
    distance(distance.begin(), max_element(distance.begin(), distance.end()));

  // p1 -> p2 in affected nodes
  fill(visited.begin(), visited.end(), false);
  fill(distance.begin(), distance.end(), -1);
  dfs(p1, 0, visited, distance, affected_nodes, adj);

  auto p2 = std::
    distance(distance.begin(), max_element(distance.begin(), distance.end()));

  // p1 -> all
  vector<int32_t> distance_from_p1_to(n, 0);
  fill(visited.begin(), visited.end(), false);
  dfs_2(p1, 0, visited, distance_from_p1_to, adj);

  // p2 -> all
  vector<int32_t> distance_from_p2_to(n, 0);
  fill(visited.begin(), visited.end(), false);
  dfs_2(p2, 0, visited, distance_from_p2_to, adj);

  auto count = 0;
  for (auto i = 0; i < n; ++i) {
    if (distance_from_p1_to[i] <= d && distance_from_p2_to[i] <= d) {
      ++count;
    }
  }

  cout << count;
}
