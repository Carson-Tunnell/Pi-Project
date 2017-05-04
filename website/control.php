<?php
$sessiName = "Rasberry_Pi";
session_name ( $sessiName );
session_start ();
$_SESSION['host'] = $_SERVER ['HTTP_HOST'];
$_SESSION['uri'] = rtrim ( dirname ( $_SERVER ['PHP_SELF'] ), '/\\' );
?>
