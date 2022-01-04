package konsepoop;

public class KonsepOOP {

    public static void main(String[] args) {
        Mahasiswa mahasiswa = new Mahasiswa();
        mahasiswa.Nama = "Fahmi";
        
        mahasiswa.BayarSPP();
        mahasiswa.Belajar();
        
        System.out.println(mahasiswa.Nama);
    }
    
}
