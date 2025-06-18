<?php
$temp = $_POST['temperature'];
$hum = $_POST['humidite'];

// Sauvegarde dans un fichier texte ou une base de données
file_put_contents("donnees.txt", date("Y-m-d H:i:s")." | Temp: $temp °C, Hum: $hum %\n", FILE_APPEND);
?>
