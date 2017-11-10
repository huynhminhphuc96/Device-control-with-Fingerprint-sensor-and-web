<?php
	session_start();
	
	include("modules/config.php");
	
	if(isset($_GET['dieukhien']))
	{
		$stt = $_GET['dieukhien'];
		$trangthai = $_GET['trangthai'];
		mysqli_query($link, "UPDATE devices SET State = '$trangthai' WHERE ID = '$stt'");	
	}	
	
	if($_SESSION['tendangnhap']==''){
		header("location: /welcome.php");
		exit();
	}
?>
    
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>HỆ THỐNG ĐIỀU KHIỂN THIẾT BỊ, BẢO MẬT VÂN TAY </title>
<link href="css/stype.css" rel="stylesheet" type="text/css" />
</head>

<body>

	<?php	
		include("modules/wrapper.php");
		include("modules/content.php");
		
	?>

</body>
</html>