#include <iostream>
#include <utility>
#include <vector>

using namespace std;

auto main() -> int32_t {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  uint32_t N{0};
  cin >> N;
  vector<pair<bool /* i is_zero */, uint32_t /* number of 0's from 0 to i */>>
    count_0_from_begin_to(N);
  for (auto i = 0; i < N; ++i) {
    auto is_1 = false;
    cin >> is_1;
    count_0_from_begin_to[i].first  = !is_1;
    count_0_from_begin_to[i].second = static_cast<uint32_t>(!is_1);
    if (i > 0) {
      count_0_from_begin_to[i].second += count_0_from_begin_to[i - 1].second;
    }
  }

  uint32_t q{0};
  cin >> q;
  for (; q > 0; --q) {
    auto L = 0;
    auto R = 0;
    cin >> L >> R;
    --L;
    --R;

    const auto count_0 =
      count_0_from_begin_to[R].second - count_0_from_begin_to[L].second +
      static_cast<uint32_t>(count_0_from_begin_to[L].first);
    const auto count_1 = (R - L + 1) - count_0;

    // any odd number of 1's will result in a true XOR
    cout << (count_1 & 1U) << " " << count_0 << '\n';
  }
}
