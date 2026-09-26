
class Tiket {
    private String id_tiket;
    private int harga_awal;
    private String validitas;

    // constructor I 
    public Tiket() {
        this.id_tiket = "-1";
    }

    // constructor II
    public Tiket(String id_tiket, int harga_awal, String validitas) {
        this.id_tiket = id_tiket;
        this.harga_awal = harga_awal;
        this.validitas = validitas;
    }

    // getter
    public String getIdTiket() {
        return id_tiket;
    }
    public int getHarga() {
        return harga_awal;
    }
    public String getValid() {
        return validitas;
    }

    // setter
    public void setIdTiket(String id_tiket) {
        this.id_tiket = id_tiket;
    }
    public void setHarga(int harga) {
        this.harga_awal = harga;
    }
    public void setValiditas(String kondisi) {
        this.validitas = kondisi;
    }
}

class TiketStandar extends Tiket {
    private String judul_film;
    private String ruangtheater;
    private int nomor_duduk;

    // constructor I 
    public TiketStandar() {
    }

    // constructor II
    public TiketStandar(String id_tiket, int harga_awal, String validitas, String judul_film, String ruangtheater, int nomor_duduk) {
        super(id_tiket, harga_awal, validitas);
        this.judul_film = judul_film;
        this.ruangtheater = ruangtheater;
        this.nomor_duduk = nomor_duduk;
    }

    // getter
    public String getFilm() {
        return judul_film;
    }
    public String getRuang() {
        return ruangtheater;
    }
    public int getDuduk() {
        return nomor_duduk;
    }

    // setter
    public void setFilm(String film) {
        this.judul_film = film;
    }
    public void setRuang(String nama) {
        this.ruangtheater = nama;
    }
    public void setDuduk(int nomor) {
        this.nomor_duduk = nomor;
    }
}

class TiketPremium extends TiketStandar {
    private int harga_tambahan;
    private String layarIMAX;
    private int nomorvoucher;

    // constructor I 
    public TiketPremium() {
    }

    // constructor II
    public TiketPremium(String id_tiket, int harga_awal, String validitas, String judul_film, String ruangtheater, int nomor_duduk, int harga_tambahan, String layarIMAX, int nomorvoucher) {
        super(id_tiket, harga_awal, validitas, judul_film, ruangtheater, nomor_duduk);
        this.harga_tambahan = harga_tambahan;
        this.layarIMAX = layarIMAX;
        this.nomorvoucher = nomorvoucher;
    }

    // getter
    public int getHargaTambah() {
        return harga_tambahan;
    }
    public String getLayarIMAX() {
        return layarIMAX;
    }
    public int getVoucher() {
        return nomorvoucher;
    }

    // setter
    public void setTambah(int hargatambah) {
        this.harga_tambahan = hargatambah;
    }
    public void setIMAX(String kondisi) {
        this.layarIMAX = kondisi;
    }
    public void setVoucher(int nomor) {
        this.nomorvoucher = nomor;
    }
}