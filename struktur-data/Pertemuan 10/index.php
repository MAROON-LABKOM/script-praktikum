<?php
    $mysql = mysqli_connect("localhost","root","","mahasiswa");
?>

<h3>Form Pencarian dengan PHP dan Mysql</h3>
<form action="index.php" method="get">
    <label>Cari :</label>
    <input type="text" name="cari">
    <input type="submit" value="Cari">
</form>

<?php
if(isset($_GET['cari'])) {
    $cari = $_GET['cari'];
    echo "<b>Hasil pencarian : ".$cari."</b>";
}
?>

<table border="1">
    <tr>
        <th>No</th>
        <th>Nama</th>
    </tr>
    <?php
        if(isset($_GET['cari'])) {
            $cari = $_GET['cari'];
            $data = mysqli_query($mysql, "SELECT * FROM mhs WHERE Nama like '%".$cari."%'");
        } else {
            $data = mysqli_query($mysql, "SELECT * FROM mhs");
        }
        $no = 1;
        while($d = mysqli_fetch_array($data)) {
    ?>
    <tr>
        <td>
            <?php
                echo $no++;
            ?>
        </td>
        <td>
            <?php echo $d['Nama']; ?>
        </td>
    </tr>
    <?php } ?>
</table>