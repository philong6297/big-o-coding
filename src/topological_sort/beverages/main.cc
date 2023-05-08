#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <string>
#include <vector>

namespace {
using namespace std;

struct BeverageInfo {
  int32_t id{0};
  string name{};
  vector<int32_t> neighbors{};
  int32_t indegree{0};
};

}    // namespace

auto main() -> int32_t {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int32_t N{0};
  auto test_case = 0;
  while (cin >> N) {
    ++test_case;

    map<string /* name */, BeverageInfo*> beverages_by_name{};
    vector<BeverageInfo> beverages_by_id{};
    beverages_by_id.reserve(N);

    for (auto i = 0; i < N; ++i) {
      BeverageInfo beverage{};
      cin >> beverage.name;
      beverage.id = i;

      beverages_by_id.emplace_back(std::move(beverage));
      beverages_by_name[beverages_by_id.back().name] = &beverages_by_id.back();
    }

    int32_t M{0};
    cin >> M;
    for (; M > 0; --M) {
      string buf_1{};
      string buf_2{};
      buf_1.reserve(51);
      buf_2.reserve(51);

      cin >> buf_1 >> ws >> buf_2;
      beverages_by_name[buf_1]
        ->neighbors.emplace_back(beverages_by_name[buf_2]->id);
      ++(beverages_by_name[buf_2]->indegree);
    }

    // choose the smaller id, which means it exists first
    priority_queue<int32_t /* id */, vector<int32_t>, greater<>> queue{};
    for (const auto& beverage : beverages_by_id) {
      if (beverage.indegree == 0) {
        queue.push(beverage.id);
      }
    }

    cout
      << "Case #" << test_case
      << ": Dilbert should drink beverages in this order:";
    while (!queue.empty()) {
      const auto current_id = queue.top();
      queue.pop();

      cout << " " << beverages_by_id[current_id].name;

      for (const auto& neighbor_id : beverages_by_id[current_id].neighbors) {
        --(beverages_by_id[neighbor_id].indegree);
        if (beverages_by_id[neighbor_id].indegree == 0) {
          queue.push(neighbor_id);
        }
      }
    }
    cout << ".\n\n";
  }
}
