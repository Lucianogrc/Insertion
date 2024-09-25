#include <iostream>
#include <vector>

using namespace std;

bool numeroPrimo(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}


void insertion(vector<int>& vec) {
    for (int i = 1; i < vec.size(); i++) {
        int key = vec[i];  // Guarda el valor actual.
        int j = i - 1;

        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
    }
}

int main() {
    vector<int> vec = {11, 5, 2, 7, 12, 1, 8, 13};

    // Quitar números no primos del vector
    for (int i = 0; i < vec.size(); i++) {
        if (!numeroPrimo(vec[i])) {
            vec.erase(vec.begin() + i);
            i--;
        }
    }

    insertion(vec);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}