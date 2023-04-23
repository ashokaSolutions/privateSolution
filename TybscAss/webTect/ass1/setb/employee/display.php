<html>
    <body>
            <h4>employee details</h4>
            <?php
                session_start();
                echo "eno:".$_SESSION["eno"]."<br>";
                echo "name:".$_SESSION["ename"]."<br>";
                echo "address".$_SESSION["add"]."<br>";
                echo "basic:".$_SESSION["basic"]."<br>";
                echo "DA:".$_SESSION["da"]."<br>";
                echo "HRA:".$_SESSION["hra"]."<br>";
            ?>
    </body>
</html>
