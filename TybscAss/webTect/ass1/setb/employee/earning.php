<html>
    <body>
        <form method="post">
            <h4>employee details</h4>
            <?php
                session_start();
                echo $_SESSION["eno"]."<br>";
                echo $_SESSION["ename"]."<br>";
                echo $_SESSION["add"]."<br>";
            ?>
            <hr>
            <h4>Earning</h4>
            basic:<input type="number" name="basic">
            <br><br>
            DA:<input type="number" name="da">
            <br><br>
            HRA:<input type="number" name="hra">
            <br><br>
            <input type="submit" value="submit" name="submit">
        </form>
    </body>
</html>
<?php   
    if(isset($_POST["submit"])){
        session_start();
        if($_POST["basic"]!="" && $_POST["da"]!="" && $_POST["hra"]!=""){
            $_SESSION["basic"]=$_POST["basic"];
            $_SESSION["da"]=$_POST["da"];
            $_SESSION["hra"]=$_POST["hra"];
            header("Location:emInfo.php");
            exit;
        }else{
            echo "enter all feilds";
        }
    }
?>
