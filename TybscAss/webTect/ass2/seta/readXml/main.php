<?php
    //just add everything in a string
    $items = array(
        array("name" => "Item 1", "type" => "Electronics", "rate" => 10.99, "quantity" => 50),
        array("name" => "Item 2", "type" => "Books", "rate" => 5.99, "quantity" => 20),
        array("name" => "Item 3", "type" => "Clothing", "rate" => 19.99, "quantity" => 30),
        array("name" => "Item 4", "type" => "Beauty", "rate" => 7.99, "quantity" => 40),
        array("name" => "Item 5", "type" => "Home", "rate" => 24.99, "quantity" => 10)
    );
    
    $data="<?xml version=\"1.0\" ?>\n";
    $data.="<items>\n";
    foreach($items as $row){
            $data.=" <item>\n";
            $data.="    <name>".$row["name"]."</name>\n";
            $data.="    <type>".$row["type"]."</type>\n";
            $data.="    <rate>".$row["rate"]."</rate>\n";
            $data.="    <quantity>".$row["quantity"]."</quantity>\n";
            $data.=" </item>\n";
        
    }
    
    $data.="<items>\n";
    file_put_contents("item.xml",$data);
?>
