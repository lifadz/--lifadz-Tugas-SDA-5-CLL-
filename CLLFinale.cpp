//Modifikasi Single Linked List menjadi Circular Linked List men

#include<iostream>
using namespace std;

struct circularll{ //struct
    
    int angka;
    circularll* next; 
};
circularll *awal = NULL, *cur ,*tambah, *del,*tambahfirst,*after;

//membuat node awal
void circularlist (int Num){
    circularll* p = new circularll;
    p->angka = Num;  
    awal = p;
    p->next = awal;
}
//membuat fungsi insert first
void tambahawal (int Num){
    circularll* p = new circularll;
    p->angka = Num;
    circularll* q = awal;
    while (q->next != awal){
        q = q->next;
    }
    p->next = awal;
    q->next = p;
    awal = p;

    
}   
//membuat fungsi insert last
void tambahakhir (int Num){
    circularll* p = new circularll;
    p->angka = Num;
    circularll* q = awal;
    while (q->next != awal){
        q = q->next;
    }
    p->next = awal;
    q->next = p;
}
//membuat fungsi insert after first
void tambahsetelahawal(int Num) {
    tambahfirst = new circularll;
    tambahfirst->angka = Num;

    cur = awal;
    Num = 1 ;
    while (Num < -1 ){
        cur = cur->next;
        Num++;       
    }
    tambahfirst->next = cur->next;
    cur->next = tambahfirst;   
}


//membuat fungsi delete first
void hapusawal (){
    circularll* p;
    circularll* q = awal;
    while (q->next != awal){
        q = q->next;
    }
    p = awal;
    awal = p->next;
    p->next = NULL;
    q->next = awal;
    delete p;
    
}
//membuat fungsi delete last
void hapusakhir (){ 
    circularll* p;
    circularll* q = awal;
    while (q->next->next != awal){
        q = q->next;
    }
    p = q->next;
    q->next = awal;
    p->next = NULL;
    delete p;
    
}
//membuat fungsi delet after first
void hapussetelahawal(int poss){ //Masukkan urutan data ke berapa yang ingin dihapus
 int nomor = 1;
    cur = awal;
    while( nomor <= poss ){
      if( nomor == poss-1 ){
        after = cur;
      }
      if( nomor == poss ){
        del = cur;
      }
      cur = cur->next;
      nomor++;
    }
    after->next = cur;
    delete del;
  }
//membuat fungsi search sequential
int cariangka(int key){
    circularll* p = awal;
    int i = 1;
    while (p->angka != key){
        p = p->next;
        i++;
    }
    return i;
}
//untuk print data
void printdatacircularlist(){ 
    cur = awal;
    while (cur->next != awal){
        cout << cur-> angka << " ";
        cur = cur->next;
    }
    cout << cur-> angka << " ";
    cout<<endl;
}

int main(){
    
    circularlist(3); // untuk deklarasi node awal
    printdatacircularlist();
    //print data
   
    tambahawal(1); //insert atau tambah awal
    printdatacircularlist();
    //print data

    tambahawal(5);//insert atau tambah awal
    printdatacircularlist();
    //print data
    
    tambahsetelahawal(9);//insert atau tambah setelah awal
    printdatacircularlist();
    //print data

    tambahsetelahawal(2);//insert atau tambah setelah awal
    printdatacircularlist();
    //print data
    
    tambahakhir(6);//insert atau tambah akhir
    printdatacircularlist();
    //print data
    
    hapusawal();//delete awal
    printdatacircularlist();
    //print data

    hapussetelahawal(2);//delete setelah awal
    printdatacircularlist();
    //print data

    hapusakhir();//delete akhir
    printdatacircularlist();
    //print data

    //untuk input data yang ingin dicari
    int key;
    cout << "Masukkan data yang ingin dicari: ";
    cin >> key; 
    cout << "Data yang anda cari terdapat pada urutan ke - " << cariangka(key);
    
}