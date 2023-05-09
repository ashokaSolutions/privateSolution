<?php
    echo "size:".$_COOKIE["size"]."<br>";
    echo "color:".$_COOKIE["color"]."<br>";
    echo "font:".$_COOKIE["font"]."<br>";
    echo "bgcolor:".$_COOKIE["bgcolor"]."<br>";
?>
<html>
    <body>
        <form method="post">
            <input type="submit" name="submit" id="submit" ></input>
        </form>
    </body>
</html>
<?php
    if(isset($_POST["submit"])){
        header("Location:actual.php");
    }
?>
