#include"bits/stdc++.h"
#include"tinh.h"
using namespace std;
List::List() {
    head = tail = NULL;
}
node* List::create(DaiBieu g) {
    node* p = new node();
    cout << "\nNhap ho ten dai bieu: ";
    fflush(stdin);
    getline(cin, g.hoten);
    cout << "\nNhap ly lich 3 doi (Tot,Trung binh): ";
    fflush(stdin);
    getline(cin, g.h);
    cout << "\nNhap so dien thoai: ";
    cin >> g.sdt;
    cout << "\nNhap chuc vu hien tai: ";
    fflush(stdin);
    getline(cin, g.chucvu);
    cout << "\nNhap so phieu: ";
    cin >> g.phieu;
    cout << "\nNhap do tin nhiem: ";
    cin >> g.cmd;
    cout << "\nCo cong voi cach mang(Co,Khong): ";
    fflush(stdin);
    getline(cin, g.cm);
    p->data = g;
    p->next = NULL;
    return p;
}
void List::them(DB g){
	int k;
	cout<<"Chen vao dai bieu thu: ";
	cin>>k;
	node *q = create(g);
	if(k==1){
	 	q->next=head;
	 	head=q;
	 }
	 else{
	 Node *a= head;
	  	for(int i=1;i<k-1;i++){
	  	    a=a->next;
	  	}
	q->next= a->next;
	a->next=q;
	}
	cout<<"Da them!!!"<<endl;
}

void tachten(string hoten, string& ten) {
    int index = hoten.find_last_of(' ');
    if (index != string::npos) {
        ten = hoten.substr(index + 1);
    }
}

void List::sapxep(DB g) {
    node* p, * q;
    for (p = head; p != tail; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            string ten1, ten2;
            tachten(p->data.hoten, ten1);
            tachten(q->data.hoten, ten2);
            int check1 = ten1.compare(ten2);
            if (check1 > 0) {
                g = p->data;
                p->data = q->data;
                q->data = g;
            }
            else if (check1 == 0) {
                int check2 = p->data.hoten.compare(q->data.hoten);
                if (check2 > 0) {
                    g = p->data;
                    p->data = q->data;
                    q->data = g;
                }
            }
        }
    }
}
void List::xoa(DB g){
	int k;
	cout<<"Xoa dai bieu thu: ";
	cin>>k;
	Node *a= head;
	Node *b = head;
	if(k==1){
		Node *p=head;
		head=head->next;
		delete p;
	}
	else{
	
	  	for(int i=1;i<k-1;i++){
	  	    a=a->next;
	  	}
	  	for(int i=0;i<k-1;i++){
	  	    b=b->next;
	  	}
	  	a->next= b->next;
	  	delete b;
}
}
void List::creareFile() {
    int m = 1;
    FILE* f;
    f = fopen("cart.dat", "wb");
    fprintf(f, "\nSTT     Ho va ten               Ly lich 3 doi            So dien thoai       Chuc vu hien tai       So phieu      Do tin nhiem      Co cong voi cach mang\n");
    for (node* i = head; i != NULL; i = i->next) {
        fprintf(f, "%-7d %-23s %-24s %-19d %-22s %-13d %-17d %s \n", m, i->data.hoten.c_str(), i->data.h.c_str(), i->data.sdt, i->data.chucvu.c_str(), i->data.phieu, i->data.cmd, i->data.cm.c_str());
        m++;
    }
    cout << "Da luu du lieu!!!" << endl;
    fclose(f);
}
void List::themcuoi(DB g){
	node *q = create(g);
	if(head==NULL){
		head=tail=q;		
	}
	else{
		tail->next=q;
		tail=q;
	}
	cout<<"Da tao!!!"<<endl;
}
void List::printf() {
    int l = 1;
cout << "Danh sach dai bieu gom: " << endl;
cout << left << setw(9) << "STT" << setw(20) << "Ho va ten" << setw(20) << "Ly lich 3 doi" << setw(19) << "So dien thoai";
cout << left << setw(20) << "Chuc vu hien tai" << setw(12) << "So phieu" << setw(15) << "Do tin nhiem" << "Co cong voi cach mang" << endl;
    for (node* i = head; i != NULL; i = i->next) {
    cout << left << setw(9) << l << setw(20) << i->data.hoten << setw(20) << i->data.h << setw(19) << i->data.sdt;
    cout << left << setw(20) << i->data.chucvu << setw(12) << i->data.phieu << setw(15) << i->data.cmd << i->data.cm << endl;
        l++;
    }
}
void List::fix() {
    string ten;
    int phieu;
    cout << "\nNhap ho ten dai bieu ban muon sua phieu: ";
    fflush(stdin);
    getline(cin, ten);
    cout << "Nhap so phieu muon sua: ";
    cin >> phieu;
    for (node* i = head; i != NULL; i = i->next) {
        if (i->data.hoten == ten) {
            i->data.phieu = phieu;
        }
    }
    cout << "Da sua xong!!!" << endl;
}
void List::rules(){
	cout<<"1. Neu ly lich 3 doi tot thi +1d, trung binh thi 0d"<<endl;
	cout<<"2. Neu so phieu tu 0 -> 250 : +1d"<<endl;
	cout<<"                   251 -> 500: +2d"<<endl;
	cout<<"                   501 -> 1000: +3d"<<endl;
	cout<<"                   1000 tro len thi: +4d"<<endl;
	cout<<"3. Neu do tin nhiem tu 0 -> 500: +1d"<<endl;
	cout<<"                   501 -> 1000: +2d"<<endl;
	cout<<"                   1000 tro len thi: +3d"<<endl;
	cout<<"4. Co cong voi cach mang thi +1d, khong thi +0d"<<endl;
	cout<<"Nguoi co so diem tong ket cao nhat se thang cu!!!"<<endl;
	cout<<"Truong hop bi trung diem thi se xet them tieu chi phu"<<endl;
	cout<<"Tieu chi phu la xet phieu bau cu, neu ai nhieu hon se thang"<<endl;
}
int List::check(node* i) {
    int tong = 0;
    int phieu = i->data.phieu;
    int cmd = i->data.cmd;
    tong += (phieu <= 250) ? 1 : (phieu <= 500) ? 2 : (phieu <= 1000) ? 3 : 4;
    tong += (cmd <= 500) ? 1 : (cmd <= 1000) ? 2 : 3;
    tong += (i->data.h.compare("Tot") == 0) ? 1 : 0;
    tong += (i->data.cm.compare("Co") == 0) ? 1 : 0;
    return tong;
}
void List::winner() {
    int max = check(head);
    node* winner = head;
    for (node* i = head; i != NULL; i = i->next) {
        int score = check(i);
        if (score > max || (score == max && i->data.phieu > winner->data.phieu)) {
            max = score;
            winner = i;
        }
    }
    cout << "Xin chuc mung!!!" << endl;
    cout << "Voi tong so diem la: " << max << " nguoi thang cu la: " << winner->data.hoten << endl;
}
