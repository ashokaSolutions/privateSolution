<?php   
    //data ka array banao
    $items=array(
        array("itemName"=>"chocolate","itemPrice"=>45,"Quantity"=>3),
        array("itemName"=>"chocolate","itemPrice"=>45,"Quantity"=>3),
        array("itemName"=>"chocolate","itemPrice"=>45,"Quantity"=>3),
        array("itemName"=>"chocolate","itemPrice"=>45,"Quantity"=>3),
        array("itemName"=>"chocolate","itemPrice"=>45,"Quantity"=>3)
    );

    //header=is a PHP function that sets the content type of the HTTP response to "text/xml"
    header("Content-type: text/xml");
    
    //now just write normal xml
    echo "<?xml version='1.0' encoding='UTC-8'?>\n";
    echo "<items>\n";
 
    //for large items
    foreach($items as $item){
        echo "  <item>\n";
        echo "      <itemName>".$item["itemName"]."</itemName>\n";
        echo "      <itemPrice>".$item["itemPrice"]."</itemPrice>\n";
        echo "      <Quantity>".$item["Quantity"]."</Quantity>\n";
        echo "  </item>\n";
    }
    echo "</items>";

    //ob_get_contents() is typically used to retrieve the contents of the-
    //output buffer so that it can be processed, such as converting it to a string,- 
    //writing it to a file or manipulating it in some other way
    $xmlData=ob_get_contents();

    //put the data in the file
    file_put_contents("book.xml",$xmlData);
?>
