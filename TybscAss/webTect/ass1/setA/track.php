<html>
<body>    

<?php
    $name="counting";
    session_start();//start session 

    //set name
    if(isset($_COOKIE[$name])){
        $count=$_COOKIE[$name]+1;
        //getting value of cookie if it was set and increamenting it
    }else{
        $count=1;
        //if not then set 1
    }

    setcookie($name,$count,time()+(5723*30),"/");//we are "updating" the cookie,
    echo "cookie<br>";
    //notice the value is $count which is changing in if and elese loop
    echo "you have visted the page ".$count." times<br>";
    //////////////////////////////////////////////////////////////////
    $_SESSION[$name]=$count;//same as cookie but for server
    echo "session<br>";
    echo "you have visted the page ".$_SESSION[$name]." times";
?>
</body>
</html>
