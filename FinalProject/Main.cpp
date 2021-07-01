#include <iostream>
#include <string.h>
#include <conio.h>
#include <Windows.h> // untuk menggunakan fungsi Sleep()
#define max 10

using namespace std;

struct mahasiswa {
	int nim;
	string nama;
	float ipk;
};

struct Tumpukan {
	int atas;
	mahasiswa data[max];
}tumpuk;

void awal() {
	tumpuk.atas = -1;
}

bool kosong() {
	if (tumpuk.atas == -1) {
		return true;
	}
	else {
		return false;
	}
}

bool penuh() {
	if (tumpuk.atas == max - 1) {
		return true;
	}
	else {
		return false;
	}
}

void input(int nim, string nama, float ipk) {
	if (kosong()) {
		tumpuk.atas++;
		tumpuk.data[tumpuk.atas].nim = nim;
		tumpuk.data[tumpuk.atas].nama = nama;
		tumpuk.data[tumpuk.atas].ipk = ipk;
		cout << "Data dengan NIM " << tumpuk.data[tumpuk.atas].nim << " Masuk ke Stack ";
	}
	else if (!penuh()) {
		tumpuk.atas++;
		tumpuk.data[tumpuk.atas].nim = nim;
		tumpuk.data[tumpuk.atas].nama = nama;
		tumpuk.data[tumpuk.atas].ipk = ipk;
		cout << "Data dengan NIM " << tumpuk.data[tumpuk.atas].nim << " Masuk ke Stack";
	}
	else {
		cout << "Tumpukkan penuh !";
	}
}

void hapus() {
	if (!kosong()) {
		tumpuk.atas--;
		cout << "Data inputan terakhir sudah di hapus";
	}
	else {
		cout << "Data kosong, Silahkan tambahkan data terlebih dahulu.";
	}
}

void tampil() {
	if (!kosong()) {
		cout << "=============================" << endl;
		cout << "= NO.\tNIM\tNAMA\tIPK =" << endl;
		cout << "=============================" << endl;
		int j = 1;
		for (int i = tumpuk.atas;i >= 0;i--) {
			cout << j << ". \t" << tumpuk.data[i].nim;
			cout << "\t" << tumpuk.data[i].nama;
			cout << "\t" << tumpuk.data[i].ipk;
			cout << endl;
			j++;
		}
	}
	else {
		cout << "Data Mahasiswa masih kosong";
	}
}

void bersih() {
	tumpuk.atas = -1;
	cout << "Berhasil. Data sudah kosong !";
}

int cariNim(int nim) {
	int posisi = -1;

	for (int i = tumpuk.atas;i >= 0; i--) {
		if (tumpuk.data[i].nim == nim) {
			return posisi = i;
		}
		else if (posisi != -1) {
			return posisi;
		}
	}

	/*while (i >= 0 && tumpuk.data[i].nim != nim) {
		i--;
	}*/
}

void tampilCari(int i) {
	if ( i == -1) {
		cout << "Maaf data yang anda cari tidak ditemukan";
	}
	else {		
		cout << "NIM\t: " << tumpuk.data[i].nim << endl;
		cout << "Nama\t: " << tumpuk.data[i].nama << endl;
		cout << "IPK\t: " << tumpuk.data[i].ipk << endl;
		cout << "Data yang anda cari ditemukan !";
	}
}

void cariNama(string nama) {

}

int main() {
	awal();
	menu:
	system("cls");
	string pilihan;
	cout << "==========================================================================" << endl;
	cout << "=                   Sistem Penginputan Nilai Mahasiswa                   =" << endl;
	cout << "==========================================================================" << endl;
	cout << "1. Input Nilai Mahasiswa\n2. Cari Mahasiswa berdasarkan NIM\n3. List Mahasiswa berdasarkan IPK tertinggi\n4. Hapus data terakhir\n5. Bersihkan data Mahasiswa\n6. Keluar" << endl;
	cout << "Masukkan pilihan anda : ";
	cin >> pilihan;

	if (pilihan == "1") {
		system("cls");
		int nim;
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
		int carnim;
		cout << "Masukkan NIM yang ingin dicari : ";
		cin >> carnim;
		int ix = cariNim(carnim);
		tampilCari(ix);
		cout << "\nTekan Enter untuk kembali . . .";
		_getch();
		goto menu;
	}
	else if (pilihan == "3") {
		tampil();
		cout << "\nTekan Enter untuk kembali . . .";
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