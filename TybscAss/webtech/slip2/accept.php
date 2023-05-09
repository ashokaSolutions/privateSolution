<html>
    <body>
        <form  method="post">
            <input type="text" name="font" id="font"/>
            <input type="text" name="color" id="color"/>
            <input type="number" name="size" id="size"/>
            <input type="text" name="bgcolor" id="bgcolor"/>
            <input type="submit" name="submit" id="submit">button</input>
        </form>
    </body>
</html>
<?php
    echo "helo";
    if(isset($_POST["submit"])){
        setcookie("font",$_POST["font"],time()+543,"/");
        setcookie("color",$_POST["color"],time()+543,"/");
        setcookie("size",$_POST["size"],time()+543,"/");
        setcookie("bgcolor",$_POST["bgcolor"],time()+543,"/");
        header("Location:display.php");
    }
?>
