#include <iostream>
#include <fstream>
#include <random>
#include <format>
#include <cassert>

struct Args {
    int n, k;
};

void generate(std::size_t id, const Args& task, std::default_random_engine &e) {
    std::vector<int> l(task.n + 1), r(task.n + 1);
    std::uniform_int_distribution<int> generator(1, task.n);
    int k = task.k > 0 ? task.k : generator(e);

    if (task.k == -2) {
        for (int i = 1; i < task.n; ++i) {
            l[i] = i + 1;
        }
        k = task.n;
    } else if (task.k == -3) {
        for (int i = 1; i < task.n; ++i) {
            r[i] = i + 1;
        }
        k = task.n;
    } else {
        struct DSU {
            std::vector<int> f, siz;
            DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
            int leader(int x) {
                while (x != f[x]) x = f[x] = f[f[x]];
                return x;
            }
            bool same(int x, int y) { return leader(x) == leader(y); }
            bool merge(int x, int y) {
                x = leader(x);
                y = leader(y);
                if (x == y) return false;
                siz[x] += siz[y];
                f[y] = x;
                return true;
            }
            int size(int x) { return siz[leader(x)]; }
        };
        DSU dsu(task.n + 1);
        std::vector<std::vector<int>> g(task.n + 1);
        std::vector<int> degree(task.n + 1), vis(task.n + 1);
        for (int i = 0; i < task.n - 1; ++i) {
            int a = generator(e);
            int b = generator(e);
            while (dsu.same(a, b) || degree[a] == 3 || degree[b] == 3 || ((a == 1 || b == 1) && degree[1] == 2)) {
                a = generator(e), b = generator(e);
            }
            ++degree[a];
            ++degree[b];
            dsu.merge(a, b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        auto dfs = [&](auto dfs, int u) -> void {
            vis[u] = 1;
            for (auto v : g[u]) {
                if (vis[v]) continue;
                if (!l[u]) l[u] = v;
                else r[u] = v;
                dfs(dfs, v);
            }
        };
        dfs(dfs, 1);
    }

    auto solve = [](const std::vector<int> l, const std::vector<int>& r, int k) -> std::vector<int> {
        if (k == 1) return {1};
        int n = l.size();
        std::vector<int> father(n + 1), temp, ans;
        for (int i = 1; i <= n; ++i) {
            if (l[i]) father[l[i]] = i;
            if (r[i]) father[r[i]] = i;
        }
        while (k) {
            temp.push_back(k);
            k = father[k];
        }
        int idx = temp.size();
        for (int i = idx - 1; i > -idx; --i) {
            ans.push_back(temp[abs(i)]);
        }
        return ans;
    };

    std::vector<int> output = solve(l, r, k);

    std::ofstream task_in("./data/task_" + std::to_string(id) + ".in");
    assert(task_in.is_open());

    task_in << task.n << " " << k << std::endl;
    for (std::size_t i = 1; i <= task.n; ++i) {
        task_in << l[i] << " " << r[i];
        if (i < task.n) task_in << std::endl;
    }
    task_in.close();

    std::ofstream task_out("./data/task_" + std::to_string(id) + ".out");
    assert(task_out.is_open());

    for (std::size_t i = 0; i < output.size(); ++i) {
        task_out << output[i];
        if (i < output.size() - 1) task_out << " ";
    }
    task_out.close();

    std::cout << "generate task " << id << "." << std::endl;
}

int main() {
    std::default_random_engine e;
    Args task1 = {10, -1};
    Args task2 = {100, -1};
    Args task3 = {1000, -1};
    Args task4 = {10000, -1};
    Args task5 = {100000, -1};
    Args task6 = {500, 1};
    Args task7 = {5000, 1};
    Args task8 = {100000, 100000};
    Args task9 = {100000, -2};
    Args task10 = {100000, -3};
    Args task11 = {1, 1};

    const std::vector<Args> tasks = {
        task1, task1, task1, task1, task1,
        task2, task2, task2, task2, task2,
        task3, task3, task3, task3, task3,
        task4, task4, task4, task4, task4,
        task5, task5, task5, task5, task5,
        task6, task7, task8, task9, task10,
        task11
    };

    for (std::size_t id = 0; id < tasks.size(); ++id) {
        generate(id, tasks[id], e);
    }
    std::cout << std::format("generate {0} tasks.", tasks.size()) << std::endl;
    return 0;
}