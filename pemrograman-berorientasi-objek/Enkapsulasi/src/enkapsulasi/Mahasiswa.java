package enkapsulasi;

public class Mahasiswa {
    public String Nama;
    public String NPM;
    public int Semester;
    
    private boolean m_bayarSpp;
    
    public Mahasiswa(String nama) {
        this.Nama = nama;
    }
    
    public void BayarSPP() {
        System.out.println(this.Nama + " sudah bayar SPP");
        m_bayarSpp = true;
    }
    
    public void AmbilKRS() {
        if (m_bayarSpp) {
            System.out.println(this.Nama + " sudah ambil KRS");    
        } else {
            System.out.println(this.Nama + " belum bayar SKS");
        }
    }
    
    public void Belajar() {
        System.out.println(this.Nama + " sedang belajar");
    }

}
