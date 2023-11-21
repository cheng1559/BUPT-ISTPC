#include <iostream>
#include <fstream>
#include <random>

struct Args {
    int n, m, len, random;
};

void generate(std::size_t id, const Args& task, std::default_random_engine &e) {
    std::vector<std::string> input(task.m);
    std::bernoulli_distribution bool_generator(0.5);

    for (int t = 0; t < task.m; ++t) {
        std::string input_t(task.len, 0);
        if (task.random) {
            bool result = bool_generator(e);
            for_each(input_t.begin(), input_t.end(), [&](auto &it) { it = "01"[bool_generator(e)]; });
            if (result) {
                int t = std::uniform_int_distribution<int>(0, task.len - task.n)(e);
                for (int i = 0; i < task.n; ++i) {
                    input_t[t + i] = '1';
                }
            }
        } else {
            bool result = bool_generator(e);
            std::cout << (result ? "Yes" : "No") << std::endl;
            int p = 0;
            while (p < task.len) {
                int p2 = std::min(p + task.n - 2, task.len - 1);
                for (int i = p; i <= p2; ++i) {
                    input_t[i] = '1';
                }
                p = p2 + 1;
                if (p < task.len) input_t[p] = '0';
                if (p < task.len && result && p + task.n - 2 >= task.len) input_t[p] = '1';
                p++;
            }
        }
        input[t] = input_t;
    }

    auto judge = [](const std::string& s, int n) -> bool {
        int len = s.length();
        for (int i = 0, ones = 0; i < len; ++i) {
            if (s[i] == '1') ++ones;
            else ones = 0;
            if (ones >= n) return true;
        }
        return false;
    };

    std::vector<std::string> output(task.m);
    for (int t = 0; t < task.m; ++t) {
        output[t] = judge(input[t], task.n) ? "Yes" : "No";
    }

    std::ofstream task_in("./data/task_" + std::to_string(id) + ".in");
    assert(task_in.is_open());

    task_in << task.n << " " << task.m << std::endl;
    for (std::size_t i = 0; i < task.m; ++i) {
        task_in << input[i];
        if (i < task.m - 1) task_in << std::endl;
    }
    task_in.close();

    std::ofstream task_out("./data/task_" + std::to_string(id) + ".out");
    assert(task_out.is_open());

    for (std::size_t i = 0; i < task.m; ++i) {
        task_out << output[i];
        if (i < task.m - 1) task_out << std::endl;
    }
    task_out.close();

    std::cout << "generate task " << id << "." << std::endl;
}

int main() {
    std::random_device rd;
    std::default_random_engine e(rd());
    Args task1 = {5, 10, 10, true};
    Args task2 = {50, 100, 100, true};
    Args task3 = {500, 100, 1000, true};
    Args task4 = {5000, 100, 10000, false};
    Args task5 = {50000, 10, 100000, false};
    Args task6 = {888888, 1, 1000000, false};
    Args task7 = {1000000, 1, 1000000, true};
    Args task8 = {1, 100, 10000, true};

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