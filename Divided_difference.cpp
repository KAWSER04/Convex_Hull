#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

double func(const std::vector< double > & a, const std::vector< double > & b, int i, int j){
    if ((i < 0) || (j < 0) || (i >= a.size()) || (j >= b.size()) || (i < j)) {
        return 0; // Ignore invalid arguments.
    }
    else if (i == j){
        return b[i];
    }
    else if (a[i] == a[j]) {
        return 0; // Avoid division by 0.
    }

    else if (i == j){
        return b[i];
    }
    else if (i - j == 1){
        return (b[i] - b[j]) / (a[i] - a[j]);
    }
    else
        return (func(a, b, i, j - 1) - func(a, b, i - 1, j)) / (a[i] - a[j]);
}

int main()
{
    int x;
      cout << "How many data points will be entered?:";
    cin >> x;
    std::vector< double > a;
    std::vector< double > b;
    for (int c = 0; c < x; c++){
        double v;
        cout << "Enter X0" << c << ":";
        cin >> v;
        a.push_back(v);
        cout << "Enter y0" << c << ":";
        cin >> v;
        b.push_back(v);
    }
 std::cout << std::endl;
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < x; j = j + 2){
            try {
            double value = func(a, b, i, j);

            std::cout << "p(x): " << value << "(x-" << a[i] << ")" << std::endl;
            }
            catch (...) {
                std::cout << "func( " << i << ", " << j << " ) = invalid " << std::endl;
            }
        }
    return 0;
}

