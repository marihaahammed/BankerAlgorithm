#include <iostream>
#include <vector>
#include <fstream>

using std::cin; using std::cout; using std::endl;

int main(int argc, char* argv[]) {

    std::ifstream in(argv[1]);
    int number;

    std::vector<int> v;
    while (in >> number) {
        v.push_back(number);
    }

    int p = 5; // no, of process
    int r = 3; // no. of  resources

    int allocation[5][3] = { {v[0], v[1], v[2]}, // allocation array
                         {v[3], v[4], v[5]},
                         {v[6], v[7], v[8]},
                         {v[9], v[10], v[11]},
                         {v[12], v[13], v[14]} };

    int maximum[5][3] = { {v[15], v[16], v[17]},  // maximum array
                         {v[18], v[19], v[20]},
                         {v[21], v[22], v[23]},
                         {v[24], v[25], v[26]},
                         {v[27], v[28], v[29]} };

    int available[3] = { v[30], v[31], v[32] }; // available array

    int finish[5], safe[5], index = 0;
    int need[5][3];

    for (int k = 0; k < p; k++) {
        finish[k] = 0;
    }
    for (int i = 0; i < p; i++) {              //need array
        for (int j = 0; j < r; j++)
            need[i][j] = maximum[i][j] - allocation[i][j];
    }

    //deciding if the process should wait or proceed

    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < p; i++) {
            if (finish[i] == 0) {
                int flag = 0;
                for (int j = 0; j < r; j++) {
                    if (need[i][j] > available[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    safe[index++] = i;
                    for (int y = 0; y < r; y++)
                        available[y] += allocation[i][y];
                    finish[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    // To check if sequence is safe or not

    for (int i = 0; i < p; i++) {
        if (finish[i] == 0) {
            flag = 0;
            cout << "The given sequence is not safe";
            break;
        }
    }
    if (flag == 1) {
        cout << "Following is the SAFE Sequence" << endl;
        for (int i = 0; i < p - 1; i++)
            cout << " P" << safe[i] << " ->";
        cout << " P" << safe[p - 1] << endl;
    }
}