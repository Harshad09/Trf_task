<?php
$distance = $_GET['distance'];
$servername = "192.168.43.151";
$username = "root";
$password = "";
$dbname = "database";
// Create connection
$conn = new mysqli($servername, $username,$password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 
$val = $_GET['distance'];
$sql = "INSERT INTO `uvdatabase`(distance) VALUES ($val);";
if ($conn->query($sql) === TRUE) {
    echo "Distance Saved Successfully!";
} else {
    echo "Error:" . $sql . "<br>" . $conn->error;
}
$conn->close();
?>