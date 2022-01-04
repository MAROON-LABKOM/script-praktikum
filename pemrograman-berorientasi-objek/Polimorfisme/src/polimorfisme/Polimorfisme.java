package polimorfisme;

import abstraksi.Mahasiswa;
import abstraksi.Penduduk;

public class Polimorfisme {

    public static void main(String[] args) {
        Mahasiswa m = new Mahasiswa();
        m.NPM = "065118116";
        
        Penduduk p = m;
        p.Nama = "Fahmi Noor Fiqri";       
        
        m.Identitas();
        p.Makan();
        p.Minum();
    }
    
}
