#include <iostream>
//  avoid using namespace std; at header
namespace math {
    int add(int a, int b) {
        return a + b;
    }
}

int main() {
    std::cout << math::add(3, 4) << std::endl;
    return 0;
}

