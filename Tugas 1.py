def hitung_gaji(jam_kerja, rate_normal, rate_lembur):
    jam_normal = 40
    if jam_kerja <= jam_normal:
        return jam_kerja * rate_normal
    else:
        gaji_normal = jam_normal * rate_normal
        gaji_lembur = (jam_kerja - jam_normal) * rate_lembur
        return gaji_normal + gaji_lembur

def status_tabungan(pemasukan, pengeluaran):
    if pemasukan > pengeluaran:
        return "bisa menabung", pemasukan - pengeluaran
    elif pemasukan == pengeluaran:
        return "tidak bisa menabung", 0
    else:
        return "cari tambahan", 0

def hitung_dan_tampilkan(nama, jam_kerja, rate_normal, pengeluaran):
    rate_lembur = rate_normal * 1.5  # Corrected assignment with '='
    gaji = hitung_gaji(jam_kerja, rate_normal, rate_lembur)
    status, tabungan = status_tabungan(gaji, pengeluaran)

    print(f"\nHasil perhitungan untuk {nama}:")
    print(f"Jam kerja: {jam_kerja} jam")
    print(f"Rate normal: Rp. {rate_normal:,}/jam")
    print(f"Pengeluaran: Rp. {pengeluaran:,}")
    print(f"Gaji: Rp. {gaji:,}")
    print(f"Status: {status}")
    if status == "bisa menabung":
        print(f"Jumlah yang bisa ditabung: Rp. {tabungan:,}")
    print("-" * 40)

def main():
    # Kasus John Travolta
    hitung_dan_tampilkan("John Travolta", 52, 15000, 600000)
    # Beberapa kasus dengan nilai yang lain
    hitung_dan_tampilkan("Alice", 40, 20000, 750000)
    hitung_dan_tampilkan("Bob", 45, 18000, 900000)

if __name__ == "__main__":
    main()
