package programcrud.model;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Koneksi {
    
    public Koneksi() throws SQLException {
        DriverManager.registerDriver(new com.mysql.cj.jdbc.Driver());
    }
    
    protected Connection GetConnection() throws SQLException {
        final String url = "jdbc:mysql://localhost:3306/programcrud";
        final String user = "root";
        final String password = "";
        
        return DriverManager.getConnection(url, user, password);
    }
    
}
