#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct vector3D {
    int x;
    int y;
    int z;

    vector3D(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

void bfs_andora(bool ***visited, int ***dist, vector3D &start, vector3D &finish) {
    queue<vector3D> q;
    q.push(start);
    while (!q.empty()) {
        vector3D temp = q.front();
        q.pop();
        if (visited[temp.x][temp.y][temp.z]) {
            continue;
        }
        visited[temp.x][temp.y][temp.z] = true;
        if (temp.x == finish.x && temp.y == finish.y && temp.z == finish.z) {
            break;
        }
        if (temp.x + 1 < 100 && !visited[temp.x + 1][temp.y][temp.z]) {
            dist[temp.x + 1][temp.y][temp.z] = dist[temp.x][temp.y][temp.z] + 1;
            q.push(vector3D(temp.x + 1, temp.y, temp.z));
        }
        if (temp.x - 1 >= 0 && !visited[temp.x - 1][temp.y][temp.z]) {
            dist[temp.x - 1][temp.y][temp.z] = dist[temp.x][temp.y][temp.z] + 1;
            q.push(vector3D(temp.x - 1, temp.y, temp.z));
        }
        if (temp.y + 1 < 100 && !visited[temp.x][temp.y + 1][temp.z]) {
            dist[temp.x][temp.y + 1][temp.z] = dist[temp.x][temp.y][temp.z] + 1;
            q.push(vector3D(temp.x, temp.y + 1, temp.z));
        }
        if (temp.y - 1 >= 0 && !visited[temp.x][temp.y - 1][temp.z]) {
            dist[temp.x][temp.y - 1][temp.z] = dist[temp.x][temp.y][temp.z] + 1;
            q.push(vector3D(temp.x, temp.y - 1, temp.z));
        }
        if (temp.z + 1 < 100 && !visited[temp.x][temp.y][temp.z + 1]) {
            dist[temp.x][temp.y][temp.z + 1] = dist[temp.x][temp.y][temp.z] + 1;
            q.push(vector3D(temp.x, temp.y, temp.z + 1));
        }
        if (temp.z - 1 >= 0 && !visited[temp.x][temp.y][temp.z - 1]) {
            dist[temp.x][temp.y][temp.z - 1] = dist[temp.x][temp.y][temp.z] + 1;
            q.push(vector3D(temp.x, temp.y, temp.z - 1));
        }
    }
}

int on_the_planet_andorra() {
    int k, e;
    cin >> k >> e;
    int x, y, z;
    cin >> x >> y >> z;
    vector3D start{x, y, z};
    cin >> x >> y >> z;
    vector3D final{x, y, z};
    if (start.x == final.x && start.y == final.y && start.z == final.z) {
        cout << 0 << "\n";
        return 0;
    }
    bool ***visited = new bool**[101];
    int ***dist = new int**[101];
    for (int i = 0; i < 101; i++) {
        visited[i] = new bool*[101];
        dist[i] = new int*[101];
        for (int j = 0; j < 101; j++) {
            visited[i][j] = new bool[101];
            dist[i][j] = new int[101];
            for (int l = 0; l < 101; l++) {
                visited[i][j][l] = false;
                dist[i][j][l] = 0;
            }
        }
    }
    int temp_1, temp_2, temp_3, temp_4;
    for (int i = 0; i < k; i++) {
        cin >> temp_1 >> temp_2 >> temp_3 >> temp_4;
        for (int j = temp_3; j < temp_3 + temp_4; j++) {
            visited[temp_1][temp_2][j] = true;
        }
    }
    bfs_andora(visited, dist, start, final);
    if (dist[final.x][final.y][final.z] <= e && dist[final.x][final.y][final.z] != 0) {
        cout << dist[final.x][final.y][final.z] << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}