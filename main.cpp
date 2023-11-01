#include"bits/stdc++.h"
#include"tinh.h"
using namespace std;
int main(){
	DB g1;
	List l;
	int k;
	do{
    cout<<"\n\t===== DANH SACH BAU CU =====\t"<<endl;
    printf("\n=============================================");
	printf("\n=      1. Tao danh sach dai bieu            =");
	printf("\n=      2. Xem danh sach dai bieu            =");
	printf("\n=      3. Chen them dai bieu                =");
	printf("\n=      4. Xoa dai bieu                      =");
	printf("\n=      5. Sap xep ten dai bieu theo chu cai =");
	printf("\n=      6. Sua lai phieu bau neu co sai xot  =");
	printf("\n=      7. Xem quy tac bau cu                =");
	printf("\n=      8. Tim nguoi thang cu                =");
	printf("\n=      9. Tao 1 file                        =");
	printf("\n=      10.Exit                              =");
	printf("\n=============================================");
	printf(" \n Ban chon: ");
	scanf("%d",&k);
	switch(k) {
	case 1: 
	l.themcuoi(g1);
	break;
	case 2:	l.printf();
	break;
	case 3:	l.them(g1);
	break;
	case 4:	l.xoa(g1);
	break;
	case 5:	l.sapxep(g1);
	l.printf();
	break;
	case 6:l.fix();
	break;
	case 7:l.rules();
	break;
	case 8:	l.winner();
	break;
	case 9:	l.creareFile();
	break;
	}
}while(k!=10);
}
