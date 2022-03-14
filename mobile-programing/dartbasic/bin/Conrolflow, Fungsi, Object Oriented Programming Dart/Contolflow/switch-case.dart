void main(List<String> arguments) {
  String hari = "jumat";
  String quote;

  switch (hari) {
    case "senin":
      {
        quote = "Mari kita mulai dari senin dengan semangat";
        break;
      }
    case "selasa":
      {
        quote = "Selesaikan tugas, dan bersantailah";
        break;
      }
    case "rabu":
      {
        quote = "Serbu! hari ini penuh semangat!";
        break;
      }
    case "kamis":
      {
        quote = "Meski bogor hujan, aku belajar coding";
        break;
      }
    case "jumat":
      {
        quote = "Jum'at berkah, jangan membaca Surat Al-Kahfi";
        break;
      }
    case "sabtu":
      {
        quote = "Tenangkan jiwa di hari akhir!";
        break;
      }
    case "minggu":
      {
        quote = "Selamat berlibur!";
        break;
      }
    default:
      {
        quote = "Hari yang anda masukan salah!";
      }
  }

  print(quote);
}
