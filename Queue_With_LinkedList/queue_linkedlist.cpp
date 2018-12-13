#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
using namespace std;

typedef struct data
{
	
	string namaPemain;
	string posisiPemain;
	int noPemain;
}dData;

class Simpul{
public:
	dData dataPemain;

	Simpul* pBrktnya;

	Simpul(string nP,string pP, int noP){
		dataPemain.namaPemain = nP;
		dataPemain.posisiPemain = pP;
		dataPemain.noPemain = noP;
		pBrktnya = NULL;
	}
	
	void tampilSimpul(){
		cout << dataPemain.noPemain << " -> " << dataPemain.namaPemain << " -> " << dataPemain.posisiPemain<<endl;
	}
};

class linkedlist{
private:
	Simpul* pPertama;
	Simpul* pAkhir;

public:
	linkedlist():pPertama(NULL), pAkhir(NULL){}
	~linkedlist(){
		Simpul* pSkrng = pPertama;
		while(pSkrng != NULL){
			Simpul* pTemp = pSkrng;
			pSkrng = pSkrng->pBrktnya;
			delete pTemp;
		}
	}

	bool apaKosong(){
		return pPertama==NULL;
	}

	void sisipAkhir(string np, string pP, int noP){
		Simpul* pSimpulBaru = new Simpul(np, pP, noP);
		if(apaKosong())
			pPertama = pSimpulBaru;
		else
			pAkhir->pBrktnya = pSimpulBaru;
		pAkhir = pSimpulBaru;
	}

	double hapusPertama(){
		Simpul* pTemp = pPertama;
		pPertama = pPertama->pBrktnya;
		delete pTemp;
		return 0;
	}

	void tampilSenarai(){
		Simpul* pSkrng = pPertama;
		while(pSkrng != NULL){
			pSkrng->tampilSimpul();
			pSkrng = pSkrng->pBrktnya;
		}
		cout<<endl;
	}
};

class QueueList{
private:
	linkedlist queue;
public:
	bool apaKosong(){
		return queue.apaKosong();
	}

	void enqueue(string nP, string pP, int noP){
		queue.sisipAkhir(nP, pP, noP);
	}

	double dequeue(){
		if(apaKosong()){
			cout<<"Antrian Kosong!!!"<<endl;
		}else{
			return queue.hapusPertama();
		}
		return 0;
	}

	void viewQueue(){
		if(apaKosong()){
			cout<<"Antrian Kosong!!!"<<endl;
		}else{
			cout<<"ISI ANTRIAN"<<endl;
			cout<<"---------------------------------"<<endl;
			queue.tampilSenarai();
		}
	}
};

int main(){
	
	QueueList mainQueue;
	
	int noPemain;
	string namePemain, posPemain;
	int pilih; 
	
do {
 	cout<<"----------------------------------------------------"<<endl;
	cout<<"              QUEUE MENGGUNAKAN LINKED LIST            "<<endl;
 	cout<<"1:Enqueue"<<endl;
 	cout<<"2:Dequeue"<<endl;
 	cout<<"3:TAMPIL"<<endl;
 	cout<<"4:EXIT"<<endl;
 	cout<<"PILIH(1-4): ";cin>>pilih;
 	switch (pilih)
 	{
	case 1: cout<<"Nama Pemain Bola"<<endl;
 			cout<<"-----------------------------"<<endl;
			cout<<"No Punggung : ";cin>>noPemain;cin.ignore();
			cout<<"Nama        : ";getline(cin,namePemain);
 			cout<<"Posisi      : ";getline(cin,posPemain);
			mainQueue.enqueue(namePemain,posPemain,noPemain);
      		break;
 	case 2: mainQueue.dequeue();
         	break;
 	case 3: mainQueue.viewQueue();
         	break;
 	case 4: exit(0);
         	break;
	default : cout<<"Menu yang di input tidak tersedia "<<endl;
 	}
 }while(true);

return 0;
}
