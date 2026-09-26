class Tiket:
    # constructor II (ada parameter) / constructor I fallback
    def __init__(self, id_tiket="-1", harga_awal=0, validitas=""):
        self._id_tiket = id_tiket
        self._harga_awal = harga_awal
        self._validitas = validitas

    # getter
    def getidtiket(self):
        return self._id_tiket
        
    def getharga(self):
        return self._harga_awal
        
    def getvalid(self):
        return self._validitas

    # setter
    def setidtiket(self, id_tiket):
        self._id_tiket = id_tiket
        
    def setharga(self, harga):
        self._harga_awal = harga
        
    def setvaliditas(self, kondisi):
        self._validitas = kondisi


class TiketStandar(Tiket):
    def __init__(self, id_tiket="-1", harga_awal=0, validitas="", judul_film="", ruangtheater="", nomor_duduk=0):
        super().__init__(id_tiket, harga_awal, validitas)
        self._judul_film = judul_film
        self._ruangtheater = ruangtheater
        self._nomor_duduk = nomor_duduk

    # getter
    def getfilm(self):
        return self._judul_film
        
    def getruang(self):
        return self._ruangtheater
        
    def getduduk(self):
        return self._nomor_duduk

    # setter
    def setfilm(self, film):
        self._judul_film = film
        
    def setruang(self, nama):
        self._ruangtheater = nama
        
    def setduduk(self, nomor):
        self._nomor_duduk = nomor


class TiketPremium(TiketStandar):
    def __init__(self, id_tiket="-1", harga_awal=0, validitas="", judul_film="", ruangtheater="", nomor_duduk=0, harga_tambahan=0, layarIMAX="", nomorvoucher=0):
        super().__init__(id_tiket, harga_awal, validitas, judul_film, ruangtheater, nomor_duduk)
        self._harga_tambahan = harga_tambahan
        self._layarIMAX = layarIMAX
        self._nomorvoucher = nomorvoucher

    # getter
    def gethargatambah(self):
        return self._harga_tambahan
        
    def getlayarIMAX(self):
        return self._layarIMAX
        
    def getvoucher(self):
        return self._nomorvoucher

    # setter
    def settambah(self, hargatambah):
        self._harga_tambahan = hargatambah
        
    def setiMAX(self, kondisi):
        self._layarIMAX = kondisi
        
    def setvoucher(self, nomor):
        self._nomorvoucher = nomor