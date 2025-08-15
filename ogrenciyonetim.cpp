#include <iostream>
#include<vector>
using namespace std;

struct Ogrenci {
	string isim;
	string soyisim;
	int ogrencino;
	vector<int>ogrencinotu;
};

vector<Ogrenci> ogrenciler;

bool ogrenciNoVarMi(int no) {
	for (auto& o : ogrenciler) {
		if (o.ogrencino == no)
			return true;
	}
	return false;
}

void ogrenciekle(string dil) {
	Ogrenci a;
	if (dil == "TR")
	{
		setlocale(LC_ALL, "Turkish");
		cout << "Lutfen ogrencinin bilgilerini giriniz." << endl;
		cout << "�sim:";
		cin >> a.isim;
		cout << endl << "Soyisim:";
		cin >> a.soyisim;
		
		int no;
		do {
			cout << "��renci No: ";
			cin >> no;
			if (ogrenciNoVarMi(no))
				cout << "Bu ��renci numaras� zaten var! L�tfen ba�ka bir numara girin.\n";
			else
				a.ogrencino = no;
		} while (ogrenciNoVarMi(no));

		int c;
		cout << "Ogrenciye ait kac not ekleyeceksiniz?";
		cin >> c;
		for (int i = 0;i < c;i++) {
			int ogrencinotu;
			cout << "Not" << i + 1 << ":";
			cin >> ogrencinotu;
			a.ogrencinotu.push_back(ogrencinotu);
		}
	}

	else {
		setlocale(LC_ALL, "Turkish");
		cout << "Please enter the student's information." << endl;
		cout << "Name:";
		cin >> a.isim;
		cout << endl << "Surname:";
		cin >> a.soyisim;
	
		int no;
		do {
			cout << "Student ID: ";
			cin >> no;
			if (ogrenciNoVarMi(no))
				cout << "This student ID already exists! Enter a different one.\n";
			else
				a.ogrencino = no;
		} while (ogrenciNoVarMi(no));

		int c;
		cout << "How many grades will you add to the student?";
		cin >> c;
		for (int i = 0;i < c;i++) {
			int ogrencinotu;
			cout << "" << i + 1 << ":";
			cin >> ogrencinotu;
			a.ogrencinotu.push_back(ogrencinotu);
		}

	}

	ogrenciler.push_back(a);
}

void ogrencilistesi(string dil) {
	for (auto& a : ogrenciler) {
		if (dil == "TR") {
			setlocale(LC_ALL, "Turkish");
			cout << "��renci No: " << a.ogrencino
				<< " �sim: " << a.isim
				<< " Soyisim: " << a.soyisim
				<< " Notlar: ";
		}
		else {
			setlocale(LC_ALL, "Turkish");
			cout << "Student ID: " << a.ogrencino
				<< " Name: " << a.isim
				<< " Surname: " << a.soyisim
				<< " Grades: ";
		}
		for (auto& n : a.ogrencinotu) cout << n << " ";
		cout << endl;
	}
}

void ogrencisil(string dil) {
	setlocale(LC_ALL, "Turkish");
	if (ogrenciler.empty()) {
		if (dil == "TR") cout << "Silinecek ��renci yok.\n";
		else cout << "No student to delete.\n";
		return;
	}

	for (int i = 0; i < ogrenciler.size(); i++) {
		if (dil == "TR")
			cout << i + 1 << ". " << ogrenciler[i].isim << " " << ogrenciler[i].soyisim
			<< " (No: " << ogrenciler[i].ogrencino << ")\n";
		else
			cout << i + 1 << ". " << ogrenciler[i].isim << " " << ogrenciler[i].soyisim
			<< " (ID: " << ogrenciler[i].ogrencino << ")\n";
	}

	int secim;
	cout << (dil == "TR" ? "Silmek istedi�iniz ��rencinin numaras�n� girin: "
		: "Enter the number of the student to delete: ");
	cin >> secim;

	if (secim < 1 || secim > ogrenciler.size()) {
		if (dil == "TR") cout << "Ge�ersiz se�im.\n";
		else cout << "Invalid choice.\n";
		return;
	}

	ogrenciler.erase(ogrenciler.begin() + secim - 1);

	if (dil == "TR") cout << "��renci silindi.\n";
	else cout << "Student deleted.\n";
}

