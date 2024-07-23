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

enum Who {
    player,
    computer
};

enum Result {
    win,
    draw,
    lose
};

struct Pos {
    std::vector<int> dx, dy;
    int x, y;
    Pos() {
        this->init();
    }
    ~Pos() {}

    std::function<void()> init = [&]() {
        this->dx = std::vector({-1, 1, 0, 0});
        this->dy = std::vector({0, 0, 1, -1});
    };
};

struct Blocks {

    std::vector<std::vector<int>> blk;

    explicit Blocks() {
        this->init();
    }
    ~Blocks() {}

    std::function<void()> init = [&]() {
        this->blk.resize(3, {0, 0, 0});
    };

    std::function<bool(Who)> win = [&](Who who_) {
        if (who_ == player) {
            return (blk[0][0] == 1 && blk[0][1] == 1 && blk[0][2] == 1) ||
                   (blk[1][0] == 1 && blk[1][1] == 1 && blk[1][2] == 1) ||
                   (blk[2][0] == 1 && blk[2][1] == 1 && blk[2][2] == 1) ||

                   (blk[0][0] == 1 && blk[1][0] == 1 && blk[2][0] == 1) ||
                   (blk[0][1] == 1 && blk[1][1] == 1 && blk[2][1] == 1) ||
                   (blk[0][2] == 1 && blk[1][2] == 1 && blk[2][2] == 1) ||

                   (blk[2][0] == 1 && blk[1][1] == 1 && blk[0][2] == 1) ||
                   (blk[0][0] == 1 && blk[1][1] == 1 && blk[2][2] == 1);
        } else {
            return (blk[0][0] == -1 && blk[0][1] == -1 && blk[0][2] == -1) ||
                   (blk[1][0] == -1 && blk[1][1] == -1 && blk[1][2] == -1) ||
                   (blk[2][0] == -1 && blk[2][1] == -1 && blk[2][2] == -1) ||

                   (blk[0][0] == -1 && blk[1][0] == -1 && blk[2][0] == -1) ||
                   (blk[0][1] == -1 && blk[1][1] == -1 && blk[2][1] == -1) ||
                   (blk[0][2] == -1 && blk[1][2] == -1 && blk[2][2] == -1) ||

                   (blk[2][0] == -1 && blk[1][1] == -1 && blk[0][2] == -1) ||
                   (blk[0][0] == -1 && blk[1][1] == -1 && blk[2][2] == -1);
        }
    };

    std::function<bool()> draw = [&]() {
        for (int i : blk) {
            if (i == 0)
                return true;
        }
        return false;
    };
};

struct Command {
    explicit Command() {};
    ~Command() {}
};

struct Scene {

    std::vector<std::string> sce;

    Scene() {
        init();
    }
    ~Scene() {}

    std::function<void()> init = [&]() {
        std::vector<std::string> &tmp = this->sce;
        tmp.resize(5);
        tmp[0] = tmp[2] = tmp[4] = "?  ?  ?\n";
        tmp[1] = tmp[3] = "       \n";
    };

    std::function<std::vector<std::string>(Blocks)> sceneTransform = [&](const Blocks &B) {
        std::vector<std::string> ret;
        ret.resize(3, {"???"});
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                switch (B.blk[i][j]) {
                case 0:
                    ret[i][j] = '?';
                    break;
                case 1:
                    ret[i][j] = 'o';
                    break;
                case 2:
                    ret[i][j] = 'x';
                    break;
                default:
                    break;
                }
            }
        }
        return ret;
    };

    std::function<void()> scenePrint = [&]() {
        system("cls");
        for (std::string &i : this->sce) {
            std::cout << i;
        }
    };

    std::function<void(std::vector<std::string>)> sceneUpdate = [&](const std::vector<std::string> &t) {
        sce[0][0] = t[0][0];
        sce[0][3] = t[0][1];
        sce[0][6] = t[0][2];
        sce[2][0] = t[1][0];
        sce[2][3] = t[1][1];
        sce[2][6] = t[1][2];
        sce[4][0] = t[2][0];
        sce[4][3] = t[2][1];
        sce[4][6] = t[2][2];
    };

    std::function<void(Pos, Blocks, Command)> sceneWork = [&](const Pos &P, const Blocks &B, const Command &C) {

    };

    std::function<Result()> sceneJudge = [&]() {
        
    };

    std::function<void(Result)> sceneEnd = [&](const Result result_) {

    };

};

int main(void) {
    Pos pos;
    Blocks blocks;
    Command command;
    Scene scene;
    scene.scenePrint();
    return 0;
}
