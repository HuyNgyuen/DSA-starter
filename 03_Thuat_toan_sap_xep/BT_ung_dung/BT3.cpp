#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// (a) Định nghĩa cấu trúc dữ liệu phòng thi
struct Room {
    int roomNumber;  // Số phòng (1 → 200)
    char building;   // Nhà (A → Z)
    int capacity;    // Khả năng chứa (10 → 250)
};

// Hàm hiển thị danh sách phòng thi
void printRooms(const vector<Room>& rooms) {
    for (const auto& room : rooms) {
        cout << "Nhà " << room.building << " - Phòng " << room.roomNumber
             << " - Sức chứa: " << room.capacity << endl;
    }
    cout << endl;
}

// (b.1) Sắp xếp giảm dần theo khả năng chứa
void sortByCapacity(vector<Room>& rooms) {
    sort(rooms.begin(), rooms.end(), [](const Room& a, const Room& b) {
        return a.capacity > b.capacity;  // Sắp xếp giảm dần
    });
}

// (b.2) Sắp xếp tăng dần theo Nhà, nếu cùng Nhà thì tăng theo Số phòng
void sortByBuildingAndRoom(vector<Room>& rooms) {
    sort(rooms.begin(), rooms.end(), [](const Room& a, const Room& b) {
        if (a.building == b.building)
            return a.roomNumber < b.roomNumber;  // Số phòng tăng dần
        return a.building < b.building;  // Nhà tăng dần từ A → Z
    });
}

// (b.3) Sắp xếp tăng dần theo Nhà, nếu cùng Nhà thì giảm dần theo Khả năng chứa
void sortByBuildingAndCapacity(vector<Room>& rooms) {
    sort(rooms.begin(), rooms.end(), [](const Room& a, const Room& b) {
        if (a.building == b.building)
            return a.capacity > b.capacity;  // Khả năng chứa giảm dần
        return a.building < b.building;  // Nhà tăng dần từ A → Z
    });
}

int main() {
    // Danh sách phòng thi mẫu
    vector<Room> rooms = {
        {101, 'B', 100}, {102, 'A', 150}, {103, 'B', 90}, {201, 'A', 200}, 
        {202, 'C', 120}, {301, 'C', 250}, {203, 'C', 180}, {204, 'A', 80}
    };

    cout << "Danh sách phòng thi ban đầu:\n";
    printRooms(rooms);

    // (b.1) Sắp xếp theo khả năng chứa giảm dần
    sortByCapacity(rooms);
    cout << "Sắp xếp giảm dần theo khả năng chứa:\n";
    printRooms(rooms);

    // (b.2) Sắp xếp theo Nhà (tăng dần), cùng nhà thì theo Số phòng (tăng dần)
    sortByBuildingAndRoom(rooms);
    cout << "Sắp xếp theo Nhà (A → Z), cùng nhà thì theo Số phòng tăng dần:\n";
    printRooms(rooms);

    // (b.3) Sắp xếp theo Nhà (A → Z), cùng nhà thì theo Khả năng chứa giảm dần
    sortByBuildingAndCapacity(rooms);
    cout << "Sắp xếp theo Nhà (A → Z), cùng nhà thì theo Khả năng chứa giảm dần:\n";
    printRooms(rooms);

    return 0;
}
