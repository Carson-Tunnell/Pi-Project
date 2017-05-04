<?php
class Statistics {
	public $humid = 0;
	public $temp = 0;
	public $smoke = array(0,0,0,0);
}
function readStats() {
	//$stats = array ();
	$fh = fopen ( 'outfile.csv', 'r' ) or die ( "Can't open file 'outfile.csv'." );
	//$keys = fgetcsv ( $fh );
	$s = new Statistics ();
	$line = 0;
	while ( ($vals = fgetcsv ( $fh )) != FALSE ) {
		if ($line == 0)
			$s->temp = $vals[1];
		else if ($line == 1)
			$s->humid = $vals[1];
		else if ($line == 2) {
			$s->smoke[0] = $vals[1];
			$s->smoke[1] = $vals[2];
			$s->smoke[2] = $vals[3];
			$s->smoke[3] = $vals[4];
		}
		$line++;
	}
	fclose ( $fh );
	return $s;
}
function smokeSum($stats) {
	$sum = 0;
	for ($i = 0; $i < 4; $i++) {
		$sum += $stats->smoke[$i];
	}
	return $sum;
}
function emailAlert() {
	$host = $_SESSION['host'];
	$uri = $_SESSION['uri'];
	$email = "carsontunnell@yahoo.com";
	$subject = "ALERT: ALARM DETECTED";
	$content = "An alarm has been triggered by your Rasberry Pi!  Get out of your home if you are inside.\n";
	$content = $content . "To check the webpage follow the link: \n";
	$content = $content . "https://$host$uri/index.php?key=sent\n";
	mail($email, $subject, $content);
}

?>