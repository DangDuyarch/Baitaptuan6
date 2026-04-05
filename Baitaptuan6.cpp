#include <iostream>
#include <string>
using namespace std;

struct File{        //Khai báo cấu trúc file
    string name;
    double size; 
    long time;   };

struct Node{      //Khai báo cấu trúc
    File data;
    Node* link;};


//Chèn node mới vào danh sách theo thứ tự thời gian(trước đến sau)
void Insertfile(Node*& head, File newFileData) {
    Node* Newnode = new Node;      // Tạo Node mới và gán dữ liệu
    Newnode->data = newFileData;
    Newnode->link = nullptr;

    
    if (head == nullptr || newFileData.time < head->data.time) { // check xem ds có rỗng hoặc file mới cũ hơn file đứng đầu
        Newnode->link = head;
        head = Newnode;           // Thay thế file mới(newnode) vào đầu nếu đúng
        return;     }

    // Tìm vị trí để chèn vào
    Node* p = head;
    while (p->link != nullptr && p->link->data.time < newFileData.time)   p = p->link;  
    
    Newnode->link = p->link;   // Chèn node mới vào sau node 'p' đang duyệt
    p->link = Newnode;
}


//Chèn node mới vào danh sách theo thứ tự kích thước(nhỏ đến lớn)
void InsertSize(Node*& head, File newFileData) {
    Node* Newnode = new Node;      // Tạo Node mới và gán dữ liệu
    Newnode->data = newFileData;
    Newnode->link = nullptr;

    
    if (head == nullptr || newFileData.size < head->data.size) { // check xem ds có rỗng hoặc file mới nhỏ hơn file đứng đầu
        Newnode->link = head;
        head = Newnode;           // Thay thế file mới(newnode) vào đầu nếu đúng
        return;    }
    // Tìm vị trí để chèn vào
    Node* p = head;
    while (p->link != nullptr && p->link->data.size < newFileData.size) p = p->link;
  
    Newnode->link = p->link;     // Chèn node mới vào sau node 'p' đang duyệt
    p->link = Newnode;
}

// Hàm sao chép dữ liệu từ List 1 sang List 2 và sắp xếp theo Size
void CopyListandSort(Node* headSource, Node*& headDest) {
    Node* q = headSource; 
    while (q != nullptr) {
        InsertSize(headDest, q->data); 
        q = q->link;
    }
}

//Hàm tính tổng dung lương(kích thước) các file
double Sumsize(Node* head) {
    double sum = 0;
    Node* p = head; 
    while (p != nullptr) {
        sum += p->data.size; // Tổng kích thước
        p = p->link;
    }
    return sum;
}
//in ra List (Document)
void printList(Node* head) {
    Node* p = head;
    while (p != nullptr) {
        cout << " ** " << p->data.name << " * Time: " << p->data.time << " * Size: " << p->data.size << "GB]\n";
        p = p->link;
    }
}




int main() {
    Node* Document = nullptr;
    Node* Document2 = nullptr; 
    // Thêm file vào danh sách
    Insertfile(Document, {"File so 1", 8.5, 1001});
    Insertfile(Document, {"File so 7", 7.0, 1005});
    Insertfile(Document, {"File so 8", 6.5, 1008});
    Insertfile(Document, {"File so 12", 2.6, 1527});
    Insertfile(Document, {"File so 16", 4.4, 1048});
    Insertfile(Document, {"File so 9", 3.1, 1036});
    Insertfile(Document, {"File so 5", 6.2, 1021});
    Insertfile(Document, {"File so 3", 5.3, 1157});
    Insertfile(Document, {"File so 15", 5.4, 2254});
    Insertfile(Document, {"File so 10", 8.5, 1016});

    cout << "Danh sach Documents theo thoi gian:" << endl;
    printList(Document);

    cout << "Tong dung luong ban dau: " << Sumsize(Document) << "GB" ;
    if(Sumsize(Document)>32.0) cout << "( > 32Gb) \n" << endl;
    if(Sumsize(Document)<32.0) cout << "( < 32Gb) \n" << endl;
    CopyListandSort(Document, Document2);

    cout << "Xoa cac file nho nhat de dam bao dung luong <32Gb " << endl;
    while (Document2 != nullptr && Sumsize(Document2) > 32.0) {  // Duyệt Document2 để xóa đảm bảo sumsize<32gb
        Node* temp = Document2; 
        cout << " Xoa file:  " << temp->data.name << " (" << temp->data.size << "GB)" << endl;
        Document2 = Document2->link;     // xóa các file 
        delete temp;                 
    }

    // In ra danh sach con lai
    cout << "\n Danh sach cac file con lai sau khi xoa (Dung luong <32Gb): " << endl;
     printList(Document2);
    cout << "Tong dung luong con lai: " << Sumsize(Document2) << " GB" << endl;
    

    return 0;
}