package abstraksiturunan;

import asbtraksi.Mahasiswa;

public class AbstraksiTurunan {

    public static void main(String[] args) {
        Mahasiswa m = new Mahasiswa();
        m.NPM = "065118116";
        m.Nama = "Fahmi Noor Fiqri";
        
        m.Identitas();
        m.Minum();
        m.Makan();
   }
}
