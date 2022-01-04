package programcrud.model;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import javax.swing.table.DefaultTableModel;

public class MahasiswaModel extends Koneksi {

    public MahasiswaModel() throws SQLException {
    }
    
    public DefaultTableModel GetAll() throws SQLException {
        Connection cn = super.GetConnection();
        Statement cmd = cn.createStatement();
        ResultSet rs = cmd.executeQuery("SELECT * FROM mahasiswa");
        
        DefaultTableModel model = new DefaultTableModel();
        model.addColumn("NPM");
        model.addColumn("Nama");
        model.addColumn("Kelas");
        
        while (rs.next()) {
            model.addRow(new Object[] 
            {
                rs.getString(1),
                rs.getString(2),
                rs.getString(3),
            });
        }
        
        return model;
    }
    
    public void Delete(String npm) throws SQLException {
        final String sql = "DELETE FROM mahasiswa WHERE npm = ?";
        Connection cn = super.GetConnection();
        PreparedStatement cmd = cn.prepareStatement(sql);
        
        cmd.setString(1, npm);
        cmd.execute();
    }
    
    public void Insert(String npm, String nama, String kelas) throws SQLException {
        final String sql = "INSERT INTO mahasiswa VALUES(?, ?, ?)";
        Connection cn = super.GetConnection();
        PreparedStatement cmd = cn.prepareStatement(sql);
        
        cmd.setString(1, npm);
        cmd.setString(2, nama);
        cmd.setString(3, kelas);
        
        cmd.execute();
    }
    
    public void Update(String npm, String nama, String kelas) throws SQLException {
        final String sql = "UPDATE mahasiswa SET nama = ?, kelas = ? WHERE npm = ?";
        Connection cn = super.GetConnection();
        PreparedStatement cmd = cn.prepareStatement(sql);
        
        cmd.setString(1, nama);
        cmd.setString(2, kelas);
        cmd.setString(3, npm);
        
        cmd.execute();
    }
}
