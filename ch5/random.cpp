#include <algorithm>
#include <time.h>
#include <math.h>
#include <iostream>

using namespace std;

int rand01() {
    return rand() % 2;
}

int randrange(int a, int b) {
    int range = b - a;
    int bits = ceil(log2(range));
    int result = 0;
    for (int i = 1; i <= bits; i++) {
        int r = rand01();
        // result = result + r >> i;
        result = 2 * result + r;
    }
    if (result > range)
        return randrange(a, b);
    return a + result;
}

int randrange2(int a, int b) {
    int result = a;
    for (int i = 1; i <= b - a; i++) {
        result += rand01();
    }
    return result;
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        cout << randrange2(3, 7) << " ";
    }
    cout << endl;
    
    /* code */
    return 0;
}
