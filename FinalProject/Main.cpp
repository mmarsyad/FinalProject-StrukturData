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

bool kosong() {
	if (tumpuk.atas = -1) {
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
	if (kosong) {
		tumpuk.atas++;
		int i = tumpuk.atas;
		tumpuk.data[tumpuk.atas].nim = nim;
		tumpuk.data[tumpuk.atas].nama = nama;
		tumpuk.data[tumpuk.atas].ipk = ipk;
		cout << "Data dengan NIM" << tumpuk.data[tumpuk.atas].nim << "Masuk ke Stack ";
	}
	else if (!penuh) {
		tumpuk.atas++;
		int i = tumpuk.atas;
		tumpuk.data[tumpuk.atas].nim = nim;
		tumpuk.data[tumpuk.atas].nama = nama;
		tumpuk.data[tumpuk.atas].ipk = ipk;
		cout << "Data dengan NIM" << tumpuk.data[tumpuk.atas].nim << "Masuk ke Stack";
	}
	else {
		cout << "Tumpukkan penuh !";
	}
}

void hapus() {
	if (!kosong) {
		cout << "Data teratas sudah terambil";
		tumpuk.atas--;
	}
	else {
		cout << "Data kosong";
	}
}

void tampil() {
	if (kosong) {
		for (int i = tumpuk.atas;i >= 0;i--) {
			cout << "";
		}
	}
}

int main() {
	menu:
	string pilihan;
	cout << "==========================================================================" << endl;
	cout << "=                   Sistem Penginputan Nilai Mahasiswa                   =" << endl;
	cout << "==========================================================================" << endl;
	cout << "1. Input Nilai Mahasiswa\n2. Cari Mahasiswa\n3. List Mahasiswa\n4. Keluar" << endl;
	cout << "Masukkan pilihan anda : ";
	cin >> pilihan;

	if (pilihan == "1") {

	}
	else if (pilihan == "2") {

	}
	else if (pilihan == "3") {

	}
	else if (pilihan == "4") {
		cout << "Anda akan keluar beberapa saat lagi . . .";
		Sleep(2000);
		exit;
	}
	else {
		cout << "Maaf pilihan yang anda masukkan tidak ditemukan !";
		Sleep(1000);
		system("cls");
		goto menu;
	}
}