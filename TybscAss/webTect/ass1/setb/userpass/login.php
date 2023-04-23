<html>
    <body>
        <form method="post" >
            username:<input type="text" name="user">
            <br><br>
            password:<input type="password" name="pass">
            <br><br>
            <input type="submit" value="submit" name="submit">
        </form>
    </body>
</html>
<?php
    if(isset($_POST["submit"])){
        
        session_start();
        
        if(!isset($_SESSION['count'])) {
            $_SESSION['count'] = 0;
        }
        if($_POST["user"]=="user" && $_POST["pass"]=="pass"){
            header("Location:redirect.php");
            exit;
        }
        elseif($_SESSION['count']>3){
            header("Location:error.php");
            exit;
        }else{
            $_SESSION['count']++;
            echo "try again;";
        }
        
        echo $_SESSION['count'];
        
    }
    
?>
