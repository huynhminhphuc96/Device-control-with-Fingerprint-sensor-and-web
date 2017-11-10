<?php
	$tenserver = "localhost";
	
	#xampp
	#$taikhoan = "root";
	#$matkhau = "root";
	#$csdl = "devices_control";
	
	#hostinger
	$taikhoan = "u532961415_root";
	$matkhau = "phuchm";
	$csdl = "u532961415_damh";
	
	#000webhost
	#$taikhoan = "id3426259_admin";
	#$matkhau = "admin";
	#$csdl = "id3426259_devices_control";
	
	$link = mysqli_connect($tenserver,$taikhoan,$matkhau,$csdl);
?>