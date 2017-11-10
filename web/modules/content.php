<link href="../css/stype.css" rel="stylesheet" type="text/css" />

<?php
	#if(isset($_GET['dieukhien']))
	#{
	#	$stt = $_GET['dieukhien'];
	#	$trangthai = $_GET['trangthai'];
	#	mysqli_query($link, "UPDATE devices SET State = '$trangthai' WHERE ID = '$stt'");	
	#}	
	$devices = mysqli_query($link, "select * from devices");
?>


<div id="content">
	<div id="history">
    	<?php
			$myfile_nd = fopen("modules/file.txt", "r") or die("xảy ra lỗi khi mở file");
			$file = fread($myfile_nd, filesize("modules/file.txt"));
			fclose($myfile_nd);
		?>
      <textarea name="history-text" cols="50" disabled="disabled" readonly="readonly" class="textdisabled"><?php echo $file?>
        </textarea>
    </div>
    
  <div id="control">
	  <table id="tb_devices" width="100%" border="1" align="center">
      
	    <tr class="tr-tile-control">
	      <td width="auto" height="50">
          	<div align="center"><strong>Thiết bị</strong></div>
          </td>
	      <td colspan="2" width="35%">
          	<div align="center"><strong>Điều khiển</strong></div>
          </td>
        </tr>
        
	    <?php
  			while($dong = mysqli_fetch_array($devices))
			{
  		?>
            <tr>
              <td height="127">
              	<img src="modules/img/<?php echo $dong["Name"]?>/<?php echo $dong["State"]?>.gif">
              </td>
				
              <td width="auto" class="td_bat">
              	<a href="index.php?dieukhien=<?php echo $dong["ID"]?>&amp;trangthai=on">Bật</a>
              </td>

              <td width="auto" class="td_tat">
              	<a href="index.php?dieukhien=<?php echo $dong["ID"]?>&amp;trangthai=off">Tắt</a>
              </td>
       		</tr>
	    <?php
			}
  		?>
	    
 	 </table>
     </div>
</div>