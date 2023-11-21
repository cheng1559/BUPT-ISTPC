#include <iostream>
#include <fstream>
#include <random>
#include <cassert>

struct Args {
    int min_x, min_k, max_x, max_k;
};

const int P = 998244353;

int fac[1000005];
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

int comb(int n, int m) {
    if (n < m || m < 0) return 0;
    return divide(divide(fac[n], fac[m]), fac[n - m]);
}

void generate(std::size_t id, const Args& task, std::default_random_engine &e) {
    int x = std::uniform_int_distribution<int>(task.min_x, task.max_x)(e);
    int k = std::uniform_int_distribution<int>(task.min_k, task.max_k)(e);

    std::bernoulli_distribution bool_generator(0.9);
    bool result = bool_generator(e);
    if (result) {
        int times = 100000;
        while (((k - x) % 2 || k < x) && times-- > 0) {
            k = std::uniform_int_distribution<int>(task.min_k, task.max_k)(e);
        }
    }

    auto solve = [](int x, int k) -> int {
        if ((k - x) % 2) {
            return 0;
        }
        fac[0] = 1;
        for (int i = 1; i <= k; ++i) {
            fac[i] = 1LL * fac[i - 1] * i % P;
        }
        int ans = (comb(k, (k - x) / 2) - comb(k, (k - x - 2) / 2) + P) % P;
        return ans;
    };

    int output = solve(x, k);

    std::ofstream task_in("./data/task_" + std::to_string(id) + ".in");
    assert(task_in.is_open());

    task_in << x << " " << k;
    task_in.close();

    std::ofstream task_out("./data/task_" + std::to_string(id) + ".out");
    assert(task_out.is_open());

    task_out << output;
    task_out.close();

    std::cout << "generate task " << id << "." << std::endl;
}

int main() {
    std::default_random_engine e;
    Args task1 = {5, 5, 10, 10};
    Args task2 = {50, 50, 100, 100};
    Args task3 = {1000, 1000, 5000, 5000};
    Args task4 = {5000, 5000, 10000, 10000};
    Args task5 = {50000, 50000, 100000, 100000};
    Args task6 = {500000, 500000, 1000000, 1000000};
    Args task7 = {0, 1, 0, 1};
    Args task8 = {0, 1000000, 0, 1000000};
    Args task9 = {1000000, 1, 1000000, 1};
    Args task10 = {1000000, 1000000, 1000000, 1000000};

    const std::vector<Args> tasks = {
        task1, task1, task1, task1, task1,
        task2, task2, task2, task2, task2,
        task3, task3, task3, task3, task3,
        task4, task4, task4, task4, task4,
        task5, task5, task5, task5, task5,
        task6, task6, task6, task6, task6,
        task7, task8, task9, task10
    };

    for (std::size_t id = 0; id < tasks.size(); ++id) {
        generate(id, tasks[id], e);
    }
    std::cout << "generate " << tasks.size() << " tasks." << std::endl;
    return 0;
}