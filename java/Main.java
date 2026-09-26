import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void title() {
        System.out.println("==============================================");
        System.out.println("||        SELAMAT DATANG DI BIOSKOP!        ||");
        System.out.println("==============================================");
        System.out.println();
    }

    public static void printHelp() {
        System.out.println("==============================================");
        System.out.println("||  Program ini ditujukan sebagai simulasi  ||");
        System.out.println("||  dalam mengatur dan mengelola tiket      ||");
        System.out.println("||             pada sebuah bioskop.         ||");
        System.out.println("||                                          ||");
        System.out.println("||                                          ||");
        System.out.println("||              COMMAND LIST                ||");
        System.out.println("||                 +INPUT                   ||");
        System.out.println("||                 +SHOW                    ||");
        System.out.println("||                 +HELP                    ||");
        System.out.println("||                 +EXIT                    ||");
        System.out.println("||                                          ||");
        System.out.println("||+ FORMAT INPUT :                          ||");
        System.out.println("||INPUT id_tiket jenis_tiket harga validitas||");
        System.out.println("||judulfilm ruangtheater nomor_duduk        ||");
        System.out.println("||[JIKA PREMIUM] h_tambahan iMAX no_voucher ||");
        System.out.println("||FUNGSI : Menginput tiket kedalam          ||");
        System.out.println("||         data bioskop                     ||");
        System.out.println("||                                          ||");
        System.out.println("||+ FORMAT SHOW :                           ||");
        System.out.println("||SHOW                                      ||");
        System.out.println("||FUNGSI : Menampilkan seluruh data dalam   ||");
        System.out.println("||         bioskop                          ||");
        System.out.println("||                                          ||");
        System.out.println("||+ FORMAT HELP :                           ||");
        System.out.println("||HELP                                      ||");
        System.out.println("||FUNGSI : Menampilkan kembali menu panduan ||");
        System.out.println("||         ini                              ||");
        System.out.println("==============================================");
    }

    public static void dataAwal(ArrayList<TiketStandar> dataStandar, ArrayList<TiketPremium> dataPremium) {
        dataStandar.add(new TiketStandar("a1", 25000, "valid", "Rocky", "Cinema01", 1));
        dataStandar.add(new TiketStandar("a2", 25000, "valid", "Prisoners", "Cinema02", 1));
        dataStandar.add(new TiketStandar("a3", 30000, "valid", "Dune", "Cinema03", 1));
        
        dataPremium.add(new TiketPremium("b1", 30000, "valid", "Interstellar", "Cinema04", 10, 20000, "IMAX", 10250));
        dataPremium.add(new TiketPremium("b2", 30000, "invalid", "Oppenheimer", "Cinema05", 11, 25000, "nonIMAX", 11256));
    }

    public static void main(String[] args) {
        ArrayList<TiketStandar> dataStandar = new ArrayList<>();
        ArrayList<TiketPremium> dataPremium = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        String command;

        dataAwal(dataStandar, dataPremium);
        title();
        printHelp();

        while (true) {
            System.out.print("\n> Masukkan Command (INPUT/SHOW/HELP/EXIT): ");
            command = scanner.next();

            if (command.equals("HELP")) {
                printHelp();
            } 
            else if (command.equals("EXIT")) {
                System.out.println("Keluar dari program...");
                break;
            }
            else if (command.equals("INPUT")) {
                String id_tiket = scanner.next();
                String jenis_tiket = scanner.next();
                int harga_awal = scanner.nextInt();
                String validitas = scanner.next();
                String judul_film = scanner.next();
                String ruangtheater = scanner.next();
                int nomor_duduk = scanner.nextInt();

                if (jenis_tiket.equalsIgnoreCase("PREMIUM")) {
                    int harga_tambahan = scanner.nextInt();
                    String layarIMAX = scanner.next();
                    int nomorvoucher = scanner.nextInt();

                    TiketPremium tiketBaru = new TiketPremium(id_tiket, harga_awal, validitas, judul_film, ruangtheater, nomor_duduk, harga_tambahan, layarIMAX, nomorvoucher);
                    dataPremium.add(tiketBaru);
                    System.out.println(">> Sukses! Tiket Premium berhasil ditambahkan.");
                } 
                else if (jenis_tiket.equalsIgnoreCase("STANDAR")) {
                    TiketStandar tiketBaru = new TiketStandar(id_tiket, harga_awal, validitas, judul_film, ruangtheater, nomor_duduk);
                    dataStandar.add(tiketBaru);
                    System.out.println(">> Sukses! Tiket Standar berhasil ditambahkan.");
                }
            }
            else if (command.equals("SHOW")) {
                System.out.println("\n========================================= DATA TIKET BIOSKOP =========================================");
                
                System.out.println("\n--- TIKET STANDAR ---");
                if (dataStandar.isEmpty()) {
                    System.out.println("(Kosong)");
                } else {
                    System.out.printf("%-5s%-10s%-20s%-15s%-10s%-15s%-15s\n", "No", "ID", "Film", "Teater", "Kursi", "Harga", "Validitas");
                    System.out.println("-".repeat(90));
                    
                    for (int i = 0; i < dataStandar.size(); i++) {
                        TiketStandar t = dataStandar.get(i);
                        System.out.printf("%-5d%-10s%-20s%-15s%-10dRp %-12d%-15s\n", 
                                i + 1, t.getIdTiket(), t.getFilm(), t.getRuang(), t.getDuduk(), t.getHarga(), t.getValid());
                    }
                }

                System.out.println("\n--- TIKET PREMIUM ---");
                if (dataPremium.isEmpty()) {
                    System.out.println("(Kosong)");
                } else {
                    System.out.printf("%-5s%-10s%-20s%-15s%-10s%-15s%-15s%-15s%-10s\n", "No", "ID", "Film", "Teater", "Kursi", "Total Harga", "IMAX", "Voucher", "Validitas");
                    System.out.println("-".repeat(115));
                    
                    for (int i = 0; i < dataPremium.size(); i++) {
                        TiketPremium t = dataPremium.get(i);
                        int total_harga = t.getHarga() + t.getHargaTambah();
                        
                        System.out.printf("%-5d%-10s%-20s%-15s%-10dRp %-12d%-15s%-15d%-10s\n", 
                                i + 1, t.getIdTiket(), t.getFilm(), t.getRuang(), t.getDuduk(), total_harga, t.getLayarIMAX(), t.getVoucher(), t.getValid());
                    }
                }
                System.out.println("======================================================================================================");
            }
            else {
                System.out.println(">> Command tidak dikenali. Ketik HELP untuk bantuan.");
            }
            
            // clearcin() replacement: Consume the remainder of the input line to clear the buffer[cite: 1]
            if (scanner.hasNextLine()) {
                scanner.nextLine();
            }
        }
        
        scanner.close();
    }
}