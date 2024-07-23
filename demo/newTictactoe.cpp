#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

struct Pos {
    std::vector<int> dx, dy;
    Pos() {}
    ~Pos() {}
};

struct Blocks {

    explicit Blocks() {}
    ~Blocks() {}
};

struct Command {
    explicit Command() {};
    ~Command() {}
};

template <class Blocks, class Pos, class Command>
struct Scene {
    // using blocks = Blocks;
    // using pos = Pos;
    // using command = Command;

    std::vector<std::string> sce;

    Scene() {
        init();
    }
    ~Scene() {}

    std::function<void()> init = [&]() {
        std::vector<std::string> tmp = &sce;
        tmp.resize(7);
        tmp[0] = tmp[3] = tmp[6] = "?  ?  ?\n";
        tmp[1] = tmp[2] = tmp[4] = tmp[5] = "       \n";
    };
};

int main(void) {
    std::function<void()> preWork = []() {
        Pos pos;
        Blocks blocks;
        Command command;
        Scene<blocks, pos, command> scene;
    }
    preWork();
    return 0;
}
