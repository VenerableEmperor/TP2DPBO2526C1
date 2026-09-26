#include <bits/stdc++.h>
#include "tiket.cpp"

using namespace std;

void title(){
	cout << "==============================================\n";
	cout << "||        SELAMAT DATANG DI BIOSKOP!        ||\n";
	cout << "==============================================\n";
	cout << "\n";
}


void printHelp() {
	cout << "==============================================\n";
	cout << "||  Program ini ditujukan sebagai simulasi  ||\n";
	cout << "||  dalam mengatur dan mengelola tiket      ||\n";
	cout << "||             pada sebuah bioskop.         ||\n";
	cout << "||                                          ||\n";
	cout << "||                                          ||\n";
	cout << "||              COMMAND LIST                ||\n";
	cout << "||                 +INPUT                   ||\n";
	cout << "||                 +SHOW                    ||\n";
	cout << "||                 +HELP                    ||\n";
	cout << "||                 +EXIT                    ||\n";
	cout << "||                                          ||\n";
	cout << "||+ FORMAT INPUT :                          ||\n";
	cout << "||INPUT id_tiket jenis_tiket harga validitas||\n";
	cout << "||judulfilm ruangtheater nomor_duduk        ||\n";
	cout << "||[JIKA PREMIUM] h_tambahan iMAX no_voucher ||\n";
	cout << "||FUNGSI : Menginput tiket kedalam          ||\n";
	cout << "||         data bioskop                     ||\n";
	cout << "||                                          ||\n";
	cout << "||+ FORMAT SHOW :                           ||\n";
	cout << "||SHOW                                      ||\n";
	cout << "||FUNGSI : Menampilkan seluruh data dalam   ||\n";
	cout << "||         bioskop                          ||\n";
	cout << "||                                          ||\n";
	cout << "||+ FORMAT HELP :                           ||\n";
	cout << "||HELP                                      ||\n";
	cout << "||FUNGSI : Menampilkan kembali menu panduan ||\n";
	cout << "||         ini                              ||\n";
	cout << "==============================================\n";
}

void clearcin(){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

void dataawal(vector<tiketstandar> &dataStandar, vector<tiketpremium> &dataPremium){
	tiketstandar tiketBaru1("a1", 25000, "valid", "Rocky", "Cinema01", 1);
    dataStandar.push_back(tiketBaru1);
    tiketstandar tiketBaru2("a2", 25000, "valid", "Prisoners", "Cinema02", 1);
    dataStandar.push_back(tiketBaru2);
    tiketstandar tiketBaru3("a3", 30000, "valid", "Dune", "Cinema03", 1);
    dataStandar.push_back(tiketBaru3);
    tiketpremium tiketBaru4("b1", 30000, "valid", "Interstellar", "Cinema04", 10, 20000, "IMAX", 10250);
    dataPremium.push_back(tiketBaru4);
    tiketpremium tiketBaru5("b2", 30000, "invalid", "Oppenheimer", "Cinema05", 11, 25000, "nonIMAX", 11256);
    dataPremium.push_back(tiketBaru5);
}

int main() {
    vector<tiketstandar> dataStandar;
    vector<tiketpremium> dataPremium;
    string command;

    dataawal(dataStandar, dataPremium);
    title();
    printHelp();

    while (true) {
        cout << "\n> Masukkan Command (INPUT/SHOW/HELP/EXIT): ";
        cin >> command;

        if (command == "HELP") {
            printHelp();
        } 
        else if (command == "EXIT") {
            cout << "Keluar dari program...\n";
            break;
        }
        else if (command == "INPUT") {
            string id_tiket, jenis_tiket, judul_film, ruangtheater, validitas;
            int harga_awal, nomor_duduk;

            cin >> id_tiket >> jenis_tiket >> harga_awal >> validitas >> judul_film >> ruangtheater >> nomor_duduk;

            if (jenis_tiket == "PREMIUM" || jenis_tiket == "premium") {
                int harga_tambahan, nomorvoucher;
                string layarIMAX;
                
                cin >> harga_tambahan >> layarIMAX >> nomorvoucher;

                tiketpremium tiketBaru(id_tiket, harga_awal, validitas, judul_film, ruangtheater, nomor_duduk, harga_tambahan, layarIMAX, nomorvoucher);
                dataPremium.push_back(tiketBaru);
                cout << ">> Sukses! Tiket Premium berhasil ditambahkan.\n";
            } 
            else if (jenis_tiket == "STANDAR" || jenis_tiket == "standar") {
                tiketstandar tiketBaru(id_tiket, harga_awal, validitas, judul_film, ruangtheater, nomor_duduk);
                dataStandar.push_back(tiketBaru);
                cout << ">> Sukses! Tiket Standar berhasil ditambahkan.\n";
            }
        }
        else if (command == "SHOW") {
            cout << "\n========================================= DATA TIKET BIOSKOP =========================================\n";
            
            cout << "\n--- TIKET STANDAR ---\n";
            if (dataStandar.empty()) {
                cout << "(Kosong)\n";
            } else {
                // Table Header Standar
                cout << left << setw(5) << "No" 
                     << setw(10) << "ID" 
                     << setw(20) << "Film" 
                     << setw(15) << "Teater" 
                     << setw(10) << "Kursi" 
                     << setw(15) << "Harga" 
                     << setw(15) << "Validitas" << "\n";
                cout << setfill('-') << setw(90) << "-" << setfill(' ') << "\n";
                
                for (size_t i = 0; i < dataStandar.size(); i++) {
                    cout << left << setw(5) << i+1
                         << setw(10) << dataStandar[i].getidtiket() 
                         << setw(20) << dataStandar[i].getfilm()
                         << setw(15) << dataStandar[i].getruang()
                         << setw(10) << dataStandar[i].getduduk()
                         << "Rp " << setw(12) << dataStandar[i].getharga()
                         << setw(15) << dataStandar[i].getvalid() << "\n";
                }
            }

            cout << "\n--- TIKET PREMIUM ---\n";
            if (dataPremium.empty()) {
                cout << "(Kosong)\n";
            } else {
                // Table Header Premium
                cout << left << setw(5) << "No" 
                     << setw(10) << "ID" 
                     << setw(20) << "Film" 
                     << setw(15) << "Teater" 
                     << setw(10) << "Kursi" 
                     << setw(15) << "Total Harga" 
                     << setw(15) << "IMAX" 
                     << setw(15) << "Voucher" 
                     << setw(10) << "Validitas" << "\n";
                cout << setfill('-') << setw(115) << "-" << setfill(' ') << "\n";
                
                for (size_t i = 0; i < dataPremium.size(); i++) {
                    int total_harga = dataPremium[i].getharga() + dataPremium[i].gethargatambah();
                    
                    cout << left << setw(5) << i+1
                         << setw(10) << dataPremium[i].getidtiket() 
                         << setw(20) << dataPremium[i].getfilm()
                         << setw(15) << dataPremium[i].getruang()
                         << setw(10) << dataPremium[i].getduduk()
                         << "Rp " << setw(12) << total_harga
                         << setw(15) << dataPremium[i].getlayarIMAX()
                         << setw(15) << dataPremium[i].getvoucher()
                         << setw(10) << dataPremium[i].getvalid() << "\n";
                }
            }
            cout << "======================================================================================================\n";
        }
        else {
            cout << ">> Command tidak dikenali. Ketik HELP untuk bantuan.\n";
        }
        clearcin();
    }
    
    return 0;
}