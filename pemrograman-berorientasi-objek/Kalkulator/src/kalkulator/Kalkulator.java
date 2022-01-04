package kalkulator;

import java.util.Scanner;

public class Kalkulator {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Masukkan nama: ");
        
        String nama = scanner.nextLine();
        System.out.println("Kamu input: " + nama);
        
        System.out.print("Masukkan usia: ");
        int usia = Integer.valueOf(scanner.nextLine());
        System.out.println("Usia: " + usia);
    }
    
}
