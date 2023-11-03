<!DOCTYPE html>
 
<html>
<body>
  <h1>Here is your Multiples Table </h1>
  <a href="practice4.html">Back</a>

 <!-- <table border='2'></table> -->
  <?php
    $size= $_POST['size'];
    
    echo "<table border =\"1\">";
    for ($row=0; $row<=$size; $row++){
        echo "<tr> \n";
        for ($col=0;$col<=$size; $col++){
            if ($row==0 && $col==0){
                echo "<td> </td>";

            }
            else if($row==0 && $col!=0){
                echo "<td> $col </td>";
            }
            else if($row!=0 && $col==0){
                echo "<td> $row </td>";
            }
            else {
                $product= $row*$col;
                echo "<td>$product</td> \n";
            }
        }
        echo "</tr>";

    }
    
  ?>
</body>
</html>