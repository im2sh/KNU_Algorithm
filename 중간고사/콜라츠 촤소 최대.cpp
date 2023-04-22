#include <iostream>
#include <vector>

#define maxshort 987654321
#define maxlong -987654321

using namespace std;
int N, M, ret2;   //ret1 = min, ret2=수 저장
int ret1 = maxshort; // 가장 짧은
//int ret1 = maxlong; // 가장 긴
int result = 0;
//987654321 -> 가장 짧은
//-987654321 -> 가장 긴
vector<int> v, ans;   //ans:정답벡터
int main() {
    cin >> N >> M;
    for (int i = N; i < M; i++) {
        int tmp = i, cnt = 1;
        v.push_back(i);
        while (tmp != 1) {
            result++;
            if (tmp % 2 == 0) tmp /= 2;
            else tmp = tmp * 3 + 1;
            v.push_back(tmp);
            cnt++;
        }
        if (cnt <= ret1) {
            //cnt <= ret1 가장 짧은
            //cnt >= ret1 가장 긴
            /*
             * 여러 개 있을 때 가장 큰 수를 찾으면 = 넣기 즉, 제일 앞에 있는 수
             * 여러 개 있을 때 카장 작은 수를 찾으면 = 빼기 즉, 제일 뒤에 있는 수
             */
            ret1 = cnt;
            ret2 = i;
            ans = v;
        }
        v.clear();
    }
    cout << ret2 << " " << ret1 << "\n";
    for (int i: ans) cout << i << " ";
    cout << "\n";
    cout << result << "\n";
    return 0;
}



//#include <iostream>
//#include <vector>
//using namespace std;
//int N, M, ret1 = -987654321, ret2;   //ret1 = min, ret2=수 저장
////987654321 -> 가장 짧은
////-987654321 -> 가장 긴
//vector<int> v, ans;   //ans:정답벡터
//int main() {
//    cin >> N >> M;
//    for (int i = N; i < M; i++) {
//        int tmp = i, cnt = 1;
//
//        v.push_back(i);
//        while (tmp != 1) {
//            if (tmp % 2 == 0) tmp /= 2;
//            else tmp = tmp * 3 + 1;
//            v.push_back(tmp);
//            cnt++;
//        }
//        if (cnt > ret1) {
//            //cnt < ret1 가장 짧은
//            //cnt > ret1 가장 긴
//            ret1 = cnt;
//            ret2 = i;
//            ans = v;
//        }
//        v.clear();
//    }
//    cout << ret2 << " " << ret1 << "\n";
//    for (int i : ans) cout << i << " ";
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//#define maxshort 987654321
//#define maxlong -987654321
//
//using namespace std;
//typedef long long ll;
//ll N, M, ret2;   //ret1 = min, ret2=수 저장
////int ret1 = maxshort; // 가장 짧은
//ll ret1 = maxlong; // 가장 긴
//
////987654321 -> 가장 짧은
////-987654321 -> 가장 긴
//vector<ll> v, ans;   //ans:정답벡터
//int main() {
//    cin >> N >> M;
//    for (int i = N; i < M; i++) {
//        ll tmp = i, cnt = 1;
//
//        v.push_back(i);
//        while (tmp != 1) {
//            if (tmp % 2 == 0) tmp /= 2;
//            else tmp = tmp * 3 + 1;
//            v.push_back(tmp);
//            cnt++;
//        }
//        if (cnt >= ret1) {
//            //cnt <= ret1 가장 짧은
//            //cnt >= ret1 가장 긴
//            /*
//             * 여러 개 있을 때 가장 큰 수를 찾으면 = 넣기 즉, 제일 앞에 있는 수
//             * 여러 개 있을 때 카장 작은 수를 찾으면 = 빼기 즉, 제일 뒤에 있는 수
//             */
//            ret1 = cnt;
//            ret2 = i;
//            ans = v;
//        }
//        v.clear();
//    }
//    cout << ret2 << " " << ret1 << "\n";
//    for (ll i: ans) cout << i << " ";
//    return 0;
//}
