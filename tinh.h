typedef struct DaiBieu {
  int cmd;
    std::string chucvu;
    int sdt;
    int phieu;
    std::string hoten;
    std::string h;
    std::string cm;
}DB;

typedef struct node {
    DaiBieu data;
    node* next;
}Node;

class List {
private:
    node* head;
    node* tail;
public:
    List();
    node* create(DaiBieu g);
    int check(node* i);
    void themcuoi(DaiBieu g);
    void them(DaiBieu g);
    void xoa(DaiBieu g);
    void sapxep(DaiBieu g);
    void fix();
    void rules();
    void winner();
    void creareFile();
    void printf();
};
