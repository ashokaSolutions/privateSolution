<html>
    <body>
        <form method="post">
            eno:<input type="text" name="eno">
            <br><br>
            ename:<input type="text" name="ename">
            <br><br>
            add:<input type="text" name="add">
            <br><br>
            <input type="submit" value="submit" name="submit">
        </form>
    </body>
</html>
<?php   
    if(isset($_POST["submit"])){
       
        session_start();
        if($_POST["eno"]!="" && $_POST["ename"]!="" && $_POST["add"]!=""){
            $_SESSION["eno"]=$_POST["eno"];
            $_SESSION["ename"]=$_POST["ename"];
            $_SESSION["add"]=$_POST["add"];
            header("Location:earning.php");
            exit;
        }else{
            echo "enter all feilds";
        }
    }
?>
