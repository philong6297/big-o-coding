#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <tuple>

namespace {
using namespace std;

constexpr auto kSize                             = static_cast<size_t>(1e9);
constexpr array<pair<int32_t, int32_t>, 8> kMove = {
  {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}
};
}    // namespace

auto main() -> int32_t {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  map<pair<int32_t, int32_t>, bool> allowed_move{};

  auto src_row = 0;
  auto src_col = 0;
  auto dst_row = 0;
  auto dst_col = 0;

  cin >> src_row >> src_col >> dst_row >> dst_col;

  auto n = 0;
  cin >> n;

  for (auto i = 0; i < n; ++i) {
    auto row       = 0;
    auto col_start = 0;
    auto col_end   = 0;

    cin >> row >> col_start >> col_end;

    for (auto col = col_start; col <= col_end; ++col) {
      allowed_move.emplace(make_pair(row, col), true);
    }
  }

  auto step = 0;
  queue<pair<int32_t, int32_t>> q;
  q.emplace(src_row, src_col);
  allowed_move[{src_row, src_col}] = false;

  while (!q.empty()) {
    ++step;
    for (auto size = q.size(); size > 0; --size) {
      auto current_row              = 0;
      auto current_col              = 0;
      tie(current_row, current_col) = q.front();
      // cout << current_row << "-" << current_col << endl;
      q.pop();

      for (const auto& move : kMove) {
        auto next = move;
        next.first += current_row;
        next.second += current_col;
        // cout << "   check " << next.first << "-" << next.second << endl;

        if (next.first > 0 && next.first <= kSize && next.second > 0 &&
            next.second <= kSize) {
          // cout << "      in range " << endl;
          auto found = allowed_move.find(next);
          if (found == allowed_move.end() || !found->second) {
            // cout << "     disallowed move" << endl;
            continue;
          }
          // cout << "     allowed move" << endl;

          if (next.first == dst_row && next.second == dst_col) {
            cout << step << endl;
            return 0;
          }

          found->second = false;
          q.emplace(next.first, next.second);
        }
      }
    }
  }

  cout << -1 << endl;
  return 0;
}
