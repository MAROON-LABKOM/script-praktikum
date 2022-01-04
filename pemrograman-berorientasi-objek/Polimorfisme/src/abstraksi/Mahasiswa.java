package abstraksi;

public class Mahasiswa extends Penduduk {
    public String NPM;
    
    public Mahasiswa() {
        super();
        this.m_MinumanFavorit = "Energen";
    }  
    
    public void Identitas() {
        System.out.println("Nama: " + this.Nama);
        System.out.println("NPM : " + this.NPM);
    }

    @Override
    public void Makan() {
        super.Makan();
        System.out.println("Ayam");
    }
}
