#include <iostream>
#include <vector>
using namespace std;

struct vector3D {
    int x;
    int y;
    int z;
    int h;
};

int main() {
    int k, e;
    cin >> k >> e;
    vector3D start{};
    cin >> start.x >> start.y >> start.z;
    vector3D final{};
    cin >> final.x >> final.y >> final.z;
    vector<vector3D> buildings(k);
    for (int i = 0; i < k; i++) {
        cin >> buildings[i].x >> buildings[i].y >> buildings[i].z >> buildings[i].h;
    }

}