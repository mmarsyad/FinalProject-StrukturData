#include <iostream>
#include <conio.h>
#include <Windows.h> // untuk menggunakan fungsi Sleep()
#include <deque>

using namespace std;

struct mahasiswa {
	string nim;
	string nama;
	float ipk;
};

deque<mahasiswa> mhs;

bool kosong() {
	if (mhs.empty()) {
		return true;
	}
	else {
		return false;
	}
}

bool cekNim(string nim) {
	bool status = false;
	for (int i = 0;i < mhs.size(); i++) {
		if (mhs[i].nim == nim) {
			return status = true;
		}
	}
	return status;
}

void input(string nim, string nama, float ipk) {
	string* ptrNim = &nim;
	string* ptrNama = &nama;
	float* ptrIpk = &ipk;
	if (cekNim(nim)) {
		cout << "NIM sudah ada !" << endl;
	}
	else if (!cekNim(nim)) {
		mhs.push_front({ *ptrNim,*ptrNama,*ptrIpk });
	}
	
	
}

void hapus() {
	if (!kosong()) {
		mhs.pop_front();
		cout << "Data inputan terakhir sudah di hapus";
	}
	else {
		cout << "Data kosong, Silahkan tambahkan data terlebih dahulu.";
	}
}

void tampilUrut() {
	if (!kosong()) {
		for (int i = 0; i < mhs.size(); i++) {
			for (int j = 0; j < mhs.size() - i - 1; j++) {
				if (mhs[j].ipk < mhs[j + 1].ipk) {
					mahasiswa min = mhs[j];
					mhs[j] = mhs[j + 1];
					mhs[j + 1] = min;
				}
			}
		}
		cout << mhs.size() << endl;
		cout << "=============================" << endl;
		cout << "= NO.\tNIM\tNAMA\tIPK =" << endl;
		cout << "=============================" << endl;
		for (int i = 0;i < mhs.size();i++) {
			cout << i + 1 << ". \t" << mhs[i].nim;
			cout << "\t" << mhs[i].nama;
			cout << "\t" << mhs[i].ipk;
			cout << endl;
		}
	}
	else {
		cout << "Data Mahasiswa masih kosong";
	}
}

void bersih() {
	mhs.clear();
	cout << "Berhasil. Data sudah kosong !";
}

int cariNim(string nim) {
	int posisi = -1;

	for (int i = 0;i < mhs.size(); i++) {
		if (mhs[i].nim == nim) {
			return posisi = i;
		}
		else if (posisi != -1) {
			return posisi;
		}
	}
}

void tampilCari(int i) {
	if ( i == -1) {
		cout << "Maaf data yang anda cari tidak ditemukan";
	}
	else {	
		cout << endl;
		cout << "NIM\t: " << mhs[i].nim << endl;
		cout << "Nama\t: " << mhs[i].nama << endl;
		cout << "IPK\t: " << mhs[i].ipk << endl;
		cout << "Data yang anda cari ditemukan !" << endl;
	}
}

void cariNama(string nama) {

}

int main() {
menu:
	system("cls");
	string pilihan;
	cout << "==========================================================================" << endl;
	cout << "=                   Sistem Penginputan Nilai Mahasiswa                   =" << endl;
	cout << "==========================================================================" << endl;
	cout << "1. Input Nilai Mahasiswa\n2. Cari Mahasiswa berdasarkan NIM\n3. List Mahasiswa berdasarkan IPK tertinggi\n4. Hapus data Tertinggi\n5. Bersihkan data Mahasiswa\n6. Keluar" << endl;
	cout << "Masukkan pilihan anda : ";
	cin >> pilihan;

	if (pilihan == "1") {
		system("cls");
		string nim;
		string nama;
		float ipk;
		cout << "Masukkan Nomor Induk Mahasiswa : ";
		cin >> nim;
		cout << "Masukan Nama Mahasiswa : ";
		cin >> nama;
		cout << "Masukkan IPK Mahasiswa : ";
		cin >> ipk;
		input(nim, nama, ipk);
		Sleep(2000);
		goto menu;
	}
	else if (pilihan == "2") {
		string carnim;
		cout << "Masukkan NIM yang ingin dicari : ";
		cin >> carnim;
		int ix = cariNim(carnim);
		tampilCari(ix);
		cout << "\nTekan Enter untuk kembali . . .";
		_getch();
		goto menu;
	}
	else if (pilihan == "3") {
		tampilUrut();
		cout << "\nTekan Enter untuk kembali . . ." << endl;
		_getch();
		goto menu;

	}
	else if (pilihan == "4") {
		hapus();
		Sleep(2000);
		goto menu;
	}
	else if (pilihan == "5") {
		bersih();
		Sleep(2000);
		goto menu;
	}
	else if (pilihan == "6") {
		cout << "Anda akan keluar beberapa saat lagi . . .";
		Sleep(2000);
		exit;
	}
	else {
		cout << "Maaf pilihan yang anda masukkan tidak ditemukan !";
		Sleep(1000);
		goto menu;
	}
}