package asbtraksi;

public class Penduduk {
    public String Nama;
    protected String m_MinumanFavorit;
    
    public Penduduk() {
        this.m_MinumanFavorit = "Susu";
    }
    
    public final void Minum() {
        System.out.println(m_MinumanFavorit);
    }
    
    public void Makan() {
        System.out.println("Nasi");
    }
}
