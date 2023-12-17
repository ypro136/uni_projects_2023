<?php 
$conn = mysqli_connect('localhost', 'mohamed', 'password', 'amazon_database');

if(!$conn){
  echo "Connection Error: " . mysqli_connect_error();
}
?>