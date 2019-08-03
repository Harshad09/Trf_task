<html>
<head>
<meta http-equiv="refresh" content="5">
</head> 
<body>
<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "database";
// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 
$sql = "SELECT * FROM leddatabase ORDER by id DESC LIMIT 33";
$result = $conn->query($sql);
if ($result->num_rows > 0) {
    // output data of each row
	echo "<h1>DATABASE OF ULTRASONIC SENSOR</h1>";
	echo "<form style =background-image: sagar.jpg;>";
	echo "<table border='1'><th>ID</th><th>distance</th><th>TIME</th>";
    while($row = $result->fetch_assoc()) {
		echo "<tr>";
		echo "<td>".$row['id']."</td>";
		echo "<td>".$row['distance']."</td>";
		echo "<td>".$row['time']."</td>";
		echo "</tr>";
    }
	echo "</table>";
} else {
    echo "0 results";
}
$conn->close();
?>
</body>
</html>