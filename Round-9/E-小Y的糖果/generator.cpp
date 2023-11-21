#include <iostream>
#include <fstream>
#include <random>
#include <cassert>

struct Args {
    int min_n, min_m, min_k, max_n, max_m, max_k;
};

const int P = 998244353;

int fac[2000005];
int power(int a, int n) {
    int res = 1;
    a %= P;
    for (; n; n /= 2, a = 1LL * a * a % P) {
        if (n % 2) {
            res = 1LL * res * a % P;
        }
    }
    return res;
}

int divide(int a, int b) {
    return 1LL * a * power(b, P - 2) % P;
}

int comb(long long n, int m) {
    if (n < m || m < 0) return 0;
    return divide(divide(fac[n], fac[m]), fac[n - m]);
}

void generate(std::size_t id, const Args& task, std::default_random_engine &e) {
    int n = std::uniform_int_distribution<int>(task.min_n, task.max_n)(e);
    int m = std::uniform_int_distribution<int>(task.min_m, task.max_m)(e);
    int k = std::uniform_int_distribution<int>(task.min_k, task.max_k)(e);

    auto solve = [](int n, int m, int k) -> int {
        fac[0] = 1;
        for (int i = 1; i <= n + m - 1; ++i) {
            fac[i] = 1LL * fac[i - 1] * i % P;
        }
        long long ans = 0;
        for (int i = 0; i <= m; ++i) {
            ans += (i % 2 ? -1LL : 1LL) * comb(m, i) * comb(n - 1LL * i * (k + 1) + m - 1, m - 1) % P;
            ans = (ans + P) % P;
        }
        return ans;
    };

    int output = solve(n, m, k);

    std::ofstream task_in("./data/task_" + std::to_string(id) + ".in");
    assert(task_in.is_open());

    task_in << n << " " << m << " " << k;
    task_in.close();

    std::ofstream task_out("./data/task_" + std::to_string(id) + ".out");
    assert(task_out.is_open());

    task_out << output;
    task_out.close();

    std::cout << "generate task " << id << "." << std::endl;
}

int main() {
    std::default_random_engine e;
    Args task1 = {5, 5, 1, 10, 10, 2};
    Args task2 = {50, 50, 10, 100, 100, 20};
    Args task3 = {1000, 1000, 200, 5000, 5000, 400};
    Args task4 = {5000, 5000, 1000, 10000, 10000, 2000};
    Args task5 = {50000, 50000, 10000, 100000, 100000, 20000};
    Args task6 = {500000, 500000, 100000, 1000000, 1000000, 200000};
    Args task7 = {1000000, 1000000, 1000000, 1000000, 1000000, 1000000};
    Args task8 = {1, 1, 1, 1, 1, 1};

    const std::vector<Args> tasks = {
        task1, task1, task1, task1, task1,
        task2, task2, task2, task2, task2,
        task3, task3, task3, task3, task3,
        task4, task4, task4, task4, task4,
        task5, task5, task5, task5, task5,
        task6, task6, task6, task6, task6,
        task7, task8
    };

    for (std::size_t id = 0; id < tasks.size(); ++id) {
        generate(id, tasks[id], e);
    }
    std::cout << "generate " << tasks.size() << " tasks." << std::endl;
    return 0;
}