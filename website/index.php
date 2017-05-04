<?php
	include 'control.php';
	include 'support.php';
	$stats = readStats();
	$alertStatus = 0;
	if ( ! (isset ($_GET['key'] ) ) ) {
		if(smokeSum($stats) != 0) {
			emailAlert();
			$_GET['key'] = 'sent';
			$alertStatus++;
		}
	}
	include 'header.php';
?>
</head>
<body>

	<?php
		include 'jumbotron.php';
		
		echo "</br>The values that are being sent by the rasberry Pi are:\n";
		echo "</br>Temperature = " . $stats->temp . " &#8451</br>";
		echo "Humidity = " . $stats->humid . "%</br>";
		echo "</br>The Smoke values are:</br>";
		echo "Gas Smoke = " . $stats->smoke[0] . "</br>"; 
		echo "Combustible Gas = " . $stats->smoke[1] . "</br>";
		echo "CO Carbon Monoxide = " . $stats->smoke[2] . "</br>";
		echo "Flame = " . $stats->smoke[3] . "</br>";
	?>
	
</body>
<?php
	include 'footer.php';
?>
</html>
