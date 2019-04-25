<?php
error_reporting(0);
$a= $_POST['val_1'];
$b= $_POST['val_2'];
$c= $_POST['val_3'];
$d= $_POST['val_4'];
$e= $_POST['val_5']; 
 if(isset($_POST['clear']))
{ 
$a=""; $b=""; $c=""; $d=""; $e="";
$display_original=""; $process_results="";
}
?>
<html>
<head>
<title>Insertion Sort in PHP</title>
<style>
body { font-family:arial;}
form { width: 400px; }
label { float: left; width: 95px; }
.clear { clear: both; height: 0; line-height: 0; }
.floatright { float: right; }
</style>
</head>
<body>
<h2>Insertion Sort in PHP</h2>
<form action="" method="post">
<label>Value No. 1 : </label> <input type="text" name="val_1" value="<?php echo $a; ?>" size="5" maxlength="5" autofocus/><br/><br>
<label>Value No. 2 : </label> <input type="text" name="val_2" value="<?php echo $b; ?>" size="5" maxlength="5"/><br/><br>
<label>Value No. 3 : </label> <input type="text" name="val_3" value="<?php echo $c; ?>" size="5" maxlength="5"/><br/><br>
<label>Value No. 4 : </label> <input type="text" name="val_4" value="<?php echo $d; ?>"size="5" maxlength="5"/><br/><br>
<label>Value No. 5 : </label> <input type="text" name="val_5" value="<?php echo $e; ?>"size="5" maxlength="5"/><br/>
<br />
<input type="submit" value="Sort" name="bubble"/>
<input type="submit" value="Clear" name="clear" />
</form>
<?php
function InsertionSort($array) {
 
$sortedArray = array();
 
for ($i = 0 ; $i < count($array); $i++) {
 
$element = $array[$i];
$j = $i;
 
while($j > 0 && $sortedArray[$j-1] > $element) {
 
$sortedArray[$j] = $sortedArray[$j-1];
$j = $j-1;
}
$sortedArray[$j] = $element;
}
return $sortedArray;
}
if(isset($_POST['bubble']))
{ 
 
 $arr = array($a,$b,$c,$d,$e);
 $orig = implode(",", $arr); 
 
 $a =InsertionSort($arr);
 $final_sort = implode(",", $a);
 $display_original = "Original Values : " .$orig."<br><br>";
 $process_results = "Sorted Values : " .$final_sort."<br>";
 
 echo $display_original;
 echo $process_results;
}
?>
</body>
</html>

//Input: 103,-56,73,3001,5
//Output: -56,5,73,103,3001
