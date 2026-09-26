#include <string>

using namespace std;

class tiket
{
	private: 
		string id_tiket;
		int harga_awal;
		string validitas;
	public: 
		//constructor I 
		tiket(){
			id_tiket = "-1";
		}

		//constructor II (ada paremeter)
		tiket(string id_tiket, int harga_awal, string validitas){
			this->id_tiket = id_tiket;
			this->harga_awal = harga_awal;
			this->validitas = validitas;
		}

		//destructor
		~tiket(){}

		//getter
		string getidtiket(){
			return id_tiket;
		}
		int getharga(){
			return harga_awal;
		}
		string getvalid(){
			return validitas;
		}

		//setter
		void setidtiket(string id_tiket){
			this->id_tiket = id_tiket;
		}
		void setharga(int harga){
			harga_awal = harga;
		}
		void setvaliditas(string kondisi){
			validitas = kondisi;
		}
};

class tiketstandar : public tiket
{
	private: 
		string judul_film;
		string ruangtheater;
		int nomor_duduk;

	public: 
		//constructor I 
		tiketstandar(){
		}

		//constructor II (ada paremeter)
		tiketstandar(string id_tiket, int harga_awal, string validitas, string judul_film, string ruangtheater, 
		int nomor_duduk) : tiket(id_tiket, harga_awal, validitas){
			this->judul_film = judul_film;
			this->ruangtheater = ruangtheater;
			this->nomor_duduk = nomor_duduk;
		}

		//destructor
		~tiketstandar(){}

		//getter
		string getfilm(){
			return judul_film;
		}
		string getruang(){
			return ruangtheater;
		}
		int getduduk(){
			return nomor_duduk;
		}

		//setter
		void setfilm(string film){
			judul_film = film;
		}
		void setruang(string nama){
			ruangtheater = nama;
		}
		void setduduk(int nomor){
			nomor_duduk = nomor;
		}
};

class tiketpremium : public tiketstandar
{
	private: 
		int harga_tambahan;
		string layarIMAX;
		int nomorvoucher;
	public: 
		//constructor I 
		tiketpremium(){
		}

		//constructor II (ada paremeter)
		tiketpremium(string id_tiket, int harga_awal, string validitas, string judul_film, string ruangtheater, 
		int nomor_duduk, int harga_tambahan, string layarIMAX, int nomorvoucher) : 
		tiketstandar(id_tiket, harga_awal, validitas, judul_film, ruangtheater, nomor_duduk){
			this->harga_tambahan = harga_tambahan;
			this->layarIMAX = layarIMAX;
			this->nomorvoucher = nomorvoucher;
		}

		//destructor
		~tiketpremium(){}

		//getter
		int gethargatambah(){
			return harga_tambahan;
		}
		string getlayarIMAX(){
			return layarIMAX;
		}
		int getvoucher(){
			return nomorvoucher;
		}

		//setter
		void settambah(int hargatambah){
			harga_tambahan = hargatambah;
		}
		void setiMAX(string kondisi){
			layarIMAX = kondisi;
		}
		void setvoucher(int nomor){
			nomorvoucher = nomor;
		}
};