package enkapsulasi;

public class Enkapsulasi {
    
      public static void main(String[] args) {
        Mahasiswa m1 = new Mahasiswa("Fahmi");
        Mahasiswa m2 = new Mahasiswa("Fiqri");
        
        m1.BayarSPP();
        m1.AmbilKRS();
        
        m2.AmbilKRS();
        
        m1.Belajar();
        m2.Belajar();
    }
    
}