void ogrenciGuncelle(string dil) {
	if (ogrenciler.empty()) {
		if (dil == "TR") cout << "G�ncellenecek ��renci yok.\n";
		else cout << "No student to update.\n";
		return;
	}

	int no;
	if (dil == "TR") cout << "G�ncellemek istedi�iniz ��rencinin numaras�n� girin: ";
	else cout << "Enter the student ID to update: ";
	cin >> no;

	Ogrenci* secilen = nullptr;
	for (auto& o : ogrenciler) {
		if (o.ogrencino == no) {
			secilen = &o;
			break;
		}
	}

	if (!secilen) {
		if (dil == "TR") cout << "��renci bulunamad�.\n";
		else cout << "Student not found.\n";
		return;
	}

	if (dil == "TR") cout << "Yeni isim (eski: " << secilen->isim << "): ";
	else cout << "New name (old: " << secilen->isim << "): ";
	cin >> secilen->isim;

	if (dil == "TR") cout << "Yeni soyisim (eski: " << secilen->soyisim << "): ";
	else cout << "New surname (old: " << secilen->soyisim << "): ";
	cin >> secilen->soyisim;

	int secim;
	if (dil == "TR") cout << "Notlar� de�i�tirmek ister misiniz? 1=Evet 0=Hay�r: ";
	else cout << "Do you want to modify grades? 1=Yes 0=No: ";
	cin >> secim;

	if (secim == 1) {
		secilen->ogrencinotu.clear();
		int c;
		if (dil == "TR") cout << "Ka� not eklemek istiyorsunuz? ";
		else cout << "How many grades do you want to add? ";
		cin >> c;

		for (int i = 0; i < c; i++) {
			int notDeger;
			if (dil == "TR") cout << "Not " << i + 1 << ": ";
			else cout << "Grade " << i + 1 << ": ";
			cin >> notDeger;
			secilen->ogrencinotu.push_back(notDeger);
		}
	}

	if (dil == "TR") cout << "��renci bilgileri g�ncellendi.\n";
	else cout << "Student information updated.\n";
}

int main() {

	int secim;
	string dil = "TR";

	while (true) {
		if (dil == "TR") {
			setlocale(LC_ALL, "Turkish");
			cout << "\n1. ��renci Ekle\n2. ��renci Listesi\n3. ��renci bilgisi sil\n4. ��renci G�ncelle\n5. ��k��\n";
			cout << "L�tfen yapmak istedi�iniz i�lemin ba��ndaki numaray� tu�lay�n�z.\nFor English please press 9\n";
			cin >> secim;

			if (secim == 1) ogrenciekle("TR");
			else if (secim == 2) ogrencilistesi("TR");
			else if (secim == 3) ogrencisil("TR");
			else if (secim == 4) ogrenciGuncelle("TR"); // G�ncelleme se�ene�i
			else if (secim == 5) break;
			else if (secim == 9) dil = "EN";
			else cout << "Yanl�� giri�. Tekrar deneyin.\n";

		}
		else {
			setlocale(LC_ALL, "Turkish");
			cout << "\n1. Add Student\n2. Check Student List\n3. Remove Student\n4. Update Student\n5. Exit\n";
			cout << "Please make your choice.\nT�rk�e i�in 9'u tu�lay�n�z.\n";
			cin >> secim;

			if (secim == 1) ogrenciekle("EN");
			else if (secim == 2) ogrencilistesi("EN");
			else if (secim == 3) ogrencisil("EN");
			else if (secim == 4) ogrenciGuncelle("EN"); // Update se�ene�i
			else if (secim == 5) break;
			else if (secim == 9) dil = "TR";
			else cout << "Invalid input. Try again.\n";
		}
	}

	return 0;
}