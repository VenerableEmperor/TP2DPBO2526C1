<?php
session_start();

// Based on the class structure from tiket.cpp[cite: 2]
class Tiket {
    protected $id_tiket;
    protected $harga_awal;
    protected $validitas;

    public function __construct($id, $harga, $validitas) {
        $this->id_tiket = $id;
        $this->harga_awal = $harga;
        $this->validitas = $validitas;
    }

    public function getIdTiket() { return $this->id_tiket; }
    public function getHarga() { return $this->harga_awal; }
    public function getValiditas() { return $this->validitas; }
}

class TiketStandar extends Tiket {
    protected $judul_film;
    protected $ruangtheater;
    protected $nomor_duduk;

    public function __construct($id, $harga, $validitas, $film, $ruang, $kursi) {
        parent::__construct($id, $harga, $validitas);
        $this->judul_film = $film;
        $this->ruangtheater = $ruang;
        $this->nomor_duduk = $kursi;
    }

    public function getFilm() { return $this->judul_film; }
    public function getRuang() { return $this->ruangtheater; }
    public function getDuduk() { return $this->nomor_duduk; }
}

class TiketPremium extends TiketStandar {
    protected $harga_tambahan;
    protected $layarIMAX;
    protected $nomorvoucher;

    public function __construct($id, $harga, $validitas, $film, $ruang, $kursi, $tambah, $imax, $voucher) {
        parent::__construct($id, $harga, $validitas, $film, $ruang, $kursi);
        $this->harga_tambahan = $tambah;
        $this->layarIMAX = $imax;
        $this->nomorvoucher = $voucher;
    }

    public function getHargaTambah() { return $this->harga_tambahan; }
    public function getLayarIMAX() { return $this->layarIMAX; }
    public function getVoucher() { return $this->nomorvoucher; }
    public function getTotalHarga() { return $this->harga_awal + $this->harga_tambahan; }
}

// Initializing default data based on main.cpp[cite: 1]
if (!isset($_SESSION['dataStandar']) || isset($_POST['reset'])) {
    $_SESSION['dataStandar'] = [
        new TiketStandar("a1", 25000, "valid", "Rocky", "Cinema01", 1),
        new TiketStandar("a2", 25000, "valid", "Prisoners", "Cinema02", 1),
        new TiketStandar("a3", 30000, "valid", "Dune", "Cinema03", 1)
    ];
    $_SESSION['dataPremium'] = [
        new TiketPremium("b1", 30000, "valid", "Interstellar", "Cinema04", 10, 20000, "IMAX", 10250),
        new TiketPremium("b2", 30000, "invalid", "Oppenheimer", "Cinema05", 11, 25000, "nonIMAX", 11256)
    ];
}

