from tiket import TiketStandar, TiketPremium

def title():
    print("==============================================")
    print("||        SELAMAT DATANG DI BIOSKOP!        ||")
    print("==============================================")
    print()

def printHelp():
    print("==============================================")
    print("||  Program ini ditujukan sebagai simulasi  ||")
    print("||  dalam mengatur dan mengelola tiket      ||")
    print("||             pada sebuah bioskop.         ||")
    print("||                                          ||")
    print("||                                          ||")
    print("||              COMMAND LIST                ||")
    print("||                 +INPUT                   ||")
    print("||                 +SHOW                    ||")
    print("||                 +HELP                    ||")
    print("||                 +EXIT                    ||")
    print("||                                          ||")
    print("||+ FORMAT INPUT :                          ||")
    print("||INPUT id_tiket jenis_tiket harga validitas||")
    print("||judulfilm ruangtheater nomor_duduk        ||")
    print("||[JIKA PREMIUM] h_tambahan iMAX no_voucher ||")
    print("||FUNGSI : Menginput tiket kedalam          ||")
    print("||         data bioskop                     ||")
    print("||                                          ||")
    print("||+ FORMAT SHOW :                           ||")
    print("||SHOW                                      ||")
    print("||FUNGSI : Menampilkan seluruh data dalam   ||")
    print("||         bioskop                          ||")
    print("||                                          ||")
    print("||+ FORMAT HELP :                           ||")
    print("||HELP                                      ||")
    print("||FUNGSI : Menampilkan kembali menu panduan ||")
    print("||         ini                              ||")
    print("==============================================")

def dataawal(dataStandar, dataPremium):
    dataStandar.append(TiketStandar("a1", 25000, "valid", "Rocky", "Cinema01", 1))
    dataStandar.append(TiketStandar("a2", 25000, "valid", "Prisoners", "Cinema02", 1))
    dataStandar.append(TiketStandar("a3", 30000, "valid", "Dune", "Cinema03", 1))
    
    dataPremium.append(TiketPremium("b1", 30000, "valid", "Interstellar", "Cinema04", 10, 20000, "IMAX", 10250))
    dataPremium.append(TiketPremium("b2", 30000, "invalid", "Oppenheimer", "Cinema05", 11, 25000, "nonIMAX", 11256))

def main():
    dataStandar = []
    dataPremium = []
    
    dataawal(dataStandar, dataPremium)
    title()
    printHelp()

    while True:
        try:
            # Read input and split by whitespace to mimic C++'s cin buffer behavior
            user_input = input("\n> Masukkan Command (INPUT/SHOW/HELP/EXIT): ").strip().split()
            if not user_input:
                continue
                
            command = user_input[0].upper()

            if command == "HELP":
                printHelp()
            elif command == "EXIT":
                print("Keluar dari program...")
                break
            elif command == "INPUT":
                args = user_input[1:]
                
                # Fetch remaining arguments if inputted on new lines (replicating C++ cin whitespace ignore)
                while len(args) < 7:
                    args.extend(input().strip().split())

                id_tiket = args[0]
                jenis_tiket = args[1]
                harga_awal = int(args[2])
                validitas = args[3]
                judul_film = args[4]
                ruangtheater = args[5]
                nomor_duduk = int(args[6])

                if jenis_tiket.lower() == "premium":
                    while len(args) < 10:
                        args.extend(input().strip().split())
                    
                    harga_tambahan = int(args[7])
                    layarIMAX = args[8]
                    nomorvoucher = int(args[9])

                    tiketBaru = TiketPremium(id_tiket, harga_awal, validitas, judul_film, ruangtheater, nomor_duduk, harga_tambahan, layarIMAX, nomorvoucher)
                    dataPremium.append(tiketBaru)
                    print(">> Sukses! Tiket Premium berhasil ditambahkan.")

                elif jenis_tiket.lower() == "standar":
                    tiketBaru = TiketStandar(id_tiket, harga_awal, validitas, judul_film, ruangtheater, nomor_duduk)
                    dataStandar.append(tiketBaru)
                    print(">> Sukses! Tiket Standar berhasil ditambahkan.")

            elif command == "SHOW":
                print("\n========================================= DATA TIKET BIOSKOP =========================================")
                
                print("\n--- TIKET STANDAR ---")
                if not dataStandar:
                    print("(Kosong)")
                else:
                    print(f"{'No':<5}{'ID':<10}{'Film':<20}{'Teater':<15}{'Kursi':<10}{'Harga':<15}{'Validitas':<15}")
                    print("-" * 90)
                    
                    for i, t in enumerate(dataStandar):
                        print(f"{i+1:<5}{t.getidtiket():<10}{t.getfilm():<20}{t.getruang():<15}{t.getduduk():<10}Rp {t.getharga():<12}{t.getvalid():<15}")

                print("\n--- TIKET PREMIUM ---")
                if not dataPremium:
                    print("(Kosong)")
                else:
                    print(f"{'No':<5}{'ID':<10}{'Film':<20}{'Teater':<15}{'Kursi':<10}{'Total Harga':<15}{'IMAX':<15}{'Voucher':<15}{'Validitas':<10}")
                    print("-" * 115)
                    
                    for i, t in enumerate(dataPremium):
                        total_harga = t.getharga() + t.gethargatambah()
                        print(f"{i+1:<5}{t.getidtiket():<10}{t.getfilm():<20}{t.getruang():<15}{t.getduduk():<10}Rp {total_harga:<12}{t.getlayarIMAX():<15}{t.getvoucher():<15}{t.getvalid():<10}")
                
                print("======================================================================================================")
            else:
                print(">> Command tidak dikenali. Ketik HELP untuk bantuan.")
                
        except (ValueError, IndexError):
            # Replacing clearcin() logic to recover cleanly from malformed input
            print(">> Format input salah. Silakan coba lagi. Ketik HELP untuk bantuan.")

if __name__ == "__main__":
    main()