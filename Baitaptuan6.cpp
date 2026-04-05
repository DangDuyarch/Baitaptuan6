#include <iostream>
#include <string>
using namespace std;

struct File{        //Khai bao cau truc file
    string name;
    double size; 
    long time;   };

struct Node{      //Khai báo cấu trúc
    File data;
    Node* link;};

void Insertfile(Node*& head, File newFileData) {
    Node* Newnode = new Node;      // Tạo Node mới và gán dữ liệu
    Newnode->data = newFileData;
    Newnode->link = nullptr;

    
    if (head == nullptr || newFileData.time < head->data.time) { // check xem ds có rỗng hoặc file mới cũ hơn file đứng đầu
        Newnode->link = head;
        head = Newnode;           // Thay thế file mới(newnode) vào đầu nếu đúng
        return;
    }

    // Tìm vị trí để chèn vào
    Node* p = head;
    while (p->link != nullptr && p->link->data.time < newFileData.time) {
        p = p->link;
    }
    
    Newnode->link = p->link;   // Chèn node mới vào sau node 'p' đang duyệt
    p->link = Newnode;
}

void printList(Node* head) {
    Node* p = head;
    while (p != nullptr) {
        cout << " ** " << p->data.name << " * Time: " << p->data.time << " * Size: " << p->data.size << "GB]\n";
        p = p->link;
    }
}

int main() {
    Node* Document = nullptr;

    // Demo thêm file vào danh sách
    Insertfile(Document, {"File so 1", 15.5, 1001});
    Insertfile(Document, {"File so 7", 12.0, 1005});
    Insertfile(Document, {"File so 8", 8.5, 1008});
    Insertfile(Document, {"File so 12", 2.6, 1527});
    Insertfile(Document, {"File so 16", 4.4, 1048});
    Insertfile(Document, {"File so 9", 3.1, 1036});
    Insertfile(Document, {"File so 5", 6.2, 1021});
    Insertfile(Document, {"File so 3", 2.3, 1157});
    Insertfile(Document, {"File so 15", 2.4, 2254});

    cout << "Danh sach Documents theo thoi gian:" << endl;
    printList(Document);

    return 0;
}