// Processing the INPUT command logic from main.cpp[cite: 1]
$message = "";
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['submit'])) {
    $jenis = $_POST['jenis_tiket'];
    $id = $_POST['id_tiket'];
    $harga = (int)$_POST['harga_awal'];
    $valid = $_POST['validitas'];
    $film = $_POST['judul_film'];
    $ruang = $_POST['ruangtheater'];
    $kursi = (int)$_POST['nomor_duduk'];

    if ($jenis === 'PREMIUM') {
        $tambah = (int)$_POST['harga_tambahan'];
        $imax = $_POST['layarIMAX'];
        $voucher = (int)$_POST['nomorvoucher'];
        $_SESSION['dataPremium'][] = new TiketPremium($id, $harga, $valid, $film, $ruang, $kursi, $tambah, $imax, $voucher);
        $message = "Sukses! Tiket Premium berhasil ditambahkan.";
    } else {
        $_SESSION['dataStandar'][] = new TiketStandar($id, $harga, $valid, $film, $ruang, $kursi);
        $message = "Sukses! Tiket Standar berhasil ditambahkan.";
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Sistem Tiket Bioskop</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 20px; background-color: #f4f4f9; }
        .container { max-width: 1000px; margin: auto; background: white; padding: 20px; border-radius: 8px; box-shadow: 0 0 10px rgba(0,0,0,0.1); }
        h1, h2 { text-align: center; color: #333; }
        table { width: 100%; border-collapse: collapse; margin-bottom: 20px; }
        th, td { border: 1px solid #ddd; padding: 8px; text-align: left; }
        th { background-color: #007bff; color: white; }
        .form-group { margin-bottom: 15px; }
        label { display: block; margin-bottom: 5px; font-weight: bold; }
        input[type="text"], input[type="number"], select { width: 100%; padding: 8px; box-sizing: border-box; }
        button { padding: 10px 15px; background: #28a745; color: white; border: none; cursor: pointer; border-radius: 4px;}
        button:hover { background: #218838; }
        .msg { padding: 10px; background: #d4edda; color: #155724; border-radius: 4px; margin-bottom: 20px; }
        .premium-fields { display: none; background: #e9ecef; padding: 10px; border-radius: 4px;}
    </style>
    <script>
        function toggleFields() {
            var type = document.getElementById("jenis_tiket").value;
            document.getElementById("premium-fields").style.display = (type === "PREMIUM") ? "block" : "none";
        }
    </script>
</head>
<body>
<div class="container">
    <h1>SELAMAT DATANG DI BIOSKOP!</h1>
    
    <?php if ($message): ?>
        <div class="msg"><?php echo $message; ?></div>
    <?php endif; ?>

    <h2>Form Input Tiket</h2>
    <form method="POST">
        <div class="form-group">
            <label>Jenis Tiket:</label>
            <select name="jenis_tiket" id="jenis_tiket" onchange="toggleFields()">
                <option value="STANDAR">Standar</option>
                <option value="PREMIUM">Premium</option>
            </select>
        </div>
        <div class="form-group"><label>ID Tiket:</label><input type="text" name="id_tiket" required></div>
        <div class="form-group"><label>Judul Film:</label><input type="text" name="judul_film" required></div>
        <div class="form-group"><label>Ruang Teater:</label><input type="text" name="ruangtheater" required></div>
        <div class="form-group"><label>Nomor Kursi:</label><input type="number" name="nomor_duduk" required></div>
        <div class="form-group"><label>Harga Awal (Rp):</label><input type="number" name="harga_awal" required></div>
        <div class="form-group"><label>Validitas:</label>
            <select name="validitas">
                <option value="valid">Valid</option>
                <option value="invalid">Invalid</option>
            </select>
        </div>

        <div id="premium-fields" class="premium-fields">
            <h4>Khusus Premium</h4>
            <div class="form-group"><label>Harga Tambahan (Rp):</label><input type="number" name="harga_tambahan" value="0"></div>
            <div class="form-group"><label>Layar (IMAX/nonIMAX):</label><input type="text" name="layarIMAX" value="nonIMAX"></div>
            <div class="form-group"><label>Nomor Voucher:</label><input type="number" name="nomorvoucher" value="0"></div>
        </div>

        <button type="submit" name="submit">Simpan Tiket</button>
    </form>

    <hr style="margin: 30px 0;">

    <h2>Data Tiket Standar</h2>
    <table>
        <tr><th>No</th><th>ID</th><th>Film</th><th>Teater</th><th>Kursi</th><th>Harga</th><th>Validitas</th></tr>
        <?php foreach ($_SESSION['dataStandar'] as $i => $tiket): ?>
        <tr>
            <td><?php echo $i + 1; ?></td>
            <td><?php echo $tiket->getIdTiket(); ?></td>
            <td><?php echo $tiket->getFilm(); ?></td>
            <td><?php echo $tiket->getRuang(); ?></td>
            <td><?php echo $tiket->getDuduk(); ?></td>
            <td>Rp <?php echo number_format($tiket->getHarga(), 0, ',', '.'); ?></td>
            <td><?php echo $tiket->getValiditas(); ?></td>
        </tr>
        <?php endforeach; ?>
    </table>

    <h2>Data Tiket Premium</h2>
    <table>
        <tr><th>No</th><th>ID</th><th>Film</th><th>Teater</th><th>Kursi</th><th>Total Harga</th><th>Layar</th><th>Voucher</th><th>Validitas</th></tr>
        <?php foreach ($_SESSION['dataPremium'] as $i => $tiket): ?>
        <tr>
            <td><?php echo $i + 1; ?></td>
            <td><?php echo $tiket->getIdTiket(); ?></td>
            <td><?php echo $tiket->getFilm(); ?></td>
            <td><?php echo $tiket->getRuang(); ?></td>
            <td><?php echo $tiket->getDuduk(); ?></td>
            <td>Rp <?php echo number_format($tiket->getTotalHarga(), 0, ',', '.'); ?></td>
            <td><?php echo $tiket->getLayarIMAX(); ?></td>
            <td><?php echo $tiket->getVoucher(); ?></td>
            <td><?php echo $tiket->getValiditas(); ?></td>
        </tr>
        <?php endforeach; ?>
    </table>
    
    <form method="POST">
        <button type="submit" name="reset" style="background:#dc3545;">Reset Data ke Default</button>
    </form>
</div>
</body>
</html>