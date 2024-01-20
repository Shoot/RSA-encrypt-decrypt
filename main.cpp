#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

using ll = long long;

ll gcdExtended(ll a, ll b, ll &x, ll &y) {
    // Базовый случай: если b равно 0, то НОД равен a, а x и y равны 1 и 0 соответственно
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    // Рекурсивный шаг: находим НОД для b и a % b
    ll x1, y1;
    ll gcd = gcdExtended(b, a % b, x1, y1);

    // Обновляем x и y
    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

ll modInverse(ll a, ll m) {
    ll x, y;
    ll gcd = gcdExtended(a, m, x, y);
    // Если a и m не взаимно просты (НОД не равен 1), то обратного по модулю не существует
    if (gcd != 1) {
        cout << "Неверный инпут!\n";
    }
    // Нормализация результата в пределах [0, m)
    return (x % m + m) % m;
}

void encrypt(ll e, ll secret, ll N) {
    ll res = 1;
    while (e--) {
        res = res*secret%N;
    }
    cout << "Шифр: <" << res << ">\n";
}

void decrypt(ll d, ll open, ll N) {
    ll res = 1;
    while (d--) {
        res = res*open%N;
    }
    cout << "Ответ: <" << res << ">\n";
}

int main() {
    ll first;
    cout << "1-Расшифровать, 2-Зашифровать? >> ";
    cin >> first;
    ll N, e;
    cout << "N, e (через пробел)? >> ";
    cin >> N >> e;
    if (first == 1) {
        ll q, p = 1;
        while (true) {
            p += 1;
            if (N%p==0) {
                q = N/p;
                break;
            }
        }
        ll phi = (p-1)*(q-1);
        cout << "e = " << e << ", φ = " << phi << "\n";
        ll d = modInverse(e, phi);
        cout << "d = " << d << "🍻\n";
        ll tests;
        cout << "Кол-во данных? >> ";
        cin >> tests;
        while (tests--) {
            ll open;
            cout << "Введи зашифрованные данные? >> ";
            cin >> open;
            decrypt(d, open, N);
        }
    }
    else if (first == 2) {
        ll tests;
        cout << "Кол-во данных? >> ";
        cin >> tests;
        while (tests--) {
            ll secret;
            cout << "Введи данные которые нужно зашифровать? >> ";
            cin >> secret;
            encrypt(e, secret, N);
        }
    }
    else {
        cout << "Неверный ввод";
    }
}
