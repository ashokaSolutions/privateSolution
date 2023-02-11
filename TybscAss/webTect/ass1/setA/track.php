<!--A session is a way to store information (in variables) to be used across multiple pages.
Unlike a cookie, the information is not stored on the users computer.-->
<html>
    <body>
        <h1>Info</h1>
        
    </body>
</html>

<?php 
  
session_start();
   
if(isset($_SESSION['views']))
    $_SESSION['views'] = $_SESSION['views']+1;
else
    $_SESSION['views']=1;
      
echo"session views = ".$_SESSION['views'];
if( isset($_COOKIE['count']))
    $_COOKIE['count']=$_COOKIE['count']+1;   
else
        $_COOKIE['count']=1;
  echo "cookie time:".$_COOKIE['count'];    
?>