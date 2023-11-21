#include <iostream>
#include <fstream>
#include <random>

struct Args {
    int n, l, r;
};

void generate(std::size_t id, const Args& task, std::default_random_engine &e) {
    std::uniform_int_distribution<int> generator(task.l, task.r);
    std::vector<int> input(task.n + 1);
    std::for_each(input.begin(), input.end(), [&](auto &it) { it = generator(e); });

    std::vector<long long> output(task.n - 1);
    for (int i = 0; i < task.n - 1; ++i) {
        output[i] = 1LL * (i + 1) * (i + 2) * input[i + 2];
    }

    std::ofstream task_in("./data/task_" + std::to_string(id) + ".in");
    assert(task_in.is_open());

    task_in << task.n << std::endl;
    for (std::size_t i = 0; i < task.n + 1; ++i) {
        task_in << input[i];
        if (i < task.n) task_in << " ";
    }
    task_in.close();

    std::ofstream task_out("./data/task_" + std::to_string(id) + ".out");
    assert(task_out.is_open());

    for (std::size_t i = 0; i < task.n - 1; ++i) {
        task_out << output[i];
        if (i < task.n - 2) task_out << " ";
    }
    task_out.close();

    std::cout << "generate task " << id << "." << std::endl;
}

int main() {
    std::default_random_engine e;
    Args task1 = {10, 1, 100};
    Args task2 = {100, 1, 100};
    Args task3 = {1000, 1, 100};
    Args task4 = {5000, 1, 500};
    Args task5 = {10000, 1, 1000};
    Args task6 = {100000, 1, 1000};

    const std::vector<Args> tasks = {
        task1, task1, task1, task1, task1,
        task2, task2, task2, task2, task2,
        task3, task3, task3, task3, task3,
        task4, task4, task4, task4, task4,
        task5, task5, task5, task5, task5,
        task6, task6, task6, task6, task6,
    };

    for (std::size_t id = 0; id < tasks.size(); ++id) {
        generate(id, tasks[id], e);
    }
    std::cout << "generate " << tasks.size() << " tasks." << std::endl;
    return 0;
}