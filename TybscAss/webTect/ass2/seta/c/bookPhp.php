<?php
    $BookInfo=array(
        array("bookno"=>1,"bookname"=>"JAVA","authorname"=>"Balguru swami","price"=>250,"year"=>2006),
        array("bookno"=>2,"bookname"=>"C","authorname"=>"Denis Ritchie","price"=>500,"year"=>1971)
    );

    header(("content-type: text/xml"));

    echo "<?xml version='1.0' encoding='UTF-8'?>\n";
    echo "<BookInfo>\n";
    foreach($BookInfo as $book){
        echo "  <book>\n";
        echo "      <bookno>".$book["bookno"]."</bookno>\n";
        echo "      <bookname>".$book["bookname"]."</bookname>\n";
        echo "      <authorname>".$book["authorname"]."</authorname>\n";
        echo "      <price>".$book["price"]."</price>\n";
        echo "      <year>".$book["year"]."</year>\n";
        echo "  </book>\n";
    }
    echo "</BookInfo>";

    $xmlData=ob_get_contents();
    file_put_contents("books.xml",$xmlData);
?>
