<?php
	include("modules/config.php");
	session_start();
	if(isset($_POST['dangnhap'])){//kiem tra nut dang nhap duoc click
		$tendangnhap = $_POST['tendangnhap'];
		$matkhau = md5($_POST['matkhau']);
		$login_error = "no";
		$ketqua = mysqli_query($link, "select * from admin where tendangnhap = '$tendangnhap' and matkhau = '$matkhau'");
		if(mysqli_num_rows($ketqua) > 0){
			#session_name($tendangnhap);
			$_SESSION['tendangnhap'] = $tendangnhap;	
			header("location: index.php");
		}else{
			$login_error = "yes";	
		}
	}
	else if(isset($_GET['ac']) == "thoat"){
		session_destroy();
		header("location: login.php");
	}
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>ĐĂNG NHẬP HỆ THỐNG </title>
<link href="css/stype.css" rel="stylesheet" type="text/css" />
</head>

<body>
<div id="wrapper">
    <div id="tile"> 
    	HỆ THỐNG ĐIỀU KHIỂN THIẾT BỊ, BẢO MẬT VÂN TAY
    </div>	
</div>
<div class="login">
    <form action="login.php" method="post">
      <p>&nbsp;</p>
      <table width="200" border="0" >
      
        <tr>
          <td align="center" class="tile-dangnhap">ĐĂNG NHẬP HỆ THỐNG</td>
        </tr>
        
        <tr>
          <td class="input-dangnhap">
                <table width="346" border="0" align="center">
                <tr>
                   <td width="151" height="36" dir="rtl">:Tên đăng nhập</td>
                   <td width="185">
                   <input name="tendangnhap" type="text" size="30">
                   </td>
                </tr>
                
                <tr>
                  <td height="37" dir="rtl">:Mật khẩu </td>
                  <td>
                  <input name="matkhau" type="password" size="30">
                  </td>
                </tr>
            
                <tr>
                  <td height="39">&nbsp;</td>
                  <td>
                    <input name="dangnhap" type="submit" value="Đăng nhập" class="btn-dangnhap">
                  </td>
                </tr>     
                </table>          
          </td>      
        </tr>
            
        <tr>
          <td height="33" colspan="2" align="center">
          	<?php
            	if(isset($login_error) == "yes"){
					include("error.php");
				}
			?>
          </td>
        </tr>
        
      </table>
    </form>
</div>
</body>
</html>